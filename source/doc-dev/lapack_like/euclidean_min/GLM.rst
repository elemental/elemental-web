General (Gauss-Markov) Linear Model
===================================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/euclidean_min/GLM.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/GLM.cpp>`__

The following routines implement solvers for dense and sparse-direct instances
of the *General Linear Model*,

.. math::

   \min_{X,Y} \| Y \|_F \;\;\; \text{subject to } A X + B Y = D.

Dense algorithm
---------------
For dense instances of the problem, where :math:`A` is :math:`m \times n` and 
:math:`B` is :math:`m \times p`, we assume that :math:`n \le m \le n+p` as well
as that :math:`A` has full column rank, :math:`n`, and 
:math:`\begin{pmatrix} A & B \end{pmatrix}` has full row rank, :math:`m`.

A Generalized QR factorization of (A,B),

.. math::

   A = Q R = Q \begin{pmatrix} R_{1,1} \\ 0 \end{pmatrix},\quad B = Q T Z = Q \begin{pmatrix} T_{1,1} & T_{1,2} \\ 0 & T_{2,2} \end{pmatrix} Z,

where :math:`Q` and :math:`Z` are unitary and :math:`R` and :math:`T` are 
upper-trapezoidal, allows us to re-express the constraint as 

.. math::

   Q^H d = \begin{pmatrix} R11 \\ 0 \end{pmatrix} x + \begin{pmatrix} T_{1,1} & T_{1,2} \\ 0 & T_{2,2} \end{pmatrix}  (Z y).

which is re-written as

.. math::

   \begin{pmatrix} g_1 \\ g_2 \end{pmatrix} = \begin{pmatrix} R_{1,1} x + T_{1,1} c_1 + T_{1,2} c_2 \\ T_{2,2} c_2 \end{pmatrix}.

Since :math:`\| c \|_2 = \| Z y \|_2 = \| y \|_2` is to be minimized, and 
:math:`c_2` is fixed, our only freedom is in the choice of :math:`c_1`, which 
we set to zero. Then all that is left is to solve

.. math::

   R_{1,1} x = g_1 - T_{1,2} c_2

for :math:`x`. *Note that essentially the same scheme is used in LAPACK's {S,D,C,Z}GGGLM*.

Sparse-direct algorithm
-----------------------
For sparse instances of the GLM problem, the symmetric quasi-semidefinite
augmented system

.. math::

   \begin{pmatrix} 0 & A & B \\ A^H & 0 & 0 \\ B^H & 0 & -\alpha I \end{pmatrix} \begin{pmatrix} Z \\ X/\alpha \\ Y/\alpha \end{pmatrix} = \begin{pmatrix} D/\alpha \\ 0 \\ 0 \end{pmatrix}

is formed, equilibrated, and then a priori regularization is added in order
to make the system sufficiently quasi-definite. A Cholesky-like factorization
of this regularized system is then used as a preconditioner for FGMRES(k).

Python API
----------
.. py:function:: GLM(A,B,D[,ctrl=None])

C++ API
-------

.. cpp:function:: void GLM( const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& D, Matrix<F>& X, Matrix<F>& Y )

.. cpp:function:: void GLM( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X, AbstractDistMatrix<F>& Y )

.. cpp:function:: void GLM( const SparseMatrix<F>& A, const SparseMatrix<F>& B, const Matrix<F>& D, Matrix<F>& X, Matrix<F>& Y, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

.. cpp:function:: void GLM( const DistSparseMatrix<F>& A, const DistSparseMatrix<F>& B, const DistMultiVec<F>& D, DistMultiVec<F>& X, DistMultiVec<F>& Y, const LeastSquaresCtrl<Base<F>>& ctrl=LeastSquaresCtrl<Base<F>>() )

Dense versions which overwrite their input
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void glm::Overwrite( Matrix<F>& A, Matrix<F>& B, Matrix<F>& D, Matrix<F>& Y )

.. cpp:function:: void glm::Overwrite( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& Y )

C API
-----

Standard interface
^^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElGLM_s( ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s D, ElMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElGLMDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s D, ElDistMatrix_s X, ElDistMatrix_s Y )
.. c:function:: ElError ElGLMSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s B, ElConstMatrix_s D, ElMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElGLMDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s B, ElConstDistMultiVec_s D, ElDistMultiVec_s X, ElDistMultiVec_s Y )

Double-precision
""""""""""""""""
.. c:function:: ElError ElGLM_d( ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d D, ElMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElGLMDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d D, ElDistMatrix_d X, ElDistMatrix_d Y )
.. c:function:: ElError ElGLMSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d B, ElConstMatrix_d D, ElMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElGLMDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d B, ElConstDistMultiVec_d D, ElDistMultiVec_d X, ElDistMultiVec_d Y )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGLM_c( ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c D, ElMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElGLMDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c D, ElDistMatrix_c X, ElDistMatrix_c Y )
.. c:function:: ElError ElGLMSparse_c( ElConstSparseMatrix_c A, ElConstSparseMatrix_c B, ElConstMatrix_c D, ElMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElGLMDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistSparseMatrix_c B, ElConstDistMultiVec_c D, ElDistMultiVec_c X, ElDistMultiVec_c Y )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGLM_z( ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z D, ElMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElGLMDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z D, ElDistMatrix_z X, ElDistMatrix_z Y )
.. c:function:: ElError ElGLMSparse_z( ElConstSparseMatrix_z A, ElConstSparseMatrix_z B, ElConstMatrix_z D, ElMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElGLMDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistSparseMatrix_z B, ElConstDistMultiVec_z D, ElDistMultiVec_z X, ElDistMultiVec_z Y )

Expert versions
^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElGLMXSparse_s( ElConstSparseMatrix_s A, ElConstSparseMatrix_s B, ElConstMatrix_s D, ElMatrix_s X, ElMatrix_s Y, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElGLMXDistSparse_s( ElConstDistSparseMatrix_s A, ElConstDistSparseMatrix_s B, ElConstDistMultiVec_s D, ElDistMultiVec_s X, ElDistMultiVec_s Y, ElLeastSquaresCtrl_s ctrl )

Double-precision
""""""""""""""""
.. c:function:: ElError ElGLMXSparse_d( ElConstSparseMatrix_d A, ElConstSparseMatrix_d B, ElConstMatrix_d D, ElMatrix_d X, ElMatrix_d Y, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElGLMXDistSparse_d( ElConstDistSparseMatrix_d A, ElConstDistSparseMatrix_d B, ElConstDistMultiVec_d D, ElDistMultiVec_d X, ElDistMultiVec_d Y, ElLeastSquaresCtrl_d ctrl )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGLMXSparse_c( ElConstSparseMatrix_c A, ElConstSparseMatrix_c B, ElConstMatrix_c D, ElMatrix_c X, ElMatrix_c Y, ElLeastSquaresCtrl_s ctrl )
.. c:function:: ElError ElGLMXDistSparse_c( ElConstDistSparseMatrix_c A, ElConstDistSparseMatrix_c B, ElConstDistMultiVec_c D, ElDistMultiVec_c X, ElDistMultiVec_c Y, ElLeastSquaresCtrl_s ctrl )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGLMXSparse_z( ElConstSparseMatrix_z A, ElConstSparseMatrix_z B, ElConstMatrix_z D, ElMatrix_z X, ElMatrix_z Y, ElLeastSquaresCtrl_d ctrl )
.. c:function:: ElError ElGLMXDistSparse_z( ElConstDistSparseMatrix_z A, ElConstDistSparseMatrix_z B, ElConstDistMultiVec_z D, ElDistMultiVec_z X, ElDistMultiVec_z Y, ElLeastSquaresCtrl_d ctrl )

