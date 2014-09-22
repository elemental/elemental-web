Fourier
=======
The :math:`n \times n` *Discrete Fourier Transform* (DFT) matrix, say :math:`A`, is given by

.. math::

   A(i,j) = \frac{1}{\sqrt{n}} e^{-2\pi i j / n}.

The following routines set the matrix ``A`` equal to the :math:`n \times n` 
DFT matrix.

C++ API
-------

.. cpp:function:: void Fourier( Matrix<Complex<Real> >& A, Int n )
.. cpp:function:: void Fourier( AbstractDistMatrix<Complex<Real>>& A, Int n )

C API
-----

.. c:function:: ElError ElFourier_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElFourier_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElFourierDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElFourierDist_z( ElDistMatrix_z A, ElInt n )
