Hermitian solve
===============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/Hermitian.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B`. When :math:`A` is dense, the default algorithm is Bunch-Kaufman, 
whereas, when :math:`A` is sparse, the default approach embeds the problem 
in the same manner as :cpp:func:`LinearSolve`, though it is possible to 
override this behaviour and attempt a sparse :math:`LDL^H` factorization which
only dynamically pivots within supernodes.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
-------
.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void HermitianSolve( const SparseMatrix<F>& A, Matrix<F>& B, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

.. cpp:function:: void HermitianSolve( const DistSparseMatrix<F>& A, DistMultiVec<F>& B, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

C API
-----
.. c:function:: ElError ElHermitianSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHermitianSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElHermitianSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHermitianSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

.. c:function:: ElError ElHermitianSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B, bool tryLDL )
.. c:function:: ElError ElHermitianSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B, bool tryLDL )

.. c:function:: ElError ElHermitianSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B, bool tryLDL )
.. c:function:: ElError ElHermitianSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B, bool tryLDL )

Python API
----------
.. py:function:: HermitianSolve(A,B,tryLDL=False,uplo=LOWER,orient=NORMAL)
