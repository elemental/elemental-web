.. _release_0_62:

##########################
02/09/2011: Elemental 0.62
##########################

`elemental-0.62.tgz <http://libelemental.org/pub/releases/elemental-0.62.tgz>`__

Changes
=======
- Avoided OpenMP bug in some versions of IBM compilers
- DistMatrix class should now be safe in the OpenMP statements in HybridDebug mode
- Added another Hegst variant
- Exposed local blocksizes for local triangular updates as runtime tuning parameters
- Improved handling of MKL during configuration
