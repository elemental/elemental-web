QR factorization
================

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

Factorization
-------------

C++ API
^^^^^^^

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void QR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d )

   Overwrite the matrix :math:`A` with both :math:`R` and the 
   Householder reflectors (and subsequent unitary diagonal matrix defined by
   the vector, `d`) representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t`.

.. cpp:function:: void QR( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d, Matrix<int>& p, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void QR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<int>& p, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )

   Overwrite :math:`A` with both the :math:`R` and (scaled) Householder 
   reflectors from a column-pivoted QR factorization and additionally return
   the permutation vector, `p`.

.. cpp:function:: void qr::ExplicitTriang( Matrix<F>& A, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void qr::ExplicitTriang( AbstractDistMatrix<F>& A, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )

   Overwrite :math:`A` with :math:`R`.

.. cpp:function:: void qr::ExplicitUnitary( Matrix<F>& A, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void qr::ExplicitUnitary( AbstractDistMatrix<F>& A, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )

   Overwrite :math:`A` with the orthogonal matrix from its QR factorization
   (with or without column pivoting).

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void qr::Explicit( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )

   Explicitly return both :math:`Q` and :math:`R` from the QR factorization.

.. cpp:function:: void qr::Explicit( Matrix<F>& A, Matrix<F>& R, Matrix<Int>& P, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void qr::Explicit( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R, AbstractDistMatrix<int>& P, const QRCtrl<Base<F>>& ctrl=QRCtrl<Base<F>>() )

   Return representations of all matrices of the pivoted QR factorization.
   Note that column pivoting is performed regardless of the value of 
   ``qrCtrl.colPiv``.

.. cpp:function:: void qr::Cholesky( Matrix<F>& A, Matrix<F>& R )
.. cpp:function:: void qr::Cholesky( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R )

   Attempt to perform a QR factorization of a tall-skinny matrix using 
   Cholesky factorization.

.. cpp:function:: qr::TreeData<F> qr::TS( const AbstractDistMatrix<F>& A )

   Forms an implicit tall-skinny QR decomposition.

.. cpp:function:: void qr::ExplicitTS( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& R )

   Forms an explicit QR decomposition using a tall-skinny algorithm: 
   A is overwritten with Q.

.. cpp:function:: DistMatrix<F,STAR,STAR> qr::ts::FormR( const AbstractDistMatrix<F>& A, const qr::TreeData<F>& treeData )

   Return the R from the QR decomposition.

.. cpp:function:: void qr::ts::FormQ( AbstractDistMatrix<F>& A, qr::TreeData<F>& treeData )

   Overwrite A with the Q from the QR decomposition.

.. cpp:type:: QRCtrl<Real>

   .. cpp:member:: bool colPiv

   .. cpp:member:: bool boundRank

   .. cpp:member:: Int maxRank

   .. cpp:member:: bool adaptive

   .. cpp:member:: Real tol

   .. cpp:member:: bool alwaysRecomputeNorms

   .. cpp:function:: QRCtrl()

      Initializes ``colPiv=false``, ``boundRank=false``, ``maxRank=0``, 
      ``adaptive=false``, ``tol=0``, and ``alwaysRecomputeNorms=false``.

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

C API
^^^^^

.. c:function:: ElError ElQR_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d )
.. c:function:: ElError ElQR_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d )
.. c:function:: ElError ElQR_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d )
.. c:function:: ElError ElQR_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d )
.. c:function:: ElError ElQRDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d )
.. c:function:: ElError ElQRDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d )
.. c:function:: ElError ElQRDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d )
.. c:function:: ElError ElQRDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d )

   Return the packed QR factorization.

.. c:function:: ElError ElQRColPiv_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d, ElMatrix_i p )
.. c:function:: ElError ElQRColPiv_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d, ElMatrix_i p )
.. c:function:: ElError ElQRColPiv_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d, ElMatrix_i p )
.. c:function:: ElError ElQRColPiv_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d, ElMatrix_i p )
.. c:function:: ElError ElQRColPivDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d, ElDistMatrix_i p )
.. c:function:: ElError ElQRColPivDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d, ElDistMatrix_i p )
.. c:function:: ElError ElQRColPivDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d, ElDistMatrix_i p )
.. c:function:: ElError ElQRColPivDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d, ElDistMatrix_i p )

   Return the packed pivoted QR factorization.

.. c:function:: ElError ElQRColPivX_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d, ElMatrix_i p, ElQRCtrl_s ctrl )
.. c:function:: ElError ElQRColPivX_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d, ElMatrix_i p, ElQRCtrl_d ctrl )
.. c:function:: ElError ElQRColPivX_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d, ElMatrix_i p, ElQRCtrl_s ctrl )
.. c:function:: ElError ElQRColPivX_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d, ElMatrix_i p, ElQRCtrl_d ctrl )
.. c:function:: ElError ElQRColPivXDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d, ElDistMatrix_i p, ElQRCtrl_s ctrl )
.. c:function:: ElError ElQRColPivXDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d, ElDistMatrix_i p, ElQRCtrl_d ctrl )
.. c:function:: ElError ElQRColPivXDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d, ElDistMatrix_i p, ElQRCtrl_s ctrl )
.. c:function:: ElError ElQRColPivXDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d, ElDistMatrix_i p, ElQRCtrl_d ctrl )

   Return the packed QR factorization (expert version).

.. c:function:: ElError ElQRExplicit_s( ElMatrix_s A, ElMatrix_s R )
.. c:function:: ElError ElQRExplicit_d( ElMatrix_d A, ElMatrix_d R )
.. c:function:: ElError ElQRExplicit_c( ElMatrix_c A, ElMatrix_c R )
.. c:function:: ElError ElQRExplicit_z( ElMatrix_z A, ElMatrix_z R )
.. c:function:: ElError ElQRExplicitDist_s( ElDistMatrix_s A, ElDistMatrix_s R )
.. c:function:: ElError ElQRExplicitDist_d( ElDistMatrix_d A, ElDistMatrix_d R )
.. c:function:: ElError ElQRExplicitDist_c( ElDistMatrix_c A, ElDistMatrix_c R )
.. c:function:: ElError ElQRExplicitDist_z( ElDistMatrix_z A, ElDistMatrix_z R )

   Return the explicit QR factorization (replace `A` with `Q` and return `R`).

.. c:function:: ElError ElQRExplicitColPiv_s( ElMatrix_s A, ElMatrix_s R, ElMatrix_i P )
.. c:function:: ElError ElQRExplicitColPiv_d( ElMatrix_d A, ElMatrix_d R, ElMatrix_i P )
.. c:function:: ElError ElQRExplicitColPiv_c( ElMatrix_c A, ElMatrix_c R, ElMatrix_i P )
.. c:function:: ElError ElQRExplicitColPiv_z( ElMatrix_z A, ElMatrix_z R, ElMatrix_i P )
.. c:function:: ElError ElQRExplicitColPivDist_s( ElDistMatrix_s A, ElDistMatrix_s R, ElDistMatrix_i P )
.. c:function:: ElError ElQRExplicitColPivDist_d( ElDistMatrix_d A, ElDistMatrix_d R, ElDistMatrix_i P )
.. c:function:: ElError ElQRExplicitColPivDist_c( ElDistMatrix_c A, ElDistMatrix_c R, ElDistMatrix_i P )
.. c:function:: ElError ElQRExplicitColPivDist_z( ElDistMatrix_z A, ElDistMatrix_z R, ElDistMatrix_i P )

   Return the explicit QR factorization with column pivoting
   (replace `A` with `Q` and return `R` and `P`).

.. c:function:: ElError ElQRExplicitTriang_s( ElMatrix_s A )
.. c:function:: ElError ElQRExplicitTriang_d( ElMatrix_d A )
.. c:function:: ElError ElQRExplicitTriang_c( ElMatrix_c A )
.. c:function:: ElError ElQRExplicitTriang_z( ElMatrix_z A )
.. c:function:: ElError ElQRExplicitTriangDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElQRExplicitTriangDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElQRExplicitTriangDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElQRExplicitTriangDist_z( ElDistMatrix_z A )

   Return the triangular factor from QR with no pivoting

.. note::

   An expert wrapper which supports column-pivoting is needed.

.. c:function:: ElError ElQRExplicitUnitary_s( ElMatrix_s A )
.. c:function:: ElError ElQRExplicitUnitary_d( ElMatrix_d A )
.. c:function:: ElError ElQRExplicitUnitary_c( ElMatrix_c A )
.. c:function:: ElError ElQRExplicitUnitary_z( ElMatrix_z A )
.. c:function:: ElError ElQRExplicitUnitaryDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElQRExplicitUnitaryDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElQRExplicitUnitaryDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElQRExplicitUnitaryDist_z( ElDistMatrix_z A )

   Return the unitary factor from QR with no pivoting

.. note::

   An expert wrapper which supports column-pivoting is needed.

.. c:function:: ElError ElCholeskyQR_s( ElMatrix_s A, ElMatrix_s R )
.. c:function:: ElError ElCholeskyQR_d( ElMatrix_d A, ElMatrix_d R )
.. c:function:: ElError ElCholeskyQR_c( ElMatrix_c A, ElMatrix_c R )
.. c:function:: ElError ElCholeskyQR_z( ElMatrix_z A, ElMatrix_z R )
.. c:function:: ElError ElCholeskyQRDist_s( ElDistMatrix_s A, ElDistMatrix_s R )
.. c:function:: ElError ElCholeskyQRDist_d( ElDistMatrix_d A, ElDistMatrix_d R )
.. c:function:: ElError ElCholeskyQRDist_c( ElDistMatrix_c A, ElDistMatrix_c R )
.. c:function:: ElError ElCholeskyQRDist_z( ElDistMatrix_z A, ElDistMatrix_z R )

   Attempt to perform a Cholesky-based QR factorization of a tall-skinny matrix.

Apply the factorization to vectors
----------------------------------
Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
`A`, `t`, and `d` from either the left or the right to :math:`B`.

C++ API
^^^^^^^

.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void qr::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<F>& B )

C API
^^^^^

.. c:function:: ElError ElApplyQAfterQR_s( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElMatrix_s B )
.. c:function:: ElError ElApplyQAfterQR_d( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterQR_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterQR_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterQRDist_s( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElDistMatrix_s B )
.. c:function:: ElError ElApplyQAfterQRDist_d( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElDistMatrix_d B )
.. c:function:: ElError ElApplyQAfterQRDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElDistMatrix_c B )
.. c:function:: ElError ElApplyQAfterQRDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElDistMatrix_z B )

Solve linear systems with the factorization
-------------------------------------------
Solves a set of linear systems using an existing packed QR factorization 
given by :math:`A` and the vectors :math:`t` and :math:`d`.
:math:`B` is the matrix of input vectors and :math:`X` is the matrix of
solutions.

C++ API
^^^^^^^

.. cpp:function:: void qr::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void qr::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

C API
^^^^^

.. c:function:: ElError ElSolveAfterQR_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElSolveAfterQR_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElSolveAfterQR_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElSolveAfterQR_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElConstMatrix_z B, ElMatrix_z X )
.. c:function:: ElError ElSolveAfterQRDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElSolveAfterQRDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElSolveAfterQRDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElSolveAfterQRDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElConstDistMatrix_z B, ElDistMatrix_z X )
