Adjoint
=======
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^H`. 

C++ API
-------
.. cpp:function:: void Adjoint( const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Adjoint( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )
.. cpp:function:: void Adjoint( const AbstractBlockDistMatrix<T>& A, AbstractBlockDistMatrix<T>& B )
.. cpp:function:: void Adjoint( const SparseMatrix<T>& A, SparseMatrix<T>& B )
.. cpp:function:: void Adjoint( const DistSparseMatrix<T>& A, DistSparseMatrix<T>& B )

adjoint namespace
^^^^^^^^^^^^^^^^^
**TODO**

C API
-----
.. c:function:: ElError ElAdjoint_c( ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElAdjoint_z( ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElAdjointDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElAdjointDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B )
.. c:function:: ElError ElAdjointSparse_c( ElConstSparseMatrix_c A, ElSparseMatrix_c B )
.. c:function:: ElError ElAdjointSparse_z( ElConstSparseMatrix_z A, ElSparseMatrix_z B )
.. c:function:: ElError ElAdjointDistSparse_c( ElConstDistSparseMatrix_c A, ElDistSparseMatrix_c B )
.. c:function:: ElError ElAdjointDistSparse_z( ElConstDistSparseMatrix_z A, ElDistSparseMatrix_z B )

Python API
----------
.. py:function:: Adjoint(A,B)
