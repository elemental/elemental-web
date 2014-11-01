Gear
====
An :math:`n \times n` *Gear matrix* with integer parameters :math:`s,t \neq 0` 
is a modification of the tridiagonal matrix with a main diagonal of zeros and 
sub and superdiagonals of ones such that entries :math:`(0,|s|-1)` and :math:`(n-1,n-|t|)` are respectively set to :math:`\text{sgn}(s)` and 
:math:`\text{sgn}(t)`.

C++ API
-------

.. cpp:function:: void Gear( Matrix<T>& G, Int n, Int s, Int t )
.. cpp:function:: void Gear( AbstractDistMatrix<T>& G, Int n, Int s, Int t )

C API
-----

.. c:function:: ElError ElGear_i( ElMatrix_i G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_s( ElMatrix_s G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_d( ElMatrix_d G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_c( ElMatrix_c G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_z( ElMatrix_z G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_i( ElDistMatrix_i G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_s( ElDistMatrix_s G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_d( ElDistMatrix_d G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_c( ElDistMatrix_c G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_z( ElDistMatrix_z G, ElInt n, ElInt s, ElInt t )

Python API
----------

.. py:function:: Gear(G,n,s,t)
