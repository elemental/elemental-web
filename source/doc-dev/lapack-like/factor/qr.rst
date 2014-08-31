QR factorization
----------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/QR.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/factor/QR>`__

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
.. cpp:function:: void QR( AbstractDistMatrix<F>& A )

   Overwrite :math:`A` with :math:`R`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void QR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d )

   Overwrite the matrix :math:`A` with both :math:`R` and the 
   Householder reflectors (and subsequent unitary diagonal matrix defined by
   the vector, `d`) representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void QR( AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )

   Overwrite :math:`A` with the :math:`R` from a column-pivoted QR 
   factorization, :math:`A P = Q R`. The permutation matrix :math:`P` is 
   represented via the permutation vector :math:`p`, which contains the 
   column indices of the nonzero entry in each row of :math:`P`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p )
.. cpp:function:: void QR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<int>& p, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )

   Overwrite :math:`A` with both the :math:`R` and (scaled) Householder 
   reflectors from a column-pivoted QR factorization.

Algorithmic options
^^^^^^^^^^^^^^^^^^^

.. cpp:type:: QRCtrl<Real>

   .. cpp:member:: bool boundRank

   .. cpp:member:: int maxRank

   .. cpp:member:: bool adaptive

   .. cpp:member:: Real tol

   .. cpp:member:: bool alwaysRecomputeNorms

   .. cpp:function:: QRCtrl()

      Initializes ``boundRank=false``, ``maxRank=0``, ``adaptive=false``,
      ``tol=0``, and ``alwaysRecomputeNorms=false``.

qr namespace
^^^^^^^^^^^^

.. cpp:function:: void qr::Explicit( Matrix<F>& A, bool colPiv=false )
.. cpp:function:: void qr::Explicit( AbstractDistMatrix<F>& A, bool colPiv=false )

   Overwrite :math:`A` with the orthogonal matrix from its QR factorization
   (with or without column pivoting).

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, bool colPiv=false )
.. cpp:function:: void qr::Explicit( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R, bool colPiv=false )

   Additionally explicitly return the :math:`R` from the QR factorization.

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, Matrix<Int>& p )
.. cpp:function:: void qr::Explicit( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R, AbstractDistMatrix<int>& p )

   Return representations of all matrices of the pivoted QR factorization
   (note that the pivot *vector* is returned, not the full pivot matrix).

.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: void qr::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void qr::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

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

.. cpp:function:: qr::TreeData<F> qr::TS( const AbstractDistMatrix<F>& A )

   Forms an implicit tall-skinny QR decomposition.

.. cpp:function:: void qr::ExplicitTS( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R )

   Forms an explicit QR decomposition using a tall-skinny algorithm: 
   A is overwritten with Q.

qr::ts namespace
________________

.. cpp:function:: DistMatrix<F,STAR,STAR> qr::ts::FormR( const AbstractDistMatrix<F>& A, const qr::TreeData<F>& treeData )

   Return the R from the QR decomposition.

.. cpp:function:: void qr::ts::FormQ( AbstractDistMatrix<F>& A, qr::TreeData<F>& treeData )

   Overwrite A with the Q from the QR decomposition.


