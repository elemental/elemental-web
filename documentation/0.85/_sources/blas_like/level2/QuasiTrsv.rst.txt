QuasiTrsv
=========
*Quasi-triangular* solve with a vector: computes
:math:`x := \mbox{op}(A)^{-1} x`, where :math:`\mbox{op}(A)` is either 
:math:`A`, :math:`A^T`, or :math:`A^H`, and :math:`A` is treated an either a 
lower or upper quasi-triangular matrix, depending upon `uplo`.

Note that the term *quasi-triangular* is in the context of real Schur 
decompositions, which produce triangular matrices with mixes of 
:math:`1 \times 1` and :math:`2 \times 2` diagonal blocks.

.. note::

   There is no corresponding BLAS routine, but it is a natural extension of 
   Trsv.

.. note::

   For the best performance, both `A` and `x` should be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void QuasiTrsv( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& x, bool checkIfSingular=false )
.. cpp:function:: void QuasiTrsv( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& x, bool checkIfSingular=false )

C API
-----

.. c:function:: ElError ElQuasiTrsv_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElQuasiTrsv_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElQuasiTrsv_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElQuasiTrsv_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElMatrix_z x )
.. c:function:: ElError ElQuasiTrsvDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElDistMatrix_s x )
.. c:function:: ElError ElQuasiTrsvDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElDistMatrix_d x )
.. c:function:: ElError ElQuasiTrsvDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElDistMatrix_c x )
.. c:function:: ElError ElQuasiTrsvDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElDistMatrix_z x )
