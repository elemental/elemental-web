Symmetric solve
===============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/solve/SymmetricSolve.cpp>`__

Solve :math:`AX=B`, :math:`A^T X = B`, or :math:`A^H X = B` for :math:`X` 
given a symmetric or Hermitian matrix :math:`A` and a right-hand side matrix
:math:`B` using Bunch-Kaufman.

.. note::

   Only the lower-triangular storage case (``uplo=LOWER``) is supported by
   the following routines.

C++ API
-------

.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, Matrix<F>& A, Matrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricSolve( UpperOrLower uplo, Orientation orientation, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

C API
-----

.. c:function:: ElError ElSymmetricSolve_s( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSymmetricSolve_d( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSymmetricSolve_c( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElSymmetricSolve_z( ElUpperOrLower uplo, ElOrientation orientation, ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElSymmetricSolveDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSymmetricSolveDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSymmetricSolveDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElSymmetricSolveDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElDistMatrix_z A, ElDistMatrix_z B )
