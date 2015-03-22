Least Squares
=============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/euclidean_min/LeastSquares.cpp>`__

A *Least Squares* problem involves the solution of 

.. math::

   \min_X \| A X - B \|_F^2

and is applicable for overdetermined (as well as square) linear system. Whenever
the system is underdetermined, it is more appropriate to solve a
*Minimum Length* problem,

.. math::
   :nowrap:

   \begin{eqnarray*}
   && \min_X \| X \|_F^2 \\
   && \text{s.t. } A X  = B.
   \end{eqnarray*}

Elemental solves dense instances of these problems using QR and LQ 
factorizations, respectively, whereas sparse instances are solved via 
applying a priori regularization to the symmetric quasi-semidefinite 
*augmented systems*

.. math::

   \begin{pmatrix} \alpha I & A \\ A^H & 0 \end{pmatrix} \begin{pmatrix} R/\alpha \\ X \end{pmatrix} = \begin{pmatrix} B \\ 0 \end{pmatrix}

and

.. math::

   \begin{pmatrix} \alpha I & A^H \\ A & 0 \end{pmatrix} \begin{pmatrix} X \\ Y \end{pmatrix} = \begin{pmatrix} 0 \\ B \end{pmatrix},

where :math:`\alpha` should ideally be chosen near :math:`\sigma_{\text{min}}(A)` in order to minimize the condition number (relative to both the augmented system and the solution for :math:`X` [Bjorck92]_ [Bjorck96]_).
The augmented systems are of interest because they have nearby quasi-definite 
[Vanderbei95]_ matrices which  be factored with a Cholesky-like sparse-direct 
solver (and can therefore be effectively preconditioned) [Saunders96]_.

Lastly, Elemental in fact allows for slight generalizations of the above
problems: :math:`A^T` or :math:`A^H` may also be used in the above equations
rather than only :math:`A`.

C++ API
-------

.. cpp:function:: void LeastSquares( Orientation orientation, Matrix<F>& A, const Matrix<F>& B, Matrix<F>& X )

.. cpp:function:: void LeastSquares( Orientation orientation, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

.. cpp:function:: void LeastSquares( Orientation orientation, const SparseMatrix<F>& A, const Matrix<F>& B, Matrix<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void LeastSquares( Orientation orientation, const DistSparseMatrix<F>& A, const DistMultiVec<F>& B, DistMultiVec<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

C API
-----

.. c:function:: ElError ElLeastSquares_s( ElOrientation orientation, ElMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElLeastSquares_d( ElOrientation orientation, ElMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElLeastSquares_c( ElOrientation orientation, ElMatrix_c A, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElLeastSquares_z( ElOrientation orientation, ElMatrix_z A, ElConstMatrix_z B, ElMatrix_z X )

.. c:function:: ElError ElLeastSquaresDist_s( ElOrientation orientation, ElDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElLeastSquaresDist_d( ElOrientation orientation, ElDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElLeastSquaresDist_c( ElOrientation orientation, ElDistMatrix_c A, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElLeastSquaresDist_z( ElOrientation orientation, ElDistMatrix_z A, ElConstDistMatrix_z B, ElDistMatrix_z X )

.. c:function:: ElError ElLeastSquaresSparse_s( ElOrientation orientation, ElSparseMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElLeastSquaresSparse_d( ElOrientation orientation, ElSparseMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElLeastSquaresSparse_c( ElOrientation orientation, ElSparseMatrix_c A, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElLeastSquaresSparse_z( ElOrientation orientation, ElSparseMatrix_z A, ElConstMatrix_z B, ElMatrix_z X )

.. c:function:: ElError ElLeastSquaresDistSparse_s( ElOrientation orientation, ElDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElDistMultiVec_s X )
.. c:function:: ElError ElLeastSquaresDistSparse_d( ElOrientation orientation, ElDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElDistMultiVec_d X )
.. c:function:: ElError ElLeastSquaresDistSparse_c( ElOrientation orientation, ElDistSparseMatrix_c A, ElConstDistMultiVec_c B, ElDistMultiVec_c X )
.. c:function:: ElError ElLeastSquaresDistSparse_z( ElOrientation orientation, ElDistSparseMatrix_z A, ElConstDistMultiVec_z B, ElDistMultiVec_z X )

Expert versions
^^^^^^^^^^^^^^^

.. c:function:: ElError ElLeastSquaresXSparse_s( ElOrientation orientation, ElSparseMatrix_s A, ElConstMatrix_s B, ElMatrix_s X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLeastSquaresXSparse_d( ElOrientation orientation, ElSparseMatrix_d A, ElConstMatrix_d B, ElMatrix_d X, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLeastSquaresXSparse_c( ElOrientation orientation, ElSparseMatrix_c A, ElConstMatrix_c B, ElMatrix_c X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLeastSquaresXSparse_z( ElOrientation orientation, ElSparseMatrix_z A, ElConstMatrix_z B, ElMatrix_z X, ElLeastSquaresCtrl_d ctrl )

.. c:function:: ElError ElLeastSquaresXDistSparse_s( ElOrientation orientation, ElDistSparseMatrix_s A, ElConstDistMultiVec_s B, ElDistMultiVec_s X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLeastSquaresXDistSparse_d( ElOrientation orientation, ElDistSparseMatrix_d A, ElConstDistMultiVec_d B, ElDistMultiVec_d X, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLeastSquaresXDistSparse_c( ElOrientation orientation, ElDistSparseMatrix_c A, ElConstDistMultiVec_c B, ElDistMultiVec_c X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLeastSquaresXDistSparse_z( ElOrientation orientation, ElDistSparseMatrix_z A, ElConstDistMultiVec_z B, ElDistMultiVec_z X, ElLeastSquaresCtrl_d ctrl )

Python API
----------
.. py:function:: LeastSquares(A,B,orient=NORMAL,ctrl=None)

.. [Bjorck92] Ake Bjorck, *Pivoting and stability in the augmented system method*. In D.F. Griffiths and G.A. Watson (eds.), Proc. 14th Dundee Conf., Pitman Research Notes in Math., pp. 1--16, 1992.

.. [Bjorck96] Ake Bjorck, *Numerical methods for least squares problems*, SIAM, Philadelphia, 1996. `DOI <http://epubs.siam.org/doi/book/10.1137/1.9781611971484>`__

.. [Saunders96] Michael Saunders, *Chapter 8, Cholesky-based Methods for Sparse Least Squares: The Benefits of Regularization*, in L. Adams and J.L. Nazareth (eds.), Linear and Nonlinear Conjugate Gradient-Related Methods, SIAM, Philadelphia, pp. 92--100, 1996. `Currently available here <http://web.stanford.edu/group/SOL/papers/seattleproc.pdf>`__

.. [Vanderbei95] R.J. Vanderbei, *Symmetric quasi-definite matrices*, SIAM J. Optim., 5(1), pp. 100--113, 1995. `Preprint available here <http://www.princeton.edu/~rvdb/tex/myPapers/sqd6.pdf>`__
