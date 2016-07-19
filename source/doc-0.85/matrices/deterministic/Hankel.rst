Hankel
======
An :math:`m \times n` matrix :math:`A` is called a *Hankel matrix* if there 
exists a vector :math:`b` such that

.. math::

   A(i,j) = b(i+j).

The following routines create an :math:`m \times n` Hankel matrix from the 
generate vector, :math:`b`.

C++ API
-------

.. cpp:function:: void Hankel( Matrix<T>& A, Int m, Int n, const std::vector<T>& b )
.. cpp:function:: void Hankel( AbstractDistMatrix<T>& A, Int m, Int n, const std::vector<T>& b )

C API
-----

.. c:function:: ElError ElHankel_i( ElMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElHankel_s( ElMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElHankel_d( ElMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElHankel_c( ElMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElHankel_z( ElMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElHankelDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElHankelDist_s( ElDistMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElHankelDist_d( ElDistMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElHankelDist_c( ElDistMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElHankelDist_z( ElDistMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )

Python API
----------

.. py:function:: Hankel(A,m,n,a)
