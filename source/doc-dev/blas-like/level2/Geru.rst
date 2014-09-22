Geru
====
General rank-one update (unconjugated): :math:`A := \alpha x y^T + A`. :math:`x`
and :math:`y` are free to be stored as either row or column vectors, but they 
will be interpreted as column vectors.

C++ API
-------

.. cpp:function:: void Geru( T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Geru( T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElGeru_c( complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElGeru_z( complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElGeruDist_c( complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElGeruDist_z( complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

