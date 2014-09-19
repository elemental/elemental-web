Linear programs
===============
The following routines attempt to solve linear programs of the form

.. math::
   
   \text{min}\, c^T z \;\;\;\text{such that }Az=b,\; z \ge 0.

using the Alternating Direction Method of Multipliers.

The following functions were inspired by a simple 
`ADMM linear program solver <http://www.stanford.edu/~boyd/papers/admm/linprog/linprog.html>`__ due to Boyd et al.
Elemental's implementations make use of parallel (dense) linear algebra, 
a custom structured factorization, and allows the user to optionally 
directly invert the (pivoted) Schur complement to accelerate its 
application. The return value is the number of performed ADMM iterations.

C++ API
-------

.. cpp:function:: Int LinearProgram( const Matrix<Real>& A, const Matrix<Real>& b, const Matrix<Real>& c, Matrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=false, bool progress=true )
.. cpp:function:: Int LinearProgram( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& b, const AbstractDistMatrix<Real>& c, AbstractDistMatrix<Real>& z, Real rho=1., Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

`Implementation <https://github.com/elemental/Elemental/blob/master/src/optimization/LinearProgram.cpp>`__

 `Example driver <https://github.com/elemental/Elemental/blob/master/examples/optimization/LinearProgram.cpp>`__

 +------------+--------------+--------------------------------------------+
 | Parameters | Input/Output | Explanation                                |
 +============+==============+============================================+
 | `A`        | Input        | part of constraints, :math:`Ax=b`          |
 +------------+--------------+--------------------------------------------+
 | `b`        | Input        | part of constraints, :math:`Ax=b`          |
 +------------+--------------+--------------------------------------------+
 | `c`        | Input        | part of the objective, :math:`c^T x`       |
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
 | `inv`      | Input        | directly compute Schur-complement inverse? |
 +------------+--------------+--------------------------------------------+
 | `progress` | Input        | display detailed progress information?     | 
 +------------+--------------+--------------------------------------------+

C API
-----

.. c:function:: ElError ElLinearProgram_s( ElConstMatrix_s A, ElConstMatrix_s b, ElConstMatrix_s c, ElMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElLinearProgram_d( ElConstMatrix_d A, ElConstMatrix_d b, ElConstMatrix_d c, ElMatrix_d z, ElInt* numIts )
.. c:function:: ElError ElLinearProgramDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s b, ElConstDistMatrix_s c, ElDistMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElLinearProgramDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d b, ElConstDistMatrix_d c, ElDistMatrix_d z, ElInt* numIts )

