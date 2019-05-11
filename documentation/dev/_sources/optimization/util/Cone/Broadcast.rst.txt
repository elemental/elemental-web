Broadcast
=========
Replicate the entry in the root position of each member cone over the entire
cone.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void cone::Broadcast( Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void cone::Broadcast( ElementalMatrix<Real>& x, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void cone::Broadcast( DistMultiVec<Real>& x, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
