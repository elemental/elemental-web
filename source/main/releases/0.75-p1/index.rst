.. _release_0_75_p1:

#############################
07/06/2012: Elemental 0.75-p1
#############################

`elemental-0.75-p1.tgz <http://libelemental.org/pub/releases/elemental-0.75-p1.tgz>`__


New functionality
=================
- SVD support through the bidiagonal QR algorithm. If libFLAME is linked, a high-performance QR algorithm will be used.
- Pseudoinverses and polar decompositions through the new SVD routine
- QR-based Dynamically-Weighted Halley iteration (QDWH) for computing the polar decomposition, with versions for both general and Hermitian matrices
- Support for fast expansions of packed Householder reflectors for a few cases (i.e., those needed for QR and LQ decompositions)
- Explicit QR and LQ decompositions
- Cheap two-norm estimates
- 'Norm' now supports all DistMatrix distributions, instead of just [MC,MR]
- DistMatrix now supports 'viewing' processes that do not actively own data; this makes temporarily distributing to a subset of processes (e.g., a perfect square) less of a hack
- MakeHermitian, MakeSymmetric, and MakeReal were added
- LUSolve was added for solving systems using an existing LU factorization, with or without partial pivoting
- The routine Hetrmm, for forming one half of the Hermitian result L^H L or U U^H, was generalized to also support symmetric updates and the name was changed to Trtrmm
- The routine Trdtrmm was added in order to aid in the inversion of symmetric/Hermitian-indefinite matrices and forms L^H inv(D) L or U inv(D) U^H (or the symmetric counterpart)

Performance improvements
========================
- Faster ApplyPackedReflectors implementations
- Many variants of Gemm are now faster due to avoiding cache-unfriendly redistributions

Bug fixes
=========
- Fixed subtle issue in Householder reflection generation when the norm of the lower part of the vector was zero
- Fixed namespacing complaints from new versions of GCC and Clang
- Fixed mistakes in 1-2-1 and Wilkinson matrix generation
- Fixed missing installation of FCMangle.h and cmake-dummy-lib
- Fixed leakage of viewingGroup in the Grid destructor
- Fixed mistake in parallel Adjoint and Transpose routines
- Avoided bug in CMake's enable_language OPTIONAL argument

Semantic changes
================
- Shortened 'SetLocalEntry' and friends to the form 'SetLocal' in order to be more consistent with the distributed equivalent, 'Set'
- Expanded routines for extracting real and imaginary parts of complex data from the form 'Real' to 'RealPart'
- Shortened many redundant filenames

People involved
===============
- Robert van de Geijn, Field van Zee, and Gregorio Quintana Orti were involved in Elemental's support for FLAME's high-performance bidiagonal QR algorithm
- Yuji Nakatsukasa, Gregorio Quintana Orti, and Robert van de Geijn were involved in the QDWH implementation
- Bryan Marker noticed the cache-unfriendly redistributions in Gemm and Trsm
- Jed Brown submitted patches for the FCMangle.h and cmake-dummy-lib installation issues, as well as the viewingGroup leakage in the Grid class
- If I missed you, I apologize! Please let me know and I will add you!
