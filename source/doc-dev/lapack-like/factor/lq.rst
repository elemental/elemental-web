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

.. note::

   The following three sets of routines should likely be renamed so that 
   their functionality is more apparent.

.. cpp:function:: void LQ( Matrix<F>& A )
.. cpp:function:: void LQ( AbstractDistMatrix<F>& A )

   Overwrite `A` with the triangular factor, `L`.

.. cpp:function:: void lq::Explicit( Matrix<F>& A )
.. cpp:function:: void lq::Explicit( AbstractDistMatrix<F>& A )

   Overwrite `A` with `Q`.

.. cpp:function:: void lq::Explicit( Matrix<F>& L, Matrix<F>& A )
.. cpp:function:: void lq::Explicit( AbstractDistMatrix<F>& L, AbstractDistMatrix<F>& A )

   Overwrite `A` with `Q` and return `L`.

C API
^^^^^

.. c:function:: ElError ElLQ_s( ElMatrix_s A, ElMatrix_s t, ElMatrix_s d )
.. c:function:: ElError ElLQ_d( ElMatrix_d A, ElMatrix_d t, ElMatrix_d d )
.. c:function:: ElError ElLQ_c( ElMatrix_c A, ElMatrix_c t, ElMatrix_s d )
.. c:function:: ElError ElLQ_z( ElMatrix_z A, ElMatrix_z t, ElMatrix_d d )
.. c:function:: ElError ElLQDist_s( ElDistMatrix_s A, ElDistMatrix_s t, ElDistMatrix_s d )
.. c:function:: ElError ElLQDist_d( ElDistMatrix_d A, ElDistMatrix_d t, ElDistMatrix_d d )
.. c:function:: ElError ElLQDist_c( ElDistMatrix_c A, ElDistMatrix_c t, ElDistMatrix_s d )
.. c:function:: ElError ElLQDist_z( ElDistMatrix_z A, ElDistMatrix_z t, ElDistMatrix_d d )

   Overwrite the matrix :math:`A` with :math:`L` and the 
   Householder reflectors representing :math:`\hat Q`. The scalings for the
   Householder reflectors are stored in the vector `t` and the diagonal 
   matrix which forces :math:`L` to be positive in `d`.

.. c:function:: ElError ElLQTriang_s( ElMatrix_s A )
.. c:function:: ElError ElLQTriang_d( ElMatrix_d A )
.. c:function:: ElError ElLQTriang_c( ElMatrix_c A )
.. c:function:: ElError ElLQTriang_z( ElMatrix_z A )
.. c:function:: ElError ElLQTriangDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElLQTriangDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElLQTriangDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLQTriangDist_z( ElDistMatrix_z A )

   Ovewrite `A` with the triangular factor, `L`.

.. c:function:: ElError ElLQUnitary_s( ElMatrix_s A )
.. c:function:: ElError ElLQUnitary_d( ElMatrix_d A )
.. c:function:: ElError ElLQUnitary_c( ElMatrix_c A )
.. c:function:: ElError ElLQUnitary_z( ElMatrix_z A )
.. c:function:: ElError ElLQUnitaryDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElLQUnitaryDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElLQUnitaryDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLQUnitaryDist_z( ElDistMatrix_z A )

   Overwrite `A` with `Q`.

.. c:function:: ElError ElLQExplicit_s( ElMatrix_s L, ElMatrix_s A )
.. c:function:: ElError ElLQExplicit_d( ElMatrix_d L, ElMatrix_d A )
.. c:function:: ElError ElLQExplicit_c( ElMatrix_c L, ElMatrix_c A )
.. c:function:: ElError ElLQExplicit_z( ElMatrix_z L, ElMatrix_z A )
.. c:function:: ElError ElLQExplicitDist_s( ElDistMatrix_s L, ElDistMatrix_s A )
.. c:function:: ElError ElLQExplicitDist_d( ElDistMatrix_d L, ElDistMatrix_d A )
.. c:function:: ElError ElLQExplicitDist_c( ElDistMatrix_c L, ElDistMatrix_c A )
.. c:function:: ElError ElLQExplicitDist_z( ElDistMatrix_z L, ElDistMatrix_z A )

   Overwrite `A` with `Q` and return `L`.

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

.. c:function:: ElError ElApplyQAfterLQ_s( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElMatrix_s B )
.. c:function:: ElError ElApplyQAfterLQ_d( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElMatrix_d B )
.. c:function:: ElError ElApplyQAfterLQ_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElMatrix_c B )
.. c:function:: ElError ElApplyQAfterLQ_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElMatrix_z B )
.. c:function:: ElError ElApplyQAfterLQDist_s( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElDistMatrix_s B )
.. c:function:: ElError ElApplyQAfterLQDist_d( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElDistMatrix_d B )
.. c:function:: ElError ElApplyQAfterLQDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElDistMatrix_c B )
.. c:function:: ElError ElApplyQAfterLQDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElDistMatrix_z B )

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

.. c:function:: ElError ElSolveAfterLQ_s( ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElConstMatrix_s d, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElSolveAfterLQ_d( ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElConstMatrix_d d, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElSolveAfterLQ_c( ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElConstMatrix_s d, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElSolveAfterLQ_z( ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElConstMatrix_d d, ElConstMatrix_z B, ElMatrix_z X )
.. c:function:: ElError ElSolveAfterLQDist_s( ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElConstDistMatrix_s d, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElSolveAfterLQDist_d( ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElConstDistMatrix_d d, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElSolveAfterLQDist_c( ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElConstDistMatrix_s d, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElSolveAfterLQDist_z( ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElConstDistMatrix_d d, ElConstDistMatrix_z B, ElDistMatrix_z X )
