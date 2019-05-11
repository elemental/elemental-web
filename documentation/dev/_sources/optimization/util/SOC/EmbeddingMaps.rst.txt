Embedding maps
==============
Compute the various mappings related to a sparse embedding of a member of a 
product of second-order cones.

C++ API
-------
.. note::

   The parameter `cutoffSparse` determines whether a subcone is determined 
   large enough for it to be worthwhile to perform a sparse embedding of its
   Hessian (which is diagonal plus rank-one).

.. cpp:function:: void soc::EmbeddingMaps( const Matrix<Int>& orders, const Matrix<Int>& firstInds, Matrix<Int>& sparseOrders, Matrix<Int>& sparseFirstInds, Matrix<Int>& origToSparseOrders, Matrix<Int>& origToSparseFirstInds, Matrix<Int>& sparseToOrigOrders, Matrix<Int>& sparseToOrigFirstInds, Int cutoffSparse )
.. cpp:function:: void soc::EmbeddingMaps( const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, DistMultiVec<Int>& sparseOrders, DistMultiVec<Int>& sparseFirstInds, DistMultiVec<Int>& origToSparseOrders, DistMultiVec<Int>& origToSparseFirstInds, DistMultiVec<Int>& sparseToOrigOrders, DistMultiVec<Int>& sparseToOrigFirstInds, Int cutoffSparse )

C API
-----
**TODO**

Python API
----------
**TODO**
