Haar
====
The Haar distribution is the uniform distribution over the space of real or 
complex unitary matrices. 

C++ API
-------

.. cpp:function:: void Haar( Matrix<F>& A, Int n )
.. cpp:function:: void Haar( ElementalMatrix<F>& A, Int n )

   Draws ``A`` from the Haar distribution. The current scheme performs a QR
   factorization of a Gaussian matrix, but Stewart introduced a well-known 
   scheme which only requires quadratic work for the implicit representation 
   as a product of random Householder reflectors.

.. cpp:function:: void ImplicitHaar( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Int n )
.. cpp:function:: void ImplicitHaar( ElementalMatrix<F>& A, ElementalMatrix<F>& t, Elemental<Base<F>>& d, Int n )

   Sets ``A`` to a set of Householder reflectors with the same structure as
   the result of a QR decomposition. The product of these reflectors is a 
   sample from the Haar distribution.

C API
-----

.. c:function:: ElError ElHaar_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElHaar_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElHaar_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElHaar_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElHaarDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElHaarDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElHaarDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElHaarDist_z( ElDistMatrix_z A, ElInt n )

.. c:function:: ElError ElImplicitHaar_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaar_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaar_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaar_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d, ElInt n )

Python API
----------

.. py:function:: Haar(A,n)
.. py:function:: ImplicitHaar(A,t,d,n)
