Entrywise norms
===============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Entrywise.cpp>`__

The following routines return the :math:`\ell_p` norm of the columns of `A` 
stacked into a single vector, i.e., :math:`\| \text{vec}(A) \|_p`. 
Note that the Frobenius norm corresponds to the :math:`p=2` case.

C++ API
-------

.. cpp:function:: Base<F> EntrywiseNorm( const Matrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> EntrywiseNorm( const AbstractDistMatrix<F>& A, Base<F> p=1 )

.. cpp:function:: Base<F> EntrywiseNorm( const SparseMatrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> EntrywiseNorm( const DistSparseMatrix<F>& A, Base<F> p=1 )

.. cpp:function:: Base<F> EntrywiseNorm( const DistMultiVec<F>& A, Base<F> p=1 )

.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const SparseMatrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const DistSparseMatrix<F>& A, Base<F> p=1 )

.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const SparseMatrix<F>& A, Base<F> p=1 )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const DistSparseMatrix<F>& A, Base<F> p=1 )

C API
-----

.. c:function:: ElError ElEntrywiseNorm_s( ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNorm_d( ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNorm_c( ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNorm_z( ElConstMatrix_z A, double p, double* norm )

.. c:function:: ElError ElEntrywiseNormDist_s( ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDist_d( ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormDist_c( ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDist_z( ElConstDistMatrix_z A, double p, double* norm )

.. c:function:: ElError ElEntrywiseNormSparse_s( ElConstSparseMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormSparse_d( ElConstSparseMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormSparse_c( ElConstSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormSparse_z( ElConstSparseMatrix_z A, double p, double* norm )

.. c:function:: ElError ElEntrywiseNormDistSparse_s( ElConstDistSparseMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDistSparse_d( ElConstDistSparseMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormDistSparse_c( ElConstDistSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDistSparse_z( ElConstDistSparseMatrix_z A, double p, double* norm )

.. c:function:: ElError ElEntrywiseNormDistMultiVec_s( ElConstDistMultiVec_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDistMultiVec_d( ElConstDistMultiVec_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormDistMultiVec_c( ElConstDistMultiVec_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDistMultiVec_z( ElConstDistMultiVec_z A, double p, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double p, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double p, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseNormSparse_s( ElUpperOrLower uplo, ElConstSparseMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormSparse_d( ElUpperOrLower uplo, ElConstSparseMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormSparse_c( ElUpperOrLower uplo, ElConstSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormSparse_z( ElUpperOrLower uplo, ElConstSparseMatrix_z A, double p, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseNormDistSparse_s( ElUpperOrLower uplo, ElConstDistSparseMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDistSparse_d( ElUpperOrLower uplo, ElConstDistSparseMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDistSparse_c( ElUpperOrLower uplo, ElConstDistSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDistSparse_z( ElUpperOrLower uplo, ElConstDistSparseMatrix_z A, double p, double* norm )

.. c:function:: ElError ElHermitianEntrywiseNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double p, double* norm )

.. c:function:: ElError ElHermitianEntrywiseNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double p, double* norm )

.. c:function:: ElError ElHermitianEntrywiseNormSparse_c( ElUpperOrLower uplo, ElConstSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNormSparse_z( ElUpperOrLower uplo, ElConstSparseMatrix_z A, double p, double* norm )

.. c:function:: ElError ElHermitianEntrywiseNormDistSparse_c( ElUpperOrLower uplo, ElConstDistSparseMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNormDistSparse_z( ElUpperOrLower uplo, ElConstDistSparseMatrix_z A, double p, double* norm )

Python API
----------
.. py:function:: EntrywiseNorm(A,p=1)
.. py:function:: HermitianEntrywiseNorm(A,p=1,uplo=LOWER)
.. py:function:: SymmetricEntrywiseNorm(A,p=1,uplo=LOWER)
