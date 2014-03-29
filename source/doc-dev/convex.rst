Convex optimization
*******************

ADMM solvers
============

BasisPursuit
------------

Attempt to minimize :math:`\| x \|_1` such that :math:`Ax=b` using ADMM.

.. cpp:function:: int BasisPursuit( const Matrix<F>& A, const Matrix<F>& b, Matrix<F>& x, Matrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=true, Base<F> pinvTol=0, bool progress=false )
.. cpp:function:: int BasisPursuit( const DistMatrix<F>& A, const DistMatrix<F>& b, DistMatrix<F>& x, DistMatrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=true, Base<F> pinvTol=0, bool progress=false )

    These functions are inspired by the following `basis pursuit ADMM algorithm
    <http://www.stanford.edu/~boyd/papers/admm/basis_pursuit/basis_pursuit.html>`__
    but make use of parallel linear algebra and allow the user to choose between either
    directly computing a (thresholded-)pseudoinverse or an LQ factorization.
    The return value is the number of performed ADMM iterations.

LinearProgram
-------------

Attempt to solve the linear program 

.. math::
   
   \text{min}\, c^T x \;\;\;\text{such that }Ax=b,\; x \ge 0.

using ADMM.

.. cpp:function:: int LinearProgram( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: int LinearProgram( const DistMatrix<Real>& A, const DistMatrix<Real>& b, const DistMatrix<Real>& c, DistMatrix<Real>& x, DistMatrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

    These functions are inspired by the following `ADMM linear program solver
    <http://www.stanford.edu/~boyd/papers/admm/linprog/linprog.html>`__
    but make use of parallel linear algebra and a custom LU factorization along with 
    allowing the user to optionally directly invert the (pivoted) Schur complement
    in order to accelerate the application of the inverse in parallel.
    The return value is the number of performed ADMM iterations.

QuadraticProgram
----------------

Attempt to solve the quadratic program

.. math::

   \text{min} \frac{1}{2} x^T P x + q^T x\;\;\;\text{such that }l_b \le x \le u_b

using ADMM.

.. cpp:function:: int QuadraticProgram( const Matrix<Real>& P, const Matrix<Real>& q, Real lb, Real ub, Matrix<Real>& x, Matrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: int QuadraticProgram( const DistMatrix<Real>& P, const DistMatrix<Real>& q, Real lb, Real ub, DistMatrix<Real>& x, DistMatrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

    These functions are inspired by the following `ADMM quadratic program solver
    <http://www.stanford.edu/~boyd/papers/admm/quadprog/quadprog.html>`__
    but make use of parallel linear algebra and allow the user to optionally directly 
    invert the Cholesky factor in order to accelerate the application of its inverse in 
    parallel. The return value is the number of performed ADMM iterations.

Utilities
=========

Clip
----
Force every entry of a matrix to lie within a given (half-)interval.

.. cpp:function:: void LowerClip( Matrix<Real>& X, Real lowerBound=0 )
.. cpp:function:: void LowerClip( DistMatrix<Real>& X, Real lowerBound=0 )

   Force every entry to be at least `lowerBound`.

.. cpp:function:: void UpperClip( Matrix<Real>& X, Real upperBound=0 )
.. cpp:function:: void UpperClip( DistMatrix<Real>& X, Real upperBound=0 )

   Force every entry to be at most `upperBound`.

.. cpp:function:: void Clip( Matrix<Real>& X, Real lowerBound=0, Real upperBound=1 )
.. cpp:function:: void Clip( DistMatrix<Real>& X, Real lowerBound=0, Real upperBound=1 )

   Force every entry to lie within the interval defined by `lowerBound` and `upperBound`.

LogBarrier
----------
Uses a careful calculation of the log of the determinant in order to return
the *log barrier* of a Hermitian positive-definite matrix `A`,
:math:`-\log(\mbox{det}(A))`.

.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const DistMatrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, DistMatrix<F>& A, bool canOverwrite=false )

LogDetDivergence
----------------
The *log-det divergence* of a pair of :math:`n \times n` Hermitian
positive-definite matrices :math:`A` and :math:`B` is

.. math::

   D_{ld}(A,B) = \mbox{tr}(A B^{-1}) -\log(\mbox{det}(A B^{-1})) - n,

which can be greatly simplified using the Cholesky factors of :math:`A` and :math:`B`.
In particular, if we set :math:`Z = L_B^{-1} L_A`, where :math:`A=L_A L_A^H` and 
:math:`B=L_B L_B^H` are Cholesky factorizations, then

.. math::

   D_{ld}(A,B) = \| Z \|_F^2 - 2 \log(\mbox{det}(Z)) - n.

.. cpp:function:: Base<F> LogDetDivergence( UpperOrLower uplo, const Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: Base<F> LogDetDivergence( UpperOrLower uplo, const DistMatrix<F>& A, const DistMatrix<F>& B )

Singular-value soft-thresholding
--------------------------------
Overwrites :math:`A` with :math:`U S_{\tau}(\Sigma) V^H`, where :math:`U \Sigma V^H` is the singular-value decomposition of :math:`A` upon input and :math:`S_{\tau}` performs soft-thresholding with parameter :math:`\tau`.
The return value is the rank of the soft-thresholded matrix.

.. cpp:function:: int SVT( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: int SVT( DistMatrix<F>& A, Base<F> tau, bool relative=false )

   Runs the default SVT algorithm. In the sequential case, this is currently
   `svt::Normal`, and, in the parallel case, it is `svt::Cross`.

.. cpp:function:: int SVT( Matrix<F>& A, Base<F> tau, int relaxedRank, bool relative=false )
.. cpp:function:: int SVT( DistMatrix<F>& A, Base<F> tau, int relaxedRank, bool relative=false )

   Runs a faster (for small ranks), but less accurate, algorithm given an
   upper bound on the rank of the soft-thresholded matrix.
   The current implementation preprocesses via `relaxedRank` steps of 
   (Businger-Golub) column-pivoted QR via the routine `svt::PivotedQR`.

.. cpp:function:: int SVT( DistMatrix<F,U,STAR>& A, Base<F> tau, bool relative=false )

   Runs an SVT algorithm designed for tall-skinny matrices. 
   The current implementation is based on TSQR factorization and is
   `svt::TSQR`.

namespace svt
^^^^^^^^^^^^^

.. cpp:function:: int svt::Normal( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: int svt::Normal( DistMatrix<F>& A, Base<F> tau, bool relative=false )

   Runs a standard SVD, soft-thresholds the singular values, and then reforms
   the matrix.

.. cpp:function:: int svt::Cross( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: int svt::Cross( DistMatrix<F>& A, Base<F> tau, bool relative=false )

   Forms the normal matrix, computes its Hermitian EVD, soft-thresholds the
   eigenvalues, and then reforms the matrix. Note that Elemental's parallel 
   Hermitian EVD is much faster than its parallel SVD; this is typically worth
   the loss of accuracy in the computed small (truncated) singular values and
   is therefore the default choice for parallel SVT.

.. cpp:function:: int svt::PivotedQR( Matrix<F>& A, Base<F> tau, int numStepsQR, bool relative=false )
.. cpp:function:: int svt::PivotedQR( DistMatrix<F>& A, Base<F> tau, int numStepsQR, bool relative=false )

   Computes an approximate SVT by first approximating A as the rank-`numSteps`
   approximation produced by `numSteps` iterations of column-pivoted QR.

.. cpp:function:: int svt::TSQR( DistMatrix<F,U,STAR>& A, Base<F> tau, bool relative=false )

   Since the majority of the work in a tall-skinny SVT will be in the initial
   QR factorization, this algorithm runs a TSQR factorization and then 
   computes the SVT of the small R factor using a single process.

Soft-thresholding
-----------------
Overwrites each entry of :math:`A` with its soft-thresholded value.

.. cpp:function:: void SoftThreshold( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: void SoftThreshold( DistMatrix<F>& A, Base<F> tau, bool relative=false )
