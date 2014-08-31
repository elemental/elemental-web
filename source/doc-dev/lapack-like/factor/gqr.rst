Generalized QR factorization
----------------------------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/GQR.cpp>`__

The *generalized QR factorization* of a pair of matrices :math:`(A,B)` is 
analogous to a QR factorization of :math:`B^{-1} A` but does not require that
:math:`B` is square or invertible: 
unitary matrices :math:`Q` and :math:`Z`, and (right) upper-triangular matrices 
:math:`R` and :math:`T`, are computed such that

.. math::

   A = Q R


and

.. math::

   B = Q T Z.

Thus, if :math:`B` was square and invertible, then the QR factorization of 
:math:`B^{-1} A` would be given by :math:`Z^H (T^{-1} R)`.

.. cpp:function:: void GQR( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void GQR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Overwrite :math:`A` with :math:`R` and :math:`B` with :math:`T`.

.. cpp:function:: void GQR( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GQR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tA, AbstractDistMatrix<Base<F>>& dA, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& tB, AbstractDistMatrix<Base<F>>& dB )

   Overwrite :math:`A` with both :math:`R` and the (scaled) Householder vectors 
   which, along with the scalings :math:`tA` and sign changes :math:`dA`, define
   :math:`Q`. Likewise, :math:`B` is overwritten with both :math:`T` and the 
   (scaled) Householder vectors which define :math:`Z`.

