Syr2k
=====
Symmetric rank-2K update: updates
:math:`C := \alpha (A B^T + B A^T) + \beta C`, or 
:math:`C := \alpha (A^T B + B^T A) + \beta C`, depending upon whether 
`orientation` is set to ``NORMAL`` or ``TRANSPOSE``, respectively. Only the 
triangle of :math:`C` specified by the `uplo` parameter is modified.

Please see :cpp:func:`SetLocalTrr2kBlocksize\<T>` 
and :cpp:func:`LocalTrr2kBlocksize\<T>` in the 
:ref:`blas-tuning` section for information on tuning the distributed 
:cpp:func:`Syr2k`.

.. note::

   For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Syr2k( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C, bool conjugate=false )
.. cpp:function:: void Syr2k( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSyr2k_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElMatrix_s C )
.. c:function:: ElError ElSyr2k_d( ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElMatrix_d C )
.. c:function:: ElError ElSyr2k_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElSyr2k_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElSyr2kDist_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElSyr2kDist_d( ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElSyr2kDist_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElSyr2kDist_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )

Python API
----------

.. py:function:: Syr2k(uplo,orient,alpha,A,B,beta,C,conjugate=False)
