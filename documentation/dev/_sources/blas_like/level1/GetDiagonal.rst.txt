GetDiagonal
===========
Return a diagonal of a matrix as a vector.

C++ API
-------
.. cpp:function:: void GetDiagonal( const Matrix<T>& A, Matrix<T>& d, Int offset=0 )
.. cpp:function:: void GetDiagonal( const DistMatrix<T,U,V>& A, AbstractDistMatrix<T>& d, Int offset=0 )

.. cpp:function:: void GetRealPartOfDiagonal( const Matrix<T>& A, Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void GetRealPartOfDiagonal( const DistMatrix<T,U,V>& A, AbstractDistMatrix<Base<T>>& d, Int offset=0 )

.. cpp:function:: void GetImagPartOfDiagonal( const Matrix<T>& A, Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void GetImagPartOfDiagonal( const DistMatrix<T,U,V>& A, AbstractDistMatrix<Base<T>>& d, Int offset=0 )

.. cpp:function:: Matrix<T> GetDiagonal( const Matrix<T>& A, Int offset=0 )
.. cpp:function:: DistMatrix<T,DiagCol<U,V>(),DiagRow<U,V>()> GetDiagonal( const DistMatrix<T,U,V>& A, Int offset=0 )

.. cpp:function:: Matrix<Base<T>> GetRealPartOfDiagonal( const Matrix<T>& A, Int offset=0 )
.. cpp:function:: DistMatrix<Base<T>,DiagCol<U,V>(),DiagRow<U,V>()> GetRealPartOfDiagonal( const DistMatrix<T,U,V>& A, Int offset=0 )

.. cpp:function:: Matrix<Base<T>> GetImagPartOfDiagonal( const Matrix<T>& A, Int offset=0 )
.. cpp:function:: DistMatrix<Base<T>,DiagCol<U,V>(),DiagRow<U,V>()> GetImagPartOfDiagonal( const DistMatrix<T,U,V>& A, Int offset=0 )

C API
-----
**TODO**

Python API
----------
**TODO**
