Normal uniform spectrum
=======================
These routines sample a diagonal matrix from the specified ball in the 
complex plane, :math:`B_{\text{radius}}(\text{center})`, and then perform a 
similarity transformation using a random Householder transform.

C++ API
-------

.. cpp:function:: void NormalUniformSpectrum( Matrix<Complex<Real> >& A, Int n, Complex<Real> center=0, Real radius=1 )
.. cpp:function:: void NormalUniformSpectrum( DistMatrix<Complex<Real>,U,V>& A, Int n, Complex<Real> center=0, Real radius=1 )

C API
-----

.. c:function:: ElError ElNormalUniformSpectrum_c( ElMatrix_c A, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElNormalUniformSpectrum_z( ElMatrix_z A, ElInt n, complex_double center, double radius )
.. c:function:: ElError ElNormalUniformSpectrumDist_c( ElDistMatrix_c A, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElNormalUniformSpectrumDist_z( ElDistMatrix_z A, ElInt n, complex_double center, double radius )

Python API
----------

.. py:function:: NormalUniformSpectrum(A,n,center=0,radius=1)
