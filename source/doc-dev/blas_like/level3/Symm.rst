Symm
====
Symmetric matrix-matrix multiplication: updates
:math:`C := \alpha A B + \beta C`, or 
:math:`C := \alpha B A + \beta C`, depending upon whether `side` is set to 
``LEFT`` or ``RIGHT``, respectively. In both of these types of updates, 
:math:`A` is implicitly symmetric and only the triangle specified by `uplo` 
is accessed.

.. note::

   For best performance, `A`, `B`, and `C` should all be in [MC,MR]
   distributions.

C++ API
-------

.. cpp:function:: void Symm( LeftOrRight side, UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C, bool conjugate=false )
.. cpp:function:: void Symm( LeftOrRight side, UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C, bool conjugate=false )

C API
-----

.. c:function:: ElError ElSymm_s( ElLeftOrRight side, ElUpperOrLower uplo, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElMatrix_s C )
.. c:function:: ElError ElSymm_d( ElLeftOrRight side, ElUpperOrLower uplo, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElMatrix_d C )
.. c:function:: ElError ElSymm_c( ElLeftOrRight side, ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElSymm_z( ElLeftOrRight side, ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElSymmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElSymmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElSymmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElSymmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )

Python API
----------

.. py:function:: Symm(side,uplo,alpha,A,B,beta,C,conjugate=False)
