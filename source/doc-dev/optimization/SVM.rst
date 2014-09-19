Support vector machines
=======================
Given a set of vectors :math:`\{a_i\}_{i=0}^{n-1} \subset \mathbb{R}^m` and
binary labels :math:`\{\eta_i\} \subset \{0,1\}`, a 
*soft-margin Support Vector Machine* solves the problem

.. math::

   \min_{w,\beta} \frac{1}{n} \sum_{i=0}^{n-1} h(1-\eta_i(w^H a_i - \beta)) +    
   \gamma \| w \|_2^2,

where :math:`h(t)` is the *hinge loss*, or *unit ramp* function, 
which is zero when :math:`t \le 0` and equal to :math:`t` otherwise, and whose
purpose is to linearly penalize the modeled distance of a point from a 
chosen hyperplane separator.

The pair :math:`(w,\beta)` can be interpreted as an unnormalized description
of the hyperplane which approximately partitions the labeled data.
In particular, :math:`w`'s direction is the normal for the hyperplane, 
:math:`\beta/\|w\|_2` is the offset of the plane from the origin in the 
direction of :math:`w`, and :math:`1/\|w\|_2` is the *half-margin* of the 
separator, which is the minimum distance a point can be from the separator 
without being penalized.

.. note::

   While sometimes functional, this implementation is still very much a 
   work-in-progress.

C++ API
-------

.. cpp:function:: Int SVM( const Matrix<Real>& G, const Matrix<Real>& q, Matrix<Real>& z, Real gamma, Real rho=1, Int maxIter=500, bool inv=true, bool progress=true )
.. cpp:function:: Int SVM( const AbstractDistMatrix<Real>& G, const AbstractDistMatrix<Real>& q, AbstractDistMatrix<Real>& z, Real gamma, Real rho=1, Int maxIter=500, bool inv=true, bool progress=true )

C API
-----

.. c:function:: ElError ElSVM_s( ElConstMatrix_s G, ElConstMatrix_s q, ElMatrix_s z, float gamma, ElInt* numIts )
.. c:function:: ElError ElSVM_d( ElConstMatrix_d G, ElConstMatrix_d q, ElMatrix_d z, double gamma, ElInt* numIts )
.. c:function:: ElError ElSVMDist_s( ElConstDistMatrix_s G, ElConstDistMatrix_s q, ElDistMatrix_s z, float gamma, ElInt* numIts )
.. c:function:: ElError ElSVMDist_d( ElConstDistMatrix_d G, ElConstDistMatrix_d q, ElDistMatrix_d z, double gamma, ElInt* numIts )

