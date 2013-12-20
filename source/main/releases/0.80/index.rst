.. _release_0_80:

##########################
06/13/2013: Elemental 0.80
##########################

`elemental-0.80.tgz <http://libelemental.org/pub/releases/elemental-0.80.tgz>`__

Features
========
- Added (nearly-complete) Python support via SWIG
- Qt5 support for matrix visualization (Display and Spy)
- Switched from QR algorithm to DQDS for computing singular values of bidiagonal matrices
- Many more test matrices
- A preliminary toolchain file for Stampede
- Simplified exception handling via ReportException
- Version of Gemv which explicitly zeros the output

Fixed Bugs
==========
- Fixed major call-stack manipulation problem
- Fixed several bugs in test matrices
- Fixed syntax errors in ID and SkewHermitianEig
- Matrix (and DistMatrix) no longer allocate memory when shrinking a view
- Avoiding MPI_{Init,Query}_thread when they are not available

Maintenance
===========
- Shortened Grid constructors since grid width was redundant
- Simplified typical usage of SetDiagonal/MakeTrapezoidal/ScaleTrapezoid
- Defaulting to one thread for PMRRR
- Removed NullStreamBuffer since it conflicted with SWIG

Notes
=====
- The cmake/elemvariables Makefile include is a bit behind and is known to not yet work when Qt5 support is enabled (as well as in various other corner cases). There would be value in laying out precisely what development cycle is expected of Elemental users (e.g., if/how to install with CMake, what the easiest way to compile and link a new executable is). This should probably be in the form of a QuickStart guide, as suggested by Aron Ahmadia.

Thanks
======
- Michael Grant for spearheading the Python interface 
- Michael Grant for finding and fixing syntax errors in ID and SkewHermitianEig
- Nick Romero for finding and Matthias Petschow for proposing the solution to the PMRRR threading issue
- Nick Romero for reporting the MPI_{Init,Query}_thread issue and Jeff Hammond for proposing the solution
