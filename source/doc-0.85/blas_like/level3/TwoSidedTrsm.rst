Two-sided Trsm
==============
Performs a two-sided triangular solves with multiple right-hand sides which 
preserves the symmetry of the input matrix, 
either :math:`A := L^{-1} A L^{-H}` or :math:`A := U^{-H} A U^{-1}`.

.. note::

   For the best performance, `A` and `B` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void TwoSidedTrsm( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: void TwoSidedTrsm( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B )

C API
-----

.. c:function:: ElError ElTwoSidedTrsm_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A, ElConstMatrix_s B )
.. c:function:: ElError ElTwoSidedTrsm_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A, ElConstMatrix_d B )
.. c:function:: ElError ElTwoSidedTrsm_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A, ElConstMatrix_c B )
.. c:function:: ElError ElTwoSidedTrsm_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A, ElConstMatrix_z B )
.. c:function:: ElError ElTwoSidedTrsmDist_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_s A, ElConstDistMatrix_s B )
.. c:function:: ElError ElTwoSidedTrsmDist_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_d A, ElConstDistMatrix_d B )
.. c:function:: ElError ElTwoSidedTrsmDist_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_c A, ElConstDistMatrix_c B )
.. c:function:: ElError ElTwoSidedTrsmDist_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElDistMatrix_z A, ElConstDistMatrix_z B )

Python API
----------

.. py:function:: TwoSidedTrsm(uplo,diag,A,B)
