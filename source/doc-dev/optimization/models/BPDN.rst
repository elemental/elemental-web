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

Python API
----------

.. py:function:: BPDN(A,b,lambd[,ctrl=None])

   :param A: dense or sparse, sequential or distributed matrix
   :param b: dense right-hand side vector (with type compatible to ``A``)
   :param lambd: penalty on the one-norm of the solution vector 
   :param ctrl: (optional) :py:class:`BPDNCtrl_s` or :py:class:`BPDNCtrl_d` instance, depending upon whether the data is single-precision or double-precision
   :rtype: dense solution vector (with type matching that of ``b``)

C++ API
-------
.. cpp:function:: void BPDN( const Matrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const BPDNCtrl<Real>& ctrl=BPDNCtrl<Real>() )
.. cpp:function:: void BPDN( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, Real lambda, AbstractDistMatrix<Real>& x, const BPDNCtrl<Real>& ctrl=BPDNCtrl<Real>() )
.. cpp:function:: void BPDN( const SparseMatrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const BPDNCtrl<Real>& ctrl=BPDNCtrl<Real>() )
.. cpp:function:: void BPDN( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, Real lambda, DistMultiVec<Real>& x, const BPDNCtrl<Real>& ctrl=BPDNCtrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElBPDN_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDNDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x )
.. c:function:: ElError ElBPDNSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElBPDNDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x )

Double-precision
""""""""""""""""

.. c:function:: ElError ElBPDN_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElBPDNDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x )
.. c:function:: ElError ElBPDNSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElBPDNDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElBPDNX_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElBPDNCtrl_s ctrl )
.. c:function:: ElError ElBPDNXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x, ElBPDNCtrl_s ctrl )
.. c:function:: ElError ElBPDNXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElBPDNCtrl_s ctrl )
.. c:function:: ElError ElBPDNXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x, ElBPDNCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElBPDNX_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElBPDNCtrl_d ctrl )
.. c:function:: ElError ElBPDNXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x, ElBPDNCtrl_d ctrl )
.. c:function:: ElError ElBPDNXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElBPDNCtrl_d ctrl )
.. c:function:: ElError ElBPDNXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x, ElBPDNCtrl_d ctrl )
