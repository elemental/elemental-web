Circulant
=========
An :math:`n \times n` matrix :math:`A` is called *circulant* if there exists a vector :math:`b` 
such that 

.. math::

   A(i,j) = b((i-j) \bmod n).

The following routines generate a circulant matrix using the vector ``a``.

C++ API
-------

.. cpp:function:: void Circulant( Matrix<T>& A, const std::vector<T>& a )
.. cpp:function:: void Circulant( AbstractDistMatrix<T>& A, const std::vector<T>& a )

C API
-----

.. c:function:: ElError ElCirculant_i( ElMatrix_i A, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElCirculant_s( ElMatrix_s A, ElInt aSize, float* aBuf )
.. c:function:: ElError ElCirculant_d( ElMatrix_d A, ElInt aSize, double* aBuf )
.. c:function:: ElError ElCirculant_c( ElMatrix_c A, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElCirculant_z( ElMatrix_z A, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElCirculantDist_i( ElDistMatrix_i A, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElCirculantDist_s( ElDistMatrix_s A, ElInt aSize, float* aBuf )
.. c:function:: ElError ElCirculantDist_d( ElDistMatrix_d A, ElInt aSize, double* aBuf )
.. c:function:: ElError ElCirculantDist_c( ElDistMatrix_c A, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElCirculantDist_z( ElDistMatrix_z A, ElInt aSize, complex_double* aBuf )

Python API
----------

.. py:function:: Circulant(A,a)
