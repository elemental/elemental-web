Frobenius prox
==============

.. math::

   \min_A \| A \|_F + \frac{\rho}{2} \| A - A_0 \|_F^2

C++ API
-------

.. cpp:function:: void FrobeniusProx( Matrix<F>& A, Base<F> rho )
.. cpp:function:: void FrobeniusProx( AbstractDistMatrix<F>& A, Base<F> rho )

C API
-----

.. c:function:: ElError ElFrobeniusProx_s( ElMatrix_s A, float rho )
.. c:function:: ElError ElFrobeniusProx_d( ElMatrix_d A, double rho )
.. c:function:: ElError ElFrobeniusProx_c( ElMatrix_c A, float rho )
.. c:function:: ElError ElFrobeniusProx_z( ElMatrix_z A, double rho )
.. c:function:: ElError ElFrobeniusProxDist_s( ElDistMatrix_s A, float rho )
.. c:function:: ElError ElFrobeniusProxDist_d( ElDistMatrix_d A, double rho )
.. c:function:: ElError ElFrobeniusProxDist_c( ElDistMatrix_c A, float rho )
.. c:function:: ElError ElFrobeniusProxDist_z( ElDistMatrix_z A, double rho )
