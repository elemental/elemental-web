Basis pursuit denoising / Lasso
===============================
`Basis pursuit denoising (BPDN) <http://dx.doi.org/10.1137/S003614450037906X>`__
seeks the solution to the problem

.. math::

   \min_x \frac{1}{2} \| b - A x \|_2^2 + \lambda \| x \|_1,

which, for a particular value of :math:`\lambda`, is equivalent to the 
`Least absolute shrinkage and selection operator (Lasso) <http://www.jstor.org/stable/2346178>`__.

Real instances of the problem are `expressable as a Quadratic Program <http://dx.doi.org/10.1137/S003614450037906X>`__ by decomposing :math:`x` into its positive and negative parts, say :math:`x = u - v`, and posing the problem

.. math::

   \min_{u,v,r} \{\; \frac{1}{2} r^T r + \lambda^T \begin{pmatrix} u \\ v \end{pmatrix} \; | \; \begin{pmatrix} A & -A \end{pmatrix} \begin{pmatrix} u \\ v \end{pmatrix} + r = b \; \wedge \; \begin{pmatrix} u \\ v \end{pmatrix} \ge 0 \; \}.

By default, Elemental solves this quadratic program via a Mehrotra 
Predictor-Corrector primal-dual Interior Point Method.

C++ API
-------
.. cpp:function:: void BPDN( const Matrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void BPDN( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, Real lambda, AbstractDistMatrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void BPDN( const SparseMatrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void BPDN( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, Real lambda, DistMultiVec<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----
.. c:function:: ElError ElBPDN_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDN_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElBPDNDist_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDNDist_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElBPDNSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDNSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElBPDNDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDNDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )

Expert interface
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElBPDNX_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElBPDNX_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElBPDNXDist_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElBPDNXDist_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElBPDNXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElBPDNXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElBPDNXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElBPDNXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )

Python API
----------
.. py:function:: BPDN(A,b,lambd,ctrl=None)