Introduction
************

Overview
========
Elemental is a library for distributed-memory "direct" linear algebra and
optimization, with the term "direct" being the best single descriptor for the 
class of algorithms containing dense linear algebra, sparse-direct linear 
algebra, and Interior Point Methods for convex optimization.
Elemental originally began as an object-oriented analogue and extension of 
the parallel dense linear algebra library [PLAPACK]_, which was designed 
around the idea of building a graph of different matrix distributions and 
providing simple API for moving a matrix from one such distribution to another 
throughout the course of a computation.
Over time, the functionality of Elemental steadily expanded beyond its 
beginnings; at one point, Elemental was quite similar in scope to 
[ScaLAPACK]_, the most widely-used library for 
extending [LAPACK]_ to distributed-memory 
architectures, but Elemental now also implements distributed-memory 
sparse-direct solvers and Interior Point Methods, and so there is no longer 
another library with comparable depth and scope.

Elemental's name is derived from the fact that, unlike PLAPACK and ScaLAPACK,
its primary dense matrix distributions are designed to spread matrix entries in
element-wise, as opposed to block-wise, fashions [PEtAl2013]_.
Some of the unique features of Elemental include distributed implementations of:

* Dense and sparse Interior Point Methods for linear and quadratic programs
* Support for dense and sparse basis pursuit, Lasso, SVM, etc.
* High-performance pseudospectral computation and visualization
* Quadratic-time low-rank Cholesky and LU modifications
* Bunch-Kaufman and Bunch-Parlett for accurate symmetric factorization
* LU and Cholesky with full pivoting
* Column-pivoted QR and interpolative/skeleton decompositions
* Quadratically Weighted Dynamic Halley iteration for the polar decomposition
* Spectral Divide and Conquer Schur decomposition and Hermitian EVD
* Many algorithms for Singular-Value soft-Thresholding (SVT)
* Tall-skinny QR decompositions
* Hermitian matrix functions

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
* `CMake <http://www.cmake.org>`_ (version 2.8.8 or later).

If a sufficiently up-to-date C++11 compiler is used (e.g., recent versions of 
``g++`` or ``clang++``), Elemental should be straightforward to build on 
Unix-like platforms. Building on Microsoft Windows platforms should also be 
possible with modest effort.

License and copyright
=====================
All files distributed with Elemental, with the exception of Elemental's 
custom `ParMETIS <http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview>`__
extensions (which can easily be disabled), are distributed under the terms of 
the `New BSD license <http://www.opensource.org/licenses/bsd-license.php>`_,
which states::

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

     - Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

     - Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

     - Neither the name of the owner nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

But note that Elemental optionally downloads and installs a number of libraries,
such as:

1. `METIS <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__, which is 
   made available under the (equally permissive) 
   `Apache License, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0.html>`__.
2. `ParMETIS <http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview>`__,
   which can not be used for commercial purposes (it can be disabled with the 
   CMake option ``-D EL_DISABLE_PARMETIS=TRUE``),
3. `libquadmath <https://gcc.gnu.org/onlinedocs/libquadmath/>`__, which is 
   available under the terms of the GNU GPL (it can be disabled with the 
   CMake option ``-D EL_DISABLE_QUAD=TRUE``), 
4. `OpenBLAS <http://www.openblas.net/>`__, which is available under the 
   New BSD License (it can be disabled with ``-D EL_DISABLE_OPENBLAS=TRUE``), 
   and
5. `ScaLAPACK <http://www.netlib.org/scalapack>`__, which is also available 
   under the New BSD License (and can be disabled with 
   ``-D EL_DISABLE_SCALAPACK=TRUE``).

Most source files contain the copyright notice::

    Copyright (c) 2009-2015, Jack Poulson
    All rights reserved.

For an up-to-date list of contributing authors, please see the 
`AUTHORS file <https://github.com/elemental/Elemental/blob/master/AUTHORS>`__.

.. [PEtAl2013] `Jack Poulson, Bryan Marker, Robert A. van de Geijn, Jeff R. Hammond, and Nichols A. Romero, *Elemental: A new framework for distributed memory dense matrix computations*, ACM Transactions on Mathematical Software, Vol. 39, Issue 2, Article No. 13, 2013. <http://dl.acm.org/citation.cfm?id=2427030>`__

.. [LAPACK] `E. Anderson, Z. Bai, C. Bischof, S. Blackford, J. Demmel, J. Dongarra, J. Du Croz, A. Greenbaum, S. Hammarling, A. McKenney, and D. Sorensen, *LAPACK Users' Guide: Third Edition*, Society for Industrial and Applied Mathematics, Philadelphia, PA, 1999 <http://www.netlib.org/lapack/lug>`_

.. [PLAPACK] `Robert A. van de Geijn, *Using PLAPACK*, The MIT Press, Cambridge, MA, 1997 <https://mitpress.mit.edu/books/using-plapack>`__

.. [ScaLAPACK] `L.S. Blackford, J. Choi, A. Cleary, E. D'Azevedo, J. Demmel, I. Dhillon, J. Dongarra, S. Hammarling, G. Henry, A. Petitet, K. Stanley, D. Walker, and C.R. Whaley, *ScaLAPACK Users' Guide*, Society for Industrial and Applied Mathematics, Philadelphia, PA, 1997 <http://www.netlib.org/scalapack/slug/>`__
