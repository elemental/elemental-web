Zero
====
.. note::
   
   This is not a standard BLAS routine, but it is BLAS-like.

Sets all of the entries of the input matrix to zero.

C++ API
-------

.. cpp:function:: void Zero( Matrix<T>& A )
.. cpp:function:: void Zero( AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElZero_i( ElMatrix_i A )
.. c:function:: ElError ElZero_s( ElMatrix_s A )
.. c:function:: ElError ElZero_d( ElMatrix_d A )
.. c:function:: ElError ElZero_c( ElMatrix_c A )
.. c:function:: ElError ElZero_z( ElMatrix_z A )
.. c:function:: ElError ElZeroDist_i( ElDistMatrix_i A )
.. c:function:: ElError ElZeroDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElZeroDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElZeroDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElZeroDist_z( ElDistMatrix_z A )


