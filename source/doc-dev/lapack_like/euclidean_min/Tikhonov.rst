Tikhonov regularization
=======================
*Tikhonov regularization* is a modification of the standard least-squares
problem which instead solves

.. math::

   \min_X \| \text{op}(A) X - B \|_2^2 + \| \Gamma X \|_2^2

C++ API
-------

.. cpp:type:: TikhonovAlg

   An enum that can take on the values:

   * ``TIKHONOV_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``TIKHONOV_QR``: Run a QR-based algorithm

.. cpp:function:: void Tikhonov( const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& Gamma, Matrix<F>& X, TikhonovAlg alg=TIKHONOV_CHOLESKY )
.. cpp:function:: void Tikhonov( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& Gamma, AbstractDistMatrix<F>& X, TikhonovAlg alg=TIKHONOV_CHOLESKY )

C API
-----

.. c:type:: ElTikhonovAlg

   An enum which can take on the values:

   * ``EL_TIKHONOV_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``EL_TIKHONOV_QR``: Run a QR-based algorithm

.. c:function:: ElError ElTikhonov_s( ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s Gamma, ElMatrix_s X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_d( ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d Gamma, ElMatrix_d X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_c( ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c Gamma, ElMatrix_c X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_z( ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z Gamma, ElMatrix_z X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s Gamma, ElDistMatrix_s X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d Gamma, ElDistMatrix_d X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c Gamma, ElDistMatrix_c X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z Gamma, ElDistMatrix_z X, ElTikhonovAlg alg )

Python API
----------
.. py:function:: Tikhonov(A,B,Gamma,alg=TIKHONOV_CHOLESKY)
