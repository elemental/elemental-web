Matrix norms
------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props/Norm.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack_like/props/Norm>`__

The following routines can return either
:math:`\|A\|_1`, :math:`\|A\|_\infty`, :math:`\|A\|_F` (the Frobenius norm),
the maximum entrywise norm, :math:`\|A\|_2`, or :math:`\|A\|_*`
(the nuclear/trace norm) of fully-populated matrices.

General
^^^^^^^
Compute a norm of a fully-populated or implicitly symmetric/Hermitian (with 
the data stored in the specified triangle) matrix. 

C++ API
"""""""

.. cpp:function:: Base<F> Norm( const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> Norm( const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> SymmetricNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const Matrix<F>& A, NormType type=FROBENIUS_NORM )
.. cpp:function:: Base<F> HermitianNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, NormType type=FROBENIUS_NORM )

C API
"""""

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

Entrywise
^^^^^^^^^
The following routines return the :math:`\ell_p` norm of the columns of `A` 
stacked into a single vector, i.e., :math:`\| \text{vec}(A) \|_p`. 
Note that the Frobenius norm corresponds to the :math:`p=2` case.

C++ API
"""""""

.. cpp:function:: Base<F> EntrywiseNorm( const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> EntrywiseNorm( const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianEntrywiseNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

C API
"""""

.. c:function:: ElError ElEntrywiseNorm_s( ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNorm_d( ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNorm_c( ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNorm_z( ElConstMatrix_z A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormDist_s( ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDist_d( ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElEntrywiseNormDist_c( ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElEntrywiseNormDist_z( ElConstDistMatrix_z A, double p, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double p, double* norm )

.. c:function:: ElError ElHermitianEntrywiseNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double p, double* norm )
.. c:function:: ElError ElHermitianEntrywiseNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElHermitianEntrywiseNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double p, double* norm )

Entrywise one-norm
^^^^^^^^^^^^^^^^^^
The following routines return the :math:`\ell_1` norm of :math:`\text{vec}(A)`. 

C++ API
"""""""

.. cpp:function:: Base<F> EntrywiseOneNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> EntrywiseOneNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricEntrywiseOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricEntrywiseOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianEntrywiseOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianEntrywiseOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElEntrywiseOneNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElEntrywiseOneNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElEntrywiseOneNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElEntrywiseOneNorm_z( ElConstMatrix_z A, double* norm )
.. c:function:: ElError ElEntrywiseOneNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElEntrywiseOneNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElEntrywiseOneNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElEntrywiseOneNormDist_z( ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElSymmetricEntrywiseOneNorm_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNorm_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNormDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNormDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElSymmetricEntrywiseOneNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

.. c:function:: ElError ElHermitianEntrywiseOneNorm_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianEntrywiseOneNorm_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* norm )
.. c:function:: ElError ElHermitianEntrywiseOneNormDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElHermitianEntrywiseOneNormDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* norm )

Frobenius norm
^^^^^^^^^^^^^^
The following routines return the :math:`\ell_2` norm of the singular values 
(the Schatten norm with :math:`p=2`), which can be cheaply computed as the 
:math:`\ell_2` norm of :math:`\text{vec}(A)`.

C++ API
"""""""

.. cpp:function:: Base<F> FrobeniusNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianFrobeniusNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElFrobeniusNorm_s( ElConstMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNorm_d( ElConstMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNorm_c( ElConstMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNorm_z( ElConstMatrix_z A, double* norm )
.. c:function:: ElError ElFrobeniusNormDist_s( ElConstDistMatrix_s A, float* norm )
.. c:function:: ElError ElFrobeniusNormDist_d( ElConstDistMatrix_d A, double* norm )
.. c:function:: ElError ElFrobeniusNormDist_c( ElConstDistMatrix_c A, float* norm )
.. c:function:: ElError ElFrobeniusNormDist_z( ElConstDistMatrix_z A, double* norm )

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

Ky-Fan norm
^^^^^^^^^^^
The following routines compute the sum of the largest `k` singular values.

C++ API
"""""""

.. cpp:function:: Base<F> KyFanNorm( const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> KyFanNorm( const AbstractDistMatrix<F>& A, Int k )

.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> SymmetricKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Int k )

.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const Matrix<F>& A, Int k )
.. cpp:function:: Base<F> HermitianKyFanNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Int k )

C API
"""""

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

Infinity norm
^^^^^^^^^^^^^
The following routines compute the maximum :math:`\ell_1` norm of the rows of 
`A`. In the symmetric and Hermitian cases, this is equivalent to the 
:math:`\|\cdot \|_1` norm.

C++ API
"""""""

.. cpp:function:: Base<F> InfinityNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianInfinityNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

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

Max norm
^^^^^^^^
The following routines compute the maximum absolute value of the matrix entries.

C++ API
"""""""

.. cpp:function:: Base<T> MaxNorm( const Matrix<T>& A )
.. cpp:function:: Base<T> MaxNorm( const AbstractDistMatrix<T>& A )

.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const Matrix<T>& A )
.. cpp:function:: Base<T> SymmetricMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<T>& A )

.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const Matrix<T>& A )
.. cpp:function:: Base<T> HermitianMaxNorm( UpperOrLower uplo, const AbstractDistMatrix<T>& A )

C API
"""""

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

Nuclear norm
^^^^^^^^^^^^
The following routines compute the sum of the singular values. 
This is equivalent to both the KyFan norm with :math:`k=n` and the Schatten 
norm with :math:`p=1`.
Note that the nuclear norm is dual to the two-norm, which is the 
Schatten norm with :math:`p=\infty`.

C++ API
"""""""

.. cpp:function:: Base<F> NuclearNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> NuclearNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianNuclearNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

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

One norm
^^^^^^^^
The following routines compute the maximum :math:`\ell_1` norm of the columns 
of `A`. In the symmetric and Hermitian cases, this is equivalent to the 
:math:`\| \cdot \|_\infty` norm.

C++ API
"""""""

.. cpp:function:: Base<F> OneNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> OneNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianOneNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

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

Schatten norm
^^^^^^^^^^^^^
The following routines compute the :math:`\ell_p` norm of the singular values.

C++ API
"""""""

.. cpp:function:: Base<F> SchattenNorm( const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SchattenNorm( const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

C API
"""""

.. c:function:: ElError ElSchattenNorm_s( ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSchattenNorm_d( ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSchattenNorm_c( ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSchattenNorm_z( ElConstMatrix_z A, double p, double* norm )
.. c:function:: ElError ElSchattenNormDist_s( ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSchattenNormDist_d( ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSchattenNormDist_c( ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSchattenNormDist_z( ElConstDistMatrix_z A, double p, double* norm )

Two norm
^^^^^^^^
The following routines compute the maximum singular value. This is equivalent 
to the KyFan norm with `k` equal to one and the Schatten norm with 
:math:`p=\infty`.

C++ API
"""""""

.. cpp:function:: Base<F> TwoNorm( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoNorm( const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> SymmetricTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HermitianTwoNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

C API
"""""

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

Zero "norm"
^^^^^^^^^^^
The following routines return the number of nonzero entries in the matrix.
This operation is often casually referred to as the zero "norm".

C++ API
"""""""

.. cpp:function:: Int ZeroNorm( const Matrix<T>& A )
.. cpp:function:: Int ZeroNorm( const AbstractDistMatrix<T>& A )

C API
"""""

.. c:function:: ElError ElZeroNorm_i( ElConstMatrix_i, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_s( ElConstMatrix_s, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_d( ElConstMatrix_d, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_c( ElConstMatrix_c, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_z( ElConstMatrix_z, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_i( ElConstDistMatrix_i, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_s( ElConstDistMatrix_s, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_d( ElConstDistMatrix_d, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_c( ElConstDistMatrix_c, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_z( ElConstDistMatrix_z, ElInt* numNonzero )

Two-norm estimates
^^^^^^^^^^^^^^^^^^
The following routines return an estimate for the two-norm which should be 
accurate within a factor of :math:`n` times the specified tolerance.

C++ API
"""""""

.. cpp:function:: Base<F> TwoNormEstimate( const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> TwoNormEstimate( const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

.. cpp:function:: Base<F> SymmetricTwoNormEstimate( UpperOrLower uplo, const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> SymmetricTwoNormEstimate( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

.. cpp:function:: Base<F> HermitianTwoNormEstimate( UpperOrLower uplo, const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> HermitianTwoNormEstimate( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

C API
"""""

.. c:function:: ElError ElTwoNormEstimate_s( ElConstMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_d( ElConstMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_c( ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_z( ElConstMatrix_z A, double tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_s( ElConstDistMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_d( ElConstDistMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_c( ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_z( ElConstDistMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElSymmetricTwoNormEstimate_s( ElUpperOrLower uplo, ElConstMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_d( ElUpperOrLower uplo, ElConstMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_c( ElUpperOrLower uplo, ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_z( ElUpperOrLower uplo, ElConstMatrix_z A, double tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElHermitianTwoNormEstimate_c( ElUpperOrLower uplo, ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElHermitianTwoNormEstimate_z( ElUpperOrLower uplo, ElConstMatrix_z A, double tol, ElInt maxIts )
.. c:function:: ElError ElHermitianTwoNormEstimateDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElHermitianTwoNormEstimateDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double tol, ElInt maxIts )
