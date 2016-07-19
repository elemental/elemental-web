Unpivoted dense LDL
===================
Though Cholesky factorizations are ideal for Hermitian Positive-Definite 
matrices, unpivoted :math:`LDL^T` and :math:`LDL^H` factorizations are 
frequently used for significantly larger classes of matrices, with the most
notable example being Symmetric Quasidefinite matrices, which were introduced
by [Vanderbei1995]_ and subsequently analyzed as a simple rescaling of a 
nonsymmetric positive-definite matrix in [GSS1996]_. While the stability 
properties of unpivoted :math:`LDL^H` factorizations of dense quasidefinite 
matrices are of intrinsic interest, there are significantly more practical 
applications for sparse matrices, where dynamic pivoting incurs typically 
substantially increases both the memory requirements and operation count of a 
factorization. 

.. toctree::
   :maxdepth: 1

   unpivoted/factor
   unpivoted/solve_after
   unpivoted/multiply_after


References
----------
.. [Vanderbei1995] Robert J. Vanderbei, *Symmetric quasi-definite matrices*, SIAM Journal on Optimization, Vol. 5, No. 1, pp. 100--113, 1995. DOI: `http://dx.doi.org/10.1137/0805005 <http://dx.doi.org/10.1137/0805005>`__

.. [GSS1996] Philip E. Gill, Michael A. Saunders, and Joseph R. Shinnerl, *On the stability of Cholesky factorization for symmetric quasidefinite systems*, SIAM Journal on Matrix Analysis and Applications, Vol. 17, No. 1, pp. 35--46, 1996. DOI: `http://dx.doi.org/10.1137/S0895479893252623 <http://dx.doi.org/10.1137/S0895479893252623>`__

`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL.cpp>`__

`C++11 subroutines <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrappers <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrappers <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__

`C++11 test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`C++11 example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__

