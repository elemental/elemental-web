Direct Linear Programs
======================

.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \ge 0 \;\}

Python API
----------
.. py:function:: LPDirect(A,b,c,x,y,z[,ctrl=None])

C++ API
-------
.. cpp:function:: void LP( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void LP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void LP( const SparseMatrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )
.. cpp:function:: void LP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElLPDirect_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElLPDirectDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z )
.. c:function:: ElError ElLPDirectSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElLPDirectDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z )

Double-precision
""""""""""""""""

.. c:function:: ElError ElLPDirect_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElLPDirectDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z )
.. c:function:: ElError ElLPDirectSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElLPDirectDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElLPDirectX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElLPDirectCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElLPDirectX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElLPDirectXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElLPDirectXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElLPDirectCtrl_d ctrl )
.. c:function:: ElError ElLPDirectXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElLPDirectCtrl_d ctrl )

