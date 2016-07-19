Max
===
The following routines return the location and value of the entry with the
maximum value (note: *NOT* the maximum absolute value).

C++ API
-------
.. cpp:function:: ValueIntPair<Real> Max( const Matrix<Real>& A )
.. cpp:function:: ValueIntPair<Real> Max( const AbstractDistMatrix<Real>& A )

.. cpp:function:: ValueIntPair<Real> SymmetricMax( UpperOrLower uplo, const Matrix<Real>& A )
.. cpp:function:: ValueIntPair<Real> SymmetricMax( UpperOrLower uplo, const AbstractDistMatrix<Real>& A )

.. cpp:function:: ValueInt<Real> VectorMax( const Matrix<Real>& x )
.. cpp:function:: ValueInt<Real> VectorMax( const AbstractDistMatrix<Real>& x )

C API
-----
.. c:function:: ElError ElMax_i( ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMax_s( ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMax_d( ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMaxDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMaxDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMaxDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry )

.. c:function:: ElError ElSymmetricMax_i( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMax_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMax_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMaxDist_i( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMaxDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMaxDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry )

.. c:function:: ElError ElVectorMax_i( ElConstMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMax_s( ElConstMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMax_d( ElConstMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMaxDist_i( ElConstDistMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMaxDist_s( ElConstDistMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMaxDist_d( ElConstDistMatrix_d x, ElValueInt_d* entry )

Python API
----------
**TODO**
