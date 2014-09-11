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

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the imaginary components of the eigenvalues of the skew-Hermitian 
   matrix `G` determined by
   the `subset` structure (the default is to compute all eigenvalues).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.

.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, Matrix<F>& G, Matrix<Base<F>>& w, Matrix<Complex<Base<F>>>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void SkewHermitianEig( UpperOrLower uplo, AbstractDistMatrix<F>& G, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<Complex<Base<F>>>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>>& subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>>& ctrl=HermitianEigCtrl<Base<F>>() )

   Compute the set of eigenpairs (note that only the imaginary components of 
   the eigenvalues are returned) of the skew-Hermitian matrix `G` determined by
   the `subset` structure (the default is to compute all eigenpairs).
   By default, Elemental is used to transform the problem to and from
   real symmetric tridiagonal form and PMRRR is used to solve the tridiagonal
   EVP. Alternatively, the `ctrl` structure may be altered to request the
   usage of a (prototype) Spectral Divide and Conquer algorithm.

   .. note::

      Strict subset computation is not currently supported with Spectral Divide
      and Conquer.
