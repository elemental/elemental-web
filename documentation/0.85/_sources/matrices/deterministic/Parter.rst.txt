Parter
======
An :math:`n \times n` *Parter matrix* has entry :math:`(i,j)` set to

.. math::

   P(i,j) = \frac{1}{i-j+\frac{1}{2}}.

C++ API
-------

.. cpp:function:: void Parter( Matrix<F>& P, Int n )
.. cpp:function:: void Parter( AbstractDistMatrix<F>& P, Int n )

C API
-----

.. c:function:: ElError ElParter_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElParter_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElParter_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElParter_z( ElMatrix_z P, ElInt n )
.. c:function:: ElError ElParterDist_s( ElDistMatrix_s P, ElInt n )
.. c:function:: ElError ElParterDist_d( ElDistMatrix_d P, ElInt n )
.. c:function:: ElError ElParterDist_c( ElDistMatrix_c P, ElInt n )
.. c:function:: ElError ElParterDist_z( ElDistMatrix_z P, ElInt n )

Python API
----------

.. py:function:: Parter(P,n)
