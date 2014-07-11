.. _release_0_84:

##########################
06/04/2014: Elemental 0.84
##########################

`Elemental-0.84-p1.tgz <http://libelemental.org/pub/releases/Elemental-0.84-p1.tgz>`__ (patch applied on 06/13/2014)

Documentation: `[HTML] <http://libelemental.org/documentation/0.84/>`__ `[PDF] <http://libelemental.org/documentation/elem-0.84.pdf>`__ 

The significant changes since release 0.83 are listed below.

New Functionality
=================

Fundamental additions
---------------------
- Low-rank Cholesky up-/down-dating (CholMod)
- Rank-one updates to LU factorizations (LUMod)
- Added Generalized RQ and QR factorizations and associated General Linear Model (GLM) and Equality-constrained Least Squares (LSE) solvers
- Pseudospectral computations can now be driven by various kernels, including 
  multi-shift Hessenberg/(quasi-)triangular solves. There is also now support a 
  variety of configurations for outputting snapshots of the results
- Multi-shift Hessenberg solves (MultiShiftHessSolve)
- Multi-shift quasi-triangular solves (MultiShiftQuasiTrsm)
- Quasi-triangular solves (QuasiTrsv/QuasiTrsm)
- Hyperbolic Householder transforms
- Basic support for a block version of DistMatrix (BlockDistMatrix)
- Support for parallel Schur decompositions via ScaLAPACK's Hessenberg QR algs.
- Support for redistributing between DistMatrix and BlockDistMatrix [MC,MR] dists.
- All user-level routines now use permutation vectors instead of pivot vectors
- Alternating Direction Method of Multipliers (ADMM) implementations of Basis Pursuit, Linear and Quadratic Programs, and Sparse Inverse Covariance Selection

Minor/incremental improvements
------------------------------
- Added {lq,rq,qr}::SolveAfter
- Added SymmetricSolve and HermitianSolve
- Support for converting real (quasi-triangular) Schur forms to complex 
  (triangular) form 
- Support for computing the eigenvalues of quasi-triangular matrices
- LQ/QR/RQ factorizations now force positive (or zero) diagonal entries in the 
  resulting triangular matrix
- Grid now supports both row-major and column-major orderings
- Support for diagonal scalings of trapezoidal matrices (DiagonalScaleTrapezoid)
- Added Global{Col,Row} and Local{Col,Row}Offset member functions to DistMatrix
- Norm and Max now support more data distributions
- Min and Max implementations (which do not use the absolute values)
- Added Bull's Head, Hatano-Nelson, random Helmholtz Green's, Trefethen, 
  Triangle, and Whale matrices.

Instrumentation/visualization/testing
-------------------------------------
- More file formats for Read and Write (e.g., ASCII and MATRIX_MARKET)
- Display windows are now strictly sized according to the size of the matrix

Maintenance
===========

Library bugfixes
----------------
- Fixed several small memory leaks in Grid
- AbstractDistMatrix::Empty() now recomputes shifts to ensure the matrix is kept
  in a legal state
- Moves of non-views to views are now converted to copies
- Fixed deflation bug in PMRRR when no eigenvectors are requested
- Fixed bugs in ApplyPackedReflectors, QuasiDiagonalScale, TriangularInverse, Trr, and Trsv

Maintenance/syntax
------------------
- Algorithmic options are now handled via control structures with default 
  constructors
- Preprocessor definitions and macros now namespaced with "ELEM"
- Grid argument to DistMatrix::[Locked]Attach was moved before the dependent 
  alignment arguments
- Added a 'Mod' routine which supports modular arithmetic with negative integers
- Copy assignments now return non-const references
- Move constructors are now "noexcept"
- Checks were added to ensure DistMatrix views are not improperly aligned
- PMRRR (and therefore Elemental) no longer requires a Fortran compiler to build
- Renamed "ShiftedTrsm" to "MultiShiftTrsm" and placed in BLAS3
- Renamed "Min" and "Max" to "MinAbs" and "MaxAbs"
- Renamed "Inertia" to "InertiaType" and "HermitianInertia" to "Inertia"
- The unnecessary Orientation arguments were removed from QuasiDiagonal{Scale,Solve}
- All interfaces now assume the usage of 'left' diagonals, which use an offset relative to the diagonal which contains the upper-left entry

Documentation
-------------
- Documentation for BlockDistMatrix is currently missing

Build system
------------
- Several bugs fixed in detection of support for C++11 random number generation
- Configuration tests moved into separate files

Python interface
----------------
- The python interface was removed due to SWIG's lack of C++11 support,
  the lack of a maintainer for the interface, and the fact that a manual 
  C interface is planned.

Thanks
======
- Jed Brown for suggesting the preprocessor namespacing
- Drew Lewis for reporting the TriangularInverse bug
