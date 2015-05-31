Unpivoted dense LDL
===================
Though Cholesky factorization is ideal for HPD matrices, unpivoted `LDL` 
factorization naturally applies to a slightly larger, but harder to define, 
class of matrices. Upon successful completion of the factorization,
a lower-triangular (with unit diagonal) :math:`L` and diagonal matrix :math:`D`,
such that :math:`A = L D L^H` or :math:`A = L D L^T`, will be returned in the 
lower triangle of :math:`A`.
If a zero pivot is attempted, then a :cpp:type:`ZeroPivotException` will 
be thrown.

.. toctree::
   :maxdepth: 1

   unpivoted/factor
   unpivoted/solve_after
   unpivoted/multiply_after


References
----------
`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__

