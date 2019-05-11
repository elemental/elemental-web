Extended Kahan
==============
The upper-triangular matrix :math:`A = S R`, where :math:`S=\text{diag}(1,\zeta,...,\zeta^{3 2^k-1})`, and

.. math::

   R = \begin{pmatrix} I & -\phi H_k & 0 \\
                       0 & I         & \phi H_k \\
                       0 & 0         & I \end{pmatrix}.

**TODO: Reference for its introduction and a description of its relevance to 
rank-revealing QR factorizations**

C++ API
-------

.. cpp:function:: void ExtendedKahan( Matrix<F>& A, Int k, Base<F> phi, Base<F> mu )
.. cpp:function:: void ExtendedKahan( ElementalMatrix<F>& A, Int k, Base<F> phi, Base<F> mu )

C API
-----

.. c:function:: ElError ElExtendedKahan_s( ElMatrix_s A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahan_d( ElMatrix_d A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahan_c( ElMatrix_c A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahan_z( ElMatrix_z A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahanDist_s( ElDistMatrix_s A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahanDist_d( ElDistMatrix_d A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahanDist_c( ElDistMatrix_c A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahanDist_z( ElDistMatrix_z A, ElInt k, double phi, double mu )

Python API
----------

.. py:function:: ExtendedKahan(A,k,phi,mu)
