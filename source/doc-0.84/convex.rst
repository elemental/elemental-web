Convex optimization
*******************

ADMM solvers
============
The following functions are inspired by 
`the MATLAB scripts <http://www.stanford.edu/~boyd/papers/admm/>`__ associated 
with the paper:

    `S. Boyd, N. Parikh, E. Chu, B. Peleato, and J. Eckstein, Distributed optimization and 
    statistical learning via the Alternating Direction Method of Multipliers
    <http://www.stanford.edu/~boyd/papers/admm_distr_stats.html>`__,

which describes a wide variety of optimization schemes using the Alternating Direction Method of 
Multipliers (ADMM). 

BasisPursuit
------------

Attempt to minimize :math:`\| x \|_1` such that :math:`Ax=b` using ADMM.

.. cpp:function:: int BasisPursuit( const Matrix<F>& A, const Matrix<F>& b, Matrix<F>& x, Matrix<F>& z, Matrix<F>& u, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=true, Base<F> pinvTol=0, bool progress=false )
.. cpp:function:: int BasisPursuit( const DistMatrix<F>& A, const DistMatrix<F>& b, DistMatrix<F>& x, DistMatrix<F>& z, DistMatrix<F>& u, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=true, Base<F> pinvTol=0, bool progress=false )

    `Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/BasisPursuit.hpp>`__

    `Example driver on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/convex/BasisPursuit.cpp>`__

    These functions are inspired by `this basis pursuit ADMM implementation
    <http://www.stanford.edu/~boyd/papers/admm/basis_pursuit/basis_pursuit.html>`__.
    Elemental's implementations use parallel (dense) linear algebra and 
    allows the user to choose between either directly computing a 
    (thresholded-)pseudoinverse or an LQ factorization. The return value is the 
    number of performed ADMM iterations.

    +------------+--------------+----------------------------------------+
    | Parameters | Input/Output | Explanation                            |
    +============+==============+========================================+
    | `A`        | Input        | part of constraint :math:`Ax=b`        |
    +------------+--------------+----------------------------------------+
    | `b`        | Input        | part of constraint :math:`Ax=b`        |
    +------------+--------------+----------------------------------------+
    | `x`        | Output       | primal solution (first term)           |
    +------------+--------------+----------------------------------------+
    | `z`        | Output       | primal solution (second term)          |
    +------------+--------------+----------------------------------------+
    | `u`        | Output       | dual solution                          |
    +------------+--------------+----------------------------------------+
    | `rho`      | Input        | augmented-Lagrangian parameter         |
    +------------+--------------+----------------------------------------+
    | `alpha`    | Input        | over-relaxation parameter              |
    |            |              | (usually in :math:`[1,1.8]`)           |
    +------------+--------------+----------------------------------------+
    | `maxIter`  | Input        | maximum number of ADMM iterations      |
    +------------+--------------+----------------------------------------+
    | `absTol`   | Input        | absolute convergence tolerance         |
    +------------+--------------+----------------------------------------+
    | `relTol`   | Input        | relative convergence tolerance         | 
    +------------+--------------+----------------------------------------+
    | `usePinv`  | Input        | directly compute a pseudoinverse?      |
    +------------+--------------+----------------------------------------+
    | `pinvTol`  | Input        | the pseudoinverse inversion tolerance  |
    +------------+--------------+----------------------------------------+
    | `progress` | Input        | display detailed progress information? | 
    +------------+--------------+----------------------------------------+

LinearProgram
-------------

Attempt to solve the linear program 

.. math::
   
   \text{min}\, c^T x \;\;\;\text{such that }Ax=b,\; x \ge 0.

using ADMM.

.. cpp:function:: int LinearProgram( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& z, Matrix<Real>& u, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: int LinearProgram( const DistMatrix<Real>& A, const DistMatrix<Real>& b, const DistMatrix<Real>& c, DistMatrix<Real>& x, DistMatrix<Real>& z, DistMatrix<F>& u, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

    `Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/LinearProgram.hpp>`__

    `Example driver on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/convex/LinearProgram.cpp>`__

    These functions are inspired by `this ADMM linear program solver
    <http://www.stanford.edu/~boyd/papers/admm/linprog/linprog.html>`__.
    Elemental's implementations make use of parallel (dense) linear algebra, 
    a custom structured factorization, and allows the user to optionally 
    directly invert the (pivoted) Schur complement to accelerate its 
    application. The return value is the number of performed ADMM iterations.

    +------------+--------------+--------------------------------------------+
    | Parameters | Input/Output | Explanation                                |
    +============+==============+============================================+
    | `A`        | Input        | part of constraints, :math:`Ax=b`          |
    +------------+--------------+--------------------------------------------+
    | `b`        | Input        | part of constraints, :math:`Ax=b`          |
    +------------+--------------+--------------------------------------------+
    | `c`        | Input        | part of the objective, :math:`c^T x`       |
    +------------+--------------+--------------------------------------------+
    | `x`        | Output       | primal solution (first term)               |
    +------------+--------------+--------------------------------------------+
    | `z`        | Output       | primal solution (second term)              |
    +------------+--------------+--------------------------------------------+
    | `u`        | Output       | dual solution                              |
    +------------+--------------+--------------------------------------------+
    | `rho`      | Input        | augmented-Lagrangian parameter             |
    +------------+--------------+--------------------------------------------+
    | `alpha`    | Input        | over-relaxation parameter                  |
    |            |              | (usually in :math:`[1,1.8]`)               |
    +------------+--------------+--------------------------------------------+
    | `maxIter`  | Input        | maximum number of ADMM iterations          |
    +------------+--------------+--------------------------------------------+
    | `absTol`   | Input        | absolute convergence tolerance             |
    +------------+--------------+--------------------------------------------+
    | `relTol`   | Input        | relative convergence tolerance             | 
    +------------+--------------+--------------------------------------------+
    | `inv`      | Input        | directly compute Schur-complement inverse? |
    +------------+--------------+--------------------------------------------+
    | `progress` | Input        | display detailed progress information?     | 
    +------------+--------------+--------------------------------------------+


QuadraticProgram
----------------

Attempt to solve the quadratic program

.. math::

   \text{min} \frac{1}{2} x^T P x + q^T x\;\;\;\text{such that }l_b \le x \le u_b

using ADMM.

.. cpp:function:: int QuadraticProgram( const Matrix<Real>& P, const Matrix<Real>& q, Real lb, Real ub, Matrix<Real>& x, Matrix<Real>& z, Matrix<Real>& u, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: int QuadraticProgram( const DistMatrix<Real>& P, const DistMatrix<Real>& q, Real lb, Real ub, DistMatrix<Real>& x, DistMatrix<Real>& z, DistMatrix<Real>& u, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

    `Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/QuadraticProgram.hpp>`__

    `Example driver on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/convex/QuadraticProgram.cpp>`__

    These functions are inspired by `this ADMM quadratic program solver
    <http://www.stanford.edu/~boyd/papers/admm/quadprog/quadprog.html>`__.
    Elemental's implementations make use of parallel (dense) linear algebra 
    and allows the user to optionally directly invert the Cholesky factor to 
    improve the parallel performance of the application of its inverse.

    +------------+--------------+--------------------------------------------+
    | Parameters | Input/Output | Explanation                                |
    +============+==============+============================================+
    | `P`        | Input        | SPD and part of objective,                 |
    |            |              | :math:`\frac{1}{2}x^T P x + q^T x`         |
    +------------+--------------+--------------------------------------------+
    | `q`        | Input        | part of objective                          |
    +------------+--------------+--------------------------------------------+
    | `lb`       | Input        | lower-bound of constraints,                |
    |            |              | :math:`l_b \le x \le u_b`                  |
    +------------+--------------+--------------------------------------------+
    | `ub`       | Input        | upper-bound of constraints,                |
    |            |              | :math:`l_b \le x \le u_b`                  |
    +------------+--------------+--------------------------------------------+
    | `x`        | Output       | primal solution (first term)               |
    +------------+--------------+--------------------------------------------+
    | `z`        | Output       | primal solution (second term)              |
    +------------+--------------+--------------------------------------------+
    | `u`        | Output       | dual solution                              |
    +------------+--------------+--------------------------------------------+
    | `rho`      | Input        | augmented-Lagrangian parameter             |
    +------------+--------------+--------------------------------------------+
    | `alpha`    | Input        | over-relaxation parameter                  |
    |            |              | (usually in :math:`[1,1.8]`)               |
    +------------+--------------+--------------------------------------------+
    | `maxIter`  | Input        | maximum number of ADMM iterations          |
    +------------+--------------+--------------------------------------------+
    | `absTol`   | Input        | absolute convergence tolerance             |
    +------------+--------------+--------------------------------------------+
    | `relTol`   | Input        | relative convergence tolerance             | 
    +------------+--------------+--------------------------------------------+
    | `inv`      | Input        | compute inverse of Cholesky factor?        |
    +------------+--------------+--------------------------------------------+
    | `progress` | Input        | display detailed progress information?     | 
    +------------+--------------+--------------------------------------------+

SparseInvCov
------------

Attempt to find a sparse inverse covariance matrix which generated the given
observations by solving the program

.. math::

   \text{min} \text{trace}(S X) - \text{log}\;\text{det}\;X + \lambda \|\text{vec}(X)\|_1

using ADMM.

.. cpp:function:: int SparseInvCov( const Matrix<Real>& D, Matrix<Real>& X, Matrix<Real>& Z, Matrix<Real>& U, Real lambda, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool progress=true )
.. cpp:function:: int SparseInvCov( const DistMatrix<Real>& D, DistMatrix<Real>& X, DistMatrix<Real>& Z, DistMatrix<Real>& U, Real lambda, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool progress=true )

    `Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/SparseInvCov.hpp>`__

    `Example driver on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/convex/SparseInvCov.cpp>`__

    These functions are inspired by `this ADMM solver
    <http://www.stanford.edu/~boyd/papers/admm/covsel/covsel.html>`__.
    Elemental's implementations make use of parallel (dense) linear algebra
    (including PMRRR for the symmetric tridiagonal eigensolver).

    +------------+--------------+--------------------------------------------+
    | Parameters | Input/Output | Explanation                                |
    +============+==============+============================================+
    | `D`        | Input        | Observations                               |
    +------------+--------------+--------------------------------------------+
    | `X`        | Output       | primal solution (first term)               |
    +------------+--------------+--------------------------------------------+
    | `Z`        | Output       | primal solution (second term)              |
    +------------+--------------+--------------------------------------------+
    | `U`        | Output       | dual solution                              |
    +------------+--------------+--------------------------------------------+
    | `lambda`   | Input        | coefficient for vector-l1 penalty          |
    +------------+--------------+--------------------------------------------+
    | `rho`      | Input        | augmented-Lagrangian parameter             |
    +------------+--------------+--------------------------------------------+
    | `alpha`    | Input        | over-relaxation parameter                  |
    |            |              | (usually in :math:`[1,1.8]`)               |
    +------------+--------------+--------------------------------------------+
    | `maxIter`  | Input        | maximum number of ADMM iterations          |
    +------------+--------------+--------------------------------------------+
    | `absTol`   | Input        | absolute convergence tolerance             |
    +------------+--------------+--------------------------------------------+
    | `relTol`   | Input        | relative convergence tolerance             | 
    +------------+--------------+--------------------------------------------+
    | `progress` | Input        | display detailed progress information?     | 
    +------------+--------------+--------------------------------------------+

Utilities
=========
The following utility routines are widely-used within first-order optimization 
methods, and some, such as Singular Value soft-Thresholding (SVT), warrant
non-trivial implementations.

Clip
----
Force every entry of a matrix to lie within a given (half-)interval.

`Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/Clip.hpp>`__

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

`Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/LogBarrier.hpp>`__

.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const DistMatrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, DistMatrix<F>& A, bool canOverwrite=false )

LogDetDiv
---------
The *log-det divergence* of a pair of :math:`n \times n` Hermitian
positive-definite matrices :math:`A` and :math:`B` is

.. math::

   D_{ld}(A,B) = \mbox{tr}(A B^{-1}) -\log(\mbox{det}(A B^{-1})) - n,

which can be greatly simplified using the Cholesky factors of :math:`A` and :math:`B`.
In particular, if we set :math:`Z = L_B^{-1} L_A`, where :math:`A=L_A L_A^H` and 
:math:`B=L_B L_B^H` are Cholesky factorizations, then

.. math::

   D_{ld}(A,B) = \| Z \|_F^2 - 2 \log(\mbox{det}(Z)) - n.

`Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/LogDetDiv.hpp>`__

`Example driver on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/convex/LogDetDiv.cpp>`__

.. cpp:function:: Base<F> LogDetDivergence( UpperOrLower uplo, const Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: Base<F> LogDetDivergence( UpperOrLower uplo, const DistMatrix<F>& A, const DistMatrix<F>& B )

Singular-value soft-thresholding
--------------------------------
Overwrites :math:`A` with :math:`U S_{\tau}(\Sigma) V^H`, where :math:`U \Sigma V^H` is the singular-value decomposition of :math:`A` upon input and :math:`S_{\tau}` performs soft-thresholding with parameter :math:`\tau`.
The return value is the rank of the soft-thresholded matrix.

`Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/SVT.hpp>`__

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

`Implementations on GitHub <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/convex/SoftThreshold.hpp>`__

.. cpp:function:: void SoftThreshold( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: void SoftThreshold( DistMatrix<F>& A, Base<F> tau, bool relative=false )
