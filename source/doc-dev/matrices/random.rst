Random
======

Gaussian
--------
An :math:`m \times n` matrix is Gaussian if each entry is independently drawn
from a normal distribution.

C++ API
^^^^^^^

.. cpp:function:: void Gaussian( Matrix<T>& A, int m, int n, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void Gaussian( AbstractDistMatrix<T>& A, int m, int n, T mean=0, Base<T> stddev=1 )

   Sets the matrix ``A`` to an :math:`m \times n` Gaussian matrix with the
   specified mean and standard deviation.

.. cpp:function:: void MakeGaussian( Matrix<T>& A, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void MakeGaussian( AbstractDistMatrix<T>& A, T mean=0, Base<T> stddev=1 )

   Changes each entry to an independent sample from the specified normal
   distribution.

C API
^^^^^

.. c:function:: ElError ElGaussian_s( ElMatrix_s A, ElInt m, ElInt n, float mean, float stddev )
.. c:function:: ElError ElGaussian_d( ElMatrix_d A, ElInt m, ElInt n, double mean, double stddev )
.. c:function:: ElError ElGaussian_c( ElMatrix_c A, ElInt m, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElGaussian_z( ElMatrix_z A, ElInt m, ElInt n, complex_double mean, double stddev )
.. c:function:: ElError ElGaussianDist_s( ElDistMatrix_s A, ElInt m, ElInt n, float mean, float stddev )
.. c:function:: ElError ElGaussianDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double mean, double stddev )
.. c:function:: ElError ElGaussianDist_c( ElDistMatrix_c A, ElInt m, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElGaussianDist_z( ElDistMatrix_z A, ElInt m, ElInt n, complex_double mean, double stddev )

Haar
----
The Haar distribution is the uniform distribution over the space of real or 
complex unitary matrices. 

C++ API
^^^^^^^

.. cpp:function:: void Haar( Matrix<F>& A, int n )
.. cpp:function:: void Haar( DistMatrix<F>& A, int n )

   Draws ``A`` from the Haar distribution. The current scheme performs a QR
   factorization of a Gaussian matrix, but Stewart introduced a well-known 
   scheme which only requires quadratic work for the implicit representation 
   as a product of random Householder reflectors.

.. cpp:function:: void ImplicitHaar( Matrix<F>& A, Matrix<F>& t, int n )
.. cpp:function:: void ImplicitHaar( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, int n )

   Sets ``A`` to a set of Householder reflectors with the same structure as
   the result of a QR decomposition. The product of these reflectors is a 
   sample from the Haar distribution.

C API
^^^^^

.. c:function:: ElError ElHaar_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElHaar_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElHaar_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElHaar_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElHaarDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElHaarDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElHaarDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElHaarDist_z( ElDistMatrix_z A, ElInt n )

.. c:function:: ElError ElImplicitHaar_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaar_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaar_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaar_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d, ElInt n )
.. c:function:: ElError ElImplicitHaarDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d, ElInt n )

Hatano-Nelson
-------------
**TODO: Add descriptions**

C++ API
^^^^^^^

.. cpp:function:: void HatanoNelson( Matrix<F>& A, Int n, F center, Base<F> radius, F g, bool periodic=true )
.. cpp:function:: void HatanoNelson( AbstractDistMatrix<F>& A, Int n, F center, Base<F> radius, F g, bool periodic=true )

C API
^^^^^

.. c:function:: ElError ElHatanoNelson_s( ElMatrix_s A, ElInt n, float center, float radius, float g, bool periodic )
.. c:function:: ElError ElHatanoNelson_d( ElMatrix_d A, ElInt n, double center, double radius, double g, bool periodic )
.. c:function:: ElError ElHatanoNelson_c( ElMatrix_c A, ElInt n, complex_float center, float radius, complex_float g, bool periodic )
.. c:function:: ElError ElHatanoNelson_z( ElMatrix_z A, ElInt n, complex_double center, double radius, complex_double g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_s( ElDistMatrix_s A, ElInt n, float center, float radius, float g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_d( ElDistMatrix_d A, ElInt n, double center, double radius, double g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_c( ElDistMatrix_c A, ElInt n, complex_float center, float radius, complex_float g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_z( ElDistMatrix_z A, ElInt n, complex_double center, double radius, complex_double g, bool periodic )

HermitianUniformSpectrum
------------------------
These routines sample a diagonal matrix from the specified interval of the 
real line, :math:`(\text{lower},\text{upper}]`, and then perform a similarity 
transformation using a random Householder transform.

C++ API
^^^^^^^

.. cpp:function:: void HermitianUniformSpectrum( Matrix<F>& A, int n, Base<F> lower=0, Base<F> upper=1 )
.. cpp:function:: void HermitianUniformSpectrum( DistMatrix<F,U,V>& A, int n, Base<F> lower=0, Base<F> upper=1 )

C API
^^^^^

.. c:function:: ElError ElHermitianUniformSpectrum_s( ElMatrix_s A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrum_d( ElMatrix_d A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrum_c( ElMatrix_c A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrum_z( ElMatrix_z A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_s( ElDistMatrix_s A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_d( ElDistMatrix_d A, ElInt n, double lower, double upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_c( ElDistMatrix_c A, ElInt n, float lower, float upper )
.. c:function:: ElError ElHermitianUniformSpectrumDist_z( ElDistMatrix_z A, ElInt n, double lower, double upper )

NormalUniformSpectrum
---------------------
These routines sample a diagonal matrix from the specified ball in the 
complex plane, :math:`B_{\text{radius}}(\text{center})`, and then perform a 
similarity transformation using a random Householder transform.

C++ API
^^^^^^^

.. cpp:function:: void NormalUniformSpectrum( Matrix<Complex<Real> >& A, int n, Complex<Real> center=0, Real radius=1 )
.. cpp:function:: void NormalUniformSpectrum( DistMatrix<Complex<Real>,U,V>& A, int n, Complex<Real> center=0, Real radius=1 )

C API
^^^^^

.. c:function:: ElError ElNormalUniformSpectrum_c( ElMatrix_c A, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElNormalUniformSpectrum_z( ElMatrix_z A, ElInt n, complex_double center, double radius )
.. c:function:: ElError ElNormalUniformSpectrumDist_c( ElDistMatrix_c A, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElNormalUniformSpectrumDist_z( ElDistMatrix_z A, ElInt n, complex_double center, double radius )

Uniform
-------
We call an :math:`m \times n` matrix is uniformly random if each entry is drawn 
from a uniform distribution over a ball with the specified center and radius.

C++ API
^^^^^^^

.. cpp:function:: void Uniform( Matrix<T>& A, int m, int n, T center=0, Base<T> radius=1 )
.. cpp:function:: void Uniform( AbstractDistMatrix<T>& A, int m, int n, T center=0, Base<T> radius=1 )

.. cpp:function:: void MakeUniform( Matrix<T>& A, T center=0, Base<T> radius=1 )
.. cpp:function:: void MakeUniform( AbstractDistMatrix<T>& A, T center=0, Base<T> radius=1 )

C API
^^^^^

.. c:function:: ElError ElUniform_i( ElMatrix_i A, ElInt m, ElInt n, ElInt center, ElInt radius )
.. c:function:: ElError ElUniform_s( ElMatrix_s A, ElInt m, ElInt n, float center, float radius )
.. c:function:: ElError ElUniform_d( ElMatrix_d A, ElInt m, ElInt n, double center, double radius )
.. c:function:: ElError ElUniform_c( ElMatrix_c A, ElInt m, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElUniform_z( ElMatrix_z A, ElInt m, ElInt n, complex_double center, double radius )
.. c:function:: ElError ElUniformDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt center, ElInt radius )
.. c:function:: ElError ElUniformDist_s( ElDistMatrix_s A, ElInt m, ElInt n, float center, float radius )
.. c:function:: ElError ElUniformDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double center, double radius )
.. c:function:: ElError ElUniformDist_c( ElDistMatrix_c A, ElInt m, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElUniformDist_z( ElDistMatrix_z A, ElInt m, ElInt n, complex_double center, double radius )

Uniform Helmholtz Green's
-------------------------
**TODO: Add descriptions**

C++ API
^^^^^^^

.. cpp:function:: void UniformHelmholtzGreens( Matrix<Complex<Real>>& A, Int n, Real lambda )
.. cpp:function:: void UniformHelmholtzGreens( AbstractDistMatrix<Complex<Real>>& A, Int n, Real lambda )

C API
^^^^^

.. c:function:: ElError ElUniformHelmholtzGreens_c( ElMatrix_c A, ElInt n, float lambda )
.. c:function:: ElError ElUniformHelmholtzGreens_z( ElMatrix_z A, ElInt n, double lambda )
.. c:function:: ElError ElUniformHelmholtzGreensDist_c( ElDistMatrix_c A, ElInt n, float lambda )
.. c:function:: ElError ElUniformHelmholtzGreensDist_z( ElDistMatrix_z A, ElInt n, double lambda )

Wigner
------
A Hermitian matrix whose entries in one triangle are all independent samples
from a normal distribution. The spectra of these matrices are well-studied.

C++ API
^^^^^^^

.. cpp:function:: void Wigner( Matrix<T>& A, int n, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void Wigner( AbstractDistMatrix<T>& A, int n, T mean=0, Base<T> stddev=1 )

C API
^^^^^

.. c:function:: ElError ElWigner_i( ElMatrix_i A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_s( ElMatrix_s A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_d( ElMatrix_d A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_c( ElMatrix_c A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_z( ElMatrix_z A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_i( ElDistMatrix_i A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_s( ElDistMatrix_s A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_d( ElDistMatrix_d A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_c( ElDistMatrix_c A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_z( ElDistMatrix_z A, ElInt k, bool binary )
