.. _release_0_73:

##########################
02/21/2012: Elemental 0.73
##########################

`elemental-0.73.tgz <http://libelemental.org/pub/releases/elemental-0.73.tgz>`__

Improvements
============
- Stable parallel matrix norm computation
- Documentation for SkewHermitianEig and HermitianGenDefiniteEig
- Added ColStride() and RowStride() to DistMatrix class
- Added more 'basic' member functions to the Grid class
- There is again an experimental C and F90 interface for a few routines

Bug fixes
=========
- Avoiding std::complex fixed a compilation issue with Darwin-g++
- Fixed mistakes in SymmetricNorm

Other changes
=============
- The 'elemental' namespace has been shortened to 'elem'
- std::complex has now been eliminated in favor of a custom Complex class due to various problems with its definition in the C++ standard
