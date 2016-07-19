Apply
=====
Apply a member of the Jordan algebra which generates the Second-Order Cone
to another member of the Jordan algebra using the symmetric product,

.. math::

   x \circ y = \begin{bmatrix} x^T y \\ \chi_0 y_1 + \eta_0 x_1 \end{bmatrix},

where :math:`x=(\chi_0;x_1)` and :math:`(\eta_0,y_1)`.

C++ API
-------
.. note::
    
   The `cutoff` parameter only effects parallel performance and is used to 
   decide whether a subcone is sufficiently large to be treated separately.

.. cpp:function:: void soc::Apply( const Matrix<Real>& x, const Matrix<Real>& y, Matrix<Real>& z, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::Apply( const ElementalMatrix<Real>& x, const ElementalMatrix<Real>& y, ElementalMatrix<Real>& z, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::Apply( const DistMultiVec<Real>& x, const DistMultiVec<Real>& y, DistMultiVec<Real>& z, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

.. cpp:function:: void soc::Apply( const Matrix<Real>& x, Matrix<Real>& y, const Matrix<Int>& orders, const Matrix<Int>& firstInds )
.. cpp:function:: void soc::Apply( const ElementalMatrix<Real>& x, ElementalMatrix<Real>& y, const ElementalMatrix<Int>& orders, const ElementalMatrix<Int>& firstInds, Int cutoff=1000 )
.. cpp:function:: void soc::Apply( const DistMultiVec<Real>& x, DistMultiVec<Real>& y, const DistMultiVec<Int>& orders, const DistMultiVec<Int>& firstInds, Int cutoff=1000 )

C API
-----
**TODO**

Python API
----------
**TODO**
