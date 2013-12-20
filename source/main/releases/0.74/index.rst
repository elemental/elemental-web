.. _release_0_74:

##########################
05/05/2012: Elemental 0.74
##########################

`elemental-0.74.tgz <http://libelemental.org/pub/releases/elemental-0.74.tgz>`__

Feature Improvements
====================
- Support for generating shared libraries was added with the "-D SHARED_LIBRARIES=ON" configuration option
- Elemental can now generate many different types of special matrices (Hilbert, Walsh, DFT, etc.)
- The routine "NormalUniformSpectrum" was added which generates a complex matrix by uniformly sampling the eigenvalues from a ball in the complex plane.
- The routines "MakeHermitianUniform" and "MakeUniformHPD" were removed in favor of the function "HermitianUniformSpectrum", which takes in the interval to uniformly sample the eigenvalues from.
- Many more examples in the examples/ folder
- HermitianSVD was added
- More functions are now supported by the Complex class
- A Shaheen (not just Intrepid) BG/P toolchain file now exists

Minor improvements and changes
==============================
- The routine "SquareRoot" was changed to "HPSDSquareRoot" since versions which do not assume a Hermitian Positive Semi-Definite matrix may eventually be added
- The enum "Side" was changed to "LeftOrRight" for clarity
- The enum "Diagonal" was changed to "UnitOrNonUnit" for clarity
- The DistMatrix implementation was greatly simplified, and many utility functions were pulled out of the class. For instance, DistMatrix member functions "MakeIdentity", "MakeTrapezoidal", and "MakeZero" were all removed from the class and are now external. 
- The documentation now uses a better style (Haiku instead of Default)

Bug fixes
=========
- Several buffers in ApplyPackedReflectors are now explicitly initialized as zero since any entries which happened to be initialized as a NaN would propagate
- Fixed several bugs in the new DistMatrix constructors where the proper row and column shifts were not correctly set
- MPI_Comm_f2c is now used to translate Fortran communicator handles into C in the experimental F90 interface
- "CMAKE_REQUIRED_INCLUDE" -> "CMAKE_REQUIRED_INCLUDES" in main CMakeLists.txt 
