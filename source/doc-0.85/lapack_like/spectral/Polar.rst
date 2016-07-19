Polar decomposition
===================
Every matrix :math:`A` can be written as :math:`A=QP`, where :math:`Q` is 
unitary and :math:`P` is Hermitian and positive semi-definite. This is known as
the *polar decomposition* of :math:`A` and can be constructed as 
:math:`Q := U V^H` and :math:`P := V \Sigma V^H`, where 
:math:`A = U \Sigma V^H` is the SVD of :math:`A`. Alternatively, it can be 
computed through (a dynamically-weighted) Halley iteration.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/Polar.cpp>`__

`SVD approach <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/Polar/SVD.hpp>`__

`QWDH approach <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/Polar/QDWH.hpp>`__

.. cpp:function:: void Polar( Matrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( AbstractDistMatrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( Matrix<F>& A, Matrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void Polar( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )

   Compute the polar decomposition of :math:`A`, :math:`A=QP`, returning 
   :math:`Q` within `A` and :math:`P` within `P`. The current implementation
   first computes the SVD.

.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, AbstractDistMatrix<F>& A, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )
.. cpp:function:: void HermitianPolar( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& P, const PolarCtrl& ctrl=PolarCtrl() )

   Compute the polar decomposition through a Hermitian EVD. Since this is 
   equivalent to a Hermitian sign decomposition (if :math:`\text{sgn}(0)` is 
   set to 1), these routines are equivalent to `HermitianSign`.

Algorithmic options
-------------------
By default, an SVD-based algorithm is used, but an approach based upon
a QR-based Dynamically Weighted Halley (QDWH) iteration can be manually chosen.

.. cpp:type:: PolarCtrl

   .. cpp:member:: bool qdwh

      Whether or not to use QDWH (the default is no)

   .. cpp:member:: bool colPiv

      Whether or not QDWH should use column pivoting in its QR factorizations
      (the default is no)

   .. cpp:member:: Int maxIts

      The maximum number of iterations of QDWH (the default is 20, but typically
      no more than 6 or 7 will be performed)

   .. cpp:member:: mutable Int numIts

      The number of iterations of QDWH performed in the last call

