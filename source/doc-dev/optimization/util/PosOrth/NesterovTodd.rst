Nesterov-Todd scaling point
===========================
Compute the (positive-orthant) Nesterov-Todd scaling point for the primal-dual
pair :math:`(s,z)`.

C++ API
-------
.. cpp:function:: void pos_orth::NesterovTodd( const Matrix<Real>& s, const Matrix<Real>& z, Matrix<Real>& w )
.. cpp:function:: void pos_orth::NesterovTodd( const ElementalMatrix<Real>& s, const ElementalMatrix<Real>& z, ElementalMatrix<Real>& w )
.. cpp:function:: void pos_orth::NesterovTodd( const DistMultiVec<Real>& s, const DistMultiVec<Real>& z, DistMultiVec<Real>& w )

C API
-----
**TODO**

Python API
----------
**TODO**
