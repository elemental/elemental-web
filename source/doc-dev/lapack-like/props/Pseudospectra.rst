Pseudospectra
-------------

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack-like/props/Pseudospectra.cpp>`__

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

Automatic window
^^^^^^^^^^^^^^^^
The following routines return the norms of the shifted inverses over an 
automatically-determined 2D window in the complex plane 
(in the matrix ``invNormMap``) with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralAutoWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElPseudospectralAutoWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Manual window
^^^^^^^^^^^^^
The following routines return the norms of the shifted inverses over the 
specified 2D window in the complex plane (in the matrix ``invNormMap``) with 
the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElPseudospectralWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Point cloud
^^^^^^^^^^^
The following routines return the norms of the shifted inverses in the vector 
``invNorms`` for a given set of shifts. The returned integer vector is a list 
of the number of iterations required for convergence of each shift.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> Pseudospectra( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> TriangularPseudospectra( const AbstractDistMatrix<F>& U, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& invNorms, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralCloud_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloud_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloud_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloud_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElPseudospectralCloudX_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudX_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudX_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudX_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

Control structures
^^^^^^^^^^^^^^^^^^

C++ API
"""""""

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
"""""

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

