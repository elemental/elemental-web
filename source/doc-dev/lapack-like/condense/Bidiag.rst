General to bidiagonal
=====================
Reduces a general fully-populated :math:`m \times n` matrix to bidiagonal form 
through two-sided Householder transformations; when the :math:`m \ge n`, the 
result is upper bidiagonal, otherwise it is lower bidiagonal. This routine is 
most commonly used as a preprocessing step in computing the SVD of a general
matrix.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/Bidiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack-like/condense/Bidiag>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/Bidiag.cpp>`__

Reduction
---------

C++ API
^^^^^^^

.. cpp:function:: void Bidiag( Matrix<F>& A, Matrix<F>& tP, Matrix<F>& tQ )
.. cpp:function:: void Bidiag( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tP, AbstractDistMatrix<F>& tQ )

   Overwrites the main and sub (or super) diagonal of the real matrix `A` with 
   the resulting bidiagonal matrix and stores the scaled Householder vectors in 
   the remainder of the matrix.
   The complex case must also store the scalings of the Householder 
   transformations (in `tP` and `tQ`) if they are to be applied.

.. cpp:function:: void bidiag::Explicit( Matrix<F>& A, Matrix<F>& P, Matrix<F>& Q )
.. cpp:function:: void bidiag::Explicit( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& P, AbstractDistMatrix<F>& Q )

   Overwrite :math:`A` with the bidiagonal matrix, :math:`B = Q^H A P`, and 
   also return :math:`P` and :math:`Q`.

.. cpp:function:: void bidiag::ExplicitCondensed( Matrix<F>& A )
.. cpp:function:: void bidiag::ExplicitCondensed( AbstractDistMatrix<F>& A )

   Returns just the resulting bidiagonal matrix, :math:`B = Q^H A P`.

C API
^^^^^

.. c:function:: ElError ElBidiag_s( ElMatrix_s A, ElMatrix_s tP, ElMatrix_s tQ )
.. c:function:: ElError ElBidiag_d( ElMatrix_d A, ElMatrix_d tP, ElMatrix_d tQ )
.. c:function:: ElError ElBidiag_c( ElMatrix_c A, ElMatrix_c tP, ElMatrix_c tQ )
.. c:function:: ElError ElBidiag_z( ElMatrix_z A, ElMatrix_z tP, ElMatrix_z tQ )
.. c:function:: ElError ElBidiagDist_s( ElDistMatrix_s A, ElDistMatrix_s tP, ElDistMatrix_s tQ )
.. c:function:: ElError ElBidiagDist_d( ElDistMatrix_d A, ElDistMatrix_d tP, ElDistMatrix_d tQ )
.. c:function:: ElError ElBidiagDist_c( ElDistMatrix_c A, ElDistMatrix_c tP, ElDistMatrix_c tQ )
.. c:function:: ElError ElBidiagDist_z( ElDistMatrix_z A, ElDistMatrix_z tP, ElDistMatrix_z tQ )

   Overwrites the main and sub (or super) diagonal of the real matrix `A` with 
   the resulting bidiagonal matrix and stores the scaled Householder vectors in 
   the remainder of the matrix.
   The complex case must also store the scalings of the Householder 
   transformations (in `tP` and `tQ`) if they are to be applied.

.. c:function:: ElError ElBidiagExplicit_s( ElMatrix_s A, ElMatrix_s P, ElMatrix_s Q )
.. c:function:: ElError ElBidiagExplicit_d( ElMatrix_d A, ElMatrix_d P, ElMatrix_d Q )
.. c:function:: ElError ElBidiagExplicit_c( ElMatrix_c A, ElMatrix_c P, ElMatrix_c Q )
.. c:function:: ElError ElBidiagExplicit_z( ElMatrix_z A, ElMatrix_z P, ElMatrix_z Q )
.. c:function:: ElError ElBidiagExplicitDist_s( ElDistMatrix_s A, ElDistMatrix_s P, ElDistMatrix_s Q )
.. c:function:: ElError ElBidiagExplicitDist_d( ElDistMatrix_d A, ElDistMatrix_d P, ElDistMatrix_d Q )
.. c:function:: ElError ElBidiagExplicitDist_c( ElDistMatrix_c A, ElDistMatrix_c P, ElDistMatrix_c Q )
.. c:function:: ElError ElBidiagExplicitDist_z( ElDistMatrix_z A, ElDistMatrix_z P, ElDistMatrix_z Q )

   Overwrite :math:`A` with the bidiagonal matrix, :math:`B = Q^H A P`, and 
   also return :math:`P` and :math:`Q`.

.. c:function:: ElError ElBidiagExplicitCondensed_s( ElMatrix_s A )
.. c:function:: ElError ElBidiagExplicitCondensed_d( ElMatrix_d A )
.. c:function:: ElError ElBidiagExplicitCondensed_c( ElMatrix_c A )
.. c:function:: ElError ElBidiagExplicitCondensed_z( ElMatrix_z A )
.. c:function:: ElError ElBidiagExplicitCondensedDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElBidiagExplicitCondensedDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElBidiagExplicitCondensedDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElBidiagExplicitCondensedDist_z( ElDistMatrix_z A )

   Returns just the resulting bidiagonal matrix, :math:`B = Q^H A P`.

Applying the changes of basis
-----------------------------

C++ API
^^^^^^^

.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

C API
^^^^^

.. c:function:: ElError ElApplyQAfterBidiag_s( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElMatrix_s B )
.. c:function:: ElError ElApplyQAfterBidiag_d( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterBidiag_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterBidiag_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterBidiagDist_s( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElDistMatrix_s B )
.. c:function:: ElError ElApplyQAfterBidiagDist_d( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d B )
.. c:function:: ElError ElApplyQAfterBidiagDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c B )
.. c:function:: ElError ElApplyQAfterBidiagDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z B )

.. c:function:: ElError ElApplyPAfterBidiag_s( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElMatrix_s B )
.. c:function:: ElError ElApplyPAfterBidiag_d( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d B )
.. c:function:: ElError ElApplyPAfterBidiag_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c B )
.. c:function:: ElError ElApplyPAfterBidiag_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z B )
.. c:function:: ElError ElApplyPAfterBidiagDist_s( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElDistMatrix_s B )
.. c:function:: ElError ElApplyPAfterBidiagDist_d( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d B )
.. c:function:: ElError ElApplyPAfterBidiagDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c B )
.. c:function:: ElError ElApplyPAfterBidiagDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z B )
