Nuclear norms
=============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Nuclear.cpp>`__

The following routines compute the sum of the singular values. 
This is equivalent to both the KyFan norm with :math:`k=n` and the Schatten 
norm with :math:`p=1`.
Note that the nuclear norm is dual to the two-norm, which is the 
Schatten norm with :math:`p=\infty`.

C++ API
-------

.. cpp:function:: Base<F> NuclearNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> NuclearNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElNuclearNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElNuclearNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElNuclearNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElNuclearNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElNuclearNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElNuclearNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElNuclearNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElNuclearNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricNuclearNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricNuclearNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricNuclearNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricNuclearNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricNuclearNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricNuclearNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricNuclearNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricNuclearNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianNuclearNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianNuclearNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianNuclearNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianNuclearNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
**TODO**
