Her2k
=====
Hermitian rank-2K update: updates
:math:`C := \alpha A B^H + \bar \alpha B A^H + \beta C`, or 
:math:`C := \alpha A^H B + \bar \alpha B^H A + \beta C`, depending upon whether 
`orientation` is set to ``NORMAL`` or ``ADJOINT``, respectively. Only the 
triangle of :math:`C` specified by the `uplo` parameter is modified.

Please see :cpp:func:`SetLocalTrr2kBlocksize\<T>` 
and :cpp:func:`LocalTrr2kBlocksize\<T>` in the 
:ref:`blas-tuning` section for information on tuning the distributed 
:cpp:func:`Her2k`.

.. note::

   For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Her2k( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& B, Base<T> beta, Matrix<T>& C )
.. cpp:function:: void Her2k( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, Base<T> beta, AbstractDistMatrix<T>& C )

C API
-----

.. c:function:: ElError ElHer2k_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, float beta, ElMatrix_c C )
.. c:function:: ElError ElHer2k_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, double beta, ElMatrix_z C )
.. c:function:: ElError ElHer2kDist_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, float beta, ElDistMatrix_c C )
.. c:function:: ElError ElHer2kDist_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, double beta, ElDistMatrix_z C )

Python API
----------

.. py:function:: Her2k(uplo,orient,alpha,A,B,beta,C)
