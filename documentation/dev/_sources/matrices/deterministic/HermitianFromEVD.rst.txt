Hermitian from EVD
==================
Construct a Hermitian matrix from its spectral decomposition,
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega=\text{diag}(w)` and :math:`w` is real.

C++ API
-------

.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, Matrix<F>& A, const Matrix<Base<F>>& w, const Matrix<F>& Z )
.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, ElementalMatrix<F>& A, const ElementalMatrix<Base<F>>& w, const ElementalMatrix<F>& Z )

C API
-----

.. c:function:: ElError ElHermitianFromEVD_s( ElUpperOrLower uplo, ElMatrix_s A, ElConstMatrix_s w, ElConstMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVD_d( ElUpperOrLower uplo, ElMatrix_d A, ElConstMatrix_d w, ElConstMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVD_c( ElUpperOrLower uplo, ElMatrix_c A, ElConstMatrix_s w, ElConstMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVD_z( ElUpperOrLower uplo, ElMatrix_z A, ElConstMatrix_d w, ElConstMatrix_z Z )
.. c:function:: ElError ElHermitianFromEVDDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElConstDistMatrix_s w, ElConstDistMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVDDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElConstDistMatrix_d w, ElConstDistMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVDDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElConstDistMatrix_s w, ElConstDistMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVDDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElConstDistMatrix_d w, ElConstDistMatrix_z Z )

Python API
----------

.. py:function:: HermitianFromEVD(uplo,A,w,Z)
