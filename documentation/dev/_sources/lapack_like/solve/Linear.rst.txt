Linear solve
============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/Linear.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. In all cases, on exit, the 
following routines overwrite :math:`B` with :math:`\text{inv}(A) B`.

Dense algorithm
---------------
For dense matrices, the solution is computed through Gaussian elimination with
partial pivoting.

Sparse-direct algorithm
-----------------------
For sparse matrices, the original problem is embedded into the augmented system

.. math::

   \begin{pmatrix} \alpha I & A \\ A^H & 0 \end{pmatrix} \begin{pmatrix} R/\alpha \\ X \end{pmatrix} = \begin{pmatrix} B \\ 0 \end{pmatrix},


where :math:`\alpha \approx \sigma_{\text{min}}(A)` is known to be near-optimal
with respect to minimizing the condition number of the augmented system.
A priori regularization is added to the linear system, a sparse-direct 
Cholesky-like factorization is performed, and the factorization is used as
a preconditioner for Flexible GMRES.

It is worth noting that this is a special case of :cpp:func:`LeastSquares`,
and that, unlike cases where :math:`A` is not invertible, it is possible for
:cpp:func:`LinearSolve` to choose :math:`\alpha=0`.

Python API
----------

.. py:function:: LinearSolve(A,B[,ctrl=None])

   :param A: Dense or sparse matrix to solve against
   :param B: Right-hand sides (which will be overwritten with the solution).
   :param ctrl: (optional) sparse-direct Least Squares control structure 

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
.. cpp:function:: void LinearSolve( const Matrix<F>& A, Matrix<F>& B )

.. cpp:function:: void LinearSolve( const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

.. cpp:function:: void LinearSolve( const SparseMatrix<F>& A, Matrix<F>& B, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void LinearSolve( const DistSparseMatrix<F>& A, DistMultiVec<F>& B, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

Dense in-place alternatives
^^^^^^^^^^^^^^^^^^^^^^^^^^^
The following routines factor :math:`A` in place.

.. cpp:function:: lin_solve::Overwrite( Matrix<F>& A, Matrix<F>& B )

.. cpp:function:: lin_solve::Overwrite( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
-----

Standard interface
^^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElLinearSolve_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElLinearSolveDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElLinearSolveSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElLinearSolveDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B )

Double-precision
""""""""""""""""
.. c:function:: ElError ElLinearSolve_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElLinearSolveDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElLinearSolveSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElLinearSolveDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLinearSolve_c( ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElLinearSolveDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElLinearSolveSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElLinearSolveDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLinearSolve_z( ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElLinearSolveDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B )
.. c:function:: ElError ElLinearSolveSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElLinearSolveDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B )

Expert versions
^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElLinearSolveXSparse_s( ElConstSparseMatrix_s A, ElMatrix_s B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_s( ElConstDistSparseMatrix_s A, ElDistMultiVec_s B, ElLeastSquaresCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElLinearSolveXSparse_d( ElConstSparseMatrix_d A, ElMatrix_d B, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_d( ElConstDistSparseMatrix_d A, ElDistMultiVec_d B, ElLeastSquaresCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLinearSolveXSparse_c( ElConstSparseMatrix_c A, ElMatrix_c B, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_c( ElConstDistSparseMatrix_c A, ElDistMultiVec_c B, ElLeastSquaresCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLinearSolveXSparse_z( ElConstSparseMatrix_z A, ElMatrix_z B, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLinearSolveXDistSparse_z( ElConstDistSparseMatrix_z A, ElDistMultiVec_z B, ElLeastSquaresCtrl_d ctrl )

