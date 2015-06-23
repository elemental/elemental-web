Optimization
************
Elemental currently supports distributed dense and sparse Linear, Quadratic,
and Second-Order Cone Programs via Mehrotra Predictor-Corrector primal-dual 
Interior Point Methods (though geometric and semidefinite support is also 
planned).
In addition to building on top of these backends to provide support for 
basis pursuit (BP), basis pursuit denoising (BPDN) / least absolute shrinkage and selection operator (LASSO), Chebyshev points (CP), Dantzig selectors (DS), non-negative least squares (NNLS), and (soft-margin) Support Vector Machines (SVM), `alternating direction and operator splitting <http://web.stanford.edu/~boyd/papers/scs.html>`__ methods for more general 
routines are currently being explored.

.. toctree::
   :maxdepth: 1

   optimization/solvers
   optimization/models
   optimization/prox
   optimization/util

