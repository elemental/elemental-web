Hermitian Positive-Definite
===========================
This routine uses a custom algorithm for computing the inverse of a
Hermitian positive-definite matrix :math:`A` as

.. math::

   A^{-1} = (L L^H)^{-1} = L^{-H} L^{-1}, 

where :math:`L` is the lower Cholesky factor of :math:`A` (the upper Cholesky
factor is computed in the case of upper-triangular storage). Rather than
performing Cholesky factorization, triangular inversion, and then the Hermitian
triangular outer product in sequence, this routine makes use of the single-sweep
algorithm described in [BGvdG2008]_ (in particular, the variant 2 algorithm 
from Fig. 9).

If the matrix is found to not be HPD, then a :cpp:type:`NonHPDMatrixException`
is thrown.

Python API
----------
.. py:function:: HPDInverse(uplo,A)

C++ API
-------

.. cpp:function:: void HPDInverse( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPDInverse( UpperOrLower uplo, AbstractDistMatrix<F>& A )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHPDInverse_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHPDInverseDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHPDInverse_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHPDInverseDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHPDInverse_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHPDInverseDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElHPDInverse_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHPDInverseDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

.. [BGvdG2008] `Paolo Bientinesi, Brian Gunter, and Robert A. van de Geijn, *Families of algorithms related to the inversion of a Symmetric Positive Definite matrix*, ACM Transactions on Mathematical Software, Vol. 35, Issue 1, Article No. 3, 2008. <http://dl.acm.org/citation.cfm?doid=1377603.1377606>`__
