Multi-shift Trsm
================
Solve for :math:`X` in the linear system

.. math::

   T^\# X - X D^\# = Y

or

.. math::

   X T^\# - D^\# X = Y

where :math:`T` is triangular, :math:`D` is diagonal, and 
:math:`A^\#` is defined to be one of :math:`\{A,A^T,A^H\}`. 
The data movement requires almost no modification from that of :cpp:func:`Trsm`.

.. note::

   There is no corresponding BLAS routine, but it is a natural modification
   of Trsm.

C++ API
-------

.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& T, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& T, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

   Overwrite the columns of `X` with the solutions to the shifted linear 
   systems.

.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const Matrix<Real>& T, const Matrix<Complex<Real>>& shifts, Matrix<Real>& XReal, Matrix<Real>& XImag )
.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const AbstractDistMatrix<Real>& T, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& XReal, AbstractDistMatrix<Real>& XImag )

   Overwrite the columns of the real and imaginary parts of `X` with the
   solutions to the shifted linear systems.

C API
-----

.. c:function:: ElError ElMultiShiftTrsm_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElMatrix_s A, ElConstMatrix_s shifts, ElMatrix_s B )
.. c:function:: ElError ElMultiShiftTrsm_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElMatrix_d A, ElConstMatrix_d shifts, ElMatrix_d B )
.. c:function:: ElError ElMultiShiftTrsm_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElMatrix_c A, ElConstMatrix_c shifts, ElMatrix_c B )
.. c:function:: ElError ElMultiShiftTrsm_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElMatrix_z A, ElConstMatrix_z shifts, ElMatrix_z B )
.. c:function:: ElError ElMultiShiftTrsmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElDistMatrix_s A, ElConstDistMatrix_s shifts, ElDistMatrix_s B )
.. c:function:: ElError ElMultiShiftTrsmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElDistMatrix_d A, ElConstDistMatrix_d shifts, ElDistMatrix_d B )
.. c:function:: ElError ElMultiShiftTrsmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_c B )
.. c:function:: ElError ElMultiShiftTrsmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_z B )
