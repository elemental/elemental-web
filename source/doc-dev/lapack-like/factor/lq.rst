LQ factorization
================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/LQ.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/factor/LQ>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack-like/LQ.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}`, an LQ factorization typically 
computes an implicit unitary matrix :math:`\hat Q \in \mathbb{F}^{n \times n}` 
such that :math:`\hat L \equiv A\hat Q^H` is lower trapezoidal. One can then 
form the thin factors :math:`L \in \mathbb{F}^{m \times \mbox{min}(m,n)}` and 
:math:`Q \in \mathbb{F}^{\mbox{min}(m,n) \times n}` by setting 
:math:`L` and :math:`Q` to first :math:`\mbox{min}(m,n)` columns and rows of 
:math:`\hat L` and :math:`\hat Q`, respectively. Upon completion :math:`L` is 
stored in the lower trapezoid of :math:`A` and the Householder reflectors 
(and preceding unitary diagonal matrix forcing :math:`L` to have a positive 
diagonal, defined by the vector `d`) representing :math:`\hat Q` are stored 
within the rows of the strictly upper trapezoid.

Factorization
-------------

C++ API
^^^^^^^

.. cpp:function:: void LQ( Matrix<F>& A, Matrix<F>& t, Matrix<Base<F>>& d )
.. cpp:function:: void LQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t, AbstractDistMatrix<Base<F>>& d )

   Overwrite the matrix :math:`A` with :math:`L` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the diagonal 
   matrix which forces :math:`L` to be positive in `d`.

.. cpp:function:: void LQ( Matrix<F>& A )
.. cpp:function:: void LQ( AbstractDistMatrix<F>& A )

   The same as above, but do not return the matrices `t` and `d`.

C API
^^^^^

**TODO**

Applying the factored matrix
----------------------------

The following routines apply the implicitly-defined :math:`Q` (or its adjoint) 
stored within `A`, `t`, and `d` from either the left or the right to :math:`B`.

C++ API
^^^^^^^

.. cpp:function:: void lq::ApplyQ( LeftOrRight side, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, Matrix<F>& B )
.. cpp:function:: void lq::ApplyQ( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, AbstractDistMatrix<F>& B )

C API
^^^^^

**TODO**

Solving against the factored matrix
-----------------------------------
The following routines solve a set of linear systems using an existing packed 
LQ factorization given by :math:`A` and the vectors :math:`t` and :math:`d`.
:math:`B` is the matrix of input vectors and :math:`X` is the matrix of 
solutions.

C++ API
^^^^^^^

.. cpp:function:: void lq::SolveAfter( Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, const Matrix<Base<F>>& d, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void lq::SolveAfter( Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

C API
^^^^^

**TODO**
