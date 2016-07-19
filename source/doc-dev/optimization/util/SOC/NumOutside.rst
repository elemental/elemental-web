Number outside of cone
======================
Return the number of members which are outside of their subcone.

C++ API
-------
.. cpp:function:: Int soc::NumOutside( const Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: Int soc::NumOutside( const ElementalMatrix<Real>& x, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: Int soc::NumOutside( const DistMultiVec<Real>& x, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
