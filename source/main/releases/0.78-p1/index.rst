.. _release_0_78_p1:

#############################
03/27/2013: Elemental 0.78-p1
#############################

`elemental-0.78-p1.tgz <http://libelemental.org/pub/releases/elemental-0.78-p1.tgz>`__

Features
========
- Revamped experimental C and F90 interfaces
- Added an early prototype of a Python interface (must be manually built)
- Added zero-norm computation (number of nonzero entries)
- Added entrywise and (unoptimized) singular-value soft-thresholding
- Added (unoptimized) Robust PCA example

Bug fixes
=========
- Fixed mistake in Grid( MPI_Comm comm ) constructor which would have greatly effected performance
- Fixed typo in CMakeLists.txt which prevented specification of MPI_Allreduce+memcpy based MPI_Reduce_scatter
- Fixed detection of MPI_IN_PLACE
- Fixed mistake in Matrix documentation

Maintenance
===========
- Renamed LockedView() member function in Matrix and DistMatrix classes to Locked() to avoid confusion with LockedView function
