Hemv
====
Hermitian matrix-vector multiply: :math:`y := \alpha A x + \beta y`, where 
:math:`A` is Hermitian.

Please see :cpp:func:`SetLocalSymvBlocksize\<T>` and 
:cpp:func:`LocalSymvBlocksize\<T>` in the :ref:`blas-tuning` section for 
information on tuning the distributed :cpp:func:`Hemv`.

C++ API
-------

.. cpp:function:: void Hemv( UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y )
.. cpp:function:: void Hemv( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y )

C API
-----

.. c:function:: ElError ElHemv_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElHemv_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_c y )
.. c:function:: ElError ElHemvDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElHemvDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_c y )
