Interpolative Decomposition (ID)
================================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/dense/ID.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/ID.cpp>`__

Interpolative Decompositions (ID's) are closely related to pivoted QR 
factorizations and are useful for representing (approximately) low-rank 
matrices in terms of linear combinations of a few of their columns, i.e., 

.. math::

   A P = \hat{A} \begin{pmatrix} I & Z \end{pmatrix},

where :math:`P` is a permutation matrix, :math:`\hat{A}` is a small set of 
columns of :math:`A`, and :math:`Z` is an interpolation matrix responsible for
representing the remaining columns in terms of the selected columns of 
:math:`A`.

The following routines use column-pivoted QR factorizations to return an 
Interpolative Decomposition.

C++ API
-------

.. cpp:function:: void ID( const Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void ID( const AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )

   The matrix :math:`A` is not modified.

.. cpp:function:: void ID( Matrix<F>& A, Matrix<int>& p, Matrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>(), bool canOverwrite=false )
.. cpp:function:: void ID( AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>(), bool canOverwrite=false )

   The matrix :math:`A` is optionally allowed to be modified.

C API
-----

.. c:function:: ElError ElID_s( ElMatrix_s A, ElMatrix_i p, ElMatrix_s Z, ElQRCtrl_s ctrl, bool canOverwrite )
.. c:function:: ElError ElID_d( ElMatrix_d A, ElMatrix_i p, ElMatrix_d Z, ElQRCtrl_d ctrl, bool canOverwrite )
.. c:function:: ElError ElID_c( ElMatrix_c A, ElMatrix_i p, ElMatrix_c Z, ElQRCtrl_s ctrl, bool canOverwrite )
.. c:function:: ElError ElID_z( ElMatrix_z A, ElMatrix_i p, ElMatrix_z Z, ElQRCtrl_d ctrl, bool canOverwrite )
.. c:function:: ElError ElIDDist_s( ElDistMatrix_s A, ElDistMatrix_i p, ElDistMatrix_s Z, ElQRCtrl_s ctrl, bool canOverwrite )
.. c:function:: ElError ElIDDist_d( ElDistMatrix_d A, ElDistMatrix_i p, ElDistMatrix_d Z, ElQRCtrl_d ctrl, bool canOverwrite )
.. c:function:: ElError ElIDDist_c( ElDistMatrix_c A, ElDistMatrix_i p, ElDistMatrix_c Z, ElQRCtrl_s ctrl, bool canOverwrite )
.. c:function:: ElError ElIDDist_z( ElDistMatrix_z A, ElDistMatrix_i p, ElDistMatrix_z Z, ElQRCtrl_d ctrl, bool canOverwrite )

   The matrix :math:`A` is optionally allowed to be modified.
