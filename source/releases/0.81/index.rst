.. _release_0_81:

##########################
07/24/2013: Elemental 0.81
##########################

`elemental-0.81.tgz <http://libelemental.org/pub/releases/elemental-0.81.tgz>`__

`documentation <http://libelemental.org/documentation/0.81/>`__

Features
========
- Matrix sign and square-root functions
- Reverse Cholesky and RQ factorizations
- Progress towards general-purpose spectral divide and conquer
- Lyapunov, Sylvester, and (algebraic) Ricatti solvers
- {Hermitian,Normal}FromEVD routines
- Greatly simplified packed Householder application, e.g., qr::ApplyQ
- "[o ,o ]", or "CIRC,CIRC" distribution for easily moving between sequential and distributed matrices
- MakeConsistent() allows non-owning processes to synchronize after the 
  distributed matrix state changed
- An instrumented Gemm example driver to benchmark Allgather and local Gemm performance
- Improved experimental F90 interface

Fixed Bugs
==========
- Avoiding accidental allocation when shrinking matrix with ResizeTo
- Fixed subtle bug when repeatedly calling routine such as QR(A,t)

Maintenance
===========
- Git SHA1 now stored in config file, and relevant version and build information
  can be printed with --version and --build command-line arguments
- Print and Write are now members of io/
- Modularized SWIG interface (Michael Grant)
- Extended set of view types so that local matrix manipulations are safer (Michael Grant)
- EnsurePMRRR() is now used so that stubs are always available
- std::bad_alloc's are now handled a bit more carefully
- Eliminated elem-dummy-lib, experimental-c, and experimental-f90 
- Greatly simplified exception handling
- Greatly simplified Householder transform usages
- FreeAlignments() is now almost-never needed
- Simplified MpiMap
- Include guards are now prefixed with "ELEM" in order to avoid collisions

Notes
=====
- The cmake/elemvariables Makefile include is still behind and is known to not yet work when Qt5 support is enabled (as well as in various other corner cases). There would be value in laying out precisely what development cycle is expected of Elemental users (e.g., if/how to install with CMake, what the easiest way to compile and link a new executable is). 

Thanks
======
- Wolfgang Bangerth for suggesting the MpiMap simplification
- Scott Rabidoux for mentioning several mistakes in the eigensolver documentation
