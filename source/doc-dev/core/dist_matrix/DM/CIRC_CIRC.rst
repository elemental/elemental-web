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

.. cpp:type:: DistMatrix<T,CIRC,CIRC>

   Only two public member functions were not described as part of
   :cpp:type:`AbstractDistMatrix\<T>` and :cpp:type:`DistMatrix\<T,U,V>`.

   .. cpp:function:: void CopyFromRoot( const Matrix<T>& A )

      To be called from the root process in order to assign a sequential matrix to
      a ``[CIRC,CIRC]`` "distributed" matrix.

   .. cpp:function:: void CopyFromNonRoot()

      To be called from non-root processes at the same time that the root process
      is calling :cpp:func:`CopyFromRoot`.
