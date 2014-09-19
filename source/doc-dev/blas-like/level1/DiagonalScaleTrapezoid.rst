DiagonalScaleTrapezoid
======================
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`A := \mbox{op}(D) A` or :math:`A := A \mbox{op}(D)`, 
where :math:`A` is trapezoidal (upper or lower with the boundary diagonal 
of given offset), :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, 
where :math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

C++ API
-------

.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<T>& d, Matrix<T>& A, Int offset=0 )
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<T>& d, AbstractDistMatrix<T>& A, Int offset=0 )

C API
-----

.. c:function:: ElError ElDiagonalScaleTrapezoid_i( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_i d, ElMatrix_i X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_s( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_s d, ElMatrix_s X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_d( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_d d, ElMatrix_d X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X, ElInt offset )
