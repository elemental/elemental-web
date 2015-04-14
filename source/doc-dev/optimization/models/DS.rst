Dantzig selector
================
The `Dantzig selector (DS) <http://projecteuclid.org/euclid.aos/1201012958>`__ 
attempts to balance the approximate satisfaction of a highly underdetermined
system of equations with a sparsity-promoting :math:`\ell_1` penalty on the 
solution using only linear programming:

.. math::

   \min_x \| x \|_1 \text{ such that } \| A^T (b - A x) \|_{\infty} \le \lambda.
  
In addition to the specific LP formulation in Candes and Tao's original paper, 
Friedlander and Saunders 
`proposed two mappings <http://projecteuclid.org/euclid.aos/1201012964>`__, 
(DS1):

.. math::

   \min_{u,v,t} \{\;1^T (u+v) \; | \; \begin{pmatrix} A^T A & -A^T A & I \end{pmatrix} \begin{pmatrix} u \\ v \\ t \end{pmatrix} = A^T b \; \wedge \; u,v \ge 0 \; \wedge \; \| t \|_{\infty} \le \lambda \;\}, \; \text{and}

(DS2):

.. math::

   \min_{u,v,r,t} \{\; 1^T (u+v) \; | \; \begin{pmatrix} A & -A & I & 0 \\ 0 & 0 & A^T & I \end{pmatrix} \begin{pmatrix} u \\ v \\ r \\ t \end{pmatrix} = \begin{pmatrix} b \\ 0 \end{pmatrix} \; \wedge \; u,v \ge 0 \; \wedge \; \| t \|_{\infty} \le \lambda \;\},

which they argued to be superior in performance and 
conditioning. Elemental defaults to (DS1) for dense matrices and (DS2) for 
sparse matrices and applies a Mehrotra Predictor-Corrector primal-dual 
Interior Point Method.

Python API
----------
.. py:function:: DS(A,b,lambd[,ctrl=None])

C++ API
-------

.. cpp:function:: void DS( const Matrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void DS( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, Real lambda, AbstractDistMatrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void DS( const SparseMatrix<Real>& A, const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )
.. cpp:function:: void DS( const DistSparseMatrix<Real>& A, const DistMultiVec<Real>& b, Real lambda, DistMultiVec<Real>& x, const lp::affine::Ctrl<Real>& ctrl=lp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElDS_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElDSDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x )
.. c:function:: ElError ElDSSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElDSDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x )

Double-precision
""""""""""""""""

.. c:function:: ElError ElDS_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElDSDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x )
.. c:function:: ElError ElDSSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElDSDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElDSX_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElDSXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElDSXSparse_s( ElConstSparseMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s x, ElLPAffineCtrl_s ctrl )
.. c:function:: ElError ElDSXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x, ElLPAffineCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElDSX_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElDSXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElDSXSparse_d( ElConstSparseMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d x, ElLPAffineCtrl_d ctrl )
.. c:function:: ElError ElDSXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x, ElLPAffineCtrl_d ctrl )

