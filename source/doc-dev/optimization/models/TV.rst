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

Python API
----------
.. py:function:: TV(b,lambd[,ctrl=None])

C++ API
-------
.. cpp:function:: void TV( const Matrix<Real>& b, Real lambda, Matrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void TV( const ElementalMatrix<Real>& b, Real lambda, ElementalMatrix<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )
.. cpp:function:: void TV( const DistMultiVec<Real>& b, Real lambda, DistMultiVec<Real>& x, const qp::affine::Ctrl<Real>& ctrl=qp::affine::Ctrl<Real>() )

C API
-----

Single-precision
""""""""""""""""

.. c:function:: ElError ElTV_s( ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElTVDist_s( ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x )
.. c:function:: ElError ElTVSparse_s( ElConstMatrix_s b, float lambda, ElMatrix_s x )
.. c:function:: ElError ElTVDistSparse_s( ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x )


Double-precision
""""""""""""""""

.. c:function:: ElError ElTV_d( ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElTVDist_d( ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x )
.. c:function:: ElError ElTVSparse_d( ElConstMatrix_d b, double lambda, ElMatrix_d x )
.. c:function:: ElError ElTVDistSparse_d( ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x )


Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElTVX_s( ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVXDist_s( ElConstDistMatrix_s b, float lambda, ElDistMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVXSparse_s( ElConstMatrix_s b, float lambda, ElMatrix_s x, ElQPAffineCtrl_s ctrl )
.. c:function:: ElError ElTVXDistSparse_s( ElConstDistMultiVec_s b, float lambda, ElDistMultiVec_s x, ElQPAffineCtrl_s ctrl )


Double-precision
""""""""""""""""

.. c:function:: ElError ElTVX_d( ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElTVXDist_d( ElConstDistMatrix_d b, double lambda, ElDistMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElTVXSparse_d( ElConstMatrix_d b, double lambda, ElMatrix_d x, ElQPAffineCtrl_d ctrl )
.. c:function:: ElError ElTVXDistSparse_d( ElConstDistMultiVec_d b, double lambda, ElDistMultiVec_d x, ElQPAffineCtrl_d ctrl )


