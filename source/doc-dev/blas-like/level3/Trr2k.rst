Trr2k
=====
Triangular rank-2k update: performs 
:math:`E := \alpha ( A^\# B^\sharp + C^\Diamond D^\triangle ) + \beta E`,
where only the triangle of `E` specified by `uplo` is modified, and 
the orientation of each input matrix, e.g., :math:`A^\# \in \{A,A^T,A^H\}`, is determined 
by `orientationOfX` for each :math:`X \in \left\{A,B,C,D\right\}`.

.. note::

   There is no corresponding BLAS routine, but it is a natural generalization
   of "symmetric" and "Hermitian" updates.

.. note::

   For the best performance, `A`, `B`, `C`, `D`, and `E` should all be in 
   [MC,MR] distributions.

C++ API
-------

.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const Matrix<T>& A, const Matrix<T>& B, const Matrix<T>& C, const Matrix<T>& D, T beta, Matrix<T>& E )
.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, const AbstractDistMatrix<T>& C, const AbstractDistMatrix<T>& D, T beta, AbstractDistMatrix<T>& E )

C API
-----

.. c:function:: ElError ElTrr2k_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElMatrix_s C )
.. c:function:: ElError ElTrr2k_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElMatrix_d C )
.. c:function:: ElError ElTrr2k_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElTrr2k_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElTrr2kDist_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElTrr2kDist_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElTrr2kDist_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElTrr2kDist_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )
