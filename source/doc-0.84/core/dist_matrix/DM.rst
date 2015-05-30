DistMatrix
----------

The :cpp:class:`DistMatrix\<T,U,V>` class, which is the final product from the
succession from :cpp:class:`AbstractDistMatrix\<T>` and 
:cpp:class:`GeneralDistMatrix\<T,U,V>`, is specialized for each
of the thirteen different legal distribution pairs.
Each specialization involves choosing a
sensical pairing of distributions for the rows and columns of the matrix:

-  `CIRC` : Only give the data to a single process
-  `STAR` : Give the data to every process
-  `MC` : Distribute round-robin within each column of the 2D process grid (*M* atrix *C* olumn)
-  `MR`: Distribute round-robin within each row of the 2D process grid (*M* atrix *R* ow)
-  `VC`: Distribute round-robin within a column-major ordering of the entire 2D process grid (*V* ector *C* olumn)
-  `VR`: Distribute round-robin within a row-major ordering of the entire 2D process grid (*V* ector *R* ow)
-  `MD`: Distribute round-robin over a diagonal of the tiling of the 2D process grid (*M* atrix *D* iagonal)

The valid pairings are:

+---------+---------+---------+---------+-----------+---------------+-----------+
| ColDist | RowDist | ColComm | RowComm | DistComm  | RedundantComm | CrossComm |
+=========+=========+=========+=========+===========+===============+===========+
| CIRC    | CIRC    | self    | self    | self      | self          | VC        |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MC      | MR      | MC      | MR      | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MC      | STAR    | MC      | self    | MC        | MR            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MD      | STAR    | MD      | self    | MD        | self          | MDPerp    |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MR      | MC      | MR      | MC      | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MR      | STAR    | MR      | self    | MR        | MC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MC      | self    | MC      | MC        | MR            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MD      | self    | MD      | MD        | self          | MDPerp    |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MR      | self    | MR      | MR        | MC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | STAR    | self    | self    | self      | VC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | VC      | self    | VC      | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | VR      | self    | VR      | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| VC      | STAR    | VC      | self    | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| VR      | STAR    | VR      | self    | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+

where `DistComm` refers to the communicator that the entire matrix (rather than
just the rows or columns) is distributed over. When the matrix is distributed
over a communicator which only involves only a subset of the processes, it is
possible to either assign the data to just that subset or redundantly store
the entire matrix on each such subset of processes (e.g., within each row of a
2D arrangement of the set of processes). The `RedundantComm` refers to the
communicator where each member process stores the same information, and the
`CrossComm` is the communicator where only a single process (the *root*) is
assigned any data.

To make this discussion more precise, each valid matrix distribution for
`DistMatrix` logically arranges the set of `p` processes of the `r` by `c`
process grid into a 4D mesh: `ColComm` x `RowComm` x `RedundantComm` x `CrossComm`, where `DistComm` is equal to `ColComm` x `RowComm`.

.. cpp:class:: DistMatrix<T,U,V>

   The following routines are available for each legal pairing of row and column
   distributions.

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMatrix( const Grid& grid=DefaultGrid(), int root=0 )

      Construct an empty (:math:`0 \times 0`) distributed matrix.

   .. cpp:function:: DistMatrix( int height, int width, const Grid& grid=DefaultGrid(), int root=0 )

      Create a `height` :math:`\times` `width` distributed matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<T,Y,Z>& A )

      Construct the current matrix to be a redistributed copy of the input 
      matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<T,U,V>&& A ) noexcept

      Use C++11 move semantics to construct the current matrix in a way which
      transfers the resources from the input matrix.

   .. cpp:function:: ~DistMatrix()

      All resources owned by the `DistMatrix` are freed upon destruction.

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: DistMatrix<T,U,V>& operator=( const DistMatrix<T,Y,Z>& A )

      Set the current distributed matrix equal to the matrix `A` redistributed
      into the appropriate form.

   .. cpp:function:: DistMatrix<T,U,V>& operator=( DistMatrix<T,U,V>&& A )

      A C++11 move assignment which cheaply transfers the resources from `A`
      to the current matrix by swapping metadata.


The standard matrix distribution (``[MC,MR]``)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is by far the most important matrix distribution in Elemental, as the vast
majority of parallel routines expect the input to be in this form. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column and row alignments are both 0):

.. math::

   \left(\begin{array}{ccccccc}
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0  
   \end{array}\right)

Similarly, if the column alignment is kept at 0 and the row alignment is changed
to 2 (meaning that the third process column owns the first column of the 
matrix), the individual entries would be owned as follows:

.. math::

   \left(\begin{array}{ccccccc}
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 
   \end{array}\right)

It should also be noted that this is the default distribution format for the 
:cpp:class:`DistMatrix\<T,U,V>` class, as :cpp:class:`DistMatrix\<T>` defaults 
to :cpp:class:`DistMatrix\<T,MC,MR>`.

.. cpp:class:: DistMatrix<T>
.. cpp:class:: DistMatrix<T,MC,MR>

   All public member functions have been described as part of 
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[MC,STAR]``
^^^^^^^^^^^^^

This distribution is often used as part of matrix-matrix multiplication. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,MC,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,MR]``
^^^^^^^^^^^^^
This distribution is also frequently used for matrix-matrix multiplication. 
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the row alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,STAR,MR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[MR,MC]``
^^^^^^^^^^^
This is essentially the transpose of the standard matrix distribution, 
``[MC,MR]``. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column and row alignments are both 0):

.. math::

   \left(\begin{array}{ccccccc}
     0 & 1 & 0 & 1 & 0 & 1 & 0 \\
     2 & 3 & 2 & 3 & 2 & 3 & 2 \\
     4 & 5 & 4 & 5 & 4 & 5 & 4 \\
     0 & 1 & 0 & 1 & 0 & 1 & 0 \\
     2 & 3 & 2 & 3 & 2 & 3 & 2 \\
     4 & 5 & 4 & 5 & 4 & 5 & 4 \\
     0 & 1 & 0 & 1 & 0 & 1 & 0 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,MR,MC>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[MR,STAR]``
^^^^^^^^^^^^^
This is the transpose of the ``[* ,MR]`` distribution and is, like many of 
the previous distributions, useful for matrix-matrix multiplication.
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,MR,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,MC]``
^^^^^^^^^^^^^
This is the transpose of the ``[MC,*]`` distribution and is, like many of 
the previous distributions, useful for matrix-matrix multiplication.
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,STAR,MC>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[MD,STAR]``
^^^^^^^^^^^^^
In the case of our :math:`2 \times 3` process grid, each diagonal of the tesselation
of the process grid will contain the entire set of processes, for instance, in the
order :math:`0,3,4,1,2,5`. This would result in the following overlay for the
owning processes of the entries of our :math:`7 \times 7` matrix example:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\ 
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\ 
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\ 
     0 & 0 & 0 & 0 & 0 & 0 & 0  
   \end{array}\right)

Notice that each column of this matrix is distributed like a diagonal of a 
``[MC,MR]`` distribution.

.. cpp:class:: DistMatrix<T,MD,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,MD]``
^^^^^^^^^^^^^
In the case of our :math:`2 \times 3` process grid, each diagonal of the 
tesselation of the process grid will contain the entire set of processes, for 
instance, in the order :math:`0,3,4,1,2,5`. This would result in the following 
overlay for the owning processes of the entries of our :math:`7 \times 7` 
matrix example:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 
   \end{array}\right)

Notice that each *row* of this matrix is distributed like a diagonal of a 
``[MC,MR]`` distribution.

.. cpp:class:: DistMatrix<T,STAR,MD>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[VC,STAR]``
^^^^^^^^^^^^^
This distribution makes use of a 1d distribution which uses a column-major 
ordering of the entire process grid. Since 1d distributions are useful for 
distributing *vectors*, and a *column-major* ordering is used, the distribution 
symbol is ``VC``. Again using the simple :math:`2 \times 3` process grid, 
with a zero column alignment, each entry of a :math:`7 \times 7` matrix 
would be owned by the following sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0
   \end{array}\right)

.. cpp:class:: DistMatrix<T,VC,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,VC]``
^^^^^^^^^^^^^
This is the transpose of the above ``[VC,* ]`` distribution. On the standard
:math:`2 \times 3` process grid with a row alignment of zero, a 
:math:`7 \times 7` matrix would be distributed as:

.. math::

   \left(\begin{array}{ccccccc}
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,STAR,VC>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[VR,STAR]``
^^^^^^^^^^^^^
This distribution makes use of a 1d distribution which uses a row-major 
ordering of the entire process grid. Since 1d distributions are useful for 
distributing *vectors*, and a *row-major* ordering is used, the distribution 
symbol is ``VR``. Again using the simple :math:`2 \times 3` process grid, 
with a zero column alignment, each entry of a :math:`7 \times 7` matrix 
would be owned by the following sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0
   \end{array}\right)

.. cpp:class:: DistMatrix<T,VR,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,VR]``
^^^^^^^^^^^^^
This is the transpose of the above ``[VR,* ]`` distribution. On the standard
:math:`2 \times 3` process grid with a row alignment of zero, a 
:math:`7 \times 7` matrix would be distributed as:

.. math::

   \left(\begin{array}{ccccccc}
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,STAR,VR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[STAR,STAR]``
^^^^^^^^^^^^^^^
This "distribution" actually redundantly stores every entry of the associated
matrix on every process. Again using a :math:`2 \times 3` process grid, 
the entries of a :math:`7 \times 7` matrix would be owned by the following
sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,STAR,STAR>

   All public member functions have been described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

``[CIRC,CIRC]``
^^^^^^^^^^^^^^^
This ``distribution`` stores the entire matrix on a single process. For instance,
if the root process is process 0 with respect to a column-major ordering of the 
process grid, then the corresponding overlay for the owners of each entry of our
7 x 7 matrix example would be:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 
   \end{array}\right)

.. cpp:class:: DistMatrix<T,CIRC,CIRC>

   Only two public member functions were not described as part of
   :cpp:class:`AbstractDistMatrix\<T>`, :cpp:class:`GeneralDistMatrix\<T,U,V>`,
   and :cpp:class:`DistMatrix\<T,U,V>`.

   .. cpp:function:: void CopyFromRoot( const Matrix<T>& A )

      To be called from the root process in order to assign a sequential matrix
      to a ``[CIRC,CIRC]`` "distributed" matrix.

   .. cpp:function:: void CopyFromNonRoot()

      To be called from non-root processes at the same time that the root 
      process is calling :cpp:func:`CopyFromRoot`.

Some special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:class:`DistMatrix\<T,U,V>`.

.. cpp:class:: DistMatrix<double,U,V>
.. cpp:class:: DistMatrix<double>
.. cpp:class:: DistMatrix<double,CIRC,CIRC>
.. cpp:class:: DistMatrix<double,MC,MR>
.. cpp:class:: DistMatrix<double,MC,STAR>
.. cpp:class:: DistMatrix<double,MD,STAR>
.. cpp:class:: DistMatrix<double,MR,MC>
.. cpp:class:: DistMatrix<double,MR,STAR>
.. cpp:class:: DistMatrix<double,STAR,MC>
.. cpp:class:: DistMatrix<double,STAR,MD>
.. cpp:class:: DistMatrix<double,STAR,MR>
.. cpp:class:: DistMatrix<double,STAR,STAR>
.. cpp:class:: DistMatrix<double,STAR,VC>
.. cpp:class:: DistMatrix<double,STAR,VR>
.. cpp:class:: DistMatrix<double,VC,STAR>
.. cpp:class:: DistMatrix<double,VR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:class:: DistMatrix<Complex<double>,U,V>
.. cpp:class:: DistMatrix<Complex<double>>
.. cpp:class:: DistMatrix<Complex<double>,CIRC,CIRC>
.. cpp:class:: DistMatrix<Complex<double>,MC,MR>
.. cpp:class:: DistMatrix<Complex<double>,MC,STAR>
.. cpp:class:: DistMatrix<Complex<double>,MD,STAR>
.. cpp:class:: DistMatrix<Complex<double>,MR,MC>
.. cpp:class:: DistMatrix<Complex<double>,MR,STAR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MC>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MD>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,STAR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,VC>
.. cpp:class:: DistMatrix<Complex<double>,STAR,VR>
.. cpp:class:: DistMatrix<Complex<double>,VC,STAR>
.. cpp:class:: DistMatrix<Complex<double>,VR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:class:: DistMatrix<Real,U,V>
.. cpp:class:: DistMatrix<Real>
.. cpp:class:: DistMatrix<Real,CIRC,CIRC>
.. cpp:class:: DistMatrix<Real,MC,MR>
.. cpp:class:: DistMatrix<Real,MC,STAR>
.. cpp:class:: DistMatrix<Real,MD,STAR>
.. cpp:class:: DistMatrix<Real,MR,MC>
.. cpp:class:: DistMatrix<Real,MR,STAR>
.. cpp:class:: DistMatrix<Real,STAR,MC>
.. cpp:class:: DistMatrix<Real,STAR,MD>
.. cpp:class:: DistMatrix<Real,STAR,MR>
.. cpp:class:: DistMatrix<Real,STAR,STAR>
.. cpp:class:: DistMatrix<Real,STAR,VC>
.. cpp:class:: DistMatrix<Real,STAR,VR>
.. cpp:class:: DistMatrix<Real,VC,STAR>
.. cpp:class:: DistMatrix<Real,VR,STAR>

   The underlying datatype, `Real`, is real (as opposed to complex).

.. cpp:class:: DistMatrix<Complex<Real>,U,V>
.. cpp:class:: DistMatrix<Complex<Real>>
.. cpp:class:: DistMatrix<Complex<Real>,CIRC,CIRC>
.. cpp:class:: DistMatrix<Complex<Real>,MC,MR>
.. cpp:class:: DistMatrix<Complex<Real>,MC,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,MD,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,MR,MC>
.. cpp:class:: DistMatrix<Complex<Real>,MR,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MC>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MD>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VC>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VR>
.. cpp:class:: DistMatrix<Complex<Real>,VC,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,VR,STAR>

   The underlying datatype, :cpp:type:`Complex\<Real>`, is complex with base 
   type `Real`. 

.. cpp:class:: DistMatrix<F,U,V>
.. cpp:class:: DistMatrix<F>
.. cpp:class:: DistMatrix<F,CIRC,CIRC>
.. cpp:class:: DistMatrix<F,MC,MR>
.. cpp:class:: DistMatrix<F,MC,STAR>
.. cpp:class:: DistMatrix<F,MD,STAR>
.. cpp:class:: DistMatrix<F,MR,MC>
.. cpp:class:: DistMatrix<F,MR,STAR>
.. cpp:class:: DistMatrix<F,STAR,MC>
.. cpp:class:: DistMatrix<F,STAR,MD>
.. cpp:class:: DistMatrix<F,STAR,MR>
.. cpp:class:: DistMatrix<F,STAR,STAR>
.. cpp:class:: DistMatrix<F,STAR,VC>
.. cpp:class:: DistMatrix<F,STAR,VR>
.. cpp:class:: DistMatrix<F,VC,STAR>
.. cpp:class:: DistMatrix<F,VR,STAR>

   The underlying datatype, `F`, is a field.

.. cpp:class:: DistMatrix<int,U,V>
.. cpp:class:: DistMatrix<int>
.. cpp:class:: DistMatrix<int,CIRC,CIRC>
.. cpp:class:: DistMatrix<int,MC,MR>
.. cpp:class:: DistMatrix<int,MC,STAR>
.. cpp:class:: DistMatrix<int,MD,STAR>
.. cpp:class:: DistMatrix<int,MR,MC>
.. cpp:class:: DistMatrix<int,MR,STAR>
.. cpp:class:: DistMatrix<int,STAR,MC>
.. cpp:class:: DistMatrix<int,STAR,MD>
.. cpp:class:: DistMatrix<int,STAR,MR>
.. cpp:class:: DistMatrix<int,STAR,STAR>
.. cpp:class:: DistMatrix<int,STAR,VC>
.. cpp:class:: DistMatrix<int,STAR,VR>
.. cpp:class:: DistMatrix<int,VC,STAR>
.. cpp:class:: DistMatrix<int,VR,STAR>

   The underlying datatype is a signed integer (of standard size).

