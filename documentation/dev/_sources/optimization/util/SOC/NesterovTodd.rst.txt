Nesterov-Todd scaling point
===========================
Compute the Nesterov-Todd scaling point of the primal-dual pair
:math:`(s,z)` with respect to the relevant product of second-order cones.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::NesterovTodd( const Matrix<Real>& x, const Matrix<Real>& y, Matrix<Real>& w, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::NesterovTodd( const ElementalMatrix<Real>& x, const ElementalMatrix<Real>& y, ElementalMatrix<Real>& w, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::NesterovTodd( const DistMultiVec<Real>& x, const DistMultiVec<Real>& y, DistMultiVec<Real>& w, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
