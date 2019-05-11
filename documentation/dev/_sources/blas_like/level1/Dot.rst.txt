Dot
===
Returns :math:`\langle A,B \rangle = \text{vec}(A)^H \text{vec}(B)`. Note that
this is precisely a Hilbert-Schmidt inner product.

C++ API
-------
.. cpp:function:: T Dot( const Matrix<T>& A, const Matrix<T>& B )
.. cpp:function:: T Dot( const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B )
.. cpp:function:: T Dot( const DistMultiVec<T>& A, const DistMultiVec<T>& B )

C API
-----
.. c:function:: ElError ElDot_i( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDot_s( ElConstMatrix_s A, ElConstMatrix_s B, float* prod )
.. c:function:: ElError ElDot_d( ElConstMatrix_d A, ElConstMatrix_d B, double* prod )
.. c:function:: ElError ElDot_c( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDot_z( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotDist_i( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDotDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod )
.. c:function:: ElError ElDotDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod )
.. c:function:: ElError ElDotDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotDistMultiVec_i( ElConstDistMultiVec_i A, ElConstDistMultiVec_i B, ElInt* prod )
.. c:function:: ElError ElDotDistMultiVec_s( ElConstDistMultiVec_s A, ElConstDistMultiVec_s B, float* prod )
.. c:function:: ElError ElDotDistMultiVec_d( ElConstDistMultiVec_d A, ElConstDistMultiVec_d B, double* prod )
.. c:function:: ElError ElDotDistMultiVec_c( ElConstDistMultiVec_c A, ElConstDistMultiVec_c B, complex_float* prod )
.. c:function:: ElError ElDotDistMultiVec_z( ElConstDistMultiVec_z A, ElConstDistMultiVec_z B, complex_double* prod )

Python API
----------
.. py:function:: Dot(A,B)
