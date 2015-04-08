Ridge regression
================
*Ridge regression* is a special case of *Tikhonov regularization*
where the regularization matrix, :math:`G`, is of the form :math:`G= \gamma I`.
When the linear system is either square or overdetermined, one solves the
*Regularized Least Squares* problem

.. math::

   \min_X \| A X - B \|_F^2 + \| \gamma X \|_F^2,

whereas, when the system is underdetermined, one solves a *Regularized 
Minimum Length* problem

.. math::
   :nowrap:

   \begin{eqnarray*}
   && \min_{X,S} \| X \|_F^2 + \| S \|_F^2 \\
   && \text{s.t. } A X + \gamma S = B.
   \end{eqnarray*}

Just as with Tikhonov regularization, Elemental in fact supports replacing 
:math:`A` in the above equations with :math:`A`, :math:`A^T`, or :math:`A^H`.

Python API
----------
.. py:function:: Ridge(A,B,alpha[,alg=RIDGE_CHOLESKY])

C++ API
-------

.. cpp:type:: RidgeAlg

   An enum that can take on the values:

   * ``RIDGE_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``RIDGE_QR``: Run a QR-based algorithm
   * ``RIDGE_SVD``: Run an SVD-based algorithm

.. cpp:function:: void Ridge( Orientation orientation, const Matrix<F>& A, const Matrix<F>& B, Base<F> gamma, Matrix<F>& X, RidgeAlg alg=RIDGE_CHOLESKY )

.. cpp:function:: void Ridge( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, Base<F> gamma, AbstractDistMatrix<F>& X, RidgeAlg alg=RIDGE_CHOLESKY )

.. cpp:function:: void Ridge( Orientation orientation, const SparseMatrix<F>& A, const Matrix<F>& B, Base<F> gamma, Matrix<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void Ridge( Orientation orientation, const DistSparseMatrix<F>& A, const DistMultiVec<F>& B, Base<F> gamma, DistMultiVec<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

C API
-----

.. c:type:: ElRidgeAlg

   An enum that can take on the values:

   * ``EL_RIDGE_CHOLESKY``: Run a less accurate, but often faster, Cholesky-based algorithm
   * ``EL_RIDGE_QR``: Run a QR-based algorithm
   * ``EL_RIDGE_SVD``: Run an SVD-based algorithm

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRidge_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s B, float gamma, ElMatrix_s X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float gamma, ElDistMatrix_s X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeSparse_s( ElOrientation orientation, ElConstSparseMatrix_s A, ElConstMatrix_s B, float gamma, ElMatrix_s X )
.. c:function:: ElError ElRidgeDistSparse_s( ElOrientation orientation, ElConstDistSparseMatrix_s A, ElConstDistMultiVec_s B, float gamma, ElDistMultiVec_s X )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRidge_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d B, double gamma, ElMatrix_d X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double gamma, ElDistMatrix_d X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeSparse_d( ElOrientation orientation, ElConstSparseMatrix_d A, ElConstMatrix_d B, double gamma, ElMatrix_d X )
.. c:function:: ElError ElRidgeDistSparse_d( ElOrientation orientation, ElConstDistSparseMatrix_d A, ElConstDistMultiVec_d B, double gamma, ElDistMultiVec_d X )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRidge_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c B, float gamma, ElMatrix_c X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c B, float gamma, ElDistMatrix_c X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeSparse_c( ElOrientation orientation, ElConstSparseMatrix_c A, ElConstMatrix_c B, float gamma, ElMatrix_c X )
.. c:function:: ElError ElRidgeDistSparse_c( ElOrientation orientation, ElConstDistSparseMatrix_c A, ElConstDistMultiVec_c B, float gamma, ElDistMultiVec_c X )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRidge_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z B, double gamma, ElMatrix_z X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z B, double gamma, ElDistMatrix_z X, ElRidgeAlg alg )
.. c:function:: ElError ElRidgeSparse_z( ElOrientation orientation, ElConstSparseMatrix_z A, ElConstMatrix_z B, double gamma, ElMatrix_z X )
.. c:function:: ElError ElRidgeDistSparse_z( ElOrientation orientation, ElConstDistSparseMatrix_z A, ElConstDistMultiVec_z B, double gamma, ElDistMultiVec_z X )

