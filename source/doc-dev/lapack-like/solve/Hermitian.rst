Hermitian solve
===============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/HermitianSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
-------

.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

C API
-----

.. c:function:: ElError ElHermitianSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElHermitianSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElHermitianSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElHermitianSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )

