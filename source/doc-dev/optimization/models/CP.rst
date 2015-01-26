Chebyshev point
===============
A Chebyshev point (CP) minimizes :math:`b - A x` in a pointwise sense, i.e.,

.. math::

   \min_x \| A x - b \|_{\infty},

and is known to be the solution of a linear program when :math:`A` and 
:math:`b` are real. In particular, we may solve

.. math::
  
   \min_{x,t} \{\; t \; | \; -t \le A x - b \le t \; \},

which, in affine conic form, becomes

.. math::

   \min_{x,t} \{\; \begin{pmatrix} 0 \\ 1 \end{pmatrix}^T \begin{pmatrix} x \\ t \end{pmatrix} \; | \; \begin{pmatrix} A & -1 \\ -A & -1 \end{pmatrix} \begin{pmatrix} x \\ t \end{pmatrix} \le \begin{pmatrix} b \\ -b \end{pmatrix} \; \}.

By default, Elemental solves this linear program via a Mehrotra 
Predictor-Corrector primal-dual Interior Point Method.

C++ API
-------
.. cpp:function:: void CP( const Matrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void CP( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, AbstractDistMatrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void CP( const SparseMatrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void CP( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, DistMultiVec<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )

C API
-----
.. c:function:: ElError ElCP_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElCP_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElCPDist_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElCPDist_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElCPSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElCPSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )
.. c:function:: ElError ElCPDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x )
.. c:function:: ElError ElCPDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x )

Expert interface
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElCPX_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElCPX_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElCPXDist_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElCPXDist_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElCPXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElCPXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElCPXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstMatrix_s b, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElCPXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstMatrix_d b, ElMatrix_d x, ElLPAffineCtrl_d ctrl )

Python API
----------
.. py:function:: CP(A,b,ctrl=None)
