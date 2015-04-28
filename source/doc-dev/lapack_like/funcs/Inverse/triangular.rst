Triangular
==========
Inverts a (possibly unit-diagonal) triangular matrix in-place. If
`diag` is set to `UNIT`, then `A` is treated as having ones on its diagonal.

Python API
----------
.. py:function:: TriangularInverse(uplo,diag,A)

C++ API
-------
.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<F>& A )
.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<F>& A )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElTriangularInverse_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A )
.. c:function:: ElError ElTriangularInverseDist_s( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_s A )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElTriangularInverse_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A )
.. c:function:: ElError ElTriangularInverseDist_d( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_d A )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElTriangularInverse_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A )
.. c:function:: ElError ElTriangularInverseDist_c( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_c A )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElTriangularInverse_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A )
.. c:function:: ElError ElTriangularInverseDist_z( ElUpperOrLower uplo, ElUnitOrNonUnit diag, ElMatrix_z A )
