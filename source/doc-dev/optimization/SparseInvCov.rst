Sparse inverse covariance selection
===================================
The following routines attempt to find a sparse inverse covariance matrix
which could generate the given observations. This search is performed by 
attempting to solve the program

.. math::

   \text{min trace}(S Z) - \text{log}\;\text{det}\;Z + 
   \lambda \|\text{vec}(Z)\|_1

using the Alternating Direction Method of Multipliers.

The following functions were inspired by a simple 
`ADMM solver <http://www.stanford.edu/~boyd/papers/admm/covsel/covsel.html>`__ due to Boyd et al.
Elemental's implementations make use of parallel (dense) linear algebra
(including PMRRR for the symmetric tridiagonal eigensolver).

C++ API
-------

.. cpp:function:: Int SparseInvCov( const Matrix<F>& D, Base<F> lambda, Matrix<F>& Z, Base<F> rho=1., Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool progress=true )
.. cpp:function:: Int SparseInvCov( const AbstractDistMatrix<F>& D, Base<F> lambda, AbstractDistMatrix<F>& Z, Base<F> rho=1., Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool progress=true )

`Implementations <https://github.com/elemental/Elemental/blob/master/src/optimization/SparseInvCov.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/optimization/SparseInvCov.cpp>`__

 +------------+--------------+--------------------------------------------+
 | Parameters | Input/Output | Explanation                                |
 +============+==============+============================================+
 | `D`        | Input        | Observations                               |
 +------------+--------------+--------------------------------------------+
 | `Z`        | Output       | primal solution (second term)              |
 +------------+--------------+--------------------------------------------+
 | `lambda`   | Input        | coefficient for vector-l1 penalty          |
 +------------+--------------+--------------------------------------------+
 | `rho`      | Input        | augmented-Lagrangian parameter             |
 +------------+--------------+--------------------------------------------+
 | `alpha`    | Input        | over-relaxation parameter                  |
 |            |              | (usually in :math:`[1,1.8]`)               |
 +------------+--------------+--------------------------------------------+
 | `maxIter`  | Input        | maximum number of ADMM iterations          |
 +------------+--------------+--------------------------------------------+
 | `absTol`   | Input        | absolute convergence tolerance             |
 +------------+--------------+--------------------------------------------+
 | `relTol`   | Input        | relative convergence tolerance             | 
 +------------+--------------+--------------------------------------------+
 | `progress` | Input        | display detailed progress information?     | 
 +------------+--------------+--------------------------------------------+

C API
-----

.. c:function:: ElError ElSparseInvCov_s( ElConstMatrix_s D, float lambda, ElMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCov_d( ElConstMatrix_d D, double lambda, ElMatrix_d Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCov_c( ElConstMatrix_c D, float lambda, ElMatrix_c Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCov_z( ElConstMatrix_z D, double lambda, ElMatrix_z Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCovDist_s( ElConstDistMatrix_s D, float lambda, ElDistMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCovDist_d( ElConstDistMatrix_d D, double lambda, ElDistMatrix_d Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCovDist_c( ElConstDistMatrix_c D, float lambda, ElDistMatrix_c Z, ElInt* numIts )
.. c:function:: ElError ElSparseInvCovDist_z( ElConstDistMatrix_z D, double lambda, ElDistMatrix_z Z, ElInt* numIts )

