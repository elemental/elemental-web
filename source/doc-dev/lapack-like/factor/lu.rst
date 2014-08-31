LU factorization
================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/LU.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/factor/LU>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/LU.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/GaussianElimination.cpp>`__

LU with partial pivoting
------------------------
Since LU factorization without pivoting is known to be unstable for general 
matrices, it is standard practice to pivot the rows of :math:`A` during the 
factorization (this is called partial pivoting since the columns are not also 
pivoted). An LU factorization with partial pivoting therefore computes 
:math:`P`, :math:`L`, and :math:`U` such that :math:`PA=LU`, where :math:`L` 
and :math:`U` are as described above and :math:`P` is a permutation matrix.

Overwrites the matrix :math:`A` with the LU decomposition of 
:math:`PA`, where :math:`P` is represented by the permutation vector `p`, 
which consists of the column indices of the nonzero entry in each row of 
:math:`P`.

Factorization
^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void LU( Matrix<F>& A, Matrix<int>& p )
.. cpp:function:: void LU( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& p )

C API
"""""

.. c:function:: ElError ElLUPartialPiv_s( ElMatrix_s A, ElMatrix_i p )
.. c:function:: ElError ElLUPartialPiv_d( ElMatrix_d A, ElMatrix_i p )
.. c:function:: ElError ElLUPartialPiv_c( ElMatrix_c A, ElMatrix_i p )
.. c:function:: ElError ElLUPartialPiv_z( ElMatrix_z A, ElMatrix_i p )

.. c:function:: ElError ElLUPartialPivDist_s( ElDistMatrix_s A, ElDistMatrix_i p )
.. c:function:: ElError ElLUPartialPivDist_d( ElDistMatrix_d A, ElDistMatrix_i p )
.. c:function:: ElError ElLUPartialPivDist_c( ElDistMatrix_c A, ElDistMatrix_i p )
.. c:function:: ElError ElLUPartialPivDist_z( ElDistMatrix_z A, ElDistMatrix_i p )

Solving linear systems with the factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<int>& p, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& B )

C API
"""""

.. c:function:: ElError ElSolveAfterLUPartialPiv_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_i p, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLUPartialPiv_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_i p, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLUPartialPiv_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_i p, ElMatrix_c B )
.. c:function:: ElError ElSolveAfterLUPartialPiv_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_i p, ElMatrix_z B )

.. c:function:: ElError ElSolveAfterLUPartialPivDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_i p, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLUPartialPivDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_i p, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLUPartialPivDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_i p, ElDistMatrix_c B )
.. c:function:: ElError ElSolveAfterLUPartialPivDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_i p, ElDistMatrix_z B )

LU with full pivoting
---------------------
Overwrites the matrix :math:`A` with the LU decomposition of 
:math:`PAQ^T`, where :math:`P` and :math:`Q` are represented by the
permutation vectors `p` and `q`, 
which consist of the column indices of the nonzero entry in each row of 
:math:`P` and :math:`Q`, respectively.

Factorization
^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void LU( Matrix<F>& A, Matrix<int>& p, Matrix<int>& q )
.. cpp:function:: void LU( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& p, AbstractDistMatrix<F>& q )

C API
"""""

.. c:function:: ElError ElLUFullPiv_s( ElMatrix_s A, ElMatrix_i p, ElMatrix_i q )
.. c:function:: ElError ElLUFullPiv_d( ElMatrix_d A, ElMatrix_i p, ElMatrix_i q )
.. c:function:: ElError ElLUFullPiv_c( ElMatrix_c A, ElMatrix_i p, ElMatrix_i q )
.. c:function:: ElError ElLUFullPiv_z( ElMatrix_z A, ElMatrix_i p, ElMatrix_i q )

.. c:function:: ElError ElLUFullPivDist_s( ElDistMatrix_s A, ElDistMatrix_i p, ElDistMatrix_i q )
.. c:function:: ElError ElLUFullPivDist_d( ElDistMatrix_d A, ElDistMatrix_i p, ElDistMatrix_i q )
.. c:function:: ElError ElLUFullPivDist_c( ElDistMatrix_c A, ElDistMatrix_i p, ElDistMatrix_i q )
.. c:function:: ElError ElLUFullPivDist_z( ElDistMatrix_z A, ElDistMatrix_i p, ElDistMatrix_i q )

Solving linear systems with the factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<int>& p, const Matrix<int>& q, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<int>& p, const AbstractDistMatrix<int>& q, AbstractDistMatrix<F>& B )

C API
"""""

.. c:function:: ElError ElSolveAfterLUFullPiv_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_i p, ElConstMatrix_i q, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLUFullPiv_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_i p, ElConstMatrix_i q, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLUFullPiv_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_i p, ElConstMatrix_i q, ElMatrix_c B )
.. c:function:: ElError ElSolveAfterLUFullPiv_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_i p, ElConstMatrix_i q, ElMatrix_z B )

.. c:function:: ElError ElSolveAfterLUFullPivDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_i p, ElConstDistMatrix_i q, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLUFullPivDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_i p, ElConstDistMatrix_i q, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLUFullPivDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_i p, ElConstDistMatrix_i q, ElDistMatrix_c B )
.. c:function:: ElError ElSolveAfterLUFullPivDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_i p, ElConstDistMatrix_i q, ElDistMatrix_z B )

LU with no pivoting
-------------------

Given :math:`A \in \mathbb{F}^{m \times n}`, an LU factorization 
(without pivoting) attempts to find a unit lower-trapezoidal 
:math:`L \in \mathbb{F}^{m \times \mbox{min}(m,n)}` and upper-trapezoidal 
:math:`U \in \mathbb{F}^{\mbox{min}(m,n) \times n}` such that :math:`A=LU`. 
Since :math:`L` is required to have its diaganal entries set to one: the upper 
portion of :math:`A` can be overwritten with `U`, and the strictly lower 
portion of :math:`A` can be overwritten with the strictly lower portion of 
:math:`L`. If a numerically zero diagonal entry of :math:`U` is created, then a 
:cpp:type:`SingularMatrixException` will be thrown.

.. note::

   It might be appropriate to switch this routine to a ``ZeroPivotException``,
   as it is strange to refer to non-square matrices as singular.

Factorization
^^^^^^^^^^^^^

The following routines overwrite :math:`A` with its LU decomposition.

C++ API
"""""""

.. cpp:function:: void LU( Matrix<F>& A )
.. cpp:function:: void LU( AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElLU_s( ElMatrix_s A )
.. c:function:: ElError ElLU_d( ElMatrix_d A )
.. c:function:: ElError ElLU_c( ElMatrix_c A )
.. c:function:: ElError ElLU_z( ElMatrix_z A )

.. c:function:: ElError ElLUDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElLUDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElLUDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLUDist_z( ElDistMatrix_z A )

Solving linear systems with the factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void lu::SolveAfter( Orientation orientation, const Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void lu::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

C API
"""""

.. c:function:: ElError ElSolveAfterLU_s( ElOrientation orientation, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLU_d( ElOrientation orientation, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLU_c( ElOrientation orientation, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElSolveAfterLU_z( ElOrientation orientation, ElConstMatrix_z A, ElMatrix_z B )

.. c:function:: ElError ElSolveAfterLUDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLUDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLUDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElSolveAfterLUDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElDistMatrix_z B )

Rank-one modification to a factorization
----------------------------------------
Modify an existing LU factorization, :math:`A = P^T L U`, to incorporate
the rank-one update :math:`A + u v^T` or :math:`A + u v^H`. This algorithm
only requires a quadratic number of operations.

.. note::

   The current implementation has only been tested for square matrices.

C++ API
^^^^^^^

.. cpp:function:: void LUMod( Matrix<F>& A, Matrix<int>& p, const Matrix<F>& u, const Matrix<F>& v, bool conjugate=true, Base<F> tau=0.1 )
.. cpp:function:: void LUMod( AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& p, const AbstractDistMatrix<F>& u, const AbstractDistMatrix<F>& v, bool conjugate=true, Base<F> tau=0.1 )

C API
^^^^^

.. c:function:: ElError ElLUMod_s( ElMatrix_s A, ElMatrix_i p, ElConstMatrix_s u, ElConstMatrix_s v, float tau )
.. c:function:: ElError ElLUMod_d( ElMatrix_d A, ElMatrix_i p, ElConstMatrix_d u, ElConstMatrix_d v, double tau )
.. c:function:: ElError ElLUMod_c( ElMatrix_c A, ElMatrix_i p, ElConstMatrix_c u, ElConstMatrix_c v, float tau )
.. c:function:: ElError ElLUMod_z( ElMatrix_z A, ElMatrix_i p, ElConstMatrix_z u, ElConstMatrix_z v, double tau )

.. c:function:: ElError ElLUModDist_s( ElDistMatrix_s A, ElDistMatrix_i p, ElConstDistMatrix_s u, ElConstDistMatrix_s v, float tau )
.. c:function:: ElError ElLUModDist_d( ElDistMatrix_d A, ElDistMatrix_i p, ElConstDistMatrix_d u, ElConstDistMatrix_d v, double tau )
.. c:function:: ElError ElLUModDist_c( ElDistMatrix_c A, ElDistMatrix_i p, ElConstDistMatrix_c u, ElConstDistMatrix_c v, float tau )
.. c:function:: ElError ElLUModDist_z( ElDistMatrix_z A, ElDistMatrix_i p, ElConstDistMatrix_z u, ElConstDistMatrix_z v, double tau )

