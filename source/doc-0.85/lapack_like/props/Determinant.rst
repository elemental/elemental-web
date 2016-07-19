Determinant
-----------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props/Determinant.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack_like/props/Determinant>`__

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

