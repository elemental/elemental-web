Lower norms
===========
Store the lower norms (i.e., :math:`\| x_1 \|_2`, where the member of the
subcone is :math:`(\chi_0;x_1)`) of each subcone and store the norm within the
root entry of said subcone.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::LowerNorms( const Matrix<Real>& x, Matrix<Real>& lowerNorms, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::LowerNorms( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& lowerNorms, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::LowerNorms( const DistMultiVec<Real>& x, DistMultiVec<Real>& lowerNorms, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
