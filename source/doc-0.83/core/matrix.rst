Sequential matrices
===================
The :cpp:type:`Matrix\<T>` class is the building of the library:
its purpose is to provide convenient mechanisms for performing basic matrix 
manipulations, such as setting and querying individual matrix entries, 
without giving up compatibility with interfaces such as BLAS and LAPACK, 
which assume column-major storage.

An example of generating an :math:`m \times n` matrix of real double-precision 
numbers where the :math:`(i,j)` entry is equal to :math:`i-j` would be:

  .. code-block:: cpp

     #include "elemental.hpp"
     using namespace elem;
     ...
     Matrix<double> A( m, n );
     for( int j=0; j<n; ++j )
         for( int i=0; i<m; ++i )
             A.Set( i, j, double(i-j) );

whereas the complex double-precision equivalent could use :cpp:type:`Complex\<double>`, which is currently a typedef for ``std::complex<double>``.
     
The underlying data storage for :cpp:type:`Matrix\<T>` is simply a contiguous 
buffer that stores entries in a column-major fashion with a *leading 
dimension* which is only required to be at least as large as the height of the 
matrix (so that entry :math:`(i,j)` is located at position ``i+j*ldim``). 
For modifiable instances of the :cpp:type:`Matrix\<T>` class, the routine
:cpp:type:`Matrix\<T>::Buffer` returns a pointer to the underlying 
buffer, while :cpp:type:`Matrix\<T>::LDim` returns the leading 
dimension; these two routines could be used to directly perform the equivalent
of the first code sample as follows:

  .. code-block:: cpp
     
     #include "elemental.hpp"
     using namespace elem;
     ...
     Matrix<double> A( m, n );
     double* buffer = A.Buffer();
     const int ldim = A.LDim();
     for( int j=0; j<n; ++j )
         for( int i=0; i<m; ++i )
             buffer[i+j*ldim] = double(i-j);

For immutable instances of the :cpp:type:`Matrix\<T>` class, a ``const`` pointer
to the underlying data can similarly be returned with a call to 
:cpp:func:`Matrix\<T>::LockedBuffer`.
In addition, a (``const``) pointer to the place in the 
(``const``) buffer where entry :math:`(i,j)` resides can be easily retrieved
with a call to :cpp:func:`Matrix\<T>::Buffer` or 
:cpp:func:`Matrix\<T>::LockedBuffer`.

It is also important to be able to create matrices which are simply *views* 
of existing (sub)matrices. For example, if `A` is a :math:`10 \times 10` 
matrix of complex doubles, then a matrix :math:`A_{BR}` can easily be created 
to view the bottom-right :math:`6 \times 7` submatrix using

  .. code-block:: cpp

     #include "elemental.hpp"
     ...
     auto ABR = View( A, 1, 2, 3, 4 );

since the bottom-right :math:`3 \times 4` submatrix beings at index 
:math:`(1,2)`. In general, to view the :math:`M \times N` submatrix starting
at entry :math:`(i,j)`, one would call ``View( ABR, A, i, j, M, N );``.

.. cpp:type:: class Matrix<T>

   The goal is for the `Matrix` class to support any datatype `T` which 
   supports both addition and multiplication and has the associated identities
   (that is, when the datatype `T` is a *ring*). While there are several 
   barriers to reaching this goal, it is important to keep in mind that, in 
   addition to `T` being allowed to be a real or complex 
   (single- or double-precision) floating-point type, signed integers 
   are also supported.

   .. rubric:: Constructors and destructors

   .. note::

      Many of the following constructors have the default parameter
      ``bool fixed=false``, which can be changed to ``true`` in order to 
      produce a `Matrix` whose entries can be modified, but the matrix's 
      dimensions cannot. This is useful for the :cpp:type:`DistMatrix\<T>` 
      class, which contains a local :cpp:type:`Matrix\<T>` whose entries can
      be locally modified in cases where it would not make sense to change
      the local matrix size (which should instead result from changing the size
      of the full distributed matrix).

   .. cpp:function:: Matrix( bool fixed=false )

      This simply creates a default :math:`0 \times 0` matrix with a leading 
      dimension of one (BLAS and LAPACK require positive leading dimensions).

   .. cpp:function:: Matrix( int height, int width, bool fixed=false )

      A `height` :math:`\times` `width` matrix is created with an unspecified
      leading dimension (though it is currently implemented as 
      :math:`\max(height,1)`).

   .. cpp:function:: Matrix( int height, int width, int ldim, bool fixed=false )

      A `height` :math:`\times` `width` matrix is created with a leading 
      dimension equal to `ldim` (which must be greater than or equal 
      :math:`\max(height,1)`).

   .. cpp:function:: Matrix( int height, int width, const T* buffer, int ldim, bool fixed=false )
   .. cpp:function:: Matrix( int height, int width, T* buffer, int ldim, bool fixed=false )

      A matrix is built around a column-major (immutable) buffer 
      with the specified dimensions. The memory pointed to by `buffer` should
      not be freed until after the :cpp:type:`Matrix\<T>` object is destructed.

   .. cpp:function:: Matrix( const Matrix<T>& A )

      A copy (not a view) of the matrix :math:`A` is built.

   .. cpp:function:: Matrix( Matrix<T>&& A )

      A C++11 move constructor which creates a new matrix by moving the metadata
      from the specified matrix over to the new matrix, which cheaply gives the
      new matrix control over the resources originally assigned to the input
      matrix.

   .. cpp:function:: ~Matrix()

      Frees all resources owned by the matrix upon destruction.

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const Matrix<T>& operator=( const Matrix<T>& A )

      Create a full copy of the specified matrix.

   .. cpp:function:: Matrix<T>& operator=( Matrix<T>&& A )

      A C++11 move assignment which swaps the metadata of two matrices so that
      the resources owned by the two objects will have been cheaply
      switched.

   .. cpp:function:: void Empty()

      Sets the matrix to :math:`0 \times 0` and frees any owned resources.

   .. cpp:function:: void Resize( int height, int width )

      Reconfigures the matrix to be `height` :math:`\times` `width`.

   .. cpp:function:: void Resize( int height, int width, int ldim )

      Reconfigures the matrix to be `height` :math:`\times` `width`, but with 
      leading dimension equal to `ldim` (which must be greater than or equal to 
      :math:`\max(height,1)`).

   .. cpp:function:: void Attach( int height, int width, T* buffer, int ldim )
   .. cpp:function:: void LockedAttach( int height, int width, const T* buffer, int ldim )

      Reconfigure the matrix around the specified (unmodifiable) buffer.

   .. cpp:function:: void Control( int height, int width, T* buffer, int ldim )

      Reconfigure the matrix around a specified buffer and give ownership of
      the resource to the matrix.

   .. rubric:: Basic queries

   .. cpp:function:: int Height() const
   .. cpp:function:: int Width() const

      Return the height/width of the matrix.

   .. cpp:function:: int LDim() const

      Return the leading dimension of the underlying buffer.

   .. cpp:function:: int MemorySize() const

      Return the number of entries of type `T` that this :cpp:type:`Matrix\<T>`
      instance has allocated space for.

   .. cpp:function:: int DiagonalLength( int offset=0 ) const

      Return the length of the specified diagonal of the matrix: an offset of 
      :math:`0` refers to the main diagonal, an offset of :math:`1` refers to 
      the superdiagonal, an offset of :math:`-1` refers to the subdiagonal, 
      etc.

   .. cpp:function:: T* Buffer()
   .. cpp:function:: const T* LockedBuffer() const

      Return a pointer to the (immutable) underlying buffer.

   .. cpp:function:: T* Buffer( int i, int j )
   .. cpp:function:: const T* LockedBuffer( int i, int j ) const

      Return a pointer to the (immutable) portion of the buffer that holds entry
      :math:`(i,j)`.

   .. cpp:function:: bool Viewing() const

      Returns `true` if the underlying buffer is merely a pointer into an 
      externally-owned buffer.

   .. cpp:function:: bool FixedSize() const

      Returns `true` if the dimensions of the matrix cannot be changed.

   .. cpp:function:: bool Locked() const

      Returns `true` if the entries of the matrix cannot be changed.

   .. rubric:: Single-entry manipulation

   .. cpp:function:: T Get( int i, int j ) const
   .. cpp:function:: Base<T> GetRealPart( int i, int j ) const
   .. cpp:function:: Base<T> GetImagPart( int i, int j ) const

      Return entry :math:`(i,j)` (or its real or imaginary part).

   .. cpp:function:: void Set( int i, int j, T alpha )
   .. cpp:function:: void SetRealPart( int i, int j, Base<T> alpha )
   .. cpp:function:: void SetImagPart( int i, int j, Base<T> alpha )

      Set entry :math:`(i,j)` (or its real or imaginary part) to :math:`\alpha`.

   .. cpp:function:: void Update( int i, int j, T alpha )
   .. cpp:function:: void UpdateRealPart( int i, int j, Base<T> alpha )
   .. cpp:function:: void UpdateImagPart( int i, int j, Base<T> alpha ) 

      Add :math:`\alpha` to entry :math:`(i,j)` (or its real or imaginary part).

   .. cpp:function:: void MakeReal( int i, int j )
 
      Force the :math:`(i,j)` entry to be real.

   .. cpp:function:: void Conjugate( int i, int j )

      Conjugate the :math:`(i,j)` entry of the matrix.

   .. rubric:: Diagonal manipulation

   .. cpp:function:: void GetDiagonal( Matrix<T>& d, int offset=0 ) const
   .. cpp:function:: void GetRealPartOfDiagonal( Matrix<Base<T>>& d, int offset=0 ) const
   .. cpp:function:: void GetImagPartOfDiagonal( Matrix<Base<T>>& d, int offset=0 ) const

      Modify :math:`d` into a column-vector containing the entries (or their 
      real or imaginary parts) lying on the `offset` diagonal of our matrix 
      (for instance, the main diagonal has offset :math:`0`, the subdiagonal 
      has offset :math:`-1`, and the superdiagonal has offset :math:`+1`).

   .. cpp:function:: Matrix<T> GetDiagonal( int offset=0 ) const
   .. cpp:function:: Matrix<Base<T>> GetRealPartOfDiagonal( int offset=0 ) const
   .. cpp:function:: Matrix<Base<T>> GetRealPartOfDiagonal( int offset=0 ) const

      Efficiently construct and return the particular diagonal 
      (or its real or imaginary part) via C++11 move semantics.

   .. cpp:function:: void SetDiagonal( const Matrix<T>& d, int offset=0 )
   .. cpp:function:: void SetRealPartOfDiagonal( const Matrix<Base<T>>& d, int offset=0 )
   .. cpp:function:: void SetImagPartOfDiagonal( const Matrix<Base<T>>& d, int offset=0 )

      Set the entries (or their real or imaginary parts) in the `offset` 
      diagonal entries from the contents of the column-vector :math:`d`.

   .. cpp:function:: void UpdateDiagonal( const Matrix<T>& d, int offset=0 )
   .. cpp:function:: void UpdateRealPartOfDiagonal( const Matrix<Base<T>>& d, int offset=0 )
   .. cpp:function:: void UpdateImagPartOfDiagonal( const Matrix<Base<T>>& d, int offset=0 )

      Add the contents of :math:`d` onto the entries (or the real or imaginary 
      parts) in the `offset` diagonal.

   .. cpp:function:: void MakeDiagonalReal( int offset=0 )

      Force the specified diagonal of the matrix to be real.

   .. cpp:function:: void ConjugateDiagonal( int offset=0 )

      Conjugate the specified diagonal of the matrix. 

   .. rubric:: Arbitrary-submatrix manipulation

   .. cpp:function:: void GetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Matrix<T>& ASub ) const
   .. cpp:function:: void GetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Matrix<Base<T>>& ASub ) const
   .. cpp:function:: void GetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Matrix<Base<T>>& ASub ) const

      Return the submatrix (or its real or imaginary part) with the specified 
      row and column indices via `ASub`.

   .. cpp:function:: Matrix<T> GetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: Matrix<Base<T>> GetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: Matrix<Base<T>> GetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const

      Return the submatrix (or its real or imaginary part) with the specified
      row and column indices via C++11 move semantics.

   .. cpp:function:: void SetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const Matrix<T>& ASub )
   .. cpp:function:: void SetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void SetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const Matrix<Base<T>>& ASub )

      Set the submatrix (or its real or imaginary part) with the specified 
      row and column indices equal to the matrix `ASub`.

   .. cpp:function:: void UpdateSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, T alpha, const Matrix<T>& ASub )
   .. cpp:function:: void UpdateRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void UpdateImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const Matrix<Base<T>>& ASub )

      Update the submatrix (or its real or imaginary part) with the specified
      row and column indices with `alpha` times `ASub`.

   .. cpp:function:: void MakeSubmatrixReal( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Force the submatrix with the specified row and column indices to be real.

   .. cpp:function:: void ConjugateSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Conjugate the entries in the submatrix with the specified row and column
      indices.

Special cases used in Elemental
-------------------------------
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`Matrix\<T>`.

.. cpp:type:: class Matrix<Real>

   Used to denote that the underlying datatype `Real` is real.

.. cpp:type:: class Matrix<Complex<Real> >

   Used to denote that the underlying datatype :cpp:type:`Complex\<Real>` is
   complex with base type `Real`.

.. cpp:type:: class Matrix<F>

   Used to denote that the underlying datatype `F` is a field.

.. cpp:type:: class Matrix<int>

   When the underlying datatype is a signed integer.

