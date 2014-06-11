Factorizations
==============

Cholesky factorization
----------------------
It is well-known that Hermitian positive-definite (HPD) matrices can be 
decomposed into the form :math:`A = L L^H` or :math:`A = U^H U`, where 
:math:`L=U^H` is lower triangular, and Cholesky factorization provides such an 
:math:`L` (or :math:`U`) given an HPD :math:`A`. If :math:`A` is found to be 
numerically indefinite, then a :cpp:type:`NonHPDMatrixException` will be 
thrown.

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/Cholesky.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/Cholesky>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/Cholesky.cpp>`__

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Cholesky( UpperOrLower uplo, DistMatrix<F>& A )

   Overwrite the `uplo` triangle of the HPD matrix `A` with its Cholesky factor.

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void Cholesky( UpperOrLower uplo, DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p )

   Performs Cholesky factorization with full (diagonal) pivoting. On exit, the 
   vector :math:`p` consists of the nonzero column indices of the permutation 
   matrix :math:`P` such that :math:`P A P^T = L L^H = U^H U`.

.. cpp:function:: void CholeskyMod( UpperOrLower uplo, Matrix<F>& T, Base<F>& alpha, Matrix<F>& V )
.. cpp:function:: void CholeskyMod( UpperOrLower uplo, DistMatrix<F>& T, Base<F>& alpha, DistMatrix<F>& V )

   Updates the Cholesky factorization to incorporate the modification
   :math:`\alpha V V^H` to the original matrix. The current algorithm uses 
   Householder transformations for updates (:math:`\alpha \ge 0`) and 
   hyperbolic Householder transformations for downdates.

It is possible to compute the Cholesky factor of a Hermitian positive
semi-definite (HPSD) matrix through its eigenvalue decomposition, though it
is significantly more expensive than the HPD case: Let :math:`A = U \Lambda U^H`
be the eigenvalue decomposition of :math:`A`, where all entries of
:math:`\Lambda` are non-negative. Then :math:`B = U \sqrt \Lambda U^H` is the
matrix square root of :math:`A`, i.e., :math:`B B = A`, and it follows that the
QR and LQ factorizations of :math:`B` yield Cholesky factors of :math:`A`:

.. math::
   A = B B = B^H B = (Q R)^H (Q R) = R^H Q^H Q R = R^H R,

and

.. math::
   A = B B = B B^H = (L Q) (L Q)^H = L Q Q^H L^H = L L^H.

If :math:`A` is found to have eigenvalues less than
:math:`-n \epsilon \| A \|_2`, then a :cpp:type:`NonHPSDMatrixException` will
be thrown.

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/HPSDCholesky.cpp>`__

.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, DistMatrix<F>& A )

   Overwrite the `uplo` triangle of the potentially singular matrix `A` with
   its Cholesky factor.

cholesky namespace
^^^^^^^^^^^^^^^^^^

.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, DistMatrix<F>& B )

   Solve linear systems using an unpivoted Cholesky factorization.

.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B, Matrix<int>& perm )
.. cpp:function:: void cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<int,UPerm,STAR>& perm )

   Solve linear systems using a pivoted Cholesky factorization.

LDL factorization
-----------------

.. cpp:type:: enum LDLPivotType

   An enum for specifying the symmetric pivoting strategy. The current
   (not yet all supported) options include:

   * ``BUNCH_KAUFMAN_A`` 
   * ``BUNCH_KAUFMAN_C`` (not yet supported)
   * ``BUNCH_KAUFMAN_D``
   * ``BUNCH_KAUFMAN_BOUNDED`` (not yet supported)
   * ``BUNCH_PARLETT``

.. cpp:type:: LDLPivot

   .. cpp:member:: int nb
   .. cpp:member:: int from[2]

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/LDL.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LDL>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/LDL.cpp>`__

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/LDL.cpp>`__

.. cpp:function:: void LDLH( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLT( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLH( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& dSub, DistMatrix<int,UPerm,STAR>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLT( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& dSub, DistMatrix<int,UPerm,STAR>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Returns a pivoted LDL factorization, where the vector :math:`p` contains the
   column indices of the nonzero entries of the permutation matrix :math:`P` 
   such that :math:`PAP^T` equals either :math:`LDL^T` or 
   :math:`LDL^H`, where :math:`D` is quasi-diagonal. 
   The Bunch-Kaufman pivoting rules are used within a higher-performance 
   blocked algorithm, whereas the Bunch-Parlett strategy uses an unblocked 
   algorithm.

Though the Cholesky factorization is ideal for most HPD matrices, the 
unpivoted `LDL` factorizations exist as slight relaxation of the Cholesky 
factorization and compute lower-triangular (with unit diagonal) :math:`L`
and diagonal :math:`D` such that :math:`A = L D L^H` or :math:`A = L D L^T`. 
If a zero pivot is attempted, then a :cpp:type:`ZeroPivotException` will 
be thrown.

   .. warning::

      The following routines do not pivot, so please use with caution.

.. cpp:function:: void LDLH( Matrix<F>& A )
.. cpp:function:: void LDLT( Matrix<F>& A )
.. cpp:function:: void LDLH( DistMatrix<F>& A )
.. cpp:function:: void LDLT( DistMatrix<F>& A )

   Overwrite the strictly lower triangle of :math:`A` with the strictly lower 
   portion of :math:`L` (:math:`L` implicitly has ones on its diagonal) and 
   the diagonal with :math:`D`.

ldl namespace
^^^^^^^^^^^^^

.. cpp:function:: void ldl::SolveAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::SolveAfter( const DistMatrix<F>& A, DistMatrix<F>& B, bool conjugated=false )

   Solve linear systems using an unpivoted LDL factorization.

.. cpp:function:: void ldl::SolveAfter( const Matrix<F>& A, const Matrix<F>& dSub, const Matrix<int>& p, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::SolveAfter( const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& dSub, const DistMatrix<int,UPerm,STAR>& p, DistMatrix<F>& B, bool conjugated=false )

   Solve linear systems using a pivoted LDL factorization.

LU factorization
----------------

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/LU.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LU>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/LU.cpp>`__

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/GaussianElimination.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}`, an LU factorization 
(without pivoting) finds a unit lower-trapezoidal 
:math:`L \in \mathbb{F}^{m \times \mbox{min}(m,n)}` and upper-trapezoidal 
:math:`U \in \mathbb{F}^{\mbox{min}(m,n) \times n}` such that :math:`A=LU`. 
Since :math:`L` is required to have its diaganal entries set to one: the upper 
portion of :math:`A` can be overwritten with `U`, and the strictly lower 
portion of :math:`A` can be overwritten with the strictly lower portion of 
:math:`L`. If :math:`A` is found to be numerically singular, then a 
:cpp:type:`SingularMatrixException` will be thrown.

.. cpp:function:: void LU( Matrix<F>& A )
.. cpp:function:: void LU( DistMatrix<F>& A )

   Overwrites :math:`A` with its LU decomposition.

Since LU factorization without pivoting is known to be unstable for general 
matrices, it is standard practice to pivot the rows of :math:`A` during the 
factorization (this is called partial pivoting since the columns are not also 
pivoted). An LU factorization with partial pivoting therefore computes 
:math:`P`, :math:`L`, and :math:`U` such that :math:`PA=LU`, where :math:`L` 
and :math:`U` are as described above and :math:`P` is a permutation matrix.

.. cpp:function:: void LU( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void LU( DistMatrix<F>& A, DistMatrix<F,UPerm,STAR>& p )

   Overwrites the matrix :math:`A` with the LU decomposition of 
   :math:`PA`, where :math:`P` is represented by the permutation vector `p`, 
   which consists of the column indices of the nonzero entry in each row of 
   :math:`P`.

.. cpp:function:: void LU( Matrix<F>& A, Matrix<int>& p, Matrix<int>& q )
.. cpp:function:: void LU( DistMatrix<F>& A, DistMatrix<F,UPerm,STAR>& p, DistMatrix<F,UPerm,STAR>& q )

   Overwrites the matrix :math:`A` with the LU decomposition of 
   :math:`PAQ^T`, where :math:`P` and :math:`Q` are represented by the
   permutation vectors `p` and `q`, 
   which consist of the column indices of the nonzero entry in each row of 
   :math:`P` and :math:`Q`, respectively.

.. cpp:function:: void LUMod( Matrix<F>& A, Matrix<int>& p, const Matrix<F>& u, const Matrix<F>& v, bool conjugate=true, Base<F> tau=0.1 )
.. cpp:function:: void LUMod( DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p, const DistMatrix<F>& u, const DistMatrix<F>& v, bool conjugate=true, Base<F> tau=0.1 )

   Modify an existing LU factorization, :math:`A = P^T L U`, to incorporate
   the rank-one update :math:`A + u v^T` or :math:`A + u v^H`. This algorithm
   only requires a quadratic number of operations.

   .. note::

      The current implementation has only been tested for square matrices.

lu namespace
^^^^^^^^^^^^

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const DistMatrix<F>& A, DistMatrix<F>& B )

   Update :math:`B := A^{-1} B`, :math:`B := A^{-T} B`, or
   :math:`B := A^{-H} B`, where :math:`A` has been overwritten with its LU
   factors (without partial pivoting).

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<int>& p, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const DistMatrix<F>& A, const DistMatrix<int,UPerm,STAR>& p, DistMatrix<F>& B )

   HERE
   Update :math:`B := A^{-1} B`, :math:`B := A^{-T} B`, or
   :math:`B := A^{-H} B`, where :math:`A` has been overwritten with
   its LU factors with partial pivoting, which satisfy :math:`P A = L U`, where
   the permutation matrix :math:`P` is represented by the pivot vector ``p``.

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<int>& p, const Matrix<int>& q, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const DistMatrix<F>& A, const DistMatrix<int,UPerm,STAR>& p, const DistMatrix<int,UPerm,STAR>& q, DistMatrix<F>& B )

   Update :math:`B := A^{-1} B`, :math:`B := A^{-T} B`, or
   :math:`B := A^{-H} B`, where :math:`A` has been overwritten with
   its LU factors with full pivoting, which satisfy :math:`P A Q = L U`, where
   the permutation matrices :math:`P` and :math:`Q` are represented by the
   pivot vector ``p`` and ``q``, respectively.

LQ factorization
----------------

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/LQ.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LQ>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/LQ.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}`, an LQ factorization typically 
computes an implicit unitary matrix :math:`\hat Q \in \mathbb{F}^{n \times n}` 
such that :math:`\hat L \equiv A\hat Q^H` is lower trapezoidal. One can then 
form the thin factors :math:`L \in \mathbb{F}^{m \times \mbox{min}(m,n)}` and 
:math:`Q \in \mathbb{F}^{\mbox{min}(m,n) \times n}` by setting 
:math:`L` and :math:`Q` to first :math:`\mbox{min}(m,n)` columns and rows of 
:math:`\hat L` and :math:`\hat Q`, respectively. Upon completion :math:`L` is 
stored in the lower trapezoid of :math:`A` and the Householder reflectors 
(and preceding unitary diagonal matrix forcing :math:`L` to have a positive 
diagonal, defined by the vector `d`) representing :math:`\hat Q` are stored 
within the rows of the strictly upper trapezoid.

.. cpp:function:: void LQ( Matrix<F>& A )
.. cpp:function:: void LQ( DistMatrix<F>& A )
.. cpp:function:: void LQ( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void LQ( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d )

   Overwrite the matrix :math:`A` with :math:`L` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the diagonal 
   matrix which forces :math:`L` to be positive in `d`.

lq namespace
^^^^^^^^^^^^

.. cpp:function:: void lq::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void lq::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,Ut,Vt>& t, const DistMatrix<Base<F>,Ud,Vd>& d, DistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: void lq::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void lq::SolveAfter( Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, const DistMatrix<Base<F>,MD,STAR>& d, const DistMatrix<F>& B, DistMatrix<F>& X )

   Solves a set of linear systems using an existing packed LQ factorization given
   by :math:`A` and the vectors :math:`t` and :math:`d`.
   :math:`B` is the matrix of input vectors and :math:`X` is the matrix of 
   solutions.

QR factorization
----------------

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/QR.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/QR>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/QR.cpp>`__

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/QR.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}`, a QR factorization typically 
computes an implicit unitary matrix :math:`\hat Q \in \mathbb{F}^{m \times m}` 
such that :math:`\hat R \equiv \hat Q^H A` is upper trapezoidal. One can then 
form the thin factors :math:`Q \in \mathbb{F}^{m \times \mbox{min}(m,n)}` and
:math:`R \in \mathbb{F}^{\mbox{min}(m,n) \times n}` by setting 
:math:`Q` and :math:`R` to first :math:`\mbox{min}(m,n)` columns and rows of 
:math:`\hat Q` and :math:`\hat R`, respectively. Upon completion :math:`R` is 
stored in the upper trapezoid of :math:`A` and the Householder reflectors 
representing :math:`\hat Q` are stored within the columns of the strictly lower 
trapezoid (this unitary matrix is scaled from the right by a unitary diagonal
matrix with entries given by `d` so that :math:`R` has a positive diagonal).

.. cpp:function:: void QR( Matrix<F>& A )
.. cpp:function:: void QR( DistMatrix<F>& A )

   Overwrite :math:`A` with :math:`R`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d )

   Overwrite the matrix :math:`A` with both :math:`R` and the 
   Householder reflectors (and subsequent unitary diagonal matrix defined by
   the vector, `d`) representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p )

   Overwrite :math:`A` with the :math:`R` from a column-pivoted QR 
   factorization, :math:`A P = Q R`. The permutation matrix :math:`P` is 
   represented via the permutation vector :math:`p`, which contains the 
   column indices of the nonzero entry in each row of :math:`P`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,UPerm,STAR>& p )

   Overwrite :math:`A` with both the :math:`R` and (scaled) Householder 
   reflectors from a column-pivoted QR factorization.

qr namespace
^^^^^^^^^^^^

.. cpp:function:: void qr::Explicit( Matrix<F>& A, bool colPiv=false )
.. cpp:function:: void qr::Explicit( DistMatrix<F>& A, bool colPiv=false )

   Overwrite :math:`A` with the orthogonal matrix from its QR factorization
   (with or without column pivoting).

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, bool colPiv=false )
.. cpp:function:: void qr::Explicit( DistMatrix<F>& A, DistMatrix<F>& R, bool colPiv=false )

   Additionally explicitly return the :math:`R` from the QR factorization.

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, Matrix<Int>& p )
.. cpp:function:: void qr::Explicit( DistMatrix<F>& A, DistMatrix<F>& R, DistMatrix<int,UPerm,STAR>& p )

   Return representations of all matrices of the pivoted QR factorization
   (note that the pivot *vector* is returned, not the full pivot matrix).

.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,Ut,Vt>& t, const DistMatrix<Base<F>,Ud,Vd>& d, DistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p )
.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,UPerm,STAR>& p )

   Column-pivoted versions of the above routines which use the Businger/Golub 
   strategy, i.e., the pivot is chosen as the remaining column with maximum
   two norm. The return value is the number of performed iterations.

.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p, int numSteps )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p, int numSteps )
.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p, int numSteps )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,UPerm,STAR>& p, int numSteps )

   Same as above, but only execute a fixed number of steps of the rank-revealing
   factorization. The return value is the number of performed iterations.

.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p, int maxSteps, Base<F> tol )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p, int maxSteps, Base<F> tol )
.. cpp:function:: int qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<int>& p, int maxSteps, Base<F> tol )
.. cpp:function:: int qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<int,UPerm,STAR>& p, int maxSteps, Base<F> tol )

   Either execute `maxSteps` iterations or stop after the maximum remaining 
   column norm is less than or equal to `tol` times the maximum original column
   norm. The return value is the number of performed iterations.

.. cpp:function:: void qr::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void qr::SolveAfter( Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, const DistMatrix<Base<F>,MD,STAR>& d, const DistMatrix<F>& B, DistMatrix<F>& X )

   Solves a set of linear systems using an existing packed QR factorization given
   by :math:`A` and the vectors :math:`t` and :math:`d`.
   :math:`B` is the matrix of input vectors and :math:`X` is the matrix of
   solutions.

.. cpp:type:: TreeData<F>

   .. cpp:member:: Matrix<F> QR0

      Initial QR factorization

   .. cpp:member:: Matrix<F> t0

      Phases from initial QR factorization

   .. cpp:member:: Matrix<Base<F>> d0

      Signature (-1,+1) which scales the Householder matrix from the right.

   .. cpp:member:: std::vector<Matrix<F>> QRList

      Factorizations within reduction tree

   .. cpp:member:: std::vector<Matrix<F>> tList

      Phases within reduction tree

   .. cpp:member:: std::vector<Matrix<Base<F>>> dList

      Signatures within reduction tree

.. cpp:function:: qr::TreeData<F> qr::TS( const DistMatrix<F,U,STAR>& A )

   Forms an implicit tall-skinny QR decomposition.

.. cpp:function:: void qr::ExplicitTS( DistMatrix<F,U,STAR>& A, DistMatrix<F,STAR,STAR>& R )

   Forms an explicit QR decomposition using a tall-skinny algorithm: 
   A is overwritten with Q.

qr::ts namespace
________________

.. cpp:function:: DistMatrix<F,STAR,STAR> qr::ts::FormR( const DistMatrix<F,U,STAR>& A, const qr::TreeData<F>& treeData )

   Return the R from the QR decomposition.

.. cpp:function:: void qr::ts::FormQ( DistMatrix<F,U,STAR>& A, qr::TreeData<F>& treeData )

   Overwrite A with the Q from the QR decomposition.

Generalized QR factorization
----------------------------

`Implementation <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/GQR.hpp>`__

The *generalized QR factorization* of a pair of matrices :math:`(A,B)` is 
analogous to a QR factorization of :math:`B^{-1} A` but does not require that
:math:`B` is square or invertible: 
unitary matrices :math:`Q` and :math:`Z`, and (right) upper-triangular matrices 
:math:`R` and :math:`T`, are computed such that

.. math::

   A = Q R


and

.. math::

   B = Q T Z.

Thus, if :math:`B` was square and invertible, then the QR factorization of 
:math:`B^{-1} A` would be given by :math:`Z^H (T^{-1} R)`.

.. cpp:function:: void GQR( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GQR( DistMatrix<F>& A, DistMatrix<F>& B )

   Overwrite :math:`A` with :math:`R` and :math:`B` with :math:`T`.

.. cpp:function:: void GQR( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GQR( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& tA, DistMatrix<Base<F>,MD,STAR>& dA, DistMatrix<F>& B, DistMatrix<F,MD,STAR>& tB, DistMatrix<Base<F>,MD,STAR>& dB )

   Overwrite :math:`A` with both :math:`R` and the (scaled) Householder vectors 
   which, along with the scalings :math:`tA` and sign changes :math:`dA`, define
   :math:`Q`. Likewise, :math:`B` is overwritten with both :math:`T` and the 
   (scaled) Householder vectors which define :math:`Z`.

RQ factorization
----------------

`Main header file <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/RQ.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/RQ>`__

`Test driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/tests/lapack-like/RQ.cpp>`__

Just like an LQ factorization, but the orthogonalization process starts from the bottom row and produces a 
much sparser triangular factor when the matrix is wider than it is tall.

.. cpp:function:: void RQ( Matrix<F>& A )
.. cpp:function:: void RQ( DistMatrix<F>& A )
.. cpp:function:: void RQ( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void RQ( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d )

   Overwrite the matrix :math:`A` with :math:`R` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the unitary diagonal
   matrix which forces :math:`R` to be positive is defined by the vector `d`.

rq namespace
^^^^^^^^^^^^

.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,Ut,Vt>& t, const DistMatrix<Base<F>,Ud,Vd>& d, DistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: void rq::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void rq::SolveAfter( Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& t, const DistMatrix<Base<F>,MD,STAR>& d, const DistMatrix<F>& B, DistMatrix<F>& X )

   Solves a set of linear systems using an existing packed RQ factorization given
   by :math:`A` and the vectors :math:`t` and :math:`d`.
   :math:`B` is the matrix of input vectors and :math:`X` is the matrix of
   solutions.

Generalized RQ factorization
----------------------------

`Implementation <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/GRQ.hpp>`__

The *generalized RQ factorization* of a pair of matrices :math:`(A,B)` is 
analogous to an RQ factorization of :math:`A B^{-1}` but does not require that
:math:`B` is square or invertible:
unitary matrices :math:`Q` and :math:`Z`, and (right) upper-triangular matrices
:math:`R` and :math:`T`, are computed such that

.. math::

   A = R Q


and

.. math::

   B = Z T Q.

Thus, is :math:`B` was square and invertible, then the RQ factorization of 
:math:`A B^{-1}` would be given by :math:`(R T^{-1}) Z^H`.

.. cpp:function:: void GRQ( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GRQ( DistMatrix<F>& A, DistMatrix<F>& B )

   Overwrite :math:`A` with :math:`R` and :math:`B` with :math:`T`.

.. cpp:function:: void GRQ( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GRQ( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& tA, DistMatrix<Base<F>,MD,STAR>& dA, DistMatrix<F>& B, DistMatrix<F,MD,STAR>& tB, DistMatrix<Base<F>,MD,STAR>& dB )

   Overwrite :math:`A` with both :math:`R` and the (scaled) Householder vectors
   which, along with the scalings :math:`tA` and sign changes :math:`dA`, define
   :math:`Q`. Likewise, :math:`B` is overwritten with both :math:`T` and the
   (scaled) Householder vectors which define :math:`Z`.

Interpolative Decomposition (ID)
--------------------------------

`Implementation <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/ID.hpp>`__

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/ID.cpp>`__

Interpolative Decompositions (ID's) are closely related to pivoted QR 
factorizations and are useful for representing (approximately) low-rank 
matrices in terms of linear combinations of a few of their columns, i.e., 

.. math::

   A P = \hat{A} \begin{pmatrix} I & Z \end{pmatrix},

where :math:`P` is a permutation matrix, :math:`\hat{A}` is a small set of 
columns of :math:`A`, and :math:`Z` is an interpolation matrix responsible for
representing the remaining columns in terms of the selected columns of 
:math:`A`.

.. cpp:function:: void ID( const Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, int numSteps )
.. cpp:function:: void ID( const DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p, DistMatrix<F,STAR,VR>& Z, int numSteps )

   `numSteps` steps of a pivoted QR factorization are used to return an 
   Interpolative Decomposition of :math:`A`.

.. cpp:function:: void ID( const Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, int maxSteps, Base<F> tol )
.. cpp:function:: void ID( const DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& p, DistMatrix<F,STAR,VR>& Z, int maxSteps, Base<F> tol )

   Either `maxSteps` steps of a pivoted QR factorization are used, or 
   executation stopped after the maximum remaining column norm was less than or
   equal to `tol` times the maximum original column norm.

Skeleton decomposition
----------------------

`Implementation <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/include/elemental/lapack-like/factor/Skeleton.hpp>`__

`Example driver <https://github.com/elemental/Elemental/tree/3cef6bb7a8103db4648055378cdd7174b19b9e96/examples/lapack-like/Skeleton.cpp>`__

Skeleton decompositions are essentially two-sided interpolative decompositions,
but the terminology is unfortunately extremely contested. We follow the 
convention that a skeleton decomposition is an approximation

.. math::

   A \approx A_C Z A_R,

where :math:`A_C` is a (small) selection of columns of :math:`A`, 
:math:`A_R` is a (small) selection of rows of :math:`A`, and :math:`Z` is a 
(small) square matrix. When :math:`Z` is allowed to be rectangular, it is more
common to call this a CUR decomposition.

.. cpp:function:: void Skeleton( const Matrix<F>& A, Matrix<int>& pR, Matrix<int>& pC, Matrix<F>& Z, int maxSteps, Base<F> tol )
.. cpp:function:: void Skeleton( const DistMatrix<F>& A, DistMatrix<int,UPerm,STAR>& pR, DistMatrix<int,UPerm,STAR>& pC, int maxSteps, Base<F> tol )

   Rather than returning :math:`A_R` and :math:`A_C`, the permutation matrices
   which implicitly define them are returned instead. At most `maxSteps` steps 
   of a pivoted QR decomposition will be used in order to generate the 
   row/column subsets, and less steps will be taken if a pivot norm is less 
   than or equal to `tolerance` times the first pivot norm.
