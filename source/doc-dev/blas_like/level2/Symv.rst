Symv
====
Symmetric matrix-vector multiply: :math:`y := \alpha A x + \beta y`, where 
:math:`A` is symmetric.

Please see :cpp:func:`SetLocalSymvBlocksize\<T>` and 
:cpp:func:`LocalSymvBlocksize\<T>` in the :ref:`blas-tuning` section for 
information on tuning the distributed :cpp:func:`Symv`.

C++ API
-------

.. cpp:function:: void Symv( UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y, bool conjugate=false )
.. cpp:function:: void Symv( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSymv_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i A, ElConstMatrix_i x, ElInt beta, ElMatrix_i y )
.. c:function:: ElError ElSymv_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s A, ElConstMatrix_s x, float beta, ElMatrix_s y )
.. c:function:: ElError ElSymv_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d A, ElConstMatrix_d x, double beta, ElMatrix_d y )
.. c:function:: ElError ElSymv_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElSymv_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_z y )
.. c:function:: ElError ElSymvDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i x, ElInt beta, ElDistMatrix_i y )
.. c:function:: ElError ElSymvDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s x, float beta, ElDistMatrix_s y )
.. c:function:: ElError ElSymvDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d x, double beta, ElDistMatrix_d y )
.. c:function:: ElError ElSymvDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElSymvDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_z y )

