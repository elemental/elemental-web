Hemm
====
Hermitian matrix-matrix multiplication: updates
:math:`C := \alpha A B + \beta C`, or 
:math:`C := \alpha B A + \beta C`, depending upon whether `side` is set to 
``LEFT`` or ``RIGHT``, respectively. In both of these types of updates, 
:math:`A` is implicitly Hermitian and only the triangle specified by `uplo` is 
accessed.

.. note::

   For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Hemm( LeftOrRight side, UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Hemm( LeftOrRight side, UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

C API
-----

.. c:function:: ElError ElHemm_c( ElLeftOrRight side, ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElHemm_z( ElLeftOrRight side, ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElHemmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElHemmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )

