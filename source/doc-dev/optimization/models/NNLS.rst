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
primal-dual Interior Point Method.

Standard interface
------------------
The following routines solve a sequence of non-negative least squares problems
which share the same coefficient matrix by forming :math:`A^T A` once and 
sequentially solving a sequence of quadratic programs (with each QP 
individually parallelized).

C++ API
^^^^^^^
.. cpp:function:: void NNLS( const Matrix<Real>& A, const Matrix<Real>& B, Matrix<Real>& X, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void NNLS( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& B, AbstractDistMatrix<Real>& X, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void NNLS( const SparseMatrix<Real>& A, const Matrix<Real>& B, Matrix<Real>& X, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )
.. cpp:function:: void NNLS( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& B, DistMultiVec<Real>& X, const qp::direct::Ctrl<Real>& ctrl=qp::direct::Ctrl<Real>() )

C API
^^^^^
.. c:function:: ElError ElNNLS_s( ElConstMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElNNLS_d( ElConstMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )

.. c:function:: ElError ElNNLSDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElNNLSDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X )

.. c:function:: ElError ElNNLSSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElNNLSSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )

.. c:function:: ElError ElNNLSDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElDistMultiVec_s X )
.. c:function:: ElError ElNNLSDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElDistMultiVec_d X )

Python API
^^^^^^^^^^
.. py:function:: NNLS(A,B)

ADMM
----
An Alternating Direction Method of Multipliers implementation which 
simultaneously solves many instances of the QP in box form is also available
for dense matrices.

C++ API
^^^^^^^

.. cpp:function:: Int nnls::ADMM( const Matrix<Real>& A, const Matrix<Real>& B, Matrix<Real>& X, const qp::box::ADMMCtrl<Real>& ctrl=qp::box::ADMMCtrl<Real>() )
.. cpp:function:: Int nnls::ADMM( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& B, AbstractDistMatrix<Real>& X, const qp::box::ADMMCtrl<Real>& ctrl=qp::box::ADMMCtrl<Real>() )

C API
^^^^^

.. c:function:: ElError ElNNLSADMM_s( ElConstMatrix_s A, ElConstMatrix_s Y, ElMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElNNLSADMM_d( ElConstMatrix_d A, ElConstMatrix_d Y, ElMatrix_d Z, ElInt* numIts )
.. c:function:: ElError ElNNLSADMMDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s Y, ElDistMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElNNLSADMMDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d Y, ElDistMatrix_d Z, ElInt* numIts )
