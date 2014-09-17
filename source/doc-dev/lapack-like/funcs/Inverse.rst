Direct inversion
================

Triangular
----------
Inverts a (possibly unit-diagonal) triangular matrix in-place. If
`diag` is set to `UNIT`, then `A` is treated as having ones on its diagonal.

C++ API
^^^^^^^

.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<F>& A )
.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElTriangularInverse_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A )
.. c:function:: ElError ElTriangularInverse_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A )
.. c:function:: ElError ElTriangularInverse_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A )
.. c:function:: ElError ElTriangularInverse_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A )
.. c:function:: ElError ElTriangularInverseDist_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A )
.. c:function:: ElError ElTriangularInverseDist_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A )
.. c:function:: ElError ElTriangularInverseDist_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A )
.. c:function:: ElError ElTriangularInverseDist_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A )

General
-------
This routine computes the in-place inverse of a general fully-populated
(invertible) matrix :math:`A` as

.. math::

   A^{-1} = U^{-1} L^{-1} P,

where :math:`PA=LU` is the result of LU factorization with partial pivoting.
The algorithm essentially factors :math:`A`, inverts :math:`U` in place,
solves against :math:`L` one block column at a time, and then applies the
row pivots in reverse order to the columns of the result.

C++ API
^^^^^^^

.. cpp:function:: void Inverse( Matrix<F>& A )
.. cpp:function:: void Inverse( AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElInverse_s( ElMatrix_s A )
.. c:function:: ElError ElInverse_d( ElMatrix_d A )
.. c:function:: ElError ElInverse_c( ElMatrix_c A )
.. c:function:: ElError ElInverse_z( ElMatrix_z A )
.. c:function:: ElError ElInverseDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElInverseDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElInverseDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElInverseDist_z( ElDistMatrix_z A )

Symmetric/Hermitian
-------------------

C++ API
^^^^^^^

.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a symmetric or Hermitian matrix using a pivoted LDL factorization.

.. cpp:function:: void HermitianInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a Hermitian matrix using a pivoted LDL factorization.

C API
^^^^^

.. c:function:: ElError ElSymmetricInverse_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElSymmetricInverse_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElSymmetricInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElSymmetricInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElSymmetricInverseDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElSymmetricInverseDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElSymmetricInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElSymmetricInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

   Invert a symmetric matrix using a pivoted LDLT factorization.

.. c:function:: ElError ElHermitianInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHermitianInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

   Invert a Hermitian matrix using a pivoted LDLH factorization.

HPD 
---
This routine uses a custom algorithm for computing the inverse of a
Hermitian positive-definite matrix :math:`A` as

.. math::

   A^{-1} = (L L^H)^{-1} = L^{-H} L^{-1}, 

where :math:`L` is the lower Cholesky factor of :math:`A` (the upper Cholesky
factor is computed in the case of upper-triangular storage). Rather than
performing Cholesky factorization, triangular inversion, and then the Hermitian
triangular outer product in sequence, this routine makes use of the single-sweep
algorithm described in Bientinesi et al.'s "Families of algorithms related to
the inversion of a symmetric positive definite matrix", in particular, the
variant 2 algorithm from Fig. 9.

If the matrix is found to not be HPD, then a :cpp:type:`NonHPDMatrixException`
is thrown.

C++ API
^^^^^^^

.. cpp:function:: void HPDInverse( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPDInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElHPDInverse_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHPDInverse_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHPDInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHPDInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHPDInverseDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHPDInverseDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHPDInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHPDInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

