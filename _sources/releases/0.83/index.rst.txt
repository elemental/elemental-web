.. _release_0_83:

##########################
02/20/2014: Elemental 0.83
##########################

`elemental-0.83.tgz <http://libelemental.org/pub/releases/elemental-0.83.tgz>`__

Documentation: `[HTML] <http://libelemental.org/documentation/0.83/>`__ `[PDF] <http://libelemental.org/documentation/elem-0.83.pdf>`__ 

New Functionality
=================

Fundamental additions
---------------------
- Preliminary routines for the high-performance computation of pseudospectra
- Distributed blocked reductions to lower/upper bidiagonal/Hessenberg form
  are now both fully supported
- Large redesign of the Matrix and DistMatrix classes which includes support
  for arbitrary submatrix manipulation

Minor/incremental improvements
------------------------------

- More performant and robust SDC via: try/catch guards around the matrix-sign 
  functions, avoidance of unnatural process team splits, the introduction of 
  many more accuracy and convergence tuning parameters, and the ability to 
  optionally print status updates
- Support was added for pivot metadata caching 
  (this will eventually have a large effect on the performance of Clique)
- Row and column pivot applications now support every matrix distribution
- The QuasiDiagonal{Scale,Solve} routines were greatly extended
- AlignWith no longer has an effect when the alignments are unchanged
- Added Demmel, Fox-Li, and Helmholtz PML matrices
- HermitianTridiagEig is now a routine

Instrumentation/visualization/testing
-------------------------------------
- Added support for BMP/JPG/PNG/etc. visualization via Qt5
- Colormaps can now be modified at runtime
- The ``-no-gui`` option is now supported so that Qt5 can be used to write 
  images to file even when no display server is running
- Preliminary support for reading/writing matrices to/from file

Maintenance
===========

Library bugfixes
----------------
- Fixed bugs in SymmetricInverse, QuasiDiagonal{Scale,Solve}, and
  HermitianInertia 
- Fixed bug in Pseudoinverse scaling (also affected Skeleton)
- Fixed edgecases in TwoNormEstimate 
- Fixed a bug in parallel one-norm computation
- Fixed bugs in Matrix::Conjugate and several diagonal alignments
- Fixed parallel Helmholtz matrix generation
- Avoided assumption that VCComm members have the same rank in the owning group
- Fixed bugs in {[VR,STAR],[STAR,VR]} <- [CIRC,CIRC] and [STAR,MR] <- [MC,MR]
  redistributions
- Fixed a bug in the Trmm driver (noticed by Hal Finkel)

Maintenance/syntax
------------------
- "ResizeTo" was shortened to "Resize"
- A ``DEBUG_ONLY`` macro was added to replace ``#ifndef RELEASE`` guards
- Variadic versions of {Logic,Runtime}Error were added
- The computation of Householder reflectors was greatly simplified and the 
  library now further breaks with LAPACK convention for complex reflectors so
  that zeros are introduced with (I-tau v v') rather than (I-conj(tau) v v')
- Matrix view-types have been simplified

Documentation
-------------
- The DistMatrix class finally now has fairly complete documentation
- The ``lapack-like/`` folder's new organization is now reflected in the
  documentation
- The REFERENCES file is now in bibtex form

Build system
------------
- Support for Intel compilers (>= 14.0.1) has been re-enabled
- C++11 compiler flags are now automatically detected for most compilers
- The configuration test for ``MPI_Comm_f2c`` was fixed
- Drivers are now recompiled (rather than just relinked) when headers change
- Vagrant files were added for Ubuntu 13.10 (Saucy)
- Multiple toolchain files were added

Python interface
----------------
- Several more routines were added (e.g., from the qr namespace)

MPI and Threading
-----------------
- Avoiding complex MPI by default due to two students running into problems
  with OpenMPI's support for complex MPI_SUM

Thanks
======
- Hal Finkel for reporting a mistake in a Trmm driver
- Jed Brown and Satish Balay for reporting several instances of unused 
  variables/typedefs
