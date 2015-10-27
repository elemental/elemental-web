Dot products
============
Store the dot products between each corresponding subcone of 
two vectors :math:`x` and :math:`y` within the root position of 
each subcone of the output vector.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::Dots( const Matrix<Real>& x, const Matrix<Real>& y, Matrix<Real>& z, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::Dots( const ElementalMatrix<Real>& x, const ElementalMatrix<Real>& y, ElementalMatrix<Real>& z, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::Dots( const DistMultiVec<Real>& x, const DistMultiVec<Real>& y, DistMultiVec<Real>& z, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
