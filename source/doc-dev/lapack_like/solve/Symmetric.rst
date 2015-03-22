Symmetric solve
===============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/Symmetric.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X`
given a Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B`. When :math:`A` is dense, the default algorithm is Bunch-Kaufman,
whereas, when :math:`A` is sparse, the default approach embeds the problem 
in the same manner as :cpp:func:`LinearSolve`, though it is possible to 
override this behaviour and attempt a sparse :math:`LDL` factorization which
only dynamically pivots within supernodes.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
-------

.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

.. cpp:function:: void SymmetricSolve( const SparseMatrix<F>& A, Matrix<F>& B, bool conjugate=false, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

.. cpp:function:: void SymmetricSolve( const DistSparseMatrix<F>& A, DistMultiVec<F>& B, bool conjugate=false, bool tryLDL=false, const BisectCtrl& ctrl=BisectCtrl() )

C API
-----

.. c:function:: ElError ElSymmetricSolve_s( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSymmetricSolve_d( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSymmetricSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElSymmetricSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElSymmetricSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSymmetricSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSymmetricSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElSymmetricSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

.. c:function:: ElError ElSymmetricSolveSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B, bool tryLDL )

.. c:function:: ElError ElSymmetricSolveDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B, bool tryLDL )
.. c:function:: ElError ElSymmetricSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B, bool tryLDL )

Python API
----------
.. py:function:: SymmetricSolve(A,B,tryLDL=False,conjugate=False,uplo=LOWER,orient=NORMAL)
