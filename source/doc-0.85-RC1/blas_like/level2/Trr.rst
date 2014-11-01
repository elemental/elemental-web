Trr
===

.. math::

   \text{tri}(A) := \text{tri}(A + \alpha x y')

C++ API
-------

.. cpp:function:: void Trr( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Trr( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
-----

.. c:function:: ElError ElTrr_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElTrr_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElTrr_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElTrr_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElTrr_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElTrrDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElTrrDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElTrrDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElTrrDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElTrrDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )
