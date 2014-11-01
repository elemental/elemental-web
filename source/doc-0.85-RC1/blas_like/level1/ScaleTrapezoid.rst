ScaleTrapezoid
==============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Scales the entries within the specified trapezoid of a general matrix.
The parameter conventions follow those of ``MakeTrapezoidal`` described above.

C++ API
-------

.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, Matrix<T>& A, Int offset=0 )
.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, AbstractDistMatrix<T>& A, Int offset=0 )

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
