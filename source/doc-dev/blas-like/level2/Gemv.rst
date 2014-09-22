Gemv
====
General matrix-vector multiply:
:math:`y := \alpha \mbox{op}(A) x + \beta y`,
where :math:`\mbox{op}(A)` can be :math:`A`, :math:`A^T`, or :math:`A^H`.
Whether or not :math:`x` and :math:`y` are stored as row vectors, they will
be interpreted as column vectors.

C++ API
-------

.. cpp:function:: void Gemv( Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y )
.. cpp:function:: void Gemv( Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y )

C API
-----

.. c:function:: ElError ElGemv_i( ElOrientation orientation, ElInt alpha, ElConstMatrix_i A, ElConstMatrix_i x, ElInt beta, ElMatrix_i y )
.. c:function:: ElError ElGemv_s( ElOrientation orientation, float alpha, ElConstMatrix_s A, ElConstMatrix_s x, float beta, ElMatrix_s y )
.. c:function:: ElError ElGemv_d( ElOrientation orientation, double alpha, ElConstMatrix_d A, ElConstMatrix_d x, double beta, ElMatrix_d y )
.. c:function:: ElError ElGemv_c( ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElGemv_z( ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_z y )
.. c:function:: ElError ElGemvDist_i( ElOrientation orientation, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i x, ElInt beta, ElDistMatrix_i y )
.. c:function:: ElError ElGemvDist_s( ElOrientation orientation, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s x, float beta, ElDistMatrix_s y )
.. c:function:: ElError ElGemvDist_d( ElOrientation orientation, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d x, double beta, ElDistMatrix_d y )
.. c:function:: ElError ElGemvDist_c( ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElGemvDist_z( ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_z y )
