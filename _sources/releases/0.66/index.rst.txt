.. _release_0_66:

##########################
05/07/2011: Elemental 0.66
##########################

`elemental-0.66.tgz <http://libelemental.org/pub/releases/elemental-0.66.tgz>`__

Changes
=======
- Replaced invalid usages of MPI_Group_incl/MPI_Comm_create with MPI_Comm_split
- Removed a needless requirement that m >= n in the QR driver.
- Fixed a build system corner case where MKL was incorrectly being detected as sufficient for non-threaded PMRRR.
