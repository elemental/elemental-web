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
   [ELPA2011]_ for such an implementation.

Reduction
---------
Elemental currently provides two different basic strategies for the reduction of
a Hermitian matrix to tridiagonal form via unitary similarity:

1. Run a pipelined algorithm designed for general (rectangular) process grids.

2. Redistribute the matrix so that it is owned by a perfect square number of
   processes, perform a fast reduction to tridiaogal form, and redistribute
   the data back to the original process grid. This algorithm is nearly 
   identical to that of [HJS1999]_ and [Stanley1997]_.

There is clearly a small penalty associated with the extra redistributions
necessary for the second approach, but the benefit from using a square process
grid is usually quite signficant. By default, :cpp:func:`HermitianTridiag` will
run the standard algorithm (approach 1) unless the matrix is already distributed
over a square process grid. The reasoning is that good performance depends upon
a "good" ordering of the square (say, :math:`\hat p \times \hat p`) subgrid,
though usually either a row-major or column-major ordering of the first
:math:`\hat p^2` processes suffices.


.. cpp:type:: HermitianTridiagApproach

   * ``HERMITIAN_TRIDIAG_NORMAL``: Run the pipelined rectangular algorithm.
   * ``HERMITIAN_TRIDIAG_SQUARE``: Run the square grid algorithm on the largest
     possible square process grid.
   * ``HERMITIAN_TRIDIAG_DEFAULT``: If the given process grid is already square,
     run the square grid algorithm, otherwise use the pipelined non-square
     approach.

   .. note::

      A properly tuned ``HERMITIAN_TRIDIAG_SQUARE`` approach is almost always 
      fastest, so it is worthwhile to test it with both the ``COLUMN_MAJOR`` and
      ``ROW_MAJOR`` subgrid orderings, as described below.


   .. note::
   
      The first algorithm heavily depends upon the performance of distributed 
      :cpp:func:`Symv`, so users interested in maximizing the performance of the
      first algorithm will likely want to investigate different values for the 
      local blocksizes through the routine
      ``SetLocalSymvBlocksize<T>( int blocksize )``; the default value is 64.


Python API
^^^^^^^^^^

.. py:function:: HermitianTridiag(uplo,A[,onlyTridiag=False,ctrl=None])

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

Single-precision
""""""""""""""""
.. c:function:: ElError ElHermitianTridiag_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s t )
.. c:function:: ElError ElHermitianTridiagDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t )

.. c:function:: ElError ElHermitianTridiagXDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t, ElHermitianTridiagCtrl ctrl )

.. c:function:: ElError ElHermitianTridiagExplicitCondensed_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )

.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElHermitianTridiag ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElHermitianTridiag_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d t )
.. c:function:: ElError ElHermitianTridiagDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t )

.. c:function:: ElError ElHermitianTridiagXDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t, ElHermitianTridiagCtrl ctrl )

.. c:function:: ElError ElHermitianTridiagExplicitCondensed_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )

.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElHermitianTridiag ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElHermitianTridiag_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c t )
.. c:function:: ElError ElHermitianTridiagDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t )

.. c:function:: ElError ElHermitianTridiagXDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t, ElHermitianTridiagCtrl ctrl )

.. c:function:: ElError ElHermitianTridiagExplicitCondensed_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )

.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElHermitianTridiag ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElHermitianTridiag_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z t )
.. c:function:: ElError ElHermitianTridiagDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t )

.. c:function:: ElError ElHermitianTridiagXDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t, ElHermitianTridiagCtrl ctrl )

.. c:function:: ElError ElHermitianTridiagExplicitCondensed_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHermitianTridiagExplicitCondensedDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

.. c:function:: ElError ElHermitianTridiagExplicitCondensedXDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElHermitianTridiag ctrl )

Applying the change of basis
----------------------------
Apply (from the left or right) the implicitly defined unitary matrix 
(or its adjoint) represented by the Householder transformations stored within
the specified triangle of `A` and their scalings are stored in the vector 
`t`.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/condense/HermitianTridiag/ApplyQ.hpp>`__

Python API
^^^^^^^^^^
.. py:function:: ApplyQAfterHermitianTridiag(side,uplo,orient,A,t,B)

C++ API
^^^^^^^

.. cpp:function:: void herm_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void herm_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

C API
^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElApplyQAfterHermitianTridiag_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z B )

Double-precision
""""""""""""""""
.. c:function:: ElError ElApplyQAfterHermitianTridiag_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d B )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElApplyQAfterHermitianTridiag_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c B )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElApplyQAfterHermitianTridiag_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterHermitianTridiagDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z B )

References
----------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/condense/HermitianTridiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack_like/condense/HermitianTridiag>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/HermitianTridiag.cpp>`__

.. [ELPA2011] T. Auckenthaler, V. Blum, H.-J. Bungartz, T. Huckle, R. Johanni, L. Kramer, B. Lang, H. Lederer, and P.R. Willems, *Parallel solution of partial symmetric eigenvalue problems from electronic structure calculations*, Parallel Computing, Vol. 37, Issue 12, pp. 783--794, 2011. DOI: `http://dx.doi.org/10.1016/j.parco.2011.05.002 <http://dx.doi.org/10.1016/j.parco.2011.05.002>`__

.. [HJS1999] Bruce Hendrickson, Elizabeth Jessup, and Christopher Smith, *Towards an efficient parallel eigensolver for dense symmetric matrices*, SIAM Journal on Scientific Computing, Vol. 20, No. 3, pp. 1132--1154, 1999. DOI: `http://dx.doi.org/10.1137/S1064827596300681 <http://dx.doi.org/10.1137/S1064827596300681>`__

.. [Stanley1997] Kendall S. Stanley, *Execution time of symmetric eigensolvers*, EECS Department, UC Berkeley, Technical Report No. UCB/CSD-98-992, 1997. Accessed from: `http://www.eecs.berkeley.edu/Pubs/TechRpts/1999/5365.html <http://www.eecs.berkeley.edu/Pubs/TechRpts/1999/5365.html>`__
