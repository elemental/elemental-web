Frobenius norms
===============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Frobenius.cpp>`__

The following routines return the :math:`\ell_2` norm of the singular values 
(the Schatten norm with :math:`p=2`), which can be cheaply computed as the 
:math:`\ell_2` norm of :math:`\text{vec}(A)`.

C++ API
-------

.. cpp:function:: Base<F> FrobeniusNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const SparseMatrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const DistSparseMatrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const DistMultiVec<F>& A )

.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const SparseMatrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const DistSparseMatrix<F>& A )

.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const SparseMatrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const DistSparseMatrix<F>& A )

C API
-----

.. c:function:: ElError ElFrobeniusNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElFrobeniusNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElFrobeniusNormSparse_s( ElConstSparseMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNormSparse_d( ElConstSparseMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNormSparse_c( ElConstSparseMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNormSparse_z( ElConstSparseMatrix_z A, double* norm )

.. c:function:: ElError ElFrobeniusNormDistSparse_s( ElConstDistSparseMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNormDistSparse_d( ElConstDistSparseMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNormDistSparse_c( ElConstDistSparseMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNormDistSparse_z( ElConstDistSparseMatrix_z A, double* norm )

.. c:function:: ElError ElFrobeniusNormDistMultiVec_s( ElConstDistMultiVec_s A, float* norm )
.. c:function:: ElError ElFrobeniusNormDistMultiVec_d( ElConstDistMultiVec_d A, double* norm )
.. c:function:: ElError ElFrobeniusNormDistMultiVec_c( ElConstDistMultiVec_c A, float* norm )
.. c:function:: ElError ElFrobeniusNormDistMultiVec_z( ElConstDistMultiVec_z A, double* norm )

.. c:function:: ElError ElSymmetricFrobeniusNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricFrobeniusNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricFrobeniusNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricFrobeniusNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricFrobeniusNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricFrobeniusNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricFrobeniusNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricFrobeniusNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianFrobeniusNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianFrobeniusNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianFrobeniusNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianFrobeniusNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
.. py:function:: FrobeniusNorm(A)
.. py:function:: HermitianFrobeniusNorm(A,uplo=LOWER)
.. py:function:: SymmetricFrobeniusNorm(A,uplo=LOWER)
