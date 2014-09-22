Grcar
=====
An :math:`n \times n` *Grcar matrix* of order :math:`k` is a banded Toeplitz 
matrix with its subdiagonal set to :math:`-1` and both its main and :math:`k` 
superdiagonals set to :math:`1`. It is a highly non-normal matrix whose 
pseudospectra is regularly visualized.

C++ API
-------

.. cpp:function:: void Grcar( Matrix<T>& A, Int n, Int k=3 )
.. cpp:function:: void Grcar( AbstractDistMatrix<T>& A, Int n, Int k=3 )

C API
-----

.. c:function:: ElError ElGrcar_i( ElMatrix_i A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_s( ElMatrix_s A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_d( ElMatrix_d A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_c( ElMatrix_c A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_z( ElMatrix_z A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_i( ElDistMatrix_i A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_s( ElDistMatrix_s A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_d( ElDistMatrix_d A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_c( ElDistMatrix_c A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_z( ElDistMatrix_z A, ElInt n, ElInt k )
