AllReduce
=========
Fill each subcone with the reduction (in some cases, sum) of the members of the
subcone.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void cone::AllReduce( Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds, mpi::Op op=mpi::SUM )
.. cpp:function:: void cone::AllReduce( ElementalMatrix<Real>& x, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, mpi::Op op=mpi::SUM, Int cutoff=1000 )
.. cpp:function:: void cone::AllReduce( DistMultiVec<Real>& x, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, mpi::Op op=mpi::SUM, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
