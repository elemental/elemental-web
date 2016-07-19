Version and configuration information
=====================================

Every Elemental driver with proper command-line argument processing will run
`PrintVersion` if the ``--version`` argument is used. If ``--build`` is used,
then all of the below information is reported.

Versioning
----------
The following routines print the Git revision, (pre-)release version, and 
build type. For example::

    Elemental version information:
      Git revision: 3c6fbdaad901a554fc27a83378d63dab55af0dd3
      Version:      0.86-dev
      Build type:   Debug

C++ API
^^^^^^^

.. cpp:function:: void PrintVersion( std::ostream& os=std::cout )

C API
^^^^^

.. c:function:: ElError ElPrintVersion( FILE* stream )

Python API
^^^^^^^^^^

.. py:function:: PrintVersion(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

Configuration
-------------
The following routines print several relevant configuration details. 
For example::

 Elemental configuration:
   Math libraries:               /usr/lib/liblapack.so;/usr/lib/libblas.so
   Have FLAME bidiagonal SVD:    YES
   Have OpenMP:                  YES
   Have Qt5:                     YES
   Avoiding complex MPI:         YES
   Have MPI_Reducescatter_block: YES
   Have MPI_IN_PLACE:            YES
   AllReduce ReduceScatterBlock: YES
   Use byte AllGathers:          YES

C++ API
^^^^^^^
   
.. cpp:function:: void PrintConfig( std::ostream& os=std::cout )

C API
^^^^^

.. c:function:: ElError ElPrintConfig( FILE* stream )

Python API
^^^^^^^^^^

.. py:function:: PrintConfig(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

C compiler info
---------------
The following routines print various details about the C compilation process. 
For example::

 Elemental's C compiler info:
   EL_CMAKE_C_COMPILER:    /usr/local/bin/gcc
   EL_MPI_C_COMPILER:      /home/poulson/Install/bin/mpicc
   EL_MPI_C_INCLUDE_PATH:  /home/poulson/Install/include
   EL_MPI_C_COMPILE_FLAGS: 
   EL_MPI_C_LINK_FLAGS:     -Wl,-rpath  -Wl,/home/poulson/Install/lib
   EL_MPI_C_LIBRARIES:     /home/poulson/Install/lib/libmpich.so;/home/poulson/Install/lib/libopa.so;/home/poulson/Install/lib/libmpl.so;/usr/lib/i386-linux-gnu/librt.so;/usr/lib/i386-linux-gnu/libpthread.so

C++ API
^^^^^^^

.. cpp:function:: void PrintCCompilerInfo( std::ostream& os=std::cout )

C API
^^^^^

.. c:function:: ElError ElPrintCCompilerInfo( FILE* stream )

Python API
^^^^^^^^^^

.. py:function:: PrintCCompilerInfo(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

C++ compiler info
-----------------
The following routines print various details about the C++ compilation process.
For example::

 Elemental's C++ compiler info:
   EL_CMAKE_CXX_COMPILER:    /usr/local/bin/g++
   EL_CXX_FLAGS:             -Wall
   EL_MPI_CXX_COMPILER:      /home/poulson/Install/bin/mpicxx
   EL_MPI_CXX_INCLUDE_PATH:  /home/poulson/Install/include
   EL_MPI_CXX_COMPILE_FLAGS: 
   EL_MPI_CXX_LINK_FLAGS:     -Wl,-rpath  -Wl,/home/poulson/Install/lib
   EL_MPI_CXX_LIBRARIES:     /home/poulson/Install/lib/libmpichcxx.so;/home/poulson/Install/lib/libmpich.so;/home/poulson/Install/lib/libopa.so;/home/poulson/Install/lib/libmpl.so;/usr/lib/i386-linux-gnu/librt.so;/usr/lib/i386-linux-gnu/libpthread.so

C++ API
^^^^^^^

.. cpp:function:: void PrintCxxCompilerInfo( std::ostream& os=std::cout )

C API
^^^^^

.. c:function:: ElError ElPrintCxxCompilerInfo( FILE* stream )

Python API
^^^^^^^^^^

.. py:function:: PrintCxxCompilerInfo(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

