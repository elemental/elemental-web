Push pair into cone
===================
Given a primal-dual pair :math:`(s,z)`, with Nesterov-Todd scaling point 
:math:`w`, push each subvector of :math:`s` and :math:`z` into the relevant
second-order cone.

C++ API
-------
.. cpp:function:: void soc::PushPairInto( Matrix<Real>& s, Matrix<Real>& z, const Matrix<Real>& w, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Real minDist=0 )
.. cpp:function:: void soc::PushPairInto( ElementalMatrix<Real>& s, ElementalMatrix<Real>& z, const ElementalMatrix<Real>& w, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Real minDist=0, Int cutoff=1000 )
.. cpp:function:: void soc::PushPairInto( DistMultiVec<Real>& s, DistMultiVec<Real>& z, const DistMultiVec<Real>& w, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Real minDist=0, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
