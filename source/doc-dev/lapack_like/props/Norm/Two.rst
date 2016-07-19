Two norms
=========

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Two.cpp>`__

The following routines compute the maximum singular value. This is equivalent 
to the KyFan norm with `k` equal to one and the Schatten norm with 
:math:`p=\infty`.

C++ API
-------

.. cpp:function:: Base<F> TwoNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElTwoNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElTwoNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElTwoNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElTwoNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElTwoNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElTwoNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElTwoNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElTwoNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricTwoNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricTwoNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricTwoNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricTwoNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricTwoNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricTwoNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricTwoNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricTwoNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianTwoNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianTwoNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianTwoNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianTwoNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
**TODO**
