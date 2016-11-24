.. General introduction to Elemental.

.. _About:

About Elemental
###############

Elemental is an open-source library for distributed-memory dense 
and sparse-direct linear algebra and optimization which builds on top of 
BLAS, LAPACK, and MPI using modern C++ and additionally exposes interfaces to
C and Python (with a Julia interface beginning development).

The development of Elemental has led to a number of 
:doc:`research articles <../citing/index>` and 
a number of related projects, such as the parallel sweeping 
preconditioner, `PSP <http://github.com/poulson/PSP>`__, and a parallel 
algorithm for Low-rank Plus Sparse MRI, `RT-LPS-MRI <http://github.com/poulson/rt-lps-mri>`__.

Unique Features
***************

Elemental supports a wide collection of sequential and distributed-memory
operations, including support for dense and sparse-direct linear algebra,
Linear, Quadratic and Second-Order Cone Programming, and lattice reduction.
Furthermore, it supports such functionality for real and complex
single-precision, double-precision, "double-double", "quad-double",
quad-precision, and arbitrary-precision floating-point arithmetic.

The C++11 API is by far the most complete, but a large percentage of the library
is also exposed to C and Python interfaces.
Please see the `README <https://github.com/elemental/Elemental/blob/master/README.md>`__ for an up-to-date list of unique functionality.

..
  This needs to be updated again...
  
  Contributors
  ************
  Project leader: `Jack Poulson <https://github.com/poulson>`__
  
  Active contributors (roughly, within the last year): `Paolo Bientinesi <http://hpac.rwth-aachen.de/~pauldj/>`__, `Jake Bolewski <https://github.com/jakebolewski>`__, `Rodrigo Canales <https://github.com/rocanale>`__, `Jiahao Chen <https://jiahao.github.io>`__, `AJ Friend <http://stanford.edu/~ajfriend/>`__, `Jeff Hammond <http://pcl.intel-research.net/people/jeff.htm>`__, and `Matthias Petschow <http://hpac.rwth-aachen.de/~petschow/>`__. 
  
  Please see `the list of contributors <./contributors.html>`__ for more details 
  on current and past contributors.

.. _about_license:

License
*******

The vast majority of Elemental is licensed under the 
`2-clause BSD License <http://opensource.org/licenses/BSD-2-Clause>`__,
but small pieces are under various other licenses. Please see the
`debian/copyright <https://github.com/elemental/Elemental/blob/master/debian/copyright>`__ file for more details.

About these pages
*****************

`This website <http://github.com/elemental/elemental-web.git>`__  was 
created by `Jack Poulson <https://github.com/poulson>`__ by 
checking out a copy of 
`fenics-web <https://bitbucket.org/fenics-project/fenics-web>`__ and slowly 
replacing FEniCS-specific content with the appropriate Elemental content.
The modified source code 
`can be found here <http://github.com/elemental/elemental-web.git>`__.

.. toctree::
   :hidden:

   contributors
