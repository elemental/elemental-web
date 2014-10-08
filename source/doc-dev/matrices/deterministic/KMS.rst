KMS
===
An :math:`n \times n` *KMS matrix* with parameter :math:`\rho` is a 
skew-Hermitian matrix such that

.. math::

   A(i,j) = \rho^{j-i},\;\;\; i <= j.

C++ API
-------

.. cpp:function:: void KMS( Matrix<T>& K, Int n, T rho )
.. cpp:function:: void KMS( AbstractDistMatrix<T>& K, Int n, T rho )

C API
-----

.. c:function:: ElError ElKMS_i( ElMatrix_i K, ElInt n, ElInt rho )
.. c:function:: ElError ElKMS_s( ElMatrix_s K, ElInt n, float rho )
.. c:function:: ElError ElKMS_d( ElMatrix_d K, ElInt n, double rho )
.. c:function:: ElError ElKMS_c( ElMatrix_c K, ElInt n, complex_float rho )
.. c:function:: ElError ElKMS_z( ElMatrix_z K, ElInt n, complex_double rho )
.. c:function:: ElError ElKMSDist_i( ElDistMatrix_i K, ElInt n, ElInt rho )
.. c:function:: ElError ElKMSDist_s( ElDistMatrix_s K, ElInt n, float rho )
.. c:function:: ElError ElKMSDist_d( ElDistMatrix_d K, ElInt n, double rho )
.. c:function:: ElError ElKMSDist_c( ElDistMatrix_c K, ElInt n, complex_float rho )
.. c:function:: ElError ElKMSDist_z( ElDistMatrix_z K, ElInt n, complex_double rho )

Python API
----------

.. py:function:: KMS(K,n,rho)
