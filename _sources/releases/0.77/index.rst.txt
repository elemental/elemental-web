.. _release_0_77:

##########################
12/14/2012: Elemental 0.77
##########################

`elemental-0.77.tgz <http://libelemental.org/pub/releases/elemental-0.77.tgz>`__

Features
========
- Nuclear norm, two-norm, and condition number routines
- Hilbert-Schmidt inner products
- Log barrier and log-det divergence routines for HPD matrices
- More special matrices (e.g., Jacobi matrices for Legendre polynomials)
- Several improved algorithms for Trmm and Trsm (thanks to Bryan Marker)
- Greatly lowered communication in Trsv
- Hegst has been split into TwoSidedTrmm/TwoSidedTrsm and extended to handle more general triangular matrices
- Trtrsm partially implemented (triangular solve against triangular matrix)
- Better command-line argument processing (via Choice)
- There are now Blue Gene/Q toolchain files (thanks to Jeff Hammond)
- 'elemvariables' Makefile include is now more robust

Bug fixes
=========
- Fixed mishandling of input buffers for PMRRR (the interface cannot be const since the buffers are modified)
- Avoided bug in HybridDebug mode caused by modifying the call stack from within an OpenMP loop (originally pointed out by Miles Lubin)

Miscellaneous
=============
- Driver for HermitianEig now allows for testing clustered eigenvalues
- Removed GFlops utility drivers since they were better left to the drivers
- New BSD License is now pointed to instead of listed in every file
- Restructuring of implementations within header files

Open issues
===========
- Forcing PMRRR to avoid threading in Pure builds when launched in a multi-threaded environment
