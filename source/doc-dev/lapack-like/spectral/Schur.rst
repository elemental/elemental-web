Schur decomposition
===================

Elemental contains a native prototype implementation of a spectral divide and
conquer scheme for the Schur decomposition, but it is not yet robust enough
to handle general matrices. For local matrices, Elemental defaults to calling
LAPACK's Hessenberg QR algorithm (with Aggressive Early Deflation); if 
support for ScaLAPACK was detected during configuration, Elemental defaults to
ScaLAPACK's Hessenberg QR algorithm (without deflation), otherwise the 
Spectral Divide and Conquer approach is attempted.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Schur.cpp>`__

.. cpp:function:: void Schur( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, bool fullTriangle=false, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( AbstractDistMatrix<F>& A, AbstractDistMatrix<Complex<Base<F>>>& w, bool fullTriangle=false, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( Matrix<F>& A, Matrix<Complex<Base<F>>>& w, Matrix<F>& Q, bool fullTriangle=true, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )
.. cpp:function:: void Schur( AbstractDistMatrix<F>& A, AbstractDistMatrix<Complex<Base<F>>>& w, AbstractDistMatrix<F>& Q, bool fullTriangle=true, const SchurCtrl<Base<F>> ctrl=SchurCtrl<Base<F>>() )

Algorithmic options
-------------------
By default, Hessenberg QR algorithms are used if possible 
(in the distributed-memory case, ScaLAPACK must have been detected), and, 
in addition to being able to configure the Hessenberg QR algorithm options,
it is also possible to force the usage of a Spectral Divide and Conquer 
algorithm.

.. cpp:type:: SchurCtrl<Real>

   .. cpp:member:: bool useSDC

      Whether or not to use Spectral Divide and Conquer

   .. cpp:member:: HessQRCtrl qrCtrl

      The control structure for the Hessenberg QR algorithm

   .. cpp:member:: SDCCtrl<Real> sdcCtrl

      The control structure for the Spectral Divide and Conquer algorithm

.. cpp:type:: SchurCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

*TODO:* Reference to the distributed Hessenberg QR work of Granat, Kagstrom, Kressner, et al.

.. cpp:type:: HessQRCtrl

   .. cpp:member:: bool distAED

      Whether or not Aggressive Early Deflation should be attempted for
      distributed matrices (due to existing bugs in the ScaLAPACK 
      implementation, by default, no)

   .. cpp:member:: Int blockHeight
   .. cpp:member:: Int blockWidth

      The distribution block height and width for the Hessenberg QR algorithm

The primary reference for the current Spectral Divide and Conquer approachh is 
*Fast linear algebra is stable*, Demmel et al. While the current 
implementation requires multiple algorithmic improvements in order to achieve
stability, for example, better Mobius transformation selection, it often
succeeds on random matrices.

`SDC header file <https://github.com/elemental/Elemental/blob/master/src/lapack-like/spectral/Schur/SDC.hpp>`__

.. cpp:type:: SDCCtrl<Real>

   .. cpp:member:: int cutoff
   .. cpp:member:: int maxInnerIts
   .. cpp:member:: int maxOuterIts
   .. cpp:member:: Real tol
   .. cpp:member:: Real spreadFactor
   .. cpp:member:: bool random
   .. cpp:member:: bool progress

.. cpp:type:: SDCCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

Quasi-triangular manipulation
-----------------------------

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& U, Matrix<Complex<Base<F>>>& w )
.. cpp:function:: void schur::QuasiTriangEig( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Complex<Base<F>>>& w )

   Return the eigenvalues of the upper quasi-triangular matrix `U` in the vector
   `w`.

.. cpp:function:: Matrix<Complex<Base<F>>> schur::QuasiTriangEig( const Matrix<F>& U )
.. cpp:function:: DistMatrix<Complex<Base<F>>,VR,STAR> schur::QuasiTriangEig( const AbstractDistMatrix<F>& U )

   Return the eigenvalues of the upper quasi-triangular matrix `U`.

.. cpp:function:: void schur::QuasiTriangEig( const Matrix<F>& dMain, const Matrix<F>& dSub, const Matrix<F>& dSup, Matrix<Complex<Base<F>>>& w )

   The underlying computation routine for computing the eigenvalues of 
   quasi-triangular matrices. The vectors `dMain`, `dSub`, and `dSup` should
   respectively contain the main, sub, and super-diagonals of the 
   upper quasi-triangular matrix.

.. cpp:function:: void schur::RealToComplex( const Matrix<Real>& UQuasi, Matrix<Complex<Real>>& U )
.. cpp:function:: void schur::RealToComplex( const AbstractDistMatrix<Real>& UQuasi, AbstractDistMatrix<Complex<Real>>& U )

   Rotate a real upper quasi-triangular matrix into a complex upper triangular
   matrix.

.. cpp:function:: void schur::CheckRealSchur( const Matrix<Real>& U, bool standardForm=false )
.. cpp:function:: void schur::CheckRealSchur( const AbstractDistMatrix<Real>& U, bool standardForm=false )

   Check whether or not the largest diagonal blocks of the upper quasi-triangular
   matrix are at most :math:`2 \times 2` and, optionally, check if the 
   :math:`2 \times 2` diagonal blocks are in standard form 
   (if so, their diagonal must be constant and the product of the off-diagonal 
   entries should be negative).
