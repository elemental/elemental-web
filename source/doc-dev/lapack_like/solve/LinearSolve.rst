Linear solve
============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/LinearSolve.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. 
For dense matrices, the solution is computed through Gaussian elimination with
partial pivoting, while, for sparse matrices, the original problem is embedded
into the "primal-dual" formulation

.. math::

   \begin{pmatrix} I & A^H \\ A & 0 \end{pmatrix} \begin{pmatrix} x \\ y \end{pmatrix} = \begin{pmatrix} 0 \\ b \end{pmatrix},

which is then solved using a regularized quasi-semidefinite :math:`LDL^H` 
factorization as a preconditioner for Flexible GMRES.

C++ API
-------
.. cpp:function:: void LinearSolve( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void LinearSolve( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )
.. cpp:function:: void LinearSolve( SparseMatrix<F>& A, Matrix<F>& B )
.. cpp:function:: void LinearSolve( DistSparseMatrix<F>& A, Matrix<F>& B )

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
.. c:function:: ElError ElLinearSolveSparse_s( ElSparseMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElLinearSolveSparse_d( ElSparseMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElLinearSolveSparse_c( ElSparseMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElLinearSolveSparse_z( ElSparseMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElLinearSolveSparse_s( ElDistSparseMatrix_s A, ElDistMultiVec_s B )
.. c:function:: ElError ElLinearSolveSparse_d( ElDistSparseMatrix_d A, ElDistMultiVec_d B )
.. c:function:: ElError ElLinearSolveSparse_c( ElDistSparseMatrix_c A, ElDistMultiVec_c B )
.. c:function:: ElError ElLinearSolveSparse_z( ElDistSparseMatrix_z A, ElDistMultiVec_z B )

Python API
----------
.. py:function:: LinearSolve(A,B)
