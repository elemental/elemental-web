Linear solve
============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/Linear.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. 
For dense matrices, the solution is computed through Gaussian elimination with
partial pivoting, while, for sparse matrices, the original problem is embedded
into the augmented system

.. math::

   \begin{pmatrix} \alpha I & A \\ A^H & 0 \end{pmatrix} \begin{pmatrix} r/\alpha \\ x \end{pmatrix} = \begin{pmatrix} b \\ 0 \end{pmatrix},


where :math:`\alpha \approx \sigma_{\text{min}}(A)` is known to be near-optimal
with respect to minimizing the condition number of the augmented system.
A priori regularization is added to the linear system, a sparse-direct 
Cholesky-like factorization is performed, and the factorization is used as
a preconditioner for Flexible GMRES.

C++ API
-------
.. cpp:function:: void LinearSolve( Matrix<F>& A, Matrix<F>& B )

.. cpp:function:: void LinearSolve( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

.. cpp:function:: void LinearSolve( SparseMatrix<F>& A, Matrix<F>& B, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void LinearSolve( DistSparseMatrix<F>& A, DistMultiVec<F>& B, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

C API
-----
.. c:function:: ElError ElLinearSolve_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElLinearSolve_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElLinearSolve_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElLinearSolve_z( ElMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElLinearSolveDist_s( ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElLinearSolveDist_d( ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElLinearSolveDist_c( ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElLinearSolveDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

.. c:function:: ElError ElLinearSolveSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElLinearSolveSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElLinearSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElLinearSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElLinearSolveDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B )
.. c:function:: ElError ElLinearSolveDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B )
.. c:function:: ElError ElLinearSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B )
.. c:function:: ElError ElLinearSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B )

Expert versions
^^^^^^^^^^^^^^^

.. c:function:: ElError ElLinearSolveXSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLinearSolveXSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B, ElLeastSquaresCtrl_d ctrl )

.. c:function:: ElError ElLinearSolveXDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B, ElLeastSquaresCtrl_d ctrl )

Python API
----------
.. py:function:: LinearSolve(A,B,ctrl=None)
