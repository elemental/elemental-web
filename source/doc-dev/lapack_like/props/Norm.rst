Matrix norms
============

Specialized interfaces
----------------------

.. toctree::
   :maxdepth: 1

   Norm/Entrywise
   Norm/Frobenius
   Norm/KyFan
   Norm/Infinity
   Norm/Max
   Norm/Nuclear
   Norm/One
   Norm/Schatten
   Norm/Two
   Norm/TwoEstimate
   Norm/Zero

Vanilla interface
-----------------
`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm.cpp>`__

The following routines can return either
:math:`\|A\|_1`, :math:`\|A\|_\infty`, :math:`\|A\|_F` (the Frobenius norm),
the maximum entrywise norm, :math:`\|A\|_2`, or :math:`\|A\|_*`
(the nuclear/trace norm) of fully-populated matrices.

C++ API
^^^^^^^

.. cpp:function:: Base<F> Norm( const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> Norm( const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

C API
^^^^^

.. c:function:: ElError ElNorm_s( ElConstMatrix_s A, ElNormType type, float* norm )
.. c:function:: ElError ElNorm_d( ElConstMatrix_d A, ElNormType type, double* norm )
.. c:function:: ElError ElNorm_c( ElConstMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElNorm_z( ElConstMatrix_z A, ElNormType type, double* norm )
.. c:function:: ElError ElNormDist_s( ElConstDistMatrix_s A, ElNormType type, float* norm )
.. c:function:: ElError ElNormDist_d( ElConstDistMatrix_d A, ElNormType type, double* norm )
.. c:function:: ElError ElNormDist_c( ElConstDistMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElNormDist_z( ElConstDistMatrix_z A, ElNormType type, double* norm )

.. c:function:: ElError ElSymmetricNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElNormType type, float* norm )
.. c:function:: ElError ElSymmetricNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElNormType type, double* norm )
.. c:function:: ElError ElSymmetricNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElSymmetricNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElNormType type, double* norm )
.. c:function:: ElError ElSymmetricNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElNormType type, float* norm )
.. c:function:: ElError ElSymmetricNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElNormType type, double* norm )
.. c:function:: ElError ElSymmetricNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElSymmetricNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElNormType type, double* norm )

.. c:function:: ElError ElHermitianNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElHermitianNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElNormType type, double* norm )
.. c:function:: ElError ElHermitianNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElNormType type, float* norm )
.. c:function:: ElError ElHermitianNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElNormType type, double* norm )

Python API
^^^^^^^^^^
.. py:function:: Norm(A,normType=FROBENIUS_NORM)
.. py:function:: HermitianNorm(A,uplo=LOWER,normType=FROBENIUS_NORM)
.. py:function:: SymmetricNorm(A,conjugate=False,uplo=LOWER,normType=FROBENIUS_NORM)
