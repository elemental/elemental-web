Trtrmm
======
.. note:: 

   This routine loosely corresponds with the LAPACK routines ?lauum.

Symmetric/Hermitian triangular matrix-matrix multiply: performs
:math:`L := L^T L`, :math:`L := L^H L`, :math:`U := U U^T`, or 
:math:`U := U U^H`, depending upon the choice of the `orientation` and 
`uplo` parameters. 

.. note::

   For the best performance, `A` should be in a [MC,MR] distribution.

C++ API
-------

.. cpp:function:: void Trtrmm( UpperOrLower uplo, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Trtrmm( UpperOrLower uplo, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
-----

.. c:function:: ElError ElTrtrmm_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElTrtrmm_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElTrtrmm_c( ElUpperOrLower uplo, ElMatrix_c A, bool conjugate )
.. c:function:: ElError ElTrtrmm_z( ElUpperOrLower uplo, ElMatrix_z A, bool conjugate )
.. c:function:: ElError ElTrtrmmDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElTrtrmmDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElTrtrmmDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, bool conjugate )
.. c:function:: ElError ElTrtrmmDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, bool conjugate )

Python API
----------

.. py:function:: Trtrmm(uplo,A,conjugate=False)
