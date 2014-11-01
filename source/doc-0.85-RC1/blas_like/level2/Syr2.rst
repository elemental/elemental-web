Syr2
====
Symmetric rank-two update: implicitly performs 
:math:`A := \alpha ( x y^T + y x^T ) + A`,
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
-------

.. cpp:function:: void Syr2( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Syr2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSyr2_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElSyr2_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElSyr2_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElSyr2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElSyr2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElSyr2Dist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElSyr2Dist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElSyr2Dist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElSyr2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElSyr2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )
