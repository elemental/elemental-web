Direct Quadratic Programs
=========================

.. math::

   \min_x     & \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; -\frac{1}{2} r^T Q^\dagger r - b^T y \; | \; r = A^T y - z + c \in \text{range}(Q) \;\wedge\; z \ge 0 \;\}

Python API
----------

.. py:function:: QPDirect(Q,A,b,c,x,y,z[,ctrl=None])

C++ API
-------

.. cpp:function:: void QP( const Matrix<Real>& Q, const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void QP( const AbstractDistMatrix<Real>& Q, const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void QP( const SparseMatrix<Real>& Q, const SparseMatrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void QP( const DistSparseMatrix<Real>& Q, const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElQPDirect_s( ElConstMatrix_s Q, ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElQPDirectDist_s( ElConstDistMatrix_s Q, ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z )
.. c:function:: ElError ElQPDirectSparse_s( ElConstSparseMatrix_s Q, ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElQPDirectDistSparse_s( ElConstDistSparseMatrix_s Q, ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z )

Double-precision
""""""""""""""""

.. c:function:: ElError ElQPDirect_d( ElConstMatrix_d Q, ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElQPDirectDist_d( ElConstDistMatrix_d Q, ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z )
.. c:function:: ElError ElQPDirectSparse_d( ElConstSparseMatrix_d Q, ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElQPDirectDistSparse_d( ElConstDistSparseMatrix_d Q, ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z )

Expert interfaces
^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElQPDirectX_s( ElConstMatrix_s Q, ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElQPDirectCtrl_s ctrl )
.. c:function:: ElError ElQPDirectXDist_s( ElConstDistMatrix_s Q, ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElQPDirectCtrl_s ctrl )
.. c:function:: ElError ElQPDirectXSparse_s( ElConstSparseMatrix_s Q, ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElQPDirectCtrl_s ctrl )
.. c:function:: ElError ElQPDirectXDistSparse_s( ElConstDistSparseMatrix_s Q, ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElQPDirectCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElQPDirectX_d( ElConstMatrix_d Q, ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElQPDirectCtrl_d ctrl )
.. c:function:: ElError ElQPDirectXDist_d( ElConstDistMatrix_d Q, ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElQPDirectCtrl_d ctrl )
.. c:function:: ElError ElQPDirectXSparse_d( ElConstSparseMatrix_d Q, ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElQPDirectCtrl_d ctrl )
.. c:function:: ElError ElQPDirectXDistSparse_d( ElConstDistSparseMatrix_d Q, ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElQPDirectCtrl_d ctrl )

