Multi-shift Hessenberg solves
=============================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/MultiShiftHessSolve.cpp>`__

Solve for :math:`X` in the system

.. math::

   H^\# X - X D^\# = Y

where :math:`H` is Hessenberg, :math:`D` is diagonal, and :math:`A^\#` 
is defined to be one of :math:`\{A,A^T,A^H\}`.

.. note::

   Only a few subcases are currently supported, as this was added as part of 
   :cpp:func:`HessenbergPseudospectrum`

C++ API
-------
.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& H, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

C API
-----
.. c:function:: ElError ElMultiShiftHessSolve_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s H, ElConstMatrix_s shifts, ElMatrix_s X )
.. c:function:: ElError ElMultiShiftHessSolve_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_d H, ElConstMatrix_d shifts, ElMatrix_d X )
.. c:function:: ElError ElMultiShiftHessSolve_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_c H, ElConstMatrix_c shifts, ElMatrix_c X )
.. c:function:: ElError ElMultiShiftHessSolve_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_z H, ElConstMatrix_z shifts, ElMatrix_z X )
.. c:function:: ElError ElMultiShiftHessSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s H, ElConstDistMatrix_s shifts, ElDistMatrix_s X )
.. c:function:: ElError ElMultiShiftHessSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_d H, ElConstDistMatrix_d shifts, ElDistMatrix_d X )
.. c:function:: ElError ElMultiShiftHessSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_c H, ElConstDistMatrix_c shifts, ElDistMatrix_c X )
.. c:function:: ElError ElMultiShiftHessSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_z H, ElConstDistMatrix_z shifts, ElDistMatrix_z X )

Python API
----------
.. py:function:: MultiShiftHessSolve(H,shifts,X,alpha=1,uplo=LOWER,orient=NORMAL)
