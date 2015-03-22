One norms
=========

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/One.cpp>`__

The following routines compute the maximum :math:`\ell_1` norm of the columns 
of `A`. In the symmetric and Hermitian cases, this is equivalent to the 
:math:`\| \cdot \|_\infty` norm.

C++ API
-------

.. cpp:function:: Base<F> OneNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> OneNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElOneNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElOneNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElOneNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElOneNorm_z( ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElOneNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElOneNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElOneNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElOneNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricOneNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricOneNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricOneNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricOneNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricOneNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricOneNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricOneNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricOneNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianOneNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianOneNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianOneNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianOneNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Python API
----------
**TODO**

