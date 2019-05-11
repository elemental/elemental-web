Kahan
=====
For any pair :math:`(\phi,\zeta)` such that :math:`|\phi|^2+|\zeta|^2=1`, 
the corresponding :math:`n \times n` Kahan matrix is given by:

.. math::

   K = \text{diag}(1,\phi,\ldots,\phi^{n-1}) \begin{pmatrix} 
   1      & -\zeta & -\zeta & \cdots & -\zeta \\
   0      & 1      & -\zeta & \cdots & -\zeta \\
          & \ddots &        & \vdots & \vdots \\
   \vdots &        &        & 1      & -\zeta \\
   0      &        & \cdots &        & 1 \end{pmatrix}

C++ API
-------

.. cpp:function:: void Kahan( Matrix<F>& A, Int n, F phi )
.. cpp:function:: void Kahan( AbstractDistMatrix<F>& A, Int n, F phi )

   Sets the matrix ``A`` equal to the :math:`n \times n` Kahan matrix with 
   the specified value for :math:`\phi`.

C API
-----

.. c:function:: ElError ElKahan_s( ElMatrix_s A, ElInt n, float phi )
.. c:function:: ElError ElKahan_d( ElMatrix_d A, ElInt n, double phi )
.. c:function:: ElError ElKahan_c( ElMatrix_c A, ElInt n, complex_float phi )
.. c:function:: ElError ElKahan_z( ElMatrix_z A, ElInt n, complex_double phi )
.. c:function:: ElError ElKahanDist_s( ElDistMatrix_s A, ElInt n, float phi )
.. c:function:: ElError ElKahanDist_d( ElDistMatrix_d A, ElInt n, double phi )
.. c:function:: ElError ElKahanDist_c( ElDistMatrix_c A, ElInt n, complex_float phi )
.. c:function:: ElError ElKahanDist_z( ElDistMatrix_z A, ElInt n, complex_double phi )

Python API
----------

.. py:function:: Kahan(A,n,phi)
