Diagonal
========
An :math:`n \times n` matrix :math:`A` is called *diagonal* if each entry :math:`(i,j)`, where 
:math:`i \neq j`, is :math:`0`. They are therefore defined by the *diagonal* values, where 
:math:`i = j`.

The following routines construct a diagonal matrix from the vector of diagonal 
values, :math:`d`.

C++ API
-------

.. cpp:function:: void Diagonal( Matrix<S>& D, const std::vector<T>& d )
.. cpp:function:: void Diagonal( AbstractDistMatrix<S>& D, const std::vector<T>& d )
.. cpp:function:: void Diagonal( AbstractBlockDistMatrix<S>& D, const std::vector<T>& d )

C API
-----

.. c:function:: ElError ElDiagonal_i( ElMatrix_i A, ElInt dSize, ElInt* dBuf )
.. c:function:: ElError ElDiagonal_s( ElMatrix_s A, ElInt dSize, float* dBuf )
.. c:function:: ElError ElDiagonal_d( ElMatrix_d A, ElInt dSize, double* dBuf )
.. c:function:: ElError ElDiagonal_c( ElMatrix_c A, ElInt dSize, complex_float* dBuf )
.. c:function:: ElError ElDiagonal_z( ElMatrix_z A, ElInt dSize, complex_double* dBuf )
.. c:function:: ElError ElDiagonalDist_i( ElDistMatrix_i A, ElInt dSize, ElInt* dBuf )
.. c:function:: ElError ElDiagonalDist_s( ElDistMatrix_s A, ElInt dSize, float* dBuf )
.. c:function:: ElError ElDiagonalDist_d( ElDistMatrix_d A, ElInt dSize, double* dBuf )
.. c:function:: ElError ElDiagonalDist_c( ElDistMatrix_c A, ElInt dSize, complex_float* dBuf )
.. c:function:: ElError ElDiagonalDist_z( ElDistMatrix_z A, ElInt dSize, complex_double* dBuf )

Python API
----------

.. py:function:: Diagonal(A,d)
