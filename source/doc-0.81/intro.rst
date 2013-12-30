Introduction
************

Overview
========
Elemental is a library for distributed-memory dense linear algebra that
draws heavily from the `PLAPACK <http://cs.utexas.edu/users/plapack>`_ approach
of building a graph of matrix distributions with a simple interface for
redistributions (much of the syntax of the library is also inspired from
`FLAME <http://cs.utexas.edu/users/flame>`_). Elemental is also similar in
functionality to `ScaLAPACK <http://netlib.org/scalapack>`_, which is the very
widely used effort towards extending `LAPACK <http://netlib.org/lapack>`_ onto
distributed-memory architectures.
Unlike PLAPACK and ScaLAPACK, Elemental performs all computations using
element-wise, rather than block, matrix distributions (please see the first
journal publication on Elemental, *Elemental: A new framework for distributed
memory dense matrix computations*, for a detailed discussion of this design
choice).
Some of the unique features of Elemental include distributed implementations of:

* Column-pivoted QR and interpolative/skeleton decompositions
* Quadratically Weighted Dynamic Halley iteration for the polar decomposition
* Hermitian matrix functions
* Sign-based Lyapunov/Ricatti/Sylvester solvers

For the sake of objectivity, here are a few reasons why one might want to
use ScaLAPACK or PLAPACK instead:

* This release of Elemental does not yet contain a parallel algorithm for 
  computing Schur decompositions, but ScaLAPACK does.
* Some applications exploit the block distribution format used by ScaLAPACK
  and PLAPACK in order to increase the efficiency of matrix
  construction. Though it is clearly possible to redistribute the matrix into
  an element-wise distribution format after construction, this might add
  an unnecessary level of complexity.
* Elemental is primarily intended to be used from C++, though interfaces to
  other languages, such as C, Fortran 90, and Python, are in various stages of
  development. ScaLAPACK and PLAPACK routines are currently significantly more
  straightforward to call from C and Fortran.

.. note::
   At this point, the vast majority of Elemental's source code is in header 
   files, so do not be surprised by the sparsity of the ``src/`` folder; please
   also look in ``include/``. There were essentially two reasons for moving as 
   much of Elemental as possible into header files:

   1. In practice, most executables only require a small subset of the library, 
      so avoiding the overhead of compiling the entire library beforehand can be
      significant. On the other hand, if one naively builds many such 
      executables with overlapping functionality, then the mainly-header 
      approach becomes slower. 
   2. Though Elemental does not yet fully support computation over arbitrary 
      fields, the vast majority of its pieces do. Moving templated 
      implementations into header files is a necessary step in the process and 
      also allowed for certain templating techniques to exploited in order to 
      simplify the class hierarchy.

Dependencies
============
* Functioning C++03 and ANSI C compilers.
* A working MPI implementation.
* BLAS and LAPACK (ideally version 3.3 or greater) implementations. If 
  a sufficiently up-to-date LAPACK implementation is not provided, then 
  a working F90 compiler is required in order to build Elemental's eigensolvers
  (the tridiagonal eigensolver, `PMRRR <http://code.google.com/p/pmrrr>`_, 
  requires recent LAPACK routines).
* `CMake <http://www.cmake.org>`_ (version 2.8.8 or later).

Elemental should be straightforward to build on Unix-like platforms. 
Building on Microsoft Windows platforms should also be possible with minor 
effort.

License and copyright
=====================
All files distributed with Elemental are made available under the 
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

Most source files contain the copyright notice::

    Copyright (c) 2009-2013, Jack Poulson
    All rights reserved.

For an up-to-date list of contributing authors, please see the 
`AUTHORS file <https://github.com/poulson/Elemental/blob/master/AUTHORS>`__.
