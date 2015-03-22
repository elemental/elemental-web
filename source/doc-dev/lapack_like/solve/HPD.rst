HPD solve
=========

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/HPD.cpp>`__

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

.. cpp:function:: void HPDSolve( const SparseMatrix<F>& A, Matrix<F>& B, const BisectCtrl& ctrl=BisectCtrl() )

.. cpp:function:: void HPDSolve( const DistSparseMatrix<F>& A, DistMultiVec<F>& B, const BisectCtrl& ctrl=BisectCtrl() )

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

.. c:function:: ElError ElHPDSolveSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElHPDSolveSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElHPDSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHPDSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElHPDSolveDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B )
.. c:function:: ElError ElHPDSolveDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B )
.. c:function:: ElError ElHPDSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B )
.. c:function:: ElError ElHPDSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B )

Python API
----------
.. py:function:: HPDSolve(A,B,uplo=LOWER,orient=NORMAL)
