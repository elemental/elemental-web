Support vector machines
=======================
Given a collection of :math:`m` labeled vectors, each of the form :math:`(a_i,\delta_i) \subset \mathbb{R}^n \times \{-1,1\}`, a 
`soft-margin Support Vector Machine <http://link.springer.com/article/10.1023%2FA%3A1022627411411>`__ 
seeks the "best" hyperplane for approximately separating the labeled vectors in
the sense that it balances maximizing the separation distance ("margin") 
associated with the hyperplane with the possibility that some of the vectors 
might not fit the model.

More specifically, a solution is sought for

.. math::

   & \min_{w,\beta,z} \frac{1}{2} \| w \|_2^2 + \lambda \sum_i \xi_i \\
   & \text{s.t. } \delta_i ( w^T a_i + \beta ) \le 1 - \xi_i, \; \xi_i \ge 0, \; \forall\; i,

where :math:`w` is the unnormalized normal vector for the separating hyperplane,
:math:`2/\|w\|_2` is the margin, :math:`\beta/\|w\|_2` is the distance 
between the hyperplane and the origin, and the :math:`i`'th entry of 
:math:`z`, :math:`\xi_i`, is the misfit for the :math:`i`'th vector.

The problem can be placed in affine quadratic form by building an 
:math:`m \times n` matrix :math:`A` with its :math:`i`'th row set to 
:math:`a_i` and a vector :math:`d` with its :math:`i`'th entry set to 
:math:`\delta_i`, yielding

.. math::

   & \min_{w,\beta,z} \frac{1}{2} \| w \|_2^2 + \lambda 1^T z \\
   & \text{s.t. } \begin{pmatrix} -\text{diag}(d) A & -d & -I \\ 0 & 0 & -I \end{pmatrix} \begin{pmatrix} w \\ \beta \\ z \end{pmatrix} \le \begin{pmatrix} -1 \\ 0 \end{pmatrix},

which Elemental then defaults to solving with a Mehrotra Predictor-Corrector
primal-dual Interior Point Method.

Python API
----------
.. py:function:: SVM(A,d,lambd[,ctrl=None])

C++ API
-------

.. cpp:function:: void SVM( const Matrix<Real>& A, const Matrix<Real>& d, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void SVM( const ElementalMatrix<Real>& A, const ElementalMatrix<Real>& d, Real lambda, ElementalMatrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void SVM( const SparseMatrix<Real>& A, const Matrix<Real>& d, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void SVM( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& d, Real lambda, DistMultiVec<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElSVM_s( ElConstMatrix_s A, ElConstMatrix_s d, float lambda, ElMatrix_s x )
.. c:function:: ElError ElSVMDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s d, float lambda, ElDistMatrix_s x )
.. c:function:: ElError ElSVMSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s d, float lambda, ElMatrix_s x )
.. c:function:: ElError ElSVMDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s d, float lambda, ElDistMultiVec_s x )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSVM_d( ElConstMatrix_d A, ElConstMatrix_d d, double lambda, ElMatrix_d x )
.. c:function:: ElError ElSVMDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d d, double lambda, ElDistMatrix_d x )
.. c:function:: ElError ElSVMSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d d, double lambda, ElMatrix_d x )
.. c:function:: ElError ElSVMDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d d, double lambda, ElDistMultiVec_d x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElSVMX_s( ElConstMatrix_s A, ElConstMatrix_s d, float lambda, ElMatrix_s x, ElQPAffine_s ctrl )
.. c:function:: ElError ElSVMXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s d, float lambda, ElDistMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElSVMXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s d, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElSVMXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s d, float lambda, ElDistMultiVec_s x, ElQPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSVMX_d( ElConstMatrix_d A, ElConstMatrix_d d, double lambda, ElMatrix_d x, ElQPAffine_d ctrl )
.. c:function:: ElError ElSVMXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d d, double lambda, ElDistMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElSVMXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d d, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElSVMXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d d, double lambda, ElDistMultiVec_d x, ElQPAffineCtrl_d ctrl )

