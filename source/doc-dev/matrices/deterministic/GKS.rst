Golub/Klema/Stewart 
===================
The *Golub/Klema/Stewart matrix* is upper-triangular with :math:`1/\sqrt{j+1}`
in the :math:`j`'th entry of its main diagonal and :math:`-1/\sqrt{j+1}` in the
:math:`j`'th column of the upper triangle. It was originally introduced as an
example of where greedy Rank-Revealing QR factorizations fail.

C++ API
-------

.. cpp:function:: void GKS( Matrix<F>& A, Int n )
.. cpp:function:: void GKS( AbstractDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElGKS_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElGKS_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElGKS_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElGKS_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElGKSDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElGKSDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElGKSDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElGKSDist_z( ElDistMatrix_z A, ElInt n )
