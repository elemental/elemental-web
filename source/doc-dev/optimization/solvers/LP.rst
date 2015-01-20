Linear programs
===============
The following routines attempt to solve primal-dual pairs of (convex) quadratic
programs in either "direct" conic form,

.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \ge 0 \;\},

or "affine" conic form

.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \ge 0 \;\}.

By default a Mehrotra Predictor-Corrector primal-dual
Interior Point Method is used.

Direct conic form
-----------------
.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \ge 0 \;\}

C++ API
^^^^^^^
.. cpp:function:: void LP( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void LP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(false) )
.. cpp:function:: void LP( const SparseMatrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )
.. cpp:function:: void LP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, const lp::direct::Ctrl<Real>& ctrl=lp::direct::Ctrl<Real>(true) )

C API
^^^^^
.. c:function:: ElError ElLPDirect_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElLPDirect_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )

.. c:function:: ElError ElLPDirectDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z )
.. c:function:: ElError ElLPDirectDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z )

.. c:function:: ElError ElLPDirectSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z )
.. c:function:: ElError ElLPDirectSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z )

.. c:function:: ElError ElLPDirectDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z )
.. c:function:: ElError ElLPDirectDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z )

Expert interface
""""""""""""""""
.. c:function:: ElError ElLPDirectX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElLPDirectCtrl_d ctrl )

.. c:function:: ElError ElLPDirectXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElLPDirectCtrl_d ctrl )

.. c:function:: ElError ElLPDirectXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElLPDirectCtrl_d ctrl )

.. c:function:: ElError ElLPDirectXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElLPDirectCtrl_s ctrl )
.. c:function:: ElError ElLPDirectXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElLPDirectCtrl_d ctrl )

Python API
^^^^^^^^^^
.. py:function:: LPDirect(A,b,c,x,y,z,ctrl=None)

Affine conic form
-----------------
.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \ge 0 \;\}

C++ API
^^^^^^^
.. cpp:function:: void LP( const Matrix<Real>& A, const Matrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& G, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, const AbstractDistMatrix<Real>& h, AbstractDistMatrix<Real>& x, AbstractDistMatrix<Real>& y, AbstractDistMatrix<Real>& z, AbstractDistMatrix<Real>& s, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LP( const SparseMatrix<Real>& A, const SparseMatrix<Real>& G, const Matrix<Real>& b, const Matrix<Real>& c, const Matrix<Real>& h, Matrix<Real>& x, Matrix<Real>& y, Matrix<Real>& z, Matrix<Real>& s, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void LP( const DistSparseMatrix<Real>& A, const DistSparseMatrix<Real>& G, const DistMultiVec<Real>& b, const DistMultiVec<Real>& c, const DistMultiVec<Real>& h, DistMultiVec<Real>& x, DistMultiVec<Real>& y, DistMultiVec<Real>& z, DistMultiVec<Real>& s, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )

C API
^^^^^
.. c:function:: ElError ElLPAffine_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElLPAffine_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )

.. c:function:: ElError ElLPAffineDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s )
.. c:function:: ElError ElLPAffineDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s )

.. c:function:: ElError ElLPAffineSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s )
.. c:function:: ElError ElLPAffineSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s )

.. c:function:: ElError ElLPAffineDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s )
.. c:function:: ElError ElLPAffineDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s )

Expert interfaces
"""""""""""""""""
.. c:function:: ElError ElLPAffineX_s( ElConstMatrix_s A, ElConstMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLPAffineX_d( ElConstMatrix_d A, ElConstMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElLPAffineCtrl_d ctrl )

.. c:function:: ElError ElLPAffineXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s G, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElConstDistMatrix_s h, ElDistMatrix_s x, ElDistMatrix_s y, ElDistMatrix_s z, ElDistMatrix_s s, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLPAffineXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_s G, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElConstDistMatrix_d h, ElDistMatrix_d x, ElDistMatrix_d y, ElDistMatrix_d z, ElDistMatrix_d s, ElLPAffineCtrl_d ctrl )

.. c:function:: ElError ElLPAffineXSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s G, ElConstMatrix_s b, ElConstMatrix_s c, ElConstMatrix_s h, ElMatrix_s x, ElMatrix_s y, ElMatrix_s z, ElMatrix_s s, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLPAffineXSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d G, ElConstMatrix_d b, ElConstMatrix_d c, ElConstMatrix_d h, ElMatrix_d x, ElMatrix_d y, ElMatrix_d z, ElMatrix_d s, ElLPAffineCtrl_d ctrl )

.. c:function:: ElError ElLPAffineXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_s b, ElConstDistMultiVec_s c, ElConstDistMultiVec_s h, ElDistMultiVec_s x, ElDistMultiVec_s y, ElDistMultiVec_s z, ElDistMultiVec_s s, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElLPAffineXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_s G, ElConstDistMultiVec_d b, ElConstDistMultiVec_d c, ElConstDistMultiVec_d h, ElDistMultiVec_d x, ElDistMultiVec_d y, ElDistMultiVec_d z, ElDistMultiVec_d s, ElLPAffineCtrl_d ctrl )

Python API
^^^^^^^^^^
.. py:function:: LPAffine(A,G,b,c,h,x,y,z,s,ctrl=None)
