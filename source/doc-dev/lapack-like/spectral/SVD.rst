SVD
===
Given a general matrix :math:`A`, the *Singular Value Decomposition* is the 
triplet :math:`(U,\Sigma,V)` such that

.. math::

   A = U \Sigma V^H,

where :math:`U` and :math:`V` are unitary, and :math:`\Sigma` is diagonal with 
non-negative entries.

General
-------

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/SVD.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack-like/spectral/SVD>`__

C++ API
^^^^^^^

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

   Overwrites `A` with :math:`U`, `s` with the diagonal entries of :math:`\Sigma`, and `V` with :math:`V`. 

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s )

   Forms the singular values of :math:`A` in `s`. Note that `A` is overwritten in order to compute the singular values.

.. cpp:type:: SVDCtrl<Real>

   .. cpp:member:: bool seqQR

      Whether or not sequential implementations should use the QR algorithm
      instead of a Divide and Conquer when computing singular vectors.
      When only singular values are requested, a bidiagonal DQDS algorithms is 
      always run.

   .. cpp:member:: double valChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when only computing singular values.

   .. cpp:member:: double fullChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when computing a full SVD.

   .. cpp:member:: bool thresholded
 
      If the sufficiently small singular triplets should be thrown away.
      When thresholded, a cross-product algorithm is used. This is often
      advantageous since tridiagonal eigensolvers tend to have faster 
      parallel implementations than bidiagonal SVD's.

   .. cpp:member:: bool relative

      If the tolerance should be relative to the largest singular value.

   .. cpp:member:: Real tol

      The numerical tolerance for the thresholding. If this value is kept at
      zero, then a value is automatically chosen based upon the matrix.

   .. cpp:function:: SVDCtrl()

      Sets ``seqQR=false``, ``valChanRatio=1.2``, ``fullChanRatio=1.5``,
      ``thresholded=false``, ``relative=true``, and ``tol=0``.

.. cpp:type:: SVDCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
^^^^^

**TODO**

Hermitian
---------
Suppose that :math:`A` is Hermitian, with a spectral decomposition

.. math::

   A = V \Lambda V^H.

Then an SVD of :math:`A` can easily be computed as

.. math::

   A = U |\Lambda| V^H,

where the columns of :math:`U` equal the columns of :math:`V`, modulo sign 
flips introduced by negative eigenvalues.

C++ API
^^^^^^^

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& U, Matrix<F>& V )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& U, AbstractDistMatrix<F>& V )

   Return a vector of singular values, :math:`s`, and the left and right 
   singular vector matrices, :math:`U` and :math:`V`, such that 
   :math:`A=U \mathrm{diag}(s) V^H`.

.. cpp:function:: void HermitianSVD( UpperOrLower uplo, Matrix<F>& A, Matrix<Base<F>>& s )
.. cpp:function:: void HermitianSVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s )

   Return the singular values of :math:`A` in `s`. Note that the appropriate 
   triangle of `A` is overwritten during computation.

C API
^^^^^

**TODO**
