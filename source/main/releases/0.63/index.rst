.. _release_0_63:

##########################
02/24/2011: Elemental 0.63
##########################

`elemental-0.63.tgz <http://libelemental.org/pub/releases/elemental-0.63.tgz>`__

Changes
=======
- Added Martin Schatz's Axpy interface for easily filling distributed matrices
- Removed all direct MPI usage in favor of using Elemental-specified wrappers. This should ease future ports to exotic architectures.
- Renamed elemental::blas and elemental::lapack to elemental::basic and elemental::advanced to avoid improperly using the BLAS/LAPACK names.
- Fixed a recently introduced bug in a [VC,* ] <- [MC,* ] SumScatter routine that was causing UT transforms applied from the right to give wrong results (and therefore causing the tridiagonalization driver to claim the answers were wrong).
