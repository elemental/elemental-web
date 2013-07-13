.. _release_0_67:

##########################
06/29/2011: Elemental 0.67
##########################

`elemental-0.67.tgz <http://libelemental.org/pub/releases/elemental-0.67.tgz>`__

Changes
=======
- Added an implementation of a parallel LCG algorithm that provably provides each process with independent samples
- Modified LAPACK calls to throw an error when info != 0, even in RELEASE mode
- Added a routine for generating random (implicitly) Hermitian matrices instead of just random HPD matrices
- Added a fix for a BG/P MPI_Allgather performance bug
