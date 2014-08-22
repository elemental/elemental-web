Level 1
=======

The prototypes for the following routines can be found at 
`include/El/blas-like/decl.hpp <https://github.com/elemental/Elemental/tree/master/include/El/blas-like/decl.hpp>`_, while the
implementations are in `include/El/blas-like/level1/ <https://github.com/elemental/Elemental/tree/master/include/El/blas-like/level1>`_.

Adjoint
-------
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^H`. 

.. cpp:function:: void Adjoint( const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Adjoint( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

Axpy
----
Performs :math:`Y := \alpha X + Y` (hence the name *axpy*).

.. cpp:function:: void Axpy( T alpha, const Matrix<T>& X, Matrix<T>& Y )
.. cpp:function:: void Axpy( T alpha, const AbstractDistMatrix<T>& X, AbstractDistMatrix<T>& Y )

Conjugate
---------
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`A := \bar A`. For real datatypes, this is a no-op.

.. cpp:function:: void Conjugate( Matrix<T>& A )
.. cpp:function:: void Conjugate( AbstractDistMatrix<T>& A )

:math:`B := \bar A`.

.. cpp:function:: void Conjugate( const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Conjugate( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

Copy
----
Sets :math:`Y := X`.

.. cpp:function:: void Copy( const Matrix<T>& X, Matrix<T>& Y )
.. cpp:function:: void Copy( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

DiagonalScale
-------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`X := \mbox{op}(D) X` or :math:`X := X \mbox{op}(D)`, 
where :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, where
:math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const Matrix<T>& d, Matrix<T>& X )
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<T>& d, AbstractDistMatrix<T>& X )

DiagonalScaleTrapezoid
----------------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`A := \mbox{op}(D) A` or :math:`A := A \mbox{op}(D)`, 
where :math:`A` is trapezoidal (upper or lower with the boundary diagonal 
of given offset), :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, 
where :math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<T>& d, Matrix<T>& A, int offset=0 )
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<T>& d, AbstractDistMatrix<T>& A, int offset=0 )

DiagonalSolve
-------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`X := \mbox{op}(D)^{-1} X` or 
:math:`X := X \mbox{op}(D)^{-1}`, where :math:`D = \mbox{diag}(d)` and :math:`d`
is a column vector.

.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const Matrix<F>& d, Matrix<F>& X, bool checkIfSingular=false )
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& d, AbstractDistMatrix<F>& X, bool checkIfSingular=false )

Dot
---
Returns :math:`(x,y) = x^H y`. :math:`x` and :math:`y` are both allowed to be 
stored as column or row vectors, but will be interpreted as column vectors.

.. cpp:function:: T Dot( const Matrix<T>& x, const Matrix<T>& y )
.. cpp:function:: T Dot( const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y )

Dotc
----
Same as ``Dot``. This routine name is provided since it is the usual 
BLAS naming convention.

.. cpp:function:: T Dotc( const Matrix<T>& x, const Matrix<T>& y )
.. cpp:function:: T Dotc( const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y )

Dotu
----
Returns :math:`x^T y`, which is **not** an inner product.

.. cpp:function:: T Dotu( const Matrix<T>& x, const Matrix<T>& y )
.. cpp:function:: T Dotu( const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y )

EntrywiseFill
-------------

.. cpp:function:: void EntrywiseFill( Matrix<T>& A, std::function<T(void)> func )
.. cpp:function:: void EntrywiseFill( AbstractDistMatrix<T>& A, std::function<T(void)> func )
.. cpp:function:: void EntrywiseFill( BlockDistMatrix<T,U,V>& A, std::function<T(void)> func )

   Fills each entry of the passed in matrix by querying the specified function.

EntrywiseMap
------------

.. cpp:function:: void EntrywiseMap( Matrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( AbstractDistMatrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( BlockDistMatrix<T,U,V>& A, std::function<T(T)> func )

   Replaces each entry of the passed in matrix with a specified function of
   the existing entry.

Hadamard
--------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

The Hadamard product of two :math:`m \times n` matrices :math:`A` and
:math:`B` is given entrywise by :math:`\alpha_{i,j} \beta_{i,j}` and denoted
by :math:`C = A \circ B`.

.. cpp:function:: void Hadamard( const Matrix<F>& A, const Matrix<F>& B, Matrix<F>& C )
.. cpp:function:: void Hadamard( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C )

HilbertSchmidt
--------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

The Hilbert-Schmidt inner-product of two :math:`m \times n` matrices :math:`A`
and :math:`B` is :math:`\mbox{tr}(A^H B)`.

.. cpp:function:: F HilbertSchmidt( const Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: F HilbertSchmidt( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B )

IndexDependentFill
------------------

.. cpp:function:: void IndexDependentFill( Matrix<T>& A, std::function<T(Int,Int)> func )
.. cpp:function:: void IndexDependentFill( AbstractDistMatrix<T>& A, std::function<T(Int,Int)> func )
.. cpp:function:: void IndexDependentFill( BlockDistMatrix<T,U,V>& A, std::function<T(Int,Int)> func )

   Fills each entry of the passed in matrix by querying the specified function
   which depends upon the global index of the entry.

IndexDependentMap
-----------------

.. cpp:function:: void IndexDependentMap( Matrix<T>& A, std::function<T(Int,Int,T)> func )
.. cpp:function:: void IndexDependentMap( AbstractDistMatrix<T>& A, std::function<T(Int,Int,T)> func )
.. cpp:function:: void IndexDependentMap( BlockDistMatrix<T,U,V>& A, std::function<T(Int,Int,T)> func )

   Replaces each entry of the passed in matrix with a specified function of
   the existing entry and its global indices.

MakeTrapezoidal
---------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Sets all entries outside of the specified trapezoidal submatrix to zero.
Whether or not the trapezoid is upper or lower
(analogous to an upper or lower-triangular matrix) is determined by the 
``uplo`` parameter, and the last diagonal is defined with the ``offset`` 
integer.

.. cpp:function:: void MakeTrapezoidal( UpperOrLower uplo, Matrix<T>& A, int offset=0 )
.. cpp:function:: void MakeTrapezoidal( UpperOrLower uplo, AbstractDistMatrix<T>& A, int offset=0 )

Nrm2
----
Returns :math:`||x||_2 = \sqrt{(x,x)} = \sqrt{x^H x}`. As with most other 
routines, even if :math:`x` is stored as a row vector, it will be interpreted
as a column vector.

.. cpp:function:: Base<F> Nrm2( const Matrix<F>& x )
.. cpp:function:: Base<F> Nrm2( const AbstractDistMatrix<F>& x )

Scale
-----
:math:`X := \alpha X`.

.. cpp:function:: void Scale( T alpha, Matrix<T>& X )
.. cpp:function:: void Scale( T alpha, AbstractDistMatrix<T>& X )

ScaleTrapezoid
--------------
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Scales the entries within the specified trapezoid of a general matrix.
The parameter conventions follow those of ``MakeTrapezoidal`` described above.

.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, Matrix<T>& A, int offset=0 )
.. cpp:function:: void ScaleTrapezoid( T alpha, UpperOrLower uplo, AbstractDistMatrix<T>& A, int offset=0 )

Transpose
---------
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^T` or :math:`B := A^H`. 

.. cpp:function:: void Transpose( const Matrix<T>& A, Matrix<T>& B, bool conjugate=false )
.. cpp:function:: void Transpose( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

Zero
----
.. note::
   
   This is not a standard BLAS routine, but it is BLAS-like.

Sets all of the entries of the input matrix to zero.

.. cpp:function:: void Zero( Matrix<T>& A )
.. cpp:function:: void Zero( AbstractDistMatrix<T>& A )

SetDiagonal
-----------
.. note::
   
   This is not a standard BLAS routine.

Sets all of the diagonal entries of a matrix to a given value.

.. cpp:function:: void SetDiagonal( Matrix<T>& A, T alpha )
.. cpp:function:: void SetDiagonal( AbstractDistMatrix<T>& A, T alpha )

.. cpp:function:: void SetDiagonal( Matrix<T>& A, T alpha, int offset=0, LeftOrRight side=LEFT )
.. cpp:function:: void SetDiagonal( AbstractDistMatrix<T>& A, T alpha, int offset=0, LeftOrRight side=LEFT )

Swap
----

.. cpp:function:: void Swap( Orientation orientation, Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Swap( Orientation orientation, AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

   Replace :math:`A` and :math:`B` with each other, their transpose, or their
   adjoint.

.. cpp:function:: void RowSwap( Matrix<T>& A, int to, int from )
.. cpp:function:: void RowSwap( AbstractDistMatrix<T>& A, int to, int from )

   Swap rows `to` and `from` in the matrix.

.. cpp:function:: void ColumnSwap( Matrix<T>& A, int to, int from )
.. cpp:function:: void RowSwap( AbstractDistMatrix<T>& A, int to, int from )

   Swap columns `to` and `from` in the matrix.

.. cpp:function:: void SymmetricSwap( UpperOrLower uplo, Matrix<T>& A, int to, int from, bool conjugate=false )
.. cpp:function:: void SymmetricSwap( UpperOrLower uplo, AbstractDistMatrix<T>& A, int to, int from, bool conjugate=false )

   Symmetrically permute the `to` and `from` degrees of freedom within the 
   implicitly symmetric (Hermitian) matrix :math:`A` which stores its data
   in the specified triangle.

QuasiDiagonalScale
------------------

.. note::

   This is not a standard BLAS routine.

.. cpp:function:: void QuasiDiagonalScale( LeftOrRight side, UpperOrLower uplo, const Matrix<FMain>& d, const Matrix<F>& dSub, Matrix<F>& X, bool conjugate=false )
.. cpp:function:: void QuasiDiagonalScale( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<FMain>& d, const AbstractDistMatrix<F>& dSub, AbstractDistMatrix<F>& X, bool conjugate=false )

   Apply a symmetric (Hermitian) quasi-diagonal matrix to the matrix X.

QuasiDiagonalSolve
------------------

.. note::

   This is not a standard BLAS routine.

.. cpp:function:: void QuasiDiagonalSolve( LeftOrRight side, UpperOrLower uplo, const Matrix<FMain>& d, const Matrix<F>& dSub, Matrix<F>& X, bool conjugate=false )
.. cpp:function:: void QuasiDiagonalSolve( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<FMain>& d, const AbstractDistMatrix<F>& dSub, AbstractDistMatrix<F>& X, bool conjugate=false )

   Apply the inverse of a symmetric (Hermitian) quasi-diagonal matrix to the 
   matrix X.

Symmetric2x2Scale
-----------------

.. note::

   This is not a standard BLAS routine.

.. cpp:function:: void Symmetric2x2Scale( LeftOrRight side, UpperOrLower uplo, const Matrix<F>& D, Matrix<F>& A, bool conjugate=false )
.. cpp:function:: void Symmetric2x2Scale( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& A, bool conjugate=false )

   Apply a 2x2 symmetric (Hermitian) matrix to the matrix A.

Symmetric2x2Solve
-----------------

.. note::

   This is not a standard BLAS routine.

.. cpp:function:: void Symmetric2x2Solve( LeftOrRight side, UpperOrLower uplo, const Matrix<F>& D, Matrix<F>& A, bool conjugate=false )
.. cpp:function:: void Symmetric2x2Solve( LeftOrRight side, UpperOrLower uplo, const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& A, bool conjugate=false )

   Apply the inverse of a 2x2 symmetric (Hermitian) matrix to the matrix A.

UpdateDiagonal
--------------
.. note::
   
   This is not a standard BLAS routine.

Adds a given value to the diagonal of a matrix.

.. cpp:function:: void UpdateDiagonal( Matrix<T>& A, T alpha )
.. cpp:function:: void UpdateDiagonal( AbstractDistMatrix<T>& A, T alpha )

.. cpp:function:: void UpdateDiagonal( Matrix<T>& A, T alpha, int offset=0, LeftOrRight side=LEFT )
.. cpp:function:: void UpdateDiagonal( AbstractDistMatrix<T>& A, T alpha, int offset=0, LeftOrRight side=LEFT )
