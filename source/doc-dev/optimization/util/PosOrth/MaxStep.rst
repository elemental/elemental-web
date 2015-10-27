Maximum step
============
Compute the maximum step in the direction ``ds`` that can be taken from the
point ``s`` that will still lie in the positive orthant.

C++ API
-------
.. cpp:function:: Real pos_orth::MaxStep( const Matrix<Real>& s, const Matrix<Real>& ds, Real upperBound=std::numeric_limits<Real>::max() )
.. cpp:function:: Real pos_orth::MaxStep( const ElementalMatrix<Real>& s, const ElementalMatrix<Real>& ds, Real upperBound=std::numeric_limits<Real>::max() )
.. cpp:function:: Real pos_orth::MaxStep( const DistMultiVec<Real>& s, const DistMultiVec<Real>& ds, Real upperBound=std::numeric_limits<Real>::max() )

C API
-----
**TODO**

Python API
----------
**TODO**
