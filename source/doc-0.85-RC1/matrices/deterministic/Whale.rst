Whale
=====
The *Whale matrix* is a banded Toeplitz matrix with symbol

.. math::

   f(z) = -z^{-4} - (3+2i) z^{-3} + i z^{-2} + z^{-1} + 10 z + (3+i) z^2 + 4 z^3 + i z^4

Please see A. Bottcher's *Infinite matrices and projection methods* for more
details.

C++ API
-------

.. cpp:function:: void Whale( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Whale( AbstractDistMatrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Whale( AbstractBlockDistMatrix<Complex<Real>>& A, Int n )

C API
-----

.. c:function:: ElError ElWhale_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElWhale_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElWhaleDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElWhaleDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Whale(A,n)
