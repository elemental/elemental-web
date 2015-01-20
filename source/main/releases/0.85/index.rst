.. _release_0_85:

##########################
11/08/2014: Elemental 0.85
##########################

`Elemental-0.85.tgz <http://libelemental.org/pub/releases/Elemental-0.85.tgz>`__

Documentation: `[HTML] <http://libelemental.org/documentation/0.85/>`__ `[PDF] <http://libelemental.org/documentation/elem-0.85.pdf>`__ 

The significant changes since release 0.84 are listed below.

Added functionality
-------------------
* Sparse-direct Cholesky and Bunch-Kaufman due to merging Clique into Elemental
* Sparse-direct least squares, ridge regression, and Tikhonov regularization
* Sparse Herk and various other BLAS1-like routines
* A (nearly full) manually-constructed C interface
* A (nearly full) manually-constructed Python interface, including extensions of Display functionality to matplotlib (for matrices) and networkx (for graphs)
* Support for Read, Write, and ReadWrite matrix proxies so that routines implemented for specific datatypes and/or data distributions can be extended to more general datatypes and arbitrary distribution choices
* Essentially all distributed routines in the library were generalized to AbstractDistMatrix for convenience (using proxies)
* Single-precision Hermitian eigensolvers are now supported (via proxies which convert to double-precision for PMRRR)
* Added Three-valued and Bernoulli, GEPPGrowth and Druinsky-Toledo, Fourier-Identity ("spikes and sines") and Walsh-Identity ("spikes and Hadamard") matrices
* Added ability to compute coherence
* Added ability to use operator() to extract contiguous submatrices (and converted library)
* Extended control of SVD and LDL via new SVDCtrl and LDLCtrl structures
* Improved performance of IO routines when ColStride() and/or RowStride() are 1

Bug fixes
---------
* Fixed a variety of compilation errors which did not appear with g++
* Fixed an (uncommon) bug in distributed HermitianFrobeniusNorm
* Added missing shrink of the phase vector in qr::BusingerGolub
* Added missing scalar argument to Matrix::UpdateDiagonal
* Fixed Ehrenfest matrix generation
* Fixed indexing of Householder phases in sequential Bidiag
* Fixed offset used by rq::ExplicitTriang
* Fixed BlockDistMatrix version of MATRIX_MARKET Read
* Fixed BLAS wrappers for complex herk, her2k, her, and her2
* Fixed PURE/HYBRID CMake detection (thanks to Richard Boyd)
* Fixed Mac vecLib/Accelerate detection

Refactoring
-----------
* Removed MakeTriangular (due to the more general MakeTrapezoidal)
* Replaced AxpyTriangle with AxpyTrapezoid
* Added a control structure for Bisect
* Significantly refactored/simplified Trr2k
* Removed spurious integer argument to TriW
* Removed Riemann matrix due to vague definition (and overlap with Redheffer)
* Removed hyphens in directory names to avoid python conflict

Name changes
------------
* Renamed namespace "elem" to "El", and "elem.hpp" to "El.hpp"
* Moved auxiliary PMRRR headers into pmrrr/ subfolder
* "Pseudospectra" -> {"SpectralPortrait","SpectralWindow","SpectralCloud"}
* Better organization/naming for explicit QR/RQ/LQ factorizations

Thanks
------
* Richard Boyd (of GTRI) for reporting the PURE/HYBRID configuration detection problem
* Field van Zee (of UT Austin) for clarifying the {c,z}her2 and {c,z}her2k scalar argument conventions
* Rodrigo Canales for noticing and fixing several missing static instantiations
* Yingzhou (Ryan) Li for reporting the vecLib/Accelerate issue

Relevant unmerged forks
-----------------------
* Rodrigo Canales's R interface: https://github.com/rocanale/Elemental
* Sayan Ghosh's one-sided Axpy interface: https://github.com/sg0/Elemental
