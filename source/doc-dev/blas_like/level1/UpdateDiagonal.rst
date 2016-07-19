UpdateDiagonal
==============
Adds a multiple of a given vector to a diagonal of a matrix.

C++ API
-------
.. cpp:function:: void UpdateDiagonal( Matrix<T>& A, T alpha, const Matrix<T>& d, Int offset=0 )
.. cpp:function:: void UpdateDiagonal( DistMatrix<T,U,V>& A, T alpha, const AbstractDistMatrix<T>& d, Int offset=0 )

.. cpp:function:: void UpdateRealPartOfDiagonal( Matrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void UpdateRealPartOfDiagonal( DistMatrix<T,U,V>& A, Base<T> alpha, const AbstractDistMatrix<Base<T>>& d, Int offset=0 )

.. cpp:function:: void UpdateImagPartOfDiagonal( Matrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void UpdateImagPartOfDiagonal( DistMatrix<T,U,V>& A, Base<T> alpha, const AbstractDistMatrix<Base<T>>& d, Int offset=0 )

C API
-----
**TODO**

Python API
----------
**TODO**
