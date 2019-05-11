Affine Second-Order Cone Programs
=================================
.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h\;\wedge\; s \in \mathcal{K} \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \in \mathcal{K} \;\}

In order to represent that product of second-order cones, the following routines
accept two integer vectors which are of the same length as :math:`s` and :math:`z`::

1. ``orders``: The size of the subcone containing each entry of :math:`s`

2. ``firstInds``: The first index (counting from zero) of the subcone containing each entry of :math:`s`

Python API
----------
.. py:function:: SOCPAffine(A,G,b,c,h,orders,firstInds,x,y,z,s[,ctrl=None])

C++ API
-------
.. cpp:function:: void SOCP( const Matrix<Real>& A, const Matrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const ElementalMatrix<Real>& A, const ElementalMatrix<Real>& G, const ElementalMatrix<Real>& b, const ElementalMatrix<Real>& c, const ElementalMatrix<Real>& h, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, ElementalMatrix<Real>& x, ElementalMatrix<Real>& y, ElementalMatrix<Real>& z, ElementalMatrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const SparseMatrix<Real>& A, const SparseMatrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )
.. cpp:function:: void SOCP( const DistSparseMatrix<Real>& A, const DistSparseMatrix<Real>& G, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, const DistMultiVec<Real>& h, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, DistMultiVec<Real>& s, const socp::affine::Ctrl<Real>& ctrl=socp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffine_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElSOCPAffineDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s )
.. c:function:: ElError ElSOCPAffineSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElSOCPAffineDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffine_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElSOCPAffineDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s )
.. c:function:: ElError ElSOCPAffineSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )
.. c:function:: ElError ElSOCPAffineDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s )

Expert interfaces
^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffineX_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElSOCPAffineCtrl_s ctrl )
.. c:function:: ElError ElSOCPAffineXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s, ElSOCPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPAffineX_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElSOCPAffineCtrl_d ctrl )
.. c:function:: ElError ElSOCPAffineXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s, ElSOCPAffineCtrl_d ctrl )

