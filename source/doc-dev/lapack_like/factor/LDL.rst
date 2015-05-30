LDL factorization
=================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/dense/LDL.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack_like/factor/dense/LDL>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__

Symmetric pivoting
------------------
The following routines return a pivoted LDL factorization, where the vector 
:math:`p` contains the column indices of the nonzero entries of the permutation
matrix :math:`P` such that :math:`PAP^T` equals either :math:`LDL^T` or 
:math:`LDL^H`, where :math:`D` is quasi-diagonal. 
The Bunch-Kaufman pivoting rules are used within a higher-performance 
blocked algorithm, whereas the Bunch-Parlett strategy uses an unblocked, but 
typically more accurate, algorithm.

Factorization
^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:enum:: LDLPivotType

   For specifying the symmetric pivoting strategy. The current
   (not yet all supported) options include:

   .. cpp:enumerator:: BUNCH_KAUFMAN_A

   .. cpp:enumerator:: BUNCH_KAUFMAN_C

      Not yet supported

   .. cpp:enumerator:: BUNCH_KAUFMAN_D

   .. cpp:enumerator:: BUNCH_KAUFMAN_BOUNDED

      Not yet supported

   .. cpp:enumerator:: BUNCH_PARLETT

   .. cpp:enumerator:: LDL_WITHOUT_PIVOTING

.. cpp:function:: Real LDLPivotConstant<Real>(LDLPivotType pivotType)

   Maps various LDL pivotings schemes to their optimal threshold constant.

.. cpp:class:: LDLPivotCtrl<Real>

   .. cpp:member:: LDLPivotType pivotType

      The type of pivoting to perform (by default, ``BUNCH_KAUFMAN_A``)

   .. cpp:member:: Real gamma

      Pivot tolerance (by default, set to ``LDLPivotConstant<Real>(pivotType)``)

   .. cpp:function:: LDLPivotCtrl(LDLPivotType piv=BUNCH_KAUFMAN_A)

.. cpp:class:: LDLPivot

   .. cpp:member:: Int nb

      Whether the pivot is 1x1 or 2x2.

   .. cpp:member:: Int from[2]

      The source indices of the row or rows to swap with for the 1x1 or 2x2
      pivot.

.. cpp:function:: void LDL( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )
.. cpp:function:: void LDL( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& dSub, AbstractDistMatrix<int>& p, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

C API
"""""

.. c:type:: ElLDLPivotType

   An enum for specifying the symmetric pivoting strategy. The current
   (not yet all supported) options include:

   * ``EL_BUNCH_KAUFMAN_A`` 
   * ``EL_BUNCH_KAUFMAN_C`` (not yet supported)
   * ``EL_BUNCH_KAUFMAN_D``
   * ``EL_BUNCH_KAUFMAN_BOUNDED`` (not yet supported)
   * ``EL_BUNCH_PARLETT``

.. c:type:: ElLDLPivotCtrl_s

   .. c:member:: ElLDLPivotType pivotType

   .. c:member:: float gamma

.. c:type:: ElLDLPivotCtrl_d

   .. c:member:: ElLDLPivotType pivotType

   .. c:member:: double gamma

.. c:type:: ElLDLPivot

   .. c:member:: Int nb

      Whether the pivot is 1x1 or 2x2.

   .. c:member:: Int from[2]

      The source indices of the row or rows to swap with for the 1x1 or 2x2
      pivot.

.. c:function:: ElError ElLDLPiv_s( ElMatrix_s A, ElMatrix_s dSub, ElMatrix_i p )
.. c:function:: ElError ElLDLPiv_d( ElMatrix_d A, ElMatrix_d dSub, ElMatrix_i p )
.. c:function:: ElError ElLDLPiv_c( ElMatrix_c A, ElMatrix_c dSub, ElMatrix_i p, bool conjugate )
.. c:function:: ElError ElLDLPiv_z( ElMatrix_z A, ElMatrix_z dSub, ElMatrix_i p, bool conjugate )

.. c:function:: ElError ElLDLPivDist_s( ElDistMatrix_s A, ElDistMatrix_s dSub, ElDistMatrix_i p )
.. c:function:: ElError ElLDLPivDist_d( ElDistMatrix_d A, ElDistMatrix_d dSub, ElDistMatrix_i p )
.. c:function:: ElError ElLDLPivDist_c( ElDistMatrix_c A, ElDistMatrix_c dSub, ElDistMatrix_i p, bool conjugate )
.. c:function:: ElError ElLDLPivDist_z( ElDistMatrix_z A, ElDistMatrix_z dSub, ElDistMatrix_i p, bool conjugate )

**TODO:: Document expert versions**

Python API
""""""""""

**TODO: Document**

Solving linear systems after factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void ldl::SolveAfter( const Matrix<F>& A, const Matrix<F>& dSub, const Matrix<int>& p, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::SolveAfter( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& dSub, const AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
"""""

.. c:function:: ElError ElSolveAfterLDLPiv_s( ElConstMatrix_s A, ElConstMatrix_s dSub, ElConstMatrix_i p, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLDLPiv_d( ElConstMatrix_d A, ElConstMatrix_d dSub, ElConstMatrix_i p, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLDLPiv_c( ElConstMatrix_c A, ElConstMatrix_c dSub, ElConstMatrix_i p, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDLPiv_z( ElConstMatrix_z A, ElConstMatrix_z dSub, ElConstMatrix_i p, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElSolveAfterLDLPivDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s dSub, ElConstDistMatrix_i p, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLDLPivDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d dSub, ElConstDistMatrix_i p, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLDLPivDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c dSub, ElConstDistMatrix_i p, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDLPivDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z dSub, ElConstDistMatrix_i p, ElDistMatrix_z B, bool conjugate )

Python API
""""""""""

**TODO: Document**

Multiply vectors after factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void ldl::MultiplyAfter( const Matrix<F>& A, const Matrix<F>& dSub, const Matrix<int>& p, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::MultiplyAfter( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& dSub, const AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
"""""

.. c:function:: ElError ElMultiplyAfterLDLPiv_s( ElConstMatrix_s A, ElConstMatrix_s dSub, ElConstMatrix_i p, ElMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLPiv_d( ElConstMatrix_d A, ElConstMatrix_d dSub, ElConstMatrix_i p, ElMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLPiv_c( ElConstMatrix_c A, ElConstMatrix_c dSub, ElConstMatrix_i p, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLPiv_z( ElConstMatrix_z A, ElConstMatrix_z dSub, ElConstMatrix_i p, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElMultiplyAfterLDLPivDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s dSub, ElConstDistMatrix_i p, ElDistMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d dSub, ElConstDistMatrix_i p, ElDistMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c dSub, ElConstDistMatrix_i p, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z dSub, ElConstDistMatrix_i p, ElDistMatrix_z B, bool conjugate )

Computing inertia after factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: InertiaType ldl::Inertia( const Matrix<Base<F>>& d, const Matrix<F>& dSub )
.. cpp:function:: InertiaType ldl::Inertia( const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& dSub )

C API
^^^^^

.. c:function:: ElError ElInertiaAfterLDL_s( ElConstMatrix_s d, ElConstMatrix_s dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_d( ElConstMatrix_d d, ElConstMatrix_d dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_c( ElConstMatrix_s d, ElConstMatrix_c dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_z( ElConstMatrix_d d, ElConstMatrix_z dSub, ElInertiaType* inertia )

.. c:function:: ElError ElInertiaAfterLDLDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElInertiaType* inertia )

No pivoting
-----------
Though Cholesky factorization is ideal for HPD matrices, unpivoted `LDL` 
factorization naturally applies to a slightly larger, but harder to define, 
class of matrices. Upon successful completion of the factorization,
a lower-triangular (with unit diagonal) :math:`L` and diagonal matrix :math:`D`,
such that :math:`A = L D L^H` or :math:`A = L D L^T`, will be returned in the 
lower triangle of :math:`A`.
If a zero pivot is attempted, then a :cpp:type:`ZeroPivotException` will 
be thrown.

Factorization
^^^^^^^^^^^^^

.. warning::

   Please use the following routines with caution, as pivoting should be
   employed in most cases.

C++ API
"""""""

.. cpp:function:: void LDLT( Matrix<F>& A )
.. cpp:function:: void LDLT( AbstractDistMatrix<F>& A )

.. cpp:function:: void LDLH( Matrix<F>& A )
.. cpp:function:: void LDLH( AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElLDLT_s( ElMatrix_s A )
.. c:function:: ElError ElLDLT_d( ElMatrix_d A )
.. c:function:: ElError ElLDLT_c( ElMatrix_c A )
.. c:function:: ElError ElLDLT_z( ElMatrix_z A )

.. c:function:: ElError ElLDLTDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElLDLTDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElLDLTDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLDLTDist_z( ElDistMatrix_z A )

.. c:function:: ElError ElLDLH_c( ElMatrix_c A )
.. c:function:: ElError ElLDLH_z( ElMatrix_z A )

.. c:function:: ElError ElLDLHDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLDLHDist_z( ElDistMatrix_z A )

Solve linear systems after factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void ldl::SolveAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::SolveAfter( const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
"""""

.. c:function:: ElError ElSolveAfterLDL_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLDL_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLDL_c( ElConstMatrix_c A, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDL_z( ElConstMatrix_z A, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElSolveAfterLDLDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLDLDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLDLDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDLDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B, bool conjugate )

Multiply vectors after factorization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void ldl::MultiplyAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::MultiplyAfter( const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
^^^^^

.. c:function:: ElError ElMultiplyAfterLDL_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDL_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDL_c( ElConstMatrix_c A, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDL_z( ElConstMatrix_z A, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElMultiplyAfterLDLDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B, bool conjugate )
