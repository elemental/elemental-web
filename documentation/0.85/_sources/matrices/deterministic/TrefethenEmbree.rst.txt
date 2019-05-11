Trefethen-Embree
================
The *Trefethen-Embree matrix* (since the author is not aware of another name)
is a banded Toeplitz matrix with symbol

.. math::

   f(z) = 2 z^{-3} - z^{-2} + 2i z^{-1} - 4 z^2 - 2i z^3.

Please see Chapter II of Lloyd N. Trefethen and Mark Embree's
*Spectra and Pseudospectra* for more details.

C++ API
-------

.. cpp:function:: void TrefethenEmbree( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void TrefethenEmbree( AbstractDistMatrix<Complex<Real>>& A, Int n )
.. cpp:function:: void TrefethenEmbree( AbstractBlockDistMatrix<Complex<Real>>& A, Int n )

C API
-----

.. c:function:: ElError ElTrefethenEmbree_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElTrefethenEmbree_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElTrefethenEmbreeDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElTrefethenEmbreeDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: TrefethenEmbree(A,n)
