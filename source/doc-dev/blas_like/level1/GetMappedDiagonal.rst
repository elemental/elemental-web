GetMappedDiagonal
=================
.. note::
   
   This is not a standard BLAS routine.

Return a function of a diagonal of a matrix as a vector.

C++ API
-------
.. cpp:function:: void GetMappedDiagonal( const Matrix<T>& A, Matrix<S>& d, std::function<S(T)> func, Int offset=0 )
.. cpp:function:: void GetMappedDiagonal( const DistMatrix<T,U,V>& A, AbstractDistMatrix<S>& d, std::function<S(T)> func, Int offset=0 )

C API
-----
**TODO**

Python API
----------
**TODO**
