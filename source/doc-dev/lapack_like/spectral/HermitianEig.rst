Hermitian eigensolvers
======================
`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/HermitianEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/HermitianEig.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/HermitianEig.cpp>`__

Elemental provides a collection of routines for both full and partial 
solutions of the Hermitian eigenvalue problem 

.. math::

   A Z = Z \Lambda,

where `A` is the given Hermitian matrix, and unitary `Z` and real diagonal 
:math:`\Lambda` are sought. 

Computing eigenvalues
---------------------
Compute the set of eigenvalues of the Hermitian matrix `A` determined by
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

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& w, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianEig_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianEig_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianEig_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianEig_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianEigDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianEigDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElSortType sort )
.. c:function:: ElError ElHermitianEigDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElSortType sort )
.. c:function:: ElError ElHermitianEigDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElSortType sort )

   Return the full set of eigenvalues

**TODO: An expert interface which used HermitianEigCtrl**

.. c:function:: ElError ElHermitianEigPartial_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPartial_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPartial_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPartial_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPartialDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPartialDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPartialDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPartialDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset )

   Return a subset of the eigenvalues

Computing eigenpairs
--------------------
Compute the set of eigenpairs of the Hermitian matrix `A` determined by
the `subset` structure (the default is to compute all eigenpairs).
By default, Elemental is used to transform the problem to and from 
real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
EVP. Alternatively, the `ctrl` structure may be altered to request and tune the
usage of a (prototype) Spectral Divide and Conquer algorithm.

.. note::

   Strict subset computation is not currently supported with Spectral Divide
   and Conquer.

C++ API
^^^^^^^

.. cpp:function:: void HermitianEig( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=ASCENDING, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElHermitianEigPair_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPair_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPair_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPair_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPairDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPairDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPairDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort )
.. c:function:: ElError ElHermitianEigPairDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort )

   Return the full eigenvalue decomposition.

**TODO: An expert interface which used HermitianEigCtrl**

.. c:function:: ElError ElHermitianEigPairPartial_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPairPartial_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPairPartial_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPairPartial_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPairPartialDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPairPartialDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset )
.. c:function:: ElError ElHermitianEigPairPartialDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset )
.. c:function:: ElError ElHermitianEigPairPartialDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset )

   Return a subset of the eigenpairs

Algorithmic options
-------------------
The default approach starts with Householder tridiagonalization 
(ala :cpp:func:`HermitianTridiag`) and then calls Matthias Petschow and 
Paolo Bientinesi's PMRRR for the tridiagonal eigenvalue problem.

However, it is also possible to use a (prototype) Spectral Divide and 
Conquer algorithm (see, for example, *Stable and efficient spectral divide and conquer algorithms for the symmetric eigenvalue problem*, Nakatsukasa et al., and *Fast linear algebra is stable*, Demmel et al.). In order to do so, the 
:cpp:type:`HermitianEigCtrl\<Real>` structure should be modified so that 
`useSDC` is true. The Spectral Divide and Conquer algorithm (if selected) is 
controlled via the :cpp:type:`HermitianSDCCtrl\<Real>` member structure.

C++ API
^^^^^^^

.. cpp:type:: HermitianEigCtrl<Real>

   .. cpp:member:: HermitianTridiagCtrl tridiagCtrl
   .. cpp:member:: HermitianSDCCtrl<Real> sdcCtrl
   .. cpp:member:: bool useSDC

   .. cpp:function:: HermitianEigCtrl()

      Initializes `tridiagCtrl` and `sdcCtrl` to their defaults and sets
      `useSDC` to false.

.. cpp:type:: HermitianEigCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

.. cpp:type:: HermitianSDCCtrl<Real>

   .. cpp:member:: Int cutoff
   .. cpp:member:: Int maxInnerIts
   .. cpp:member:: Int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

   .. cpp:function:: HermitianSDCCtrl()

      Defaults to using a sequential Schur decomposition for problems of size 
      256 or smaller (``cutoff=256``), a maximum of two random rank-revealing 
      attempts per spectral split trials (``maxInnerIts=2``), and a maximum of 
      ten trial spectral split trials before failure (``maxOuterIts=10``).
      The tolerance for accepting a split is kept at its default 
      (via ``tol=0``), the relative spreading factor for perturbing the 
      estimate of the projected spectral median is set to :`1e-6` 
      (``spreadFactor=1e-6``), and progress is not displayed by default 
      (``progress=false``).

.. cpp:type:: HermitianSDCCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
^^^^^

.. c:type:: HermitianEigCtrl_s

   .. c:member:: ElHermitianTridiagCtrl tridiagCtrl
   .. c:member:: ElHermitianSDCCtrl_s sdcCtrl
   .. c:member:: bool useSDC

.. c:type:: HermitianEigCtrl_d

   .. c:member:: ElHermitianTridiagCtrl tridiagCtrl
   .. c:member:: ElHermitianSDCCtrl_d sdcCtrl
   .. c:member:: bool useSDC

.. c:function:: void ElHermitianEigCtrlDefault_s( ElHermitianEigCtrl_s* ctrl )
.. c:function:: void ElHermitianEigCtrlDefault_d( ElHermitianEigCtrl_d* ctrl )

      Initializes `tridiagCtrl` and `sdcCtrl` to their defaults and sets
      `useSDC` to false.

.. c:type:: ElHermitianSDCCtrl_s

   .. c:member:: ElInt cutoff
   .. c:member:: ElInt maxInnerIts
   .. c:member:: ElInt maxOuterIts
   .. c:member:: float tol
   .. c:member:: float spreadFactor
   .. c:member:: bool random
   .. c:member:: bool progress

.. c:type:: ElHermitianSDCCtrl_d

   .. c:member:: ElInt cutoff
   .. c:member:: ElInt maxInnerIts
   .. c:member:: ElInt maxOuterIts
   .. c:member:: double tol
   .. c:member:: double spreadFactor
   .. c:member:: bool random
   .. c:member:: bool progress

.. c:function:: ElHermitianSDCCtrlDefault_s( ElHermitianSDCCtrl_s* ctrl )
.. c:function:: ElHermitianSDCCtrlDefault_d( ElHermitianSDCCtrl_d* ctrl )

   Defaults to using a sequential Schur decomposition for problems of size 
   256 or smaller (``cutoff=256``), a maximum of two random rank-revealing 
   attempts per spectral split trials (``maxInnerIts=2``), and a maximum of ten
   trial spectral split trials before failure (``maxOuterIts=10``).
   The tolerance for accepting a split is kept at its default (via ``tol=0``),
   the relative spreading factor for perturbing the estimate of the projected
   spectral median is set to :`1e-6` (``spreadFactor=1e-6``), and progress is
   not displayed by default (``progress=false``).
