Multi-shift Hessenberg solves
=============================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/MultiShiftHess.cpp>`__

Solve for :math:`X` in the system

.. math::

   H^\# X - X D^\# = \alpha Y

where :math:`H` is Hessenberg, :math:`D` is diagonal, and :math:`A^\#` 
is defined to be one of :math:`\{A,A^T,A^H\}`.

.. note::

   Only a few subcases are currently supported, as this was added as part of 
   :cpp:func:`HessenbergPseudospectrum`

Python API
----------
.. py:function:: MultiShiftHessSolve(H,shifts,X[,alpha=1,uplo=LOWER,orient=NORMAL])

   :param H: Dense Hessenberg matrix to solve against (with shifts)
   :param shifts: a list of shifts (one per right-hand side) to subtract from the diagonal of :math:`H` before solving the linear system
   :param X: the right-hand sides to solve against (and overwrite)
   :param alpha: (optional) the scaling of the right-hand sides
   :param uplo: (optional) whether :math:`H` is lower or upper-Hessenberg
   :param orient: (optional) whether to solve against :math:`H`, :math:`H^T`, or :math:`H^H`

C++ API
-------
.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& H, const Matrix<F>& shifts, Matrix<F>& X )

.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElMultiShiftHessSolve_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s H, ElConstMatrix_s shifts, ElMatrix_s X )
.. c:function:: ElError ElMultiShiftHessSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s H, ElConstDistMatrix_s shifts, ElDistMatrix_s X )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElMultiShiftHessSolve_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_d H, ElConstMatrix_d shifts, ElMatrix_d X )
.. c:function:: ElError ElMultiShiftHessSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_d H, ElConstDistMatrix_d shifts, ElDistMatrix_d X )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElMultiShiftHessSolve_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_c H, ElConstMatrix_c shifts, ElMatrix_c X )
.. c:function:: ElError ElMultiShiftHessSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_c H, ElConstDistMatrix_c shifts, ElDistMatrix_c X )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElMultiShiftHessSolve_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_z H, ElConstMatrix_z shifts, ElMatrix_z X )
.. c:function:: ElError ElMultiShiftHessSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_z H, ElConstDistMatrix_z shifts, ElDistMatrix_z X )

