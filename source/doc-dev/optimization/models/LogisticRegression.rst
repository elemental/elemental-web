Logistic regression
===================
Given a sequence of vectors :math:`\{a_i\}_{i=0}^{n-1} \subset \mathbb{R}^m` 
with binary labels :math:`\{\eta_i\}_{i=0}^{n-1} \subset \{0,1\}`, 
:math:`\ell_p`-*regularized logistic regression* solves the problem

.. math::

   \min_{z,\nu} \frac{1}{n} \sum_{i=0}^{n-1} f(z^H a_i + \nu \eta_i) +    
   \lambda \| z \|_p,

where :math:`f` is the *logistic loss function*, 

.. math::

   f(t) = \log(1+e^{-t}).

.. note::

   While sometimes functional, this implementation is still very much a 
   work-in-progress.

C++ API
-------

.. c:type:: Regularization

   An enum which can take on the values ``NO_PENALTY``, ``L1_PENALTY``, 
   and ``L2_PENALTY``

.. cpp:function:: Int LogisticRegression( const Matrix<Real>& G, const Matrix<Real>& q, Matrix<Real>& z, Real gamma, Regularization penalty=L1_PENALTY, Real rho=1, Int maxIter=500, bool inv=true, bool progress=true )
.. cpp:function:: Int LogisticRegression( const ElementalMatrix<Real>& G, const ElementalMatrix<Real>& q, ElementalMatrix<Real>& z, Real gamma, Regularization penalty=L1_PENALTY, Real rho=1, Int maxIter=500, bool inv=true, bool progress=true )

C API
-----

.. c:type:: ElRegularization

   An enum which can take on the values ``EL_NO_PENALTY``, ``EL_L1_PENALTY``, 
   and ``EL_L2_PENALTY``

.. c:function:: ElError ElLogisticRegression_s( ElConstMatrix_s G, ElConstMatrix_s q, ElMatrix_s z, float gamma, ElRegularization penalty, ElInt* numIts )
.. c:function:: ElError ElLogisticRegression_d( ElConstMatrix_d G, ElConstMatrix_d q, ElMatrix_d z, double gamma, ElRegularization penalty, ElInt* numIts )
.. c:function:: ElError ElLogisticRegressionDist_s( ElConstDistMatrix_s G, ElConstDistMatrix_s q, ElDistMatrix_s z, float gamma, ElRegularization penalty, ElInt* numIts )
.. c:function:: ElError ElLogisticRegressionDist_d( ElConstDistMatrix_d G, ElConstDistMatrix_d q, ElDistMatrix_d z, double gamma, ElRegularization penalty, ElInt* numIts )

