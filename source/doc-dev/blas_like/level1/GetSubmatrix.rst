GetSubmatrix
============
.. note::
   
   This is not a standard BLAS routine.

Gets a (possibly non-contiguous) submatrix of a given matrix.

C++ API
-------
.. cpp:function:: void GetSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Matrix<T>& ASub )
.. cpp:function:: void GetSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, AbstractDistMatrix<T>& ASub )

.. cpp:function:: void GetRealPartOfSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Matrix<Base<T>>& ASub )
.. cpp:function:: void GetRealPartOfSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, AbstractDistMatrix<Base<T>>& ASub )

.. cpp:function:: void GetImagPartOfSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Matrix<Base<T>>& ASub )
.. cpp:function:: void GetImagPartOfSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, AbstractDistMatrix<Base<T>>& ASub )

.. cpp:function:: Matrix<T> GetSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )
.. cpp:function:: DistMatrix<T,STAR,STAR> GetSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )

.. cpp:function:: Matrix<Base<T>> GetRealPartOfSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )
.. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetRealPartOfSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )

.. cpp:function:: Matrix<Base<T>> GetImagPartOfSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )
.. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetImagPartOfSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )

C API
-----
**TODO**

Python API
----------
**TODO**
