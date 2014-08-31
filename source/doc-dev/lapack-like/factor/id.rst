Interpolative Decomposition (ID)
--------------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/ID.cpp>`__

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

.. cpp:function:: void ID( const Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void ID( const AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )

   Use column-pivoted QR factorizations to return an Interpolative 
   Decomposition of :math:`A`. The matrix :math:`A` is not modified.

.. cpp:function:: void ID( Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>(), bool canOverwrite=false )
.. cpp:function:: void ID( AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>(), bool canOverwrite=false )

   Use column-pivoted QR factorizations to return an Interpolative 
   Decomposition of :math:`A`. The matrix :math:`A` is optionally allowed to
   be modified.
