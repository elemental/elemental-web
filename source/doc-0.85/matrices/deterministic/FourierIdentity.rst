Fourier-Identity
================
The :math:`n \times 2 n` Fourier-Identity matrix, say :math:`A`, is given by

.. math::

   A = \left[ F I \right],

where :math:`F` is the :math:`n \times n` Discrete Fourier Transform matrix,
and :math:`I` is the :math:`n \times n` identity. It is a common example of 
a matrix with low coherence.

C++ API
-------

.. cpp:function:: void FourierIdentity( Matrix<Complex<Real> >& A, Int n )
.. cpp:function:: void FourierIdentity( AbstractDistMatrix<Complex<Real>>& A, Int n )

C API
-----

.. c:function:: ElError ElFourierIdentity_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElFourierIdentity_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElFourierIdentityDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElFourierIdentityDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: FourierIdentity(A,n)
