Hermitian SVD
=============

Suppose that :math:`A` is Hermitian, with a spectral decomposition

.. math::

   A = V \Lambda V^H.

Then an SVD of :math:`A` can easily be computed as

.. math::

   A = U |\Lambda| V^H,

where the columns of :math:`U` equal the columns of :math:`V`, modulo sign 
flips introduced by negative eigenvalues.

Computing singular values
-------------------------
The following routines return the singular values of :math:`A` in `s`. Note 
that the appropriate triangle of `A` is overwritten during computation.

C++ API
^^^^^^^

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s )

C API
^^^^^

.. c:function:: ElError ElHermitianSingularValues_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s s )
.. c:function:: ElError ElHermitianSingularValues_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d s )
.. c:function:: ElError ElHermitianSingularValues_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s s )
.. c:function:: ElError ElHermitianSingularValues_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d s )
.. c:function:: ElError ElHermitianSingularValuesDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s s )
.. c:function:: ElError ElHermitianSingularValuesDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d s )
.. c:function:: ElError ElHermitianSingularValuesDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s s )
.. c:function:: ElError ElHermitianSingularValuesDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d s )

Computing Singular Value Decompositions
---------------------------------------
The following routines return a vector of singular values, :math:`s`, and the 
left and right singular vector matrices, :math:`U` and :math:`V`, such that 
:math:`A=U \mathrm{diag}(s) V^H`.

C++ API
^^^^^^^

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& U, Matrix<F>& V )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& U, AbstractDistMatrix<F>& V )

C API
^^^^^

.. c:function:: ElError ElHermitianSVD_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s s, ElMatrix_s U, ElMatrix_s V )
.. c:function:: ElError ElHermitianSVD_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d s, ElMatrix_d U, ElMatrix_d V )
.. c:function:: ElError ElHermitianSVD_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s s, ElMatrix_c U, ElMatrix_c V )
.. c:function:: ElError ElHermitianSVD_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d s, ElMatrix_z U, ElMatrix_z V )
.. c:function:: ElError ElHermitianSVDDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s s, ElDistMatrix_s U, ElDistMatrix_s V )
.. c:function:: ElError ElHermitianSVDDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d s, ElDistMatrix_d U, ElDistMatrix_d V )
.. c:function:: ElError ElHermitianSVDDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s s, ElDistMatrix_c U, ElDistMatrix_c V )
.. c:function:: ElError ElHermitianSVDDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d s, ElDistMatrix_z U, ElDistMatrix_z V )
