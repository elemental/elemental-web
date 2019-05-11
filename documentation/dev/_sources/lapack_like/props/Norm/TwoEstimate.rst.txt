Two-norm estimates
==================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Norm/Two.cpp>`__

The following routines return an estimate for the two-norm which should be 
accurate within a factor of :math:`n` times the specified tolerance.

C++ API
-------

.. cpp:function:: Base<F> TwoNormEstimate( const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> TwoNormEstimate( const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

.. cpp:function:: Base<F> SymmetricTwoNormEstimate( UpperOrLower uplo, const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> SymmetricTwoNormEstimate( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

.. cpp:function:: Base<F> HermitianTwoNormEstimate( UpperOrLower uplo, const Matrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )
.. cpp:function:: Base<F> HermitianTwoNormEstimate( UpperOrLower uplo, const AbstractDistMatrix<F>& A, Base<F> tol=1e-6, Int maxIts=1000 )

C API
-----

.. c:function:: ElError ElTwoNormEstimate_s( ElConstMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_d( ElConstMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_c( ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimate_z( ElConstMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElTwoNormEstimateDist_s( ElConstDistMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_d( ElConstDistMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_c( ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElTwoNormEstimateDist_z( ElConstDistMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElSymmetricTwoNormEstimate_s( ElUpperOrLower uplo, ElConstMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_d( ElUpperOrLower uplo, ElConstMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_c( ElUpperOrLower uplo, ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimate_z( ElUpperOrLower uplo, ElConstMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElSymmetricTwoNormEstimateDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElSymmetricTwoNormEstimateDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElHermitianTwoNormEstimate_c( ElUpperOrLower uplo, ElConstMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElHermitianTwoNormEstimate_z( ElUpperOrLower uplo, ElConstMatrix_z A, double tol, ElInt maxIts )

.. c:function:: ElError ElHermitianTwoNormEstimateDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float tol, ElInt maxIts )
.. c:function:: ElError ElHermitianTwoNormEstimateDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double tol, ElInt maxIts )

Python API
----------
**TODO**
