Forsythe
========
A *Forsythe matrix* is a Jordan block with the bottom-left entry replaced with
an arbitrary value. In the below routines, the eigenvalue of the 
:math:`n \times n` Jordan block is :math:`\lambda`, and the entry placed in the 
:math:`(n-1,0)` position is :math:`\alpha`.

C++ API
-------

.. cpp:function:: void Forsythe( Matrix<T>& J, Int n, T alpha, T lambda )
.. cpp:function:: void Forsythe( AbstractDistMatrix<T>& J, Int n, T alpha, T lambda )

C API
-----

.. c:function:: ElError ElForsythe_i( ElMatrix_i J, ElInt n, ElInt alpha, ElInt lambda )
.. c:function:: ElError ElForsythe_s( ElMatrix_s J, ElInt n, float alpha, float lambda )
.. c:function:: ElError ElForsythe_d( ElMatrix_d J, ElInt n, double alpha, double lambda )
.. c:function:: ElError ElForsythe_c( ElMatrix_c J, ElInt n, complex_float alpha, complex_float lambda )
.. c:function:: ElError ElForsythe_z( ElMatrix_z J, ElInt n, complex_double alpha, complex_double lambda )
.. c:function:: ElError ElForsytheDist_i( ElDistMatrix_i J, ElInt n, ElInt alpha, ElInt lambda )
.. c:function:: ElError ElForsytheDist_s( ElDistMatrix_s J, ElInt n, float alpha, float lambda )
.. c:function:: ElError ElForsytheDist_d( ElDistMatrix_d J, ElInt n, double alpha, double lambda )
.. c:function:: ElError ElForsytheDist_c( ElDistMatrix_c J, ElInt n, complex_float alpha, complex_float lambda )
.. c:function:: ElError ElForsytheDist_z( ElDistMatrix_z J, ElInt n, complex_double alpha, complex_double lambda )

Python API
----------

.. py:function:: Forsythe(J,n,alpha,lamb)
