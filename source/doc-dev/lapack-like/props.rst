Matrix properties
=================

Condition number
----------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Condition.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Condition>`__

The condition number of a matrix with respect to a particular norm is

.. math::

   \kappa(A) = \|A\| \|A^{-1}\|,

with the most common choice being the matrix two-norm.

General
^^^^^^^
Returns the condition number with respect to the specified norm 
(one, two, or Frobenius).

C++ API
"""""""

.. cpp:function:: Base<F> Condition( const Matrix<F>& A, NormType type=TWO_NORM )
.. cpp:function:: Base<F> Condition( const AbstractDistMatrix<F>& A, NormType type=TWO_NORM )

C API
"""""

.. c:function:: ElError ElCondition_s( ElConstMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_d( ElConstMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElCondition_c( ElConstMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_z( ElConstMatrix_z A, ElNormType normType, double* cond )
.. c:function:: ElError ElConditionDist_s( ElConstDistMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_d( ElConstDistMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElConditionDist_c( ElConstDistMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_z( ElConstDistMatrix_z A, ElNormType normType, double* cond )

Frobenius norm
^^^^^^^^^^^^^^
Returns the condition number with respect to the Frobenius norm.

C++ API
"""""""

.. cpp:function:: Base<F> FrobeniusCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElFrobeniusCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElFrobeniusConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_z( ElConstDistMatrix_z A, double* cond )

Infinity norm
^^^^^^^^^^^^^
Returns the condition number with respect to the infinity norm.

C++ API
"""""""

.. cpp:function:: Base<F> InfinityCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElInfinityCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElInfinityCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElInfinityCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElInfinityCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElInfinityConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElInfinityConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElInfinityConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElInfinityConditionDist_z( ElConstDistMatrix_z A, double* cond )

Max norm
^^^^^^^^
Returns the condition number with respect to the entrywise maximum norm.

C++ API
"""""""

.. cpp:function:: Base<F> MaxCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> MaxCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElMaxCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElMaxCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElMaxCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElMaxCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElMaxConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElMaxConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElMaxConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElMaxConditionDist_z( ElConstDistMatrix_z A, double* cond )

One norm
^^^^^^^^
Returns the condition number with respect to the one norm.

C++ API
"""""""

.. cpp:function:: Base<F> OneCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> OneCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElOneCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElOneCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElOneCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElOneCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElOneConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElOneConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElOneConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElOneConditionDist_z( ElConstDistMatrix_z A, double* cond )

Two norm
^^^^^^^^
Returns the condition number with respect to the two norm.

C++ API
"""""""

.. cpp:function:: Base<F> TwoCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoCondition( const AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElTwoCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElTwoCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElTwoCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElTwoCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElTwoConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElTwoConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElTwoConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElTwoConditionDist_z( ElConstDistMatrix_z A, double* cond )

Determinant
-----------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Determinant.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Determinant>`__

Though there are many different possible definitions of the determinant of a 
matrix :math:`A \in \mathbb{F}^{n \times n}`, the simplest one is in terms of 
the product of the eigenvalues (including multiplicity):

.. math::

   \mbox{det}(A) = \prod_{i=0}^{n-1} \lambda_i.

General
^^^^^^^

Since :math:`\mbox{det}(AB)=\mbox{det}(A)\mbox{det}(B)`, we can compute the 
determinant of an arbitrary matrix in :math:`\mathcal{O}(n^3)` work by 
computing its LU decomposition (with partial pivoting), :math:`PA=LU`, 
recognizing that :math:`\mbox{det}(P)=\pm 1` 
(the *signature* of the permutation), and computing

.. math::

   \mbox{det}(A) = \mbox{det}(P)\mbox{det}(L)\mbox{det}(U) 
                 = \mbox{det}(P) \prod_{i=0}^{n-1} \upsilon_{i,i}
                 = \pm \prod_{i=0}^{n-1} \upsilon_{i,i},

where :math:`\upsilon_{i,i}` is the i'th diagonal entry of :math:`U`.

C++ API
"""""""

.. cpp:function:: F Determinant( const Matrix<F>& A )
.. cpp:function:: F Determinant( const AbstractDistMatrix<F>& A )
.. cpp:function:: F Determinant( Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: F Determinant( AbstractDistMatrix<F>& A, bool canOverwrite=false )

   Return the determinant of the (fully populated) square matrix `A`.
   Some of the variants allow for overwriting the input matrix in order to 
   avoid forming another temporary matrix.

.. cpp:function:: SafeProduct<F> SafeDeterminant( const Matrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeDeterminant( const AbstractDistMatrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeDeterminant( Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: SafeProduct<F> SafeDeterminant( AbstractDistMatrix<F>& A, bool canOverwrite=false )

   Return the determinant of the square matrix `A` in an expanded form 
   which is less likely to over/under-flow.

.. cpp:type:: SafeProduct<F>

   Represents the product of `n` values as :math:`\rho \exp(\kappa n)`, 
   where :math:`|\rho| \le 1` and :math:`\kappa \in \mathbb{R}`.

   .. cpp:member:: F rho

      For nonzero values, `rho` is the modulus and lies *on* the unit 
      circle; in order to represent a value that is precisely zero, `rho` 
      is set to zero.

   .. cpp:member:: Base<F> kappa

      `kappa` can be an arbitrary real number.

   .. cpp:member:: Int n

      The number of values in the product.

C API
"""""

.. c:function:: ElError ElDeterminant_s( ElConstMatrix_s A, float* det )
.. c:function:: ElError ElDeterminant_d( ElConstMatrix_d A, double* det )
.. c:function:: ElError ElDeterminant_c( ElConstMatrix_c A, complex_float* det )
.. c:function:: ElError ElDeterminant_z( ElConstMatrix_z A, complex_double* det )
.. c:function:: ElError ElDeterminantDist_s( ElConstDistMatrix_s A, float* det )
.. c:function:: ElError ElDeterminantDist_d( ElConstDistMatrix_d A, double* det )
.. c:function:: ElError ElDeterminantDist_c( ElConstDistMatrix_c A, complex_float* det )
.. c:function:: ElError ElDeterminantDist_z( ElConstDistMatrix_z A, complex_double* det )

   Return the determinant of the (fully populated) square matrix `A`.

.. c:function:: ElError ElSafeDeterminant_s( ElConstMatrix_s A, ElSafeProduct_s* det )
.. c:function:: ElError ElSafeDeterminant_d( ElConstMatrix_d A, ElSafeProduct_d* det )
.. c:function:: ElError ElSafeDeterminant_c( ElConstMatrix_c A, ElSafeProduct_c* det )
.. c:function:: ElError ElSafeDeterminant_z( ElConstMatrix_z A, ElSafeProduct_z* det )
.. c:function:: ElError ElSafeDeterminantDist_s( ElConstDistMatrix_s A, ElSafeProduct_s* det )
.. c:function:: ElError ElSafeDeterminantDist_d( ElConstDistMatrix_d A, ElSafeProduct_d* det )
.. c:function:: ElError ElSafeDeterminantDist_c( ElConstDistMatrix_c A, ElSafeProduct_c* det )
.. c:function:: ElError ElSafeDeterminantDist_z( ElConstDistMatrix_z A, ElSafeProduct_z* det )

   Return the determinant of the (fully populated) square matrix `A` in an 
   expanded form which helps prevent under/overflow.

HPD
^^^
A version of the above determinant specialized for Hermitian positive-definite
matrices (which will therefore have all positive eigenvalues and a positive 
determinant).

C++ API
"""""""

.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: Base<F> HPDDeterminant( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool canOverwrite=false )

   Return the determinant of the (fully populated) Hermitian positive-definite
   matrix `A`.
   Some of the variants allow for overwriting the input matrix in order to 
   avoid forming another temporary matrix.

.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: SafeProduct<F> SafeHPDDeterminant( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool canOverwrite=false )

   Return the determinant of the Hermitian positive-definite matrix `A` in an 
   expanded form which is less likely to over/under-flow.

C API
"""""

.. c:function:: ElError ElHPDDeterminant_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* det )
.. c:function:: ElError ElHPDDeterminant_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* det )
.. c:function:: ElError ElHPDDeterminant_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* det )
.. c:function:: ElError ElHPDDeterminant_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* det )
.. c:function:: ElError ElHPDDeterminantDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* det )
.. c:function:: ElError ElHPDDeterminantDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* det )
.. c:function:: ElError ElHPDDeterminantDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* det )
.. c:function:: ElError ElHPDDeterminantDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* det )

   Return the determinant of the (fully populated) Hermitian positive-definite
   matrix `A`.

.. c:function:: ElError ElHPDSafeDeterminant_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElSafeProduct_s* det )
.. c:function:: ElError ElHPDSafeDeterminant_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElSafeProduct_d* det )
.. c:function:: ElError ElHPDSafeDeterminant_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElSafeProduct_s* det )
.. c:function:: ElError ElHPDSafeDeterminant_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElSafeProduct_d* det )
.. c:function:: ElError ElHPDSafeDeterminantDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElSafeProduct_s* det )
.. c:function:: ElError ElHPDSafeDeterminantDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElSafeProduct_d* det )
.. c:function:: ElError ElHPDSafeDeterminantDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElSafeProduct_s* det )
.. c:function:: ElError ElHPDSafeDeterminantDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElSafeProduct_d* det )

   Return the determinant of the Hermitian positive-definite matrix `A` in an 
   expanded form which is less likely to over/under-flow.

Matrix norms
------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Norm.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Norm>`__

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

Pseudospectra
-------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Pseudospectra.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Pseudospectra>`__

`Pseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/Pseudospectra.cpp>`__

`ChunkedPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/ChunkedPseudospectra.cpp>`__

`TriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/TriangularPseudospectra.cpp>`__

`ChunkedTriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/ChunkedTriangularPseudospectra.cpp>`__

The :math:`\epsilon`-*pseudospectrum* of a square matrix :math:`A` is the set
of all shifts :math:`z` such that :math:`\hat A - z` is singular for some
:math:`\hat A` such that :math:`\| \hat A - A \|_2 < \epsilon`. In other
words, :math:`z` is in the :math:`\epsilon`-pseudospectrum of :math:`A` if
the smallest singular value of :math:`A - z` is less than :math:`\epsilon`.

Elemental currently supports two methods for computing pseudospectra: 
the first is a high-performance improvement of Shiu-Hong Lui's 
triangularization followed by inverse iteration approach suggested in
*Computation of pseudospectra by continuation* (please see
Trefethen's *Computation of pseudospectra* for a comprehensive review).
In particular, Elemental begins by computing the Schur decomposition of the
given matrix, which preserves the :math:`\epsilon`-pseudospectrum, up to
round-off error, and then simultaneously performs many Implicitly Restarted 
Arnoldi (IRA) iterations with the inverse normal matrix for each shift in a 
manner which communicates no more data than a standard triangular solve with 
many right-hand sides.
Converged pseudospectral estimates are deflated after convergence.

The second approach is quite similar and, instead of reducing to triangular
form, reduces to Hessenberg form and performs multi-shift triangular solves
in a manner similar to Greg Henry's *The shifted Hessenberg system solve 
computation* and Purkayastha et al.'s *A parallel algorithm for the 
Sylvester-Observer Equation*. This algorithm is not yet performance-tuned in
Elemental, but should be preferred in massively-parallel situations where the
Schur decomposition is considered infeasible.

Automatic window
^^^^^^^^^^^^^^^^
The following routines return the norms of the shifted inverses over an 
automatically-determined 2D window in the complex plane 
(in the matrix ``invNormMap``) with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralAutoWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralAutoWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElPseudospectralAutoWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralAutoWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Manual window
^^^^^^^^^^^^^
The following routines return the norms of the shifted inverses over the 
specified 2D window in the complex plane (in the matrix ``invNormMap``) with 
the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> Pseudospectra( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularPseudospectra( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularPseudospectra( const Matrix<Real>& U, Matrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElPseudospectralWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElPseudospectralWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Point cloud
^^^^^^^^^^^
The following routines return the norms of the shifted inverses in the vector 
``invNorms`` for a given set of shifts. The returned integer vector is a list 
of the number of iterations required for convergence of each shift.

C++ API
"""""""

.. cpp:function:: Matrix<int> Pseudospectra( const Matrix<F>& A, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> Pseudospectra( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularPseudospectra( const Matrix<F>& U, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> TriangularPseudospectra( const AbstractDistMatrix<F>& U, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> QuasiTriangularPseudospectra( const AbstractDistMatrix<Real>& U, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& invNorms, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergPseudospectra( const Matrix<F>& H, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> HessenbergPseudospectra( const AbstractDistMatrix<F>& H, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
"""""

.. c:function:: ElError ElPseudospectralCloud_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloud_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloud_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloud_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )
.. c:function:: ElError ElPseudospectralCloudDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElPseudospectralCloudX_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudX_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudX_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudX_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElPseudospectralCloudXDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

Control structures
^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:type:: SnapshotCtrl

   .. cpp:member:: Int realSize
   .. cpp:member:: Int imagSize

   .. cpp:member:: Int imgSaveFreq
   .. cpp:member:: Int numSaveFreq
   .. cpp:member:: Int imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. cpp:member:: Int imgSaveCount
   .. cpp:member:: Int numSaveCount
   .. cpp:member:: Int imgDispCount

   .. cpp:member:: std::string imgBase
   .. cpp:member:: std::string numBase

   .. cpp:member:: FileFormat imgFormat
   .. cpp:member:: FileFormat numFormat

   .. cpp:function::  SnapshotCtrl()

      All counters and dimensions are initially zero, all save/display "frequencies" are set
      to -1 (no output), the basename strings are initialized to "ps",
      the image format to ``PNG``, and the numerical format to ``ASCII_MATLAB``.

   .. cpp:function:: void ResetCounts()

      Resets all counters to zero

   .. cpp:function:: void Iterate()

      Increments all counters by one

.. cpp:type:: PseudospecCtrl<Real>

   .. cpp:member::bool schur

   .. cpp:member:: bool forceComplexSchur

   .. cpp:member:: bool forceComplexPs

   .. cpp:member:: SchurCtrl<Real> schurCtrl

   .. cpp:member:: Int maxIts

   .. cpp:member:: Real tol

   .. cpp:member:: bool deflate

   .. cpp:member:: bool arnoldi

   .. cpp:member:: Int basisSize

   .. cpp:member:: bool reorthog

   .. cpp:member:: bool progress

   .. cpp:member:: SnapshotCtrl snapCtrl

.. cpp:type:: PseudospecCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
"""""

.. c:type:: ElSnapshotCtrl

   .. c:member:: ElInt realSize
   .. c:member:: ElInt imagSize

   .. c:member:: ElInt imgSaveFreq
   .. c:member:: ElInt numSaveFreq
   .. c:member:: ElInt imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. c:member:: ElInt imgSaveCount
   .. c:member:: ElInt numSaveCount
   .. c:member:: ElInt imgDispCount

   .. c:member:: const char* imgBase
   .. c:member:: const char* numBase

   .. c:member:: ElFileFormat imgFormat
   .. c:member:: ElFileFormat numFormat

.. c:function:: ElError ElSnapshotCtrlDefault( ElSnapshotCtrl* ctrl )
.. c:function:: ElError ElSnapshotCtrlDestroy( ElSnapshotCtrl* ctrl )

.. c:type:: ElPseudospecCtrl_s

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: float tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:type:: ElPseudospecCtrl_d

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: double tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:function:: ElError ElPseudospecCtrlDefault_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDefault_d( ElPseudospecCtrl_d* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_d( ElPseudospecCtrl_d* ctrl )

Trace
-----

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Trace.hpp>`__

The two equally useful definitions of the trace of a square matrix 
:math:`A \in \mathbb{F}^{n \times n}` are

.. math::

   \mbox{tr}(A) = \sum_{i=0}^{n-1} A(i,i) = \sum_{i=0}^{n-1} \lambda_i,

where :math:`\lambda_i` is the i'th eigenvalue (counting multiplicity) of 
:math:`A`.

Clearly the former equation is easier to compute, but the latter is an 
important characterization.

C++ API
^^^^^^^

.. cpp:function:: T Trace( const Matrix<T>& A )
.. cpp:function:: T Trace( const AbstractDistMatrix<T>& A )

C API
^^^^^

.. c:function:: ElError ElTrace_i( ElConstMatrix_i A, ElInt* trace )
.. c:function:: ElError ElTrace_s( ElConstMatrix_s A, float* trace )
.. c:function:: ElError ElTrace_d( ElConstMatrix_d A, double* trace )
.. c:function:: ElError ElTrace_c( ElConstMatrix_c A, complex_float* trace )
.. c:function:: ElError ElTrace_z( ElConstMatrix_z A, complex_double* trace )
.. c:function:: ElError ElTraceDist_i( ElConstDistMatrix_i A, ElInt* trace )
.. c:function:: ElError ElTraceDist_s( ElConstDistMatrix_s A, float* trace )
.. c:function:: ElError ElTraceDist_d( ElConstDistMatrix_d A, double* trace )
.. c:function:: ElError ElTraceDist_c( ElConstDistMatrix_c A, complex_float* trace )
.. c:function:: ElError ElTraceDist_z( ElConstDistMatrix_z A, complex_double* trace )

Inertia
-------

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Inertia.hpp>`__

The following routines return a triplet containing the number of positive, 
negative, and zero eigenvalues of a Hermitian matrix by analyzing the 
quasi-diagonal matrix resulting from a pivoted LDLH factorization.

C++ API
^^^^^^^

.. cpp:type:: InertiaType

   .. cpp:member:: Int numPositive
   .. cpp:member:: Int numNegative
   .. cpp:member:: Int numZero

      The basic eigenvalue structure of a Hermitian matrix (which can be quickly
      computed from the quasi-diagonal matrix produced by Bunch-Kaufman).

.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, Matrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )
.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, AbstractDistMatrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )

C API
^^^^^

.. c:type:: ElInertiaType

   .. c:member:: ElInt numPositive
   .. c:member:: ElInt numNegative
   .. c:member:: ElInt numZero

.. c:function:: ElError ElInertia_s( ElUpperOrLower uplo, ElMatrix_s A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_d( ElUpperOrLower uplo, ElMatrix_d A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_c( ElUpperOrLower uplo, ElMatrix_c A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_z( ElUpperOrLower uplo, ElMatrix_z A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElInertiaType* inertia )

