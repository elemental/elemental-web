Affine Quadratic Programs
=========================
.. math::

   \min_{x,s} & \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \ge 0 \;\}, \\
   \max_{y,z} & \{\; -\frac{1}{2} r^T Q^\dagger r - b^T y - h^T z \; | \; r = A^T y + G^T z + c \in \text{range}(Q) \;\wedge\; z \ge 0 \;\}

Python API
----------

.. py:function:: QPAffine(Q,A,G,b,c,h,x,y,z,s[,ctrl=None])

C++ API
-------
.. cpp:function:: void QP( const Matrix<Real>& Q, const Matrix<Real>& A, const Matrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void QP( const AbstractDistMatrix<Real>& Q, const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& G, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, const AbstractDistMatrix<Real>& h, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, AbstractDistMatrix<Real>& s, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void QP( const SparseMatrix<Real>& Q, const SparseMatrix<Real>& A, const SparseMatrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void QP( const DistSparseMatrix<Real>& Q, const DistSparseMatrix<Real>& A, const DistSparseMatrix<Real>& G, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, const DistMultiVec<Real>& h, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, DistMultiVec<Real>& s, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElQPAffine_s( ElConstMatrix_s Q, ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElQPAffineDist_s( ElConstDistMatrix_s Q, ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s )
.. c:function:: ElError ElQPAffineSparse_s( ElConstSparseMatrix_s Q, ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElQPAffineDistSparse_s( ElConstDistSparseMatrix_s Q, ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s )

Double-precision
""""""""""""""""

.. c:function:: ElError ElQPAffine_d( ElConstMatrix_d Q, ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElQPAffineDist_d( ElConstDistMatrix_d Q, ElConstDistMatrix_d A, ElConstDistMatrix_d G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s )
.. c:function:: ElError ElQPAffineSparse_d( ElConstSparseMatrix_d Q, ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElQPAffineDistSparse_d( ElConstDistSparseMatrix_d Q, ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s )

Expert interfaces
^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElQPAffineX_s( ElConstMatrix_s Q, ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElQPAffineXDist_s( ElConstDistMatrix_s Q, ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElQPAffineXSparse_s( ElConstSparseMatrix_s Q, ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElQPAffineXDistSparse_s( ElConstDistSparseMatrix_s Q, ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s, ElQPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElQPAffineX_d( ElConstMatrix_d Q, ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElQPAffineXDist_d( ElConstDistMatrix_d Q, ElConstDistMatrix_d A, ElConstDistMatrix_d G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElQPAffineXSparse_d( ElConstSparseMatrix_d Q, ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElQPAffineXDistSparse_d( ElConstDistSparseMatrix_d Q, ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s, ElQPAffineCtrl_d ctrl )

