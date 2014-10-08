Axpy
====
Performs :math:`Y := \alpha X + Y` (hence the name *axpy*).

C++ API
-------

.. cpp:function:: void Axpy( S alpha, const Matrix<T>& X, Matrix<T>& Y )
.. cpp:function:: void Axpy( S alpha, const AbstractDistMatrix<T>& X, AbstractDistMatrix<T>& Y )
.. cpp:function:: void Axpy( T alpha, const MultiVec<T>& X, MultiVec<T>& Y )
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
