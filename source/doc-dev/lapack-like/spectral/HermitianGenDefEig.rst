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

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/HermitianGenDefEig.cpp>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianGenDefEig.cpp>`__

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

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

.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, Matrix<F>& A, Matrix<F>& B, Matrix<Base<F>>& w, Matrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )
.. cpp:function:: void HermitianGenDefEig( Pencil pencil, UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<Base<F>>& w, AbstractDistMatrix<F>& Z, SortType sort=UNSORTED, const HermitianEigSubset<Base<F>> subset=HermitianEigSubset<Base<F>>(), const HermitianEigCtrl<Base<F>> ctrl=HermitianEigCtrl<Base<F>>() )

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

