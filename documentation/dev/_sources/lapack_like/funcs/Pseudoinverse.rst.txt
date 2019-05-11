Pseudoinverse
=============

General
-------
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

C++ API
^^^^^^^

.. cpp:function:: void Pseudoinverse( Matrix<F>& A, Base<F> tolerance=0 )
.. cpp:function:: void Pseudoinverse( AbstractDistMatrix<F>& A, Base<F> tolerance=0 )

C API
^^^^^

.. c:function:: ElError ElPseudoinverse_s( ElMatrix_s A )
.. c:function:: ElError ElPseudoinverse_d( ElMatrix_d A )
.. c:function:: ElError ElPseudoinverse_c( ElMatrix_c A )
.. c:function:: ElError ElPseudoinverse_z( ElMatrix_z A )
.. c:function:: ElError ElPseudoinverseDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElPseudoinverseDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElPseudoinverseDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElPseudoinverseDist_z( ElDistMatrix_z A )

Hermitian
---------
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

C++ API
^^^^^^^

.. cpp:function:: void HermitianPseudoinverse( UpperOrLower uplo, Matrix<F>& A, Base<F> tolerance=0 )
.. cpp:function:: void HermitianPseudoinverse( UpperOrLower uplo, AbstractDistMatrix<F>& A, Base<F> tolerance=0 )

C API
^^^^^

.. c:function:: ElError ElHermitianPseudoinverse_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHermitianPseudoinverse_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHermitianPseudoinverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianPseudoinverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianPseudoinverseDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHermitianPseudoinverseDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHermitianPseudoinverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHermitianPseudoinverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )
