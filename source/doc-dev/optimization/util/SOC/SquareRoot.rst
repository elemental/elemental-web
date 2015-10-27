Square-root
===========
Form the square-root of a member of the Jordan algebra whose squared elements
generate the relevant product of second-order cones.

C++ API
-------
.. note::

   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::SquareRoot( const Matrix<Real>& x, Matrix<Real>& xRoot, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::SquareRoot( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& xRoot, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::SquareRoot( const DistMultiVec<Real>& x, DistMultiVec<Real>& xRoot, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
