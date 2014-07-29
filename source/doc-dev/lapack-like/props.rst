Matrix properties
=================

Condition number
----------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Condition.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Condition>`__

The condition number of a matrix with respect to a particular norm is

.. math::

   \kappa(A) = \|A\| \|A^{-1}\|,

with the most common choice being the matrix two-norm.

.. cpp:function:: Base<F> Condition( const Matrix<F>& A, NormType type=TWO_NORM )
.. cpp:function:: Base<F> Condition( const AbstractDistMatrix<F>& A, NormType type=TWO_NORM )

   Returns the condition number with respect to the specified norm 
   (one, two, or Frobenius).

.. cpp:function:: Base<F> FrobeniusCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusCondition( const AbstractDistMatrix<F>& A )

   Returns the condition number with respect to the Frobenius norm.

.. cpp:function:: Base<F> InfinityCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityCondition( const AbstractDistMatrix<F>& A )

   Returns the condition number with respect to the infinity norm.

.. cpp:function:: Base<F> MaxCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> MaxCondition( const AbstractDistMatrix<F>& A )

   Returns the condition number with respect to the entrywise maximum norm.

.. cpp:function:: Base<F> OneCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> OneCondition( const AbstractDistMatrix<F>& A )

   Returns the condition number with respect to the one norm.

.. cpp:function:: Base<F> TwoCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoCondition( const AbstractDistMatrix<F>& A )

   Returns the condition number with respect to the two norm.

Determinant
-----------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Determinant.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Determinant>`__

Though there are many different possible definitions of the determinant of a 
matrix :math:`A \in \mathbb{F}^{n \times n}`, the simplest one is in terms of 
the product of the eigenvalues (including multiplicity):

.. math::

   \mbox{det}(A) = \prod_{i=0}^{n-1} \lambda_i.

General
^^^^^^^

Since :math:`\mbox{det}(AB)=\mbox{det}(A)\mbox{det}(B)`, we can compute the 
determinant of an arbitrary matrix in :math:`\mathcal{O}(n^3)` work by 
computing its LU decomposition (with partial pivoting), :math:`PA=LU`, 
recognizing that :math:`\mbox{det}(P)=\pm 1` 
(the *signature* of the permutation), and computing

.. math::

   \mbox{det}(A) = \mbox{det}(P)\mbox{det}(L)\mbox{det}(U) 
                 = \mbox{det}(P) \prod_{i=0}^{n-1} \upsilon_{i,i}
                 = \pm \prod_{i=0}^{n-1} \upsilon_{i,i},

where :math:`\upsilon_{i,i}` is the i'th diagonal entry of :math:`U`.

.. cpp:function:: F Determinant( const Matrix<F>& A )
.. cpp:function:: F Determinant( const AbstractDistMatrix<F>& A )
.. cpp:function:: F Determinant( Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: F Determinant( DistMatrix<F>& A, bool canOverwrite=false )

   The determinant of the (fully populated) square matrix `A`.
   Some of the variants allow for overwriting the input matrix in order to 
   avoid forming another temporary matrix.

.. cpp:type:: SafeProduct<F>

   Represents the product of `n` values as :math:`\rho \exp(\kappa n)`, 
   where :math:`|\rho| \le 1` and :math:`\kappa \in \mathbb{R}`.

   .. cpp:member:: F rho

      For nonzero values, `rho` is the modulus and lies *on* the unit 
      circle; in order to represent a value that is precisely zero, `rho` 
      is set to zero.

   .. cpp:member:: Base<F> kappa

      `kappa` can be an arbitrary real number.

   .. cpp:member:: int n

      The number of values in the product.

.. cpp:function:: SafeProduct<F> SafeDeterminant( const Matrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeDeterminant( const AbstractDistMatrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeDeterminant( Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: SafeProduct<F> SafeDeterminant( DistMatrix<F>& A, bool canOverwrite=false )

   The determinant of the square matrix `A` in an expanded form 
   which is less likely to over/under-flow.

HPD
^^^
A version of the above determinant specialized for Hermitian positive-definite
matrices (which will therefore have all positive eigenvalues and a positive 
determinant).

.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, DistMatrix<F>& A, bool canOverwrite=false )

   The determinant of the (fully populated) Hermitian positive-definite
   matrix `A`.
   Some of the variants allow for overwriting the input matrix in order to 
   avoid forming another temporary matrix.

.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, DistMatrix<F>& A, bool canOverwrite=false )

   The determinant of the Hermitian positive-definite matrix `A` in an 
   expanded form which is less likely to over/under-flow.

Matrix norms
------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Norm.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Norm>`__

The following routines can return either
:math:`\|A\|_1`, :math:`\|A\|_\infty`, :math:`\|A\|_F` (the Frobenius norm),
the maximum entrywise norm, :math:`\|A\|_2`, or :math:`\|A\|_*`
(the nuclear/trace norm) of fully-populated matrices.

.. cpp:function:: Base<F> Norm( const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> Norm( const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

   Compute a norm of a fully-populated or implicitly symmetric/Hermitian (with 
   the data stored in the specified triangle) matrix. 

Alternatively, one may directly call the following routines (note that the entrywise, KyFan, and Schatten norms have an extra parameter and must be called 
directly).

.. cpp:function:: Base<F> EntrywiseNorm( const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> EntrywiseNorm( const AbstractDistMatrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

   The :math:`\ell_p` norm of the columns of `A` stacked into a single vector. 
   Note that the Frobenius norm corresponds to the :math:`p=2` case.

.. cpp:function:: Base<F> EntrywiseOneNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> EntrywiseOneNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianEntrywiseOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianEntrywiseOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricEntrywiseOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricEntrywiseOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The :math:`\ell_1` norm of the columns of `A` stacked into a single vector. 

.. cpp:function:: Base<F> FrobeniusNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The :math:`\ell_2` norm of the singular values (the Schatten norm with 
   :math:`p=2`), which can be cheaply computed as the :math:`\ell_2` norm of 
   :math:`\text{vec}(A)`.

.. cpp:function:: Base<F> KyFanNorm( const Matrix<F>& A, int k )
.. cpp:function:: Base<F> KyFanNorm( const AbstractDistMatrix<F>& A, int k )
.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, int k )
.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, int k )
.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, int k )
.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, int k )

   The sum of the largest `k` singular values.

.. cpp:function:: Base<F> InfinityNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The maximum :math:`\ell_1` norm of the rows of `A`. In the symmetric and 
   Hermitian cases, this is equivalent to the :math:`\|\cdot \|_1` norm.

.. cpp:function:: Base<F> MaxNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> MaxNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianMaxNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricMaxNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The maximum absolute value of the matrix entries.

.. cpp:function:: Base<F> NuclearNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> NuclearNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The sum of the singular values. This is equivalent to both the KyFan 
   norm with :math:`k=n` and the Schatten norm with :math:`p=1`.
   Note that the nuclear norm is dual to the two-norm, which is the 
   Schatten norm with :math:`p=\infty`.

.. cpp:function:: Base<F> OneNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> OneNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The maximum :math:`\ell_1` norm of the columns of `A`. In the symmetric and 
   Hermitian cases, this is equivalent to the :math:`\| \cdot \|_\infty` norm.

.. cpp:function:: Base<F> SchattenNorm( const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SchattenNorm( const AbstractDistMatrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

   The :math:`\ell_p` norm of the singular values.

.. cpp:function:: Base<F> TwoNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

   The maximum singular value. This is equivalent to the KyFan norm with `k` 
   equal to one and the Schatten norm with :math:`p=\infty`.

.. cpp:function:: int ZeroNorm( const Matrix<F>& A )
.. cpp:function:: int ZeroNorm( const AbstractDistMatrix<F>& A )

   Return the number of nonzero entries in the matrix.

   .. note::

      Symmetric/Hermitian versions are not yet written

Two-norm estimates
^^^^^^^^^^^^^^^^^^

.. cpp:function:: Base<F> TwoNormEstimate( const Matrix<F>& A, Base<F> tol=1e-6 )
.. cpp:function:: Base<F> TwoNormEstimate( const DistMatrix<F>& A, Base<F> tol=1e-6 )
.. cpp:function:: Base<F> HermitianTwoNormEstimate( const Matrix<F>& A, Base<F> tol=1e-6 )
.. cpp:function:: Base<F> HermitianTwoNormEstimate( const DistMatrix<F>& A, Base<F> tol=1e-6 )
.. cpp:function:: Base<F> SymmetricTwoNormEstimate( const Matrix<F>& A, Base<F> tol=1e-6 )
.. cpp:function:: Base<F> SymmetricTwoNormEstimate( const DistMatrix<F>& A, Base<F> tol=1e-6 )

   Return an estimate for the two-norm which should be accurate within a 
   factor of :math:`n` times the specified tolerance.

Pseudospectra
-------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Pseudospectra.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Pseudospectra>`__

`Pseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/Pseudospectra.cpp>`__

`ChunkedPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/ChunkedPseudospectra.cpp>`__

`TriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/TriangularPseudospectra.cpp>`__

`ChunkedTriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/ChunkedTriangularPseudospectra.cpp>`__

The :math:`\epsilon`-*pseudospectrum* of a square matrix :math:`A` is the set
of all shifts :math:`z` such that :math:`\hat A - z` is singular for some
:math:`\hat A` such that :math:`\| \hat A - A \|_2 < \epsilon`. In other
words, :math:`z` is in the :math:`\epsilon`-pseudospectrum of :math:`A` if
the smallest singular value of :math:`A - z` is less than :math:`\epsilon`.

Elemental currently supports two methods for computing pseudospectra: 
the first is a high-performance improvement of Shiu-Hong Lui's 
triangularization followed by inverse iteration approach suggested in
*Computation of pseudospectra by continuation* (please see
Trefethen's *Computation of pseudospectra* for a comprehensive review).
In particular, Elemental begins by computing the Schur decomposition of the
given matrix, which preserves the :math:`\epsilon`-pseudospectrum, up to
round-off error, and then simultaneously performs many Implicitly Restarted 
Arnoldi (IRA) iterations with the inverse normal matrix for each shift in a 
manner which communicates no more data than a standard triangular solve with 
many right-hand sides.
Converged pseudospectral estimates are deflated after convergence.

The second approach is quite similar and, instead of reducing to triangular
form, reduces to Hessenberg form and performs multi-shift triangular solves
in a manner similar to Greg Henry's *The shifted Hessenberg system solve 
computation* and Purkayastha et al.'s *A parallel algorithm for the 
Sylvester-Observer Equation*. This algorithm is not yet performance-tuned in
Elemental, but should be preferred in massively-parallel situations where the
Schur decomposition is considered infeasible.

.. cpp:type:: SnapshotCtrl

   .. cpp:member:: int realSize
   .. cpp:member:: int imagSize

   .. cpp:member:: int imgSaveFreq
   .. cpp:member:: int numSaveFreq
   .. cpp:member:: int imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to :math:`n > 0`
      if, in addition to a final snapshot, the partial results should be output roughly overy `n`
      iterations (there is no output in the middle of Impliclty Restarted Arnoldi cycles). 

   .. cpp:member:: int imgSaveCount
   .. cpp:member:: int numSaveCount
   .. cpp:member:: int imgDispCount

   .. cpp:member:: std::string imgBase
   .. cpp:member:: std::string numBase

   .. cpp:member:: FileFormat imgFormat
   .. cpp:member:: FileFormat numFormat

   .. cpp:function::  SnapshotCtrl()

      All counters and dimensions are initially zero, all save/display "frequencies" are set
      to -1 (no output), the basename strings are initialized to "ps",
      the image format to ``PNG``, and the numerical format to ``ASCII_MATLAB``.

   .. cpp:function:: void ResetCounts()

      Resets all counters to zero

   .. cpp:function:: void Iterate()

      Increments all counters by one

.. cpp:type:: PseudospecCtrl<Real>

   .. cpp:member::bool schur

   .. cpp:member:: bool forceComplexSchur

   .. cpp:member:: bool forceComplexPs

   .. cpp:member:: SdcCtrl<Real> sdcCtrl

   .. cpp:member:: int maxIts

   .. cpp:member:: Real tol

   .. cpp:member:: bool deflate

   .. cpp:member:: bool arnoldi

   .. cpp:member:: int basisSize

   .. cpp:member:: bool reorthog

   .. cpp:member:: bool progress

   .. cpp:member:: SnapshotCtrl snapCtrl

.. cpp:type:: PseudospecCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const DistMatrix<F>& A, DistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const DistMatrix<F>& U, DistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, int realSize, int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const DistMatrix<Real>& U, DistMatrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, int realSize, int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const DistMatrix<F>& H, DistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

   Returns the norms of the shifted inverses over a 2D window in the complex
   plane (in the matrix ``invNormMap``) with the specified x and y resolutions.
   The returned integer matrix corresponds to the number of iterations required
   for convergence at each shift in the 2D grid.

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const DistMatrix<F>& A, DistMatrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const DistMatrix<F>& U, DistMatrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const DistMatrix<Real>& U, DistMatrix<Real>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const DistMatrix<F>& H, DistMatrix<Base<F>>& invNormMap, int realSize, int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

   Same as above, but the window in the complex plane is automatically
   determined.

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> Pseudospectra( const DistMatrix<F>& A, const DistMatrix<Complex<Base<F>>,VR,STAR>& shifts, DistMatrix<Base<F>,VR,STAR>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> TriangularPseudospectra( const DistMatrix<F>& U, const DistMatrix<Complex<Base<F>>,VR,STAR>& shifts, DistMatrix<Base<F>,VR,STAR>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> QuasiTriangularPseudospectra( const DistMatrix<Real>& U, const DistMatrix<Complex<Real>,VR,STAR>& shifts, DistMatrix<Real,VR,STAR>& invNorms, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> HessenbergPseudospectra( const DistMatrix<F>& H, const DistMatrix<Complex<Base<F>>,VR,STAR>& shifts, DistMatrix<Base<F>,VR,STAR>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

   Returns the norms of the shifted inverses in the vector ``invNorms`` for a
   given set of shifts. The returned integer vector is a list of the number of
   iterations required for convergence of each shift.

Trace
-----

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Trace.hpp>`__

The two equally useful definitions of the trace of a square matrix 
:math:`A \in \mathbb{F}^{n \times n}` are

.. math::

   \mbox{tr}(A) = \sum_{i=0}^{n-1} \alpha_{i,i} = \sum_{i=0}^{n-1} \lambda_i,

where :math:`\alpha_{i,i}` is the i'th diagonal entry of :math:`A` and 
:math:`\lambda_i` is the i'th eigenvalue (counting multiplicity) of :math:`A`.

Clearly the former equation is easier to compute, but the latter is an 
important characterization.

.. cpp:function:: T Trace( const Matrix<T>& A )
.. cpp:function:: T Trace( const AbstractDistMatrix<T>& A )

   Return the trace of the square matrix `A`.

Inertia
-------

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Inertia.hpp>`__

.. cpp:type:: InertiaType

   .. cpp:member:: int numPositive
   .. cpp:member:: int numNegative
   .. cpp:member:: int numZero

      The basic eigenvalue structure of a Hermitian matrix (which can be quickly
      computed from the quasi-diagonal matrix produced by Bunch-Kaufman).

.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, Matrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )
.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, DistMatrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )

   Returns the triplet containing the number of positive, negative, and 
   zero eigenvalues of the Hermitian matrix by analyzing the block diagonal
   resulting from a pivoted LDL factorization.
