Sign
====
The matrix sign function can be written as

.. math::
   \text{sgn}(A) = A(A^2)^{-1/2},

as long as :math:`A` does not have any pure-imaginary eigenvalues.

General
-------
The current implementation for :math:`n \times n` matrices makes use of a 
globally-convergent Newton iteration with several scaling options.
Each iteration takes the form

.. math::

   X_{k+1} := \frac{1}{2} ( \mu_k X_k + \mu_k^{-1} X_k^{-1} ),

where :math:`\mu_k` is the scaling factor computed from :math:`X_k`.
Convergence is determined to occur when

.. math::

   \| X_{k+1} - X_k \|_1 \le \| X_{k+1} \|_1^{q+1} \text{tol},

where the exponent :math:`q` is typically one, and the relative tolerance,
`tol`, defaults to :math:`n \epsilon`, where :math:`\epsilon` is the machine
precision. Please see Nicholas J. Higham and Awad H. Al-Mohy's
*Computing Matrix Functions* for more details.

C++ API
^^^^^^^

.. cpp:function:: void Sign( Matrix<F>& A, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sign( AbstractDistMatrix<F>& A, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Overwrite :math:`A` with :math:`\text{sgn}(A)`

.. cpp:function:: void Sign( Matrix<F>& A, Matrix<F>& N, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sign( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& N, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Compute the polar decomposition :math:`A = S N`, where 
   :math:`S=\text{sgn}(A)`, overwriting :math:`A` with :math:`S` on exit

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

C API
^^^^^

.. c:function:: ElError ElSign_s( ElMatrix_s A )
.. c:function:: ElError ElSign_d( ElMatrix_d A )
.. c:function:: ElError ElSign_c( ElMatrix_c A )
.. c:function:: ElError ElSign_z( ElMatrix_z A )
.. c:function:: ElError ElSignDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElSignDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElSignDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElSignDist_z( ElDistMatrix_z A )

   Overwrite :math:`A` with :math:`\text{sgn}(A)`

.. c:function:: ElError ElSignDecomp_s( ElMatrix_s A, ElMatrix_s N )
.. c:function:: ElError ElSignDecomp_d( ElMatrix_d A, ElMatrix_d N )
.. c:function:: ElError ElSignDecomp_c( ElMatrix_c A, ElMatrix_c N )
.. c:function:: ElError ElSignDecomp_z( ElMatrix_z A, ElMatrix_z N )
.. c:function:: ElError ElSignDecompDist_s( ElDistMatrix_s A, ElDistMatrix_s N )
.. c:function:: ElError ElSignDecompDist_d( ElDistMatrix_d A, ElDistMatrix_d N )
.. c:function:: ElError ElSignDecompDist_c( ElDistMatrix_c A, ElDistMatrix_c N )
.. c:function:: ElError ElSignDecompDist_z( ElDistMatrix_z A, ElDistMatrix_z N )

   Compute the polar decomposition :math:`A = S N`, where 
   :math:`S=\text{sgn}(A)`, overwriting :math:`A` with :math:`S` on exit

**TODO: Add an expert interface**

.. c:type:: ElSignCtrl_s

   .. c:member:: ElInt maxIts
   .. c:member:: float tol
   .. c:member:: float power
   .. c:member:: ElSignScaling scaling
   .. c:member:: bool progress

.. c:type:: ElSignCtrl_d

   .. c:member:: ElInt maxIts
   .. c:member:: double tol
   .. c:member:: double power
   .. c:member:: ElSignScaling scaling
   .. c:member:: bool progress

.. c:type:: ElSignScaling

   An enum which can be set to one of

   * ``EL_SIGN_SCALE_NONE``
   * ``EL_SIGN_SCALE_DET``
   * ``EL_SIGN_SCALE_FROB``

Hermitian
---------
Compute the Hermitian EVD, replace the eigenvalues with their sign, and then
reform the matrix. Optionally return the full decomposition, :math:`A=SN`,
where :math:`A` is overwritten by :math:`S`. Note that this will also be 
a polar decomposition.

C++ API
^^^^^^^

.. cpp:function:: void HermitianSign( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HermitianSign( UpperOrLower uplo, AbstractDistMatrix<F>& A )

   Overwrite :math:`A` with :math:`\text{sgn}(A)`

.. cpp:function:: void HermitianSign( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& N )
.. cpp:function:: void HermitianSign( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& N )

   Compute the polar decomposition :math:`A = S N`, where 
   :math:`S=\text{sgn}(A)`, overwriting :math:`A` with :math:`S` on exit

C API
^^^^^

.. c:function:: ElError ElHermitianSign_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHermitianSign_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHermitianSign_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianSign_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianSignDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHermitianSignDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHermitianSignDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHermitianSignDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

   Overwrite :math:`A` with :math:`\text{sgn}(A)`

.. c:function:: ElError ElHermitianSignDecomp_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s N )
.. c:function:: ElError ElHermitianSignDecomp_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d N )
.. c:function:: ElError ElHermitianSignDecomp_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c N )
.. c:function:: ElError ElHermitianSignDecomp_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z N )
.. c:function:: ElError ElHermitianSignDecompDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s N )
.. c:function:: ElError ElHermitianSignDecompDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d N )
.. c:function:: ElError ElHermitianSignDecompDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c N )
.. c:function:: ElError ElHermitianSignDecompDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z N )

   Compute the polar decomposition :math:`A = S N`, where 
   :math:`S=\text{sgn}(A)`, overwriting :math:`A` with :math:`S` on exit
