Total variation denoising
=========================
`Total variation denoising (TV) <http://www.sciencedirect.com/science/article/pii/016727899290242F>`__
seeks the solution to the problem

.. math::

   \min_x \frac{1}{2} \| b - x \|_2^2 + \lambda \| D x \|_1,

where :math:`b \in \mathbb{R}^n` is the original (1D) signal and 
:math:`D : \mathbb{R}^n \rightarrow \mathbb{R}^{n-1}` is the upper-bidiagonal
difference operator which maps a vector :math:`x` to 

.. math::

   (D x)_i = x_i - x_{i+1}.

Real instances of the problem are expressable as a Quadratic Program, and 
Elemental follows the formulation used within `CVXOPT <http://cvxopt.org/>`__: 

.. math::

   & \min_{x,t} \frac{1}{2} \| x - b \|_2^2 + \lambda 1^T t \\
   & \text{s.t. } -t \le D x \le t.

By default, Elemental solves this quadratic program via a Mehrotra 
Predictor-Corrector primal-dual Interior Point Method.

C++ API
-------
.. cpp:function:: void TV( const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void TV( const AbstractDistMatrix<Real>& b, Real lambda, AbstractDistMatrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void TV( const DistMultiVec<Real>& b, Real lambda, DistMultiVec<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----
.. c:function:: ElError ElTV_s( ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElTV_d( ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElTVDist_s( ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElTVDist_d( ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElTVDistSparse_s( ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElTVDistSparse_d( ElConstMatrix_d b, double lambda, ElMatrix_d x )

Expert interface
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElTVX_s( ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVX_d( ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElTVXDist_s( ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVXDist_d( ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElTVXDistSparse_s( ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVXDistSparse_d( ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )

Python API
----------
.. py:function:: TV(b,lambd,ctrl=None)
