Syr
===
Symmetric rank-one update: implicitly performs :math:`A := \alpha x x^T + A`, 
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
-------

.. cpp:function:: void Syr( UpperOrLower uplo, T alpha, const Matrix<T>& x, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Syr( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSyr_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElMatrix_i A )
.. c:function:: ElError ElSyr_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElMatrix_s A )
.. c:function:: ElError ElSyr_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElMatrix_d A )
.. c:function:: ElError ElSyr_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElMatrix_c A )
.. c:function:: ElError ElSyr_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElMatrix_z A )
.. c:function:: ElError ElSyrDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElDistMatrix_i A )
.. c:function:: ElError ElSyrDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElDistMatrix_s A )
.. c:function:: ElError ElSyrDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElDistMatrix_d A )
.. c:function:: ElError ElSyrDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElDistMatrix_c A )
.. c:function:: ElError ElSyrDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElDistMatrix_z A )
