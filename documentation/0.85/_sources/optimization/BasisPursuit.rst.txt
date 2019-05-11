Basis pursuit
=============
The minimization problem

.. math::

   \min_z \| z \|_1 \text{ such that } A z = b,

is referred to as *basis pursuit* and is well-known to promote sparse solutions.

The following functions were inspired by a simple 
`basis pursuit ADMM implementation <http://www.stanford.edu/~boyd/papers/admm/basis_pursuit/basis_pursuit.html>`__ due to Boyd et al.
Elemental's implementations use parallel (dense) linear algebra and allows the
user to choose between either directly computing a 
(thresholded-)pseudoinverse or an LQ factorization. The return value is the 
number of performed ADMM iterations.

C++ API
-------

.. cpp:function:: Int BasisPursuit( const Matrix<F>& A, const Matrix<F>& b, Matrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=false, Base<F> pinvTol=0, bool progress=true )
.. cpp:function:: Int BasisPursuit( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& b, AbstractDistMatrix<F>& z, Base<F> rho=1, Base<F> alpha=1.2, Int maxIter=500, Base<F> absTol=1e-6, Base<F> relTol=1e-4, bool usePinv=false, Base<F> pinvTol=0, bool progress=true )

`Implementation <https://github.com/elemental/Elemental/blob/master/src/optimization/BasisPursuit.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/optimization/BasisPursuit.cpp>`__

 +------------+--------------+----------------------------------------+
 | Parameters | Input/Output | Explanation                            |
 +============+==============+========================================+
 | `A`        | Input        | part of constraint :math:`Ax=b`        |
 +------------+--------------+----------------------------------------+
 | `b`        | Input        | part of constraint :math:`Ax=b`        |
 +------------+--------------+----------------------------------------+
 | `z`        | Output       | primal solution (second term)          |
 +------------+--------------+----------------------------------------+
 | `rho`      | Input        | augmented-Lagrangian parameter         |
 +------------+--------------+----------------------------------------+
 | `alpha`    | Input        | over-relaxation parameter              |
 |            |              | (usually in :math:`[1,1.8]`)           |
 +------------+--------------+----------------------------------------+
 | `maxIter`  | Input        | maximum number of ADMM iterations      |
 +------------+--------------+----------------------------------------+
 | `absTol`   | Input        | absolute convergence tolerance         |
 +------------+--------------+----------------------------------------+
 | `relTol`   | Input        | relative convergence tolerance         | 
 +------------+--------------+----------------------------------------+
 | `usePinv`  | Input        | directly compute a pseudoinverse?      |
 +------------+--------------+----------------------------------------+
 | `pinvTol`  | Input        | the pseudoinverse inversion tolerance  |
 +------------+--------------+----------------------------------------+
 | `progress` | Input        | display detailed progress information? | 
 +------------+--------------+----------------------------------------+

C API
-----

.. c:function:: ElError ElBasisPursuit_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuit_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuit_c( ElConstMatrix_c A, ElConstMatrix_c b, ElMatrix_c z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuit_z( ElConstMatrix_z A, ElConstMatrix_z b, ElMatrix_z z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuitDist_s( ElConstMatrix_s A, ElConstMatrix_s b, ElMatrix_s z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuitDist_d( ElConstMatrix_d A, ElConstMatrix_d b, ElMatrix_d z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuitDist_c( ElConstMatrix_c A, ElConstMatrix_c b, ElMatrix_c z, ElInt* numIts )
.. c:function:: ElError ElBasisPursuitDist_z( ElConstMatrix_z A, ElConstMatrix_z b, ElMatrix_z z, ElInt* numIts )

**TODO: Expert versions**

