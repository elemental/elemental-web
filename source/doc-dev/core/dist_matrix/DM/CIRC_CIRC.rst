``[CIRC,CIRC]``
===============
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

   Only the following public member functions are new relative to 
   :cpp:type:`AbstractDistMatrix\<T>`

   .. cpp:function:: DistMatrix<T,CIRC,CIRC> operator()( Range<Int> I, Range<Int> J )

   .. cpp:function:: const DistMatrix<T,CIRC,CIRC> operator()( Range<Int> I, Range<Int> J ) const

   .. cpp:function:: void CopyFromRoot( const Matrix<T>& A )

      To be called from the root process in order to assign a sequential matrix to
      a ``[CIRC,CIRC]`` "distributed" matrix.

   .. cpp:function:: void CopyFromNonRoot()

      To be called from non-root processes at the same time that the root process
      is calling :cpp:func:`CopyFromRoot`.
