Uniform Helmholtz Green's
=========================
These routines generate a member of the family of "random Green's matrices"
from A. Goetschy and S. E. Skipetrov's 
*Non-Hermitian Euclidean random matrix theory*.
Each such matrix is the restriction of a 3D Helmholtz Green's function
to a subset of points chosen uniformly from the unit ball. The behaviour of the
spectrum is known to change dramatically dependening upon the number of points
sampled per wavelength.

C++ API
-------

.. cpp:function:: void UniformHelmholtzGreens( Matrix<Complex<Real>>& A, Int n, Real lambda )
.. cpp:function:: void UniformHelmholtzGreens( AbstractDistMatrix<Complex<Real>>& A, Int n, Real lambda )

C API
-----

.. c:function:: ElError ElUniformHelmholtzGreens_c( ElMatrix_c A, ElInt n, float lambda )
.. c:function:: ElError ElUniformHelmholtzGreens_z( ElMatrix_z A, ElInt n, double lambda )
.. c:function:: ElError ElUniformHelmholtzGreensDist_c( ElDistMatrix_c A, ElInt n, float lambda )
.. c:function:: ElError ElUniformHelmholtzGreensDist_z( ElDistMatrix_z A, ElInt n, double lambda )
