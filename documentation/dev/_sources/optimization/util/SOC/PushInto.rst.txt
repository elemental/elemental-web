Push into cone
==============
Push a vector into the relevant product of second-order cones.

C++ API
-------
.. cpp:function:: void soc::PushInto( Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Real minDist=0 )
.. cpp:function:: void soc::PushInto( ElementalMatrix<Real>& x, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Real minDist=0, Int cutoff=1000 )
.. cpp:function:: void soc::PushInto( DistMultiVec<Real>& x, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Real minDist=0, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
