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

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/Cholesky.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/Cholesky>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/Cholesky.cpp>`__

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void Cholesky( UpperOrLower uplo, DistMatrix<F>& A )

   Overwrite the `uplo` triangle of the HPD matrix `A` with its Cholesky factor.

.. cpp:function:: void Cholesky( UpperOrLower uplo, Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void Cholesky( UpperOrLower uplo, DistMatrix<F>& A, Matrix<int>& p )

   Performs Cholesky factorization with full (diagonal) pivoting.

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

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/HPSDCholesky.cpp>`__

.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void HPSDCholesky( UpperOrLower uplo, DistMatrix<F>& A )

   Overwrite the `uplo` triangle of the potentially singular matrix `A` with
   its Cholesky factor.

cholesky namespace
^^^^^^^^^^^^^^^^^^

.. cpp:function:: cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, DistMatrix<F>& B )

   Solve linear systems using an unpivoted Cholesky factorization.

.. cpp:function:: cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& B, Matrix<int>& p )
.. cpp:function:: cholesky::SolveAfter( UpperOrLower uplo, Orientation orientation, const DistMatrix<F>& A, DistMatrix<F>& B, DistMatrix<int,VC,STAR>& p )

   Solve linear systems using a pivoted Cholesky factorization.

:math:`LDL` factorization
-------------------------

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

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/LDL.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LDL>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/LDL.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/LDL.cpp>`__

.. cpp:function:: void LDLH( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLT( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLH( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& dSub, DistMatrix<int,VC,STAR>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )
.. cpp:function:: void LDLT( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& dSub, DistMatrix<int,VC,STAR>& p, LDLPivotType pivotType=BUNCH_KAUFMAN_A )

   Pivoted LDL factorization. The Bunch-Kaufman pivoting rules are used within
   a higher-performance blocked algorithm, whereas the Bunch-Parlett strategy
   uses an unblocked algorithm.

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

.. cpp:function:: ldl::SolveAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: ldl::SolveAfter( const DistMatrix<F>& A, DistMatrix<F>& B, bool conjugated=false )

   Solve linear systems using an unpivoted LDL factorization.

.. cpp:function:: ldl::SolveAfter( const Matrix<F>& A, const Matrix<F>& dSub, const Matrix<int>& p, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: ldl::SolveAfter( const DistMatrix<F>& A, const DistMatrix<F,MD,STAR>& dSub, const DistMatrix<int,VC,STAR>& p, DistMatrix<F>& B, bool conjugated=false )

   Solve linear systems using a pivoted LDL factorization.

:math:`LU` factorization
------------------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/LU.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LU>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/LU.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/GaussianElimination.cpp>`__

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
.. cpp:function:: void LU( DistMatrix<F>& A, DistMatrix<F,VC,STAR>& p )

   Overwrites the matrix :math:`A` with the LU decomposition of 
   :math:`PA`, where :math:`P` is represented by the pivot vector `p`.

.. cpp:function:: void LU( Matrix<F>& A, Matrix<int>& p, Matrix<int>& q )
.. cpp:function:: void LU( DistMatrix<F>& A, DistMatrix<F,VC,STAR>& p, DistMatrix<F,VC,STAR>& q )

   Overwrites the matrix :math:`A` with the LU decomposition of 
   :math:`PAQ`, where :math:`P` is represented by the pivot vector `p`, 
   and likewise for :math:`Q`.

:math:`LQ` factorization
------------------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/LQ.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/LQ>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/LQ.cpp>`__

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

:math:`QR` factorization
------------------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/QR.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/QR>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/QR.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/QR.cpp>`__

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
.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d )

   Overwrite the matrix :math:`A` with :math:`R` and the 
   Householder reflectors (and subsequent unitary diagonal matrix defined by
   the vector, `d`) representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p )
.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p )
.. cpp:function:: void QR( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,VR,STAR>& p )

   Column-pivoted QR factorization. The current implementation uses 
   Businger-Golub pivoting.

qr namespace
^^^^^^^^^^^^

.. cpp:function:: void qr::Explicit( Matrix<F>& A, bool colPiv=false )
.. cpp:function:: void qr::Explicit( DistMatrix<F>& A, bool colPiv=false )

   Overwrite :math:`A` with the orthogonal matrix from its QR factorization
   (with or without column pivoting).

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, bool colPiv=false )
.. cpp:function:: void qr::Explicit( DistMatrix<F>& A, DistMatrix<F>& R, bool colPiv=false )

   Additionally explicitly return the :math:`R` from the QR factorization.

.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const DistMatrix<F>& A, const DistMatrix<F,Ut,Vt>& t, const DistMatrix<Base<F>,Ud,Vd>& d, DistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p )
.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,VR,STAR>& p )

   Column-pivoted versions of the above routines which use the Businger/Golub 
   strategy, i.e., the pivot is chosen as the remaining column with maximum
   two norm.

.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p, int numSteps )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p, int numSteps )
.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p, int numSteps )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<Base<F>,MD,STAR>& d, DistMatrix<int,VR,STAR>& p, int numSteps )

   Same as above, but only execute a fixed number of steps of the rank-revealing
   factorization.

.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<int>& p, int maxSteps, Base<F> tol )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p, int maxSteps, Base<F> tol )
.. cpp:function:: void qr::BusingerGolub( Matrix<F>& A, Matrix<F>& t, Matrix<int>& p, int maxSteps, Base<F> tol )
.. cpp:function:: void qr::BusingerGolub( DistMatrix<F>& A, DistMatrix<F,MD,STAR>& t, DistMatrix<int,VR,STAR>& p, int maxSteps, Base<F> tol )

   Either execute `maxSteps` iterations or stop after the maximum remaining 
   column norm is less than or equal to `tol` times the maximum original column
   norm.

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

:math:`RQ` factorization
------------------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/RQ.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/elemental/lapack-like/factor/RQ>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/RQ.cpp>`__

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

Interpolative Decomposition (ID)
--------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/ID.hpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/ID.cpp>`__

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
.. cpp:function:: void ID( const DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p, DistMatrix<F,STAR,VR>& Z, int numSteps )

   `numSteps` steps of a pivoted QR factorization are used to return an 
   Interpolative Decomposition of :math:`A`.

.. cpp:function:: void ID( const Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, int maxSteps, Base<F> tol )
.. cpp:function:: void ID( const DistMatrix<F>& A, DistMatrix<int,VR,STAR>& p, DistMatrix<F,STAR,VR>& Z, int maxSteps, Base<F> tol )

   Either `maxSteps` steps of a pivoted QR factorization are used, or 
   executation stopped after the maximum remaining column norm was less than or
   equal to `tol` times the maximum original column norm.

Skeleton decomposition
----------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/include/elemental/lapack-like/factor/Skeleton.hpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/Skeleton.cpp>`__

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
.. cpp:function:: void Skeleton( const DistMatrix<F>& A, DistMatrix<int,VR,STAR>& pR, DistMatrix<int,VR,STAR>& pC, int maxSteps, Base<F> tol )

   Rather than returning :math:`A_R` and :math:`A_C`, the permutation matrices
   which implicitly define them are returned instead. At most `maxSteps` steps 
   of a pivoted QR decomposition will be used in order to generate the 
   row/column subsets, and less steps will be taken if a pivot norm is less 
   than or equal to `tolerance` times the first pivot norm.
