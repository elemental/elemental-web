Herk
====
Hermitian rank-K update: updates
:math:`C := \alpha A A^H + \beta C`, or 
:math:`C := \alpha A^H A + \beta C`, depending upon whether `orientation` is
set to ``NORMAL`` or ``ADJOINT``, respectively. Only the triangle of :math:`C` 
specified by the `uplo` parameter is modified.

Please see :cpp:func:`SetLocalTrrkBlocksize\<T>` 
and :cpp:func:`LocalTrrkBlocksize\<T>` in the :ref:`blas-tuning`
section for information on tuning the distributed :cpp:func:`Herk`.

.. note::

   For the best performance, `A` and `C` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Herk( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, T beta, Matrix<T>& C )
.. cpp:function:: void Herk( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, T beta, AbstractDistMatrix<T>& C )

C API
-----

.. c:function:: ElError ElHerk_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElHerk_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElHerkDist_c( ElUpperOrLower uplo, ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElHerkDist_z( ElUpperOrLower uplo, ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, complex_double beta, ElDistMatrix_z C )
