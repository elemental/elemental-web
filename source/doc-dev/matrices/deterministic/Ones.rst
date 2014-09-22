Ones
====
Create an :math:`m \times n` matrix of all ones.

C++ API
-------

.. cpp:function:: void Ones( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Ones( AbstractDistMatrix<T>& A, Int m, Int n )

C API
-----

.. c:function:: ElError ElOnes_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_z( ElDistMatrix_z A, ElInt m, ElInt n )
