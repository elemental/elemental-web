Hermitian tridiagonal eigensolvers
==================================
`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/HermitianTridiagEig.cpp>`__

Elemental provides a collection of routines for both full and partial 
solutions of the Hermitian eigenvalue problem 

.. math::

   T Z = Z \Lambda,

where `T` is a given Hermitian tridiagonal matrix, and unitary `Z` and real 
diagonal :math:`\Lambda` are sought. 

Note that the tridiagonal matrix is defined via its real main 
diagonal, `d`, and (possibly complex) *subdiagonal*, `dSub`.

Computing eigenvalues
---------------------
Compute the set of eigenvalues of the Hermitian tridiagonal matrix `T` 
determined by the `subset` structure (the default is to compute all 
eigenvalues). 

C++ API
^^^^^^^

.. cpp:function:: void HermitianTridiagEig( Matrix<Base<F>>& d, Matrix<F>& dSub, Matrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>() )
.. cpp:function:: void HermitianTridiagEig( const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& dSub, AbstractDistMatrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianTridiagEig_s( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEig_d( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEig_c( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEig_z( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElDistMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElDistMatrix_d w, ElSortType sort )

   Return the full set of eigenvalues

.. c:function:: ElError ElHermitianTridiagEigPartial_s( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPartial_d( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPartial_c( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPartial_z( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPartialDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPartialDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPartialDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPartialDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )

   Return a subset of the eigenvalues

Computing eigenpairs
--------------------
Compute the set of eigenpairs of the Hermitian tridiagonal matrix `T` 
determined by the `subset` structure (the default is to compute all eigenpairs)
via PMRRR.

C++ API
^^^^^^^

.. cpp:function:: void HermitianTridiagEig( Matrix<Base<F>>& d, Matrix<F>& dSub, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>() )
.. cpp:function:: void HermitianTridiagEig( const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& dSub, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianTridiagEigPair_s( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPair_d( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPair_c( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPair_z( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPairDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPairDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPairDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianTridiagEigPairDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort )

   Return the full set of eigenvalues

.. c:function:: ElError ElHermitianTridiagEigPairPartial_s( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartial_d( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartial_c( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartial_z( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartialDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartialDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartialDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianTridiagEigPairPartialDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )

   Return a subset of the eigenvalues

Subset computation
------------------
The :cpp:type:`HermitianEigSubset\<Real>` structure is used to control subset
computation, and, when not explicitly manipulated, defaults to a request for
the entire set of eigenvalues or eigenpairs.

C++ API
^^^^^^^

.. cpp:type:: HermitianEigSubset<Real>

   .. cpp:member:: bool indexSubset
   .. cpp:member:: Int lowerIndex
   .. cpp:member:: Int upperIndex

      If `indexSubset` is true, then the eigenvalues/pairs with indices 
      (inclusively) between `lowerIndex` and `upperIndex` will be found.

   .. cpp:member:: bool rangeSubset
   .. cpp:member:: Real lowerBound
   .. cpp:member:: Real upperBound

      Alternatively, if `rangeSubset` is true, 
      then the eigenvalues/pairs within the numerical range
      :math:`(lowerBound,upperBound]` will be found.

.. cpp:type:: HermitianEigSubset<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
^^^^^

.. c:type:: HermitianEigSubset_s

   .. c:member:: bool indexSubset
   .. c:member:: Int lowerIndex
   .. c:member:: Int upperIndex

      If `indexSubset` is true, then the eigenvalues/pairs with indices 
      (inclusively) between `lowerIndex` and `upperIndex` will be found.

   .. c:member:: bool rangeSubset
   .. c:member:: float lowerBound
   .. c:member:: float upperBound

      Alternatively, if `rangeSubset` is true, 
      then the eigenvalues/pairs within the numerical range
      :math:`(lowerBound,upperBound]` will be found.

.. c:type:: HermitianEigSubset_d

   .. c:member:: bool indexSubset
   .. c:member:: Int lowerIndex
   .. c:member:: Int upperIndex

      If `indexSubset` is true, then the eigenvalues/pairs with indices 
      (inclusively) between `lowerIndex` and `upperIndex` will be found.

   .. c:member:: bool rangeSubset
   .. c:member:: double lowerBound
   .. c:member:: double upperBound

      Alternatively, if `rangeSubset` is true, 
      then the eigenvalues/pairs within the numerical range
      :math:`(lowerBound,upperBound]` will be found.
