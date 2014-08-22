Matrix functions
================

Direct inversion
----------------

Triangular
^^^^^^^^^^
Inverts a (possibly unit-diagonal) triangular matrix in-place.

.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<F>& A )
.. cpp:function:: void TriangularInverse( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<F>& A )

   Inverts the triangle of `A` specified by the parameter `uplo`;
   if `diag` is set to `UNIT`, then `A` is treated as unit-diagonal.

General
^^^^^^^
This routine computes the in-place inverse of a general fully-populated
(invertible) matrix :math:`A` as

.. math::

   A^{-1} = U^{-1} L^{-1} P,

where :math:`PA=LU` is the result of LU factorization with partial pivoting.
The algorithm essentially factors :math:`A`, inverts :math:`U` in place,
solves against :math:`L` one block column at a time, and then applies the
row pivots in reverse order to the columns of the result.

.. cpp:function:: void Inverse( Matrix<F>& A )
.. cpp:function:: void Inverse( AbstractDistMatrix<F>& A )

   Overwrites the general matrix `A` with its inverse.

Symmetric/Hermitian
^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void SymmetricInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a symmetric or Hermitian matrix using a pivoted LDL factorization.

.. cpp:function:: void HermitianInverse( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void HermitianInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Invert a Hermitian matrix using a pivoted LDL factorization.

HPD 
^^^
This routine uses a custom algorithm for computing the inverse of a
Hermitian positive-definite matrix :math:`A` as

.. math::

   A^{-1} = (L L^H)^{-1} = L^{-H} L^{-1}, 

where :math:`L` is the lower Cholesky factor of :math:`A` (the upper Cholesky
factor is computed in the case of upper-triangular storage). Rather than
performing Cholesky factorization, triangular inversion, and then the Hermitian
triangular outer product in sequence, this routine makes use of the single-sweep
algorithm described in Bientinesi et al.'s "Families of algorithms related to
the inversion of a symmetric positive definite matrix", in particular, the
variant 2 algorithm from Fig. 9.

If the matrix is found to not be HPD, then a :cpp:type:`NonHPDMatrixException`
is thrown.

.. cpp:function:: void HPDInverse( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPDInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A )

   Overwrite the `uplo` triangle of the HPD matrix `A` with the same
   triangle of the inverse of `A`.

Hermitian functions
-------------------
Reform the matrix with the eigenvalues modified by a user-defined function. 
When the user-defined function is real-valued, the result will remain Hermitian,
but when the function is complex-valued, the result is best characterized as 
normal. 

When the user-defined function, say :math:`f`, is analytic, we can say much
more about the result: if the eigenvalue decomposition of the 
Hermitian matrix :math:`A` is :math:`A=Z \Lambda Z^H`, then

.. math::

   f(A) = f(Z \Lambda Z^H) = Z f(\Lambda) Z^H.

Two important special cases are :math:`f(\lambda) = \exp(\lambda)` and 
:math:`f(\lambda)=\exp(i \lambda)`, where the former results in a Hermitian 
matrix and the latter in a normal (in fact, unitary) matrix.

.. note:: 

   Since Elemental currently depends on PMRRR for its tridiagonal 
   eigensolver, only double-precision results are supported as of now.

.. cpp:function:: void HermitianFunction( UpperOrLower uplo, Matrix<F>& A, std::function<Real(Real)> f )
.. cpp:function:: void HermitianFunction( UpperOrLower uplo, AbstractDistMatrix<F>& A, std::function<Real(Real)> f )

   Modifies the eigenvalues of the passed-in Hermitian matrix by replacing 
   each eigenvalue :math:`\lambda_i` with :math:`f(\lambda_i) \in \mathbb{R}`. 
   See `examples/lapack-like/RealSymmetricFunction.cpp <https://github.com/elemental/Elemental/tree/master/examples/lapack-like/RealHermitianFunction.cpp>`_ for an example usage.

.. cpp:function:: void HermitianFunction( UpperOrLower uplo, Matrix<Complex<Real>>& A, std::function<Complex<Real>(Real)> f )
.. cpp:function:: void HermitianFunction( UpperOrLower uplo, AbstractDistMatrix<Complex<Real>>& A, std::function<Complex<Real>(Real)> f )

   Modifies the eigenvalues of the passed-in complex Hermitian matrix by
   replacing each eigenvalue :math:`\lambda_i` with 
   :math:`f(\lambda_i) \in \mathbb{C}`. 
   See `examples/lapack-like/ComplexHermitianFunction.cpp <https://github.com/elemental/Elemental/tree/master/examples/lapack-like/ComplexHermitianFunction.cpp>`_ for an example usage.

**TODO: A version of (complex) HermitianFunction which begins with a real matrix**

Pseudoinverse
-------------

.. cpp:function:: Pseudoinverse( Matrix<F>& A, Base<F> tolerance=0 )
.. cpp:function:: Pseudoinverse( AbstractDistMatrix<F>& A, Base<F> tolerance=0 )

   Computes the pseudoinverse of a general matrix through computing its SVD,
   modifying the singular values with the function

   .. math::

      f(\sigma) = \left\{\begin{array}{cc} 
        1/\sigma, & \sigma \ge \epsilon \, n \, \| A \|_2 \\
            0,      & \mbox{otherwise}
      \end{array}\right.,

   where :math:`\epsilon` is the relative machine precision,
   :math:`n` is the height of :math:`A`, and :math:`\| A \|_2` is the maximum
   singular value.
   If a nonzero value for `tolerance` was specified, it is used instead of 
   :math:`\epsilon n \| A \|_2`.

.. cpp:function:: HermitianPseudoinverse( UpperOrLower uplo, Matrix<F>& A, Base<F> tolerance=0 )
.. cpp:function:: HermitianPseudoinverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, Base<F> tolerance=0 )

   Computes the pseudoinverse of a Hermitian matrix through a customized version
   of :cpp:func:`HermitianFunction` which used the eigenvalue mapping 
   function

   .. math::

      f(\omega) = \left\{\begin{array}{cc} 
        1/\omega, & |\omega| \ge \epsilon \, n \, \| A \|_2 \\
            0,      & \mbox{otherwise}
      \end{array}\right.,

   where :math:`\epsilon` is the relative machine precision,
   :math:`n` is the height of :math:`A`, and :math:`\| A \|_2` can be computed
   as the maximum absolute value of the eigenvalues of :math:`A`.
   If a nonzero value for `tolerance` is specified, it is used instead of
   :math:`\epsilon n \| A \|_2`.

Square root
-----------
A matrix :math:`B` satisfying 

.. math::

   B^2 = A

is referred to as the *square-root* of the matrix :math:`A`. Such a matrix
is guaranteed to exist as long as :math:`A` is diagonalizable: if 
:math:`A = X \Lambda X^{-1}`, then we may put 

.. math::

   B = X \sqrt{\Lambda} X^{-1},

where each eigenvalue :math:`\lambda = r e^{i\theta}` maps to
:math:`\sqrt{\lambda} = \sqrt{r} e^{i\theta/2}`. 

.. cpp:function:: void SquareRoot( Matrix<F>& A )
.. cpp:function:: void SquareRoot( AbstractDistMatrix<F>& A )

   Currently uses a Newton iteration to compute the general matrix square-root. 
   See ``square_root::Newton`` for the more detailed interface.

.. cpp:function:: void HPSDSquareRoot( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPSDSquareRoot( UpperOrLower uplo, AbstractDistMatrix<F>& A )

   Computes the Hermitian EVD, square-roots the eigenvalues, and then 
   reforms the matrix. If any of the eigenvalues were sufficiently negative,
   a :cpp:type:`NonHPSDMatrixException` is thrown.

**TODO: HermitianSquareRoot**

square_root namespace
^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: int square_root::Newton( Matrix<F>& A, int maxIts=100, Base<F> tol=0 )
.. cpp:function:: int square_root::Newton( AbstractDistMatrix<F>& A, int maxIts=100, Base<F> tol=0 )

   Performs at most ``maxIts`` Newton steps in an attempt to compute the 
   matrix square-root within the specified tolerance, which defaults to 
   :math:`n \epsilon`, where :math:`n` is the matrix height and :math:`\epsilon`
   is the machine precision.

Sign
----
The matrix sign function can be written as

.. math::
   \text{sgn}(A) = A(A^2)^{-1/2},

as long as :math:`A` does not have any pure-imaginary eigenvalues.

.. cpp:type:: SignScaling

   An enum which can be set to one of

   * ``SIGN_SCALE_NONE``
   * ``SIGN_SCALE_DET``
   * ``SIGN_SCALE_FROB``

.. cpp:type:: SignCtrl<Real>

   .. cpp:member:: int maxIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real power
   .. cpp:member:: SignScaling scaling
   .. cpp:member:: bool progress

.. cpp:type:: SignCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   datatype ``F``.

.. cpp:function:: void Sign( Matrix<F>& A, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sign( AbstractDistMatrix<F>& A, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sign( Matrix<F>& A, Matrix<F>& N, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sign( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& N, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Compute the matrix sign through a globally-convergent Newton iteration
   scaled with the Frobenius norm of the iterate and its inverse.
   Optionally return the full decomposition, :math:`A=S N`, where :math:`A`
   is overwritten by :math:`S`.

.. cpp:function:: void HermitianSign( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HermitianSign( UpperOrLower uplo, AbstractDistMatrix<F>& A )
.. cpp:function:: void HermitianSign( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& N )
.. cpp:function:: void HermitianSign( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& N )

   Compute the Hermitian EVD, replace the eigenvalues with their sign, and then
   reform the matrix. Optionally return the full decomposition, :math:`A=SN`,
   where :math:`A` is overwritten by :math:`S`. Note that this will also be 
   a polar decomposition.
