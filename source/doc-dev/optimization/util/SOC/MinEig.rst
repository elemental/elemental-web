Minimum eigenvalues
===================


C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::MinEig( const Matrix<Real>& x, Matrix<Real>& minEigs, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::MinEig( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& minEigs, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::MinEig( const DistMultiVec<Real>& x, DistMultiVec<Real>& minEigs, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

   Store the minimum eigenvalue of each subcone member within the root entry of
   its subcone.

.. cpp:function:: Real soc::MinEig( const Matrix<Real>& x, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: Real soc::MinEig( const ElementalMatrix<Real>& x, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: Real soc::MinEig( const DistMultiVec<Real>& x, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

   Return the minimum of all of the minimum eigenvalues of each subcone member.

C API
-----
**TODO**

Python API
----------
**TODO**
