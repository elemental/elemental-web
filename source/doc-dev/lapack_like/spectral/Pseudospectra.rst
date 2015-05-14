Pseudospectra
=============

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

Spectral portrait
-----------------
The following routines return the norms of the shifted inverses over an 
*automatically-determined* 2D window in the complex plane 
(in the matrix ``invNormMap``) with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

Python API
^^^^^^^^^^

.. py:function:: SpectralPortrait(A[,realSize=100,imagSize=100,ctrl=None])

C++ API
^^^^^^^

.. cpp:function:: Matrix<int> SpectralPortrait( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> SpectralPortrait( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralPortrait( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularSpectralPortrait( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularSpectralPortrait( const Matrix<Real>& U, Matrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularSpectralPortrait( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralPortrait( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergSpectralPortrait( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElSpectralPortrait_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElSpectralPortrait_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralPortrait_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralPortrait_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Spectral window
---------------
The following routines return the norms of the shifted inverses over a
*user-specified* 2D window in the complex plane (in the matrix ``invNormMap``) 
with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

Python API
^^^^^^^^^^

.. py:function:: SpectralWindow(A[,center=0,realWidth=1,imagWidth=1,realSize=100,imagSize=100,ctrl=None])

C++ API
^^^^^^^

.. cpp:function:: Matrix<int> SpectralWindow( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> SpectralWindow( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralWindow( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularSpectralWindow( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularSpectralWindow( const Matrix<Real>& U, Matrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularSpectralWindow( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralWindow( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergSpectralWindow( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElSpectralWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElSpectralWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Spectral cloud
--------------
The following routines return the norms of the shifted inverses in the vector 
``invNorms`` for a given set of shifts. The returned integer vector is a list 
of the number of iterations required for convergence of each shift.

Python API
^^^^^^^^^^

.. py:function:: SpectralCloud(A,shifts[,ctrl=None])

C++ API
^^^^^^^

.. cpp:function:: Matrix<int> SpectralCloud( const Matrix<F>& A, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> SpectralCloud( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralCloud( const Matrix<F>& U, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> TriangularSpectralCloud( const AbstractDistMatrix<F>& U, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> QuasiTriangularSpectralCloud( const AbstractDistMatrix<Real>& U, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& invNorms, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralCloud( const Matrix<F>& H, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> HessenbergSpectralCloud( const AbstractDistMatrix<F>& H, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElSpectralCloud_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElSpectralCloudDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )

.. c:function:: ElError ElSpectralCloudX_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralCloudXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElSpectralCloud_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElSpectralCloudDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElSpectralCloudX_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralCloudXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralCloud_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElSpectralCloudDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )

.. c:function:: ElError ElSpectralCloudX_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralCloudXDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElSpectralCloud_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElSpectralCloudDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElSpectralCloudX_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralCloudXDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

Control structures
------------------

Python API
^^^^^^^^^^

**TODO**

C++ API
^^^^^^^

.. cpp:type:: SnapshotCtrl

   .. cpp:member:: Int realSize
   .. cpp:member:: Int imagSize

   .. cpp:member:: Int imgSaveFreq
   .. cpp:member:: Int numSaveFreq
   .. cpp:member:: Int imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. cpp:member:: Int imgSaveCount
   .. cpp:member:: Int numSaveCount
   .. cpp:member:: Int imgDispCount

   .. cpp:member:: std::string imgBase
   .. cpp:member:: std::string numBase

   .. cpp:member:: FileFormat imgFormat
   .. cpp:member:: FileFormat numFormat

   .. cpp:function::  SnapshotCtrl()

      All counters and dimensions are initially zero, all save/display 
      "frequencies" are set to -1 (no output), the basename strings are 
      initialized to "ps", the image format to ``PNG``, and the numerical 
      format to ``ASCII_MATLAB``.

   .. cpp:function:: void ResetCounts()

      Resets all counters to zero

   .. cpp:function:: void Iterate()

      Increments all counters by one

.. cpp:type:: PseudospecCtrl<Real>

   .. cpp:member::bool schur

   .. cpp:member:: bool forceComplexSchur

   .. cpp:member:: bool forceComplexPs

   .. cpp:member:: SchurCtrl<Real> schurCtrl

   .. cpp:member:: Int maxIts

   .. cpp:member:: Real tol

   .. cpp:member:: bool deflate

   .. cpp:member:: bool arnoldi

   .. cpp:member:: Int basisSize

   .. cpp:member:: bool reorthog

   .. cpp:member:: bool progress

   .. cpp:member:: SnapshotCtrl snapCtrl

.. cpp:type:: PseudospecCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
^^^^^

.. c:type:: ElSnapshotCtrl

   .. c:member:: ElInt realSize
   .. c:member:: ElInt imagSize

   .. c:member:: ElInt imgSaveFreq
   .. c:member:: ElInt numSaveFreq
   .. c:member:: ElInt imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. c:member:: ElInt imgSaveCount
   .. c:member:: ElInt numSaveCount
   .. c:member:: ElInt imgDispCount

   .. c:member:: const char* imgBase
   .. c:member:: const char* numBase

   .. c:member:: ElFileFormat imgFormat
   .. c:member:: ElFileFormat numFormat

.. c:function:: ElError ElSnapshotCtrlDefault( ElSnapshotCtrl* ctrl )
.. c:function:: ElError ElSnapshotCtrlDestroy( ElSnapshotCtrl* ctrl )

.. c:type:: ElPseudospecCtrl_s

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: float tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:type:: ElPseudospecCtrl_d

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: double tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:function:: ElError ElPseudospecCtrlDefault_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDefault_d( ElPseudospecCtrl_d* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_d( ElPseudospecCtrl_d* ctrl )

References
----------
`C++ implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/spectral/Pseudospectra.cpp>`__

`C++ pseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/Pseudospectra.cpp>`__

`C++ ChunkedPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/ChunkedPseudospectra.cpp>`__

`C++ TriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/TriangularPseudospectra.cpp>`__

`C++ ChunkedTriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/ChunkedTriangularPseudospectra.cpp>`__
