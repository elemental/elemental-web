QuasiDiagonalScale
==================
Apply a symmetric (Hermitian) quasi-diagonal matrix to the matrix X.

.. note::

   This is not a standard BLAS routine.

C++ API
-------

.. cpp:function:: void QuasiDiagonalScale( LeftOrRight side, UpperOrLower uplo, const Matrix<FMain>& d, const Matrix<F>& dSub, Matrix<F>& X, bool conjugate=false )
.. cpp:function:: void QuasiDiagonalScale( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<FMain>& d, const AbstractDistMatrix<F>& dSub, AbstractDistMatrix<F>& X, bool conjugate=false )

C API
-----

**TODO**

