Matrix decompositions
=====================

Hermitian eigensolver
---------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/HermitianEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianEig.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/HermitianEig.cpp>`__

Elemental provides a collection of routines for both full and partial 
solution of the Hermitian eigenvalue problem 

.. math::

   A Z = Z \Lambda,

where `A` is the given Hermitian matrix, and unitary `Z` and real diagonal 
:math:`\Lambda` are sought. In particular, with the eigenvalues and 
corresponding eigenpairs labeled in non-decreasing order, the three basic 
modes are:

1. Compute all eigenvalues or eigenpairs, :math:`\{\lambda_i\}_{i=0}^{n-1}` or 
   :math:`\{(z_i,\lambda_i)\}_{i=0}^{n-1}`.
2. Compute the eigenvalues or eigenpairs with a given range of indices, say  
   :math:`\{\lambda_i\}_{i=a}^b` or :math:`\{(z_i,\lambda_i)\}_{i=a}^b`, 
   with :math:`0 \le a \le b < n`.
3. Compute all eigenpairs (or just eigenvalues) with eigenvalues lying in a 
   particular half-open interval, either
   :math:`\{\lambda_i \;|\; \lambda_i \in (a,b] \}` or 
   :math:`\{ (z_i,\lambda_i) \;|\; \lambda_i \in (a,b] \}`.

As of now, all three approaches start with Householder tridiagonalization 
(ala :cpp:func:`HermitianTridiag`) and then call Matthias Petschow and 
Paolo Bientinesi's PMRRR for the tridiagonal eigenvalue problem.

.. note::

   Unfortunately, PMRRR currently only supports double-precision problems, and 
   so the parallel versions of these routines are limited to real and complex 
   double-precision matrices.

.. cpp:type:: HermitianEigCtrl<Real>

   .. cpp:member:: HermitianTridiagCtrl tridiagCtrl
   .. cpp:member:: HermitianSdcCtrl<Real> sdcCtrl
   .. cpp:member:: bool useSdc

   .. cpp:function:: HermitianEigCtrl()

      Initializes `tridiagCtrl` and `sdcCtrl` to their defaults and sets
      `useSdc` to false.

.. note::

   Please see the :ref:`lapack-tuning` section for extensive information on 
   maximizing the performance of Householder tridiagonalization.

Full spectrum computation
^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenvalues of the Hermitian matrix `A`.

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenpairs of the Hermitian matrix `A`.

Index-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues of a Hermitian matrix `A` with indices in the range 
   :math:`a,a+1,...,b`.

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs of a Hermitian matrix `A` with indices in the range 
   :math:`a,a+1,...,b`.

Range-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F,STAR,STAR>& A, DistMatrix<Base<F>,STAR,STAR>& w, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues of a Hermitian matrix `A` lying in the half-open 
   interval :math:`(a,b]`.

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F,STAR,STAR>& A, DistMatrix<Base<F>,STAR,STAR>& w, DistMatrix<F,STAR,STAR>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs of a Hermitian matrix `A` with eigenvalues lying in 
   the half-open interval :math:`(a,b]`.

Spectral divide and conquer
^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/HermitianEig/SDC.hpp>`__

The primary references for this approach is Demmel et al.'s *Fast linear algebra
is stable* and Nakatsukasa et al.'s *Stable and efficient spectral divide and conquer algorithms for the symmetric eigenvalue problem*.

.. cpp:type:: HermitianSdcCtrl<Real>

   .. cpp:member:: int cutoff
   .. cpp:member:: int maxInnerIts
   .. cpp:member:: int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

.. cpp:type:: HermitianSdcCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.


.. cpp:function:: void herm_eig::SDC( Matrix<F>& A, Matrix<Base<F>>& w, HermitianSdcCtrl<Base<F>> sdcCtrl=HermitianSdcCtrl<Base<F>>() )
.. cpp:function:: void herm_eig::SDC( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, HermitianSdcCtrl<Base<F>> sdcCtrl=HermitianSdcCtrl<Base<F>>() )

   Compute the eigenvalues of the matrix :math:`A` via a QDWH-based spectral 
   divide and conquer process. 

.. cpp:function:: void herm_eig::SDC( Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Q, HermitianSdcCtrl<Base<F>> sdcCtrl=HermitianSdcCtrl<Base<F>>() )
.. cpp:function:: void herm_eig::SDC( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Q, HermitianSdcCtrl<Base<F>> sdcCtrl=HermitianSdcCtrl<Base<F>>() )

   Attempt to also compute the eigenvectors.

Skew-Hermitian eigensolver
--------------------------
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

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/SkewHermitianEig.hpp>`__

Full spectrum computation
^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenvalues of the skew-Hermitian matrix `G`.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, Matrix<Complex<Base<F>> >& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, DistMatrix<Complex<Base<F>> >& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenpairs of the skew-Hermitian matrix `G`.

Index-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues of a skew-Hermitian matrix `G` with
   indices in the range :math:`a,a+1,...,b`.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, Matrix<Complex<Base<F>> >& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, DistMatrix<Complex<Base<F>> >& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs of a skew-Hermitian matrix `G` with 
   indices in the range :math:`a,a+1,...,b`.

Range-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues of a skew-Hermitian matrix `G` 
   lying in the half-open interval :math:`(a,b]i`.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& wImag, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, DistMatrix<F>& G, DistMatrix<Base<F>,VR,STAR>& wImag, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs of a skew-Hermitian matrix `G` with 
   eigenvalues lying in the half-open interval :math:`(a,b]i`.

Hermitian generalized-definite eigensolvers
-------------------------------------------
The following Hermitian generalized-definite eigenvalue problems frequently 
appear, where both :math:`A` and :math:`B` are Hermitian, and :math:`B` is 
additionally positive-definite:

.. math::

   ABx = \lambda x,

which is denoted with the value ``ABX`` via the 
:cpp:type:`HermitianGenDefiniteEigType` enum,

.. math::

   BAx = \lambda x,

which uses the ``BAX`` value, and finally

.. math::

   Ax = \lambda B x,

which uses the ``AXBX`` enum value.

.. cpp:type:: HermitianGenDefiniteEigType

   An enum for specifying either the ``ABX``, ``BAX``, or ``AXBX`` 
   generalized eigenvalue problems (described above).

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/HermitianGenDefiniteEig.hpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianGenDefiniteEig.cpp>`__

Full spectrum computation
^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenvalues of a generalized EVP involving the 
   Hermitian matrices `A` and `B`, where `B` is also positive-definite.

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<Base<F>>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<Base<F>>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the full set of eigenpairs of a generalized EVP involving the 
   Hermitian matrices `A` and `B`, where `B` is also positive-definite.

Index-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, int a, int b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues with indices in the range :math:`a,a+1,...,b` of a 
   generalized EVP involving the Hermitian matrices `A` and `B`, where `B` is 
   also positive-definite.

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs with indices in the range :math:`a,a+1,...,b` of a 
   generalized EVP involving the Hermitian matrices `A` and `B`, where `B` is 
   also positive-definite.

Range-based subset computation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, Base<F> a, Base<F> b, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenvalues lying in the half-open interval :math:`(a,b]` of a 
   generalized EVP involving the Hermitian matrices `A` and `B`, where `B` is 
   also positive-definite.

.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefiniteEig( HermitianGenDefiniteEigType type, UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<Base<F>,VR,STAR>& w, DistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the eigenpairs whose eigenvalues lie in the half-open interval 
   :math:`(a,b]` of a generalized EVP involving the Hermitian matrices `A` and 
   `B`, where `B` is also positive-definite.

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

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Schur.hpp>`__

.. cpp:function:: void Schur( Matrix<F>& A )
.. cpp:function:: void Schur( DistMatrix<F>& A )
.. cpp:function:: void Schur( Matrix<F>& A, Matrix<F>& Q )
.. cpp:function:: void Schur( DistMatrix<F>& A, DistMatrix<F>& Q )

Hessenberg QR algorithm
^^^^^^^^^^^^^^^^^^^^^^^

`QR algorithm header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Schur/QR.hpp>`__

.. cpp:function:: void schur::QR( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, bool fullTriangle=false )
.. cpp:function:: void schur::QR( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, Matrix<F>& Q, bool fullTriangle=true )

   Condense the matrix to upper-Hessenberg form and then use a sequential QR 
   algorithm to compute a (partial) Schur decomposition. 
   It is optional whether or not the full Schur factor is computed.

.. cpp:function:: void schur::QR( DistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, bool fullTriangle=false, bool aed=false )
.. cpp:function:: void schur::QR( BlockDistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, bool fullTriangle=false, bool aed=false )
.. cpp:function:: void schur::QR( DistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, DistMatrix<F>& Q, bool fullTriangle=true, bool aed=false )
.. cpp:function:: void schur::QR( BlockDistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, BlockDistMatrix<F>& Q, bool fullTriangle=true, bool aed=false )

   Condense the matrix to upper-Hessenberg form and then use ScaLAPACK's 
   parallel QR algorithm to compute a (partial) Schur decomposition.
   It is optional whether or not the full Schur factor is computed, and 
   Aggressive Early Deflation is also optional for real matrices (as of now,
   its usage is not recommended due to known bugs in the implementation).

Quasi-triangular manipulation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& U, Matrix<Complex<Base<F>>>& w )
.. cpp:function:: void schur::QuasiTriangEig( const DistMatrix<F>& U, DistMatrix<Complex<Base<F>>,colDist,rowDist>& w )

   Return the eigenvalues of the upper quasi-triangular matrix `U` in the vector
   `w`.

.. cpp:function:: Matrix<Complex<Base<F>>> schur::QuasiTriangEig( const Matrix<F>& U )
.. cpp:function:: DistMatrix<Complex<Base<F>>,VR,STAR> schur::QuasiTriangEig( const DistMatrix<F>& U )

   Return the eigenvalues of the upper quasi-triangular matrix `U`.

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& dMain, const Matrix<F>& dSub, const Matrix<F>& dSup, Matrix<Complex<Base<F>>>& w )

   The underlying computation routine for computing the eigenvalues of 
   quasi-triangular matrices. The vectors `dMain`, `dSub`, and `dSup` should
   respectively contain the main, sub, and super-diagonals of the 
   upper quasi-triangular matrix.

.. cpp:function:: void schur::RealToComplex( const Matrix<Real>& UQuasi, Matrix<Complex<Real>>& U )
.. cpp:function:: void schur::RealToComplex( const DistMatrix<Real>& UQuasi, DistMatrix<Complex<Real>>& U )

   Rotate a real upper quasi-triangular matrix into a complex upper triangular
   matrix.

.. cpp:function:: void schur::CheckRealSchur( const Matrix<Real>& U, bool standardForm=false )
.. cpp:function:: void schur::CheckRealSchur( const DistMatrix<Real>& U, bool standardForm=false )

   Check whether or not the largest diagonal blocks of the upper quasi-triangular
   matrix are at most :math:`2 \times 2` and, optionally, check if the 
   :math:`2 \times 2` diagonal blocks are in standard form 
   (if so, their diagonal must be constant and the product of the off-diagonal 
   entries should be negative).

Spectral divide and conquer
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The primary reference for this approach is Demmel et al.'s *Fast linear algebra
is stable*. While the current implementation needs a large number of algorithmic
improvements, especially with respect to choosing the Mobius transformations,
it tends to succeed on random matrices.

`SDC header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Schur/SDC.hpp>`__

.. cpp:type:: SdcCtrl<Real>

   .. cpp:member:: int cutoff
   .. cpp:member:: int maxInnerIts
   .. cpp:member:: int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

.. cpp:type:: SdcCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

.. cpp:function:: void schur::SDC( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, bool formATR=false, SdcCtrl<Base<F>> sdcCtrl=SdcCtrl<Base<F>>() )
.. cpp:function:: void schur::SDC( DistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, bool formATR=false, SdcCtrl<Base<F>> sdcCtrl=SdcCtrl<Base<F>>() )

   Compute the eigenvalues of the matrix :math:`A` via a spectral divide and
   conquer process. On exit, the eigenvalues of :math:`A` will be stored on its
   diagonal, and, if ``formATR`` was set to true, the upper triangle of 
   :math:`A` will be its corresponding upper-triangular Schur factor.

.. cpp:function:: void schur::SDC( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, Matrix<F>& Q, bool formATR=true, SdcCtrl<Base<F>> sdcCtrl=SdcCtrl<Base<F>>() )
.. cpp:function:: void schur::SDC( DistMatrix<F>& A, DistMatrix<Complex<Base<F>>,VR,STAR>& w, DistMatrix<F>& Q, bool formATR=true, SdcCtrl<Base<F>> sdcCtrl=SdcCtrl<Base<F>>() )

   Attempt to also compute the Schur vectors.

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

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/SVD.hpp>`__

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& U, Matrix<F>& V )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, DistMatrix<F>& U, DistMatrix<F>& V )

   Return a vector of singular values, :math:`s`, and the left and right 
   singular vector matrices, :math:`U` and :math:`V`, such that 
   :math:`A=U \mathrm{diag}(s) V^H`.

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s )

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

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Polar.hpp>`__

`SVD approach <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Polar/SVD.hpp>`__

`QWDH approach <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/Polar/QDWH.hpp>`__

.. cpp:function:: void Polar( Matrix<F>& A )
.. cpp:function:: void Polar( DistMatrix<F>& A )
.. cpp:function:: void Polar( Matrix<F>& A, Matrix<F>& P )
.. cpp:function:: void Polar( DistMatrix<F>& A, DistMatrix<F>& P )

   Compute the polar decomposition of :math:`A`, :math:`A=QP`, returning 
   :math:`Q` within `A` and :math:`P` within `P`. The current implementation
   first computes the SVD.

.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, DistMatrix<F>& A )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& P )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& P )

   Compute the polar decomposition through a Hermitian EVD. Since this is 
   equivalent to a Hermitian sign decomposition (if :math:`\text{sgn}(0)` is 
   set to 1), these routines are equivalent to `HermitianSign`.

polar namespace
^^^^^^^^^^^^^^^

.. cpp:function:: int polar::QDWH( Matrix<F>& A, bool colPiv=false, int maxits=20 )
.. cpp:function:: int polar::QDWH( DistMatrix<F>& A, bool colPiv=false, int maxIts=20 )
.. cpp:function:: int hermitian_polar::QDWH( UpperOrLower uplo, Matrix<F>& A, bool colPiv=false, int maxits=20 )
.. cpp:function:: int hermitian_polar::QDWH( UpperOrLower uplo, DistMatrix<F>& A, bool colPiv=false, int maxIts=20 )

   Overwrites :math:`A` with the :math:`Q` from the polar decomposition using 
   a QR-based dynamically weighted Halley iteration. The number of iterations
   used is returned upon completion.
   **TODO: reference to Yuji's paper**

.. cpp:function:: int polar::QDWH( Matrix<F>& A, Matrix<F>& P, bool colPiv=false, int maxits=20 )
.. cpp:function:: int polar::QDWH( DistMatrix<F>& A, DistMatrix<F>& P, bool colPiv=false, int maxIts=20 )
.. cpp:function:: int hermitian_polar::QDWH( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& P, bool colPiv=false, int maxits=20 )
.. cpp:function:: int hermitian_polar::QDWH( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F>& P, bool colPiv=false, int maxIts=20 )

   Return the full polar decomposition, where :math:`P` is HPD.

SVD
---
Given a general matrix :math:`A`, the *Singular Value Decomposition* is the 
triplet :math:`(U,\Sigma,V)` such that

.. math::

   A = U \Sigma V^H,

where :math:`U` and :math:`V` are unitary, and :math:`\Sigma` is diagonal with 
non-negative entries.

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/decomp/SVD.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/decomp/SVD>`__

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V )

.. cpp:function:: void SVD( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, DistMatrix<F>& V )

   Overwrites `A` with :math:`U`, `s` with the diagonal entries of :math:`\Sigma`, and `V` with :math:`V`. 

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s )

.. cpp:function:: void SVD( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s )

   Forms the singular values of :math:`A` in `s`. Note that `A` is overwritten in order to compute the singular values.


svd namespace
^^^^^^^^^^^^^

.. cpp:function:: void svd::QRSVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V )

   SVD which uses bidiagonal QR algorithm.

.. cpp:function:: void svd::DivideAndConquerSVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V )

   SVD which uses a bidiagonal divide-and-conquer algorithm.

.. cpp:function:: void svd::Chan( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, double heightRatio=1.2 )
.. cpp:function:: void svd::Chan( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, DistMatrix<F>& V, double heightRatio=1.5 )

   SVD which preprocesses with an initial QR decomposition if the matrix is 
   sufficiently tall relative to its width.

.. cpp:function:: void svd::GolubReinschUpper( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s )
.. cpp:function:: void svd::GolubReinschUpper( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, DistMatrix<F>& V )

   Computes the singular values (and vectors) of a matrix which is taller than
   it is wide using the Golub-Reinsch algorithm, though DQDS is used when only
   the singular values are sought.

.. cpp:function:: void svd::Thresholded( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V, Base<F> tol=0, bool relative=false )
.. cpp:function:: void svd::Thresholded( DistMatrix<F>& A, DistMatrix<Base<F>,VR,STAR>& s, DistMatrix<F>& V, Base<F> tol=0, bool relative=false )

   Computes the singular triplets whose singular values are larger than a 
   specified tolerance using the cross-product algorithm. This is often 
   advantageous because tridiagonal eigensolvers tend to enjoy better parallel
   implementations than bidiagonal SVD's.
