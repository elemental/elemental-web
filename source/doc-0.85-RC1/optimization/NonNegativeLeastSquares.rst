Non-negative least squares
==========================
A *non-negative least squares problem* seeks a solution to the problem

.. math::

   \min_x \| A z - y \|_2 \text{ such that } z \ge 0.

The following routines attempt to solve such problems by recognizing the 
equivalence to the quadratic program

.. math::

  \min_z \frac{1}{2} z^T P z + q^T z \text{ such that } z \ge 0

with :math:`P = A^T A` and :math:`q = -A^T y`.

C++ API
-------

.. cpp:function:: Int NonNegativeLeastSquares( const Matrix<Real>& A, const Matrix<Real>& Y, Matrix<Real>& Z, Real rho=1, Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )
.. cpp:function:: Int NonNegativeLeastSquares( const AbstractDistMatrix<Real>& A, const AbstractDistMatrix<Real>& Y, AbstractDistMatrix<Real>& Z, Real rho=1, Real alpha=1.2, Int maxIter=500, Real absTol=1e-6, Real relTol=1e-4, bool inv=true, bool progress=true )

C API
-----

.. c:function:: ElError ElNonNegativeLeastSquares_s( ElConstMatrix_s A, ElConstMatrix_s Y, ElMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElNonNegativeLeastSquares_d( ElConstMatrix_d A, ElConstMatrix_d Y, ElMatrix_d Z, ElInt* numIts )
.. c:function:: ElError ElNonNegativeLeastSquaresDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s Y, ElDistMatrix_s Z, ElInt* numIts )
.. c:function:: ElError ElNonNegativeLeastSquaresDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d Y, ElDistMatrix_d Z, ElInt* numIts )

