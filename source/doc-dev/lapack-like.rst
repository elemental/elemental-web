LAPACK-like linear algebra
**************************

This chapter describes all of the linear algebra operations which are not basic
enough to fall within the BLAS (Basic Linear Algebra Subprograms) framework.
In particular, algorithms which would traditionally have fallen into the 
domain of LAPACK (Linear Algebra PACKage), such as factorizations and 
matrix decompositions, are placed here.

.. toctree::
   :maxdepth: 2

   lapack-like/condense
   lapack-like/factor

   lapack-like/spectral

   lapack-like/funcs

   lapack-like/props
   lapack-like/solve

   lapack-like/perm

   lapack-like/reflect

   lapack-like/util 
   lapack-like/tuning
