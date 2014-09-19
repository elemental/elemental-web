Gaussian elimination
====================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/GaussianElimination.cpp>`__

Solves :math:`AX=B` for :math:`X` given a general square nonsingular matrix 
:math:`A` and right-hand side matrix :math:`B`. The solution is computed through
(partially pivoted) Gaussian elimination.

C++ API
-------

.. cpp:function:: void GaussianElimination( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GaussianElimination( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
-----

.. c:function:: ElError ElGaussianElimination_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElGaussianElimination_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElGaussianElimination_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElGaussianElimination_z( ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElGaussianEliminationDist_s( ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElGaussianEliminationDist_d( ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElGaussianEliminationDist_c( ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElGaussianEliminationDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

