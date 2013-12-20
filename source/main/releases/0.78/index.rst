.. _release_0_78:

##########################
03/07/2013: Elemental 0.78
##########################

`elemental-0.78.tgz <http://libelemental.org/pub/releases/elemental-0.78.tgz>`__

Features
========
- Added Schatten, KyFan, and entrywise norms (and explicitly exposed each norm)
- Added Hadamard products
- Added Cholesky-based QR factorization for tall-skinny matrices
- Faster builds due to support for non-monolithic header inclusion

Bug fixes
=========
- Fixed bugs in Trtrmm and Trdtrmm which effected upper HPDInverse
- Fixed bugs in [MD,* ] and [* ,MD] alignment routines
- Fixed bug in [MC,MR] TransposeFrom member function
- Added check for MPI threading support when initializing Elemental in hybrid mode
- Fixed conjugation problem in sequential complex Hilbert-Schmidt inner product
- Fixed detection of MPI_Reduce_scatter_block

Miscellaneous
=============
- Removed unnecessary 'Local' prefix from many routines, e.g., LocalLength and LocalMatrix
- Separated LogBarrier and LogDetDivergence into folder for convex optimization
- No longer attempt to automatically detect MKL during configuration
- Simplified inclusion of Elemental as CMake subproject
- Pulled many member functions out of (and generally simplified) DistMatrix class
- Removed many redundancies with respect to symmetric and Hermitian implementations
- Greatly simplified Dot and Dotu implementations
- Detection for MPI_Comm_set_errhandler (replaces MPI_Errhandler_set in MPI3)
- Shortened code for MPI wrappers
- Many more toolchain files (and removed support for XL)

Open issues
===========
- Forcing PMRRR to avoid threading in Pure builds when launched in a multi-threaded environment
