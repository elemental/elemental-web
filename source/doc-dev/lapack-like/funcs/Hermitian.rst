Hermitian functions
===================
Reform the matrix with the eigenvalues modified by a user-defined function. 
When the user-defined function is real-valued, the result will remain Hermitian,
but when the function is complex-valued, the result is best characterized as 
normal. 

When the user-defined function, say :math:`f`, is analytic, we can say much
more about the result: if the eigenvalue decomposition of the 
Hermitian matrix :math:`A` is :math:`A=Z \Lambda Z^H`, then

.. math::

   f(A) = f(Z \Lambda Z^H) = Z f(\Lambda) Z^H.

Two important special cases are :math:`f(\lambda) = \exp(\lambda)` and 
:math:`f(\lambda)=\exp(i \lambda)`, where the former results in a Hermitian 
matrix and the latter in a normal (in fact, unitary) matrix.

C++ API
-------

.. cpp:function:: void HermitianFunction( UpperOrLower uplo, Matrix<F>& A, std::function<Real(Real)> f )
.. cpp:function:: void HermitianFunction( UpperOrLower uplo, AbstractDistMatrix<F>& A, std::function<Real(Real)> f )

   Modifies the eigenvalues of the passed-in Hermitian matrix by replacing 
   each eigenvalue :math:`\lambda_i` with :math:`f(\lambda_i) \in \mathbb{R}`. 
   See `examples/lapack-like/RealSymmetricFunction.cpp <https://github.com/elemental/Elemental/tree/master/examples/lapack-like/RealHermitianFunction.cpp>`_ for an example usage.

.. cpp:function:: void HermitianFunction( UpperOrLower uplo, Matrix<Complex<Real>>& A, std::function<Complex<Real>(Real)> f )
.. cpp:function:: void HermitianFunction( UpperOrLower uplo, AbstractDistMatrix<Complex<Real>>& A, std::function<Complex<Real>(Real)> f )

   Modifies the eigenvalues of the passed-in complex Hermitian matrix by
   replacing each eigenvalue :math:`\lambda_i` with 
   :math:`f(\lambda_i) \in \mathbb{C}`. 
   See `examples/lapack-like/ComplexHermitianFunction.cpp <https://github.com/elemental/Elemental/tree/master/examples/lapack-like/ComplexHermitianFunction.cpp>`_ for an example usage.

**TODO: A version of (complex) HermitianFunction which begins with a real matrix**

C API
-----

.. c:function:: ElError ElRealHermitianFunction_s( ElUpperOrLower uplo, ElMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElRealHermitianFunction_d( ElUpperOrLower uplo, ElMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElRealHermitianFunction_c( ElUpperOrLower uplo, ElMatrix_c A, float (*func)(float) )
.. c:function:: ElError ElRealHermitianFunction_z( ElUpperOrLower uplo, ElMatrix_z A, double (*func)(double) )
.. c:function:: ElError ElRealHermitianFunctionDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElRealHermitianFunctionDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElRealHermitianFunctionDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, float (*func)(float) )
.. c:function:: ElError ElRealHermitianFunctionDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, double (*func)(double) )

   Modifies the eigenvalues of the passed-in Hermitian matrix by replacing 
   each eigenvalue :math:`\lambda_i` with :math:`f(\lambda_i) \in \mathbb{R}`. 

.. c:function:: ElError ElComplexHermitianFunction_c( ElUpperOrLower uplo, ElMatrix_c A, complex_float (*func)(float) )
.. c:function:: ElError ElComplexHermitianFunction_z( ElUpperOrLower uplo, ElMatrix_z A, complex_double (*func)(double) )
.. c:function:: ElError ElComplexHermitianFunctionDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, complex_float (*func)(float) )
.. c:function:: ElError ElComplexHermitianFunctionDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, complex_double (*func)(double) )

   Modifies the eigenvalues of the passed-in complex Hermitian matrix by
   replacing each eigenvalue :math:`\lambda_i` with 
   :math:`f(\lambda_i) \in \mathbb{C}`. 

