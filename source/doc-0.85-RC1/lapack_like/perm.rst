Permutations
============

Permutation vectors
-------------------
In order to represent arbitrary permutations, Elemental recently switched from
LAPACK-style pivot sequence representations to general permutation vectors, 
where entry `i` of the *permutation* *vector* `p` contains the column index of
the nonzero entry in row `i` of the corresponding permutation matrix.

PermuteCols
^^^^^^^^^^^

.. cpp:function:: void PermuteCols( Matrix<T>& A, const Matrix<int>& p )
.. cpp:function:: void PermuteCols( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p )

.. cpp:function:: void PermuteCols( Matrix<T>& A, const Matrix<int>& p, const Matrix<int>& pInv )
.. cpp:function:: void PermuteCols( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p, const AbstractDistMatrix<int>& pInv )

   Provide the inverse permutations so that they do not need to be internally
   computed and discarded.

PermuteRows
^^^^^^^^^^^

.. cpp:function:: void PermuteRows( Matrix<T>& A, const Matrix<int>& p )
.. cpp:function:: void PermuteRows( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p )

.. cpp:function:: void PermuteRows( Matrix<T>& A, const Matrix<int>& p, const Matrix<int>& pInv )
.. cpp:function:: void PermuteRows( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p, const AbstractDistMatrix<int>& pInv )

   Provide the inverse permutations so that they do not need to be internally
   computed and discarded.

InversePermuteCols
^^^^^^^^^^^^^^^^^^

.. cpp:function:: void InversePermuteCols( Matrix<T>& A, const Matrix<int>& p )
.. cpp:function:: void InversePermuteCols( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p )

InversePermuteRows
^^^^^^^^^^^^^^^^^^

.. cpp:function:: void InversePermuteRows( Matrix<T>& A, const Matrix<int>& p )
.. cpp:function:: void InversePermuteRows( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& p )

InvertPermutation
^^^^^^^^^^^^^^^^^

.. cpp:function:: void InvertPermutation( const Matrix<int>& p, Matrix<int>& pInv )
.. cpp:function:: void InvertPermutation( const AbstractDistMatrix<int>& p, AbstractDistMatrix<int>& pInv )

   Compute the inverse permutation matrix in compressed (vector) form.

ExplicitPermutation
^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ExplicitPermutation( const Matrix<int>& p, Matrix<int>& P )
.. cpp:function:: void ExplicitPermutation( const AbstractDistMatrix<int>& p, AbstractDistMatrix<int>& P )

   Return the full permutation matrix, `P`, represented by the permutation 
   vector `p`.

PermutationParity
^^^^^^^^^^^^^^^^^

.. cpp:function:: bool PermutationParity( const Matrix<int>& p )
.. cpp:function:: bool PermutationParity( const AbstractDistMatrix<int>& p )

   Return true if the given permutation is odd. The parity is determined in
   linear time by finding the decomposition of the inverse of the permutation 
   as a product of transpositions.

PermutationMeta
^^^^^^^^^^^^^^^

.. cpp:type:: PermutationMeta

   .. cpp:member:: Int align
   .. cpp:member:: mpi::Comm comm

   .. cpp:member:: std::vector<int> sendCounts
   .. cpp:member:: std::vector<int> sendDispls
   .. cpp:member:: std::vector<int> sendIdx
   .. cpp:member:: std::vector<int> sendRanks

   .. cpp:member:: std::vector<int> recvCounts
   .. cpp:member:: std::vector<int> recvDispls
   .. cpp:member:: std::vector<int> recvIdx
   .. cpp:member:: std::vector<int> recvRanks

   .. cpp:function:: int TotalSend() const
   .. cpp:function:: int TotalRecv() const

   .. cpp:function:: void ScaleUp( int length )
   .. cpp:function:: void ScaleDown( int length )

   .. cpp:function:: PermutationMeta( const AbstractDistMatrix<int>& p, const AbstractDistMatrix<int>& pInv )

Pivot sequences
---------------
These routines make use of LAPACK-style pivot sequence vectors, where the 
*pivot* *sequence* *vector* `p` implies the sequence of swaps :math:`(0,p_0)`,
:math:`(1,p_1)`, ..., :math:`(n-1,p_{n-1})`. Elemental used to follow this
convention when returning permutations from factorizations, but clearly this
representation is somewhat restrictive, as routines which perform multiple swaps
for each pivot (e.g., some variants of Bunch-Kaufman) cannot be handled.

ApplyColPivots
^^^^^^^^^^^^^^

.. cpp:function:: void ApplyColPivots( Matrix<T>& A, const Matrix<int>& pivots )
.. cpp:function:: void ApplyColPivots( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots )

ApplyInverseColPivots
^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ApplyInverseColPivots( Matrix<T>& A, const Matrix<int>& pivots )
.. cpp:function:: void ApplyInverseColPivots( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots )

ApplyRowPivots
^^^^^^^^^^^^^^

.. cpp:function:: void ApplyRowPivots( Matrix<T>& A, const Matrix<int>& pivots )
.. cpp:function:: void ApplyRowPivots( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots )

ApplyInverseRowPivots
^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ApplyInverseRowPivots( Matrix<T>& A, const Matrix<int>& pivots )
.. cpp:function:: void ApplyInverseRowPivots( AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots )

ApplySymmetricPivots
^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ApplySymmetricPivots( UpperOrLower uplo, Matrix<T>& A, const Matrix<int>& pivots, bool conjugate=false )
.. cpp:function:: void ApplySymmetricPivots( UpperOrLower uplo, AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots, bool conjugate=false )

ApplyInverseSymmetricPivots
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ApplyInverseSymmetricPivots( UpperOrLower uplo, Matrix<T>& A, const Matrix<int>& pivots, bool conjugate=false )
.. cpp:function:: void ApplyInverseSymmetricPivots( UpperOrLower uplo, AbstractDistMatrix<T>& A, const AbstractDistMatrix<int>& pivots, bool conjugate=false )

PivotParity
^^^^^^^^^^^

.. cpp:function:: bool PivotParity( const Matrix<int>& pivots )
.. cpp:function:: bool PivotParity( const AbstractDistMatrix<int>& pivots )

   Return true if the permutation implied by the pivot sequence is odd. This
   is determined by determining if an odd number of non-trivial transpositions
   are performed.

Converting pivot sequences to permutations
------------------------------------------

PivotsToPermutation
^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void PivotsToPermutation( const Matrix<int>& pivots, Matrix<int>& p, int offset=0 )
.. cpp:function:: void PivotsToPermutation( const AbstractDistMatrix<int>& pivots, AbstractDistMatrix<int>& p, int offset=0 )

PivotsToInversePermutation
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void PivotsToInversePermutation( const Matrix<int>& pivots, Matrix<int>& pInv, int offset=0 )
.. cpp:function:: void PivotsToInversePermutation( const AbstractDistMatrix<int>& pivots, AbstractDistMatrix<int>& pInv, int offset=0 )

PivotsToPartialPermutation
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void PivotsToPartialPermutation( const Matrix<int>& pivots, Matrix<int>& p, Matrix<int>& pInv, int offset=0 )
.. cpp:function:: void PivotsToPartialPermutation( const AbstractDistMatrix<int>& pivots, AbstractDistMatrix<int>& p, AbstractDistMatrix<int>& pInv, int offset=0 )

