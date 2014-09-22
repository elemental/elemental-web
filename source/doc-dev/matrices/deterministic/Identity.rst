Identity
========
The :math:`n \times n` *identity matrix* is simply defined by setting entry 
:math:`(i,j)` to one if :math:`i = j`, and zero otherwise. For various 
reasons, we generalize this definition to nonsquare, :math:`m \times n`, 
matrices.

C++ API
-------

.. cpp:function:: void Identity( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Identity( AbstractDistMatrix<T>& A, Int m, Int n )

   Set the matrix ``A`` equal to the :math:`m \times n` identity(-like) matrix.

.. cpp:function:: void MakeIdentity( Matrix<T>& A )
.. cpp:function:: void MakeIdentity( AbstractDistMatrix<T>& A ) 

   Set the matrix ``A`` to be identity-like.

C API
-----

.. c:function:: ElError ElIdentity_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_z( ElDistMatrix_z A, ElInt m, ElInt n )
