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

C++ API
-------
.. cpp:function:: void BP( const Matrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, AbstractDistMatrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void BP( const SparseMatrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )
.. cpp:function:: void BP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, DistMultiVec<Real>& x, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )

C API
-----
.. c:function:: ElError ElBP_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBP_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElBPDist_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBPDist_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElBPSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBPSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElBPDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElBPDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )

Expert interface
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElBPX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDist_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDist_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElBPXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElBPXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPDirectCtrl_d ctrl )

Python API
----------
.. py:function:: BP(A,b,ctrl=None)
