Quadratic programs
==================
The following routines attempt to solve quadratic programs of the form

.. math::

   \text{min} \frac{1}{2} z^T P z + q^T z\;\;\;\text{such that }l_b 
   \le z \le u_b

using the Alternating Direction Method of Multipliers. 

These functions are inspired by a simple 
`ADMM quadratic program solver <http://www.stanford.edu/~boyd/papers/admm/quadprog/quadprog.html>`__ 
due to Boyd et al.
Elemental's implementations make use of parallel (dense) linear algebra 
and allows the user to optionally directly invert the Cholesky factor to 
improve the parallel performance of the application of its inverse.

C++ API
-------

.. cpp:function:: Int QuadraticProgram( const Matrix<Real>& P, const Matrix<Real>& q, Real lb, Real ub, Matrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: Int QuadraticProgram( const AbstractDistMatrix<Real>& P, const AbstractDistMatrix<Real>& q, Real lb, Real ub, AbstractDistMatrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

 `Implementations <https://github.com/elemental/Elemental/blob/master/src/optimization/QuadraticProgram.cpp>`__

 `Example driver <https://github.com/elemental/Elemental/blob/master/examples/optimization/QuadraticProgram.cpp>`__

 +------------+--------------+--------------------------------------------+
 | Parameters | Input/Output | Explanation                                |
 +============+==============+============================================+
 | `P`        | Input        | SPD and part of objective,                 |
 |            |              | :math:`\frac{1}{2}x^T P x + q^T x`         |
 +------------+--------------+--------------------------------------------+
 | `q`        | Input        | part of objective                          |
 +------------+--------------+--------------------------------------------+
 | `lb`       | Input        | lower-bound of constraints,                |
 |            |              | :math:`l_b \le x \le u_b`                  |
 +------------+--------------+--------------------------------------------+
 | `ub`       | Input        | upper-bound of constraints,                |
 |            |              | :math:`l_b \le x \le u_b`                  |
 +------------+--------------+--------------------------------------------+
 | `z`        | Output       | primal solution (second term)              |
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
 | `inv`      | Input        | compute inverse of Cholesky factor?        |
 +------------+--------------+--------------------------------------------+
 | `progress` | Input        | display detailed progress information?     | 
 +------------+--------------+--------------------------------------------+

C API
-----

.. c:function:: ElError ElQuadraticProgram_s( ElConstMatrix_s P, ElConstMatrix_s S, float lb, float ub, ElMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElQuadraticProgram_d( ElConstMatrix_d P, ElConstMatrix_d S, double lb, double ub, ElMatrix_d Z, ElInt* numIts )
.. c:function:: ElError ElQuadraticProgramDist_s( ElConstDistMatrix_s P, ElConstDistMatrix_s S, float lb, float ub, ElDistMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElQuadraticProgramDist_d( ElConstDistMatrix_d P, ElConstDistMatrix_d S, double lb, double ub, ElDistMatrix_d Z, ElInt* numIts )

