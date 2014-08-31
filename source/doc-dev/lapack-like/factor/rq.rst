RQ factorization
----------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/RQ.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/factor/RQ>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/RQ.cpp>`__

Just like an LQ factorization, but the orthogonalization process starts from the bottom row and produces a 
much sparser triangular factor when the matrix is wider than it is tall.

.. cpp:function:: void RQ( Matrix<F>& A )
.. cpp:function:: void RQ( AbstractDistMatrix<F>& A )
.. cpp:function:: void RQ( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void RQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d )

   Overwrite the matrix :math:`A` with :math:`R` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the unitary diagonal
   matrix which forces :math:`R` to be positive is defined by the vector `d`.

rq namespace
^^^^^^^^^^^^

.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void rq::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<F>& B )

   Applies the implicitly-defined :math:`Q` (or its adjoint) stored within
   `A`, `t`, and `d` from either the left or the right to :math:`B`.

.. cpp:function:: void rq::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void rq::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

   Solves a set of linear systems using an existing packed RQ factorization given
   by :math:`A` and the vectors :math:`t` and :math:`d`.
   :math:`B` is the matrix of input vectors and :math:`X` is the matrix of
   solutions.
