Trmm
====
Triangular matrix-matrix multiplication: performs
:math:`C := \alpha A^\# B`, or 
:math:`C := \alpha B A^\#`, depending upon whether `side` was chosen
to be ``LEFT`` or ``RIGHT``, respectively. Whether :math:`A` is treated as 
lower or upper triangular is determined by `uplo`, and :math:`A^\#` is defined 
to be one of :math:`\{A,A^T,A^H\}` (and `diag` determines
whether :math:`A` is treated as unit-diagonal or not).

.. note::

   For the best performance, `A` and `B` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Trmm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, T alpha, const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Trmm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, T alpha, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

C API
-----

.. c:function:: ElError ElTrmm_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElTrmm_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElTrmm_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElTrmm_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElTrmmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElTrmmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElTrmmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElTrmmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstDistMatrix_z A, ElDistMatrix_z B )

Python API
----------

.. py:function:: Trmm(side,uplo,orient,diag,alpha,A,B)
