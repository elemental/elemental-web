Basis pursuit
=============
`Basis pursuit (BP) <http://dx.doi.org/10.1109/ACSSC.1994.471413>`__ is the 
search for a solution to :math:`A x = b` which minimizes the one norm of 
:math:`x`, i.e.,

.. math::

   \min_x \| x \|_1 \text{ such that } A x = b.

Real instances of the problem are `expressible as a Linear Program <http://dx.doi.org/10.1137/S003614450037906X>`__ by decomposing :math:`x` into its positive and negative parts, say :math:`x = u - v`, and posing the problem

.. math::

   \min_{u,v} \{\; 1^T \begin{pmatrix} u \\ v \end{pmatrix} \; | \; \begin{pmatrix} A & -A \end{pmatrix} \begin{pmatrix} u \\ v \end{pmatrix} = b \; \wedge \; \begin{pmatrix} u \\ v \end{pmatrix} \ge 0 \; \}.

By default, Elemental solves this linear program via a Mehrotra 
Predictor-Corrector primal-dual Interior Point Method.

Complex instances of Basis Pursuit are currently supported through 
Second-Order Cone Programs. **TODO**: Describe this embedding.

Python API
----------
.. py:function:: BP(A,b[,ctrl=None])

   :param A: dense or sparse, sequential or distributed matrix
   :param b: dense right-hand side vector (with type compatible to ``A``)
   :param ctrl: (optional) :py:class:`LPDirectCtrl` instance
   :rtype: dense solution vector (with type matching that of ``b``)

C++ API
-------
.. cpp:function:: void BP( const Matrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const ElementalMatrix<Real>& A, const ElementalMatrix<Real>& b, ElementalMatrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const SparseMatrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )
.. cpp:function:: void BP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, DistMultiVec<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )

.. cpp:function:: void BP( const Matrix<Complex<Real>>& A, const Matrix<Complex<Real>>& b, Matrix<Complex<Real>>& x, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const ElementalMatrix<Complex<Real>>& A, const ElementalMatrix<Complex<Real>>& b, ElementalMatrix<Complex<Real>>& x, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const SparseMatrix<Complex<Real>>& A, const Matrix<Complex<Real>>& b, Matrix<Complex<Real>>& x, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(true) )
.. cpp:function:: void BP( const DistSparseMatrix<Complex<Real>>& A, const DistMultiVec<Complex<Real>>& b, DistMultiVec<Complex<Real>>& x, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(true) )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElBP_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBPDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElDistMatrix_s x )
.. c:function:: ElError ElBPSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBPDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElDistMultiVec_s x )


Double-precision
""""""""""""""""

.. c:function:: ElError ElBP_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElBPDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElDistMatrix_d x )
.. c:function:: ElError ElBPSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElBPDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElDistMultiVec_d x )

Single-precision complex
""""""""""""""""""""""""

.. c:function:: ElError ElBP_c( ElConstMatrix_c A, ElConstMatrix_c b, ElMatrix_c x )
.. c:function:: ElError ElBPDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c b, ElDistMatrix_c x )
.. c:function:: ElError ElBPSparse_c( ElConstSparseMatrix_c A, ElConstMatrix_c b, ElMatrix_c x )
.. c:function:: ElError ElBPDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistMultiVec_c b, ElDistMultiVec_c x )

Double-precision complex
""""""""""""""""""""""""

.. c:function:: ElError ElBP_z( ElConstMatrix_z A, ElConstMatrix_z b, ElMatrix_z x )
.. c:function:: ElError ElBPDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z b, ElDistMatrix_z x )
.. c:function:: ElError ElBPSparse_z( ElConstSparseMatrix_z A, ElConstMatrix_z b, ElMatrix_z x )
.. c:function:: ElError ElBPDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistMultiVec_z b, ElDistMultiVec_z x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElBPX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElDistMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElDistMultiVec_s x, ElLPDirectCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElBPX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElDistMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElDistMultiVec_d x, ElLPDirectCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""

.. c:function:: ElError ElBPX_c( ElConstMatrix_c A, ElConstMatrix_c b, ElMatrix_c x, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c b, ElDistMatrix_c x, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXSparse_c( ElConstSparseMatrix_c A, ElConstMatrix_c b, ElMatrix_c x, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistMultiVec_c b, ElDistMultiVec_c x, ElSOCPDirectCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""

.. c:function:: ElError ElBPX_z( ElConstMatrix_z A, ElConstMatrix_z b, ElMatrix_z x, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z b, ElDistMatrix_z x, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXSparse_z( ElConstSparseMatrix_z A, ElConstMatrix_z b, ElMatrix_z x, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistMultiVec_z b, ElDistMultiVec_z x, ElSOCPDirectCtrl_d ctrl )

