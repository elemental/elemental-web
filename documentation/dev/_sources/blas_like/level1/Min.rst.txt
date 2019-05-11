Min
===
The following routines return the location and value of the entry with the
minimum value (note: *NOT* the minimum absolute value).

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
.. c:function:: ElError ElMin_i( ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMin_s( ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMin_d( ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMinDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMinDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMinDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry )

.. c:function:: ElError ElSymmetricMin_i( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMin_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMin_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMinDist_i( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMinDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMinDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry )

.. c:function:: ElError ElVectorMin_i( ElConstMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMin_s( ElConstMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMin_d( ElConstMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMinDist_i( ElConstDistMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMinDist_s( ElConstDistMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMinDist_d( ElConstDistMatrix_d x, ElValueInt_d* entry )

Python API
----------
**TODO**
