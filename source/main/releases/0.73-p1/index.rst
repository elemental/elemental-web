.. _release_0_73_p1:

#############################
03/11/2012: Elemental 0.73-p1
#############################

`elemental-0.73-p1.tgz <http://libelemental.org/pub/releases/elemental-0.73-p1.tgz>`__

- Fixed bug in Frobenius norm computation in HermitianNorm
- Fixed bug in [VR,* ] <- [MR,* ] SumScatterFrom
- Modified elem::Initialize/elem::Finalize to reference count
- Added wrappers for std::memcpy and std::memset for later generalization
- Relaxed the requirements for builds with MKL (libguide.a not required)
- Added enough wrappers to allow elem::Gemm to run with integer datatypes
- Updated documentation from Sphinx 1.1.2 to 1.1.3
