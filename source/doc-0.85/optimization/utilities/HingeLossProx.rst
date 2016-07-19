Hinge-loss prox
===============

C++ API
-------

.. cpp:function:: void HingeLossProx( Matrix<Real>& A, Real rho )
.. cpp:function:: void HingeLossProx( AbstractDistMatrix<Real>& A, Real rho )

C API
-----

.. c:function:: ElError ElHingeLossProx_s( ElMatrix_s A, float rho )
.. c:function:: ElError ElHingeLossProx_d( ElMatrix_d A, double rho )
.. c:function:: ElError ElHingeLossProxDist_s( ElDistMatrix_s A, float rho )
.. c:function:: ElError ElHingeLossProxDist_d( ElDistMatrix_d A, double rho )
