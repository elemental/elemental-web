Reduction to condensed form
===========================

Hermitian to tridiagonal
------------------------
The currently best-known algorithms for computing eigenpairs of dense Hermitian 
matrices begin by performing a unitary similarity transformation which reduces 
the matrix to real symmetric tridiagonal form (usually through Householder 
transformations). This routine performs said reduction on a Hermitian matrix 
and stores the scaled Householder vectors in place of the introduced zeroes. 

`Main source file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/src/lapack-like/HermitianTridiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack-like/HermitianTridiag>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/HermitianTridiag.cpp>`__

.. cpp:type:: HermitianTridiagCtrl

   .. cpp:member:: HermitianTridiagApproach approach
   .. cpp:member:: GridOrder order

   .. cpp:function:: HermitianTridiagCtrl()

      Sets `approach` to ``HERMITIAN_TRIDIAG_SQUARE`` and `order` to 
      ``ROW_MAJOR``.

.. note::

   Please see the :ref:`lapack-tuning` section for extensive information on 
   maximizing the performance of Householder tridiagonalization.

.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F,STAR,STAR>& t, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Overwrites the main and sub (super) diagonal of the real matrix 
   `A` with its similar symmetric tridiagonal matrix and stores the scaled 
   Householder vectors below (above) its tridiagonal entries.
   Complex Hermitian reductions have the added complication of needing to 
   also store the scalings for the Householder vectors (the scaling can
   be inferred since the Householder vectors must be unit length) if they are 
   to be applied (in the column vector `t`). 

.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, DistMatrix<F>& A, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Returns just the (appropriate triangle of the) resulting tridiagonal matrix.

hermitian_tridiag namespace
^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Implementations <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/condense/HermitianTridiag/ApplyQ.hpp>`__

.. cpp:function:: void hermitian_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void hermitian_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, DistMatrix<F>& B )
.. cpp:function:: void hermitian_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,STAR,STAR>& t, DistMatrix<F>& B )

   Apply (from the left or right) the implicitly defined unitary matrix 
   (or its adjoint) represented by the Householder transformations stored within
   the specified triangle of `A` and their scalings are stored in the vector 
   `t`.

Square to Hessenberg
--------------------

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/condense/Hessenberg.hpp>`__

`Subroutine header files <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/condense/Hessenberg>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/Hessenberg.cpp>`__

.. cpp:function:: void Hessenberg( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void Hessenberg( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<F,STAR,STAR>& t )

   Returns the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. cpp:function:: void Hessenberg( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Hessenberg( UpperOrLower uplo, DistMatrix<F>& A )

    Returns just the Hessenberg matrix.

hessenberg namespace
^^^^^^^^^^^^^^^^^^^^
**TODO**

.. cpp:function:: void hessenberg::ApplyQ( UpperOrLower uplo, LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& H )
.. cpp:function:: void hessenberg::ApplyQ( UpperOrLower uplo, LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, DistMatrix<F>& H )
.. cpp:function:: void hessenberg::ApplyQ( UpperOrLower uplo, LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,STAR,STAR>& t, DistMatrix<F>& H )

General to bidiagonal
---------------------
Reduces a general fully-populated :math:`m \times n` matrix to bidiagonal form 
through two-sided Householder transformations; when the :math:`m \ge n`, the 
result is upper bidiagonal, otherwise it is lower bidiagonal. This routine is 
most commonly used as a preprocessing step in computing the SVD of a general
matrix.

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/condense/Bidiag.hpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/condense/Bidiag>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/Bidiag.cpp>`__

.. cpp:function:: void Bidiag( Matrix<F>& A, Matrix<F>& tP, Matrix<F>& tQ )
.. cpp:function:: void Bidiag( DistMatrix<F>& A, DistMatrix<F,STAR,STAR>& tP, DistMatrix<F,STAR,STAR>& tQ )

   Overwrites the main and sub (or super) diagonal of the real matrix `A` with 
   the resulting bidiagonal matrix and stores the scaled Householder vectors in 
   the remainder of the matrix.
   The complex case must also store the scalings of the Householder 
   transformations (in `tP` and `tQ`) if they are to be applied.

.. cpp:function:: void Bidiag( Matrix<F>& A )
.. cpp:function:: void Bidiag( DistMatrix<F>& A )

   Returns just the resulting bidiagonal matrix.

bidiag namespace
^^^^^^^^^^^^^^^^
**TODO**

.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, DistMatrix<F>& B )
.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,STAR,STAR>& t, DistMatrix<F>& B )

.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, DistMatrix<F>& B )
.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,STAR,STAR>& t, DistMatrix<F>& B )

