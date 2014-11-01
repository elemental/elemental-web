Ridge regression
================
*Ridge regression* is a modification of the standard least-squares
problem which instead solves

.. math::

   \min_X \| \text{op}(A) X - B \|_2^2 + \| \alpha X \|_2^2,

which is a special case of *Tikhonov regularization* where the weighting matrix
is a multiple of the identity.

C++ API
-------

.. cpp:type:: RidgeAlg

   An enum that can take on the values:

   * ``RIDGE_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``RIDGE_QR``: Run a QR-based algorithm
   * ``RIDGE_SVD``: Run an SVD-based algorithm

.. cpp:function:: void Ridge( const Matrix<F>& A, const Matrix<F>& B, Base<F> alpha, Matrix<F>& X, RidgeAlg alg=RIDGE_CHOLESKY )
.. cpp:function:: void Ridge( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, Base<F> alpha, AbstractDistMatrix<F>& X, RidgeAlg alg=RIDGE_CHOLESKY )

C API
-----

.. c:type:: ElRidgeAlg

   An enum that can take on the values:

   * ``EL_RIDGE_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``EL_RIDGE_QR``: Run a QR-based algorithm
   * ``EL_RIDGE_SVD``: Run an SVD-based algorithm

.. c:function:: ElError ElRidge_s( ElConstMatrix_s A, ElConstMatrix_s B, float alpha, ElMatrix_s X, ElRidgeAlg alg )
.. c:function:: ElError ElRidge_d( ElConstMatrix_d A, ElConstMatrix_d B, double alpha, ElMatrix_d X, ElRidgeAlg alg )
.. c:function:: ElError ElRidge_c( ElConstMatrix_c A, ElConstMatrix_c B, float alpha, ElMatrix_c X, ElRidgeAlg alg )
.. c:function:: ElError ElRidge_z( ElConstMatrix_z A, ElConstMatrix_z B, double alpha, ElMatrix_z X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float alpha, ElDistMatrix_s X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double alpha, ElDistMatrix_d X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, float alpha, ElDistMatrix_c X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, double alpha, ElDistMatrix_z X, ElRidgeAlg alg )
