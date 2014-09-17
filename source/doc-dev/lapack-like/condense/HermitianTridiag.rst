Hermitian to tridiagonal
========================
The standard approach for computing eigenpairs of dense Hermitian 
matrices begins by performing a unitary similarity transformation which reduces 
the matrix to real symmetric tridiagonal form (usually through Householder 
transformations). The following routines perform said reduction on a Hermitian 
matrix and store the scaled Householder vectors in place of the introduced 
zeroes. 

.. note:: 

   While so-called *Successive Band Reduction* approaches, which reduce the
   matrix to tridiagonal form using a two-stage process, are sometimes 
   preferred, they are not yet supported within Elemental. Please see 
   `ELPA <http://elpa.rzg.mpg.de/>`__ for such an implementation.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/HermitianTridiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack-like/condense/HermitianTridiag>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianTridiag.cpp>`__

Reduction
---------

C++ API
^^^^^^^

.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Overwrites the main and sub (super) diagonal of the real matrix 
   `A` with its similar symmetric tridiagonal matrix and stores the scaled 
   Householder vectors below (above) its tridiagonal entries.
   Complex Hermitian reductions have the added complication of needing to 
   also store the scalings for the Householder vectors (the scaling can
   be inferred since the Householder vectors must be unit length) if they are 
   to be applied (in the column vector `t`). 

.. cpp:function:: void herm_tridiag::ExplicitCondensed( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void herm_tridiag::ExplicitCondensed( UpperOrLower uplo, AbstractDistMatrix<F>& A, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Returns just the (appropriate triangle of the) resulting tridiagonal matrix.

.. cpp:type:: HermitianTridiagCtrl

   .. cpp:member:: HermitianTridiagApproach approach
   .. cpp:member:: GridOrder order

   .. cpp:function:: HermitianTridiagCtrl()

      Sets `approach` to ``HERMITIAN_TRIDIAG_SQUARE`` and `order` to 
      ``ROW_MAJOR``.

.. note::

   Please see the :ref:`lapack-tuning` section for extensive information on 
   maximizing the performance of Householder tridiagonalization.

C API
^^^^^

.. c:type:: ElHermitianTridiagCtrl

   .. cpp:member:: ElHermitianTridiagApproach approach
   .. cpp:member:: ElGridOrder order

.. c:function:: ElHermitianTridiagCtrlDefault( ElHermitianTridiagCtrl* ctrl )

   Sets `approach` to ``HERMITIAN_TRIDIAG_SQUARE`` and `order` to ``ROW_MAJOR``.

.. c:function:: ElError ElHermitianTridiag_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s t )
.. c:function:: ElError ElHermitianTridiag_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d t )
.. c:function:: ElError ElHermitianTridiag_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c t )
.. c:function:: ElError ElHermitianTridiag_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z t )
.. c:function:: ElError ElHermitianTridiagDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t )
.. c:function:: ElError ElHermitianTridiagDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t )
.. c:function:: ElError ElHermitianTridiagDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t )
.. c:function:: ElError ElHermitianTridiagDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t )

.. c:function:: ElError ElHermitianTridiagXDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t, ElHermitianTridiagCtrl ctrl )
.. c:function:: ElError ElHermitianTridiagXDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t, ElHermitianTridiagCtrl ctrl )
.. c:function:: ElError ElHermitianTridiagXDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t, ElHermitianTridiagCtrl ctrl )
.. c:function:: ElError ElHermitianTridiagXDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t, ElHermitianTridiagCtrl ctrl )

.. c:function:: ElError ElHermitianTridiagExplicitCondensed_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensed_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensed_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensed_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElHermitianTridiag ctrl )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElHermitianTridiag ctrl )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElHermitianTridiag ctrl )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElHermitianTridiag ctrl )

Applying the change of basis
----------------------------
Apply (from the left or right) the implicitly defined unitary matrix 
(or its adjoint) represented by the Householder transformations stored within
the specified triangle of `A` and their scalings are stored in the vector 
`t`.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/HermitianTridiag/ApplyQ.hpp>`__

C++ API
^^^^^^^

.. cpp:function:: void herm_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void herm_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

C API
^^^^^

.. c:function:: ElError ElApplyQAfterHermitianTridiag_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElMatrix_s B )
.. c:function:: ElError ElApplyQAfterHermitianTridiag_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterHermitianTridiag_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterHermitianTridiag_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElDistMatrix_s B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z B )
