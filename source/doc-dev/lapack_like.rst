LAPACK-like linear algebra
**************************

This chapter describes all of the linear algebra operations which are not basic
enough to fall within the BLAS (Basic Linear Algebra Subprograms) framework.
In particular, algorithms which would traditionally have fallen into the 
domain of LAPACK (Linear Algebra PACKage), such as factorizations and 
matrix decompositions, are placed here.

.. toctree::
   :maxdepth: 2

   lapack_like/condense
   lapack_like/factor

   lapack_like/spectral

   lapack_like/funcs

   lapack_like/props
   lapack_like/solve
   lapack_like/euclidean_min

   lapack_like/perm

   lapack_like/reflect

   lapack_like/util 
