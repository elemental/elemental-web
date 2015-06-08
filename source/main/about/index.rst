.. General introduction to Elemental.

.. _About:

About Elemental
###############

Elemental is an open-source library for distributed-memory dense 
and sparse-direct linear algebra and optimization which builds on top of 
BLAS, LAPACK, and MPI using modern C++ and additionally exposes interfaces to
C and Python (with a Julia interface beginning development).

The development of Elemental has led to a number of 
:doc:`research articles<../citing/index>` and 
a number of related projects, such as the parallel sweeping 
preconditioner, `PSP <http://github.com/poulson/PSP>`__, and a parallel 
algorithm for Low-rank Plus Sparse MRI, `RT-LPS-MRI <http://github.com/poulson/rt-lps-mri>`__.

Unique Features
***************

Elemental supports a wide collection of distributed-memory operations, 
including:

Convex optimization
===================

* Dense and sparse Interior Point Methods for Linear and Quadratic Programs
    - Basis Pursuit
    - Chebyshev Points
    - Dantzig selectors
    - LASSO / Basis Pursuit Denoising
    - Least Absolute Value regression
    - Non-negative Least Squares
    - Support Vector Machines
    - (1D) Total Variation

* Distributed Jordan algebras over products of Second-Order Cones

* Various prototype dense Alternating Direction Method of Multipliers routines
    - Sparse inverse covariance selection
    - Robust Principal Component Analysis

* Prototype alternating direction Non-negative Matrix Factorization

Linear algebra
==============

* Dense and sparse-direct (generalized) Least Squares problems
    - Least Squares / Minimum Length
    - Tikhonov (and ridge) regression
    - Equality-constrained Least Squares
    - General (Gauss-Markov) Linear Models

* High-performance pseudospectral computation and visualization

* Quadratic-time low-rank Cholesky and LU modifications

* Bunch-Kaufman and Bunch-Parlett for accurate symmetric factorization

* LU and Cholesky with full pivoting

* Column-pivoted QR and interpolative/skeleton decompositions

* Quadratically Weighted Dynamic Halley iteration for the polar decomposition

* Many algorithms for Singular-Value soft-Thresholding (SVT)

* Tall-skinny QR decompositions

* Hermitian matrix functions

* Prototype Spectral Divide and Conquer Schur decomposition and Hermitian EVD

* Sign-based Lyapunov/Ricatti/Sylvester solvers

Contributors
************

Project leader: `Jack Poulson <http://web.stanford.edu/~poulson>`__

Active contributors (roughly, within the last year): `Paolo Bientinesi <http://hpac.rwth-aachen.de/~pauldj/>`__, `Jake Bolewski <https://github.com/jakebolewski>`__, `Rodrigo Canales <https://github.com/rocanale>`__, `Jiahao Chen <https://jiahao.github.io>`__, `AJ Friend <http://stanford.edu/~ajfriend/>`__, `Jeff Hammond <http://pcl.intel-research.net/people/jeff.htm>`__, and `Matthias Petschow <http://hpac.rwth-aachen.de/~petschow/>`__. 

Please see `the list of contributors <./contributors.html>`__ for more details 
on current and past contributors.

.. _about_license:

License
*******

All of Elemental is licensed under the 
`New BSD License <http://opensource.org/licenses/BSD-3-Clause>`__,
with the exception of 
`METIS 5.1.0 <http://glaros.dtc.umn.edu/gkhome/metis/metis/overview>`__, 
which is distributed under the (equally permissive)
`Apache License, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0.html>`__.

About these pages
*****************

`This website <http://github.com/elemental/elemental-web.git>`__  was 
created by `Jack Poulson <http://web.stanford.edu/~poulson>`__ by 
checking out a copy of 
`fenics-web <https://bitbucket.org/fenics-project/fenics-web>`__ and slowly 
replacing FEniCS-specific content with the appropriate Elemental content.
The modified source code 
`can be found here <http://github.com/elemental/elemental-web.git>`__.

.. toctree::
   :hidden:

   contributors
