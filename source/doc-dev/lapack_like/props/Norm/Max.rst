Max norm
========

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Max.cpp>`__

The following routines compute the maximum absolute value of the matrix entries.

C++ API
-------

.. cpp:function:: Base<T> MaxNorm( const Matrix<T>& A )
.. cpp:function:: Base<T> MaxNorm( const AbstractDistMatrix<T>& A )
.. cpp:function:: Base<T> MaxNorm( const SparseMatrix<T>& A )
.. cpp:function:: Base<T> MaxNorm( const DistSparseMatrix<T>& A )

.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const Matrix<T>& A )
.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<T>& A )
.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const SparseMatrix<T>& A )
.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const DistSparseMatrix<T>& A )

.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const Matrix<T>& A )
.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<T>& A )
.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const SparseMatrix<T>& A )
.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const DistSparseMatrix<T>& A )

C API
-----

.. c:function:: ElError ElMaxNorm_i( ElConstMatrix_i A, ElInt* norm )
.. c:function:: ElError ElMaxNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElMaxNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElMaxNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElMaxNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElMaxNormDist_i( ElConstDistMatrix_i A, ElInt* norm )
.. c:function:: ElError ElMaxNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElMaxNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElMaxNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElMaxNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricMaxNorm_i( ElUpperOrLower uplo, ElConstMatrix_i A, ElInt* norm )
.. c:function:: ElError ElSymmetricMaxNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricMaxNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricMaxNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricMaxNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricMaxNormDist_i( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElInt* norm )
.. c:function:: ElError ElSymmetricMaxNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricMaxNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricMaxNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricMaxNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianMaxNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianMaxNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianMaxNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianMaxNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
**TODO**
