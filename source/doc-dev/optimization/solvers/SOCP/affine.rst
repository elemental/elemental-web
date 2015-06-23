Affine Second-Order Cone Programs
=================================
.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \in \mathcal{K} \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \in \mathcal{K} \;\}

**TODO**: Describe how ``orders``, ``firstInds``, and ``labels`` describe the cone :math:`\mathcal{K}`

Python API
----------
.. py:function:: SOCPAffine(A,G,b,c,h,orders,firstInds,labels,x,y,z,s[,ctrl=None])

C++ API
-------
.. cpp:function:: void SOCP( const Matrix<Real>& A, const Matrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, const Matrix<Int>& orders, const Matrix<Int>& firstInds, const Matrix<Int>& labels, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& G, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, const AbstractDistMatrix<Real>& h, const AbstractDistMatrix<Int>& orders, const AbstractDistMatrix<Int>& firstInds, const AbstractDistMatrix<Int>& labels, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, AbstractDistMatrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const SparseMatrix<Real>& A, const SparseMatrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds, const Matrix<Int>& labels, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const DistSparseMatrix<Real>& A, const DistSparseMatrix<Real>& G, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, const DistMultiVec<Real>& h, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, const DistMultiVec<Int>& labels, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, DistMultiVec<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffine_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElSOCPAffineDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElConstDistMatrix_i labels, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s )
.. c:function:: ElError ElSOCPAffineSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElSOCPAffineDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElConstDistMultiVec_i labels, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffine_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElSOCPAffineDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElConstDistMatrix_i labels, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s )
.. c:function:: ElError ElSOCPAffineSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElSOCPAffineDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElConstDistMultiVec_i labels, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s )

Expert interfaces
^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffineX_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElConstDistMatrix_i labels, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElConstDistMultiVec_i labels, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s, ElSOCPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffineX_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElConstDistMatrix_i labels, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElConstMatrix_i labels, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElConstDistMultiVec_i labels, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s, ElSOCPAffineCtrl_d ctrl )

