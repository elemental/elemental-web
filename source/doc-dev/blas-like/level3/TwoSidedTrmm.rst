Two-sided Trmm
==============
Performs a two-sided triangular multiplication with multiple right-hand sides 
which preserves the symmetry of the input matrix, 
either :math:`A := L^H A L` or :math:`A := U A U^H`.

.. note::

   For the best performance, `A` and `B` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void TwoSidedTrmm( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<T>& A, const Matrix<T>& B )
.. cpp:function:: void TwoSidedTrmm( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B )

C API
-----

.. c:function:: ElError ElTwoSidedTrmm_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A, ElConstMatrix_s B )
.. c:function:: ElError ElTwoSidedTrmm_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A, ElConstMatrix_d B )
.. c:function:: ElError ElTwoSidedTrmm_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A, ElConstMatrix_c B )
.. c:function:: ElError ElTwoSidedTrmm_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A, ElConstMatrix_z B )
.. c:function:: ElError ElTwoSidedTrmmDist_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_s A, ElConstDistMatrix_s B )
.. c:function:: ElError ElTwoSidedTrmmDist_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_d A, ElConstDistMatrix_d B )
.. c:function:: ElError ElTwoSidedTrmmDist_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_c A, ElConstDistMatrix_c B )
.. c:function:: ElError ElTwoSidedTrmmDist_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_z A, ElConstDistMatrix_z B )
