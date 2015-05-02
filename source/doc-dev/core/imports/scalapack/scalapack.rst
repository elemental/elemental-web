ScaLAPACK proper
================

Factorizations
--------------

Cholesky
^^^^^^^^

.. cpp:function:: void scalapack::Cholesky( char uplo, int n, F* A, const int* desca )

Spectral analysis
-----------------

Reduction of a generalized HPD EVP to standard form
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Two-sided Trsm
""""""""""""""
.. cpp:function:: void TwoSidedTrsm( char uplo, int n, F* A, const int* desca, const F* B, const int* descb )

Two-sided Trmm
""""""""""""""
.. cpp:function:: void TwoSidedTrmm( char uplo, int n, F* A, const int* desca, const F* B, const int* descb )

Hessenberg Schur decomposition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void scalapack::HessenbergSchur( int n, F* H, int* desch, Complex<Base<F>>* w, bool fullTriangle=false, bool aed=false )

   Computes the eigenvalues (and possibly the full Schur factor) of an upper 
   Hessenberg matrix using the QR algorithm. Aggressive Early Deflation may
   be optionally used for real matrices, but there are known bugs in the 
   ScaLAPACK implementation.

.. cpp:function:: void scalapack::HessenbergSchur( int n, F* H, int* desch, Complex<Base<F>>* w, F* Q, int* descq, bool fullTriangle=true, bool multiplyQ=false, bool aed=false )

   Computes the eigenvalues (and possibly the full Schur factor) as well as 
   the Schur vectors of of an upper Hessenberg matrix using the QR algorithm.
   If `multiplyQ` is true, then the Schur vectors are multiplied against the
   input matrix from the right. Aggressive Early Deflation may
   be optionally used for real matrices, but there are known bugs in the 
   ScaLAPACK implementation.

Hessenberg eigenvalues
^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void scalapack::HessenbergEig( int n, F* H, int* desch, Complex<Base<F>>* w )

   Computes the eigenvalues of an upper Hessenberg matrix using the QR 
   algorithm.

.. note::

   There are not yet wrappers for computing Hessenberg eigenvectors.
