Generalized RQ factorization
============================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/dense/GRQ.cpp>`__

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

C++ API
-------

.. cpp:function:: void GRQ( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GRQ( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tA, AbstractDistMatrix<Base<F>>& dA, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& tB, AbstractDistMatrix<Base<F>>& dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder
   vectors which define `Z`.

.. cpp:function:: void grq::ExplicitTriang( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void grq::ExplicitTriang( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Overwrite `A` with `R` and `B` with `T`.

C API
-----

.. c:function:: ElError ElGRQ_s( ElMatrix_s A, ElMatrix_s tA, ElMatrix_s dA, ElMatrix_s B, ElMatrix_s tB, ElMatrix_s dB )
.. c:function:: ElError ElGRQ_d( ElMatrix_d A, ElMatrix_d tA, ElMatrix_d dA, ElMatrix_d B, ElMatrix_d tB, ElMatrix_d dB )
.. c:function:: ElError ElGRQ_c( ElMatrix_c A, ElMatrix_c tA, ElMatrix_s dA, ElMatrix_c B, ElMatrix_c tB, ElMatrix_s dB )
.. c:function:: ElError ElGRQ_z( ElMatrix_z A, ElMatrix_z tA, ElMatrix_d dA, ElMatrix_z B, ElMatrix_z tB, ElMatrix_d dB )
.. c:function:: ElError ElGRQDist_s( ElDistMatrix_s A, ElDistMatrix_s tA, ElDistMatrix_s dA, ElDistMatrix_s B, ElDistMatrix_s tB, ElDistMatrix_s dB )
.. c:function:: ElError ElGRQDist_d( ElDistMatrix_d A, ElDistMatrix_d tA, ElDistMatrix_d dA, ElDistMatrix_d B, ElDistMatrix_d tB, ElDistMatrix_d dB )
.. c:function:: ElError ElGRQDist_c( ElDistMatrix_c A, ElDistMatrix_c tA, ElDistMatrix_s dA, ElDistMatrix_c B, ElDistMatrix_c tB, ElDistMatrix_s dB )
.. c:function:: ElError ElGRQDist_z( ElDistMatrix_z A, ElDistMatrix_z tA, ElDistMatrix_d dA, ElDistMatrix_z B, ElDistMatrix_z tB, ElDistMatrix_d dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder
   vectors which define `Z`.

.. c:function:: ElError ElGRQExplicitTriang_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElGRQExplicitTriang_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElGRQExplicitTriang_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElGRQExplicitTriang_z( ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElGRQExplicitTriangDist_s( ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElGRQExplicitTriangDist_d( ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElGRQExplicitTriangDist_c( ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElGRQExplicitTriangDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

   Overwrite `A` with `R` and `B` with `T`.
