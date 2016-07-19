LogBarrier
==========
Uses a careful calculation of the log of the determinant in order to return
the *log barrier* of a Hermitian positive-definite matrix `A`,
:math:`-\log(\mbox{det}(A))`.

`Implementations <https://github.com/elemental/Elemental/blob/master/src/optimization/LogBarrier.cpp>`__

C++ API
-------

.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const Matrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, const AbstractDistMatrix<F>& A )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, Matrix<F>& A, bool canOverwrite=false )
.. cpp:function:: Base<F> LogBarrier( UpperOrLower uplo, AbstractDistMatrix<F>& A, bool canOverwrite=false )

C API
-----

.. c:function:: ElError ElLogBarrier_s( ElUpperOrLower uplo, ElConstMatrix_s A, float* barrier )
.. c:function:: ElError ElLogBarrier_d( ElUpperOrLower uplo, ElConstMatrix_d A, double* barrier )
.. c:function:: ElError ElLogBarrier_c( ElUpperOrLower uplo, ElConstMatrix_c A, float* barrier )
.. c:function:: ElError ElLogBarrier_z( ElUpperOrLower uplo, ElConstMatrix_z A, double* barrier )
.. c:function:: ElError ElLogBarrierDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, float* barrier )
.. c:function:: ElError ElLogBarrierDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, double* barrier )
.. c:function:: ElError ElLogBarrierDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, float* barrier )
.. c:function:: ElError ElLogBarrierDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, double* barrier )
