Ky-Fan norms
============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/KyFan.cpp>`__

The following routines compute the sum of the largest `k` singular values.

C++ API
-------

.. cpp:function:: Base<F> KyFanNorm( const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> KyFanNorm( const AbstractDistMatrix<F>& A, Int k )

.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Int k )

.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Int k )

C API
-----

.. c:function:: ElError ElKyFanNorm_s( ElConstMatrix_s A, ElInt k, float* norm )
.. c:function:: ElError ElKyFanNorm_d( ElConstMatrix_d A, ElInt k, double* norm )
.. c:function:: ElError ElKyFanNorm_c( ElConstMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElKyFanNorm_z( ElConstMatrix_z A, ElInt k, double* norm )

.. c:function:: ElError ElKyFanNormDist_s( ElConstDistMatrix_s A, ElInt k, float* norm )
.. c:function:: ElError ElKyFanNormDist_d( ElConstDistMatrix_d A, ElInt k, double* norm )
.. c:function:: ElError ElKyFanNormDist_c( ElConstDistMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElKyFanNormDist_z( ElConstDistMatrix_z A, ElInt k, double* norm )

.. c:function:: ElError ElSymmetricKyFanNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElInt k, float* norm )
.. c:function:: ElError ElSymmetricKyFanNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElInt k, double* norm )
.. c:function:: ElError ElSymmetricKyFanNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElSymmetricKyFanNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElInt k, double* norm )

.. c:function:: ElError ElSymmetricKyFanNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElInt k, float* norm )
.. c:function:: ElError ElSymmetricKyFanNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElInt k, double* norm )
.. c:function:: ElError ElSymmetricKyFanNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElSymmetricKyFanNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElInt k, double* norm )

.. c:function:: ElError ElHermitianKyFanNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElHermitianKyFanNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElInt k, double* norm )
.. c:function:: ElError ElHermitianKyFanNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElInt k, float* norm )
.. c:function:: ElError ElHermitianKyFanNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElInt k, double* norm )

Python API
----------
**TODO**
