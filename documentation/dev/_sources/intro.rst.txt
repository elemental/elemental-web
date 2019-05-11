Introduction
************

Overview
========
Elemental is C++11-based library that supports a wide collection of
sequential and distributed-memory operations, including support for dense and sparse-direct linear algebra, Linear, Quadratic and Second-Order Cone Programming, and lattice reduction. Furthermore, it supports such functionality for real and complex single-precision, double-precision, “double-double”, “quad-double”, quad-precision, and arbitrary-precision floating-point arithmetic.

The project originally began as an object-oriented analogue and extension of 
the parallel dense linear algebra library [PLAPACK]_, which was designed 
around the idea of building a graph of different matrix distributions and 
providing simple API for moving a matrix from one such distribution to another 
throughout the course of a computation.
Over time, the functionality of Elemental steadily expanded beyond its 
beginnings; at one point, Elemental was quite similar in scope to 
[ScaLAPACK]_, the most widely-used library for 
extending [LAPACK]_ to distributed-memory 
architectures, but Elemental now also supports a much wider scope
(including sparse-direct linear and (generalized) least squares solvers,
Interior Point Methods for Second-Order Cone Programs, and lattice reduction).

Elemental's name is derived from the fact that, unlike PLAPACK and ScaLAPACK,
its primary dense matrix distributions are designed to spread matrix entries in
element-wise, as opposed to block-wise, fashions [PEtAl2013]_.

Elemental currently supports C++11, C, and Python interfaces, while 
`an R interface is being maintained by Rodrigo Canales <https://github.com/rocanale/R-Elemental>`__ and `a Julia interface <https://github.com/JuliaParallel/Elemental.jl>`__ is under development.
Interfaces to other languages, such as Fortran 90, can be built on top of
the C interface in a straightforward, if not tedious, manner. Ideally 
Elemental will eventually be hooked into LLVM in order to help automate 
the creation of external interfaces.

Dependencies
============
* Functioning C++11 and ANSI C compilers.
* A working MPI2 implementation
* BLAS and LAPACK (ideally version 3.3 or greater) implementations. 
* `CMake <http://www.cmake.org>`_ (version 2.8.12 or later for OS X and version 2.8.11 or later otherwise).
* For double-double and quad-double support, `QD <http://crd-legacy.lbl.gov/%7Edhbailey/mpdist/>`__ is required.
* For arbitrary-precision arithmetic, `MPFR <http://www.mpfr.org/>`__ and `MPC <http://www.multiprecision.org/index.php?prog=mpc>`__ are required.

If a sufficiently up-to-date C++11 compiler is used (e.g., recent versions of 
``g++`` or ``clang++``), Elemental should be straightforward to build on 
Unix-like platforms. There are still a few edges left to round to support
Microsoft Windows platforms.

License and copyright
=====================
While the vast majority of the project is licensed under the `2-clause BSD License <https://opensource.org/licenses/bsd-license.php>`__, several components are
modifications of external work that is under a different license. Please see
the `debian/copyright file <https://github.com/elemental/Elemental/blob/master/debian/copyright>`__ for more details.

Further, note that Elemental optionally downloads and installs a number of
libraries,such as:

1. `METIS <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__, which is 
   made available under the (equally permissive) 
   `Apache License, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0.html>`__.
2. `ParMETIS <http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview>`__,
   which can not be used for commercial purposes (it can be disabled with the 
   CMake option ``-D EL_DISABLE_PARMETIS=TRUE``),
3. `OpenBLAS <http://www.openblas.net/>`__, which is available under the 
   New BSD License (it can be disabled with ``-D EL_DISABLE_OPENBLAS=TRUE``), 
4. `BLIS <https://code.google.com/p/blis>`__, which is available under the
   New BSD License (it can be disabled with ``-D EL_DISABLE_BLIS=TRUE``), and
5. `ScaLAPACK <http://www.netlib.org/scalapack>`__, which is also available 
   under the New BSD License (and is not built by default).

References
==========

.. [PEtAl2013] Jack Poulson, Bryan Marker, Robert A. van de Geijn, Jeff R. Hammond, and Nichols A. Romero, *Elemental: A new framework for distributed memory dense matrix computations*, ACM Transactions on Mathematical Software, Vol. 39, Issue 2, Article No. 13, 2013. DOI: `http://dx.doi.org/10.1145/2427023.2427030 <http://dx.doi.org/10.1145/2427023.2427030>`__

.. [LAPACK] E. Anderson, Z. Bai, C. Bischof, S. Blackford, J. Demmel, J. Dongarra, J. Du Croz, A. Greenbaum, S. Hammarling, A. McKenney, and D. Sorensen, *LAPACK Users' Guide: Third Edition*, Society for Industrial and Applied Mathematics, Philadelphia, PA, 1999. Last accessed from: `http://www.netlib.org/lapack/lug/ <http://www.netlib.org/lapack/lug/>`__

.. [PLAPACK] Robert A. van de Geijn, *Using PLAPACK*, The MIT Press, Cambridge, MA, 1997. Currently available from: `https://mitpress.mit.edu/books/using-plapack <https://mitpress.mit.edu/books/using-plapack>`__

.. [ScaLAPACK] L.S. Blackford, J. Choi, A. Cleary, E. D'Azevedo, J. Demmel, I. Dhillon, J. Dongarra, S. Hammarling, G. Henry, A. Petitet, K. Stanley, D. Walker, and C.R. Whaley, *ScaLAPACK Users' Guide*, Society for Industrial and Applied Mathematics, Philadelphia, PA, 1997. Last accessed from: `http://www.netlib.org/scalapack/slug/ <http://www.netlib.org/scalapack/slug/>`__
