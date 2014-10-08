Fiedler
=======
Given a vector :math:`c` of length :math:`n`, a *Fielder matrix* is an 
:math:`n \times n` matrix with entry :math:`(i,j)` (counting from zero) set to

.. math::

   A(i,j) = |c(i)-c(j)|.

C++ API
-------

.. cpp:function:: void Fiedler( Matrix<F>& A, const std::vector<F>& c )
.. cpp:function:: void Fiedler( AbstractDistMatrix<F>& A, const std::vector<F>& c )

C API
-----

.. c:function:: ElError ElFiedler_s( ElMatrix_s A, ElInt cSize, float* cBuf )
.. c:function:: ElError ElFiedler_d( ElMatrix_d A, ElInt cSize, double* cBuf )
.. c:function:: ElError ElFiedler_c( ElMatrix_c A, ElInt cSize, complex_float* cBuf )
.. c:function:: ElError ElFiedler_z( ElMatrix_z A, ElInt cSize, complex_double* cBuf )
.. c:function:: ElError ElFiedlerDist_s( ElDistMatrix_s A, ElInt cSize, float* cBuf )
.. c:function:: ElError ElFiedlerDist_d( ElDistMatrix_d A, ElInt cSize, double* cBuf )
.. c:function:: ElError ElFiedlerDist_c( ElDistMatrix_c A, ElInt cSize, complex_float* cBuf )
.. c:function:: ElError ElFiedlerDist_z( ElDistMatrix_z A, ElInt cSize, complex_double* cBuf )

Python API
----------

.. py:function:: Fiedler(A,c)
