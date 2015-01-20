Introduction
************

Overview
========
Elemental is a library for distributed-memory dense and sparse-direct linear 
algebra that draws heavily from the 
`PLAPACK <http://cs.utexas.edu/users/plapack>`_ approach of building a graph of
matrix distributions with a simple interface for redistributions 
Elemental is also similar in functionality to 
`ScaLAPACK <http://netlib.org/scalapack>`_, which is the very 
widely used effort towards extending `LAPACK <http://netlib.org/lapack>`_ onto 
distributed-memory architectures.
Unlike PLAPACK and ScaLAPACK, Elemental performs virtually all computations 
using element-wise, rather than block, matrix distributions 
(please see the first journal publication on Elemental, 
*Elemental: A new framework for distributed
memory dense matrix computations*, for a detailed discussion of this design 
choice).
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
* Sign-based Lyapunov/Ricatti/Sylvester solvers

Elemental currently supports C++11, C, and Python interfaces, `an R interface is being maintained by Rodrigo Canales <https://github.com/rocanale/R-Elemental>`__
and a Julia interface is under development.
Interfaces to other languages, such as Fortran 90, can be built on top of
the C interface in a straightforward, if not tedious, manner.

Dependencies
============
* Functioning C++11 and ANSI C compilers.
* A working MPI2 implementation
* BLAS and LAPACK (ideally version 3.3 or greater) implementations. 
* `CMake <http://www.cmake.org>`_ (version 2.8.8 or later).

If a sufficiently up-to-date C++11 compiler is used (e.g., recent versions of 
``g++`` or ``clang++``), Elemental should be straightforward to build on 
Unix-like platforms. Building on Microsoft Windows platforms should also be 
possible with minor effort.

License and copyright
=====================
All files distributed with Elemental, with the exception of 
`METIS 5.1.0 <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__, are 
made available under the 
`New BSD license <http://www.opensource.org/licenses/bsd-license.php>`_,
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

Note that 
`METIS 5.1.0 <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__ 
is distributed under the (equally permissive) 
`Apache License, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0.html>`__.

Most source files contain the copyright notice::

    Copyright (c) 2009-2015, Jack Poulson
    All rights reserved.

For an up-to-date list of contributing authors, please see the 
`AUTHORS file <https://github.com/elemental/Elemental/blob/master/AUTHORS>`__.
