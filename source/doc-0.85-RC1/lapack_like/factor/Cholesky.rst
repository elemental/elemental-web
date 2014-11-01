Cholesky factorization
======================
It is well-known that Hermitian positive-definite (HPD) matrices can be 
decomposed into the form :math:`A = L L^H` or :math:`A = U^H U`, where 
:math:`L=U^H` is lower triangular, and Cholesky factorization provides such an 
:math:`L` (or :math:`U`) given an HPD :math:`A`. If :math:`A` is found to be 
numerically indefinite, then a :cpp:type:`NonHPDMatrixException` will be 
thrown.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/Cholesky.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack_like/factor/Cholesky>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/Cholesky.cpp>`__

Without pivoting
----------------
The following routines overwrite the `uplo` triangle of the Hermitian 
positive-definite matrix `A` with its Cholesky factor without performing any
pivoting.

Factorization
^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Cholesky( UpperOrLower uplo, AbstractDistMatrix<F>& A )


C API
"""""

.. c:function:: ElError ElCholesky_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElCholesky_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElCholesky_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElCholesky_z( ElUpperOrLower uplo, ElMatrix_z A )

.. c:function:: ElError ElCholeskyDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElCholeskyDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElCholeskyDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElCholeskyDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

Solving linear systems with the factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
"""""

.. c:function:: ElError ElSolveAfterCholesky_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterCholesky_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterCholesky_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElSolveAfterCholesky_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElSolveAfterCholeskyDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterCholeskyDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterCholeskyDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElSolveAfterCholeskyDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElDistMatrix_z B )

Full pivoting
-------------
The following routines perform Cholesky factorization with diagonal pivoting,
which can be shown to be equivalent to full pivoting for Hermitian 
positive-definite matrices. On exit, the vector :math:`p` consists of the 
nonzero column indices of the permutation matrix :math:`P` such that either
:math:`P A P^T = L L^H` or :math:`P A P^T = U^H U`.

Factorization
^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void Cholesky( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p )

C API
"""""

.. c:function:: ElError ElCholeskyPiv_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPiv_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPiv_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPiv_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_i p )

.. c:function:: ElError ElCholeskyPivDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPivDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPivDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElMatrix_i p )
.. c:function:: ElError ElCholeskyPivDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElMatrix_i p )

Solving linear systems with the factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B, Matrix<int>& p )
.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<int>& p )

C API
"""""

.. c:function:: ElError ElSolveAfterCholeskyPiv_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_i p, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterCholeskyPiv_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_i p, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterCholeskyPiv_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_i p, ElMatrix_c B )
.. c:function:: ElError ElSolveAfterCholeskyPiv_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_i p, ElMatrix_z B )

.. c:function:: ElError ElSolveAfterCholeskyPivDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_i p, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterCholeskyPivDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_i p, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterCholeskyPivDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_i p, ElDistMatrix_c B )
.. c:function:: ElError ElSolveAfterCholeskyPivDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_i p, ElDistMatrix_z B )

Low-rank updates to a factorization
-----------------------------------
The following routines update an existing Cholesky factorization to incorporate
the modification :math:`\alpha V V^H` to the original matrix. The current 
algorithm uses Householder transformations for updates (:math:`\alpha \ge 0`) 
and hyperbolic Householder transformations for downdates.

C++ API
^^^^^^^

.. cpp:function:: void CholeskyMod( UpperOrLower uplo, Matrix<F>& T, Base<F>& alpha, Matrix<F>& V )
.. cpp:function:: void CholeskyMod( UpperOrLower uplo, AbstractDistMatrix<F>& T, Base<F>& alpha, AbstractDistMatrix<F>& V )

C API
^^^^^

.. c:function:: ElError ElCholeskyMod_s( ElUpperOrLower uplo, ElMatrix_s T, float alpha, ElMatrix_s V )
.. c:function:: ElError ElCholeskyMod_d( ElUpperOrLower uplo, ElMatrix_d T, double alpha, ElMatrix_d V )
.. c:function:: ElError ElCholeskyMod_c( ElUpperOrLower uplo, ElMatrix_c T, float alpha, ElMatrix_c V )
.. c:function:: ElError ElCholeskyMod_z( ElUpperOrLower uplo, ElMatrix_z T, double alpha, ElMatrix_z V )

.. c:function:: ElError ElCholeskyModDist_s( ElUpperOrLower uplo, ElDistMatrix_s T, float alpha, ElDistMatrix_s V )
.. c:function:: ElError ElCholeskyModDist_d( ElUpperOrLower uplo, ElDistMatrix_d T, double alpha, ElDistMatrix_d V )
.. c:function:: ElError ElCholeskyModDist_c( ElUpperOrLower uplo, ElDistMatrix_c T, float alpha, ElDistMatrix_c V )
.. c:function:: ElError ElCholeskyModDist_z( ElUpperOrLower uplo, ElDistMatrix_z T, double alpha, ElDistMatrix_z V )

Rank-deficient factorization
----------------------------

It is possible to compute the Cholesky factor of a Hermitian positive
semi-definite (HPSD) matrix through its eigenvalue decomposition, though it
is significantly more expensive than the HPD case: Let :math:`A = U \Lambda U^H`
be the eigenvalue decomposition of :math:`A`, where all entries of
:math:`\Lambda` are non-negative. Then :math:`B = U \sqrt \Lambda U^H` is the
matrix square root of :math:`A`, i.e., :math:`B B = A`, and it follows that the
QR and LQ factorizations of :math:`B` yield Cholesky factors of :math:`A`:

.. math::
   A = B B = B^H B = (Q R)^H (Q R) = R^H Q^H Q R = R^H R,

and

.. math::
   A = B B = B B^H = (L Q) (L Q)^H = L Q Q^H L^H = L L^H.

If :math:`A` is found to have eigenvalues less than
:math:`-n \epsilon \| A \|_2`, then a :cpp:type:`NonHPSDMatrixException` will
be thrown.

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/HPSDCholesky.cpp>`__

The following routines overwrite the `uplo` triangle of the potentially 
singular matrix `A` with its Cholesky factor.

C++ API
^^^^^^^

.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElHPSDCholesky_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHPSDCholesky_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHPSDCholesky_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHPSDCholesky_z( ElUpperOrLower uplo, ElMatrix_z A )

.. c:function:: ElError ElHPSDCholeskyDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHPSDCholeskyDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHPSDCholeskyDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHPSDCholeskyDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )
