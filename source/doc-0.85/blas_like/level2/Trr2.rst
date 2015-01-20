Trr2
====

.. math::

   \text{tri}(A) := \text{tri}(A + \alpha X Y'),

where :math:`X` and :math:`Y` each consist of two columns

C++ API
-------

.. cpp:function:: void Trr2( UpperOrLower uplo, T alpha, const Matrix<T>& X, const Matrix<T>& Y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Trr2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& X, const AbstractDistMatrix<T>& Y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
-----

.. c:function:: ElError ElTrr2_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElConstMatrix_i Y, ElMatrix_i A )
.. c:function:: ElError ElTrr2_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s X, ElConstMatrix_s Y, ElMatrix_s A )
.. c:function:: ElError ElTrr2_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d X, ElConstMatrix_d Y, ElMatrix_d A )
.. c:function:: ElError ElTrr2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElConstMatrix_c Y, ElMatrix_c A )
.. c:function:: ElError ElTrr2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElConstMatrix_z Y, ElMatrix_z A )
.. c:function:: ElError ElTrr2Dist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i X, ElConstDistMatrix_i Y, ElDistMatrix_i A )
.. c:function:: ElError ElTrr2Dist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s X, ElConstDistMatrix_s Y, ElDistMatrix_s A )
.. c:function:: ElError ElTrr2Dist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d X, ElConstDistMatrix_d Y, ElDistMatrix_d A )
.. c:function:: ElError ElTrr2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c X, ElConstDistMatrix_c Y, ElDistMatrix_c A )
.. c:function:: ElError ElTrr2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z X, ElConstDistMatrix_z Y, ElDistMatrix_z A )
