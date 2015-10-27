Ruiz Equilibration
==================
Perform Ruiz diagonal equilibration of a matrix in a way which ensures that
members of subcones are scaled equally (otherwise equilibration would not 
preserve, for example, a Second-Order Cone Program).

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void cone::RuizEquil( Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& dRowA, Matrix<Base<F>>& dRowB, Matrix<Base<F>>& dCol, const Matrix<Int>& orders, const Matrix<Int>& firstInds, bool progress=false )
.. cpp:function:: void cone::RuizEquil( ElementalMatrix<F>& A, ElementalMatrix<F>& B, ElementalMatrix<Base<F>>& dRowA, ElementalMatrix<Base<F>>& dRowB, ElementalMatrix<Base<F>>& dCol, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000, bool progress=false )
.. cpp:function:: void cone::RuizEquil( SparseMatrix<F>& A, SparseMatrix<F>& B, Matrix<Base<F>>& dRowA, Matrix<Base<F>>& dRowB, Matrix<Base<F>>& dCol, const Matrix<Int>& orders, const Matrix<Int>& firstInds, bool progress=false )
.. cpp:function:: void cone::RuizEquil( DistSparseMatrix<F>& A, DistSparseMatrix<F>& B, DistMultiVec<Base<F>>& dRowA, DistMultiVec<Base<F>>& dRowB, DistMultiVec<Base<F>>& dCol, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000, bool progress=false )

C API
-----
**TODO**

Python API
----------
**TODO**
