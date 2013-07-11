.. _release_0_79:

##########################
04/28/2013: Elemental 0.79
##########################

`elemental-0.79.tgz <http://libelemental.org/pub/releases/elemental-0.79.tgz>`__

Features
========
- Added Businger/Golub pivoted QR and the ability to early-exit (qr::BusingerGolub)
- Added thresholded SVD based upon the cross-product algorithm (svd::Thresholded)
- Added RRQR preprocessing for faster SingularValueSoftThresholding (SVT)
- Updated RPCA example to allow for use of RRQR-preprocessed SVT
- Added implementation of Cannon's algorithm (gemm::Cannon_NN)
- Added Kahan, GKS, and Extended Kahan matrices
- Added HermitianSign and UnitaryCoherence calculations
- Added sequential version of HermitianEig
- Added versions of a few routines (e.g., Gemm) which handle zero initialization
- Added a MemSwap function to complement MemCopy and MemZero

Bug fixes
=========
- Fixed several zero initialization bugs
- Fixed shared library linking for PMRRR on Macs
- Fixed syntax error in DistMatrix driver

Maintenance
===========
- Beginning to maintain REFERENCES and PUBLICATIONS files
- Switched to much simpler RAII-based call-stack manipulation
- Added BASE(F) macro to avoid repeatedly using 'typename Base<F>::type'
- Removed Parallel Linear Congruential Generator in favor of simpler scheme
- All special matrix function routines now take the output matrix as first argument
- Began removing 'internal' namespaces in favor of routine-specific namespaces
- Renamed 'HouseholderSolve' to 'LeastSquares'
