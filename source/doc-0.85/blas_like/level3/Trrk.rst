Trrk
====
Triangular rank-k update: performs 
:math:`C := \alpha A^\# B^\sharp + \beta C`, where only the 
triangle of `C` specified by `uplo` is modified, and the orientations :math:`A^\#` and 
:math:`B^\sharp` are determined by `orientationOfA` and `orientationOfB`, 
respectively.

.. note::

   There is no corresponding BLAS routine, but this type of update is frequently
   encountered, even in serial. For instance, the symmetric rank-k update 
   performed during an LDL factorization is symmetric but one of the 
   two update matrices is scaled by D.

.. note::

   For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Trrk( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Trrk( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

C API
-----

.. c:function:: ElError ElTrrk_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElMatrix_s C )
.. c:function:: ElError ElTrrk_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElMatrix_d C )
.. c:function:: ElError ElTrrk_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElTrrk_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElTrrkDist_s( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElTrrkDist_d( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElTrrkDist_c( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElTrrkDist_z( ElUpperOrLower uplo, ElOrientation orientA, ElOrientation orientB, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )

Python API
----------

.. py:function:: Trrk(uplo,orientA,orientB,alpha,A,B,beta,C)
