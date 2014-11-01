QuasiTrsm
=========
Solve for :math:`X` in the linear system

.. math::

   T^\# X = Y

or

.. math::

   X T^\# = Y

where :math:`T` is *quasi-triangular* and
:math:`A^\#` is defined to be one of :math:`\{A,A^T,A^H\}`.
The algorithm is very similar to that of :cpp:func:`Trsm`.

Note that the term *quasi-triangular* is in the context of real Schur
decompositions, which produce triangular matrices with mixes of
:math:`1 \times 1` and :math:`2 \times 2` diagonal blocks.

The following routines overwrite the columns of `X` with the solutions to the 
quasi-triangular linear systems.

.. note::

   There is no corresponding BLAS routine, but it is a natural extension of
   Trsm.

.. note::

   For best performance, `T` and `X` should be in [MC,MR] distributions.

C++ API
-------

.. cpp:function:: void QuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& T, Matrix<F>& X, bool checkIfSingular=false )
.. cpp:function:: void QuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& T, AbstractDistMatrix<F>& X, bool checkIfSingular=false )

C API
-----

.. c:function:: ElError ElQuasiTrsm_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElQuasiTrsm_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElQuasiTrsm_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElQuasiTrsm_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElQuasiTrsmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElQuasiTrsmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElQuasiTrsmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElQuasiTrsmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, ElDistMatrix_z B )

Python API
----------

.. py:function:: QuasiTrsm(side,uplo,orient,alpha,A,B)
