Hermitian generalized-definite eigensolvers
===========================================
The following Hermitian generalized-definite eigenvalue problems frequently 
appear, where both :math:`A` and :math:`B` are Hermitian, and :math:`B` is 
additionally positive-definite:

.. math::

   ABx = \lambda x,

which is denoted with the value ``ABX`` via the :cpp:type:`Pencil` enum,

.. math::

   BAx = \lambda x,

which uses the ``BAX`` value, and finally

.. math::

   Ax = \lambda B x,

which uses the ``AXBX`` enum value.

.. cpp:type:: Pencil

   An enum for specifying either the ``ABX``, ``BAX``, or ``AXBX`` 
   generalized eigenvalue problems (described above).

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/HermitianGenDefEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/HermitianGenDefEig.cpp>`__

Computing eigenvalues
---------------------
Compute the set of eigenvalues of the Hermitian-definite matrix pencil 
determined by
the `subset` structure (the default is to compute all eigenvalues).
By default, Elemental is used to transform the problem to and from
real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
EVP. Alternatively, the `ctrl` structure may be altered to request the
usage of a (prototype) Spectral Divide and Conquer algorithm.

.. note::

   Strict subset computation is not currently supported with Spectral Divide
   and Conquer.

C++ API
^^^^^^^

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianGenDefEig_s( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEig_d( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEig_c( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEig_z( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigDist_s( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigDist_d( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigDist_c( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigDist_z( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElSortType sort )

.. c:function:: ElError ElHermitianGenDefEigPartial_s( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPartial_d( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPartial_c( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPartial_z( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, SortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPartialDist_s( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPartialDist_d( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPartialDist_c( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPartialDist_z( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )

Computing eigenpairs
--------------------
Compute the set of eigenpairs of the Hermitian-definite matrix pencil 
determined by
the `subset` structure (the default is to compute all eigenpairs).
By default, Elemental is used to transform the problem to and from
real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
EVP. Alternatively, the `ctrl` structure may be altered to request the
usage of a (prototype) Spectral Divide and Conquer algorithm.

.. note::

   Strict subset computation is not currently supported with Spectral Divide
   and Conquer.

C++ API
^^^^^^^

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianGenDefEigPair_s( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPair_d( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPair_c( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPair_z( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPairDist_s( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPairDist_d( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPairDist_c( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianGenDefEigPairDist_z( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort )

.. c:function:: ElError ElHermitianGenDefEigPairPartial_s( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartial_d( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartial_c( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartial_z( ElPencil pencil, ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartialDist_s( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartialDist_d( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartialDist_c( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianGenDefEigPairPartialDist_z( ElPencil pencil, ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
