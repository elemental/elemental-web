Least absolute shrinkage and selection operator
===============================================
The *least absolute shrinkage and selection operator* (lasso) solves the
problem

.. math::

   \min_z \frac{1}{2} \| A z - b \|_2^2 + \lambda \| z \|_1,

where the :math:`\ell_1` penalty coefficient, :math:`\lambda`, provides a 
tradeoff between sparsity and fidelity. 

The following routines make use of Alternating Direction Method of Multipliers
techniques for finding approximate solutions and are inspired by a simple
`MATLAB script <http://www.stanford.edu/~boyd/papers/admm/lasso/lasso.html>`__
due to Boyd et al.

C++ API
-------

.. cpp:function:: Int Lasso( const Matrix<F>& A, const Matrix<F>& b, Base<F> lambda, Matrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool inv=true, bool progress=true )
.. cpp:function:: Int Lasso( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& b, Base<F> lambda, AbstractDistMatrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool inv=true, bool progress=true )

**TODO: Discussion of parameters**

C API
-----

.. c:function:: ElError ElLasso_s( ElConstMatrix_s A, ElConstMatrix_s b, float lambda, ElMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElLasso_d( ElConstMatrix_d A, ElConstMatrix_d b, double lambda, ElMatrix_d z, ElInt* numIts )
.. c:function:: ElError ElLasso_c( ElConstMatrix_c A, ElConstMatrix_c b, float lambda, ElMatrix_c z, ElInt* numIts )
.. c:function:: ElError ElLasso_z( ElConstMatrix_z A, ElConstMatrix_z b, double lambda, ElMatrix_z z, ElInt* numIts )
.. c:function:: ElError ElLassoDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, float lambda, ElDistMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElLassoDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, double lambda, ElDistMatrix_d z, ElInt* numIts )
.. c:function:: ElError ElLassoDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c b, float lambda, ElDistMatrix_c z, ElInt* numIts )
.. c:function:: ElError ElLassoDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z b, double lambda, ElDistMatrix_z z, ElInt* numIts )
