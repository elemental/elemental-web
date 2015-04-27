Least Absolute Value regression
===============================
Least Absolute Value (LAV) regression minimizes a residual :math:`b - A x`
in the one-norm, i.e.,

.. math::

   \min_x \| A x - b \|_1,

and is `known to be the solution of a linear program <http://dx.doi.org/10.1287/mnsc.1.2.138>`__ when :math:`A` and  :math:`b` are real. 
In particular, we may solve

.. math::
  
   \min_{x,u,v} \{\; 1^T \begin{pmatrix} u \\ v \end{pmatrix} \; | \; \begin{pmatrix} A & I & -I \end{pmatrix} \begin{pmatrix} x \\ u \\ v \end{pmatrix} = b \; \wedge \; u,v \ge 0 \; \}.

By default, Elemental solves this linear program via a Mehrotra 
Predictor-Corrector primal-dual Interior Point Method.

Python API
----------
.. py:function:: LAV(A,b[,ctrl=None])

   :param A: dense or sparse, sequential or distributed matrix
   :param b: dense right-hand side vector (with type compatible to ``A``)
   :param ctrl: (optional) :py:class:`LPAffineCtrl` instance
   :rtype: dense solution vector (with type matching that of ``b``)

C++ API
-------
.. cpp:function:: void LAV( const Matrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LAV( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, AbstractDistMatrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LAV( const SparseMatrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LAV( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, DistMultiVec<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElLAV_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElLAVDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElDistMatrix_s x )
.. c:function:: ElError ElLAVSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElLAVDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElDistMultiVec_s x )

Double-precision
""""""""""""""""

.. c:function:: ElError ElLAV_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElLAVDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElDistMatrix_d x )
.. c:function:: ElError ElLAVSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElLAVDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElDistMultiVec_d x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElLAVX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLAVXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElDistMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLAVXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLAVXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElDistMultiVec_s x, ElLPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElLAVX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElLAVXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElDistMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElLAVXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElLAVXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElDistMultiVec_d x, ElLPAffineCtrl_d ctrl )

