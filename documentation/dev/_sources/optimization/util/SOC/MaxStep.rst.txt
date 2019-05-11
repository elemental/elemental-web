Maximum step
============
Return the maximum step size that can be taken in the direction ``ds`` from
the point ``s`` that will remain within the product of second-order cones.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: Real MaxStep( const Matrix<Real>& x, const Matrix<Real>& y, const Matrix<Int>& orders, const Matrix<Int>& firstInds, Real upperBound=std::numeric_limits<Real>::max() )
.. cpp:function:: Real MaxStep( const ElementalMatrix<Real>& x, const ElementalMatrix<Real>& y, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Real upperBound=std::numeric_limits<Real>::max(), Int cutoff=1000 )
.. cpp:function:: Real MaxStep( const DistMultiVec<Real>& x, const DistMultiVec<Real>& y, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Real upperBound=std::numeric_limits<Real>::max(), Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
