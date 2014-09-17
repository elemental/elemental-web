Skew-Hermitian eigensolvers
===========================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/SkewHermitianEig.cpp>`__

Essentially identical to the Hermitian eigensolver, :cpp:func:`HermitianEig`;
for any skew-Hermitian matrix :math:`G`, :math:`iG` is Hermitian, as 

.. math::

   (iG)^H = -iG^H = iG.

This fact implies a fast method for solving skew-Hermitian eigenvalue problems:

1. Form :math:`iG` in :math:`O(n^2)` work 
   (switching to complex arithmetic in the real case)
2. Run a Hermitian eigensolve on :math:`iG`, yielding :math:`iG=Z \Lambda Z^H`.
3. Recognize that :math:`G=Z (-i \Lambda) Z^H` provides an EVD of :math:`G`.

Please see the :cpp:func:`HermitianEig` documentation for more details.

Computing eigenvalues
---------------------
The following routines compute the imaginary components of the eigenvalues of 
the skew-Hermitian matrix `G` determined by the `subset` structure (the default
is to compute all eigenvalues). By default, Elemental is used to transform the 
problem to and from real symmetric tridiagonal form and PMRRR is used to solve 
the tridiagonal EVP. Alternatively, the `ctrl` structure may be altered to 
request the usage of a (prototype) Spectral Divide and Conquer algorithm.

.. note::

   Strict subset computation is not currently supported with Spectral Divide
   and Conquer.

C++ API
^^^^^^^

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElSkewHermitianEig_s( ElUpperOrLower uplo, ElMatrix_s G, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEig_d( ElUpperOrLower uplo, ElMatrix_d G, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEig_c( ElUpperOrLower uplo, ElMatrix_c G, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEig_z( ElUpperOrLower uplo, ElMatrix_z G, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigDist_s( ElUpperOrLower uplo, ElDistMatrix_s G, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigDist_d( ElUpperOrLower uplo, ElDistMatrix_d G, ElDistMatrix_d w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigDist_c( ElUpperOrLower uplo, ElDistMatrix_c G, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigDist_z( ElUpperOrLower uplo, ElDistMatrix_z G, ElDistMatrix_d w, ElSortType sort )

.. c:function:: ElError ElSkewHermitianEigPartial_s( ElUpperOrLower uplo, ElMatrix_s G, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPartial_d( ElUpperOrLower uplo, ElMatrix_d G, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPartial_c( ElUpperOrLower uplo, ElMatrix_c G, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPartial_z( ElUpperOrLower uplo, ElMatrix_z G, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPartialDist_s( ElUpperOrLower uplo, ElDistMatrix_s G, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPartialDist_d( ElUpperOrLower uplo, ElDistMatrix_d G, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPartialDist_c( ElUpperOrLower uplo, ElDistMatrix_c G, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPartialDist_z( ElUpperOrLower uplo, ElDistMatrix_z G, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )

Computing eigenpairs
--------------------
The following routines compute the set of eigenpairs (note that only the 
imaginary components of the eigenvalues are returned) of the skew-Hermitian 
matrix `G` determined by the `subset` structure (the default is to compute all 
eigenpairs). By default, Elemental is used to transform the problem to and from
real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
EVP. Alternatively, the `ctrl` structure may be altered to request the
usage of a (prototype) Spectral Divide and Conquer algorithm.

.. note::

   Strict subset computation is not currently supported with Spectral Divide
   and Conquer.

C++ API
^^^^^^^

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, Matrix<Complex<Base<F>>>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<Complex<Base<F>>>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElSkewHermitianEigPair_s( ElUpperOrLower uplo, ElMatrix_s G, ElMatrix_s w, ElMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPair_d( ElUpperOrLower uplo, ElMatrix_d G, ElMatrix_d w, ElMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPair_c( ElUpperOrLower uplo, ElMatrix_c G, ElMatrix_s w, ElMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPair_z( ElUpperOrLower uplo, ElMatrix_z G, ElMatrix_d w, ElMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPairDist_s( ElUpperOrLower uplo, ElDistMatrix_s G, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPairDist_d( ElUpperOrLower uplo, ElDistMatrix_d G, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPairDist_c( ElUpperOrLower uplo, ElDistMatrix_c G, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElSkewHermitianEigPairDist_z( ElUpperOrLower uplo, ElDistMatrix_z G, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort )

.. c:function:: ElError ElSkewHermitianEigPairPartial_s( ElUpperOrLower uplo, ElMatrix_s G, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPairPartial_d( ElUpperOrLower uplo, ElMatrix_d G, ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPairPartial_c( ElUpperOrLower uplo, ElMatrix_c G, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPairPartial_z( ElUpperOrLower uplo, ElMatrix_z G, ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPairPartialDist_s( ElUpperOrLower uplo, ElDistMatrix_s G, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPairPartialDist_d( ElUpperOrLower uplo, ElDistMatrix_d G, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElSkewHermitianEigPairPartialDist_c( ElUpperOrLower uplo, ElDistMatrix_c G, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElSkewHermitianEigPairPartialDist_z( ElUpperOrLower uplo, ElDistMatrix_z G, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
