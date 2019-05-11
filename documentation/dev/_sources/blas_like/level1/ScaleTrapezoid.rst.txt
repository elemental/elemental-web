ScaleTrapezoid
==============
Scales the entries within the specified trapezoid of a general matrix.
The parameter conventions follow those of ``MakeTrapezoidal`` described above.

C++ API
-------

.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, Matrix<T>& A, Int offset=0 )
.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, AbstractDistMatrix<T>& A, Int offset=0 )
.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, SparseMatrix<T>& A, Int offset=0 )
.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, DistSparseMatrix<T>& A, Int offset=0 )

C API
-----

.. c:function:: ElError ElScaleTrapezoid_i( ElInt alpha, ElUpperOrLower uplo, ElMatrix_i A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoid_s( float alpha, ElUpperOrLower uplo, ElMatrix_s A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoid_d( double alpha, ElUpperOrLower uplo, ElMatrix_d A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoid_c( complex_float alpha, ElUpperOrLower uplo, ElMatrix_c A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoid_z( complex_double alpha, ElUpperOrLower uplo, ElMatrix_z A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDist_i( ElInt alpha, ElUpperOrLower uplo, ElDistMatrix_i A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDist_s( float alpha, ElUpperOrLower uplo, ElDistMatrix_s A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDist_d( double alpha, ElUpperOrLower uplo, ElDistMatrix_d A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDist_c( complex_float alpha, ElUpperOrLower uplo, ElDistMatrix_c A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDist_z( complex_double alpha, ElUpperOrLower uplo, ElDistMatrix_z A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidSparse_i( ElInt alpha, ElUpperOrLower uplo, ElSparseMatrix_i A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidSparse_s( float alpha, ElUpperOrLower uplo, ElSparseMatrix_s A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidSparse_d( double alpha, ElUpperOrLower uplo, ElSparseMatrix_d A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidSparse_c( complex_float alpha, ElUpperOrLower uplo, ElSparseMatrix_c A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidSparse_z( complex_double alpha, ElUpperOrLower uplo, ElSparseMatrix_z A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDistSparse_i( ElInt alpha, ElUpperOrLower uplo, ElDistSparseMatrix_i A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDistSparse_s( float alpha, ElUpperOrLower uplo, ElDistSparseMatrix_s A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDistSparse_d( double alpha, ElUpperOrLower uplo, ElDistSparseMatrix_d A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDistSparse_c( complex_float alpha, ElUpperOrLower uplo, ElDistSparseMatrix_c A, ElInt offset )
.. c:function:: ElError ElScaleTrapezoidDistSparse_z( complex_double alpha, ElUpperOrLower uplo, ElDistSparseMatrix_z A, ElInt offset )

Python API
----------

.. py:function:: ScaleTrapezoid(alpha,uplo,A,offset=0)
