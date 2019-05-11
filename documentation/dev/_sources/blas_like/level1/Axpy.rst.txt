Axpy
====
Update a matrix :math:`Y` with :math:`\alpha X`, i.e.,

.. math::

   Y := \alpha X + Y,

which is the reason for the name *axpy*: "alpha X plus Y".

C++ API
-------
.. cpp:function:: void Axpy( S alpha, const Matrix<T>& X, Matrix<T>& Y )
.. cpp:function:: void Axpy( S alpha, const AbstractDistMatrix<T>& X, AbstractDistMatrix<T>& Y )
.. cpp:function:: void Axpy( S alpha, const SparseMatrix<T>& X, SparseMatrix<T>& Y )
.. cpp:function:: void Axpy( S alpha, const DistSparseMatrix<T>& X, DistSparseMatrix<T>& Y )
.. cpp:function:: void Axpy( T alpha, const DistMultiVec<T>& X, DistMultiVec<T>& Y )

C API
-----
.. c:function:: ElError ElAxpy_i( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElAxpy_s( float alpha, ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElAxpy_d( double alpha, ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElAxpy_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAxpy_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAxpyDist_i( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElAxpyDist_s( float alpha, ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElAxpyDist_d( double alpha, ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElAxpyDist_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAxpyDist_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAxpySparse_i( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElAxpySparse_s( float alpha, ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElAxpySparse_d( double alpha, ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElAxpySparse_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAxpySparse_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAxpyDistSparse_i( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElAxpyDistSparse_s( float alpha, ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElAxpyDistSparse_d( double alpha, ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElAxpyDistSparse_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAxpyDistSparse_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElAxpyDistMultiVec_i( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElAxpyDistMultiVec_s( float alpha, ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElAxpyDistMultiVec_d( double alpha, ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElAxpyDistMultiVec_c( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElAxpyDistMultiVec_z( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y )

Python API
----------
.. py:function:: Axpy(alpha,X,Y)
