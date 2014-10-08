MinAbs
======
The following routines return the coordinates and magnitude of the entry with
the smallest absolute value.

C++ API
-------

.. cpp:function:: ValueIntPair<Base<F>> MinAbs( const Matrix<F>& A )
.. cpp:function:: ValueIntPair<Base<F>> MinAbs( const AbstractDistMatrix<F>& A )

.. cpp:function:: ValueIntPair<Base<F>> SymmetricMinAbs( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: ValueIntPair<Base<F>> SymmetricMinAbs( UpperOrLower uplo, const AbstractDistMatrix<F>& A )

.. cpp:function:: ValueInt<Base<F>> VectorMinAbs( const Matrix<F>& x )
.. cpp:function:: ValueInt<Base<F>> VectorMinAbs( const AbstractDistMatrix<F>& x )

C API
-----

.. c:function:: ElError ElMinAbs_i( ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMinAbs_s( ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMinAbs_d( ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMinAbs_c( ElConstMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElMinAbs_z( ElConstMatrix_z A, ElValueIntPair_z* entry )
.. c:function:: ElError ElMinAbsDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElMinAbsDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElMinAbsDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElMinAbsDist_c( ElConstDistMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElMinAbsDist_z( ElConstDistMatrix_z A, ElValueIntPair_z* entry )

.. c:function:: ElError ElSymmetricMinAbs_i( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMinAbs_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMinAbs_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMinAbs_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElSymmetricMinAbs_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElValueIntPair_z* entry )
.. c:function:: ElError ElSymmetricMinAbsDist_i( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry )
.. c:function:: ElError ElSymmetricMinAbsDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry )
.. c:function:: ElError ElSymmetricMinAbsDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry )
.. c:function:: ElError ElSymmetricMinAbsDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElValueIntPair_c* entry )
.. c:function:: ElError ElSymmetricMinAbsDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElValueIntPair_z* entry )

.. c:function:: ElError ElVectorMinAbs_i( ElConstMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMinAbs_s( ElConstMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMinAbs_d( ElConstMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMinAbs_c( ElConstMatrix_c x, ElValueInt_c* entry )
.. c:function:: ElError ElVectorMinAbs_z( ElConstMatrix_z x, ElValueInt_z* entry )
.. c:function:: ElError ElVectorMinAbsDist_i( ElConstDistMatrix_i x, ElValueInt_i* entry )
.. c:function:: ElError ElVectorMinAbsDist_s( ElConstDistMatrix_s x, ElValueInt_s* entry )
.. c:function:: ElError ElVectorMinAbsDist_d( ElConstDistMatrix_d x, ElValueInt_d* entry )
.. c:function:: ElError ElVectorMinAbsDist_c( ElConstDistMatrix_c x, ElValueInt_c* entry )
.. c:function:: ElError ElVectorMinAbsDist_z( ElConstDistMatrix_z x, ElValueInt_z* entry )
