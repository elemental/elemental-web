Trace
=====

The two equally useful definitions of the trace of a square matrix 
:math:`A \in \mathbb{F}^{n \times n}` are

.. math::

   \mbox{tr}(A) = \sum_{i=0}^{n-1} A(i,i) = \sum_{i=0}^{n-1} \lambda_i,

where :math:`\lambda_i` is the i'th eigenvalue (counting multiplicity) of 
:math:`A`.

Clearly the former equation is easier to compute, but the latter is an 
important characterization.

Python API
----------
**TODO**

C++ API
-------

.. cpp:function:: T Trace( const Matrix<T>& A )
.. cpp:function:: T Trace( const AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElTrace_i( ElConstMatrix_i A, ElInt* trace )
.. c:function:: ElError ElTrace_s( ElConstMatrix_s A, float* trace )
.. c:function:: ElError ElTrace_d( ElConstMatrix_d A, double* trace )
.. c:function:: ElError ElTrace_c( ElConstMatrix_c A, complex_float* trace )
.. c:function:: ElError ElTrace_z( ElConstMatrix_z A, complex_double* trace )
.. c:function:: ElError ElTraceDist_i( ElConstDistMatrix_i A, ElInt* trace )
.. c:function:: ElError ElTraceDist_s( ElConstDistMatrix_s A, float* trace )
.. c:function:: ElError ElTraceDist_d( ElConstDistMatrix_d A, double* trace )
.. c:function:: ElError ElTraceDist_c( ElConstDistMatrix_c A, complex_float* trace )
.. c:function:: ElError ElTraceDist_z( ElConstDistMatrix_z A, complex_double* trace )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/props/Trace.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/props-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/props.py>`__
