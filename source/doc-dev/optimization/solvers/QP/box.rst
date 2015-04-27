Box-constrained Quadratic Programs
==================================

.. math::

   \min_x \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; l_b \le x \le u_b \;\}

C++ API
-------

.. cpp:function:: Int qp::ADMM( const Matrix<Real>& Q, const Matrix<Real>& C, Real lb, Real ub, Matrix<Real>& X, const ADMMCtrl<Real>& ctrl=ADMMCtrl<Real>() )
.. cpp:function:: Int qp::ADMM( const AbstractDistMatrix<Real>& Q, const AbstractDistMatrix<Real>& C, Real lb, Real ub, AbstractDistMatrix<Real>& X, const ADMMCtrl<Real>& ctrl=ADMMCtrl<Real>() )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^

.. c:function:: ElError ElQPBoxADMM_s( ElConstMatrix_s Q, ElConstMatrix_s C, float lb, float ub, ElMatrix_s X, ElInt* numIts )
.. c:function:: ElError ElQPBoxADMMDist_s( ElConstDistMatrix_s Q, ElConstDistMatrix_s C, float lb, float ub, ElDistMatrix_s X, ElInt* numIts )

Double-precision
^^^^^^^^^^^^^^^^

.. c:function:: ElError ElQPBoxADMM_d( ElConstMatrix_d Q, ElConstMatrix_d C, double lb, double ub, ElMatrix_d X, ElInt* numIts )
.. c:function:: ElError ElQPBoxADMMDist_d( ElConstDistMatrix_d Q, ElConstDistMatrix_d C, double lb, double ub, ElDistMatrix_d X, ElInt* numIts )

