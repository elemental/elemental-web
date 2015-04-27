Non-negative least squares
==========================
*Non-negative least squares* minimizes the residual :math:`b - A x` under the
constraint that :math:`x` must have non-negative entries, i.e., 

.. math::

   \min_x \| A x - b \|_2 \text{ such that } x \ge 0,

and real instances of this problem is well-known to be expressable as the 
quadratic program

.. math::

   & \min_x \frac{1}{2} x^T (A^T A) x + (-A^T b)^T x \\
   & \text{s.t. } x \ge 0.

Elemental defaults to solving this QP via a Mehrotra Predictor-Corrector
primal-dual Interior Point Method, but a (prototype) batched version of QP 
ADMM is also available.

Python API
----------

.. py:function:: NNLS(A,B[,ctrl=None])

   :param A: dense or sparse, sequential or distributed matrix
   :param B: dense right-hand side matrix (with type compatible to ``A``)
   :param ctrl: (optional) :py:class:`NNLSCtrl_s` or :py:class:`NNLSCtrl_d` instance, depending upon whether data is single-precision or double-precision
   :rtype: dense solution vector (with type matching that of ``b``)

C++ API
-------
.. cpp:function:: void NNLS( const Matrix<Real>& A, const Matrix<Real>& B, Matrix<Real>& X, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )
.. cpp:function:: void NNLS( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& B, AbstractDistMatrix<Real>& X, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )
.. cpp:function:: void NNLS( const SparseMatrix<Real>& A, const Matrix<Real>& B, Matrix<Real>& X, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )
.. cpp:function:: void NNLS( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& B, DistMultiVec<Real>& X, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )

C API
-----

Single-precision
""""""""""""""""
.. c:function:: ElError ElNNLS_s( ElConstMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElNNLSDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElNNLSSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElNNLSDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElDistMultiVec_s X )

Double-precision
""""""""""""""""
.. c:function:: ElError ElNNLS_d( ElConstMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElNNLSDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElNNLSSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElNNLSDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElDistMultiVec_d X )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElNNLSX_s( ElConstMatrix_s A, ElConstMatrix_s B, ElMatrix_s X, ElNNLSCtrl_s ctrl )
.. c:function:: ElError ElNNLSXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X, ElNNLSCtrl_s ctrl )
.. c:function:: ElError ElNNLSXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s B, ElMatrix_s X, ElNNLSCtrl_s ctrl )
.. c:function:: ElError ElNNLSXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElDistMultiVec_s X, ElNNLSCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElNNLSX_d( ElConstMatrix_d A, ElConstMatrix_d B, ElMatrix_d X, ElNNLSCtrl_d ctrl )
.. c:function:: ElError ElNNLSXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X, ElNNLSCtrl_d ctrl )
.. c:function:: ElError ElNNLSXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d B, ElMatrix_d X, ElNNLSCtrl_d ctrl )
.. c:function:: ElError ElNNLSXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElDistMultiVec_d X, ElNNLSCtrl_d ctrl )
