Hermitian uniform spectrum
==========================
These routines sample a diagonal matrix from the specified interval of the 
real line, :math:`(\text{lower},\text{upper}]`, and then perform a similarity 
transformation using a random Householder transform.

C++ API
-------

.. cpp:function:: void HermitianUniformSpectrum( Matrix<F>& A, Int n, Base<F> lower=0, Base<F> upper=1 )
.. cpp:function:: void HermitianUniformSpectrum( DistMatrix<F,U,V>& A, Int n, Base<F> lower=0, Base<F> upper=1 )

C API
-----

.. c:function:: ElError ElHermitianUniformSpectrum_s( ElMatrix_s A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrum_d( ElMatrix_d A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrum_c( ElMatrix_c A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrum_z( ElMatrix_z A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_s( ElDistMatrix_s A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_d( ElDistMatrix_d A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_c( ElDistMatrix_c A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_z( ElDistMatrix_z A, ElInt n, double lower, double upper )

Python API
----------

.. py:function:: HermitianUniformSpectrum(A,n,lower=0,upper=1)
