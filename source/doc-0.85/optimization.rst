Optimization
************
Elemental contains a variety of routines for solving optimization problems
(currently, first-order methods via ADMM) as well as a collection of common 
utilities, such as Singular Value soft-Thresholding (SVT).

Please note that a large percentage of the following optimizaton routines were 
inspired by `the MATLAB scripts <http://www.stanford.edu/~boyd/papers/admm/>`__ 
associated with the paper:

    `S. Boyd, N. Parikh, E. Chu, B. Peleato, and J. Eckstein, 
    Distributed optimization and statistical learning via the Alternating 
    Direction Method of Multipliers
    <http://www.stanford.edu/~boyd/papers/admm_distr_stats.html>`__,

which describes a wide variety of optimization schemes using the Alternating 
Direction Method of Multipliers (ADMM). 

.. toctree::
   :maxdepth: 1

   optimization/BasisPursuit
   optimization/Lasso
   optimization/LinearProgram
   optimization/LogisticRegression
   optimization/ModelFit
   optimization/NonNegativeLeastSquares
   optimization/NMF
   optimization/QuadraticProgram
   optimization/RPCA
   optimization/SparseInvCov
   optimization/SVM
   optimization/utilities

