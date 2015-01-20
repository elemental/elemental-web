Helmholtz with PML
==================
The following routines return a simple second-order discretization of the 
constant coefficient Helmholtz equation over :math:`[0,1]^d` with Perfectly
Matched Layer boundary conditions with profile defined by the amplitude 
:math:`\sigma` and exponent `pmlExp`, discretized over `numPmlPoints` grid
points.

C++ API
-------

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int n, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int n, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   1D Helmholtz

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int nx, Int ny, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int nx, Int ny, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   2D Helmholtz

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int nx, Int ny, Int nz, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int nx, Int ny, Int nz, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   3D Helmholtz


C API
-----

.. c:function:: ElError ElHelmholtzPML1D_c( ElMatrix_c H, ElInt nx, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML1D_z( ElMatrix_z H, ElInt nx, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML1DDist_c( ElDistMatrix_c H, ElInt nx, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML1DDist_z( ElDistMatrix_z H, ElInt nx, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   1D Helmholtz

.. c:function:: ElError ElHelmholtzPML2D_c( ElMatrix_c H, ElInt nx, ElInt ny, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML2D_z( ElMatrix_z H, ElInt nx, ElInt ny, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML2DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML2DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   2D Helmholtz

.. c:function:: ElError ElHelmholtzPML3D_c( ElMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML3D_z( ElMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML3DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML3DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   3D Helmholtz

Python API
----------

.. py:function:: HelmholtzPML1D(H,nx,omega,numPmlPoints,sigma,pmlExp)
.. py:function:: HelmholtzPML2D(H,nx,ny,omega,numPmlPoints,sigma,pmlExp)
.. py:function:: HelmholtzPML3D(H,nx,ny,nz,omega,numPmlPoints,sigma,pmlExp)
