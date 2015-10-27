Determinants
============
Store the (Jordan algebra) determinants of each member of the 
product of second-order cones within the root entry of each subcone.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::Dets( const Matrix<Real>& x, Matrix<Real>& d, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::Dets( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& d, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::Dets( const DistMultiVec<Real>& x, DistMultiVec<Real>& d, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
