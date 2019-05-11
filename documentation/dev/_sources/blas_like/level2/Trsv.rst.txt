Trsv
====
Triangular solve with a vector: computes
:math:`x := \mbox{op}(A)^{-1} x`, where :math:`\mbox{op}(A)` is either 
:math:`A`, :math:`A^T`, or :math:`A^H`, and :math:`A` is treated an either a 
lower or upper triangular matrix, depending upon `uplo`. :math:`A` can also be 
treated as implicitly having a unit-diagonal if `diag` is set to ``UNIT``.

.. note::

   For the best performance, `A` and `x` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Trsv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const Matrix<F>& A, Matrix<F>& x )
.. cpp:function:: void Trsv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& x )

C API
-----

.. c:function:: ElError ElTrsv_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElTrsv_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElTrsv_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElTrsv_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_z A, ElMatrix_z x )
.. c:function:: ElError ElTrsvDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_s A, ElDistMatrix_s x )
.. c:function:: ElError ElTrsvDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_d A, ElDistMatrix_d x )
.. c:function:: ElError ElTrsvDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_c A, ElDistMatrix_c x )
.. c:function:: ElError ElTrsvDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_z A, ElDistMatrix_z x )
