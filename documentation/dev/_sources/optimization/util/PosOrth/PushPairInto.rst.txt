Push pair into cone
===================
Push the primal-dual pair :math:`(s,z)`, with Nesterov-Todd scaling point
:math:`w`, into the cone.

C++ API
-------
.. cpp:function:: void pos_orth::PushPairInto( Matrix<Real>& s, Matrix<Real>& z, const Matrix<Real>& w, Real wMaxNormLimit )
.. cpp:function:: void pos_orth::PushPairInto( ElementalMatrix<Real>& s, ElementalMatrix<Real>& z, const ElementalMatrix<Real>& w, Real wMaxNormLimit )
.. cpp:function:: void pos_orth::PushPairInto( DistMultiVec<Real>& s, DistMultiVec<Real>& z, const DistMultiVec<Real>& w, Real wMaxNormLimit )

C API
-----
**TODO**

Python API
----------
**TODO**
