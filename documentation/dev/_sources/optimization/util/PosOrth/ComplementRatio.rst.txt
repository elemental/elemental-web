Complementarity ratio
=====================
Compute the complementarity ratio of the primal-dual pair :math:`(s,z)`, 
:math:`s^T z / n`, where :math:`n` is the degree of the cone (in this case,
the lengths of :math:`s` and :math:`z`).

C++ API
-------
.. cpp:function:: Real pos_orth::ComplementRatio( const Matrix<Real>& s, const Matrix<Real>& z )
.. cpp:function:: Real pos_orth::ComplementRatio( const ElementalMatrix<Real>& s, const ElementalMatrix<Real>& z )
.. cpp:function:: Real pos_orth::ComplementRatio( const DistMultiVec<Real>& s, const DistMultiVec<Real>& z )

C API
-----
**TODO**

Python API
----------
**TODO**
