Apply quadratic
===============
Apply a member of the Jordan algebra which generates the Second-Order Cone
to another member of the Jordan algebra using the quadratic product,

.. math::

   Q_x(y) = \left(2 x x^T - \text{det}(x) R\right) y,

where :math:`\text{det}(x)` is the determinant of :math:`x` in the sense of the
eigenvalues from the Jordan frame of the Jordan algebra.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::ApplyQuadratic( const Matrix<Real>& x, const Matrix<Real>& y, Matrix<Real>& z, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::ApplyQuadratic( const ElementalMatrix<Real>& x, const ElementalMatrix<Real>& y, ElementalMatrix<Real>& z, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::ApplyQuadratic( const DistMultiVec<Real>& x, const DistMultiVec<Real>& y, DistMultiVec<Real>& z, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

.. cpp:function:: void soc::ApplyQuadratic( const Matrix<Real>& x, Matrix<Real>& y, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::ApplyQuadratic( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& y, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::ApplyQuadratic( const DistMultiVec<Real>& x, DistMultiVec<Real>& y, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
