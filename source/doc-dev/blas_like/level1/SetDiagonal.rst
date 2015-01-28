SetDiagonal
===========
.. note::
   
   This is not a standard BLAS routine.

Sets a diagonal of a matrix equal to a particular vector.

C++ API
-------
.. cpp:function:: void SetDiagonal( Matrix<T>& A, const Matrix<T>& d, Int offset=0 )
.. cpp:function:: void SetDiagonal( DistMatrix<T,U,V>& A, const AbstractDistMatrix<T>& d, Int offset=0 )

.. cpp:function:: void SetRealPartOfDiagonal( Matrix<T>& A, const Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void SetRealPartOfDiagonal( DistMatrix<T,U,V>& A, const AbstractDistMatrix<Base<T>>& d, Int offset=0 )

.. cpp:function:: void SetImagPartOfDiagonal( Matrix<T>& A, const Matrix<Base<T>>& d, Int offset=0 )
.. cpp:function:: void SetImagPartOfDiagonal( DistMatrix<T,U,V>& A, const AbstractDistMatrix<Base<T>>& d, Int offset=0 )

C API
-----
**TODO**

Python API
----------
**TODO**
