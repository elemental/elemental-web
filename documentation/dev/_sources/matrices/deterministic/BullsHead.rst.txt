Bull's Head
===========
The *Bull's head* matrix is a banded Toeplitz matrix with symbol

.. math::

   f(z) = 2i z^{-1} + z^2 + \frac{7}{10} z^3.

Please see L. Reichel and L. N. Trefethen's *Eigenvalues and pseudo-eigenvalues of Toeplitz matrices* for more details.

C++ API
-------

.. cpp:function:: void BullsHead( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void BullsHead( AbstractDistMatrix<Complex<Real>>& A, Int n )

C API
-----

.. c:function:: ElError ElBullsHead_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElBullsHead_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElBullsHeadDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElBullsHeadDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: BullsHead(A,n)
