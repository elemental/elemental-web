Legendre
========
The :math:`n \times n` tridiagonal Jacobi matrix associated with the Legendre
polynomials. Its main diagonal is zero, and the off-diagonal terms are given 
by 

.. math::

   \beta_j = \frac{1}{2}\left(1-(2(j+1))^{-2}\right)^{-1/2},

where :math:`\beta_j` connects the :math:`j`'th degree of freedom to the 
:math:`j+1`'th degree of freedom, counting from zero.
The eigenvalues of this matrix lie in :math:`[-1,1]` and are the locations for 
Gaussian quadrature of order :math:`n`. The corresponding weights may be found 
by doubling the square of the first entry of the corresponding normalized 
eigenvector.

C++ API
-------

.. cpp:function:: void Legendre( Matrix<F>& A, Int n )
.. cpp:function:: void Legendre( AbstractDistMatrix<F>& A, Int n )

   Sets the matrix ``A`` equal to the :math:`n \times n` Jacobi matrix.

C API
-----

.. c:function:: ElError ElLegendre_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElLegendre_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElLegendre_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElLegendre_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElLegendreDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElLegendreDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElLegendreDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElLegendreDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Legendre(A,n)
