Her2
====
Hermitian rank-two update: implicitly performs 
:math:`A := \alpha x y^H + \bar \alpha y x^H + A`,
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
-------

.. cpp:function:: void Her2( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Her2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElHer2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElHer2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElHer2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElHer2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )
