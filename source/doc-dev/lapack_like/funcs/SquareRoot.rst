Square root
===========
A matrix :math:`B` satisfying 

.. math::

   B^2 = A

is referred to as the *square-root* of the matrix :math:`A`. Such a matrix
can easily be seen to exist when :math:`A` is diagonalizable: if 
:math:`A = X \Lambda X^{-1}`, then we may put 

.. math::

   B = X \sqrt{\Lambda} X^{-1},

where each eigenvalue :math:`\lambda = r e^{i\theta}` maps to
:math:`\sqrt{\lambda} = \sqrt{r} e^{i\theta/2}`. 

General
-------
The current implementation for :math:`n \times n` matrices uses the Newton 
iteration

.. math::

   X_{k+1} := \frac{1}{2} ( X_k + X_k^{-1} A )

and convergence is determined to occur when

.. math::

   \| X_{k+1} - X_k \|_1 \le \| X_{k+1} \|_1^{q+1} \text{tol},

where the exponent :math:`q` is typically one, and the relative tolerance,
`tol`, defaults to :math:`n \epsilon`, where :math:`\epsilon` is the machine
precision. Please see Nicholas J. Higham and Awad H. Al-Mohy's 
*Computing Matrix Functions* for more details.

C++ API
^^^^^^^

.. cpp:function:: void SquareRoot( Matrix<F>& A, const SquareRootCtrl<Base<F>> ctrl=SquareRootCtrl<Base<F>>() )
.. cpp:function:: void SquareRoot( AbstractDistMatrix<F>& A, const SquareRootCtrl<Base<F>> ctrl=SquareRootCtrl<Base<F>>() )

.. cpp:type:: SquareRootCtrl<Real>

   .. cpp:member:: Int maxIts

      The maximum number of Newton iterations

   .. cpp:member:: Real tol

      The relative tolerance for convergence of the Newton iteration

   .. cpp:member:: Real power

      The power of the one norm of the new iterate that should be used to
      scale the error when checking for convergence

   .. cpp:member:: bool progress

      Whether or not to print convergence progress

   .. cpp:function:: SquareRootCtrl()

      Sets ``maxIts=100``, ``tol=0`` (which signals that matrix-dependent 
      value will be computed), ``power=1``, and ``progress=false``.

C API
^^^^^

.. c:function:: ElError ElSquareRoot_s( ElMatrix_s A )
.. c:function:: ElError ElSquareRoot_d( ElMatrix_d A )
.. c:function:: ElError ElSquareRoot_c( ElMatrix_c A )
.. c:function:: ElError ElSquareRoot_z( ElMatrix_z A )
.. c:function:: ElError ElSquareRootDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElSquareRootDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElSquareRootDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElSquareRootDist_z( ElDistMatrix_z A )

**TODO: Expert versions**

Hermitian Positive Semi-Definite
--------------------------------
Computes the Hermitian EVD, square-roots the eigenvalues, and then 
reforms the matrix. If any of the eigenvalues were sufficiently negative,
a :cpp:type:`NonHPSDMatrixException` is thrown.

C++ API
^^^^^^^

.. cpp:function:: void HPSDSquareRoot( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPSDSquareRoot( UpperOrLower uplo, AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElHPSDSquareRoot_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHPSDSquareRoot_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHPSDSquareRoot_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHPSDSquareRoot_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHPSDSquareRootDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHPSDSquareRootDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHPSDSquareRootDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHPSDSquareRootDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

**TODO: HermitianSquareRoot**
