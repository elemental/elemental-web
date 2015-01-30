FillDiagonal
============
Fills all of the diagonal entries of a matrix to a given value.

C++ API
-------
.. cpp:function:: void FillDiagonal( Matrix<T>& A, T alpha, Int offset=0 )
.. cpp:function:: void FillDiagonal( AbstractDistMatrix<T>& A, T alpha, Int offset=0 )
.. cpp:function:: void FillDiagonal( AbstractBlockDistMatrix<T>& A, T alpha, Int offset=0 )

C API
-----
.. c:function:: ElError ElFillDiagonal_i( ElMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonal_s( ElMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonal_d( ElMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonal_c( ElMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonal_z( ElMatrix_z A, complex_double alpha, ElInt offset )

.. c:function:: ElError ElFillDiagonalDist_i( ElDistMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonalDist_s( ElDistMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonalDist_d( ElDistMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonalDist_c( ElDistMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElFillDiagonalDist_z( ElDistMatrix_z A, complex_double alpha, ElInt offset )

Python API
----------
.. py:function:: FillDiagonal(A,alpha,offset=0)
