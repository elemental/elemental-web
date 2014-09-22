Zeros
=====
Create an :math:`m \times n` matrix of all zeros.

C++ API
-------

.. cpp:function:: void Zeros( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Zeros( AbstractDistMatrix<T>& A, Int m, Int n )

C API
-----

.. c:function:: ElError ElZeros_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_z( ElDistMatrix_z A, ElInt m, ElInt n )
