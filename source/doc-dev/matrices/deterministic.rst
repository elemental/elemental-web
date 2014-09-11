Deterministic
=============

Bull's Head
-----------
**TODO: Description**

C++ API
^^^^^^^

.. cpp:function:: void BullsHead( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void BullsHead( AbstractDistMatrix<Complex<Real>>& A, Int n )
.. cpp:function:: void BullsHead( AbstractBlockDistMatrix<Complex<Real>>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElBullsHead_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElBullsHead_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElBullsHeadDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElBullsHeadDist_z( ElDistMatrix_z A, ElInt n )

Cauchy
------
An :math:`m \times n` matrix :math:`A` is called *Cauchy* if there exist 
vectors :math:`x` and :math:`y` such that 

.. math::

   A(i,j) = \frac{1}{x(i) - y(j)}.

The following functions generate a Cauchy matrix using the defining vectors, 
:math:`x` and :math:`y`. 

C++ API
^^^^^^^

.. cpp:function:: void Cauchy( Matrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void Cauchy( AbstractDistMatrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )

C API
^^^^^

.. c:function:: ElError ElCauchy_s( ElMatrix_s A, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchy_d( ElMatrix_d A, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchy_c( ElMatrix_c A, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchy_z( ElMatrix_z A, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )
.. c:function:: ElError ElCauchyDist_s( ElDistMatrix_s A, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyDist_d( ElDistMatrix_d A, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyDist_c( ElDistMatrix_c A, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyDist_z( ElDistMatrix_z A, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )

Cauchy-like
-----------
An :math:`m \times n` matrix :math:`A` is called *Cauchy-like* if there exist 
vectors :math:`r`, :math:`s`, :math:`x`, and :math:`y` such that 

.. math::

   A(i,j) = \frac{r(i) s(j)}{x(i) - y(j)}.

The following routines generate a Cauchy-like matrix using the defining 
vectors: :math:`r`, :math:`s`, :math:`x`, and :math:`y`.

C++ API
^^^^^^^

.. cpp:function:: void CauchyLike( Matrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void CauchyLike( AbstractDistMatrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )

C API
^^^^^

.. c:function:: ElError ElCauchyLike_s( ElMatrix_s A, ElInt rSize, float* rBuf, ElInt sSize, float* sBuf, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyLike_d( ElMatrix_d A, ElInt rSize, double* rBuf, ElInt sSize, double* sBuf, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyLike_c( ElMatrix_c A, ElInt rSize, complex_float* rBuf, ElInt sSize, complex_float* sBuf, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyLike_z( ElMatrix_z A, ElInt rSize, complex_double* rBuf, ElInt sSize, complex_double* sBuf, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )
.. c:function:: ElError ElCauchyLikeDist_s( ElDistMatrix_s A, ElInt rSize, float* rBuf, ElInt sSize, float* sBuf, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyLikeDist_d( ElDistMatrix_d A, ElInt rSize, double* rBuf, ElInt sSize, double* sBuf, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyLikeDist_c( ElDistMatrix_c A, ElInt rSize, complex_float* rBuf, ElInt sSize, complex_float* sBuf, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyLikeDist_z( ElDistMatrix_z A, ElInt rSize, complex_double* rBuf, ElInt sSize, complex_double* sBuf, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )

Circulant
---------
An :math:`n \times n` matrix :math:`A` is called *circulant* if there exists a vector :math:`b` 
such that 

.. math::

   A(i,j) = b((i-j) \bmod n).

The following routines generate a circulant matrix using the vector ``a``.

C++ API
^^^^^^^

.. cpp:function:: void Circulant( Matrix<T>& A, const std::vector<T>& a )
.. cpp:function:: void Circulant( AbstractDistMatrix<T>& A, const std::vector<T>& a )

C API
^^^^^

.. c:function:: ElError ElCirculant_i( ElMatrix_i A, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElCirculant_s( ElMatrix_s A, ElInt aSize, float* aBuf )
.. c:function:: ElError ElCirculant_d( ElMatrix_d A, ElInt aSize, double* aBuf )
.. c:function:: ElError ElCirculant_c( ElMatrix_c A, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElCirculant_z( ElMatrix_z A, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElCirculantDist_i( ElDistMatrix_i A, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElCirculantDist_s( ElDistMatrix_s A, ElInt aSize, float* aBuf )
.. c:function:: ElError ElCirculantDist_d( ElDistMatrix_d A, ElInt aSize, double* aBuf )
.. c:function:: ElError ElCirculantDist_c( ElDistMatrix_c A, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElCirculantDist_z( ElDistMatrix_z A, ElInt aSize, complex_double* aBuf )

Demmel
------
An :math:`n \times n` *Demmel* matrix is of the form

.. math::

   D(n,\beta) = (\beta J(-\beta^{-1},n))^{-1},

where :math:`J(-\beta^{-1},n)` is the :math:`n \times n` Jordan block with
eigenvalue :math:`-\beta^{-1}`, and the standard value for :math:`\beta` is 
:math:`10^{4/(n-1)}`. More explicitly, :math:`D(n,\beta)` is an 
upper-triangular matrix where the :math:`j`'th super-diagonal is equal to 
:math:`-\beta^j`.

C++ API
^^^^^^^

.. cpp:function:: void Demmel( Matrix<F>& A, Int n )
.. cpp:function:: void Demmel( AbstractDistMatrix<F>& A, Int n )
.. cpp:function:: void Demmel( AbstractBlockDistMatrix<F>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElDemmel_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElDemmel_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElDemmel_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElDemmel_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElDemmelDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElDemmelDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElDemmelDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElDemmelDist_z( ElDistMatrix_z A, ElInt n )

Diagonal
--------
An :math:`n \times n` matrix :math:`A` is called *diagonal* if each entry :math:`(i,j)`, where 
:math:`i \neq j`, is :math:`0`. They are therefore defined by the *diagonal* values, where 
:math:`i = j`.

The following routines construct a diagonal matrix from the vector of diagonal 
values, :math:`d`.

C++ API
^^^^^^^

.. cpp:function:: void Diagonal( Matrix<S>& D, const std::vector<T>& d )
.. cpp:function:: void Diagonal( AbstractDistMatrix<S>& D, const std::vector<T>& d )
.. cpp:function:: void Diagonal( AbstractBlockDistMatrix<S>& D, const std::vector<T>& d )

C API
^^^^^

.. c:function:: ElError ElDiagonal_i( ElMatrix_i A, ElInt dSize, ElInt* dBuf )
.. c:function:: ElError ElDiagonal_s( ElMatrix_s A, ElInt dSize, float* dBuf )
.. c:function:: ElError ElDiagonal_d( ElMatrix_d A, ElInt dSize, double* dBuf )
.. c:function:: ElError ElDiagonal_c( ElMatrix_c A, ElInt dSize, complex_float* dBuf )
.. c:function:: ElError ElDiagonal_z( ElMatrix_z A, ElInt dSize, complex_double* dBuf )
.. c:function:: ElError ElDiagonalDist_i( ElDistMatrix_i A, ElInt dSize, ElInt* dBuf )
.. c:function:: ElError ElDiagonalDist_s( ElDistMatrix_s A, ElInt dSize, float* dBuf )
.. c:function:: ElError ElDiagonalDist_d( ElDistMatrix_d A, ElInt dSize, double* dBuf )
.. c:function:: ElError ElDiagonalDist_c( ElDistMatrix_c A, ElInt dSize, complex_float* dBuf )
.. c:function:: ElError ElDiagonalDist_z( ElDistMatrix_z A, ElInt dSize, complex_double* dBuf )

Egorov
------
Sets :math:`A` to an :math:`n \times n` matrix with the :math:`(i,j)` entry
equal to

.. math::

   \exp(i \phi(i,j)).

C++ API
^^^^^^^

.. cpp:function:: void Egorov( Matrix<Complex<Real> >& A, std::function<Real(Int,Int)> phi, Int n )
.. cpp:function:: void Egorov( AbstractDistMatrix<Complex<Real>>& A, std::function<Real(Int,Int)> phi, Int n )

C API
^^^^^

.. c:function:: ElError ElEgorov_c( ElMatrix_c A, float (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorov_z( ElMatrix_z A, double (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorovDist_c( ElDistMatrix_c A, float (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorovDist_z( ElDistMatrix_z A, double (*phase)(ElInt,ElInt), ElInt n )

Extended Kahan
--------------
The upper-triangular matrix :math:`A = S R`, where :math:`S=\text{diag}(1,\zeta,...,\zeta^{3 2^k-1})`, and

.. math::

   R = \begin{pmatrix} I & -\phi H_k & 0 \\
                       0 & I         & \phi H_k \\
                       0 & 0         & I \end{pmatrix}.

**TODO: Reference for its introduction and a description of its relevance to 
rank-revealing QR factorizations**

C++ API
^^^^^^^

.. cpp:function:: void ExtendedKahan( Matrix<F>& A, Int k, Base<F> phi, Base<F> mu )
.. cpp:function:: void ExtendedKahan( AbstractDistMatrix<F>& A, Int k, Base<F> phi, Base<F> mu )

C API
^^^^^

.. c:function:: ElError ElExtendedKahan_s( ElMatrix_s A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahan_d( ElMatrix_d A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahan_c( ElMatrix_c A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahan_z( ElMatrix_z A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahanDist_s( ElDistMatrix_s A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahanDist_d( ElDistMatrix_d A, ElInt k, double phi, double mu )
.. c:function:: ElError ElExtendedKahanDist_c( ElDistMatrix_c A, ElInt k, float phi, float mu )
.. c:function:: ElError ElExtendedKahanDist_z( ElDistMatrix_z A, ElInt k, double phi, double mu )

Fiedler
-------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Fiedler( Matrix<F>& A, const std::vector<F>& c )
.. cpp:function:: void Fiedler( AbstractDistMatrix<F>& A, const std::vector<F>& c )

C API
^^^^^

.. c:function:: ElError ElFiedler_s( ElMatrix_s A, ElInt cSize, float* cBuf )
.. c:function:: ElError ElFiedler_d( ElMatrix_d A, ElInt cSize, double* cBuf )
.. c:function:: ElError ElFiedler_c( ElMatrix_c A, ElInt cSize, complex_float* cBuf )
.. c:function:: ElError ElFiedler_z( ElMatrix_z A, ElInt cSize, complex_double* cBuf )
.. c:function:: ElError ElFiedlerDist_s( ElDistMatrix_s A, ElInt cSize, float* cBuf )
.. c:function:: ElError ElFiedlerDist_d( ElDistMatrix_d A, ElInt cSize, double* cBuf )
.. c:function:: ElError ElFiedlerDist_c( ElDistMatrix_c A, ElInt cSize, complex_float* cBuf )
.. c:function:: ElError ElFiedlerDist_z( ElDistMatrix_z A, ElInt cSize, complex_double* cBuf )

Forsythe
--------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Forsythe( Matrix<T>& J, Int n, T alpha, T lambda )
.. cpp:function:: void Forsythe( AbstractDistMatrix<T>& J, Int n, T alpha, T lambda )

C API
^^^^^

.. c:function:: ElError ElForsythe_i( ElMatrix_i J, ElInt n, ElInt alpha, ElInt lambda )
.. c:function:: ElError ElForsythe_s( ElMatrix_s J, ElInt n, float alpha, float lambda )
.. c:function:: ElError ElForsythe_d( ElMatrix_d J, ElInt n, double alpha, double lambda )
.. c:function:: ElError ElForsythe_c( ElMatrix_c J, ElInt n, complex_float alpha, complex_float lambda )
.. c:function:: ElError ElForsythe_z( ElMatrix_z J, ElInt n, complex_double alpha, complex_double lambda )
.. c:function:: ElError ElForsytheDist_i( ElDistMatrix_i J, ElInt n, ElInt alpha, ElInt lambda )
.. c:function:: ElError ElForsytheDist_s( ElDistMatrix_s J, ElInt n, float alpha, float lambda )
.. c:function:: ElError ElForsytheDist_d( ElDistMatrix_d J, ElInt n, double alpha, double lambda )
.. c:function:: ElError ElForsytheDist_c( ElDistMatrix_c J, ElInt n, complex_float alpha, complex_float lambda )
.. c:function:: ElError ElForsytheDist_z( ElDistMatrix_z J, ElInt n, complex_double alpha, complex_double lambda )

Fourier
-------
The :math:`n \times n` *Discrete Fourier Transform* (DFT) matrix, say :math:`A`, is given by

.. math::

   A(i,j) = \frac{1}{\sqrt{n}} e^{-2\pi i j / n}.

The following routines set the matrix ``A`` equal to the :math:`n \times n` 
DFT matrix.

C++ API
^^^^^^^

.. cpp:function:: void Fourier( Matrix<Complex<Real> >& A, Int n )
.. cpp:function:: void Fourier( AbstractDistMatrix<Complex<Real>>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElFourier_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElFourier_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElFourierDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElFourierDist_z( ElDistMatrix_z A, ElInt n )

GCDMatrix
---------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void GCDMatrix( Matrix<T>& G, Int m, Int n )
.. cpp:function:: void GCDMatrix( AbstractDistMatrix<T>& G, Int m, Int n )

C API
^^^^^

.. c:function:: ElError ElGCDMatrix_i( ElMatrix_i G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_s( ElMatrix_s G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_d( ElMatrix_d G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_c( ElMatrix_c G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_z( ElMatrix_z G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_i( ElDistMatrix_i G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_s( ElDistMatrix_s G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_d( ElDistMatrix_d G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_c( ElDistMatrix_c G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_z( ElDistMatrix_z G, ElInt m, ElInt n )

Gear
----
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Gear( Matrix<T>& G, Int n, Int s, Int t )
.. cpp:function:: void Gear( AbstractDistMatrix<T>& G, Int n, Int s, Int t )

C API
^^^^^

.. c:function:: ElError ElGear_i( ElMatrix_i G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_s( ElMatrix_s G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_d( ElMatrix_d G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_c( ElMatrix_c G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGear_z( ElMatrix_z G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_i( ElDistMatrix_i G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_s( ElDistMatrix_s G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_d( ElDistMatrix_d G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_c( ElDistMatrix_c G, ElInt n, ElInt s, ElInt t )
.. c:function:: ElError ElGearDist_z( ElDistMatrix_z G, ElInt n, ElInt s, ElInt t )

Golub/Klema/Stewart 
-------------------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void GKS( Matrix<F>& A, Int n )
.. cpp:function:: void GKS( AbstractDistMatrix<F>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElGKS_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElGKS_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElGKS_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElGKS_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElGKSDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElGKSDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElGKSDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElGKSDist_z( ElDistMatrix_z A, ElInt n )

Grcar
-----
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Grcar( Matrix<T>& A, Int n, Int k=3 )
.. cpp:function:: void Grcar( AbstractDistMatrix<T>& A, Int n, Int k=3 )

C API
^^^^^

.. c:function:: ElError ElGrcar_i( ElMatrix_i A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_s( ElMatrix_s A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_d( ElMatrix_d A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_c( ElMatrix_c A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcar_z( ElMatrix_z A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_i( ElDistMatrix_i A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_s( ElDistMatrix_s A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_d( ElDistMatrix_d A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_c( ElDistMatrix_c A, ElInt n, ElInt k )
.. c:function:: ElError ElGrcarDist_z( ElDistMatrix_z A, ElInt n, ElInt k )

Hankel
------
An :math:`m \times n` matrix :math:`A` is called a *Hankel matrix* if there 
exists a vector :math:`b` such that

.. math::

   A(i,j) = b(i+j).

The following routines create an :math:`m \times n` Hankel matrix from the 
generate vector, :math:`b`.

C++ API
^^^^^^^

.. cpp:function:: void Hankel( Matrix<T>& A, Int m, Int n, const std::vector<T>& b )
.. cpp:function:: void Hankel( AbstractDistMatrix<T>& A, Int m, Int n, const std::vector<T>& b )

C API
^^^^^

.. c:function:: ElError ElHankel_i( ElMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElHankel_s( ElMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElHankel_d( ElMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElHankel_c( ElMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElHankel_z( ElMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElHankelDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElHankelDist_s( ElDistMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElHankelDist_d( ElDistMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElHankelDist_c( ElDistMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElHankelDist_z( ElDistMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )

Hanowa
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Hanowa( Matrix<T>& A, Int n, T mu )
.. cpp:function:: void Hanowa( AbstractDistMatrix<T>& A, Int n, T mu )

C API
^^^^^

.. c:function:: ElError ElHanowa_i( ElMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElHanowa_s( ElMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElHanowa_d( ElMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElHanowa_c( ElMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElHanowa_z( ElMatrix_z A, ElInt n, complex_double mu )
.. c:function:: ElError ElHanowaDist_i( ElDistMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElHanowaDist_s( ElDistMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElHanowaDist_d( ElDistMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElHanowaDist_c( ElDistMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElHanowaDist_z( ElDistMatrix_z A, ElInt n, complex_double mu )

Helmholtz
---------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int n, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int n, F shift )

   1D Helmholtz: **TODO**

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int nx, Int ny, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int nx, Int ny, F shift )

   2D Helmholtz: **TODO**

.. cpp:function:: void Helmholtz( Matrix<F>& H, Int nx, Int ny, Int nz, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, Int nx, Int ny, Int nz, F shift )

   3D Helmholtz: **TODO**

C API
^^^^^

.. c:function:: ElError ElHelmholtz1D_s( ElMatrix_s H, ElInt nx, float shift )
.. c:function:: ElError ElHelmholtz1D_d( ElMatrix_d H, ElInt nx, double shift )
.. c:function:: ElError ElHelmholtz1D_c( ElMatrix_c H, ElInt nx, complex_float shift )
.. c:function:: ElError ElHelmholtz1D_z( ElMatrix_z H, ElInt nx, complex_double shift )
.. c:function:: ElError ElHelmholtz1DDist_s( ElDistMatrix_s H, ElInt nx, float shift )
.. c:function:: ElError ElHelmholtz1DDist_d( ElDistMatrix_d H, ElInt nx, double shift )
.. c:function:: ElError ElHelmholtz1DDist_c( ElDistMatrix_c H, ElInt nx, complex_float shift )
.. c:function:: ElError ElHelmholtz1DDist_z( ElDistMatrix_z H, ElInt nx, complex_double shift )

   1D Helmholtz: **TODO**

.. c:function:: ElError ElHelmholtz2D_s( ElMatrix_s H, ElInt nx, ElInt ny, float shift )
.. c:function:: ElError ElHelmholtz2D_d( ElMatrix_d H, ElInt nx, ElInt ny, double shift )
.. c:function:: ElError ElHelmholtz2D_c( ElMatrix_c H, ElInt nx, ElInt ny, complex_float shift )
.. c:function:: ElError ElHelmholtz2D_z( ElMatrix_z H, ElInt nx, ElInt ny, complex_double shift )
.. c:function:: ElError ElHelmholtz2DDist_s( ElDistMatrix_s H, ElInt nx, ElInt ny, float shift )
.. c:function:: ElError ElHelmholtz2DDist_d( ElDistMatrix_d H, ElInt nx, ElInt ny, double shift )
.. c:function:: ElError ElHelmholtz2DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, complex_float shift )
.. c:function:: ElError ElHelmholtz2DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, complex_double shift )

   2D Helmholtz: **TODO**

.. c:function:: ElError ElHelmholtz3D_s( ElMatrix_s H, ElInt nx, ElInt ny, ElInt nz, float shift )
.. c:function:: ElError ElHelmholtz3D_d( ElMatrix_d H, ElInt nx, ElInt ny, ElInt nz, double shift )
.. c:function:: ElError ElHelmholtz3D_c( ElMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float shift )
.. c:function:: ElError ElHelmholtz3D_z( ElMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double shift )
.. c:function:: ElError ElHelmholtz3DDist_s( ElDistMatrix_s H, ElInt nx, ElInt ny, ElInt nz, float shift )
.. c:function:: ElError ElHelmholtz3DDist_d( ElDistMatrix_d H, ElInt nx, ElInt ny, ElInt nz, double shift )
.. c:function:: ElError ElHelmholtz3DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float shift )
.. c:function:: ElError ElHelmholtz3DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double shift )

   3D Helmholtz: **TODO**

Helmholtz with PML
------------------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int n, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int n, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   1D Helmholtz: **TODO**

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int nx, Int ny, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int nx, Int ny, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   2D Helmholtz: **TODO**

.. cpp:function:: void HelmholtzPML( Matrix<Complex<Real>>& H, Int nx, Int ny, Int nz, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )
.. cpp:function:: void HelmholtzPML( AbstractDistMatrix<Complex<Real>>& H, Int nx, Int ny, Int nz, Complex<Real> shift, Int numPmlPoints, Real sigma, Real pmlExp )

   3D Helmholtz: **TODO**


C API
^^^^^

.. c:function:: ElError ElHelmholtzPML1D_c( ElMatrix_c H, ElInt nx, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML1D_z( ElMatrix_z H, ElInt nx, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML1DDist_c( ElDistMatrix_c H, ElInt nx, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML1DDist_z( ElDistMatrix_z H, ElInt nx, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   1D Helmholtz: **TODO**

.. c:function:: ElError ElHelmholtzPML2D_c( ElMatrix_c H, ElInt nx, ElInt ny, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML2D_z( ElMatrix_z H, ElInt nx, ElInt ny, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML2DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML2DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   2D Helmholtz: **TODO**

.. c:function:: ElError ElHelmholtzPML3D_c( ElMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML3D_z( ElMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )
.. c:function:: ElError ElHelmholtzPML3DDist_c( ElDistMatrix_c H, ElInt nx, ElInt ny, ElInt nz, complex_float omega, ElInt numPmlPoints, float sigma, float pmlExp )
.. c:function:: ElError ElHelmholtzPML3DDist_z( ElDistMatrix_z H, ElInt nx, ElInt ny, ElInt nz, complex_double omega, ElInt numPmlPoints, double sigma, double pmlExp )

   3D Helmholtz: **TODO**

Hermitian from EVD
------------------

C++ API
^^^^^^^

.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, Matrix<F>& A, const Matrix<Base<F>>& w, const Matrix<F>& Z )
.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, const AbstractDistMatrix<Base<F>>& w, const AbstractDistMatrix<F>& Z )

C API
^^^^^

.. c:function:: ElError ElHermitianFromEVD_s( ElUpperOrLower uplo, ElMatrix_s A, ElConstMatrix_s w, ElConstMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVD_d( ElUpperOrLower uplo, ElMatrix_d A, ElConstMatrix_d w, ElConstMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVD_c( ElUpperOrLower uplo, ElMatrix_c A, ElConstMatrix_s w, ElConstMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVD_z( ElUpperOrLower uplo, ElMatrix_z A, ElConstMatrix_d w, ElConstMatrix_z Z )
.. c:function:: ElError ElHermitianFromEVDDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElConstDistMatrix_s w, ElConstDistMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVDDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElConstDistMatrix_d w, ElConstDistMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVDDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElConstDistMatrix_s w, ElConstDistMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVDDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElConstDistMatrix_d w, ElConstDistMatrix_z Z )

Hilbert
-------
The Hilbert matrix of order :math:`n` is the :math:`n \times n` matrix where
entry :math:`(i,j)` is equal to :math:`1/(i+j+1)`.

The following routines generate the :math:`n \times n` Hilbert matrix ``A``.

C++ API
^^^^^^^

.. cpp:function:: void Hilbert( Matrix<F>& A, Int n )
.. cpp:function:: void Hilbert( AbstractDistMatrix<F>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElHilbert_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElHilbert_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElHilbert_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElHilbert_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElHilbertDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElHilbertDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElHilbertDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElHilbertDist_z( ElDistMatrix_z A, ElInt n )

HermitianFromEVD
----------------
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega=\text{diag}(w)` and :math:`w` is real.

C++ API
^^^^^^^

.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, Matrix<F>& A, const Matrix<Base<F>>& w, const Matrix<F>& Z )
.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, AbstractDistMatrix<F>& A, const AbstractDistMatrix<Base<F>>& w, const AbstractDistMatrix<F>& Z )

C API
^^^^^

.. c:function:: ElError ElHermitianFromEVD_s( ElUpperOrLower uplo, ElMatrix_s A, ElConstMatrix_s w, ElConstMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVD_d( ElUpperOrLower uplo, ElMatrix_d A, ElConstMatrix_d w, ElConstMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVD_c( ElUpperOrLower uplo, ElMatrix_c A, ElConstMatrix_s w, ElConstMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVD_z( ElUpperOrLower uplo, ElMatrix_z A, ElConstMatrix_d w, ElConstMatrix_z Z )
.. c:function:: ElError ElHermitianFromEVDDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElConstDistMatrix_s w, ElConstDistMatrix_s Z )
.. c:function:: ElError ElHermitianFromEVDDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElConstDistMatrix_d w, ElConstDistMatrix_d Z )
.. c:function:: ElError ElHermitianFromEVDDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElConstDistMatrix_s w, ElConstDistMatrix_c Z )
.. c:function:: ElError ElHermitianFromEVDDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElConstDistMatrix_d w, ElConstDistMatrix_z Z )

Identity
--------
The :math:`n \times n` *identity matrix* is simply defined by setting entry 
:math:`(i,j)` to one if :math:`i = j`, and zero otherwise. For various 
reasons, we generalize this definition to nonsquare, :math:`m \times n`, 
matrices.

C++ API
^^^^^^^

.. cpp:function:: void Identity( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Identity( AbstractDistMatrix<T>& A, Int m, Int n )

   Set the matrix ``A`` equal to the :math:`m \times n` identity(-like) matrix.

.. cpp:function:: void MakeIdentity( Matrix<T>& A )
.. cpp:function:: void MakeIdentity( AbstractDistMatrix<T>& A ) 

   Set the matrix ``A`` to be identity-like.

C API
^^^^^

.. c:function:: ElError ElIdentity_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentity_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElIdentityDist_z( ElDistMatrix_z A, ElInt m, ElInt n )

Jordan
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Jordan( Matrix<T>& J, Int n, T lambda )
.. cpp:function:: void Jordan( AbstractDistMatrix<T>& J, Int n, T lambda )

C API
^^^^^

.. c:function:: ElError ElJordan_i( ElMatrix_i J, ElInt n, ElInt lambda )
.. c:function:: ElError ElJordan_s( ElMatrix_s J, ElInt n, float lambda )
.. c:function:: ElError ElJordan_d( ElMatrix_d J, ElInt n, double lambda )
.. c:function:: ElError ElJordan_c( ElMatrix_c J, ElInt n, complex_float lambda )
.. c:function:: ElError ElJordan_z( ElMatrix_z J, ElInt n, complex_double lambda )
.. c:function:: ElError ElJordanDist_i( ElDistMatrix_i J, ElInt n, ElInt lambda )
.. c:function:: ElError ElJordanDist_s( ElDistMatrix_s J, ElInt n, float lambda )
.. c:function:: ElError ElJordanDist_d( ElDistMatrix_d J, ElInt n, double lambda )
.. c:function:: ElError ElJordanDist_c( ElDistMatrix_c J, ElInt n, complex_float lambda )
.. c:function:: ElError ElJordanDist_z( ElDistMatrix_z J, ElInt n, complex_double lambda )

Kahan
-----
For any pair :math:`(\phi,\zeta)` such that :math:`|\phi|^2+|\zeta|^2=1`, 
the corresponding :math:`n \times n` Kahan matrix is given by:

.. math::

   K = \text{diag}(1,\phi,\ldots,\phi^{n-1}) \begin{pmatrix} 
   1      & -\zeta & -\zeta & \cdots & -\zeta \\
   0      & 1      & -\zeta & \cdots & -\zeta \\
          & \ddots &        & \vdots & \vdots \\
   \vdots &        &        & 1      & -\zeta \\
   0      &        & \cdots &        & 1 \end{pmatrix}

C++ API
^^^^^^^

.. cpp:function:: void Kahan( Matrix<F>& A, Int n, F phi )
.. cpp:function:: void Kahan( AbstractDistMatrix<F>& A, Int n, F phi )

   Sets the matrix ``A`` equal to the :math:`n \times n` Kahan matrix with 
   the specified value for :math:`\phi`.

C API
^^^^^

.. c:function:: ElError ElKahan_s( ElMatrix_s A, ElInt n, float phi )
.. c:function:: ElError ElKahan_d( ElMatrix_d A, ElInt n, double phi )
.. c:function:: ElError ElKahan_c( ElMatrix_c A, ElInt n, complex_float phi )
.. c:function:: ElError ElKahan_z( ElMatrix_z A, ElInt n, complex_double phi )
.. c:function:: ElError ElKahanDist_s( ElDistMatrix_s A, ElInt n, float phi )
.. c:function:: ElError ElKahanDist_d( ElDistMatrix_d A, ElInt n, double phi )
.. c:function:: ElError ElKahanDist_c( ElDistMatrix_c A, ElInt n, complex_float phi )
.. c:function:: ElError ElKahanDist_z( ElDistMatrix_z A, ElInt n, complex_double phi )

KMS
---
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void KMS( Matrix<T>& K, Int n, T rho )
.. cpp:function:: void KMS( AbstractDistMatrix<T>& K, Int n, T rho )

C API
^^^^^

.. c:function:: ElError ElKMS_i( ElMatrix_i K, ElInt n, ElInt rho )
.. c:function:: ElError ElKMS_s( ElMatrix_s K, ElInt n, float rho )
.. c:function:: ElError ElKMS_d( ElMatrix_d K, ElInt n, double rho )
.. c:function:: ElError ElKMS_c( ElMatrix_c K, ElInt n, complex_float rho )
.. c:function:: ElError ElKMS_z( ElMatrix_z K, ElInt n, complex_double rho )
.. c:function:: ElError ElKMSDist_i( ElDistMatrix_i K, ElInt n, ElInt rho )
.. c:function:: ElError ElKMSDist_s( ElDistMatrix_s K, ElInt n, float rho )
.. c:function:: ElError ElKMSDist_d( ElDistMatrix_d K, ElInt n, double rho )
.. c:function:: ElError ElKMSDist_c( ElDistMatrix_c K, ElInt n, complex_float rho )
.. c:function:: ElError ElKMSDist_z( ElDistMatrix_z K, ElInt n, complex_double rho )

Laplacian
---------

C++ API
^^^^^^^

.. cpp:function:: void Laplacian( Matrix<F>& L, Int n )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int n )

   Discrete Laplacian over :math:`[0,1]` with n grid points

.. cpp:function:: void Laplacian( Matrix<F>& L, Int nx, Int ny )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int nx, Int ny )

   Discrete Laplacian over :math:`[0,1]^2` with :math:`n_x \times n_y`
   grid points

.. cpp:function:: void Laplacian( Matrix<F>& L, Int nx, Int ny, Int nz )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int nx, Int ny, Int nz )

   Discrete Laplacian over :math:`[0,1]^3` with 
   :math:`n_x \times n_y \times n_z` grid points

C API
^^^^^

.. c:function:: ElError ElLaplacian1D_s( ElMatrix_s L, ElInt n )
.. c:function:: ElError ElLaplacian1D_d( ElMatrix_d L, ElInt n )
.. c:function:: ElError ElLaplacian1D_c( ElMatrix_c L, ElInt n )
.. c:function:: ElError ElLaplacian1D_z( ElMatrix_z L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_s( ElDistMatrix_s L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_d( ElDistMatrix_d L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_c( ElDistMatrix_c L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_z( ElDistMatrix_z L, ElInt n )

   Discrete Laplacian over :math:`[0,1]` with `n` grid points

.. c:function:: ElError ElLaplacian2D_s( ElMatrix_s L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_d( ElMatrix_d L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_c( ElMatrix_c L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_z( ElMatrix_z L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_s( ElDistMatrix_s L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_d( ElDistMatrix_d L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_c( ElDistMatrix_c L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_z( ElDistMatrix_z L, ElInt nx, ElInt ny )

   Discrete Laplacian over :math:`[0,1]^2` with :math:`n_x \times n_y`
   grid points

Lauchli
-------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Lauchli( Matrix<T>& A, Int n, T mu )
.. cpp:function:: void Lauchli( AbstractDistMatrix<T>& A, Int n, T mu )

C API
^^^^^

.. c:function:: ElError ElLauchli_i( ElMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElLauchli_s( ElMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElLauchli_d( ElMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElLauchli_c( ElMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElLauchli_z( ElMatrix_z A, ElInt n, complex_double mu )
.. c:function:: ElError ElLauchliDist_i( ElDistMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElLauchliDist_s( ElDistMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElLauchliDist_d( ElDistMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElLauchliDist_c( ElDistMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElLauchliDist_z( ElDistMatrix_z A, ElInt n, complex_double mu )

Legendre
--------
The :math:`n \times n` tridiagonal Jacobi matrix associated with the Legendre
polynomials. Its main diagonal is zero, and the off-diagonal terms are given 
by 

.. math::

   \beta_j = \frac{1}{2}\left(1-(2(j+1))^{-2}\right)^{-1/2},

where :math:`\beta_j` connects the :math:`j`'th degree of freedom to the 
:math:`j+1`'th degree of freedom, counting from zero.
The eigenvalues of this matrix lie in :math:`[-1,1]` and are the locations for 
Gaussian quadrature of order :math:`n`. The corresponding weights may be found 
by doubling the square of the first entry of the corresponding normalized 
eigenvector.

C++ API
^^^^^^^

.. cpp:function:: void Legendre( Matrix<F>& A, Int n )
.. cpp:function:: void Legendre( AbstractDistMatrix<F>& A, Int n )

   Sets the matrix ``A`` equal to the :math:`n \times n` Jacobi matrix.

C API
^^^^^

.. c:function:: ElError ElLegendre_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElLegendre_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElLegendre_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElLegendre_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElLegendreDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElLegendreDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElLegendreDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElLegendreDist_z( ElDistMatrix_z A, ElInt n )

Lehmer
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Lehmer( Matrix<F>& L, Int n )
.. cpp:function:: void Lehmer( AbstractDistMatrix<F>& L, Int n )

C API
^^^^^

.. c:function:: ElError ElLehmer_s( ElMatrix_s L, ElInt n )
.. c:function:: ElError ElLehmer_d( ElMatrix_d L, ElInt n )
.. c:function:: ElError ElLehmer_c( ElMatrix_c L, ElInt n )
.. c:function:: ElError ElLehmer_z( ElMatrix_z L, ElInt n )
.. c:function:: ElError ElLehmerDist_s( ElDistMatrix_s L, ElInt n )
.. c:function:: ElError ElLehmerDist_d( ElDistMatrix_d L, ElInt n )
.. c:function:: ElError ElLehmerDist_c( ElDistMatrix_c L, ElInt n )
.. c:function:: ElError ElLehmerDist_z( ElDistMatrix_z L, ElInt n )

Lotkin
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Lotkin( Matrix<F>& A, Int n )
.. cpp:function:: void Lotkin( AbstractDistMatrix<F>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElLotkin_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElLotkin_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElLotkin_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElLotkin_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElLotkinDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElLotkinDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElLotkinDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElLotkinDist_z( ElDistMatrix_z A, ElInt n )

MinIJ
-----
Return an :math:`n \times n` matrix with the :math:`(i,j)` entry equal to
:math:`\text{min}(i+1,j+1)` (counting from zero).

C++ API
^^^^^^^

.. cpp:function:: void MinIJ( Matrix<T>& M, Int n )
.. cpp:function:: void MinIJ( AbstractDistMatrix<T>& M, Int n )

C API
^^^^^

.. c:function:: ElError ELMinIJ_i( ElMatrix_i M, ElInt n )
.. c:function:: ElError ELMinIJ_s( ElMatrix_s M, ElInt n )
.. c:function:: ElError ELMinIJ_d( ElMatrix_d M, ElInt n )
.. c:function:: ElError ELMinIJ_c( ElMatrix_c M, ElInt n )
.. c:function:: ElError ELMinIJ_z( ElMatrix_z M, ElInt n )
.. c:function:: ElError ELMinIJDist_i( ElDistMatrix_i M, ElInt n )
.. c:function:: ElError ELMinIJDist_s( ElDistMatrix_s M, ElInt n )
.. c:function:: ElError ELMinIJDist_d( ElDistMatrix_d M, ElInt n )
.. c:function:: ElError ELMinIJDist_c( ElDistMatrix_c M, ElInt n )
.. c:function:: ElError ELMinIJDist_z( ElDistMatrix_z M, ElInt n )

NormalFromEVD
-------------
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega` is a complex diagonal matrix.

C++ API
^^^^^^^

.. cpp:function:: void NormalFromEVD( Matrix<Complex<Real> >& A, const Matrix<Complex<Real> >& w, const Matrix<Complex<Real> >& Z )
.. cpp:function:: void NormalFromEVD( AbstractDistMatrix<Complex<Real> >& A, const AbstractDistMatrix<Complex<Real>>& w, const AbstractDistMatrix<Complex<Real> >& Z )

   The diagonal entries of :math:`\Omega` are given by the vector :math:`w`.

C API
^^^^^

.. c:function:: ElError ElNormalFromEVD_c( ElMatrix_c A, ElConstMatrix_c w, ElConstMatrix_c Z )
.. c:function:: ElError ElNormalFromEVD_z( ElMatrix_z A, ElConstMatrix_z w, ElConstMatrix_z Z )
.. c:function:: ElError ElNormalFromEVDDist_c( ElDistMatrix_c A, ElConstDistMatrix_c w, ElConstDistMatrix_c Z )
.. c:function:: ElError ElNormalFromEVDDist_z( ElDistMatrix_z A, ElConstDistMatrix_z w, ElConstDistMatrix_z Z )

Ones
----
Create an :math:`m \times n` matrix of all ones.

C++ API
^^^^^^^

.. cpp:function:: void Ones( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Ones( AbstractDistMatrix<T>& A, Int m, Int n )

   Set the matrix ``A`` to be an :math:`m \times n` matrix of all ones.

C API
^^^^^

.. c:function:: ElError ElOnes_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElOnes_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElOnesDist_z( ElDistMatrix_z A, ElInt m, ElInt n )

OneTwoOne
---------
A "1-2-1" matrix is tridiagonal with a diagonal of all twos and sub- and 
super-diagonals of all ones.

C++ API
^^^^^^^

.. cpp:function:: void OneTwoOne( Matrix<T>& A, Int n )
.. cpp:function:: void OneTwoOne( AbstractDistMatrix<T>& A, Int n )

   Set ``A`` to a :math:`n \times n` "1-2-1" matrix.

C API
^^^^^

.. c:function:: ElError ElOneTwoOne_i( ElMatrix_i A, ElInt n )
.. c:function:: ElError ElOneTwoOne_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElOneTwoOne_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElOneTwoOne_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElOneTwoOne_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_i( ElDistMatrix_i A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_z( ElDistMatrix_z A, ElInt n )

Parter
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Parter( Matrix<F>& P, Int n )
.. cpp:function:: void Parter( AbstractDistMatrix<F>& P, Int n )

C API
^^^^^

.. c:function:: ElError ElParter_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElParter_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElParter_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElParter_z( ElMatrix_z P, ElInt n )
.. c:function:: ElError ElParterDist_s( ElDistMatrix_s P, ElInt n )
.. c:function:: ElError ElParterDist_d( ElDistMatrix_d P, ElInt n )
.. c:function:: ElError ElParterDist_c( ElDistMatrix_c P, ElInt n )
.. c:function:: ElError ElParterDist_z( ElDistMatrix_z P, ElInt n )

Pei
---
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Pei( Matrix<T>& P, Int n, T alpha )
.. cpp:function:: void Pei( AbstractDistMatrix<T>& P, Int n, T alpha )

C API
^^^^^

.. c:function:: ElError ElPei_i( ElMatrix_i P, ElInt n, ElInt alpha )
.. c:function:: ElError ElPei_s( ElMatrix_s P, ElInt n, float alpha )
.. c:function:: ElError ElPei_d( ElMatrix_d P, ElInt n, double alpha )
.. c:function:: ElError ElPei_c( ElMatrix_c P, ElInt n, complex_float alpha )
.. c:function:: ElError ElPei_z( ElMatrix_z P, ElInt n, complex_double alpha )
.. c:function:: ElError ElPeiDist_i( ElDistMatrix_i P, ElInt n, ElInt alpha )
.. c:function:: ElError ElPeiDist_s( ElDistMatrix_s P, ElInt n, float alpha )
.. c:function:: ElError ElPeiDist_d( ElDistMatrix_d P, ElInt n, double alpha )
.. c:function:: ElError ElPeiDist_c( ElDistMatrix_c P, ElInt n, complex_float alpha )
.. c:function:: ElError ElPeiDist_z( ElDistMatrix_z P, ElInt n, complex_double alpha )

Redheffer
---------
Return the :math:`n \times n` matrix with entry :math:`(i,j)` (counting from
zero) set to

.. math::

   \begin{array}{ll} 
     1, & j = 0, \text{ or } (j+1) \bmod (i+1) = 0, \\
     0, & \text{otherwise}.
   \end{array}

C++ API
^^^^^^^

.. cpp:function:: void Redheffer( Matrix<T>& R, Int n )
.. cpp:function:: void Redheffer( AbstractDistMatrix<T>& R, Int n )

C API
^^^^^

.. c:function:: ElError ElRedheffer_i( ElMatrix_i R, ElInt n )
.. c:function:: ElError ElRedheffer_s( ElMatrix_s R, ElInt n )
.. c:function:: ElError ElRedheffer_d( ElMatrix_d R, ElInt n )
.. c:function:: ElError ElRedheffer_c( ElMatrix_c R, ElInt n )
.. c:function:: ElError ElRedheffer_z( ElMatrix_z R, ElInt n )
.. c:function:: ElError ElRedhefferDist_i( ElDistMatrix_i R, ElInt n )
.. c:function:: ElError ElRedhefferDist_s( ElDistMatrix_s R, ElInt n )
.. c:function:: ElError ElRedhefferDist_d( ElDistMatrix_d R, ElInt n )
.. c:function:: ElError ElRedhefferDist_c( ElDistMatrix_c R, ElInt n )
.. c:function:: ElError ElRedhefferDist_z( ElDistMatrix_z R, ElInt n )

Riemann
-------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Riemann( Matrix<T>& R, Int n )
.. cpp:function:: void Riemann( AbstractDistMatrix<T>& R, Int n )

C API
^^^^^

.. c:function:: ElError ElRiemann_i( ElMatrix_i R, ElInt n )
.. c:function:: ElError ElRiemann_s( ElMatrix_s R, ElInt n )
.. c:function:: ElError ElRiemann_d( ElMatrix_d R, ElInt n )
.. c:function:: ElError ElRiemann_c( ElMatrix_c R, ElInt n )
.. c:function:: ElError ElRiemann_z( ElMatrix_z R, ElInt n )
.. c:function:: ElError ElRiemannDist_i( ElDistMatrix_i R, ElInt n )
.. c:function:: ElError ElRiemannDist_s( ElDistMatrix_s R, ElInt n )
.. c:function:: ElError ElRiemannDist_d( ElDistMatrix_d R, ElInt n )
.. c:function:: ElError ElRiemannDist_c( ElDistMatrix_c R, ElInt n )
.. c:function:: ElError ElRiemannDist_z( ElDistMatrix_z R, ElInt n )

Riffle
------
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void Riffle( Matrix<F>& P, Int n )
.. cpp:function:: void Riffle( AbstractDistMatrix<F>& P, Int n )
.. cpp:function:: void Riffle( AbstractBlockDistMatrix<F>& P, Int n )

   Return the :math:`n \times n` transition matrix.

.. cpp:function:: void Riffle( Matrix<F>& P, Matrix<F>& PInf, Int n )
.. cpp:function:: void Riffle( AbstractDistMatrix<F>& P, AbstractDistMatrix<F>& PInf, Int n )
.. cpp:function:: void Riffle( AbstractBlockDistMatrix<F>& P, AbstractBlockDistMatrix<F>& PInf, Int n )

   Return both the :math:`n \times n` transition matrix and its stationary 
   distribution (as a square matrix with identical rows).

.. cpp:function:: void RiffleStationary( Matrix<F>& PInf, Int n )
.. cpp:function:: void RiffleStationary( AbstractDistMatrix<F>& PInf, Int n )
.. cpp:function:: void RiffleStationary( AbstractBlockDistMatrix<F>& PInf, Int n )

   Return the stationary distribution of the :math:`n \times n` system as
   a square matrix with identical rows.

.. cpp:function:: void RiffleDecay( Matrix<F>& A, Int n )
.. cpp:function:: void RiffleDecay( AbstractDistMatrix<F>& A, Int n )

   Return the transition matrix with its stationary distribution subtracted
   from each row.

C API
^^^^^

.. c:function:: ElError ElRiffle_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElRiffle_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElRiffle_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElRiffle_z( ElMatrix_z P, ElInt n )
.. c:function:: ElError ElRiffleDist_s( ElDistMatrix_s P, ElInt n )
.. c:function:: ElError ElRiffleDist_d( ElDistMatrix_d P, ElInt n )
.. c:function:: ElError ElRiffleDist_c( ElDistMatrix_c P, ElInt n )
.. c:function:: ElError ElRiffleDist_z( ElDistMatrix_z P, ElInt n )

   Return the :math:`n \times n` transition matrix.

.. c:function:: ElError ElRiffleStationary_s( ElMatrix_s PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_d( ElMatrix_d PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_c( ElMatrix_c PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_z( ElMatrix_z PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_s( ElDistMatrix_s PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_d( ElDistMatrix_d PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_c( ElDistMatrix_c PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_z( ElDistMatrix_z PInf, ElInt n )

   Return the stationary distribution of the :math:`n \times n` system as a
   square matrix with identical rows.

.. c:function:: ElError ElRiffleDecay_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElRiffleDecay_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElRiffleDecay_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElRiffleDecay_z( ElMatrix_z A, ElInt n )

   Return the transition matrix with its stationary distribution subtracted
   from each row.

Ris
---
Return the :math:`n \times n` matrix with the :math:`(i,j)` entry
(counting from zero) set to

.. math::

   A(i,j) = \frac{1}{2(n-i-j)-1}.

C++ API
^^^^^^^

.. cpp:function:: void Ris( Matrix<F>& R, Int n )
.. cpp:function:: void Ris( AbstractDistMatrix<F>& R, Int n )

C API
^^^^^

.. c:function:: ElError ElRis_s( ElMatrix_s R, ElInt n )
.. c:function:: ElError ElRis_d( ElMatrix_d R, ElInt n )
.. c:function:: ElError ElRis_c( ElMatrix_c R, ElInt n )
.. c:function:: ElError ElRis_z( ElMatrix_z R, ElInt n )
.. c:function:: ElError ElRisDist_s( ElDistMatrix_s R, ElInt n )
.. c:function:: ElError ElRisDist_d( ElDistMatrix_d R, ElInt n )
.. c:function:: ElError ElRisDist_c( ElDistMatrix_c R, ElInt n )
.. c:function:: ElError ElRisDist_z( ElDistMatrix_z R, ElInt n )

Toeplitz
--------
An :math:`m \times n` matrix is *Toeplitz* if there exists a vector :math:`b` such that, for each entry :math:`A(i,j)` of :math:`A`,

.. math::

   A(i,j) = b(i-j+(n-1)).


C++ API
^^^^^^^

.. cpp:function:: void Toeplitz( Matrix<T>& A, Int m, Int n, const std::vector<T>& b )
.. cpp:function:: void Toeplitz( AbstractDistMatrix<T>& A, Int m, Int n, const std::vector<T>& b )

C API
^^^^^

.. c:function:: ElError ElToeplitz_i( ElMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElToeplitz_s( ElMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElToeplitz_d( ElMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElToeplitz_c( ElMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElToeplitz_z( ElMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )
.. c:function:: ElError ElToeplitzDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt aSize, ElInt* aBuf )
.. c:function:: ElError ElToeplitzDist_s( ElDistMatrix_s A, ElInt m, ElInt n, ElInt aSize, float* aBuf )
.. c:function:: ElError ElToeplitzDist_d( ElDistMatrix_d A, ElInt m, ElInt n, ElInt aSize, double* aBuf )
.. c:function:: ElError ElToeplitzDist_c( ElDistMatrix_c A, ElInt m, ElInt n, ElInt aSize, complex_float* aBuf )
.. c:function:: ElError ElToeplitzDist_z( ElDistMatrix_z A, ElInt m, ElInt n, ElInt aSize, complex_double* aBuf )

Trefethen
---------

C++ API
^^^^^^^

.. cpp:function:: void Trefethen( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Trefethen( AbstractDistMatrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Trefethen( AbstractBlockDistMatrix<Complex<Real>>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElTrefethen_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElTrefethen_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElTrefethenDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElTrefethenDist_z( ElDistMatrix_z A, ElInt n )

Triangle
--------

C++ API
^^^^^^^

.. cpp:function:: void Triangle( Matrix<F>& A, Int n )
.. cpp:function:: void Triangle( AbstractDistMatrix<F>& A, Int n )
.. cpp:function:: void Triangle( AbstractBlockDistMatrix<F>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElTriangle_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElTriangle_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElTriangle_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElTriangle_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElTriangleDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElTriangleDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElTriangleDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElTriangleDist_z( ElDistMatrix_z A, ElInt n )

TriW
----
**TODO**

C++ API
^^^^^^^

.. cpp:function:: void TriW( Matrix<T>& A, Int m, Int n, T alpha, Int k )
.. cpp:function:: void TriW( AbstractDistMatrix<T>& A, Int m, Int n, T alpha, Int k )

C API
^^^^^

.. c:function:: ElError ElTriW_i( ElMatrix_i A, ElInt m, ElInt n, ElInt alpha, ElInt k )
.. c:function:: ElError ElTriW_s( ElMatrix_s A, ElInt m, ElInt n, float alpha, ElInt k )
.. c:function:: ElError ElTriW_d( ElMatrix_d A, ElInt m, ElInt n, double alpha, ElInt k )
.. c:function:: ElError ElTriW_c( ElMatrix_c A, ElInt m, ElInt n, complex_float alpha, ElInt k )
.. c:function:: ElError ElTriW_z( ElMatrix_z A, ElInt m, ElInt n, complex_double alpha, ElInt k )
.. c:function:: ElError ElTriWDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt alpha, ElInt k )
.. c:function:: ElError ElTriWDist_s( ElDistMatrix_s A, ElInt m, ElInt n, float alpha, ElInt k )
.. c:function:: ElError ElTriWDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double alpha, ElInt k )
.. c:function:: ElError ElTriWDist_c( ElDistMatrix_c A, ElInt m, ElInt n, complex_float alpha, ElInt k )
.. c:function:: ElError ElTriWDist_z( ElDistMatrix_z A, ElInt m, ElInt n, complex_double alpha, ElInt k )

Walsh
-----
The Walsh matrix of order :math:`k` is a :math:`2^k \times 2^k` matrix, where

.. math::

   W_1 = \left(\begin{array}{cc} 1 & 1 \\ 1 & -1 \end{array}\right),

and 

.. math::

   W_k = \left(\begin{array}{cc} W_{k-1} & W_{k-1} \\ W_{k-1} & -W_{k-1} 
               \end{array}\right).

A *binary* Walsh matrix changes the bottom-right entry of :math:`W_1` from 
:math:`-1` to :math:`0`.

C++ API
^^^^^^^

.. cpp:function:: void Walsh( Matrix<T>& W, Int k, bool binary=false )
.. cpp:function:: void Walsh( AbstractDistMatrix<T>& W, Int k, bool binary=false )

C API
^^^^^

.. c:function:: ElError ElWalsh_i( ElMatrix_i W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_s( ElMatrix_s W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_d( ElMatrix_d W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_c( ElMatrix_c W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_z( ElMatrix_z W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_i( ElDistMatrix_i W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_s( ElDistMatrix_s W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_d( ElDistMatrix_d W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_c( ElDistMatrix_c W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_z( ElDistMatrix_z W, ElInt k, bool binary )

Whale
-----

C++ API
^^^^^^^

.. cpp:function:: void Whale( Matrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Whale( AbstractDistMatrix<Complex<Real>>& A, Int n )
.. cpp:function:: void Whale( AbstractBlockDistMatrix<Complex<Real>>& A, Int n )

C API
^^^^^

.. c:function:: ElError ElWhale_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElWhale_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElWhaleDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElWhaleDist_z( ElDistMatrix_z A, ElInt n )

Wilkinson
---------
A *Wilkinson matrix* of order :math:`k` is a tridiagonal matrix with diagonal

.. math::

   [k,k-1,k-2,...,1,0,1,...,k-2,k-1,k],

and sub- and super-diagonals of all ones.

C++ API
^^^^^^^

.. cpp:function:: void Wilkinson( Matrix<T>& W, Int k )
.. cpp:function:: void Wilkinson( AbstractDistMatrix<T>& W, Int k )


C API
^^^^^

.. c:function:: ElError ElWilkinson_i( ElMatrix_i W, ElInt k )
.. c:function:: ElError ElWilkinson_s( ElMatrix_s W, ElInt k )
.. c:function:: ElError ElWilkinson_d( ElMatrix_d W, ElInt k )
.. c:function:: ElError ElWilkinson_c( ElMatrix_c W, ElInt k )
.. c:function:: ElError ElWilkinson_z( ElMatrix_z W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_i( ElDistMatrix_i W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_s( ElDistMatrix_s W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_d( ElDistMatrix_d W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_c( ElDistMatrix_c W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_z( ElDistMatrix_z W, ElInt k )

Zeros
-----
Create an :math:`m \times n` matrix of all zeros.

C++ API
^^^^^^^

.. cpp:function:: void Zeros( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Zeros( AbstractDistMatrix<T>& A, Int m, Int n )

C API
^^^^^

.. c:function:: ElError ElZeros_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElZeros_z( ElMatrix_z A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElZerosDist_z( ElDistMatrix_z A, ElInt m, ElInt n )
