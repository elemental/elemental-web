Transpose
=========
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^T` or :math:`B := A^H`. 

C++ API
-------

.. cpp:function:: void Transpose( const Matrix<T>& A, Matrix<T>& B, bool conjugate=false )
.. cpp:function:: void Transpose( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )
.. cpp:function:: void Transpose( const SparseMatrix<T>& A, SparseMatrix<T>& B, bool conjugate=false )
.. cpp:function:: void Transpose( const DistSparseMatrix<T>& A, DistSparseMatrix<T>& B, bool conjugate=false )

C API
-----

.. c:function:: ElError ElTranspose_i( ElConstMatrix_i A, ElMatrix_i B )
.. c:function:: ElError ElTranspose_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElTranspose_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElTranspose_c( ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElTranspose_z( ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElTransposeDist_i( ElConstDistMatrix_i A, ElDistMatrix_i B )
.. c:function:: ElError ElTransposeDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElTransposeDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElTransposeDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElTransposeDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B )
.. c:function:: ElError ElTransposeSparse_i( ElConstSparseMatrix_i A, ElSparseMatrix_i B )
.. c:function:: ElError ElTransposeSparse_s( ElConstSparseMatrix_s A, ElSparseMatrix_s B )
.. c:function:: ElError ElTransposeSparse_d( ElConstSparseMatrix_d A, ElSparseMatrix_d B )
.. c:function:: ElError ElTransposeSparse_c( ElConstSparseMatrix_c A, ElSparseMatrix_c B )
.. c:function:: ElError ElTransposeSparse_z( ElConstSparseMatrix_z A, ElSparseMatrix_z B )
.. c:function:: ElError ElTransposeDistSparse_i( ElConstDistSparseMatrix_i A, ElDistSparseMatrix_i B )
.. c:function:: ElError ElTransposeDistSparse_s( ElConstDistSparseMatrix_s A, ElDistSparseMatrix_s B )
.. c:function:: ElError ElTransposeDistSparse_d( ElConstDistSparseMatrix_d A, ElDistSparseMatrix_d B )
.. c:function:: ElError ElTransposeDistSparse_c( ElConstDistSparseMatrix_c A, ElDistSparseMatrix_c B )
.. c:function:: ElError ElTransposeDistSparse_z( ElConstDistSparseMatrix_z A, ElDistSparseMatrix_z B )

Python API
----------

.. py:function:: Transpose(A,B,conjugate=False)
