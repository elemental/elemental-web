Direct Second-Order Cone Programs
=================================

.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \in \mathcal{K} \;\}, \\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \in \mathcal{K} \;\}


In order to represent that product of second-order cones, the following routinesaccept two integer vectors which are of the same length as :math:`x` and :math:`z`::

1. ``orders``: The size of the subcone containing each entry of :math:`x`

2. ``firstInds``: The first index (counting from zero) of the subcone containing each entry of :math:`x`

Python API
----------
.. py:function:: SOCPDirect(A,b,c,orders,firstInds,x,y,z[,ctrl=None])

C++ API
-------
.. cpp:function:: void SOCP( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(false) )
.. cpp:function:: void SOCP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, const AbstractDistMatrix<Int>& orders, const AbstractDistMatrix<Int>& firstInds, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(false) )
.. cpp:function:: void SOCP( const SparseMatrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(true) )
.. cpp:function:: void SOCP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, const socp::direct::Ctrl<Real>& ctrl=socp::direct::Ctrl<Real>(true) )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPDirect_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElSOCPDirectDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z )
.. c:function:: ElError ElSOCPDirectSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElSOCPDirectDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPDirect_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElSOCPDirectDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z )
.. c:function:: ElError ElSOCPDirectSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )
.. c:function:: ElError ElSOCPDirectDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElSOCPDirectX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElSOCPDirectXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElSOCPDirectXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElSOCPDirectCtrl_s ctrl )
.. c:function:: ElError ElSOCPDirectXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElSOCPDirectCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElSOCPDirectX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElSOCPDirectXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_i orders, ElConstDistMatrix_i firstInds, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElSOCPDirectXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_i orders, ElConstMatrix_i firstInds, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElSOCPDirectCtrl_d ctrl )
.. c:function:: ElError ElSOCPDirectXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_i orders, ElConstDistMultiVec_i firstInds, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElSOCPDirectCtrl_d ctrl )

