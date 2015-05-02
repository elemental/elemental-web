PBLAS
=====

Level 2
-------

Gemv
^^^^

.. cpp:function:: void pblas::Gemv( char trans, int m, int n, F alpha, const F* A, const int* desca, const F* x, const int* descx, int incx, F beta, F* y, const int* descy, int incy )

Hemv
^^^^

.. cpp:function:: void pblas::Hemv( char uplo, int n, F alpha, const F* A, const int* desca, const F* x, const int* descx, int incx, F beta, F* y, const int* descy, int incy )

Symv
^^^^

.. cpp:function:: void pblas::Symv( char uplo, int n, F alpha, const F* A, const int* desca, const F* x, const int* descx, int incx, F beta, F* y, const int* descy, int incy )

   .. note::

      ScaLAPACK does not provide complex versions of Symv.

Trmv
^^^^

.. cpp:function:: void pblas::Trmv( char uplo, char trans, char diag, int n, const F* A, const int* desca, F* x, const int* descx, int incx )

Trsv
^^^^

.. cpp:function:: void pblas::Trsv( char uplo, char trans, char diag, int n, const F* A, const int* desca, F* x, const int* descx, int incx )

Level 3
-------

Gemm
^^^^

.. cpp:function:: void pblas::Gemm( char transa, char transb, int m, int n, int k, F alpha, const F* A, const int* desca, const F* B, const int* descb, F beta, F* C, const int* descc )

Trmm
^^^^

.. cpp:function:: void pblas::Trmm( char side, char uplo, char trans, char diag, int m, int n, F alpha, const F* A, const int* desca, F* B, const int* descb )

Trsm
^^^^

.. cpp:function:: void pblas::Trsm( char side, char uplo, char trans, char diag, int m, int n, F alpha, const F* A, const int* desca, F* B, const int* descb )
