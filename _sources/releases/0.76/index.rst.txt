.. _release_0_76:

##########################
08/06/2012: Elemental 0.76
##########################

`elemental-0.76.tgz <http://libelemental.org/pub/releases/elemental-0.76.tgz>`__

Improvements
============
- Added a PETSc-style Makefile include (elemvariables) to simplify the usage of the library
- Added a large number of links into the documentation
- Added a toolchain file for NERSC's HOPPER (and simplified the others)

Bug fixes
=========
- Fixed several mistakes in workspace sizes for calls to LAPACK's bidiagonal SVD
- Fixed several mistakes in the SVD routines
- Fixed a missing alignment free in Trdtrmm
- Restored support for MPI-1 by only using MPI_IN_PLACE when it is available
- Moved prototypes for BLAS and LAPACK functions out of header files to avoid conflicts with previous definitions
- Avoiding problems from the availability of OpenMP changing between configuration and compilation

Syntactic changes
=================
- Renamed the CMake options "BUILD_TESTS" and "BUILD_EXAMPLES" to "ELEM_TESTS" and "ELEM_EXAMPLES"
- Renamed "LUSolve" to "SolveAfterLU"
