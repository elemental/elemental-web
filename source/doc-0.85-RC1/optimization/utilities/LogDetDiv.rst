LogDetDiv
=========
The *log-det divergence* of a pair of :math:`n \times n` Hermitian
positive-definite matrices :math:`A` and :math:`B` is

.. math::

   D_{ld}(A,B) = \mbox{tr}(A B^{-1}) -\log(\mbox{det}(A B^{-1})) - n,

which can be greatly simplified using the Cholesky factors of :math:`A` and :math:`B`.
In particular, if we set :math:`Z = L_B^{-1} L_A`, where :math:`A=L_A L_A^H` and 
:math:`B=L_B L_B^H` are Cholesky factorizations, then

.. math::

   D_{ld}(A,B) = \| Z \|_F^2 - 2 \log(\mbox{det}(Z)) - n.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/optimization/LogDetDiv.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/optimization/LogDetDiv.cpp>`__

C++ API
-------

.. cpp:function:: Base<F> LogDetDiv( UpperOrLower uplo, const Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: Base<F> LogDetDiv( UpperOrLower uplo, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B )

C API
-----

.. c:function:: ElError ElLogDetDiv_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElConstMatrix_s B )
.. c:function:: ElError ElLogDetDiv_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElConstMatrix_d B )
.. c:function:: ElError ElLogDetDiv_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElConstMatrix_c B )
.. c:function:: ElError ElLogDetDiv_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElConstMatrix_z B )
.. c:function:: ElError ElLogDetDivDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElConstDistMatrix_s B )
.. c:function:: ElError ElLogDetDivDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElConstDistMatrix_d B )
.. c:function:: ElError ElLogDetDivDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElConstDistMatrix_c B )
.. c:function:: ElError ElLogDetDivDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElConstDistMatrix_z B )
