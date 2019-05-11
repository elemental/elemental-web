Equality-constrained Least Squares
==================================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/euclidean_min/LSE.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LSE.cpp>`__

The following routines support the solution of dense and sparse-direct 
instances of the *Equality-constrained Least Squares* problem

.. math::

   \min_X \| A X - C \|_F \;\;\; \text{subject to } B X = D.


Dense algorithm
---------------
For dense instances of the problem, a Generalized RQ factorization can be
employed as long as :math:`A` is :math:`m \times n`, :math:`B` is 
:math:`p \times n`, and :math:`p \le n \le m+p`. It is assumed that :math:`B` 
has full row rank, :math:`p`, and :math:`\begin{pmatrix} A \\ B \end{pmatrix}` 
has full column rank, :math:`n`.

A Generalized RQ factorization of :math:`(B,A)`,

.. math::

    B = T Q = \begin{pmatrix} 0 & T_{1,2} \end{pmatrix} Q,\quad  A = Z \begin{pmatrix} R_{1,1} & R_{1,2} \\ 0 & R_{2,2} \end{pmatrix} Q,

where :math:`Q` and :math:`Z` are unitary and :math:`R` and :math:`T` are 
upper-trapezoidal, allows us to re-express the constraint

.. math::

   T Q x = d,

as

.. math::

   \begin{pmatrix} 0 & T_{1,2} \end{pmatrix} \begin{pmatrix} y_1 \\ y_2 \end{pmatrix} = d,

where :math:`y = Q x`, which only requires the solution of the upper-triangular 
system

.. math::

   T_{1,2} y_2 = d.

The objective can be rewritten as

.. math::

   \| A x - c \|_2 = \| Z^H A x - Z^H c \|_2 = \| R Q x - Z^H c \|_2

which, defining :math:`g = Z^H c`, can be partitioned as

.. math::

   \begin{pmatrix} R_{1,1} & R_{1,2} \\ 0 & R_{2,2} \end{pmatrix} \begin{pmatrix} y_1 \\ y_2 \end{pmatrix}  - \begin{pmatrix} g_1 \\ g_2 \end{pmatrix} = \begin{pmatrix} R_{1,1} y_1 + R_{1,2} y_2 - g_1 \\ R_{2,2} y_2 - g_2 \end{pmatrix}.

Since :math:`y_2` is fixed by the constraint, the norm is minimized by setting 
the top term to zero, which involves solving the upper-triangular system

.. math::

   R_{1,1} y_1 = g_1 - R_{1,2} y_2.

On exit of the internal dense routine, :math:`A` and :math:`B` are overwritten 
with their implicit Generalized RQ factorization of :math:`(B,A)`, and, 
optionally, :math:`C` is overwritten with the rotated residual matrix

.. math::

   Z^H (A X - C) = (R Q X - Z^H C) = \begin{pmatrix} 0 \\ R_{2,2} Y_2 - G_1 \end{pmatrix},

where :math:`R_{2,2}` is an upper-trapezoidal (not necessarily triangular) 
matrix. *Note that essentially the same scheme is used in LAPACK's {S,D,C,Z}GGLSE*.

Sparse-direct algorithm
-----------------------
For sparse instances of the LSE problem, the symmetric quasi-semidefinite
augmented system

.. math::

   \begin{pmatrix} 0 & A^H & B^H \\ A & -\alpha I & 0 \\ B & 0 & 0 \end{pmatrix} \begin{pmatrix} X \\ -R/\alpha \\ Y/\alpha \end{pmatrix} = \begin{pmatrix} 0 \\ C \\ D \end{pmatrix}

is formed, equilibrated, and then a priori regularization is added in order
to make the system sufficiently quasi-definite. A Cholesky-like factorization
of this regularized system is then used as a preconditioner for FGMRES(k).

Python API
----------
.. py:function:: LSE(A,B,C,D[,ctrl=None])

C++ API
-------

.. cpp:function:: void LSE( const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& C, const Matrix<F>& D, Matrix<F>& X )

.. cpp:function:: void LSE( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& C, const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X )

.. cpp:function:: void LSE( const SparseMatrix<F>& A, const SparseMatrix<F>& B, const Matrix<F>& C, const Matrix<F>& D, Matrix<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void LSE( const DistSparseMatrix<F>& A, const DistSparseMatrix<F>& B, const DistMultiVec<F>& C, const DistMultiVec<F>& D, DistMultiVec<F>& X, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

Dense versions which overwrite their input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void lse::Overwrite( Matrix<F>& A, Matrix<F>& B, Matrix<F>& C, Matrix<F>& D, Matrix<F>& X, bool computeResidual=false )

.. cpp:function:: void lse::Overwrite( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X, bool computeResidual=false )

C API
-----

Standard interface
^^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElLSE_s( ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s C, ElConstMatrix_s D, ElMatrix_s X )
.. c:function:: ElError ElLSEDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s C, ElConstDistMatrix_s D, ElDistMatrix_s X )
.. c:function:: ElError ElLSESparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s B, ElConstMatrix_s C, ElConstMatrix_s D, ElMatrix_s X )
.. c:function:: ElError ElLSEDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s B, ElConstDistMultiVec_s C, ElConstDistMultiVec_s D, ElDistMultiVec_s X )

Double-precision
""""""""""""""""
.. c:function:: ElError ElLSE_d( ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d C, ElConstMatrix_d D, ElMatrix_d X )
.. c:function:: ElError ElLSEDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d C, ElConstDistMatrix_d D, ElDistMatrix_d X )
.. c:function:: ElError ElLSESparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d B, ElConstMatrix_d C, ElConstMatrix_d D, ElMatrix_d X )
.. c:function:: ElError ElLSEDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d B, ElConstDistMultiVec_d C, ElConstDistMultiVec_d D, ElDistMultiVec_d X )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLSE_c( ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c C, ElConstMatrix_c D, ElMatrix_c X )
.. c:function:: ElError ElLSEDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c C, ElConstDistMatrix_c D, ElDistMatrix_c X )
.. c:function:: ElError ElLSESparse_c( ElConstSparseMatrix_c A, ElConstSparseMatrix_c B, ElConstMatrix_c C, ElConstMatrix_c D, ElMatrix_c X )
.. c:function:: ElError ElLSEDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistSparseMatrix_c B, ElConstDistMultiVec_c C, ElConstDistMultiVec_c D, ElDistMultiVec_c X )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLSE_z( ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z C, ElConstMatrix_z D, ElMatrix_z X )
.. c:function:: ElError ElLSEDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z C, ElConstDistMatrix_z D, ElDistMatrix_z X )
.. c:function:: ElError ElLSESparse_z( ElConstSparseMatrix_z A, ElConstSparseMatrix_z B, ElConstMatrix_z C, ElConstMatrix_z D, ElMatrix_z X )
.. c:function:: ElError ElLSEDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistSparseMatrix_z B, ElConstDistMultiVec_z C, ElConstDistMultiVec_z D, ElDistMultiVec_z X )

Expert versions
^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElLSEXSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s B, ElConstMatrix_s C, ElConstMatrix_s D, ElMatrix_s X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLSEXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s B, ElConstDistMultiVec_s C, ElConstDistMultiVec_s D, ElDistMultiVec_s X, ElLeastSquaresCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElLSEXSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d B, ElConstMatrix_d C, ElConstMatrix_d D, ElMatrix_d X, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLSEXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d B, ElConstDistMultiVec_d C, ElConstDistMultiVec_d D, ElDistMultiVec_d X, ElLeastSquaresCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLSEXSparse_c( ElConstSparseMatrix_c A, ElConstSparseMatrix_c B, ElConstMatrix_c C, ElConstMatrix_c D, ElMatrix_c X, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElLSEXDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistSparseMatrix_c B, ElConstDistMultiVec_c C, ElConstDistMultiVec_c D, ElDistMultiVec_c X, ElLeastSquaresCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElLSEXSparse_z( ElConstSparseMatrix_z A, ElConstSparseMatrix_z B, ElConstMatrix_z C, ElConstMatrix_z D, ElMatrix_z X, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElLSEXDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistSparseMatrix_z B, ElConstDistMultiVec_z C, ElConstDistMultiVec_z D, ElDistMultiVec_z X, ElLeastSquaresCtrl_d ctrl )

