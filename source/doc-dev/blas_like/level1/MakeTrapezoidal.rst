MakeTrapezoidal
===============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Sets all entries outside of the specified trapezoidal submatrix to zero.
Whether or not the trapezoid is upper or lower
(analogous to an upper or lower-triangular matrix) is determined by the 
``uplo`` parameter, and the last diagonal is defined with the ``offset`` 
integer.

C++ API
-------

.. cpp:function:: void MakeTrapezoidal( UpperOrLower uplo, Matrix<T>& A, Int offset=0 )
.. cpp:function:: void MakeTrapezoidal( UpperOrLower uplo, AbstractDistMatrix<T>& A, Int offset=0 )

C API
-----

.. c:function:: ElError ElMakeTrapezoidal_i( ElUpperOrLower uplo, ElMatrix_i A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidal_s( ElUpperOrLower uplo, ElMatrix_s A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidal_d( ElUpperOrLower uplo, ElMatrix_d A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidal_c( ElUpperOrLower uplo, ElMatrix_c A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidal_z( ElUpperOrLower uplo, ElMatrix_z A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidalDist_i( ElUpperOrLower uplo, ElDistMatrix_i A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidalDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidalDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidalDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt offset )
.. c:function:: ElError ElMakeTrapezoidalDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt offset )
