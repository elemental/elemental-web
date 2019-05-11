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

Python API
----------
.. py:function:: HermitianSolve(A,B[,tryLDL=False,uplo=LOWER,orient=NORMAL])

   :param A: Dense or sparse Hermitian matrix to solve against
   :param B: Right-hand sides (which will be overwritten with the solution).
   :param tryLDL: (optional) if a sparse :math:`LDL^H` factorization without pivoting should be attempted instead of embedding in a QSD system
   :param uplo: (optional) which triangle the data is explicitly stored in
   :param orient: (optional) whether to use :math:`A`, :math:`A^T`, or :math:`A^H` 

+------------------------+------------------------+
| Type of :math:`A`      | Type of B              |
+------------------------+------------------------+
| ``Matrix``             | ``Matrix``             |
+------------------------+------------------------+
| ``AbstractDistMatrix`` | ``AbstractDistMatrix`` |
+------------------------+------------------------+
| ``SparseMatrix``       | ``Matrix``             |
+------------------------+------------------------+
| ``DistSparseMatrix``   | ``DistMultiVec``       |
+------------------------+------------------------+

C++ API
-------
.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void HermitianSolve( const SparseMatrix<F>& A, Matrix<F>& B, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

.. cpp:function:: void HermitianSolve( const DistSparseMatrix<F>& A, DistMultiVec<F>& B, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

Dense versions which factor in-place
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. cpp:function:: void herm_solve::Overwrite( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void herm_solve::Overwrite( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

C API
-----

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHermitianSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHermitianSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHermitianSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B, bool tryLDL )
.. c:function:: ElError ElHermitianSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B, bool tryLDL )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHermitianSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElHermitianSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElDistMatrix_z B )
.. c:function:: ElError ElHermitianSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B, bool tryLDL )
.. c:function:: ElError ElHermitianSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B, bool tryLDL )
