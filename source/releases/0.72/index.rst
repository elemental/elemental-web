.. _release_0_72:

##########################
01/08/2012: Elemental 0.72
##########################

`elemental-0.72.tgz <http://libelemental.org/pub/releases/elemental-0.72.tgz>`__

Improvements
============
- Added Hermitian matrix square roots
- Added Cholesky for semi-definite matrices
- Added bidiagonalization for matrices where m >= n
- Switched to faster (and configurable) reduce-scatter approach
- Added checks for nonblocking collectives for later use
- Finished converting DistMatrix to template over the integer type

Bug fixes
=========
- Fixed clang++ compilation
- Added missing absolute value application in HermitianPseudoInverse
- Fixed typos in Hetrmm

Other changes
=============
- Avoided bug in xlC compiler related to DistMatrix integer templates
- Removed 'basic' and 'advanced' namespaces
- Removed WITHOUT_COMPLEX build option in order to simplify code
