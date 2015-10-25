NormalFromEVD
=============
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega` is a complex diagonal matrix with diagonal entries given
by the vector :math:`w`.

C++ API
-------

.. cpp:function:: void NormalFromEVD( Matrix<Complex<Real> >& A, const Matrix<Complex<Real> >& w, const Matrix<Complex<Real> >& Z )
.. cpp:function:: void NormalFromEVD( ElementalMatrix<Complex<Real> >& A, const ElementalMatrix<Complex<Real>>& w, const ElementalMatrix<Complex<Real> >& Z )

C API
-----

.. c:function:: ElError ElNormalFromEVD_c( ElMatrix_c A, ElConstMatrix_c w, ElConstMatrix_c Z )
.. c:function:: ElError ElNormalFromEVD_z( ElMatrix_z A, ElConstMatrix_z w, ElConstMatrix_z Z )
.. c:function:: ElError ElNormalFromEVDDist_c( ElDistMatrix_c A, ElConstDistMatrix_c w, ElConstDistMatrix_c Z )
.. c:function:: ElError ElNormalFromEVDDist_z( ElDistMatrix_z A, ElConstDistMatrix_z w, ElConstDistMatrix_z Z )

Python API
----------

.. py:function:: NormalFromEVD(A,w,Z)
