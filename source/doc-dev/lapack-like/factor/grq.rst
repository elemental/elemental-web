Generalized RQ factorization
----------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/GRQ.cpp>`__

The *generalized RQ factorization* of a pair of matrices :math:`(A,B)` is 
analogous to an RQ factorization of :math:`A B^{-1}` but does not require that
:math:`B` is square or invertible:
unitary matrices :math:`Q` and :math:`Z`, and (right) upper-triangular matrices
:math:`R` and :math:`T`, are computed such that

.. math::

   A = R Q


and

.. math::

   B = Z T Q.

Thus, is :math:`B` was square and invertible, then the RQ factorization of 
:math:`A B^{-1}` would be given by :math:`(R T^{-1}) Z^H`.

.. cpp:function:: void GRQ( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GRQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Overwrite :math:`A` with :math:`R` and :math:`B` with :math:`T`.

.. cpp:function:: void GRQ( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GRQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tA, AbstractDistMatrix<Base<F>>& dA, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& tB, AbstractDistMatrix<Base<F>>& dB )

   Overwrite :math:`A` with both :math:`R` and the (scaled) Householder vectors
   which, along with the scalings :math:`tA` and sign changes :math:`dA`, define
   :math:`Q`. Likewise, :math:`B` is overwritten with both :math:`T` and the
   (scaled) Householder vectors which define :math:`Z`.
