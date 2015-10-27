Inverse
=======
Form the inverse of a member of the Jordan algebra whose squared elements
generate the relevant product of second-order cones.

C++ API
-------
.. note::

   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::Inverse( const Matrix<Real>& x, Matrix<Real>& xInv, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::Inverse( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& xInv, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::Inverse( const DistMultiVec<Real>& x, DistMultiVec<Real>& xInv, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
