Trdtrmm
=======
.. note:: 

   This is a modification of Trtrmm for LDL factorizations.

Symmetric/Hermitian triangular matrix-matrix multiply (with diagonal scaling): 
performs :math:`L := L^T D^{-1} L`, :math:`L := L^H D^{-1} L`, 
:math:`U := U D^{-1} U^T`, or :math:`U := U D^{-1} U^H`, 
depending upon the choice of the `orientation` and `uplo` parameters. 
Note that :math:`L` and :math:`U` are unit-diagonal and their diagonal is 
overwritten with :math:`D`.

C++ API
-------

.. cpp:function:: void Trdtrmm( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false )
.. cpp:function:: void Trdtrmm( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool conjugate=false )

.. cpp:function:: void Trdtrmm( UpperOrLower uplo, Matrix<F>& A, const Matrix<F>& dSub, bool conjugate=false )
.. cpp:function:: void Trdtrmm( UpperOrLower uplo, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& dSub, bool conjugate=false )

   An extension to quasi-diagonal :math:`D`, where the main diagonal is stored
   over the main diagonal of `A` and the subdiagonal is given by `dSub`.

C API
-----

.. c:function:: ElError ElTrdtrmm_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElTrdtrmm_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElTrdtrmm_c( ElUpperOrLower uplo, ElMatrix_c A, bool conjugate )
.. c:function:: ElError ElTrdtrmm_z( ElUpperOrLower uplo, ElMatrix_z A, bool conjugate )
.. c:function:: ElError ElTrdtrmmDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElTrdtrmmDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElTrdtrmmDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, bool conjugate )
.. c:function:: ElError ElTrdtrmmDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, bool conjugate )

.. c:function:: ElError ElTrdtrmmQuasi_s( ElUpperOrLower uplo, ElMatrix_s A, ElConstMatrix_s dOff )
.. c:function:: ElError ElTrdtrmmQuasi_d( ElUpperOrLower uplo, ElMatrix_d A, ElConstMatrix_d dOff )
.. c:function:: ElError ElTrdtrmmQuasi_c( ElUpperOrLower uplo, ElMatrix_c A, ElConstMatrix_c dOff, bool conjugate )
.. c:function:: ElError ElTrdtrmmQuasi_z( ElUpperOrLower uplo, ElMatrix_z A, ElConstMatrix_z dOff, bool conjugate )
.. c:function:: ElError ElTrdtrmmQuasiDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElConstDistMatrix_s dOff )
.. c:function:: ElError ElTrdtrmmQuasiDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElConstDistMatrix_d dOff )
.. c:function:: ElError ElTrdtrmmQuasiDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElConstDistMatrix_c dOff, bool conjugate )
.. c:function:: ElError ElTrdtrmmQuasiDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElConstDistMatrix_z dOff, bool conjugate )

Python API
----------

.. py:function:: Trdtrmm(uplo,A,conjugate=False)
.. py:function:: TrdtrmmQuasi(uplo,A,dSub,conjugate=False)
