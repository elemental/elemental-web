Gaussian
========
An :math:`m \times n` matrix is Gaussian if each entry is independently drawn
from a normal distribution.

C++ API
-------

.. cpp:function:: void Gaussian( Matrix<T>& A, Int m, Int n, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void Gaussian( AbstractDistMatrix<T>& A, Int m, Int n, T mean=0, Base<T> stddev=1 )

   Sets the matrix ``A`` to an :math:`m \times n` Gaussian matrix with the
   specified mean and standard deviation.

.. cpp:function:: void MakeGaussian( Matrix<T>& A, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void MakeGaussian( AbstractDistMatrix<T>& A, T mean=0, Base<T> stddev=1 )

   Changes each entry to an independent sample from the specified normal
   distribution.

C API
-----

.. c:function:: ElError ElGaussian_s( ElMatrix_s A, ElInt m, ElInt n, float mean, float stddev )
.. c:function:: ElError ElGaussian_d( ElMatrix_d A, ElInt m, ElInt n, double mean, double stddev )
.. c:function:: ElError ElGaussian_c( ElMatrix_c A, ElInt m, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElGaussian_z( ElMatrix_z A, ElInt m, ElInt n, complex_double mean, double stddev )
.. c:function:: ElError ElGaussianDist_s( ElDistMatrix_s A, ElInt m, ElInt n, float mean, float stddev )
.. c:function:: ElError ElGaussianDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double mean, double stddev )
.. c:function:: ElError ElGaussianDist_c( ElDistMatrix_c A, ElInt m, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElGaussianDist_z( ElDistMatrix_z A, ElInt m, ElInt n, complex_double mean, double stddev )

Python API
----------

.. py:function:: Gaussian(A,m,n,mean=0,stddev=1)
