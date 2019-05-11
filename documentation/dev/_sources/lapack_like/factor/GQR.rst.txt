Generalized QR factorization
============================
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

Python API
----------
The style of factorization is encoded within a pseudo-enum which takes on one of four values:

.. py:data:: GQR_IMPLICIT=0

   Form the implicit, packed factorization

.. py:data:: GQR_EXPLICIT=1

   Explicitly return the individual factors (not yet supported)

.. py:data:: GQR_EXPLICIT_TRIANG=2

   Explicitly return the triangular factors, :math:`R` and :math:`T`

.. py:data:: GQR_EXPLICIT_UNITARY=3

   Explicitly return the unitary factors, :math:`Q` and :math:`Z` 
   (not yet supported)

.. py:function:: GQR(A,B[,factType=GQR_IMPLICIT])

   :param A:
   :param B:
   :param factType: (optional)
   :rtype: If ``factType`` is :py:data:`GQR_IMPLICIT`, :math:`(t_A,d_A,t_B,d_b)`, ...

C++ API
-------
.. cpp:function:: void GQR( Matrix<F>& A, Matrix<F>& tA, Matrix<Base<F>>& dA, Matrix<F>& B, Matrix<F>& tB, Matrix<Base<F>>& dB )
.. cpp:function:: void GQR( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& tA, AbstractDistMatrix<Base<F>>& dA, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& tB, AbstractDistMatrix<Base<F>>& dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors 
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder 
   vectors which define `Z`.

.. cpp:function:: void gqr::ExplicitTriang( Matrix<F>& A, Matrix<F>& B )
.. cpp:function:: void gqr::ExplicitTriang( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B )

   Overwrite `A` with `R` and `B` with `T`.

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElGQR_s( ElMatrix_s A, ElMatrix_s tA, ElMatrix_s dA, ElMatrix_s B, ElMatrix_s tB, ElMatrix_s dB )
.. c:function:: ElError ElGQRDist_s( ElDistMatrix_s A, ElDistMatrix_s tA, ElDistMatrix_s dA, ElDistMatrix_s B, ElDistMatrix_s tB, ElDistMatrix_s dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors 
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder 
   vectors which define `Z`.

.. c:function:: ElError ElGQRExplicitTriang_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElGQRExplicitTriangDist_s( ElDistMatrix_s A, ElDistMatrix_s B )

   Overwrite `A` with `R` and `B` with `T`.

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElGQR_d( ElMatrix_d A, ElMatrix_d tA, ElMatrix_d dA, ElMatrix_d B, ElMatrix_d tB, ElMatrix_d dB )
.. c:function:: ElError ElGQRDist_d( ElDistMatrix_d A, ElDistMatrix_d tA, ElDistMatrix_d dA, ElDistMatrix_d B, ElDistMatrix_d tB, ElDistMatrix_d dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors 
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder 
   vectors which define `Z`.

.. c:function:: ElError ElGQRExplicitTriang_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElGQRExplicitTriangDist_d( ElDistMatrix_d A, ElDistMatrix_d B )

   Overwrite `A` with `R` and `B` with `T`.

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElGQR_c( ElMatrix_c A, ElMatrix_c tA, ElMatrix_s dA, ElMatrix_c B, ElMatrix_c tB, ElMatrix_s dB )
.. c:function:: ElError ElGQRDist_c( ElDistMatrix_c A, ElDistMatrix_c tA, ElDistMatrix_s dA, ElDistMatrix_c B, ElDistMatrix_c tB, ElDistMatrix_s dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors 
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder 
   vectors which define `Z`.

.. c:function:: ElError ElGQRExplicitTriang_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElGQRExplicitTriangDist_c( ElDistMatrix_c A, ElDistMatrix_c B )

   Overwrite `A` with `R` and `B` with `T`.

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElGQR_z( ElMatrix_z A, ElMatrix_z tA, ElMatrix_d dA, ElMatrix_z B, ElMatrix_z tB, ElMatrix_d dB )
.. c:function:: ElError ElGQRDist_z( ElDistMatrix_z A, ElDistMatrix_z tA, ElDistMatrix_d dA, ElDistMatrix_z B, ElDistMatrix_z tB, ElDistMatrix_d dB )

   Overwrite `A` with both `R` and the (scaled) Householder vectors 
   which, along with the scalings `tA` and sign changes `dA`, define
   `Q`. Likewise, `B` is overwritten with both `T` and the (scaled) Householder 
   vectors which define `Z`.

.. c:function:: ElError ElGQRExplicitTriang_z( ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElGQRExplicitTriangDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

   Overwrite `A` with `R` and `B` with `T`

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/GQR.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrappers <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrappers <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__
