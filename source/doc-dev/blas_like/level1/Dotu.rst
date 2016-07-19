Dotu
====
Returns a `\text{vec}(A)^T \text{vec}(B)`.

C++ API
-------
.. cpp:function:: T Dotu( const Matrix<T>& A, const Matrix<T>& B )
.. cpp:function:: T Dotu( const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B )
.. cpp:function:: T Dotu( const DistMultiVec<T>& A, const DistMultiVec<T>& B )

C API
-----
.. c:function:: ElError ElDotu_i( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDotu_s( ElConstMatrix_s A, ElConstMatrix_s B, float* prod )
.. c:function:: ElError ElDotu_d( ElConstMatrix_d A, ElConstMatrix_d B, double* prod )
.. c:function:: ElError ElDotu_c( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotu_z( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotuDist_i( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDotuDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod )
.. c:function:: ElError ElDotuDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod )
.. c:function:: ElError ElDotuDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotuDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotuDistMultiVec_i( ElConstDistMultiVec_i A, ElConstDistMultiVec_i B, ElInt* prod )
.. c:function:: ElError ElDotuDistMultiVec_s( ElConstDistMultiVec_s A, ElConstDistMultiVec_s B, float* prod )
.. c:function:: ElError ElDotuDistMultiVec_d( ElConstDistMultiVec_d A, ElConstDistMultiVec_d B, double* prod )
.. c:function:: ElError ElDotuDistMultiVec_c( ElConstDistMultiVec_c A, ElConstDistMultiVec_c B, complex_float* prod )
.. c:function:: ElError ElDotuDistMultiVec_z( ElConstDistMultiVec_z A, ElConstDistMultiVec_z B, complex_double* prod )

Python API
----------
.. py:function:: Dotu(A,B)
