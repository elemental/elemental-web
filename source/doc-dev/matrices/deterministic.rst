Deterministic
=============

Cauchy
------
An :math:`m \times n` matrix :math:`A` is called *Cauchy* if there exist 
vectors :math:`x` and :math:`y` such that 

.. math::

   \alpha_{i,j} = \frac{1}{\chi_i - \eta_j},

where :math:`\chi_i` is the :math:`i`'th entry of :math:`x` and :math:`\eta_j`
is the :math:`j`'th entry of :math:`y`.

.. cpp:function:: void Cauchy( Matrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void Cauchy( AbstractDistMatrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )

   Generate a Cauchy matrix using the defining vectors, :math:`x` and :math:`y`. 

Cauchy-like
-----------
An :math:`m \times n` matrix :math:`A` is called *Cauchy-like* if there exist 
vectors :math:`r`, :math:`s`, :math:`x`, and :math:`y` such that 

.. math::

   \alpha_{i,j} = \frac{\rho_i \psi_j}{\chi_i - \eta_j},

where :math:`\rho_i` is the :math:`i`'th entry of :math:`r`, :math:`\psi_j` is the :math:`j`'th 
entry of :math:`s`, :math:`\chi_i` is the :math:`i`'th entry of :math:`x`, and :math:`\eta_j`
is the :math:`j`'th entry of :math:`y`.

.. cpp:function:: void CauchyLike( Matrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void CauchyLike( AbstractDistMatrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )

   Generate a Cauchy-like matrix using the defining vectors: :math:`r`, :math:`s`, :math:`x`, and :math:`y`.

Circulant
---------
An :math:`n \times n` matrix :math:`A` is called *circulant* if there exists a vector :math:`b` 
such that 

.. math::

   \alpha_{i,j} = \beta_{(i-j) \bmod n},

where :math:`\beta_k` is the :math:`k`'th entry of vector :math:`b`.

.. cpp:function:: void Circulant( Matrix<T>& A, const std::vector<T>& a )
.. cpp:function:: void Circulant( AbstractDistMatrix<T>& A, const std::vector<T>& a )

   Generate a circulant matrix using the vector ``a``.

Diagonal
--------
An :math:`n \times n` matrix :math:`A` is called *diagonal* if each entry :math:`(i,j)`, where 
:math:`i \neq j`, is :math:`0`. They are therefore defined by the *diagonal* values, where 
:math:`i = j`.

.. cpp:function:: void Diagonal( Matrix<T>& D, const std::vector<T>& d )
.. cpp:function:: void Diagonal( AbstractDistMatrix<T>& D, const std::vector<T>& d )

   Construct a diagonal matrix from the vector of diagonal values, :math:`d`.

Egorov
------
Sets :math:`A` to an :math:`n \times n` matrix with the :math:`(i,j)` entry
equal to

.. math::

   \exp(i \phi(i,j)).

.. cpp:function:: void Egorov( Matrix<Complex<Real> >& A, std::function<Real(Int,Int)> phi, int n )
.. cpp:function:: void Egorov( AbstractDistMatrix<Complex<Real>>& A, std::function<Real(Int,Int)> phi, int n )

Extended Kahan
--------------
**TODO**

.. cpp:function:: void ExtendedKahan( Matrix<F>& A, int k, Base<F> phi, Base<F> mu )
.. cpp:function:: void ExtendedKahan( AbstractDistMatrix<F>& A, int k, Base<F> phi, Base<F> mu )

Fiedler
-------
**TODO**

.. cpp:function:: void Fiedler( Matrix<F>& A, const std::vector<F>& c )
.. cpp:function:: void Fiedler( AbstractDistMatrix<F>& A, const std::vector<F>& c )

Forsythe
--------
**TODO**

.. cpp:function:: void Forsythe( Matrix<T>& J, int n, T alpha, T lambda )
.. cpp:function:: void Forsythe( AbstractDistMatrix<T>& J, int n, T alpha, T lambda )

Fourier
-------
The :math:`n \times n` *Discrete Fourier Transform* (DFT) matrix, say :math:`A`, is given by

.. math::

   \alpha_{i,j} = \frac{e^{-2\pi i j / n}}{\sqrt{n}}.

.. cpp:function:: void Fourier( Matrix<Complex<Real> >& A, int n )
.. cpp:function:: void Fourier( AbstractDistMatrix<Complex<Real>>& A, int n )

   Set the matrix ``A`` equal to the :math:`n \times n` DFT matrix.

GCDMatrix
---------
**TODO**

.. cpp:function:: void GCDMatrix( Matrix<T>& G, int m, int n )
.. cpp:function:: void GCDMatrix( AbstractDistMatrix<T>& G, int m, int n )

Gear
----
**TODO**

.. cpp:function:: void Gear( Matrix<T>& G, int n, int s, int t )
.. cpp:function:: void Gear( AbstractDistMatrix<T>& G, int n, int s, int t )

Golub/Klema/Stewart 
-------------------
**TODO**

.. cpp:function:: void GKS( Matrix<F>& A, int n )
.. cpp:function:: void GKS( AbstractDistMatrix<F>& A, int n )

Grcar
-----
**TODO**

.. cpp:function:: void Grcar( Matrix<T>& A, int n, int k=3 )
.. cpp:function:: void Grcar( AbstractDistMatrix<T>& A, int n, int k=3 )

Hankel
------
An :math:`m \times n` matrix :math:`A` is called a *Hankel matrix* if there 
exists a vector :math:`b` such that

.. math::

   \alpha_{i,j} = \beta_{i+j},

where :math:`\alpha_{i,j}` is the :math:`(i,j)` entry of :math:`A` and 
:math:`\beta_k` is the :math:`k`'th entry of the vector :math:`b`.

.. cpp:function:: void Hankel( Matrix<T>& A, int m, int n, const std::vector<T>& b )
.. cpp:function:: void Hankel( AbstractDistMatrix<T>& A, int m, int n, const std::vector<T>& b )

   Create an :math:`m \times n` Hankel matrix from the generate vector, 
   :math:`b`.

Hanowa
------
**TODO**

.. cpp:function:: void Hanowa( Matrix<T>& A, int n, T mu )
.. cpp:function:: void Hanowa( AbstractDistMatrix<T>& A, int n, T mu )

Helmholtz
---------
**TODO**

.. cpp:function:: void Helmholtz( Matrix<F>& H, int n, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, int n, F shift )

   1D Helmholtz: **TODO**

.. cpp:function:: void Helmholtz( Matrix<F>& H, int nx, int ny, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, int nx, int ny, F shift )

   2D Helmholtz: **TODO**

.. cpp:function:: void Helmholtz( Matrix<F>& H, int nx, int ny, int nz, F shift )
.. cpp:function:: void Helmholtz( AbstractDistMatrix<F>& H, int nx, int ny, int nz, F shift )

   3D Helmholtz: **TODO**

Hilbert
-------
The Hilbert matrix of order :math:`n` is the :math:`n \times n` matrix where
entry :math:`(i,j)` is equal to :math:`1/(i+j+1)`.

.. cpp:function:: void Hilbert( Matrix<F>& A, int n )
.. cpp:function:: void Hilbert( AbstractDistMatrix<F>& A, int n )

   Generate the :math:`n \times n` Hilbert matrix ``A``.

HermitianFromEVD
----------------
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega` is a real diagonal matrix.

.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, Matrix<F>& A, const Matrix<Base<F>>& w, const Matrix<F>& Z )
.. cpp:function:: void HermitianFromEVD( UpperOrLower uplo, DistMatrix<F>& A, const DistMatrix<Base<F>,VR,STAR>& w, const DistMatrix<F>& Z )

   The diagonal entries of :math:`\Omega` are given by the vector :math:`w`.

Identity
--------
The :math:`n \times n` *identity matrix* is simply defined by setting entry 
:math:`(i,j)` to one if :math:`i = j`, and zero otherwise. For various 
reasons, we generalize this definition to nonsquare, :math:`m \times n`, 
matrices.

.. cpp:function:: void Identity( Matrix<T>& A, int m, int n )
.. cpp:function:: void Identity( AbstractDistMatrix<T>& A, int m, int n )

   Set the matrix ``A`` equal to the :math:`m \times n` identity(-like) matrix.

.. cpp:function:: void MakeIdentity( Matrix<T>& A )
.. cpp:function:: void MakeIdentity( AbstractDistMatrix<T>& A ) 

   Set the matrix ``A`` to be identity-like.

Jordan
------
**TODO**

.. cpp:function:: void Jordan( Matrix<T>& J, int n, T lambda )
.. cpp:function:: void Jordan( AbstractDistMatrix<T>& J, int n, T lambda )

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

.. cpp:function:: void Kahan( Matrix<F>& A, int n, F phi )
.. cpp:function:: void Kahan( AbstractDistMatrix<F>& A, int n, F phi )

   Sets the matrix ``A`` equal to the :math:`n \times n` Kahan matrix with 
   the specified value for :math:`\phi`.

KMS
---
**TODO**

.. cpp:function:: void KMS( Matrix<T>& K, int n, T rho )
.. cpp:function:: void KMS( AbstractDistMatrix<T>& K, int n, T rho )

Laplacian
---------
**TODO**

.. cpp:function:: void Laplacian( Matrix<F>& L, int n )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, int n )

   1D Laplacian: **TODO**

.. cpp:function:: void Laplacian( Matrix<F>& L, int nx, int ny )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, int nx, int ny )

   2D Laplacian: **TODO**

.. cpp:function:: void Laplacian( Matrix<F>& L, int nx, int ny, int nz )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, int nx, int ny, int nz )

   3D Laplacian: **TODO**

Lauchli
-------
**TODO**

.. cpp:function:: void Lauchli( Matrix<T>& A, int n, T mu )
.. cpp:function:: void Lauchli( AbstractDistMatrix<T>& A, int n, T mu )

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

.. cpp:function:: void Legendre( Matrix<F>& A, int n )
.. cpp:function:: void Legendre( AbstractDistMatrix<F>& A, int n )

   Sets the matrix ``A`` equal to the :math:`n \times n` Jacobi matrix.

Lehmer
------
**TODO**

.. cpp:function:: void Lehmer( Matrix<F>& L, int n )
.. cpp:function:: void Lehmer( AbstractDistMatrix<F>& L, int n )

Lotkin
------
**TODO**

.. cpp:function:: void Lotkin( Matrix<F>& A, int n )
.. cpp:function:: void Lotkin( AbstractDistMatrix<F>& A, int n )

MinIJ
-----
**TODO**

.. cpp:function:: void MinIJ( Matrix<T>& M, int n )
.. cpp:function:: void MinIJ( AbstractDistMatrix<T>& M, int n )

NormalFromEVD
-------------
Form

.. math::

   A := Z \Omega Z^H,

where :math:`\Omega` is a complex diagonal matrix.

.. cpp:function:: void NormalFromEVD( Matrix<Complex<Real> >& A, const Matrix<Complex<Real> >& w, const Matrix<Complex<Real> >& Z )
.. cpp:function:: void NormalFromEVD( DistMatrix<Complex<Real> >& A, const DistMatrix<Complex<Real>,VR,STAR>& w, const DistMatrix<Complex<Real> >& Z )

   The diagonal entries of :math:`\Omega` are given by the vector :math:`w`.

Ones
----
Create an :math:`m \times n` matrix of all ones.

.. cpp:function:: void Ones( Matrix<T>& A, int m, int n )
.. cpp:function:: void Ones( AbstractDistMatrix<T>& A, int m, int n )

   Set the matrix ``A`` to be an :math:`m \times n` matrix of all ones.

OneTwoOne
---------
A "1-2-1" matrix is tridiagonal with a diagonal of all twos and sub- and 
super-diagonals of all ones.

.. cpp:function:: void OneTwoOne( Matrix<T>& A, int n )
.. cpp:function:: void OneTwoOne( AbstractDistMatrix<T>& A, int n )

   Set ``A`` to a :math:`n \times n` "1-2-1" matrix.

Parter
------
**TODO**

.. cpp:function:: void Parter( Matrix<F>& P, int n )
.. cpp:function:: void Parter( AbstractDistMatrix<F>& P, int n )

Pei
---
**TODO**

.. cpp:function:: void Pei( Matrix<T>& P, int n, T alpha )
.. cpp:function:: void Pei( AbstractDistMatrix<T>& P, int n, T alpha )

Redheffer
---------
**TODO**

.. cpp:function:: void Redheffer( Matrix<T>& R, int n )
.. cpp:function:: void Redheffer( AbstractDistMatrix<T>& R, int n )

Riemann
-------
**TODO**

.. cpp:function:: void Riemann( Matrix<T>& R, int n )
.. cpp:function:: void Riemann( AbstractDistMatrix<T>& R, int n )

Ris
---
**TODO**

.. cpp:function:: void Ris( Matrix<F>& R, int n )
.. cpp:function:: void Ris( AbstractDistMatrix<F>& R, int n )

Toeplitz
--------
An :math:`m \times n` matrix is *Toeplitz* if there exists a vector :math:`b` such that, for each entry :math:`\alpha_{i,j}` of :math:`A`,

.. math::

   \alpha_{i,j} = \beta_{i-j+(n-1)},

where :math:`\beta_k` is the :math:`k`'th entry of :math:`b`.

.. cpp:function:: void Toeplitz( Matrix<T>& A, int m, int n, const std::vector<T>& b )
.. cpp:function:: void Toeplitz( AbstractDistMatrix<T>& A, int m, int n, const std::vector<T>& b )

   Build the matrix ``A`` using the generating vector :math:`b`.

TriW
----
**TODO**

.. cpp:function:: void TriW( Matrix<T>& A, int m, int n, T alpha, int k )
.. cpp:function:: void TriW( AbstractDistMatrix<T>& A, int m, int n, T alpha, int k )

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

.. cpp:function:: void Walsh( Matrix<T>& W, int k, bool binary=false )
.. cpp:function:: void Walsh( AbstractDistMatrix<T>& W, int k, bool binary=false )

   Set the matrix :math:`W` equal to the :math:`k`'th (possibly binary) Walsh 
   matrix.

Wilkinson
---------
A *Wilkinson matrix* of order :math:`k` is a tridiagonal matrix with diagonal

.. math::

   [k,k-1,k-2,...,1,0,1,...,k-2,k-1,k],

and sub- and super-diagonals of all ones.

.. cpp:function:: void Wilkinson( Matrix<T>& W, int k )
.. cpp:function:: void Wilkinson( AbstractDistMatrix<T>& W, int k )

   Set the matrix :math:`W` equal to the :math:`k`'th Wilkinson matrix.

Zeros
-----
Create an :math:`m \times n` matrix of all zeros.

.. cpp:function:: void Zeros( Matrix<T>& A, int m, int n )
.. cpp:function:: void Zeros( AbstractDistMatrix<T>& A, int m, int n )

   Set the matrix ``A`` to be an :math:`m \times n` matrix of all zeros. 
