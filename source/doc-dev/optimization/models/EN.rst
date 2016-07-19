Elastic net
===========
The `elastic net (EN) <http://onlinelibrary.wiley.com/doi/10.1111/j.1467-9868.2005.00503.x/abstract>`__ seeks an approximate solution to 
a (usually undetermined) system of equations which penalizes both the one and 
two norms of the solution:

.. math::

   \min_x \| b - A x \|_2^2 + \lambda_1 \| x \|_1 + \lambda_2 \| x \|_2^2.

One could perhaps motivate the elastic net by recognizing that an LQ 
decomposition of an underdetermined systems of equations finds an :math:`x` 
which *exactly* satisfies :math:`A x = b` and simultaneously minimizes 
:math:`\| x \|_2`.
From this perspective, for underdetermined systems, the elastic net trades the 
exact satisfaction of :math:`A x = b`, which would be provided via an LQ 
decomposition, for the hope of a sparse :math:`x` via the addition of a penalty
on :math:`\| x \|_1`.

Real instances of the problem are expressable as an (affine) quadratic program 
in a manner which is nearly identical to that of basis pursuit denoising 
(BPDN): by 
splitting :math:`x` into its positive and negative components, say :math:`x = u - v`, and introducing the residual :math:`r = b - A x`, one arrives at

.. math::

   & \min_{u,v,r} r^T r + \lambda_2 (u^T u + v^T v) + \lambda_1 1^T (u + v) \\
   & \text{s.t. } \begin{pmatrix} A & -A \end{pmatrix} \begin{pmatrix} u \\ v \end{pmatrix} + r = b,\; u,v \ge 0.

By default, Elemental solves this equation using a Mehrotra Predictor-Corrector
primal-dual Interior Point Method.

Python API
----------
.. py:function:: EN(A,b,lambda1,lambda2[,ctrl=None])

   :param A: dense or sparse, sequential or distributed matrix
   :param b: dense right-hand side vector (with type compatible to ``A``)
   :param lambda1: penalty on the one-norm of the solution
   :param lambda2: penalty on the square of the two-norm of the solution
   :param ctrl: (optional) :py:class:`QPAffineCtrl` instance
   :rtype: dense solution vector (with type matching that of ``b``)

C++ API
-------
.. cpp:function:: void EN( const Matrix<Real>& A, const Matrix<Real>& b, Real lambda1, Real lambda2, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void EN( const ElementalMatrix<Real>& A, const ElementalMatrix<Real>& b, Real lambda1, Real lambda2, ElementalMatrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void EN( const SparseMatrix<Real>& A, const Matrix<Real>& b, Real lambda1, Real lambda2, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void EN( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, Real lambda1, Real lambda2, DistMultiVec<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElEN_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda1, float lambda2, ElMatrix_s x )
.. c:function:: ElError ElENDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda1, float lambda2, ElDistMatrix_s x )
.. c:function:: ElError ElENSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda1, float lambda2, ElMatrix_s x )
.. c:function:: ElError ElENDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda1, float lambda2, ElDistMultiVec_s x )

Double-precision
""""""""""""""""

.. c:function:: ElError ElEN_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda1, double lambda2, ElMatrix_d x )
.. c:function:: ElError ElENDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda1, double lambda2, ElDistMatrix_d x )
.. c:function:: ElError ElENSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda1, double lambda2, ElMatrix_d x )
.. c:function:: ElError ElENDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda1, double lambda2, ElDistMultiVec_d x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElENX_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda1, float lambda2, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElENXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda1, float lambda2, ElDistMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElENXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda1, float lambda2, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElENXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda1, float lambda2, ElDistMultiVec_s x, ElQPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElENX_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda1, double lambda2, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElENXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda1, double lambda2, ElDistMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElENXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda1, double lambda2, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElENXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda1, double lambda2, ElDistMultiVec_d x, ElQPAffineCtrl_d ctrl )

