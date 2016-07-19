Build system
************
Elemental's build system relies on `CMake <http://www.cmake.org>`__ 
in order to manage a large number of configuration options in a 
platform-independent manner; it can be easily configured to build on Linux and 
Unix environments (including Darwin), as well as via Cygwin in a Windows 
environment (Visual Studio's is expected to begin supporting ``constexpr``, 
which is heavily used by Elemental, with the official VS 2015 release in 
July 2015). A relatively recent C++11 compiler (e.g., gcc >= 4.7) is 
required in all cases.

Elemental's main external dependencies are

1. `CMake <http://www.cmake.org/>`__ ,
2. `MPI <http://en.wikipedia.org/wiki/Message_Passing_Interface>`__ ,
3. `BLAS <http://netlib.org/blas>`__ ,
4. `LAPACK <http://netlib.org/lapack>`__, 
5. `METIS <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__, and
6. `PMRRR <http://code.google.com/p/pmrrr>`__,

and the dependencies which can **not** currently be automatically handled by 
Elemental's build system are

1. CMake, and
2. MPI.

Handling mandatory external dependencies
========================================

Installing CMake
----------------
Elemental uses several relatively new CMake modules, so it is important to 
ensure that CMake version 2.8.12 or later is available. Thankfully, the 
`installation process <http://www.cmake.org/cmake/help/install.html>`_
is extremely straightforward: either download a platform-specific binary from
the `downloads page <http://www.cmake.org/cmake/resources/software.html>`_,
or instead grab the most recent stable tarball and have CMake bootstrap itself.
In the simplest case, the bootstrap process is as simple as running the 
following commands::

    ./bootstrap
    make
    sudo make install

Note that recent versions of `Ubuntu <http://www.ubuntu.com/>`__ (e.g., version 13.10) have sufficiently up-to-date
versions of CMake, and so the following command is sufficient for installation::

    sudo apt-get install cmake

If you do install from source, there are two important issues to consider

1. By default, ``make install`` attempts a system-wide installation 
   (e.g., into ``/usr/bin``) and will likely require administrative privileges.
   A different installation folder may be specified with the ``--prefix`` 
   option to the ``bootstrap`` script, e.g.,::

    ./bootstrap --prefix=/home/your_username
    make
    make install

   Afterwards, it is a good idea to make sure that the environment variable 
   ``PATH`` includes the ``bin`` subdirectory of the installation folder, e.g.,
   ``/home/your_username/bin``.

2. Some highly optimizing compilers will not correctly build CMake, but the GNU
   compilers nearly always work. You can specify which compilers to use by
   setting the environment variables ``CC`` and ``CXX`` to the full paths to 
   your preferred C and C++ compilers before running the ``bootstrap`` script.

Basic usage
^^^^^^^^^^^
Though many configuration utilities, like 
`autoconf <http://www.gnu.org/software/autoconf/>`_, are designed such that
the user need only invoke ``./configure && make && sudo make install`` from the
top-level source directory, CMake targets *out-of-source* builds, which is 
to say that the build process occurs away from the source code. The 
out-of-source build approach is ideal for projects that offer several 
different build modes, as each version of the project can be built in a 
separate folder.

A common approach is to create a folder named ``build`` in the top-level of 
the source directory and to invoke CMake from within it::

    mkdir build
    cd build
    cmake ..

The last line calls the command line version of CMake, ``cmake``,
and tells it that it should look in the parent directory for the configuration
instructions, which should be in a file named ``CMakeLists.txt``. Users that 
would prefer a graphical interface from the terminal (through ``curses``)
should instead use ``ccmake`` (on Unix platforms) or ``CMakeSetup`` 
(on Windows platforms). In addition, a GUI version is available through 
``cmake-gui``. 

Though running ``make clean`` will remove all files generated from running 
``make``, it will not remove configuration files. Thus, the best approach for
completely cleaning a build is to remove the entire build folder. On \*nix 
machines, this is most easily accomplished with::

    cd .. 
    rm -rf build/

This is perhaps a safer habit than simply running ``rm -rf *`` since, 
if accidentally run from the wrong directory, deleting ``build/`` would be 
unlikely to have any effect.

Installing MPI
--------------
An implementation of the Message Passing Interface (MPI) is required for 
building Elemental. The two most commonly used implementations are

1. `MPICH <https://www.mpich.org>`_,
2. `OpenMPI <http://www.open-mpi.org/>`_, and
3. `MVAPICH <http://mvapich.cse.ohio-state.edu>`_,

where MVAPICH is primarily focused on systems with 
`InfiniBand <http://en.wikipedia.org/wiki/InfiniBand>`_  and/or GPUs.

Each of the respective websites contains installation instructions, but, on recent versions of `Ubuntu <http://www.ubuntu.com/>`__, 
MPICH2 can be installed with ::

    sudo apt-get install libmpich2-dev

and OpenMPI can be installed with ::

    sudo apt-get install libopenmpi-dev

Alternatively, one could manually download and install a recent stable release
of MPICH, typically available from `http://www.mpich.org/downloads/ <http://www.mpich.org/downloads/>`__. For example, to download and install `mpich-3.1.4 <http://www.mpich.org/static/downloads/3.1.4/mpich-3.1.4.tar.gz>`__, one might run::

    wget http://www.mpich.org/static/downloads/3.1.4/mpich-3.1.4.tar.gz
    tar -xzf mpich-3.1.4.tar.gz
    cd mpich-3.1.4/
    ./configure --prefix=/where/to/install/mpich --CC=YourCCompiler --CXX=YourC++Compiler --FC=YourFortranCompiler
    make
    sudo make install 

where the ``sudo`` is obviously not needed if you have permission to install
files into the directory specified with ``--prefix``. Lastly, these instructions
assumed the existence of a Fortran compiler, and so, if one is not available,
you should instead run the commands::

    wget http://www.mpich.org/static/downloads/3.1.4/mpich-3.1.4.tar.gz
    tar -xzf mpich-3.1.4.tar.gz
    cd mpich-3.1.4/
    ./configure --prefix=/where/to/install/mpich --CC=YourCCompiler --CXX=YourC++Compiler --disable-fortran
    make
    sudo make install 

Soft dependencies
=================
As was already mentioned, Elemental has several external dependencies which
can be optionally be handled by the build process, and one 
(`PMRRR <http://code.google.com/p/pmrrr>`__), which is always built by 
Elemental. For the optionally-specified dependencies 
(i.e., BLAS, LAPACK, METIS, ParMETIS, and ScaLAPACK), if custom implementations
were not specified during the CMake configuration phase, then appropriate 
libraries will be automatically downloaded/built/installed via CMake's 
`ExternalProject <http://www.cmake.org/cmake/help/v3.0/module/ExternalProject.html>`__ functionality. In particular, Elemental can automatically fulfill 
dependencies using:

1. `OpenBLAS <http://www.openblas.net/>`__ or `BLIS <https://code.google.com/p/blis>`__ (to provide BLAS+LAPACK)
2. `METIS <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__ and/or `ParMETIS <http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview>`__ (for computing a vertex separator of a graph), and
3. `ScaLAPACK <http://netlib.org/scalapack>`__ (for implementations of distributed Hessenberg QR algorithms).

Furthermore, there are several further (optional) external dependencies:

1. `libFLAME <http://www.cs.utexas.edu/users/flame/>`_ is recommended 
   for faster SVD's due to its high-performance bidiagonal QR algorithm 
   implementation, 
2. `libquadmath <https://gcc.gnu.org/onlinedocs/libquadmath/>`_ for 
   quad-precision support (and more robust sparse-direct solvers),
3. `Qt5 <http://qt-project.org>`_ for C++11 matrix visualization,
4. `matplotlib <http://matplotlib.org/>`_ for Python matrix visualization,
5. `NetworkX <https://networkx.github.io/>`_ for Python graph visualization, and
6. `NumPy <http://www.numpy.org/>`_ for supporting the Python interface in 
   general.

Support is not required for any of these libraries, but each is helpful for 
particular components of Elemental's functionality.

Installing BLAS and LAPACK
--------------------------
The Basic Linear Algebra Subprograms (BLAS) and Linear Algebra PACKage (LAPACK) 
are both used heavily within Elemental. On most installations of `Ubuntu <http://www.ubuntu.com>`__, either of the following command should suffice for their installation::

    sudo apt-get install libopenblas-dev
    sudo apt-get install libatlas-dev liblapack-dev

The reference implementation of LAPACK can be found at

    http://www.netlib.org/lapack/

and the reference implementation of BLAS can be found at

    http://www.netlib.org/blas/

However, it is better to install an optimized version of these libraries,
especialy for the BLAS. The most commonly used open-source versions the BLAS are
`ATLAS <http://math-atlas.sourceforge.net/>`__, `OpenBLAS <https://github.com/xianyi/OpenBLAS>`__, and `BLIS <https://code.google.com/p/blis>`__.
If no version of BLAS+LAPACK is detected, Elemental attempts to download and
install OpenBLAS (or BLIS).

OpenBLAS
^^^^^^^^
`OpenBLAS <http://www.openblas.net>`__ is a high-performance implementation of 
the BLAS (and, to a somewhat lesser degree, LAPACK) which Elemental defaults
to downloading and installing if no other high-performance implementation
was detected . For example, by default, on Mac OS X, either Accelerate or 
vecLib is used, but this behavior may be overridden via the CMake option 
``-D EL_PREFER_OPENBLAS=TRUE``. Furthermore, Elemental may be requested not to
use OpenBLAS via the option ``-D EL_DISABLE_OPENBLAS=TRUE``.
Lastly, while Elemental will, by default, search for a previous installation of
OpenBLAS before attempting to download and install the library, this search can
be prevented via the ``-D EL_BUILD_OPENBLAS=TRUE`` option.

BLIS
^^^^
`BLIS <https://code.google.com/p/blis>`__ is "a software framework for 
instantiating high-performance BLAS-like dense linear algebra libraries" and
can optionally be downloaded and installed as part of Elemental's build 
process. In order to do so on non-Apple architectures, the flag 
``-D EL_DISABLE_OPENBLAS=TRUE`` should be enabled to avoid the OpenBLAS
default, and, on Apple-architectures, the flag 
``-D EL_PREFER_BLIS_LAPACK=TRUE`` should be specified to avoid the 
``vecLib``/``Accelerate`` frameworks.

libFLAME
^^^^^^^^
`libFLAME` is an open source library made available as part of the FLAME 
project. 
Elemental's current implementation of parallel SVD is dependent upon a serial 
kernel for the bidiagonal SVD. A high-performance implementation of this 
kernel was recently introduced in [vZvdGQ2014]_.

Installation of `libFLAME` is fairly straightforward. It is recommended that 
you download the latest nightly snapshot from

    http://www.cs.utexas.edu/users/flame/snapshots/

and then installation should simply be a matter of running::

    ./configure
    make
    sudo make install

Automatic installation of libflame will hopefully be added into Elemental's 
build system soon (pending the resolution of issues in the current ``libflame``
build system). Until that time, it is necessary to manually specify ``libflame``
as part of the ``MATH_LIBS`` variable. For example, if libflame is available at
``/path/to/libflame.a``, then this library needs to be prepended to the 
list of BLAS and LAPACK libraries, e.g., via::

    -D MATH_LIBS="/path/to/libflame.a;-L/usr/lib -llapack -lblas -lm"

or::

    -D MATH_LIBS="/path/to/libflame.a;-mkl"

PMRRR
-----
PMRRR is a parallel implementation of the MRRR algorithm introduced by 
`Inderjit Dhillon <http://www.cs.utexas.edu/~inderjit/>`_ and 
`Beresford Parlett <http://math.berkeley.edu/~parlett/>`_ for computing 
:math:`k` eigenvectors of a tridiagonal matrix of size :math:`n` in 
:math:`\mathcal{O}(nk)` time. PMRRR was written by 
`Matthias Petschow <http://www.aices.rwth-aachen.de/people/petschow>`_ and 
`Paolo Bientinesi <http://www.aices.rwth-aachen.de/people/bientinesi>`_ and,
while it is included within Elemental, it is also available at:

    http://code.google.com/p/pmrrr

Note that PMRRR currently requires support for pthreads.

METIS
-----
`METIS <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__ is perhaps the
most widely-used library for (hyper)graph partitioning and is the default 
tool used within Elemental in order to construct vertex separators for the 
Nested Dissection approach to sparse-direct factorization. In particular, 
Elemental makes use of the routine ``METIS_ComputeVertexSeparator``, which is
somewhat undocumented but used by ParMETIS. METIS, unlike ParMETIS, is released
under the terms of the Apache License Version 2.0 (which is similar in spirit 
to Elemental's New BSD License).

Support for METIS can be disabled via the CMake option 
``-D EL_DISABLE_METIS=TRUE``, or Elemental can be requested to avoid 
detecting a previous installation and instead immediately decide to 
download/install the library via the ``-D EL_BUILD_METIS=TRUE`` option.

ParMETIS
--------
`ParMETIS <http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview>`__ is a 
parallel version of METIS that is unfortunately released under a more 
restrictive license that does not allow for commercial usage, and so commercial
users should add the CMake option ``-D EL_DISABLE_PARMETIS=TRUE`` when 
configuring Elemental. Furthermore, since ParMETIS, unlike METIS, does not 
provide a routine for computing a vertex separator of a graph, Elemental 
makes use of ParMETIS's internal APIs in order to construct such a routine
(which can be viewed as a parallel analogue of 
``METIS_ComputeVertexSeparator``).

Also, Elemental can be requested to avoid 
detecting a previous installation (which is extremely unlikely to be sufficient due to Elemental's usage of ParMETIS's internal API, which is not typically 
installed) and instead immediately decide to download and install the library 
via the ``-D EL_BUILD_PARMETIS=TRUE`` option.

ScaLAPACK
---------
`ScaLAPACK <http://netlib.org/scalapack>`__ is the most widely-used library for
distributed-memory dense linear algebra and contains a number of routines not
implemented elsewhere. In particular, its distributed Hessenberg Schur 
decomposition support can be optionally used within Elemental for computing
Schur decompositions (which is the preprocessing step for Elemental's 
high-performance pseudospectral calculations).
The routines resulting from the work of [HWD2002]_ (and the corresponding 
complex implementation from [Fahey2003]_), as well as the later AED versions from [GKK2010]_, are all used in different instances.

Support for ScaLAPACK can be disabled via the CMake option ``-D EL_DISABLE_SCALAPACK=TRUE``, or Elemental can be requested to avoid detecting previous 
installations and to download/install the library via 
``-D EL_BUILD_SCALAPACK=TRUE``.

libquadmath
-----------
If a GNU compiler is being used to compile Elemental, then it is likely that
support for `libquadmath <https://gcc.gnu.org/onlinedocs/libquadmath/>`_ was
detected, and, by default, this would lead to both more robust Interior Point
Methods and your copy of Elemental transitioning from the terms of the New 
BSD License to the GNU General Public License. If you prefer not to use 
Elemental under the terms of the GPL, then ``libquadmath`` must be disabled
via the CMake option ``-D EL_DISABLE_QUAD=TRUE``.

Qt5
---
Qt is an open source cross-platform library for creating Graphical User 
Interfaces (GUIs) in C++. Elemental currently supports using version 5.1.1 of 
the library to display and save images of matrices.

Please visit Qt Project's `download page <http://qt-project.org/downloads>`__
for download and installation instructions. Note that, if Elemental is launched
with the `-no-gui` command-line option, then Qt5 will be started without GUI
support. This supports using Elemental on clusters whose compute nodes do not
run display servers, but PNG's of matrices need to be created using Qt5's 
simple interface.

Getting Elemental's source 
==========================
There are two basic approaches:

1. Download a tarball of the most recent version from 
   `libelemental.org/releases <http://libelemental.org/releases/>`_. 
   A new version is typically released every one to two months.

2. Install `git <http://git-scm.com/>`_ and check out a copy of 
   the repository by running ::

    git clone git://github.com/elemental/Elemental.git

Building Elemental
==================
On Unix-like machines with MPI and CMake installed in standard locations,
Elemental can often be built and installed using the commands::

    git clone https://github.com/elemental/Elemental
    cd Elemental
    mkdir build
    cd build
    cmake ..
    sudo make
    sudo make install

Note that super-user privileges may be required for the ``make`` phase due to 
the installation of external packages.

As with the installation of CMake, the default install location is 
system-wide, e.g., ``/usr/local``. The installation directory of the main 
library can be changed at any time by invoking CMake with the option::

    -D CMAKE_INSTALL_PREFIX=/your/desired/install/path

and the installation of the Python interface can be switched from the default
system-wide location to the user's home directory via the option::

    -D INSTALL_PYTHON_INTO_USER_SITE=ON

or instead installed into ``${CMAKE_INSTALL_PREFIX}/python/`` via the option::

    -D INSTALL_PYTHON_PACKAGE=OFF

Alternatively, the user can specify a particular directory for the python
package via::

    -D PYTHON_SITE_PACKAGES=/your/desired/python/install/path

Though the above instructions will work on many systems, it is common to need
to manually specify several build options, especially when multiple versions of
libraries or several different compilers are available on your system. For 
instance, any C++, C, or Fortran compiler can respectively be set with the 
``CMAKE_CXX_COMPILER``, ``CMAKE_C_COMPILER``, and ``CMAKE_Fortran_COMPILER`` 
variables, e.g., ::

    -D CMAKE_CXX_COMPILER=/usr/bin/g++ \
    -D CMAKE_C_COMPILER=/usr/bin/gcc   \
    -D CMAKE_Fortran_COMPILER=/usr/bin/gfortran 

and it may be necessary to manually specify the paths to the MPI compilers as  
well using, for example, the options::

    -D MPI_CXX_COMPILER=/usr/bin/mpicxx \
    -D MPI_C_COMPILER=/usr/bin/mpicc \
    -D MPI_Fortran_COMPILER=/usr/bin/mpif90

It is also occasionally necessary to specify which libraries need to be linked 
in order to link to BLAS and LAPACK (and, if SVD is important, libFLAME).
The ``MATH_LIBS`` variable was introduced for this purpose and an 
(unrecommended for performance reasons) example for specifying BLAS and LAPACK 
libraries in ``/usr/lib`` might be ::

    -D MATH_LIBS="-L/usr/lib -llapack -lblas -lm"

whereas specifying Intel's MKL libraries when using the Intel compilers is often
as simple as::

    -D MATH_LIBS="-mkl"

It is important to ensure that if library A depends upon library B, A should 
be specified to the left of B; in this case, LAPACK depends upon BLAS, so 
``-llapack`` is specified to the left of ``-lblas``. If ``MATH_LIBS`` is not
specified, then Elemental will attempt to download and install either 
OpenBLAS or BLIS, or, failing that, search for an installed reference 
implementation.

Build modes
===========
Elemental currently has two different build modes:

* **Debug** - Maintains a call stack and provides significant error-checking.
* **Release** - An optimized build suitable for production usage (assuming high-performance BLAS and MPI implementations were used)

The build mode can be specified with the ``CMAKE_BUILD_TYPE`` option, e.g., 
``-D CMAKE_BUILD_TYPE=Debug``. If this option is not specified, Elemental
defaults to the **Release** build mode.

Once the build mode is selected, one might also want to manually set the 
optimization level of the compiler, e.g., via the CMake option 
``-D CXX_FLAGS="-O3"``.

Furthermore, there is also an option to attempt to make use of OpenMP 
parallelization when packing and unpacking MPI buffers that is enabled when
the ``-D EL_HYBRID=TRUE`` CMake option is set. If this option is used, the user
should ensure that a threaded BLAS implementation is used.

Testing the C++11 installation
==============================
Once Elemental has been installed, it is a good idea to verify that it is 
functioning properly. This can be accomplished by simply running::

    make test

Alternatively, an example of generating a random distributed matrix, 
computing its Singular Value Decomposition (SVD), and checking for numerical 
error is available in `examples/lapack_like/SVD.cpp <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/SVD.cpp>`__.

As you can see, the only required header is ``El.hpp``, which must be
in the include path when compiling this simple driver, ``SVD.cpp``. 
If Elemental was installed in ``/usr/local``, then 
``/usr/local/conf/ElVars`` can be used to build a simple Makefile::

    include /usr/local/conf/ElVars

    SVD: SVD.cpp
        ${CXX} ${EL_COMPILE_FLAGS} $< -o $@ ${EL_LINK_FLAGS} ${EL_LIBS}

As long as ``SVD.cpp`` and this ``Makefile`` are in the current directory,
simply typing ``make`` should build the driver. 

The executable can then typically be run with a single process (generating a 
:math:`300 \times 300` distributed matrix, using ::

    ./SVD --height 300 --width 300

and the output should be similar to ::
    
    ||A||_max   = 0.999997
    ||A||_1     = 165.286
    ||A||_oo    = 164.116
    ||A||_F     = 173.012
    ||A||_2     = 19.7823

    ||A - U Sigma V^H||_max = 2.20202e-14
    ||A - U Sigma V^H||_1   = 1.187e-12
    ||A - U Sigma V^H||_oo  = 1.17365e-12
    ||A - U Sigma V^H||_F   = 1.10577e-12
    ||A - U Sigma V_H||_F / (max(m,n) eps ||A||_2) = 1.67825

The driver can be run with several processes using the MPI launcher provided
by your MPI implementation; a typical way to run the ``SVD`` driver on 
eight processes would be::

    mpirun -np 8 ./SVD --height 300 --width 300

You can also build a wide variety of example and test drivers 
(unfortunately the line is a little blurred) by using the CMake options::

    -D EL_EXAMPLES=ON

and/or ::

    -D EL_TESTS=ON  

Testing the Python installation
===============================
A number of Python example scripts which, for example, solve sparse linear 
systems and quadratic programs, may be found at
`examples/interface <https://github.com/elemental/Elemental/blob/master/examples/interface>`__. However, it is typically necessary to augment the environment
variable ``PYTHONPATH``, and perhaps also ``LD_LIBRARY_PATH``.

Linux systems
-------------
On most Linux systems, it will be necessary to append 
``$(CMAKE_INSTALL_PREFIX)/lib`` to ``LD_LIBRARY_PATH`` as well as setting
``PYTHONPATH`` to a value dependent upon how Elemental was instructed to install
the Python interface. In the default case, where Python is installed into the 
global site packages directory, ``PYTHONPATH`` should be set to the result of::

    from distutils.sysconfig import get_python_lib
    print get_python_lib()

which may have a value suh as ``$(HOME)/anaconda/lib/python2.7/site-packages``.

In cases where the CMake option 
``INSTALL_PYTHON_PACKAGE=OFF`` was specified, ``PYTHONPATH`` should be set to
``$(CMAKE_INSTALL_PREFIX)/python``, whereas, if the CMake option 
``INSTALL_PYTHON_INTO_USER_SITE=ON`` was specified, then ``PYTHONPATH`` 
should be set to the result of::

    import site
    print site.USER_SITE


which is frequently ``$(HOME)/.local/lib/python2.7/site-packages``.

Mac OS X
---------
It should typically only be necessary to set ``PYTHONPATH`` in the same way 
as on Linux systems (there should be no need to set ``LD_LIBRARY_PATH``, 
nor its OS X equivalent, ``DYLD_LIBRARY_PATH``).

Elemental as a CMake subproject
===============================

.. note::

   These instructions are somewhat out of date and so an email to 
   `users@libelemental.org <mailto:users@libelemental.org>`_ might be 
   more appropriate for now in order to help with using Elemental as a
   subproject of another CMake build system.

Adding Elemental as a dependency into a project which uses CMake for its build 
system can be relatively straightforward: simply put an entire copy of the 
Elemental source tree in a subdirectory of your main project folder, say 
``external/elemental``, and then create a ``CMakeLists.txt`` file in your main 
project folder that builds off of the following snippet::

    cmake_minimum_required(VERSION 2.8.8) 
    project(Foo)

    add_subdirectory(external/elemental)
    include_directories("${PROJECT_BINARY_DIR}/external/El/include")
    include_directories(${MPI_CXX_INCLUDE_PATH})

    # Build your project here
    # e.g., 
    #   add_library(foo ${LIBRARY_TYPE} ${FOO_SRC})
    #   target_link_libraries(foo El)

Troubleshooting
===============
If you run into build problems, please email 
`maint@libelemental.org <mailto:maint@libelemental.org>`_ 
and make sure to attach the file ``include/El/config.h``, which should 
be generated within your build directory. 
Please only direct usage questions to 
`users@libelemental.org <mailto:users@libelemental.org>`_, 
and development questions to 
`dev@libelemental.org <mailto:dev@libelemental.org>`_.

References
==========

.. [HWD2002] Greg Henry, David Watkins, and Jack Dongarra, *A parallel implementation of the nonsymmetric QR algorithm for distributed memory architectures*, SIAM Journal on Scientific Computing, Vol. 24, No. 1, pp. 284--311, 2002. DOI: `http://dx.doi.org/10.1137/S1064827597325165 <http://dx.doi.org/10.1137/S1064827597325165>`__

.. [Fahey2003] Mark R. Fahey, *Algorithm 826: A parallel eigenvalue routine for complex Hessenberg matrices*, ACM Transactions on Mathematical Software, Vol. 29, Issue 3, pp. 326--336, 2003. DOI: `http://dx.doi.org/10.1145/838250.838256 <http://dx.doi.org/10.1145/838250.838256>`__

.. [GKK2010] Robert Granat, Bo Kagstrom, and Daniel Kressner, *A novel parallel QR algorithm for hybrid distributed memory HPC systems*, SIAM Journal on Scientific Computing, Vol. 32, No. 4, pp. 2345--2378, 2010. DOI: `http://dx.doi.org/10.1137/090756934 <http://dx.doi.org/10.1137/090756934>`__

.. [vZvdGQ2014] Field G. van Zee, Robert A. van de Geijn, and Gregorio Quintana-Orti, *Restructuring the tridiagonal and bidiagonal QR algorithms for performance*, ACM Transactions on Mathematical Software, Vol. 40, Issue 3, Article No. 18, 2014. DOI: `http://dx.doi.org/10.1145/2535371 <http://dx.doi.org/10.1145/2535371>`__
