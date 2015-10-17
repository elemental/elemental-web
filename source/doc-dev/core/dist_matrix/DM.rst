DistMatrix
==========
The :cpp:class:`DistMatrix\<scalarType=double,colDist=MC,rowDist=MR,wrapType=ELEMENT>` class, which is a derivation from
:cpp:class:`AbstractDistMatrix\<scalarType>`,
is specialized for each of the thirteen different legal distribution pairs.
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

.. cpp:class:: DistMatrix<scalarType=double,colDist=MC,rowDist=MR,wrapType=ELEMENT>

   The following routines are available for each legal pairing of row and column
   distributions.

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMatrix( const Grid& grid=DefaultGrid(), Int root=0 )

      Construct an empty (:math:`0 \times 0`) distributed matrix.

   .. cpp:function:: DistMatrix( Int height, Int width, const Grid& grid=DefaultGrid(), Int root=0 )

      Create a `height` :math:`\times` `width` distributed matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<scalarType,colDist2,rowDist2>& A )

      Construct the current matrix to be a redistributed copy of the input 
      matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<scalarType,colDist,rowDist>&& A ) noexcept

      Use C++11 move semantics to construct the current matrix in a way which
      transfers the resources from the input matrix.

   .. cpp:function:: ~DistMatrix()

      All resources owned by the `DistMatrix` are freed upon destruction.

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist>& operator=( const DistMatrix<scalarType,colDist2,rowDist2>& A )

      Set the current distributed matrix equal to the matrix `A` redistributed
      into the appropriate form.

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist>& operator=( DistMatrix<scalarType,colDist,rowDist>&& A )

      A C++11 move assignment which cheaply transfers the resources from `A`
      to the current matrix by swapping metadata.

   .. rubric:: Viewing

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist> operator()( Range<Int> I, Range<Int> J )

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist> operator()( Range<Int> I, Range<Int> J ) const


.. toctree::
   :maxdepth: 1

   DM/MC_MR
   DM/MC_STAR
   DM/MD_STAR
   DM/MR_MC
   DM/MR_STAR
   DM/STAR_MC
   DM/STAR_MD
   DM/STAR_MR
   DM/STAR_STAR
   DM/STAR_VC
   DM/STAR_VR
   DM/VC_STAR
   DM/VR_STAR
   DM/CIRC_CIRC
   DM/special
