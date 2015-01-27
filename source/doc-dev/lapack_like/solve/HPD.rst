HPD solve
=========

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/HPDSolve.cpp>`__

Solves :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X=B` for :math:`X` given 
Hermitian positive-definite (HPD) :math:`A` and right-hand side matrix 
:math:`B` (note that these options are all identical except for when :math:`A`. 
is complex).
The solution is computed by first finding the Cholesky factorization of 
:math:`A` and then performing two successive triangular solves against 
:math:`B`.

Note that only the `uplo` triangle of :math:`A` is accessed by the below 
routines.

C++ API
-------
.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
-----
.. c:function:: ElError ElHPDSolve_s( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElHPDSolve_d( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElHPDSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHPDSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElHPDSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElHPDSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElHPDSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHPDSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

Python API
----------
.. py:function:: HPDSolve(A,B,uplo=LOWER,orient=NORMAL)
