Trmv
====

.. math::

   x := \text{tri}(A)^\sharp x

.. note::

   Distributed ``Trmv`` not yet written. Please call :cpp:func:`Trmm` for now.

C++ API
-------

.. cpp:function:: void Trmv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const Matrix<T>& A, Matrix<T>& x )

C API
-----

.. c:function:: ElError ElTrmv_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElTrmv_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElTrmv_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElTrmv_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_z A, ElMatrix_z x )
