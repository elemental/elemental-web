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

Note that only the `uplo` triangle of :math:`A` is accessed by the below 
routines.

C++ API
^^^^^^^

.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void HPDSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
^^^^^

.. c:function:: ElError ElHPDSolve_s( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElHPDSolve_d( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElHPDSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHPDSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElHPDSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElHPDSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElHPDSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHPDSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

Symmetric solve
---------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/SymmetricSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a symmetric or Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
^^^^^^^

.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

C API
^^^^^

.. c:function:: ElError ElSymmetricSolve_s( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSymmetricSolve_d( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSymmetricSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElSymmetricSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B, bool conjugate )
.. c:function:: ElError ElSymmetricSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSymmetricSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSymmetricSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElSymmetricSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B, bool conjugate )

Hermitian solve
---------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/HermitianSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
^^^^^^^

.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

C API
^^^^^

.. c:function:: ElError ElHermitianSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHermitianSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElHermitianSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHermitianSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

Gaussian elimination
--------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/GaussianElimination.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. The solution is computed through
(partially pivoted) Gaussian elimination.

C++ API
^^^^^^^

.. cpp:function:: void GaussianElimination( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GaussianElimination( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
^^^^^

.. c:function:: ElError ElGaussianElimination_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElGaussianElimination_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElGaussianElimination_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElGaussianElimination_z( ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElGaussianEliminationDist_s( ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElGaussianEliminationDist_d( ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElGaussianEliminationDist_c( ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElGaussianEliminationDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

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

The above optimization problems can be readily generalized to multiple 
right-hand sides by switching to Frobenius norms. 

.. note::

   If `orientation` is set to ``NORMAL``, then solve :math:`AX=B`, otherwise 
   `orientation` must be equal to ``ADJOINT`` and :math:`A^H X=B` will 
   be solved. Upon completion, :math:`A` is overwritten with its QR or LQ 
   factorization, and each column of :math:`X` is overwritten with a solution 
   vector.

C++ API
^^^^^^^

.. cpp:function:: void LeastSquares( Orientation orientation, Matrix<F>& A, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void LeastSquares( Orientation orientation, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

C API
^^^^^

.. c:function:: ElError ElLeastSquares_s( ElOrientation orientation, ElMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElLeastSquares_d( ElOrientation orientation, ElMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElLeastSquares_c( ElOrientation orientation, ElMatrix_c A, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElLeastSquares_z( ElOrientation orientation, ElMatrix_z A, ElConstMatrix_z B, ElMatrix_z X )
.. c:function:: ElError ElLeastSquaresDist_s( ElOrientation orientation, ElDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElLeastSquaresDist_d( ElOrientation orientation, ElDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElLeastSquaresDist_c( ElOrientation orientation, ElDistMatrix_c A, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElLeastSquaresDist_z( ElOrientation orientation, ElDistMatrix_z A, ElConstDistMatrix_z B, ElDistMatrix_z X )

General (Gauss-Markov) Linear Model (GLM)
-----------------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/GLM.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/GLM.cpp>`__

.. math::

   \min_{X,Y} \| Y \|_F \;\;\; \text{subject to } A X + B Y = D.

C++ API
^^^^^^^

.. cpp:function:: void GLM( Matrix<F>& A, Matrix<F>& B, Matrix<F>& D, Matrix<F>& Y )
.. cpp:function:: void GLM( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& Y )

C API
^^^^^

.. c:function:: ElError ElGLM_s( ElMatrix_s A, ElMatrix_s B, ElMatrix_s D, ElMatrix_s Y )
.. c:function:: ElError ElGLM_d( ElMatrix_d A, ElMatrix_d B, ElMatrix_d D, ElMatrix_d Y )
.. c:function:: ElError ElGLM_c( ElMatrix_c A, ElMatrix_c B, ElMatrix_c D, ElMatrix_c Y )
.. c:function:: ElError ElGLM_z( ElMatrix_z A, ElMatrix_z B, ElMatrix_z D, ElMatrix_z Y )
.. c:function:: ElError ElGLMDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s D, ElDistMatrix_s Y )
.. c:function:: ElError ElGLMDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d D, ElDistMatrix_d Y )
.. c:function:: ElError ElGLMDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_c D, ElDistMatrix_c Y )
.. c:function:: ElError ElGLMDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_z D, ElDistMatrix_z Y )

Equality-constrained Least Squares (LSE)
----------------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/LSE.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/LSE.cpp>`__

.. math::

   \min_X \| A X - C \|_F \;\;\; \text{subject to } B X = D.

C++ API
^^^^^^^

.. cpp:function:: void LSE( Matrix<F>& A, Matrix<F>& B, Matrix<F>& C, Matrix<F>& D, Matrix<F>& X, bool computeResidual=false )
.. cpp:function:: void LSE( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X, bool computeResidual=false )

C API
^^^^^

.. c:function:: ElError ElLSE_s( ElMatrix_s A, ElMatrix_s B, ElMatrix_s C, ElMatrix_s D, ElMatrix_s X )
.. c:function:: ElError ElLSE_d( ElMatrix_d A, ElMatrix_d B, ElMatrix_d C, ElMatrix_d D, ElMatrix_d X )
.. c:function:: ElError ElLSE_c( ElMatrix_c A, ElMatrix_c B, ElMatrix_c C, ElMatrix_c D, ElMatrix_c X )
.. c:function:: ElError ElLSE_z( ElMatrix_z A, ElMatrix_z B, ElMatrix_z C, ElMatrix_z D, ElMatrix_z X )
.. c:function:: ElError ElLSEDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s C, ElDistMatrix_s D, ElDistMatrix_s X )
.. c:function:: ElError ElLSEDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d C, ElDistMatrix_d D, ElDistMatrix_d X )
.. c:function:: ElError ElLSEDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_c C, ElDistMatrix_c D, ElDistMatrix_c X )
.. c:function:: ElError ElLSEDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_z C, ElDistMatrix_z D, ElDistMatrix_z X )

Multi-shift Hessenberg solves
-----------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/MultiShiftHessSolve.cpp>`__

Solve for :math:`X` in the system

.. math::

   H^\# X - X D^\# = Y

where :math:`H` is Hessenberg, :math:`D` is diagonal, and :math:`A^\#` 
is defined to be one of :math:`\{A,A^T,A^H\}`.

.. note::

   Only a few subcases are currently supported, as this was added as part of 
   :cpp:func:`HessenbergPseudospectrum`

C++ API
^^^^^^^

.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& H, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftHessSolve( UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

C API
^^^^^

.. c:function:: ElError ElMultiShiftHessSolve_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_s H, ElConstMatrix_s shifts, ElMatrix_s X )
.. c:function:: ElError ElMultiShiftHessSolve_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_d H, ElConstMatrix_d shifts, ElMatrix_d X )
.. c:function:: ElError ElMultiShiftHessSolve_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_c H, ElConstMatrix_c shifts, ElMatrix_c X )
.. c:function:: ElError ElMultiShiftHessSolve_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstMatrix_z H, ElConstMatrix_z shifts, ElMatrix_z X )
.. c:function:: ElError ElMultiShiftHessSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_s H, ElConstDistMatrix_s shifts, ElDistMatrix_s X )
.. c:function:: ElError ElMultiShiftHessSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_d H, ElConstDistMatrix_d shifts, ElDistMatrix_d X )
.. c:function:: ElError ElMultiShiftHessSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_c H, ElConstDistMatrix_c shifts, ElDistMatrix_c X )
.. c:function:: ElError ElMultiShiftHessSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, float alpha, ElConstDistMatrix_z H, ElConstDistMatrix_z shifts, ElDistMatrix_z X )
