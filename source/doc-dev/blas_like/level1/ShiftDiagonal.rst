ShiftDiagonal
=============
Adds a given value to a diagonal of a matrix.

C++ API
-------
.. cpp:function:: void ShiftDiagonal( Matrix<T>& A, S alpha, Int offset=0 )
.. cpp:function:: void ShiftDiagonal( AbstractDistMatrix<T>& A, S alpha, Int offset=0 )
.. cpp:function:: void ShiftDiagonal( AbstractBlockDistMatrix<T>& A, S alpha, Int offset=0 )
.. cpp:function:: void ShiftDiagonal( SparseMatrix<T>& A, S alpha, Int offset=0 )
.. cpp:function:: void ShiftDiagonal( DistSparseMatrix<T>& A, S alpha, Int offset=0 )

C API
-----
.. c:function:: ElError ElShiftDiagonal_i( ElMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonal_s( ElMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonal_d( ElMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonal_c( ElMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonal_z( ElMatrix_z A, complex_double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDist_i( ElDistMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDist_s( ElDistMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDist_d( ElDistMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDist_c( ElDistMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDist_z( ElDistMatrix_z A, complex_double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalSparse_i( ElSparseMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalSparse_s( ElSparseMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalSparse_d( ElSparseMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalSparse_c( ElSparseMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalSparse_z( ElSparseMatrix_z A, complex_double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDistSparse_i( ElDistSparseMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDistSparse_s( ElDistSparseMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDistSparse_d( ElDistSparseMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDistSparse_c( ElDistSparseMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElShiftDiagonalDistSparse_z( ElDistSparseMatrix_z A, complex_double alpha, ElInt offset )

Python API
----------
.. py:function:: ShiftDiagonal(A,alpha,offset=0)
