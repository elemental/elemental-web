Trr2k
=====
Triangular rank-2k update: performs 
:math:`E := \alpha A^\# B^\sharp + \beta C^\Diamond D^\triangle  + \gamma E`,
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

.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, const Matrix<T>& C, const Matrix<T>& D, T gamma, Matrix<T>& E )
.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, const AbstractDistMatrix<T>& C, const AbstractDistMatrix<T>& D, T gamma, AbstractDistMatrix<T>& E )

C API
-----

.. c:function:: ElError ElTrr2k_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElConstMatrix_s C, ElConstMatrix_s D, float gamma, ElMatrix_s E )
.. c:function:: ElError ElTrr2k_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElConstMatrix_d C, ElConstMatrix_d D, double gamma, ElMatrix_d E )
.. c:function:: ElError ElTrr2k_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElConstMatrix_c C, ElConstMatrix_c D, complex_float gamma, ElMatrix_c E )
.. c:function:: ElError ElTrr2k_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElConstMatrix_z C, ElConstMatrix_z D, complex_double gamma, ElMatrix_z E )
.. c:function:: ElError ElTrr2kDist_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElConstDistMatrix_s C, ElConstDistMatrix_s D, float gamma, ElDistMatrix_s E )
.. c:function:: ElError ElTrr2kDist_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElConstDistMatrix_d C, ElConstDistMatrix_d D, double gamma, ElDistMatrix_d E )
.. c:function:: ElError ElTrr2kDist_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElConstDistMatrix_c C, ElConstDistMatrix_c D, complex_float gamma, ElDistMatrix_c E )
.. c:function:: ElError ElTrr2kDist_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, ElOrientation orientC, ElOrientation orientD, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElConstDistMatrix_z C, ElConstDistMatrix_z D, complex_double gamma, ElDistMatrix_z E )

Python API
----------

.. py:function:: Trr2k(uplo,orientA,orientB,orientC,orientD,alpha,A,B,beta,C,D,gamma,E)
