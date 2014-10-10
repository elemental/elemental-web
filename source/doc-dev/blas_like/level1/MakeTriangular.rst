MakeTriangular
==============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Sets all entries outside of the specified triangular submatrix to zero.
Whether or not the triangle is upper or lower is determined by the 
``uplo`` parameter.

C++ API
-------

.. cpp:function:: void MakeTriangular( UpperOrLower uplo, Matrix<T>& A )
.. cpp:function:: void MakeTriangular( UpperOrLower uplo, AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElMakeTriangular_i( ElUpperOrLower uplo, ElMatrix_i A )
.. c:function:: ElError ElMakeTriangular_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElMakeTriangular_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElMakeTriangular_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElMakeTriangular_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElMakeTriangularDist_i( ElUpperOrLower uplo, ElDistMatrix_i A )
.. c:function:: ElError ElMakeTriangularDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElMakeTriangularDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElMakeTriangularDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElMakeTriangularDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )
