.. _release_0_71:

##########################
11/27/2011: Elemental 0.71
##########################

`elemental-0.71.tgz <http://libelemental.org/pub/releases/elemental-0.71.tgz>`__

Improvements
============
- More work on the documentation
- Added a routine for computing the determinant of a general matrix, 
  advanced::Determinant, and a version which returns a higher precision 
  result, advanced::SafeDeterminant
- Added a routine for computing the matrix trace, advanced::Trace
- Added an O(n) algorithm for composing pivots for an entire matrix
- Added a lower triangular version of advanced::HPDInverse
- Added a version of advanced::SortEig for sorting just eigenvalues
- Added a few routines to Grid to ease naive usage
- std::bad_alloc exceptions in the Memory class are now caught in 
  debug builds

Bug fixes
=========
- Fixed a sign error in advanced::HPDInverse
- Fixed a syntax error in advanced::HouseholderSolve
- Fixed several instances of the Matrix class initializing the 
  leading dimension to 0 (which is incompatible with BLAS)
- Fixed many std namespace issues throughout the headers which were
  artifacts of the conversion from source files to header files

Other changes
=============
- Renamed Shape to UpperOrLower since it was ambiguous
- Renamed basic::LocalTriangularRankK to basic::LocalTrrk, and 
  similarly basic::LocalTriangularRank2K to basic::LocalTrr2k
- All member variables now postfix underscores rather than prefixing
- Partway through converting Matrix and DistMatrix classes to template 
  over the integer type
