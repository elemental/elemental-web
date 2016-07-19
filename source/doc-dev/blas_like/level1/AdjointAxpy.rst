AdjointAxpy
===========
Performs :math:`Y := \alpha X^H + Y` (hence the name *axpy*).

C++ API
-------
.. cpp:function:: void AdjointAxpy( S alpha, const Matrix<T>& X, Matrix<T>& Y )
.. cpp:function:: void AdjointAxpy( S alpha, const AbstractDistMatrix<T>& X, AbstractDistMatrix<T>& Y )
.. cpp:function:: void AdjointAxpy( S alpha, const SparseMatrix<T>& X, SparseMatrix<T>& Y )
.. cpp:function:: void AdjointAxpy( S alpha, const DistSparseMatrix<T>& X, DistSparseMatrix<T>& Y )

adjoint_axpy namespace
^^^^^^^^^^^^^^^^^^^^^^
**TODO**

C API
-----
.. c:function:: ElError ElAdjointAxpy_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAdjointAxpy_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAdjointAxpyDist_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAdjointAxpyDist_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAdjointAxpySparse_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAdjointAxpySparse_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAdjointAxpyDistSparse_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAdjointAxpyDistSparse_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )

Python API
----------
.. py:function:: AdjointAxpy(alpha,X,Y)
