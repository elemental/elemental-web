Model fit
=========
Rather than fitting a model 

.. math::

   \min_z l(A z + b) + r(z),

via a specific choice of a *loss* function, :math:`l`, and regularization 
function, :math:`r`, such as for a support vector machine or logistic 
regression, the following routines accept function wrappers for the proximal
maps said functions and execute an Alternating Direction Method of Multipliers.

.. note::

   While sometimes functional, this implementation is still very much a 
   work-in-progress.

C++ API
-------

.. cpp:function:: Int ModelFit( std::function<void(Matrix<Real>&,Real)> lossProx, std::function<void(Matrix<Real>&,Real)> regProx, const Matrix<Real>& A, const Matrix<Real>& b, Matrix<Real>& w, Real rho, Int maxIter=1000, bool inv=true, bool progress=true )
.. cpp:function:: Int ModelFit( std::function<void(DistMatrix<Real>&,Real)> lossProx, std::function<void(DistMatrix<Real>&,Real)> regProx, const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, AbstractDistMatrix<Real>& w, Real rho, Int maxIter=1000, bool inv=true, bool progress=true )

C API
-----

.. c:function:: ElError ElModelFit_s( void (*lossProx)(ElMatrix_s,float), void (*regProx)(ElMatrix_s,float), ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s w, float rho, ElInt* numIts )
.. c:function:: ElError ElModelFit_d( void (*lossProx)(ElMatrix_d,double), void (*regProx)(ElMatrix_d,double), ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d w, double rho, ElInt* numIts )
.. c:function:: ElError ElModelFitDist_s( void (*lossProx)(ElDistMatrix_s,float), void (*regProx)(ElDistMatrix_s,float), ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElDistMatrix_s w, float rho, ElInt* numIts )
.. c:function:: ElError ElModelFitDist_d( void (*lossProx)(ElDistMatrix_d,double), void (*regProx)(ElDistMatrix_d,double), ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElDistMatrix_d w, double rho, ElInt* numIts )
