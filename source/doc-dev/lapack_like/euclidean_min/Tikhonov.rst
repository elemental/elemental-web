Tikhonov regularization
=======================
*Tikhonov regularization* involves the solution of either a *Regularized
Least Squares* problem,

.. math::

   \min_X \| A X - B \|_F^2 + \| G X \|_F^2,

where :math:`G` is the regularization matrix, or a *Regularized Minimum Length*
problem

.. math::
   :nowrap:

   \begin{eqnarray*}
   && \min_{X,S} \| X \|_F^2 + \| S \|_F^2 \\
   && \text{s.t. } A X + G S = B.
   \end{eqnarray*}

Each of these problems is equivalent to a larger standard Least Squares or
Minimum Length problems, i.e.,

.. math::

   \min_X \left\| \begin{pmatrix} A \\ G \end{pmatrix} X - \begin{pmatrix} B \\ 0 \end{pmatrix} \right\|_F^2

or

.. math::
   :nowrap:
   
   \begin{eqnarray*}
   && \min_{\begin{pmatrix} X \\ S \end{pmatrix}} \left\| \begin{pmatrix} X \\ S \end{pmatrix} \right\|_F^2 \\
   && \text{s.t. } \begin{pmatrix} A & G \end{pmatrix} \begin{pmatrix} X \\ S \end{pmatrix} = B.
   \end{eqnarray*}

Elemental explicitly exploits this equivalence for sparse matrices so that 
its sparse :cpp:func:`LeastSquares` solver can be directly leveraged; for 
dense matrices, the embedding is used implicitly to avoid large unncessary 
memory usage.

Lastly, Elemental in fact allows for slight generalizations of the above
problems: :math:`A^T` or :math:`A^H` may also be used in the above equations
rather than only :math:`A`.

C++ API
-------

.. cpp:type:: TikhonovAlg

   An enum that can take on the values:

   * ``TIKHONOV_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``TIKHONOV_QR``: Run a QR-based algorithm

.. cpp:function:: void Tikhonov( Orientation orientation, const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& Gamma, Matrix<F>& X, TikhonovAlg alg=TIKHONOV_CHOLESKY )

.. cpp:function:: void Tikhonov( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& Gamma, AbstractDistMatrix<F>& X, TikhonovAlg alg=TIKHONOV_CHOLESKY )

.. cpp:function:: void Tikhonov( Orientation orientation, const SparseMatrix<F>& A, const Matrix<F>& B, const SparseMatrix<F>& G, Matrix<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void Tikhonov( Orientation orientation, const DistSparseMatrix<F>& A, const DistMultiVec<F>& B, const DistSparseMatrix<F>& G, DistMultiVec<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

C API
-----

.. c:type:: ElTikhonovAlg

   An enum which can take on the values:

   * ``EL_TIKHONOV_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``EL_TIKHONOV_QR``: Run a QR-based algorithm

.. c:function:: ElError ElTikhonov_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s Gamma, ElMatrix_s X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d Gamma, ElMatrix_d X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c Gamma, ElMatrix_c X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonov_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z Gamma, ElMatrix_z X, ElTikhonovAlg alg )

.. c:function:: ElError ElTikhonovDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s Gamma, ElDistMatrix_s X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d Gamma, ElDistMatrix_d X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c Gamma, ElDistMatrix_c X, ElTikhonovAlg alg )
.. c:function:: ElError ElTikhonovDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z Gamma, ElDistMatrix_z X, ElTikhonovAlg alg )

.. c:function:: ElError ElTikhonovSparse_s( ElOrientation orientation, ElConstSparseMatrix_s A, ElConstMatrix_s B, ElConstSparseMatrix_s G, ElMatrix_s X )
.. c:function:: ElError ElTikhonovSparse_d( ElOrientation orientation, ElConstSparseMatrix_d A, ElConstMatrix_d B, ElConstSparseMatrix_d G, ElMatrix_d X )
.. c:function:: ElError ElTikhonovSparse_c( ElOrientation orientation, ElConstSparseMatrix_c A, ElConstMatrix_c B, ElConstSparseMatrix_c G, ElMatrix_c X )
.. c:function:: ElError ElTikhonovSparse_z( ElOrientation orientation, ElConstSparseMatrix_z A, ElConstMatrix_z B, ElConstSparseMatrix_z G, ElMatrix_z X )

.. c:function:: ElError ElTikhonovDistSparse_s( ElOrientation orientation, ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElConstDistSparseMatrix_s G, ElDistMultiVec_s X )
.. c:function:: ElError ElTikhonovDistSparse_d( ElOrientation orientation, ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElConstDistSparseMatrix_d G, ElDistMultiVec_d X )
.. c:function:: ElError ElTikhonovDistSparse_c( ElOrientation orientation, ElConstDistSparseMatrix_c A, ElConstDistMultiVec_c B, ElConstDistSparseMatrix_c G, ElDistMultiVec_c X )
.. c:function:: ElError ElTikhonovDistSparse_z( ElOrientation orientation, ElConstDistSparseMatrix_z A, ElConstDistMultiVec_z B, ElConstDistSparseMatrix_z G, ElDistMultiVec_z X )

Python API
----------
.. py:function:: Tikhonov(A,B,Gamma,alg=TIKHONOV_CHOLESKY)
