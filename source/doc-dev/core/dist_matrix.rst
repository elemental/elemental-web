Distributed matrices
====================
The :cpp:type:`DistMatrix\<T,U,V>` class is meant to provide a 
distributed-memory analogue of the :cpp:type:`Matrix\<T>` class. 
In a manner similar to PLAPACK, roughly ten different matrix 
distributions are provided and it is trivial (in the sense that it requires a 
single command) to redistribute from one to another: in PLAPACK, one would 
simply call ``PLA_Copy``, whereas, in Elemental, it is handled through 
overloading the :math:`=` operator (or instead calling the :cpp:func:`Copy` 
function).

Since it is crucial to know not only how many 
processes to distribute the data over, but *which* processes, and in what 
manner they should be decomposed into a logical two-dimensional grid, an 
instance of the :cpp:type:`Grid` class must be passed into the constructor of 
the :cpp:type:`DistMatrix\<T,U,V>` class.

.. note:: 
   
   Since the :cpp:type:`DistMatrix\<T,U,V>` class makes use of MPI for 
   message passing, custom interfaces must be written for nonstandard datatypes.
   As of now, the following datatypes are fully supported for 
   :cpp:type:`DistMatrix\<T,U,V>`:
   ``int``, ``float``, ``double``, ``Complex<float>``, and ``Complex<double>``.

.. cpp:type:: struct DistData

   .. note::

      Documentation still needs to be written for this data structure.

   .. cpp:member:: Distribution colDist
   
   .. cpp:member:: Distribution rowDist

   .. cpp:member:: int colAlign

   .. cpp:member:: int rowAlign

   .. cpp:member:: int root

   .. cpp:member:: const Grid* grid

AbstractDistMatrix
------------------

This abstract class defines the list of member functions that are guaranteed 
to be available for all matrix distributions.

.. cpp:type:: class AbstractDistMatrix<T>

   .. rubric:: Constructors and destructors

   .. cpp:function:: AbstractDistMatrix( AbstractDistMatrix<T>&& A )

      A C++11 move constructor which transfers the metadata from the specified
      matrix over to the new matrix as a means of cheaply transferring 
      resources.

   .. cpp:function:: ~AbstractDistMatrix()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: AbstractDistMatrix<T>& operator=( AbstractDistMatrix<T>&& A )

      A C++11 move assignment which swaps the metadata between the two matrices
      as a means of cheaply swapping the resources assigned to each matrix.

   .. cpp:function:: void Empty()

      Empties the data and frees all alignments.

   .. cpp:function:: void EmptyData()

      Sets the matrix size to zero and frees associated memory 
      (the alignments are left unchanged).

   .. cpp:function:: void SetGrid( const Grid& grid )

      Clear the distributed matrix's contents and reconfigure for the new 
      process grid.

   .. cpp:function:: void Resize( int height, int width )

      Reconfigure the matrix so that it is `height` :math:`\times` `width`.

   .. cpp:function:: void Resize( int height, int width, int ldim )

      Same as above, but the local leading dimension is also specified.

   .. cpp:function:: void MakeConsistent()

      Gives every non-participating process a copy of the metadata stored
      by the root process in the distribution communicator.

   .. cpp:function:: void Align( int colAlign, int rowAlign )
 
      Aligns the column and row distributions.

   .. cpp:function:: void AlignCols( int colAlign )

      Aligns the column distribution.

   .. cpp:function:: void AlignRows( int rowAlign )
 
      Aligns the row distribution.

   .. cpp:function:: void FreeAlignments()

      Free all alignment constaints.

   .. cpp:function:: void SetRoot( int root )
      
      For querying and changing the process rank in the cross communicator which
      owns the data.

   .. cpp:function:: void AlignWith( const DistData& data )

      Aligns the row and column distributions (as necessary) to conform with
      the specified distribution data.

   .. cpp:function:: void AlignColsWith( const DistData& data )

      Aligns the column distribution (as necessary) to conform with the
      specified distribution data.

   .. cpp:function:: void AlignRowsWith( const DistData& data )

      Aligns the row distribution (as necessary) to conform with the 
      specified distribution data.

   .. rubric:: Basic queries

   .. cpp:function:: int Height() const
   .. cpp:function:: int Width() const

      Return the height (width) of the distributed matrix.

   .. cpp:function:: int DiagonalLength( int offset=0 ) const

      Return the length of the specified diagonal of the distributed matrix.

   .. cpp:function:: bool Viewing() const

      Return whether or not this matrix is viewing another.

   .. cpp:function:: bool Locked() const

      Return whether or not this matrix is viewing another in a manner
      that does not allow for modifying the viewed data.

   .. cpp:function:: int LocalHeight() const
   .. cpp:function:: int LocalWidth() const

      Return the height (width) of the local matrix stored by a particular 
      process.

   .. cpp:function:: int LDim() const

      Return the leading dimension of the local matrix stored by a particular 
      process.

   .. cpp:function:: Matrix<T>& Matrix()
   .. cpp:function:: const Matrix<T>& LockedMatrix() const

      Return an (immutable) reference to the local matrix.

   .. cpp:function:: size_t AllocatedMemory() const

      Return the number of entries of type `T` that we have locally allocated
      space for.

   .. cpp:function:: T* Buffer()
   .. cpp:function:: const T* LockedBuffer() const

      Return an (immutable) pointer to the local matrix's buffer.

   .. cpp:function:: T* Buffer( int iLoc, int jLoc )
   .. cpp:function:: const T* LockedBuffer( int iLoc, int jLoc ) const

      Return an (immutable) pointer to the portion of the local buffer that 
      stores entry `(iLoc,jLoc)`.

   .. rubric:: Distribution information

   .. cpp:function:: const Grid& Grid() const

      Return the grid that this distributed matrix is distributed over.

   .. cpp:function:: bool ColConstrained() const
   .. cpp:function:: bool RowConstrained() const

      Return whether or not the column (row) alignment is constrained.

   .. cpp:function:: int ColAlign() const
   .. cpp:function:: int RowAlign() const

      Return the rank of the member of our :cpp:func:`ColComm` or 
      :cpp:func:`RowComm` assigned to the top-left entry of the matrix.

   .. cpp:function:: int ColShift() const
   .. cpp:function:: int RowShift() const

      Return the first row or column to be locally assigned to this process,
      respectively.

   .. cpp:function:: int ColRank() const
   .. cpp:function:: int RowRank() const

      Return our rank in our :cpp:func:`ColComm` or :cpp:func:`RowComm`,
      respectively.

   .. cpp:function:: int DistRank() const
   .. cpp:function:: int CrossRank() const
   .. cpp:function:: int RedundantRank() const

      Return our rank in our :cpp:func:`DistComm`, :cpp:func:`CrossComm`, or 
      :cpp:func:`RedundantComm`, respectively.

   .. cpp:function:: int DistSize() const
   .. cpp:function:: int CrossSize() const
   .. cpp:function:: int RedundantSize() const

      Return the number of members of our :cpp:func:`DistComm`, 
      :cpp:func:`CrossComm`, or :cpp:func:`RedundantComm`, respectively.

   .. cpp:function:: int Root() const

      Return the rank of the member of our cross communicator 
      (:cpp:func:`CrossComm`) which can store data.

   .. cpp:function:: bool Participating() const

      Return whether or not this process can be assigned matrix data (that is, 
      whether or not this process is both in the process grid and the root of 
      :cpp:func:`CrossComm`).

   .. cpp:function:: int RowOwner( int i ) const

      Return the rank (in :cpp:func:`ColComm`) of the process which owns 
      row `i`.

   .. cpp:function:: int ColOwner( int j ) const

      Return the rank (in :cpp:func:`RowComm`) of the process which owns 
      column `j`.

   .. cpp:function:: int Owner( int i, int j ) const

      Return the rank (in :cpp:func:`DistComm`) of the process which owns entry
      `(i,j)`.

   .. cpp:function:: int LocalRow( int i ) const
   .. cpp:function:: int LocalCol( int j ) const

      Return the local row (column) index for row `i` (`j`); if this process
      is not assigned row `i` (column `j`), then throw an exception.

   .. cpp:function:: bool IsLocalRow( int i ) const
   .. cpp:function:: bool IsLocalCol( int j ) const
   .. cpp:function:: bool IsLocal( int i, int j ) const

      Return whether or not the row, column, or entry, respectively, is assigned
      to this process.

   .. cpp:function:: DistData DistData() const

      Returns a description of the distribution and alignment information

   .. cpp:function:: mpi::Comm DistComm() const

      The communicator used to distribute the entire set of entries of the 
      matrix (in some sense, the product of the column and row communicators), 
      our rank in the communicator, and the total number of processes in the
      communicator, respectively.

   .. cpp:function:: mpi::Comm CrossComm() const

      The orthogonal complement of the product of the `Dist` and `Redundant`
      communicators with respect to the process grid, our rank in the
      communicator, and the total number of processes in the communicator,
      respectively.

   .. cpp:function:: mpi::Comm RedundantComm() const

      The communicator over which data is redundantly stored, our rank in the
      communicator, and the total number of processes in the communicator,
      respectively.

   .. cpp:function:: mpi::Comm ColComm() const

      The communicator used to distribute each column of the matrix.

   .. cpp:function:: mpi::Comm RowComm() const

      The communicator used to distribute each row of the matrix.

   .. cpp:function:: int ColStride() const

      The number of processes used to distribute each column of the matrix; 
      this is equivalent to the number of rows each locally owned row is 
      apart.

   .. cpp:function:: int RowStride() const

      The number of processes used to distribute each row of the matrix; 
      this is equivalent to the number of columns each locally owned 
      column is apart.

   .. rubric:: Single-entry manipulation

   .. cpp:function:: T Get( int i, int j ) const
   .. cpp:function:: Base<T> GetRealPart( int i, int j ) const
   .. cpp:function:: Base<T> GetImagPart( int i, int j ) const

      Return the `(i,j)` entry (or its real or imaginary part) of the global 
      matrix.

   .. cpp:function:: void Set( int i, int j, T alpha )
   .. cpp:function:: void SetRealPart( int i, int j, Base<T> alpha )
   .. cpp:function:: void SetImagPart( int i, int j, Base<T> alpha )

      Set the `(i,j)` entry (or its real or imaginary part) of the global 
      matrix to :math:`\alpha`. 

   .. cpp:function:: void Update( int i, int j, T alpha )
   .. cpp:function:: void UpdateRealPart( int i, int j, Base<T> alpha )
   .. cpp:function:: void UpdateImagPart( int i, int j, Base<T> alpha )

      Add :math:`\alpha` to the `(i,j)` entry (or its real or imaginary part) 
      of the global matrix. 

   .. cpp:function:: void MakeReal( int i, int j )

      Force the :math:`(i,j)` entry of the global matrix to be real.

   .. cpp:function:: void Conjugate( int i, int j )

      Conjugate the :math:`(i,j)` entry of the global matrix.

   .. cpp:function:: T GetLocal( int iLoc, int jLoc ) const
   .. cpp:function:: Base<T> GetRealPartLocal( int iLoc, int jLoc ) const
   .. cpp:function:: Base<T> GetLocalImagPart( int iLoc, int jLoc ) const

      Return the :math:`(iLoc,jLoc)` entry (or its real or imaginary part) of 
      our local matrix.

   .. cpp:function:: void SetLocal( int iLoc, int jLoc, T alpha )
   .. cpp:function:: void SetLocalRealPart( int iLoc, int jLoc, Base<T> alpha )
   .. cpp:function:: void SetLocalImagPart( int iLoc, int jLoc, Base<T> alpha )

      Set the `(iLoc,jLoc)` entry (or its real or imaginary part) of our 
      local matrix to :math:`\alpha`.

   .. cpp:function:: void UpdateLocal( int iLoca, int jLoc, T alpha )
   .. cpp:function:: void UpdateRealPartLocal( int iLoc, int jLoc, Base<T> alpha )
   .. cpp:function:: void UpdateLocalImagPart( int iLoc, int jLoc, Base<T> alpha )

      Add :math:`\alpha` to the `(iLoc,jLoc)` entry (or its real or 
      imaginary part) of our local matrix.

   .. cpp:function:: void MakeRealLocal( int iLoc, int jLoc )

      Force the `(iLoc,jLoc)` entry of our local matrix to be real.

   .. cpp:function:: void ConjugateLocal( int iLoc, int jLoc )

      Conjugate the `(iLoc,jLoc)` entry of our local matrix.

   .. rubric:: Arbitrary-submatrix manipulation

   .. cpp:function:: void Get( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<T,STAR,STAR>& ASub ) const
   .. cpp:function:: void GetRealPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<Base<T>,STAR,STAR>& ASub ) const
   .. cpp:function:: void GetImagPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<Base<T>,STAR,STAR>& ASub ) const

      Return the submatrix (or its real or imaginary part) with the specified
      row and column indices via `ASub`.

   .. cpp:function:: DistMatrix<T,STAR,STAR> Get( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetRealPart( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetImagPart( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const

      Return the submatrix (or its real or imaginary part) with the specified
      row and column indices via C++11 move semantics.

   .. cpp:function:: void Set( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<T,STAR,STAR>& ASub )
   .. cpp:function:: void SetRealPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<Base<T>,STAR,STAR>& ASub )
   .. cpp:function:: void SetImagPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<Base<T>,STAR,STAR>& ASub )

      Set the submatrix (or its real or imaginary part) with the specified
      row and column indices equal to the matrix `ASub`.

   .. cpp:function:: void Update( const std::vector<int>& rowInd, const std::vector<int>& colInd, T alpha, const DistMatrix<T,STAR,STAR>& ASub )
   .. cpp:function:: void UpdateRealPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const DistMatrix<Base<T>,STAR,STAR>& ASub )
   .. cpp:function:: void UpdateImagPart( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const DistMatrix<Base<T>,STAR,STAR>& ASub )

      Update the submatrix (or its real or imaginary part) with the specified
      row and column indices with `alpha` times `ASub`.

   .. cpp:function:: void MakeReal( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Force the submatrix with the specified row and column indices to be real.

   .. cpp:function:: void Conjugate( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Conjugate the entries in the submatrix with the specified row and column
      indices.

   .. cpp:function:: void GetLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<T>& ASub ) const
   .. cpp:function:: void GetLocalRealPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<Base<T>>& ASub ) const
   .. cpp:function:: void GetLocalImagPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<Base<T>>& ASub ) const

      Return the local submatrix (or its real or imaginary part) with the specified
      row and column indices via `ASub`.

   .. cpp:function:: Matrix<T> GetLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const
   .. cpp:function:: Matrix<Base<T>> GetLocalRealPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const
   .. cpp:function:: Matrix<Base<T>> GetLocalImagPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const

      Return the local submatrix (or its real or imaginary part) with the specified
      row and column indices via C++11 move semantics.

   .. cpp:function:: void SetLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<T>& ASub )
   .. cpp:function:: void SetLocalRealPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void SetLocalImagPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<Base<T>>& ASub )

      Set the local submatrix (or its real or imaginary part) with the specified
      row and column indices equal to the matrix `ASub`.

   .. cpp:function:: void UpdateLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, T alpha, const Matrix<T>& ASub )
   .. cpp:function:: void UpdateLocalRealPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Base<T> alpha, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void UpdateLocalImagPart( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Base<T> alpha, const Matrix<Base<T>>& ASub )

      Update the local submatrix (or its real or imaginary part) with the specified
      row and column indices with `alpha` times `ASub`.

   .. cpp:function:: void MakeRealLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc )

      Force the local submatrix with the specified row and column indices to be real.

   .. cpp:function:: void ConjugateLocal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc )

      Conjugate the entries in the local submatrix with the specified row and column
      indices.

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`AbstractDistMatrix\<T>`.

.. cpp:type:: class AbstractDistMatrix<Real>

   Used to denote that the underlying datatype `Real` is real.

.. cpp:type:: class AbstractDistMatrix<Complex<Real> >

   Used to denote that the underlying datatype :cpp:type:`Complex\<Real>` is 
   complex with base type `Real`.

.. cpp:type:: class AbstractDistMatrix<F>

   Used to denote that the underlying datatype `F` is a field. 

.. cpp:type:: class AbstractDistMatrix<int>

   When the underlying datatype is a signed integer (of standard size).

DistMatrix
----------

.. cpp:type:: class DistMatrix<T,U,V>

   This templated class for manipulating distributed matrices is only defined
   for the following choices of the column and row :cpp:type:`Distribution`'s, 
   `U` and `V` (`T` is only assumed to be a ring).

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<T,U,V>`.

.. cpp:type:: class DistMatrix<double,U,V>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,U,V>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,U,V>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,U,V>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`. 

.. cpp:type:: class DistMatrix<F,U,V>

   The underlying datatype `F` is a field.

.. cpp:type:: class DistMatrix<int,U,V>

   The underlying datatype is a signed integer (of standard size).

The standard matrix distribution (``[MC,MR]``)
----------------------------------------------

This is by far the most important matrix distribution in Elemental, as the vast
majority of parallel routines expect the input to be in this form. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column and row alignments are both 0):

.. math::

   \left(\begin{array}{ccccccc}
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0 \\
     1 & 3 & 5 & 1 & 3 & 5 & 1 \\ 
     0 & 2 & 4 & 0 & 2 & 4 & 0  
   \end{array}\right)

Similarly, if the column alignment is kept at 0 and the row alignment is changed
to 2 (meaning that the third process column owns the first column of the 
matrix), the individual entries would be owned as follows:

.. math::

   \left(\begin{array}{ccccccc}
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 \\
     5 & 1 & 3 & 5 & 1 & 3 & 5 \\ 
     4 & 0 & 2 & 4 & 0 & 2 & 4 
   \end{array}\right)

It should also be noted that this is the default distribution format for the 
:cpp:type:`DistMatrix\<T,U,V>` class, as :cpp:type:`DistMatrix\<T>` defaults to
:cpp:type:`DistMatrix\<T,MC,MR>`.

.. cpp:type:: class DistMatrix<T>

.. cpp:type:: class DistMatrix<T,MC,MR>

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMatrix( const Grid& grid=DefaultGrid() )
      
      Create a :math:`0 \times 0` distributed matrix.

   .. cpp:function:: DistMatrix( int height, int width, const Grid& grid=DefaultGrid() )

      Create a `height` :math:`\times` `width` distributed matrix.

   .. cpp:function:: DistMatrix( int height, int width, int colAlign, int rowAlign, const Grid& grid )

      Create a `height` :math:`\times` `width` distributed matrix, but with the 
      top-left entry owned by the `colAlign` process row and the `rowAlign` 
      process column.

   .. cpp:function:: DistMatrix( int height, int width, int colAlign, int rowAlign, int ldim, const Grid& grid )

      Same as above, but the local leading dimension is also specified.

   .. cpp:function:: DistMatrix( int height, int width, int colAlign, int rowAlign, T* buffer, int ldim, const Grid& grid )
   .. cpp:function:: DistMatrix( int height, int width, int colAlign, int rowAlign, const T* buffer, int ldim, const Grid& grid )

      View an (immutable) distributed matrix's buffer; the buffer must 
      correspond to the local portion of an elemental distributed matrix with 
      the specified row and column alignments and leading dimension, `ldim`.

   .. cpp:function:: DistMatrix( const DistMatrix<T,U,V>& A )

      Build a copy of the distributed matrix `A`, but force it to be in the
      ``[MC,MR]`` distribution.

   .. cpp:function:: DistMatrix( DistMatrix<T,MC,MR>&& A )

      A C++11 move constructor which builds a new matrix by moving the metadata
      of the specified matrix over to the new matrix, thus effectively cheaply 
      transferring the resources.

   .. cpp:function:: ~DistMatrix()

      All resources owned by the `DistMatrix` are freed upon destruction.

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const DistMatrix<T,MC,MR>& operator=( const DistMatrix<T,U,V>& A )

      Redistribute from any distribution into a standard matrix distribution.

   .. cpp:function:: DistMatrix<T,MC,MR>& operator=( DistMatrix<T,MC,MR>&& A )

      A C++11 move assignment which swaps the metadata of the two matrices as a
      means of cheaply transferring resources.

   .. cpp:function:: void Attach( int height, int width, int colAlign, int rowAlign, T* buffer, int ldim, const Grid& grid )
   .. cpp:function:: void LockedAttach( int height, int width, int colAlign, int rowAlign, const T* buffer, int ldim, const Grid& grid )

      Reconfigure this distributed matrix around an implicit (immutable) 
      ``[MC,MR]`` distributed matrix of the specified dimensions, alignments, 
      local buffer, local leading dimension, and process grid.

   .. cpp:function:: void Attach( Matrix<T>& A, int colAlign, int rowAlign, const elem::Grid& g )
   .. cpp:function:: void LockedAttach( const Matrix<T>& A, int colAlign, int rowAlign, const elem::Grid& g )

      Reconfigure this distributed matrix around an implicit (immutable)
      ``[MC,MR]`` distributed matrix with specified local matrix, alignments,
      and process grid.

   .. cpp:function:: void AlignWith( const DistData& data )

      A mechanism for aligning with a distributed matrix of a different 
      datatype, via ``AlignWith( A.DistData() );``, or just ``AlignWith( A )``,
      as the conversion will happen implicitly.

   .. cpp:function:: void AlignColsWith( const DistData& data )

      A mechanism for aligning with a distributed matrix of a different 
      datatype, via ``AlignColsWith( A )``.

   .. cpp:function:: void AlignRowsWith( const DistData& data )

      A mechanism for aligning with a distributed matrix of a different 
      datatype, via ``AlignRowsWith( A );``

   The following routines primarily exist as a means of avoiding the poor 
   memory bandwidth which results from packing or unpacking large amounts of 
   data without a unit stride. PLAPACK noticed this issue and avoided the 
   problem by carefully (conjugate-)transposing matrices in strategic places,
   usually before a gather or after a scatter, and we follow suit.

   .. cpp:function:: void SumScatterFrom( const DistMatrix<T,MC,STAR>& A )
   .. cpp:function:: void SumScatterUpdate( T alpha, const DistMatrix<T,MC,STAR>& A )

      Simultaneously sum :math:`A[M_C,\star]` within each process row and 
      scatter the entries in each row to form (or update) the result in an 
      :math:`[M_C,M_R]` distribution.

   .. cpp:function:: void SumScatterFrom( const DistMatrix<T,STAR,MR>& A )
   .. cpp:function:: void SumScatterUpdate( T alpha, const DistMatrix<T,STAR,MR>& A )

      Simultaenously sum :math:`A[\star,M_R]` within each process column and 
      scatter the entries in each column to form (or update) the result in an 
      :math:`[M_C,M_R]` distribution.

   .. cpp:function:: void SumScatterFrom( const DistMatrix<T,STAR,STAR>& A )
   .. cpp:function:: void SumScatterUpdate( T alpha, const DistMatrix<T,STAR,STAR>& A )

      Simultaneously sum :math:`A[\star,\star]` over the entire process grid and
      scatter the entries in each row and column to form (or update) the 
      result in an :math:`[M_C,M_R]` distribution.

   .. cpp:function:: void TransposeFrom( const DistMatrix<T,STAR,MC>& A, bool conjugate=false )
   .. cpp:function:: void AdjointFrom( const DistMatrix<T,STAR,MC>& A )

      Set the parent matrix equal to the redistributed (conjugate-)transpose of 
      :math:`A[\star,M_C]`; in particular, 
      :math:`(A[\star,M_C])^H = A^H[M_C,\star]`, so perform an 
      :math:`[M_C,M_R] \leftarrow [M_C,\star]` redistribution on the adjoint of
      `A`, which typically just consists of locally copying (and conjugating) 
      subsets of the data from :math:`A[\star,M_C]`.

   .. cpp:function:: void TransposeFrom( const DistMatrix<T,MR,STAR>& A, bool conjugate=false )
   .. cpp:function:: void AdjointFrom( const DistMatrix<T,MR,STAR>& A )

      This routine is the dual of the above routine, and performs an
      :math:`[M_C,M_R] \leftarrow [\star,M_R]` redistribution on the 
      (conjugate-)transpose of `A`.

   .. rubric:: Basic queries

   .. cpp:function:: DistData DistData() const
   .. cpp:function:: mpi::Comm DistComm() const
   .. cpp:function:: mpi::Comm CrossComm() const
   .. cpp:function:: mpi::Comm RedundantComm() const
   .. cpp:function:: mpi::Comm ColComm() const
   .. cpp:function:: mpi::Comm RowComm() const
   .. cpp:function:: int ColStride() const
   .. cpp:function:: int RowStride() const

   .. rubric:: Diagonal manipulation

   .. cpp:function:: void GetDiagonal( DistMatrix<T,MD,STAR>& d, int offset=0 ) const
   .. cpp:function:: void GetDiagonal( DistMatrix<T,STAR,MD>& d, int offset=0 ) const
   .. cpp:function:: void GetRealPartOfDiagonal( DistMatrix<Base<T>,MD,STAR>& d, int offset=0 ) const
   .. cpp:function:: void GetRealPartOfDiagonal( DistMatrix<Base<T>,STAR,MD>& d, int offset=0 ) const
   .. cpp:function:: void GetImagPartOfDiagonal( DistMatrix<Base<T>,MD,STAR>& d, int offset=0 ) const
   .. cpp:function:: void GetImagPartOfDiagonal( DistMatrix<Base<T>,STAR,MD>& d, int offset=0 ) const

      The :math:`[M_D,\star]` (:math:`[\star,M_D]`) distribution is defined 
      such that its columns (rows) are distributed like diagonals of the 
      standard matrix distribution, ``[MC,MR]``. 
      Thus, `d` can be formed locally if the distribution can
      be aligned with that of the `offset` diagonal of :math:`A[M_C,M_R]`. 

   .. cpp:function:: DistMatrix<T,MD,STAR> GetDiagonal( int offset=0 ) const
   .. cpp:function:: DistMatrix<Base<T>,MD,STAR> GetRealPartOfDiagonal( int offset=0 ) const
   .. cpp:function:: DistMatrix<Base<T>,MD,STAR> GetImagPartOfDiagonal( int offset=0 ) const

      The specified diagonal is returned in an ``[MD,STAR]`` distribution via
      C++11 move semantics.

   .. cpp:function:: void SetDiagonal( const DistMatrix<T,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void SetDiagonal( const DistMatrix<T,STAR,MD>& d, int offset=0 )
   .. cpp:function:: void SetRealPartOfDiagonal( const DistMatrix<Base<T>,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void SetRealPartOfDiagonal( const DistMatrix<Base<T>,STAR,MD>& d, int offset=0 )
   .. cpp:function:: void SetImagPartOfDiagonal( const DistMatrix<Base<T>,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void SetImagPartOfDiagonal( const DistMatrix<Base<T>,STAR,MD>& d, int offset=0 )

      The diagonal (or its real or imaginary part) is set to the passed-in 
      matrix.

   .. cpp:function:: void UpdateDiagonal( const DistMatrix<T,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void UpdateDiagonal( const DistMatrix<T,STAR,MD>& d, int offset=0 )
   .. cpp:function:: void UpdateRealPartOfDiagonal( const DistMatrix<Base<T>,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void UpdateRealPartOfDiagonal( const DistMatrix<Base<T>,STAR,MD>& d, int offset=0 )
   .. cpp:function:: void UpdateImagPartOfDiagonal( const DistMatrix<Base<T>,MD,STAR>& d, int offset=0 )
   .. cpp:function:: void UpdateImagPartOfDiagonal( const DistMatrix<Base<T>,STAR,MD>& d, int offset=0 )

      The diagonal (or its real or imaginary part) is updated with a scalar 
      multiple of the passed-in matrix.

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<T,MC,MR>` = :cpp:type:`DistMatrix\<T>`.

.. cpp:type:: class DistMatrix<double>

.. cpp:type:: class DistMatrix<double,MC,MR>

   The underlying datatype is the set of double-precision real numbers. 

.. cpp:type:: class DistMatrix<Complex<double>>

.. cpp:type:: class DistMatrix<Complex<double>,MC,MR>

   The underlying datatype is the set of double-precision complex numbers. 

.. cpp:type:: class DistMatrix<Real>

.. cpp:type:: class DistMatrix<Real,MC,MR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>>

.. cpp:type:: class DistMatrix<Complex<Real>,MC,MR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`. 

.. cpp:type:: class DistMatrix<F>

.. cpp:type:: class DistMatrix<F,MC,MR>

   The underlying datatype `F` is a field.

``[MC,* ]``
-----------

This distribution is often used as part of matrix-matrix multiplication. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,MC,STAR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,MC,STAR>`.

.. cpp:type:: class DistMatrix<double,MC,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,MC,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,MC,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,MC,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,MC,STAR>

   The underlying datatype `F` is a field.

``[* ,MR]``
-----------
This distribution is also frequently used for matrix-matrix multiplication. 
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the row alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} \\
     \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} & \{2,3\} & \{4,5\} & \{0,1\} 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,STAR,MR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,MR>`.

.. cpp:type:: class DistMatrix<double,STAR,MR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,MR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,MR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,MR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,MR>

   The underlying datatype `F` is a field.

``[MR,MC]``
-----------
This is essentially the transpose of the standard matrix distribution, 
``[MC,MR]``. For a
:math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process grid,
individual entries would be owned by the following processes (assuming the 
column and row alignments are both 0):

.. math::

   \left(\begin{array}{ccccccc}
     0 & 1 & 0 & 1 & 0 & 1 & 0 \\
     2 & 3 & 2 & 3 & 2 & 3 & 2 \\
     4 & 5 & 4 & 5 & 4 & 5 & 4 \\
     0 & 1 & 0 & 1 & 0 & 1 & 0 \\
     2 & 3 & 2 & 3 & 2 & 3 & 2 \\
     4 & 5 & 4 & 5 & 4 & 5 & 4 \\
     0 & 1 & 0 & 1 & 0 & 1 & 0 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,MR,MC>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,MR,MC>`.

.. cpp:type:: class DistMatrix<double,MR,MC>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,MR,MC>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,MR,MC>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,MR,MC>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,MR,MC>

   The underlying datatype `F` is a field.
 
``[MR,* ]``
-----------
This is the transpose of the ``[* ,MR]`` distribution and is, like many of 
the previous distributions, useful for matrix-matrix multiplication.
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,MR,STAR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,MR,STAR>`.

.. cpp:type:: class DistMatrix<double,MR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,MR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,MR,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,MR,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,MR,STAR>

   The underlying datatype `F` is a field.

``[* ,MC]``
-----------
This is the transpose of the ``[MC,*]`` distribution and is, like many of 
the previous distributions, useful for matrix-matrix multiplication.
For a :math:`7 \times 7` matrix distributed over a :math:`2 \times 3` process 
grid, individual entries would be owned by the following processes (assuming 
the column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} \\
     \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & \{0,2,4\} & \{1,3,5\} & 
     \{0,2,4\} 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,STAR,MC>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,MC>`.

.. cpp:type:: class DistMatrix<double,STAR,MC>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,MC>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,MC>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,MC>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,MC>

   The underlying datatype `F` is a field.

``[MD,* ]``
-----------
**TODO**, but not as high of a priority since the :math:`[M_D,\star]` 
distribution is not as crucial for end users as many other details that have 
not yet been documented.

.. cpp:type:: class DistMatrix<T,MD,STAR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,MD,STAR>`.

.. cpp:type:: class DistMatrix<double,MD,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,MD,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,MD,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,MD,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,MD,STAR>

   The underlying datatype `F` is a field.

``[* ,MD]``
-----------
**TODO**, but not as high of a priority since the :math:`[\star,M_D]` 
distribution is not as crucial for end users as many other details that have 
not yet been documented.

.. cpp:type:: class DistMatrix<T,STAR,MD>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,MD>`.

.. cpp:type:: class DistMatrix<double,STAR,MD>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,MD>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,MD>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,MD>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,MD>

   The underlying datatype `F` is a field.

``[VC,* ]``
-----------
This distribution makes use of a 1d distribution which uses a column-major 
ordering of the entire process grid. Since 1d distributions are useful for 
distributing *vectors*, and a *column-major* ordering is used, the distribution 
symbol is ``VC``. Again using the simple :math:`2 \times 3` process grid, 
with a zero column alignment, each entry of a :math:`7 \times 7` matrix 
would be owned by the following sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,VC,STAR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,VC,STAR>`.

.. cpp:type:: class DistMatrix<double,VC,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,VC,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,VC,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,VC,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,VC,STAR>

   The underlying datatype `F` is a field.

``[* ,VC]``
-----------
This is the transpose of the above ``[VC,* ]`` distribution. On the standard
:math:`2 \times 3` process grid with a row alignment of zero, a 
:math:`7 \times 7` matrix would be distributed as:

.. math::

   \left(\begin{array}{ccccccc}
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 \\
   0 & 1 & 2 & 3 & 4 & 5 & 0 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,STAR,VC>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,VC>`.

.. cpp:type:: class DistMatrix<double,STAR,VC>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,VC>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,VC>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,VC>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,VC>

   The underlying datatype `F` is a field.

``[VR,* ]``
-----------
This distribution makes use of a 1d distribution which uses a row-major 
ordering of the entire process grid. Since 1d distributions are useful for 
distributing *vectors*, and a *row-major* ordering is used, the distribution 
symbol is ``VR``. Again using the simple :math:`2 \times 3` process grid, 
with a zero column alignment, each entry of a :math:`7 \times 7` matrix 
would be owned by the following sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,VR,STAR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,VR,STAR>`.

.. cpp:type:: class DistMatrix<double,VR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,VR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,VR,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,VR,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,VR,STAR>

   The underlying datatype `F` is a field.

``[* ,VR]``
-----------
This is the transpose of the above ``[VR,* ]`` distribution. On the standard
:math:`2 \times 3` process grid with a row alignment of zero, a 
:math:`7 \times 7` matrix would be distributed as:

.. math::

   \left(\begin{array}{ccccccc}
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,STAR,VR>

   **TODO:** Add the member functions. 

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,VR>`.

.. cpp:type:: class DistMatrix<double,STAR,VR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,VR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,VR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,VR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,VR>

   The underlying datatype `F` is a field.

``[* ,* ]``
-----------
This "distribution" actually redundantly stores every entry of the associated
matrix on every process. Again using a :math:`2 \times 3` process grid, 
the entries of a :math:`7 \times 7` matrix would be owned by the following
sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} 
   \end{array}\right)

.. cpp:type:: class DistMatrix<T,STAR,STAR>

   **TODO:** Add the member functions. 

``[o ,o ]``
-----------
This ``distribution`` stores the entire matrix on a single process.

.. cpp:type:: class DistMatrix<T,CIRC,CIRC>

Special cases used in Elemental
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMatrix\<T,STAR,STAR>`.

.. cpp:type:: class DistMatrix<double,STAR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: class DistMatrix<Complex<double>,STAR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: class DistMatrix<Real,STAR,STAR>

   The underlying datatype `Real` is real.

.. cpp:type:: class DistMatrix<Complex<Real>,STAR,STAR>

   The underlying datatype :cpp:type:`Complex\<Real>` is complex with base type 
   `Real`.

.. cpp:type:: class DistMatrix<F,STAR,STAR>

   The underlying datatype `F` is a field.

