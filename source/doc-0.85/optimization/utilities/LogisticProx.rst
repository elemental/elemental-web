Logistic prox
=============

C++ API
-------

.. cpp:function:: void LogisticProx( Matrix<Real>& A, Real rho )
.. cpp:function:: void LogisticProx( AbstractDistMatrix<Real>& A, Real rho )

C API
-----

.. c:function:: ElError ElLogisticProx_s( ElMatrix_s A, float rho )
.. c:function:: ElError ElLogisticProx_d( ElMatrix_d A, double rho )
.. c:function:: ElError ElLogisticProxDist_s( ElDistMatrix_s A, float rho )
.. c:function:: ElError ElLogisticProxDist_d( ElDistMatrix_d A, double rho )
