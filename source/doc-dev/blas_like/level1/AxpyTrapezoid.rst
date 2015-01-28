AxpyTrapezoid
=============
Performs the trapezoidal portion of an axpy :math:`Y := \alpha X + Y`;
the trapezoid is defined by the ``uplo`` and ``offset`` parameters, where 
``offset`` determines which sub or superdiagonal to use as the cutoff for the
upper or lower-trapezoidal portion of the update.

C++ API
-------
.. cpp:function:: void AxpyTrapezoid( UpperOrLower uplo, S alpha, const Matrix<T>& X, Matrix<T>& Y, Int offset=0 )
.. cpp:function:: void AxpyTrapezoid( UpperOrLower uplo, S alpha, const AbstractDistMatrix<T>& X, AbstractDistMatrix<T>& Y, Int offset=0 )
.. cpp:function:: void AxpyTrapezoid( UpperOrLower uplo, S alpha, const SparseMatrix<T>& X, SparseMatrix<T>& Y, Int offset=0 )
.. cpp:function:: void AxpyTrapezoid( UpperOrLower uplo, S alpha, const DistSparseMatrix<T>& X, DistSparseMatrix<T>& Y, Int offset=0 )

C API
-----
.. c:function:: ElError ElAxpyTrapezoid_i( UpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoid_s( UpperOrLower uplo, float alpha, ElConstMatrix_s X, ElMatrix_s Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoid_d( UpperOrLower uplo, double alpha, ElConstMatrix_d X, ElMatrix_d Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoid_c( UpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoid_z( UpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDist_i( UpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDist_s( UpperOrLower uplo, float alpha, ElConstMatrix_s X, ElMatrix_s Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDist_d( UpperOrLower uplo, double alpha, ElConstMatrix_d X, ElMatrix_d Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDist_c( UpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDist_z( UpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidSparse_i( UpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidSparse_s( UpperOrLower uplo, float alpha, ElConstMatrix_s X, ElMatrix_s Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidSparse_d( UpperOrLower uplo, double alpha, ElConstMatrix_d X, ElMatrix_d Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidSparse_c( UpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidSparse_z( UpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDistSparse_i( UpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDistSparse_s( UpperOrLower uplo, float alpha, ElConstMatrix_s X, ElMatrix_s Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDistSparse_d( UpperOrLower uplo, double alpha, ElConstMatrix_d X, ElMatrix_d Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDistSparse_c( UpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y, ElInt offset )
.. c:function:: ElError ElAxpyTrapezoidDistSparse_z( UpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y, ElInt offset )

Python API
----------
.. py:function:: AxpyTrapezoid(uplo,alpha,X,Y,offset=0)
