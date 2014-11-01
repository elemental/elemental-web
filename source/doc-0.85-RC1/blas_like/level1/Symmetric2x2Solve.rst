Symmetric2x2Solve
=================
Apply the inverse of a 2x2 symmetric (Hermitian) matrix to the matrix A.

.. note::

   This is not a standard BLAS routine.

C++ API
-------

.. cpp:function:: void Symmetric2x2Solve( LeftOrRight side, UpperOrLower uplo, const Matrix<F>& D, Matrix<F>& A, bool conjugate=false )
.. cpp:function:: void Symmetric2x2Solve( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& A, bool conjugate=false )

C API
-----

**TODO**

