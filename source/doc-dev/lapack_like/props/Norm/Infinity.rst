Infinity norms
==============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Infinity.cpp>`__

The following routines compute the maximum :math:`\ell_1` norm of the rows of 
`A`. In the symmetric and Hermitian cases, this is equivalent to the 
:math:`\|\cdot \|_1` norm.

C++ API
-------

.. cpp:function:: Base<F> InfinityNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElInfinityNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElInfinityNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElInfinityNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElInfinityNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElInfinityNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElInfinityNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElInfinityNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElInfinityNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricInfinityNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricInfinityNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricInfinityNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricInfinityNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricInfinityNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricInfinityNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricInfinityNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricInfinityNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianInfinityNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianInfinityNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianInfinityNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianInfinityNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
.. py:function:: InfinityNorm(A)
.. py:function:: HermitianInfinityNorm(A,uplo=LOWER)
.. py:function:: SymmetricInfinityNorm(A,uplo=LOWER)
