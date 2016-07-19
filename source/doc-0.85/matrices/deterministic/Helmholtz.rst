Helmholtz
=========
A shifted discrete Laplacian over :math:`[0,1]^d`.

C++ API
-------

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int n, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int n, F shift )

   1D Helmholtz

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int nx, Int ny, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int nx, Int ny, F shift )

   2D Helmholtz

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int nx, Int ny, Int nz, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int nx, Int ny, Int nz, F shift )

   3D Helmholtz

C API
-----

.. c:function:: ElError ElHelmholtz1D_s( ElMatrix_s H, ElInt nx, float shift )
.. c:function:: ElError ElHelmholtz1D_d( ElMatrix_d H, ElInt nx, double shift )
.. c:function:: ElError ElHelmholtz1D_c( ElMatrix_c H, ElInt nx, complex_float shift )
.. c:function:: ElError ElHelmholtz1D_z( ElMatrix_z H, ElInt nx, complex_double shift )
.. c:function:: ElError ElHelmholtz1DDist_s( ElDistMatrix_s H, ElInt nx, float shift )
.. c:function:: ElError ElHelmholtz1DDist_d( ElDistMatrix_d H, ElInt nx, double shift )
.. c:function:: ElError ElHelmholtz1DDist_c( ElDistMatrix_c H, ElInt nx, complex_float shift )
.. c:function:: ElError ElHelmholtz1DDist_z( ElDistMatrix_z H, ElInt nx, complex_double shift )

   1D Helmholtz

.. c:function:: ElError ElHelmholtz2D_s( ElMatrix_s H, ElInt nx, ElInt ny, float shift )
.. c:function:: ElError ElHelmholtz2D_d( ElMatrix_d H, ElInt nx, ElInt ny, double shift )
.. c:function:: ElError ElHelmholtz2D_c( ElMatrix_c H, ElInt nx, ElInt ny, complex_float shift )
.. c:function:: ElError ElHelmholtz2D_z( ElMatrix_z H, ElInt nx, ElInt ny, complex_double shift )
.. c:function:: ElError ElHelmholtz2DDist_s( ElDistMatrix_s H, ElInt nx, ElInt ny, float shift )
.. c:function:: ElError ElHelmholtz2DDist_d( ElDistMatrix_d H, ElInt nx, ElInt ny, double shift )
.. c:function:: ElError ElHelmholtz2DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, complex_float shift )
.. c:function:: ElError ElHelmholtz2DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, complex_double shift )

   2D Helmholtz

.. c:function:: ElError ElHelmholtz3D_s( ElMatrix_s H, ElInt nx, ElInt ny, ElInt nz, float shift )
.. c:function:: ElError ElHelmholtz3D_d( ElMatrix_d H, ElInt nx, ElInt ny, ElInt nz, double shift )
.. c:function:: ElError ElHelmholtz3D_c( ElMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float shift )
.. c:function:: ElError ElHelmholtz3D_z( ElMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double shift )
.. c:function:: ElError ElHelmholtz3DDist_s( ElDistMatrix_s H, ElInt nx, ElInt ny, ElInt nz, float shift )
.. c:function:: ElError ElHelmholtz3DDist_d( ElDistMatrix_d H, ElInt nx, ElInt ny, ElInt nz, double shift )
.. c:function:: ElError ElHelmholtz3DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float shift )
.. c:function:: ElError ElHelmholtz3DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double shift )

   3D Helmholtz

Python API
----------

.. py:function:: Helmholtz1D(H,nx,shift)
.. py:function:: Helmholtz2D(H,nx,ny,shift)
.. py:function:: Helmholtz3D(H,nx,ny,nz,shift)
