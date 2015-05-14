Reduction to condensed form
===========================
Computing the eigenvalues or singular values of a matrix, as a general rule,
boils down to an iterative procedure. Naive applications of this iterative
algorithm would often both require :math:`O(n^4)` work for :math:`n \times n`
matrices and be less numerically stable than first spending :math:`O(n^3)` work
to *condense* the matrix to a form where each of roughly :math:`O(n)` iterations
requires at most :math:`O(n^2)` work. In the case of a full eigenvalue 
decomposition of a Hermitian matrix, a similarity transformation composed of 
Householder transformations is applied to condense the matrix down to 
real symmetric tridiagonal form, where an iterative algorithm can be quickly
(read: in at most cubic time) applied.
Similarly, it is standard practice to condense a general matrix to bidiagonal 
form in order to compute its Singular Value Decomposition, and to reduce a 
general square matrix to upper Hessenberg form in order to compute its Schur
decomposition. In each of these cases, it is possible cast a significant portion
of the reduction to condensed form into high-performance 
matrix-matrix multiplications [DSH1989]_.

.. toctree::
   :maxdepth: 1

   condense/HermitianTridiag
   condense/Hessenberg
   condense/Bidiag

References
----------
`C++ Header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/condense.hpp>`__

`C Header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/condense.h>`__

`Python wrappers <https://github.com/elemental/Elemental/blob/master/python/lapack_like/condense.py>`__

.. [DSH1989] Jack J. Dongarra, Danny C. Sorensen, and Sven J. Hammarling, *Block reduction of matrices to condensed forms for eigenvalue computations*, Journal of Computational and Applied Mathematics, Vol. 27, Issues 1--2, pp. 215--227, 1989. DOI: `http://dx.doi.org/10.1016/0377-0427(89)90367-1 <http://dx.doi.org/10.1016/0377-0427(89)90367-1>`__
