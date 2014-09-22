Redheffer
=========
Return the :math:`n \times n` matrix with entry :math:`(i,j)` (counting from
zero) set to

.. math::

   \begin{array}{ll} 
     1, & j = 0, \text{ or } (j+1) \bmod (i+1) = 0, \\
     0, & \text{otherwise}.
   \end{array}

The determinants of such matrices are connected to the Riemann hypothesis,
which holds if and only if

.. math::

   \text{det}(R) = O(n^{1/2+\epsilon})  

for every :math:`\epsilon > 0`.

C++ API
-------

.. cpp:function:: void Redheffer( Matrix<T>& R, Int n )
.. cpp:function:: void Redheffer( AbstractDistMatrix<T>& R, Int n )

C API
-----

.. c:function:: ElError ElRedheffer_i( ElMatrix_i R, ElInt n )
.. c:function:: ElError ElRedheffer_s( ElMatrix_s R, ElInt n )
.. c:function:: ElError ElRedheffer_d( ElMatrix_d R, ElInt n )
.. c:function:: ElError ElRedheffer_c( ElMatrix_c R, ElInt n )
.. c:function:: ElError ElRedheffer_z( ElMatrix_z R, ElInt n )
.. c:function:: ElError ElRedhefferDist_i( ElDistMatrix_i R, ElInt n )
.. c:function:: ElError ElRedhefferDist_s( ElDistMatrix_s R, ElInt n )
.. c:function:: ElError ElRedhefferDist_d( ElDistMatrix_d R, ElInt n )
.. c:function:: ElError ElRedhefferDist_c( ElDistMatrix_c R, ElInt n )
.. c:function:: ElError ElRedhefferDist_z( ElDistMatrix_z R, ElInt n )
