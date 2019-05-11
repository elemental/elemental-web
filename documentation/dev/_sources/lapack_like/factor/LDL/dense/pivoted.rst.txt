Pivoted dense LDL
=================
The following routines return a pivoted LDL factorization, where the vector 
:math:`p` contains the column indices of the nonzero entries of the permutation
matrix :math:`P` such that :math:`PAP^T` equals either :math:`LDL^T` or 
:math:`LDL^H`, where :math:`D` is quasi-diagonal. 
The Bunch-Kaufman pivoting rules are used within a higher-performance 
blocked algorithm, whereas the Bunch-Parlett strategy uses an unblocked, but 
typically more accurate, algorithm.

.. toctree::
   :maxdepth: 1

   pivoted/factor
   pivoted/solve_after
   pivoted/multiply_after
   pivoted/inertia_after

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL.cpp>`__

`C++11 test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`C++11 example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__
