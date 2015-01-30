SetSubmatrix
============
Sets a (possibly non-contiguous) submatrix to a given matrix.
another matrix.

C++ API
-------
.. cpp:function:: void SetSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const Matrix<T>& ASub )
.. cpp:function:: void SetSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const AbstractDistMatrix<T>& ASub )

.. cpp:function:: void SetRealPartOfSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const Matrix<Base<T>>& ASub )
.. cpp:function:: void SetRealPartOfSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const AbstractDistMatrix<Base<T>>& ASub )

.. cpp:function:: void SetImagPartOfSubmatrix( Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const Matrix<Base<T>>& ASub )
.. cpp:function:: void SetImagPartOfSubmatrix( AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, const AbstractDistMatrix<Base<T>>& ASub )

C API
-----
**TODO**

Python API
----------
**TODO**
