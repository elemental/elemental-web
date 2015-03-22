Schatten norms
==============

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementations <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Schatten.cpp>`__

The following routines compute the :math:`\ell_p` norm of the singular values.

C++ API
-------

.. cpp:function:: Base<F> SchattenNorm( const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SchattenNorm( const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> SymmetricSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const Matrix<F>& A, Base<F> p )
.. cpp:function:: Base<F> HermitianSchattenNorm( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> p )

C API
-----

.. c:function:: ElError ElSchattenNorm_s( ElConstMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSchattenNorm_d( ElConstMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSchattenNorm_c( ElConstMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSchattenNorm_z( ElConstMatrix_z A, double p, double* norm )

.. c:function:: ElError ElSchattenNormDist_s( ElConstDistMatrix_s A, float p, float* norm )
.. c:function:: ElError ElSchattenNormDist_d( ElConstDistMatrix_d A, double p, double* norm )
.. c:function:: ElError ElSchattenNormDist_c( ElConstDistMatrix_c A, float p, float* norm )
.. c:function:: ElError ElSchattenNormDist_z( ElConstDistMatrix_z A, double p, double* norm )

Python API
----------
**TODO**
