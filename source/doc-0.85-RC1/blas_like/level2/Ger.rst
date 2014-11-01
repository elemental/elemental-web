Ger
===
General rank-one update: :math:`A := \alpha x y^H + A`. :math:`x` and :math:`y`
are free to be stored as either row or column vectors, but they will be 
interpreted as column vectors.

C++ API
-------

.. cpp:function:: void Ger( T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Ger( T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElGer_i( ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElGer_s( float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElGer_d( double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElGer_c( complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElGer_z( complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElGerDist_i( ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElGerDist_s( float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElGerDist_d( double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElGerDist_c( complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElGerDist_z( complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )
