Toeplitz
========
An :math:`m \times n` matrix is *Toeplitz* if there exists a vector :math:`b` such that, for each entry :math:`A(i,j)` of :math:`A`,

.. math::

   A(i,j) = b(i-j+(n-1)).


C++ API
-------

.. cpp:function:: void Toeplitz( Matrix<T>& A, Int m, Int n, const std::vector<T>& b )
.. cpp:function:: void Toeplitz( AbstractDistMatrix<T>& A, Int m, Int n, const std::vector<T>& b )

C API
-----

.. c:function:: ElError ElToeplitz_i( ElMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElToeplitz_s( ElMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElToeplitz_d( ElMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElToeplitz_c( ElMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElToeplitz_z( ElMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElToeplitzDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElToeplitzDist_s( ElDistMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElToeplitzDist_d( ElDistMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElToeplitzDist_c( ElDistMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElToeplitzDist_z( ElDistMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )
