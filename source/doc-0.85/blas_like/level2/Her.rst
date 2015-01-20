Her
===
Hermitian rank-one update: implicitly performs :math:`A := \alpha x x^H + A`, 
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
-------

.. cpp:function:: void Her( UpperOrLower uplo, T alpha, const Matrix<T>& x, Matrix<T>& A )
.. cpp:function:: void Her( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElHer_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElMatrix_c A )
.. c:function:: ElError ElHer_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElMatrix_z A )
.. c:function:: ElError ElHerDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElDistMatrix_c A )
.. c:function:: ElError ElHerDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElDistMatrix_z A )
