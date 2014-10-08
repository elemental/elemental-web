Pei
===
An :math:`n \times n` *Pei matrix* with parameter :math:`\alpha` has a main
diagonal of :math:`\alpha+1` and all other entries set to :math:`1`.

C++ API
-------

.. cpp:function:: void Pei( Matrix<T>& P, Int n, T alpha )
.. cpp:function:: void Pei( AbstractDistMatrix<T>& P, Int n, T alpha )

C API
-----

.. c:function:: ElError ElPei_i( ElMatrix_i P, ElInt n, ElInt alpha )
.. c:function:: ElError ElPei_s( ElMatrix_s P, ElInt n, float alpha )
.. c:function:: ElError ElPei_d( ElMatrix_d P, ElInt n, double alpha )
.. c:function:: ElError ElPei_c( ElMatrix_c P, ElInt n, complex_float alpha )
.. c:function:: ElError ElPei_z( ElMatrix_z P, ElInt n, complex_double alpha )
.. c:function:: ElError ElPeiDist_i( ElDistMatrix_i P, ElInt n, ElInt alpha )
.. c:function:: ElError ElPeiDist_s( ElDistMatrix_s P, ElInt n, float alpha )
.. c:function:: ElError ElPeiDist_d( ElDistMatrix_d P, ElInt n, double alpha )
.. c:function:: ElError ElPeiDist_c( ElDistMatrix_c P, ElInt n, complex_float alpha )
.. c:function:: ElError ElPeiDist_z( ElDistMatrix_z P, ElInt n, complex_double alpha )

Python API
----------

.. py:function:: Pei(P,n,alpha)
