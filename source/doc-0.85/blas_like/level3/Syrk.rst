Syrk
====
Symmetric rank-K update: updates
:math:`C := \alpha A A^T + \beta C`, or 
:math:`C := \alpha A^T A + \beta C`, depending upon whether `orientation` is
set to ``NORMAL`` or ``TRANSPOSE``, respectively. Only the triangle of :math:`C`
specified by the `uplo` parameter is modified.

Please see :cpp:func:`SetLocalTrrkBlocksize\<T>` 
and :cpp:func:`LocalTrrkBlocksize\<T>` in the :ref:`blas-tuning`
section for information on tuning the distributed :cpp:func:`Syrk`.

.. note::

   For the best performance, `A` and `C` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Syrk( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, T beta, Matrix<T>& C, bool conjugate=false )
.. cpp:function:: void Syrk( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, T beta, AbstractDistMatrix<T>& C, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSyrk_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s A, float beta, ElMatrix_s C )
.. c:function:: ElError ElSyrk_d( ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstMatrix_d A, double beta, ElMatrix_d C )
.. c:function:: ElError ElSyrk_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElSyrk_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElSyrkDist_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s A, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElSyrkDist_d( ElUpperOrLower uplo, ElOrientation orientation, double alpha, ElConstDistMatrix_d A, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElSyrkDist_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElSyrkDist_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, complex_double beta, ElDistMatrix_z C )

Python API
----------

.. py:function:: Syrk(uplo,orient,alpha,A,beta,C,conjugate=False)
