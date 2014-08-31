Reduction to condensed form
===========================
`Header <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/condense.hpp>`__

Hermitian to tridiagonal
------------------------
The currently best-known algorithms for computing eigenpairs of dense Hermitian 
matrices begin by performing a unitary similarity transformation which reduces 
the matrix to real symmetric tridiagonal form (usually through Householder 
transformations). This routine performs said reduction on a Hermitian matrix 
and stores the scaled Householder vectors in place of the introduced zeroes. 

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/HermitianTridiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack-like/condense/HermitianTridiag>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/HermitianTridiag.cpp>`__

.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Overwrites the main and sub (super) diagonal of the real matrix 
   `A` with its similar symmetric tridiagonal matrix and stores the scaled 
   Householder vectors below (above) its tridiagonal entries.
   Complex Hermitian reductions have the added complication of needing to 
   also store the scalings for the Householder vectors (the scaling can
   be inferred since the Householder vectors must be unit length) if they are 
   to be applied (in the column vector `t`). 

.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HermitianTridiag( UpperOrLower uplo, AbstractDistMatrix<F>& A, const HermitianTridiagCtrl& ctrl=HermitianTridiagCtrl() )

   Returns just the (appropriate triangle of the) resulting tridiagonal matrix.

Algorithmic options
^^^^^^^^^^^^^^^^^^^

.. cpp:type:: HermitianTridiagCtrl

   .. cpp:member:: HermitianTridiagApproach approach
   .. cpp:member:: GridOrder order

   .. cpp:function:: HermitianTridiagCtrl()

      Sets `approach` to ``HERMITIAN_TRIDIAG_SQUARE`` and `order` to 
      ``ROW_MAJOR``.

.. note::

   Please see the :ref:`lapack-tuning` section for extensive information on 
   maximizing the performance of Householder tridiagonalization.

Auxiliary routines
^^^^^^^^^^^^^^^^^^

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/HermitianTridiag/ApplyQ.hpp>`__

.. cpp:function:: void hermitian_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void hermitian_tridiag::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

   Apply (from the left or right) the implicitly defined unitary matrix 
   (or its adjoint) represented by the Householder transformations stored within
   the specified triangle of `A` and their scalings are stored in the vector 
   `t`.

Square to Hessenberg
--------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/Hessenberg.cpp>`__

`Subroutine header files <https://github.com/elemental/Elemental/tree/master/src/lapack-like/condense/Hessenberg>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/Hessenberg.cpp>`__

.. cpp:function:: void Hessenberg( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void Hessenberg( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t )

   Returns the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. cpp:function:: void Hessenberg( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Hessenberg( UpperOrLower uplo, AbstractDistMatrix<F>& A )

    Returns just the Hessenberg matrix.

Auxiliary routines
^^^^^^^^^^^^^^^^^^
**TODO**

.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& H )
.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& H )

General to bidiagonal
---------------------
Reduces a general fully-populated :math:`m \times n` matrix to bidiagonal form 
through two-sided Householder transformations; when the :math:`m \ge n`, the 
result is upper bidiagonal, otherwise it is lower bidiagonal. This routine is 
most commonly used as a preprocessing step in computing the SVD of a general
matrix.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/condense/Bidiag.cpp>`__

`Subroutine implementations <https://github.com/elemental/Elemental/tree/master/src/lapack-like/condense/Bidiag>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/Bidiag.cpp>`__

.. cpp:function:: void Bidiag( Matrix<F>& A, Matrix<F>& tP, Matrix<F>& tQ )
.. cpp:function:: void Bidiag( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tP, AbstractDistMatrix<F>& tQ )

   Overwrites the main and sub (or super) diagonal of the real matrix `A` with 
   the resulting bidiagonal matrix and stores the scaled Householder vectors in 
   the remainder of the matrix.
   The complex case must also store the scalings of the Householder 
   transformations (in `tP` and `tQ`) if they are to be applied.

.. cpp:function:: void Bidiag( Matrix<F>& A )
.. cpp:function:: void Bidiag( AbstractDistMatrix<F>& A )

   Returns just the resulting bidiagonal matrix.

Auxiliary routines
^^^^^^^^^^^^^^^^^^
**TODO**

.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )
.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& B )
.. cpp:function:: void bidiag::ApplyP( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& B )

