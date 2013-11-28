.. _release_0_82_p1:

#############################
11/25/2013: Elemental 0.82-p1
#############################

`elemental-0.82-p1.tgz <http://libelemental.org/pub/releases/elemental-0.82-p1.tgz>`__

`documentation <http://libelemental.org/documentation/0.82-p1/>`__

.. note:: 

   In addition to fixing a bug with respect to the combination of _Pragma and
   OpenMP's collapse statement, this patch added several routines for 
   simplifying local entry manipulation. The other changes since 0.81 are 
   listed below.

New Functionality
=================

Fundamental additions
---------------------
- LU with full pivoting
- Various (blocked when possible) pivoted LDL factorizations
- Accurate symmetric/Hermitian inversion
- Hermitian inertia
- Blocked pivoted Cholesky factorization
- Two-norm estimation
- Preliminary Spectral Divide and Conquer algorithm for Schur decomposition
- Preliminary Spectral Divide and Conquer algorithm for Hermitian EVD
- Preliminary TSQR and TS-SVT implementations

Minor/incremental improvements
------------------------------
- Added Gaussian, Wigner, and Haar matrices
- Added UpdateDiagonal for adding a constant to the diagonal of a matrix
- Added move semantics for Matrix and DistMatrix
- Added QuasiDiagonal{Scale,Solve}
- Added SymmetricSwap
- Added support for relative thresholding in SVD and SVT
- Extended condition number support, see Condition
- Extended sorting to allow for ascending or descending, see Sort
- Axpy now supports arbitrary distributions
- All distributions now connected via operator=
- DistMatrix redesigned in terms of {Row,Col,Dist,Redundant,Cross}Comm's
- Higher-quality random number generation through std::mt19937 Mersenne twister

Maintenance
===========

Library bugfixes
----------------
- Avoiding implicit int -> MPI_Comm conversions in Grid constructors
- {Hermitian,Normal}UniformSpectrum now rotate diagonal matrix through a
  Haar similarity instead of a random Householder transformation
- Fixed mistake in matrix sign function
- Fixed mistake in unaligned AxpyTriangle

Instrumentation/visualization/testing
-------------------------------------
- Higher-quality timers via std::chrono

Maintenance/syntax
------------------
- Base<F> template alias
- elem::Complex is now a template alias for the improved std::complex
- Using _Pragma to simplify OpenMP directives
- Switched away from integer templates to typedefs, i.e., Int and Unsigned
- Added {Logic,Runtime}Error shortcuts for 'throw std::{logic,runtime}_error'
- Modified partially-pivoted LU and GaussianElimination to use ValueInt
- Removed obsolete TwoNorm{Lower,Upper}Bound
- Renamed 'Trtrsm' to 'Trstrm' (TRiangular Solve with TRiangular Matrix)
- Renamed 'SingularValueSoftThresholding' to 'SVT'
- Renamed 'Alignment' to 'Align' in most of the library
- Moved pivoting routines from lapack-like/ to blas-like/ folder
- Simplified ApplyPackedReflectors, HermitianEig, and Transpose implementations
- Simplified LDL and avoided modification of above-diagonal entries

Documentation
-------------
- Added README to almost every directory
- Greatly improved TODO list
- Moved Sphinx documentation to elemental-web repository

Build system
------------
- C++11 is now required
- Added support for Qt5 into elemvariables
- Fixed mistakes in compilation of sample code during configuration
- Directly testing for 'collapse' OpenMP directive to avoid Clang issue
- Improved toolchains for Vesta, and added GNU toolchain for Stampede

Python interface
----------------
- Functioning but not yet supporting all additions since 0.81

MPI and Threading
-----------------
- Added simplified MPI wrappers and prefixed versions which use tags with 'Tagged', e.g., 'TaggedSend'

Thanks
======
- Jed Brown for contributing a patch which removed several unused variables
- Michael Grant for updating the Python interface to handle integer typedef'ing
- Jeff Hammond for contributing toolchain file updates for Blue Gene/Q
