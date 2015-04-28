Symmetric/Hermitian
===================

Python API
----------
.. py:function:: SymmetricInverse(uplo,A,conjugate=False)
.. py:function:: HermitianInverse(uplo,A)

C++ API
-------

.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a symmetric or Hermitian matrix using a pivoted LDL factorization.

.. cpp:function:: void HermitianInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a Hermitian matrix using a pivoted LDL factorization.

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSymmetricInverse_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElSymmetricInverseDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSymmetricInverse_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElSymmetricInverseDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSymmetricInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElSymmetricInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )

   Invert a symmetric matrix using a pivoted LDLT factorization.

.. c:function:: ElError ElHermitianInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )

   Invert a Hermitian matrix using a pivoted LDLH factorization.
Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSymmetricInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElSymmetricInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

   Invert a symmetric matrix using a pivoted LDLT factorization.

.. c:function:: ElError ElHermitianInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

   Invert a Hermitian matrix using a pivoted LDLH factorization.
