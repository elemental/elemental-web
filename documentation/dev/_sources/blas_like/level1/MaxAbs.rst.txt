MaxAbs
======
The following routines return the coordinates and magnitude of the entry with
the largest absolute value.

C++ API
-------

.. cpp:function:: ValueIntPair<Base<F>> MaxAbs( const Matrix<F>& A )
.. cpp:function:: ValueIntPair<Base<F>> MaxAbs( const AbstractDistMatrix<F>& A )

.. cpp:function:: ValueIntPair<Base<F>> SymmetricMaxAbs( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: ValueIntPair<Base<F>> SymmetricMaxAbs( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: ValueInt<Base<F>> VectorMaxAbs( const Matrix<F>& x )
.. cpp:function:: ValueInt<Base<F>> VectorMaxAbs( const AbstractDistMatrix<F>& x )

C API
-----

.. c:function:: ElError ElMaxAbs_i( ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMaxAbs_s( ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMaxAbs_d( ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMaxAbs_c( ElConstMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElMaxAbs_z( ElConstMatrix_z A, ElValueIntPair_z* entry )
.. c:function:: ElError ElMaxAbsDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMaxAbsDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMaxAbsDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMaxAbsDist_c( ElConstDistMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElMaxAbsDist_z( ElConstDistMatrix_z A, ElValueIntPair_z* entry )

.. c:function:: ElError ElSymmetricMaxAbs_i( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMaxAbs_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMaxAbs_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMaxAbs_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElSymmetricMaxAbs_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElValueIntPair_z* entry )
.. c:function:: ElError ElSymmetricMaxAbsDist_i( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMaxAbsDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMaxAbsDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMaxAbsDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElSymmetricMaxAbsDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElValueIntPair_z* entry )

.. c:function:: ElError ElVectorMaxAbs_i( ElConstMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMaxAbs_s( ElConstMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMaxAbs_d( ElConstMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMaxAbs_c( ElConstMatrix_c x, ElValueInt_c* entry )
.. c:function:: ElError ElVectorMaxAbs_z( ElConstMatrix_z x, ElValueInt_z* entry )
.. c:function:: ElError ElVectorMaxAbsDist_i( ElConstDistMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMaxAbsDist_s( ElConstDistMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMaxAbsDist_d( ElConstDistMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMaxAbsDist_c( ElConstDistMatrix_c x, ElValueInt_c* entry )
.. c:function:: ElError ElVectorMaxAbsDist_z( ElConstDistMatrix_z x, ElValueInt_z* entry )
