Trsm
====
Triangular solve with multiple right-hand sides: performs
:math:`C := \alpha A^{-\#} B`, or 
:math:`C := \alpha B A^{-\#}`, depending upon whether `side` was 
chosen to be ``LEFT`` or ``RIGHT``, respectively. Whether :math:`A` is treated 
as lower or upper triangular is determined by `uplo`, and :math:`A^{-\#}` 
can be :math:`A^{-1}`, :math:`A^{-T}`, or :math:`A^{-H}` (and `diag` determines
whether :math:`A` is treated as unit-diagonal or not).

.. note::

   For the best performance, `A` and `B` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Trsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const Matrix<F>& A, Matrix<F>& B )

.. cpp:function:: void Trsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
-----

.. c:function:: ElError ElTrsm_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElTrsm_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElTrsm_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElTrsm_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElTrsmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElTrsmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElTrsmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElTrsmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstDistMatrix_z A, ElDistMatrix_z B )

Python API
----------

.. py:function:: Trsm(side,uplo,orient,diag,alpha,A,B)
