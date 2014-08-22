Solvers
=======
`Header <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/solve.hpp>`__

HPD solve
---------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/HPDSolve.cpp>`__

Solves :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X=B` for :math:`X` given 
Hermitian positive-definite (HPD) :math:`A` and right-hand side matrix 
:math:`B` (note that these options are all identical except for when :math:`A`. 
is complex).
The solution is computed by first finding the Cholesky factorization of 
:math:`A` and then performing two successive triangular solves against 
:math:`B`.

.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Overwrite `B` with the solution to :math:`AX=B` or :math:`A^T X=B`, 
   where `A` is Hermitian positive-definite and only the triangle of `A` 
   specified by `uplo` is accessed.

Symmetric solve
---------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/SymmetricSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a symmetric or Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Overwrites :math:`B` with the solution to the linear system. :math:`A`
   is assumed symmetric if ``conjugate`` is false, and Hermitian otherwise.

.. note:: 

   Only the lower-storage case is currently supported.

Hermitian solve
---------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/HermitianSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Overwrites :math:`B` with the solution to the linear system.

.. note:: 

   Only the lower-storage case is currently supported, as this is a simple 
   wrapper around :cpp:func:`SymmetricSolve`.

Gaussian elimination
--------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/GaussianElimination.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. The solution is computed through
(partially pivoted) Gaussian elimination.

.. cpp:function:: void GaussianElimination( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GaussianElimination( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Upon completion, :math:`A` will have been overwritten with Gaussian 
   elimination and :math:`B` will be overwritten with :math:`X`.

Least Squares
-------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/LeastSquares.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}` and a right-hand side 
:math:`b \in \mathbb{F}^m`, a *least-squares* method solves
:math:`A x \approx b` differently depending upon whether :math:`m \ge n`.

When :math:`m \ge n`, there are at least as many constraints as degrees of freedom, and 
so a solution is sought for

.. math::

   \min_x \| A x - b \|_2

This problem is solved through the use of :cpp:func:`QR`.

When :math:`m < n`, the problem is under-constrained and a solution is sought for the
problem

.. math::

   \min_x \| x \|_2 \;\;\; \text{such that } A x = b.

This problem is solved through the use of :cpp:func:`LQ`.

The above optimization problems can be readily generalized to multiple right-hand
sides by switching to Frobenius norms. 

.. cpp:function:: void LeastSquares( Orientation orientation, Matrix<F>& A, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void LeastSquares( Orientation orientation, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

   If `orientation` is set to ``NORMAL``, then solve :math:`AX=B`, otherwise 
   `orientation` must be equal to ``ADJOINT`` and :math:`A^H X=B` will 
   be solved. Upon completion, :math:`A` is overwritten with its QR or LQ 
   factorization, and each column of :math:`X` is overwritten with a solution vector.

General (Gauss-Markov) Linear Model (GLM)
-----------------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/GLM.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/GLM.cpp>`__

.. math::

   \min_{X,Y} \| Y \|_F \;\;\; \text{subject to } A X + B Y = D.

.. cpp:function:: void GLM( Matrix<F>& A, Matrix<F>& B, Matrix<F>& D, Matrix<F>& Y )
.. cpp:function:: void GLM( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& Y )

Equality-constrained Least Squares (LSE)
----------------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/LSE.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/LSE.cpp>`__

.. math::

   \min_X \| A X - C \|_F \;\;\; \text{subject to } B X = D.

.. cpp:function:: void LSE( Matrix<F>& A, Matrix<F>& B, Matrix<F>& C, Matrix<F>& D, Matrix<F>& X, bool computeResidual=false )
.. cpp:function:: void LSE( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X, bool computeResidual=false )

Multi-shift Hessenberg solves
-----------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/MultiShiftHessSolve.cpp>`__

Solve for :math:`X` in the system

.. math::

   H^\# X - X D^\# = Y

where :math:`H` is Hessenberg, :math:`D` is diagonal, and :math:`A^\#` 
is defined to be one of :math:`\{A,A^T,A^H\}`.

.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& H, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

   Overwrite the columns of `X` with the solutions to shifted linear systems.

.. note::

   Only a few subcases are currently supported, as this was added as part of 
   :cpp:func:`HessenbergPseudospectrum`
