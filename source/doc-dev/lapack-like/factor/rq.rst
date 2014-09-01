RQ factorization
================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/RQ.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/factor/RQ>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/RQ.cpp>`__

Just like an LQ factorization, but the orthogonalization process starts from the bottom row and produces a 
much sparser triangular factor when the matrix is wider than it is tall.

Factorization
-------------

C++ API
^^^^^^^

.. cpp:function:: void RQ( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void RQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d )

   Overwrite the matrix :math:`A` with :math:`R` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the unitary diagonal
   matrix which forces :math:`R` to be positive is defined by the vector `d`.

.. cpp:function:: void RQ( Matrix<F>& A )
.. cpp:function:: void RQ( AbstractDistMatrix<F>& A )

   Overwrite `A` with the triangular factor, `R`.

C API
^^^^^

.. c:function:: ElError ElRQ_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d )
.. c:function:: ElError ElRQ_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d )
.. c:function:: ElError ElRQ_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d )
.. c:function:: ElError ElRQ_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d )
.. c:function:: ElError ElRQDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d )
.. c:function:: ElError ElRQDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d )
.. c:function:: ElError ElRQDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d )
.. c:function:: ElError ElRQDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d )

   Overwrite the matrix :math:`A` with :math:`R` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the unitary diagonal
   matrix which forces :math:`R` to be positive is defined by the vector `d`.

.. c:function:: ElError ElRQTriang_s( ElMatrix_s A )
.. c:function:: ElError ElRQTriang_d( ElMatrix_d A )
.. c:function:: ElError ElRQTriang_c( ElMatrix_c A )
.. c:function:: ElError ElRQTriang_z( ElMatrix_z A )

   Overwrite `A` with the triangular factor, `R`.

Apply the factored matrix
-------------------------

C++ API
^^^^^^^

.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

C API
^^^^^

.. c:function:: ElError ElApplyQAfterRQ_s( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElMatrix_s B )
.. c:function:: ElError ElApplyQAfterRQ_d( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterRQ_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterRQ_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterRQDist_s( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElDistMatrix_s B )
.. c:function:: ElError ElApplyQAfterRQDist_d( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElDistMatrix_d B )
.. c:function:: ElError ElApplyQAfterRQDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElDistMatrix_c B )
.. c:function:: ElError ElApplyQAfterRQDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElDistMatrix_z B )

Solve linear systems with the factored matrix
---------------------------------------------

C++ API
^^^^^^^

.. cpp:function:: void rq::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void rq::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

   Solves a set of linear systems using an existing packed RQ factorization 
   given by :math:`A` and the vectors :math:`t` and :math:`d`.
   :math:`B` is the matrix of input vectors and :math:`X` is the matrix of
   solutions.

C API
^^^^^

.. c:function:: ElError ElSolveAfterRQ_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElSolveAfterRQ_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElSolveAfterRQ_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElSolveAfterRQ_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElConstMatrix_z B, ElMatrix_z X )
.. c:function:: ElError ElSolveAfterRQDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElSolveAfterRQDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElSolveAfterRQDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElSolveAfterRQDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElConstDistMatrix_z B, ElDistMatrix_z X )
