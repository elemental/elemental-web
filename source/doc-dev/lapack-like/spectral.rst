Spectral decompositions
=======================
`Header <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/spectral.hpp>`__

Hermitian eigensolver
---------------------
`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/HermitianEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianEig.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/HermitianEig.cpp>`__

Elemental provides a collection of routines for both full and partial 
solution of the Hermitian eigenvalue problem 

.. math::

   A Z = Z \Lambda,

where `A` is the given Hermitian matrix, and unitary `Z` and real diagonal 
:math:`\Lambda` are sought. 

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenvalues of the Hermitian matrix `A` determined by
   the `subset` structure (the default is to compute all eigenvalues).
   By default, Elemental is used to transform the problem to and from 
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenpairs of the Hermitian matrix `A` determined by
   the `subset` structure (the default is to compute all eigenpairs).
   By default, Elemental is used to transform the problem to and from 
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

Subset computation
^^^^^^^^^^^^^^^^^^
The structure used to control subset computation is

.. cpp:type:: HermitianEigSubset<Real>

   .. cpp:member:: bool indexSubset
   .. cpp:member:: Int lowerIndex
   .. cpp:member:: Int upperIndex

      If `indexSubset` is true, then the eigenvalues/pairs with indices 
      (inclusively) between `lowerIndex` and `upperIndex` will be found.

   .. cpp:member:: bool rangeSubset
   .. cpp:member:: Real lowerBound
   .. cpp:member:: Real upperBound

      Alternatively, if `rangeSubset` is true, 
      then the eigenvalues/pairs within the numerical range
      :math:`(lowerBound,upperBound]` will be found.

.. cpp:type:: HermitianEigSubset<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

Note that, by default, both `indexSubset` and `rangeSubset` are false, which
leads to the entire spectrum being computed.

Algorithmic options
^^^^^^^^^^^^^^^^^^^
The default approach starts with Householder tridiagonalization 
(ala :cpp:func:`HermitianTridiag`) and then calls Matthias Petschow and 
Paolo Bientinesi's PMRRR for the tridiagonal eigenvalue problem.

.. note::

   Please see the :ref:`lapack-tuning` section for extensive information on 
   maximizing the performance of Householder tridiagonalization.

.. note::

   Unfortunately, PMRRR currently only supports double-precision problems, and 
   so the parallel versions of these routines are limited to real and complex 
   double-precision matrices.

However, it is also possible to use a (prototype) Spectral Divide and 
Conquer algorithm (see, for example, *Stable and efficient spectral divide and conquer algorithms for the symmetric eigenvalue problem*, Nakatsukasa et al., and *Fast linear algebra is stable*, Demmel et al.). In order to do so, the 
`HermitianEigCtrl` structure,

.. cpp:type:: HermitianEigCtrl<Real>

   .. cpp:member:: HermitianTridiagCtrl tridiagCtrl
   .. cpp:member:: HermitianSDCCtrl<Real> sdcCtrl
   .. cpp:member:: bool useSDC

   .. cpp:function:: HermitianEigCtrl()

      Initializes `tridiagCtrl` and `sdcCtrl` to their defaults and sets
      `useSDC` to false.

.. cpp:type:: HermitianEigCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

should be modified so that `useSDC` is set to `true`. The Spectral Divide and
Conquer algorithm is controlled via the structure

.. cpp:type:: HermitianSDCCtrl<Real>

   .. cpp:member:: int cutoff
   .. cpp:member:: int maxInnerIts
   .. cpp:member:: int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

.. cpp:type:: HermitianSDCCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

Skew-Hermitian eigensolver
--------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/SkewHermitianEig.cpp>`__

Essentially identical to the Hermitian eigensolver, :cpp:func:`HermitianEig`;
for any skew-Hermitian matrix :math:`G`, :math:`iG` is Hermitian, as 

.. math::

   (iG)^H = -iG^H = iG.

This fact implies a fast method for solving skew-Hermitian eigenvalue problems:

1. Form :math:`iG` in :math:`O(n^2)` work 
   (switching to complex arithmetic in the real case)
2. Run a Hermitian eigensolve on :math:`iG`, yielding :math:`iG=Z \Lambda Z^H`.
3. Recognize that :math:`G=Z (-i \Lambda) Z^H` provides an EVD of :math:`G`.

Please see the :cpp:func:`HermitianEig` documentation for more details.

.. note::

   Unfortunately, PMRRR currently only supports double-precision problems, and 
   so the parallel versions of these routines are limited to real and complex 
   double-precision matrices.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the imaginary components of the eigenvalues of the skew-Hermitian 
   matrix `G` determined by
   the `subset` structure (the default is to compute all eigenvalues).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, Matrix<Complex<Base<F>>>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<Complex<Base<F>>>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenpairs (note that only the imaginary components of 
   the eigenvalues are returned) of the skew-Hermitian matrix `G` determined by
   the `subset` structure (the default is to compute all eigenpairs).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

Hermitian generalized-definite eigensolvers
-------------------------------------------
The following Hermitian generalized-definite eigenvalue problems frequently 
appear, where both :math:`A` and :math:`B` are Hermitian, and :math:`B` is 
additionally positive-definite:

.. math::

   ABx = \lambda x,

which is denoted with the value ``ABX`` via the :cpp:type:`Pencil` enum,

.. math::

   BAx = \lambda x,

which uses the ``BAX`` value, and finally

.. math::

   Ax = \lambda B x,

which uses the ``AXBX`` enum value.

.. cpp:type:: Pencil

   An enum for specifying either the ``ABX``, ``BAX``, or ``AXBX`` 
   generalized eigenvalue problems (described above).

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/HermitianGenDefEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianGenDefEig.cpp>`__

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenvalues of the Hermitian-definite matrix pencil 
   determined by
   the `subset` structure (the default is to compute all eigenvalues).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenpairs of the Hermitian-definite matrix pencil 
   determined by
   the `subset` structure (the default is to compute all eigenpairs).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

Unitary eigensolver
-------------------
Not yet written, will likely be based on Ming Gu's unitary Divide and Conquer 
algorithm for unitary Hessenberg matrices. The spectral divide and conquer 
technique described below should suffice in the meantime.

Normal eigensolver
------------------
Not yet written, will likely be based on Angelika Bunse-Gerstner et al.'s 
Jacobi-like method for simultaneous diagonalization of the commuting Hermitian 
and skew-Hermitian portions of the matrix.
The spectral divide and conquer scheme described below should suffice in the 
meantime.

Schur decomposition
-------------------

Elemental contains a native prototype implementation of a spectral divide and
conquer scheme for the Schur decomposition, but it is not yet robust enough
to handle general matrices. For local matrices, Elemental defaults to calling
LAPACK's Hessenberg QR algorithm (with Aggressive Early Deflation); if 
support for ScaLAPACK was detected during configuration, Elemental defaults to
ScaLAPACK's Hessenberg QR algorithm (without deflation), otherwise the 
Spectral Divide and Conquer approach is attempted.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Schur.cpp>`__

.. cpp:function:: void Schur( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, bool fullTriangle=false, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( AbstractDistMatrix<F>& A, AbstractDistMatrix<Complex<Base<F>>>& w, bool fullTriangle=false, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, Matrix<F>& Q, bool fullTriangle=true, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( AbstractDistMatrix<F>& A, AbstractDistMatrix<Complex<Base<F>>>& w, AbstractDistMatrix<F>& Q, bool fullTriangle=true, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )

Algorithmic options
^^^^^^^^^^^^^^^^^^^
By default, Hessenberg QR algorithms are used if possible 
(in the distributed-memory case, ScaLAPACK must have been detected), and, 
in addition to being able to configure the Hessenberg QR algorithm options,
it is also possible to force the usage of a Spectral Divide and Conquer 
algorithm.

.. cpp:type:: SchurCtrl<Real>

   .. cpp:member:: bool useSDC

      Whether or not to use Spectral Divide and Conquer

   .. cpp:member:: HessQRCtrl qrCtrl

      The control structure for the Hessenberg QR algorithm

   .. cpp:member:: SDCCtrl<Real> sdcCtrl

      The control structure for the Spectral Divide and Conquer algorithm

.. cpp:type:: SchurCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

*TODO:* Reference to the distributed Hessenberg QR work of Granat, Kagstrom, Kressner, et al.

.. cpp:type:: HessQRCtrl

   .. cpp:member:: bool distAED

      Whether or not Aggressive Early Deflation should be attempted for
      distributed matrices (due to existing bugs in the ScaLAPACK 
      implementation, by default, no)

   .. cpp:member:: Int blockHeight
   .. cpp:member:: Int blockWidth

      The distribution block height and width for the Hessenberg QR algorithm

The primary reference for the current Spectral Divide and Conquer approachh is 
*Fast linear algebra is stable*, Demmel et al. While the current 
implementation requires multiple algorithmic improvements in order to achieve
stability, for example, better Mobius transformation selection, it often
succeeds on random matrices.

`SDC header file <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Schur/SDC.hpp>`__

.. cpp:type:: SDCCtrl<Real>

   .. cpp:member:: int cutoff
   .. cpp:member:: int maxInnerIts
   .. cpp:member:: int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

.. cpp:type:: SDCCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

Quasi-triangular manipulation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& U, Matrix<Complex<Base<F>>>& w )
.. cpp:function:: void schur::QuasiTriangEig( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Complex<Base<F>>>& w )

   Return the eigenvalues of the upper quasi-triangular matrix `U` in the vector
   `w`.

.. cpp:function:: Matrix<Complex<Base<F>>> schur::QuasiTriangEig( const Matrix<F>& U )
.. cpp:function:: DistMatrix<Complex<Base<F>>,VR,STAR> schur::QuasiTriangEig( const AbstractDistMatrix<F>& U )

   Return the eigenvalues of the upper quasi-triangular matrix `U`.

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& dMain, const Matrix<F>& dSub, const Matrix<F>& dSup, Matrix<Complex<Base<F>>>& w )

   The underlying computation routine for computing the eigenvalues of 
   quasi-triangular matrices. The vectors `dMain`, `dSub`, and `dSup` should
   respectively contain the main, sub, and super-diagonals of the 
   upper quasi-triangular matrix.

.. cpp:function:: void schur::RealToComplex( const Matrix<Real>& UQuasi, Matrix<Complex<Real>>& U )
.. cpp:function:: void schur::RealToComplex( const AbstractDistMatrix<Real>& UQuasi, AbstractDistMatrix<Complex<Real>>& U )

   Rotate a real upper quasi-triangular matrix into a complex upper triangular
   matrix.

.. cpp:function:: void schur::CheckRealSchur( const Matrix<Real>& U, bool standardForm=false )
.. cpp:function:: void schur::CheckRealSchur( const AbstractDistMatrix<Real>& U, bool standardForm=false )

   Check whether or not the largest diagonal blocks of the upper quasi-triangular
   matrix are at most :math:`2 \times 2` and, optionally, check if the 
   :math:`2 \times 2` diagonal blocks are in standard form 
   (if so, their diagonal must be constant and the product of the off-diagonal 
   entries should be negative).

Hermitian SVD
-------------
Given an eigenvalue decomposition of a Hermitian matrix :math:`A`, say

.. math::

   A = V \Lambda V^H,

where :math:`V` is unitary and :math:`\Lambda` is diagonal and real. 
Then an SVD of :math:`A` can easily be computed as

.. math::

   A = U |\Lambda| V^H,

where the columns of :math:`U` equal the columns of :math:`V`, modulo sign 
flips introduced by negative eigenvalues.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/SVD.cpp>`__

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& U, Matrix<F>& V )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& U, AbstractDistMatrix<F>& V )

   Return a vector of singular values, :math:`s`, and the left and right 
   singular vector matrices, :math:`U` and :math:`V`, such that 
   :math:`A=U \mathrm{diag}(s) V^H`.

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s )

   Return the singular values of :math:`A` in `s`. Note that the appropriate 
   triangle of `A` is overwritten during computation.

Polar decomposition
-------------------
Every matrix :math:`A` can be written as :math:`A=QP`, where :math:`Q` is 
unitary and :math:`P` is Hermitian and positive semi-definite. This is known as
the *polar decomposition* of :math:`A` and can be constructed as 
:math:`Q := U V^H` and :math:`P := V \Sigma V^H`, where 
:math:`A = U \Sigma V^H` is the SVD of :math:`A`. Alternatively, it can be 
computed through (a dynamically-weighted) Halley iteration.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Polar.cpp>`__

`SVD approach <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Polar/SVD.hpp>`__

`QWDH approach <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Polar/QDWH.hpp>`__

.. cpp:function:: void Polar( Matrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( AbstractDistMatrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( Matrix<F>& A, Matrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )

   Compute the polar decomposition of :math:`A`, :math:`A=QP`, returning 
   :math:`Q` within `A` and :math:`P` within `P`. The current implementation
   first computes the SVD.

.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, AbstractDistMatrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )

   Compute the polar decomposition through a Hermitian EVD. Since this is 
   equivalent to a Hermitian sign decomposition (if :math:`\text{sgn}(0)` is 
   set to 1), these routines are equivalent to `HermitianSign`.

Algorithmic options
^^^^^^^^^^^^^^^^^^^
By default, an SVD-based algorithm is used, but an approach based upon
a QR-based Dynamically Weighted Halley (QDWH) iteration can be manually chosen.

.. cpp:type:: PolarCtrl

   .. cpp:member:: bool qdwh

      Whether or not to use QDWH (the default is no)

   .. cpp:member:: bool colPiv

      Whether or not QDWH should use column pivoting in its QR factorizations
      (the default is no)

   .. cpp:member:: Int maxIts

      The maximum number of iterations of QDWH (the default is 20, but typically
      no more than 6 or 7 will be performed)

   .. cpp:member:: mutable Int numIts

      The number of iterations of QDWH performed in the last call

SVD
---
Given a general matrix :math:`A`, the *Singular Value Decomposition* is the 
triplet :math:`(U,\Sigma,V)` such that

.. math::

   A = U \Sigma V^H,

where :math:`U` and :math:`V` are unitary, and :math:`\Sigma` is diagonal with 
non-negative entries.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/SVD.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/spectral/SVD>`__

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

   Overwrites `A` with :math:`U`, `s` with the diagonal entries of :math:`\Sigma`, and `V` with :math:`V`. 

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s )

   Forms the singular values of :math:`A` in `s`. Note that `A` is overwritten in order to compute the singular values.

Algorithmic options
^^^^^^^^^^^^^^^^^^^

.. cpp:type:: SVDCtrl<Real>

   .. cpp:member:: bool seqQR

      Whether or not sequential implementations should use the QR algorithm
      instead of a Divide and Conquer when computing singular vectors.
      When only singular values are requested, a bidiagonal DQDS algorithms is 
      always run.

   .. cpp:member:: double valChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when only computing singular values.

   .. cpp:member:: double fullChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when computing a full SVD.

   .. cpp:member:: bool thresholded
 
      If the sufficiently small singular triplets should be thrown away.
      When thresholded, a cross-product algorithm is used. This is often
      advantageous since tridiagonal eigensolvers tend to have faster 
      parallel implementations than bidiagonal SVD's.

   .. cpp:member:: bool relative

      If the tolerance should be relative to the largest singular value.

   .. cpp:member:: Real tol

      The numerical tolerance for the thresholding. If this value is kept at
      zero, then a value is automatically chosen based upon the matrix.

   .. cpp:function:: SVDCtrl()

      Sets ``seqQR=false``, ``valChanRatio=1.2``, ``fullChanRatio=1.5``,
      ``thresholded=false``, ``relative=true``, and ``tol=0``.

.. cpp:type:: SVDCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

