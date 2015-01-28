UpdateSubmatrix
===============
.. note::
   
   This is not a standard BLAS routine.

Adds a multiple of a matrix to a (possibly non-contiguous) submatrix of 
another matrix.

C++ API
-------

.. cpp:function:: void UpdateSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, T alpha, const Matrix<T>& ASub )
.. cpp:function:: void UpdateSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, T alpha, const AbstractDistMatrix<T>& ASub )

.. cpp:function:: void UpdateRealPartOfSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Base<T> alpha, const Matrix<Base<T>>& ASub )
.. cpp:function:: void UpdateRealPartOfSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Base<T> alpha, const AbstractDistMatrix<Base<T>>& ASub )

.. cpp:function:: void UpdateImagPartOfSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Base<T> alpha, const Matrix<Base<T>>& ASub )
.. cpp:function:: void UpdateImagPartOfSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Base<T> alpha, const AbstractDistMatrix<Base<T>>& ASub )

C API
-----
**TODO**

Python API
----------
**TODO**
