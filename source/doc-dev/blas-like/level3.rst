Level 3
=======

The prototypes for the following routines can be found at          
`include/El/blas-like/level3.hpp <https://github.com/elemental/Elemental/tree/master/include/El/blas-like/level3.hpp>`_, while the
implementations are in 
`src/blas-like/level3/ <https://github.com/elemental/Elemental/tree/master/src/blas-like/level3>`_.

Gemm
----
General matrix-matrix multiplication: updates
:math:`C := \alpha A^\# B^\sharp + \beta C`,
where :math:`M^\#` and :math:`M^\sharp` are individually defined to be one of
:math:`\{M,M^T,M^H\}`.

.. cpp:function:: void Gemm( Orientation orientationOfA, Orientation orientationOfB, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Gemm( Orientation orientationOfA, Orientation orientationOfB, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
      distributions.

Hemm
----
Hermitian matrix-matrix multiplication: updates
:math:`C := \alpha A B + \beta C`, or 
:math:`C := \alpha B A + \beta C`, depending upon whether `side` is set to 
``LEFT`` or ``RIGHT``, respectively. In both of these types of updates, 
:math:`A` is implicitly Hermitian and only the triangle specified by `uplo` is 
accessed.

.. cpp:function:: void Hemm( LeftOrRight side, UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Hemm( LeftOrRight side, UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
      distributions.

Herk
----
Hermitian rank-K update: updates
:math:`C := \alpha A A^H + \beta C`, or 
:math:`C := \alpha A^H A + \beta C`, depending upon whether `orientation` is
set to ``NORMAL`` or ``ADJOINT``, respectively. Only the triangle of :math:`C` 
specified by the `uplo` parameter is modified.

.. cpp:function:: void Herk( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, T beta, Matrix<T>& C )
.. cpp:function:: void Herk( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A` and `C` should both be in [MC,MR] 
      distributions.

Please see :cpp:func:`SetLocalTrrkBlocksize\<T>` 
and :cpp:func:`LocalTrrkBlocksize\<T>` in the :ref:`blas-tuning`
section for information on tuning the distributed :cpp:func:`Herk`.

Her2k
-----
Hermitian rank-2K update: updates
:math:`C := \alpha (A B^H + B A^H) + \beta C`, or 
:math:`C := \alpha (A^H B + B^H A) + \beta C`, depending upon whether 
`orientation` is set to ``NORMAL`` or ``ADJOINT``, respectively. Only the 
triangle of :math:`C` specified by the `uplo` parameter is modified.

.. cpp:function:: void Her2k( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Her2k( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
      distributions.

Please see :cpp:func:`SetLocalTrr2kBlocksize\<T>` 
and :cpp:func:`LocalTrr2kBlocksize\<T>` in the 
:ref:`blas-tuning` section for information on tuning the distributed 
:cpp:func:`Her2k`.

Multi-shift QuasiTrsm
---------------------
Solve for :math:`X` in the linear system

.. math::

   T^\# X - X D^\# = Y

or

.. math::

   X T^\# - D^\# X = Y

where :math:`T` is *quasi-triangular*, :math:`D` is diagonal, and 
:math:`A^\#` is defined to be one of :math:`\{A,A^T,A^H\}`. 
The data movement requires almost no modification from that of 
:cpp:func:`QuasiTrsm`.

Note that the term *quasi-triangular* is in the context of real Schur
decompositions, which produce triangular matrices with mixes of
:math:`1 \times 1` and :math:`2 \times 2` diagonal blocks.

.. note::

   There is no corresponding BLAS routine, but it is a natural extension of
   Trsm.

.. cpp:function:: void MultiShiftQuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& T, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftQuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& T, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

   Overwrite the columns of `X` with the solutions to the shifted linear 
   systems.

.. cpp:function:: void MultiShiftQuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const Matrix<Real>& T, const Matrix<Complex<Real>>& shifts, Matrix<Real>& XReal, Matrix<Real>& XImag )
.. cpp:function:: void MultiShiftQuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const AbstractDistMatrix<Real>& T, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& XReal, AbstractDistMatrix<Real>& XImag )

   Overwrite the columns of the real and imaginary parts of `X` with the 
   solutions to the shifted linear systems.

Multi-shift Trsm
----------------
Solve for :math:`X` in the linear system

.. math::

   T^\# X - X D^\# = Y

or

.. math::

   X T^\# - D^\# X = Y

where :math:`T` is triangular, :math:`D` is diagonal, and 
:math:`A^\#` is defined to be one of :math:`\{A,A^T,A^H\}`. 
The data movement requires almost no modification from that of :cpp:func:`Trsm`.

.. note::

   There is no corresponding BLAS routine, but it is a natural modification
   of Trsm.

.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& T, const Matrix<F>& shifts, Matrix<F>& X )
.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& T, const AbstractDistMatrix<F>& shifts, AbstractDistMatrix<F>& X )

   Overwrite the columns of `X` with the solutions to the shifted linear 
   systems.

.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const Matrix<Real>& T, const Matrix<Complex<Real>>& shifts, Matrix<Real>& XReal, Matrix<Real>& XImag )
.. cpp:function:: void MultiShiftTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, Complex<Real> alpha, const AbstractDistMatrix<Real>& T, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& XReal, AbstractDistMatrix<Real>& XImag )

   Overwrite the columns of the real and imaginary parts of `X` with the
   solutions to the shifted linear systems.

QuasiTrsm
---------
Solve for :math:`X` in the linear system

.. math::

   T^\# X = Y

or

.. math::

   X T^\# = Y

where :math:`T` is *quasi-triangular* and
:math:`A^\#` is defined to be one of :math:`\{A,A^T,A^H\}`.
The algorithm is very similar to that of :cpp:func:`Trsm`.

Note that the term *quasi-triangular* is in the context of real Schur
decompositions, which produce triangular matrices with mixes of
:math:`1 \times 1` and :math:`2 \times 2` diagonal blocks.

.. note::

   There is no corresponding BLAS routine, but it is a natural extension of
   Trsm.

.. cpp:function:: void QuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const Matrix<F>& T, Matrix<F>& X, bool checkIfSingular=false )
.. cpp:function:: void QuasiTrsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, F alpha, const AbstractDistMatrix<F>& T, AbstractDistMatrix<F>& X, bool checkIfSingular=false )

   Overwrite the columns of `X` with the solutions to the quasi-triangular
   linear systems.

   .. note::

   For best performance, `T` and `X` should be in [MC,MR] distributions.

Symm
----
Symmetric matrix-matrix multiplication: updates
:math:`C := \alpha A B + \beta C`, or 
:math:`C := \alpha B A + \beta C`, depending upon whether `side` is set to 
``LEFT`` or ``RIGHT``, respectively. In both of these types of updates, 
:math:`A` is implicitly symmetric and only the triangle specified by `uplo` 
is accessed.

.. cpp:function:: void Symm( LeftOrRight side, UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C, bool conjugate=false )
.. cpp:function:: void Symm( LeftOrRight side, UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C, bool conjugate=false )

   .. note::

      For best performance, `A`, `B`, and `C` should all be in [MC,MR]
      distributions.

Syrk
----
Symmetric rank-K update: updates
:math:`C := \alpha A A^T + \beta C`, or 
:math:`C := \alpha A^T A + \beta C`, depending upon whether `orientation` is
set to ``NORMAL`` or ``TRANSPOSE``, respectively. Only the triangle of :math:`C`
specified by the `uplo` parameter is modified.

.. cpp:function:: void Syrk( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, T beta, Matrix<T>& C )
.. cpp:function:: void Syrk( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A` and `C` should both be in [MC,MR] 
      distributions.

Please see :cpp:func:`SetLocalTrrkBlocksize\<T>` 
and :cpp:func:`LocalTrrkBlocksize\<T>` in the :ref:`blas-tuning`
section for information on tuning the distributed :cpp:func:`Syrk`.

Syr2k
-----
Symmetric rank-2K update: updates
:math:`C := \alpha (A B^T + B A^T) + \beta C`, or 
:math:`C := \alpha (A^T B + B^T A) + \beta C`, depending upon whether 
`orientation` is set to ``NORMAL`` or ``TRANSPOSE``, respectively. Only the 
triangle of :math:`C` specified by the `uplo` parameter is modified.

.. cpp:function:: void Syr2k( UpperOrLower uplo, Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Syr2k( UpperOrLower uplo, Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
      distributions.

Please see :cpp:func:`SetLocalTrr2kBlocksize\<T>` 
and :cpp:func:`LocalTrr2kBlocksize\<T>` in the 
:ref:`blas-tuning` section for information on tuning the distributed 
:cpp:func:`Syr2k`.

Trmm
----
Triangular matrix-matrix multiplication: performs
:math:`C := \alpha A^\# B`, or 
:math:`C := \alpha B A^\#`, depending upon whether `side` was chosen
to be ``LEFT`` or ``RIGHT``, respectively. Whether :math:`A` is treated as 
lower or upper triangular is determined by `uplo`, and :math:`A^\#` is defined to
be one of :math:`\{A,A^T,A^H\}` (and `diag` determines
whether :math:`A` is treated as unit-diagonal or not).

.. cpp:function:: void Trmm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, T alpha, const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Trmm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, T alpha, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

   .. note::

      For the best performance, `A` and `B` should both be in [MC,MR] 
      distributions.

Trrk
----
Triangular rank-k update: performs 
:math:`C := \alpha A^\# B^\sharp + \beta C`, where only the 
triangle of `C` specified by `uplo` is modified, and the orientations :math:`A^\#` and 
:math:`B^\sharp` are determined by `orientationOfA` and `orientationOfB`, 
respectively.

.. note::

   There is no corresponding BLAS routine, but this type of update is frequently
   encountered, even in serial. For instance, the symmetric rank-k update 
   performed during an LDL factorization is symmetric but one of the 
   two update matrices is scaled by D.

.. cpp:function:: void Trrk( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Trrk( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C )

   .. note::

      For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
      distributions.

Trr2k
-----
Triangular rank-2k update: performs 
:math:`E := \alpha ( A^\# B^\sharp + C^\Diamond D^\triangle ) + \beta E`,
where only the triangle of `E` specified by `uplo` is modified, and 
the orientation of each input matrix, e.g., :math:`A^\# \in \{A,A^T,A^H\}`, is determined 
by `orientationOfX` for each :math:`X \in \left\{A,B,C,D\right\}`.

.. note::

   There is no corresponding BLAS routine, but it is a natural generalization
   of "symmetric" and "Hermitian" updates.

.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const Matrix<T>& A, const Matrix<T>& B, const Matrix<T>& C, const Matrix<T>& D, T beta, Matrix<T>& E )
.. cpp:function:: void Trr2k( UpperOrLower uplo, Orientation orientationOfA, Orientation orientationOfB, Orientation orientationOfC, Orientation orientationOfD, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, const AbstractDistMatrix<T>& C, const AbstractDistMatrix<T>& D, T beta, AbstractDistMatrix<T>& E )

   .. note::

      For the best performance, `A`, `B`, `C`, `D`, and `E` should all be in 
      [MC,MR] distributions.

Trtrmm
------
.. note:: 

   This routine loosely corresponds with the LAPACK routines ?lauum.

Symmetric/Hermitian triangular matrix-matrix multiply: performs
:math:`L := L^T L`, :math:`L := L^H L`, :math:`U := U U^T`, or 
:math:`U := U U^H`, depending upon the choice of the `orientation` and 
`uplo` parameters. 

.. cpp:function:: void Trtrmm( Orientation orientation, UpperOrLower uplo, Matrix<T>& A )
.. cpp:function:: void Trtrmm( Orientation orientation, UpperOrLower uplo, AbstractDistMatrix<T>& A )

   .. note::

      For the best performance, `A` should be in a [MC,MR] distribution.

Trdtrmm
-------
.. note:: 

   This is a modification of Trtrmm for LDL factorizations.

Symmetric/Hermitian triangular matrix-matrix multiply (with diagonal scaling): 
performs :math:`L := L^T D^{-1} L`, :math:`L := L^H D^{-1} L`, 
:math:`U := U D^{-1} U^T`, or :math:`U := U D^{-1} U^H`, 
depending upon the choice of the `orientation` and `uplo` parameters. 
Note that :math:`L` and :math:`U` are unit-diagonal and their diagonal is 
overwritten with :math:`D`.

.. cpp:function:: void Trdtrmm( Orientation orientation, UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Trdtrmm( Orientation orientation, UpperOrLower uplo, AbstractDistMatrix<F>& A )

   .. note::

      For the best performance, `A` should be in a [MC,MR] distribution.

.. cpp:function:: void Trdtrmm( Orientation orientation, UpperOrLower uplo, Matrix<F>& A, const Matrix<F>& dSub )
.. cpp:function:: void Trdtrmm( Orientation orientation, UpperOrLower uplo, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& dSub )

   An extension to quasi-diagonal :math:`D`, where the main diagonal is stored
   over the main diagonal of `A` and the subdiagonal is given by `dSub`.

   .. note::

      For the best performance, `A` should be in a [MC,MR] distribution,
      while `dSub` should be in a [MD,STAR] distribution.

Trsm
----
Triangular solve with multiple right-hand sides: performs
:math:`C := \alpha A^{-\#} B`, or 
:math:`C := \alpha B A^{-\#}`, depending upon whether `side` was 
chosen to be ``LEFT`` or ``RIGHT``, respectively. Whether :math:`A` is treated 
as lower or upper triangular is determined by `uplo`, and :math:`A^{-\#}` 
can be :math:`A^{-1}`, :math:`A^{-T}`, or :math:`A^{-H}` (and `diag` determines
whether :math:`A` is treated as unit-diagonal or not).

.. cpp:function:: void Trsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const Matrix<F>& A, Matrix<F>& B )

.. cpp:function:: void Trsm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   .. note::

      For the best performance, `A` and `B` should both be in [MC,MR] 
      distributions.

Trstrm
------
Performs a triangular solve against a triangular matrix. Only the Left Lower 
Normal option is currently supported.

.. cpp:function:: void Trstrm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const Matrix<F>& A, Matrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void Trstrm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& X, bool checkIfSingular=true )

   .. note::

      For the best performance, `A` and `B` should both be in [MC,MR] 
      distributions.

Two-sided Trmm
--------------
Performs a two-sided triangular multiplication with multiple right-hand sides 
which preserves the symmetry of the input matrix, 
either :math:`A := L^H A L` or :math:`A := U A U^H`.

.. cpp:function:: void TwoSidedTrmm( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<T>& A, const Matrix<T>& B )
.. cpp:function:: void TwoSidedTrmm( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B )

   .. note::

      For the best performance, `A` and `B` should both be in [MC,MR] 
      distributions.


Two-sided Trsm
--------------
Performs a two-sided triangular solves with multiple right-hand sides which 
preserves the symmetry of the input matrix, 
either :math:`A := L^{-1} A L^{-H}` or :math:`A := U^{-H} A U^{-1}`.

.. cpp:function:: void TwoSidedTrsm( UpperOrLower uplo, UnitOrNonUnit diag, Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: void TwoSidedTrsm( UpperOrLower uplo, UnitOrNonUnit diag, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B )

   .. note::

      For the best performance, `A` and `B` should both be in [MC,MR] 
      distributions.
