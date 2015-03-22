Zero norms
==========

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Zero.cpp>`__

The following routines return the number of nonzero entries in the matrix.
This operation is often casually referred to as the zero "norm".

C++ API
-------

.. cpp:function:: Int ZeroNorm( const Matrix<T>& A )
.. cpp:function:: Int ZeroNorm( const AbstractDistMatrix<T>& A )

C API
-----

.. c:function:: ElError ElZeroNorm_i( ElConstMatrix_i, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_s( ElConstMatrix_s, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_d( ElConstMatrix_d, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_c( ElConstMatrix_c, ElInt* numNonzero )
.. c:function:: ElError ElZeroNorm_z( ElConstMatrix_z, ElInt* numNonzero )

.. c:function:: ElError ElZeroNormDist_i( ElConstDistMatrix_i, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_s( ElConstDistMatrix_s, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_d( ElConstDistMatrix_d, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_c( ElConstDistMatrix_c, ElInt* numNonzero )
.. c:function:: ElError ElZeroNormDist_z( ElConstDistMatrix_z, ElInt* numNonzero )

Python API
----------
**TODO**
