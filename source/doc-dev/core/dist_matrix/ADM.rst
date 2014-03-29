AbstractDistMatrix
------------------

This abstract class defines the list of member functions that are guaranteed 
to be available for all matrix distributions and whose prototype does not 
depend upon the particular matrix distribution; the 
:cpp:type:`GeneralDistMatrix\<T,U,V>` class exists for general routines whose 
prototype *does* depend upon the particular matrix distribution.

.. cpp:type:: class AbstractDistMatrix<T>

   .. rubric:: Constructors and destructors

   .. cpp:function:: AbstractDistMatrix( AbstractDistMatrix<T>&& A ) noexcept

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
   .. cpp:function:: void Resize( int height, int width, int ldim )

      Reconfigure the matrix so that it is `height` :math:`\times` `width`.
      Optionally, the local leading dimension may also be specified.

   .. cpp:function:: void MakeConsistent()

      Gives every non-participating process a copy of the metadata stored
      by the root process in the distribution communicator.

   .. rubric:: Realignment

   .. cpp:function:: void Align( int colAlign, int rowAlign )
   .. cpp:function:: void AlignCols( int colAlign )
   .. cpp:function:: void AlignRows( int rowAlign )
 
      Aligns the row or column distribution (or both).

   .. cpp:function:: void FreeAlignments()

      Free all alignment constaints.

   .. cpp:function:: void SetRoot( int root )
      
      For querying and changing the process rank in the cross communicator which
      owns the data.

   .. cpp:function:: void AlignWith( const DistData& data )
   .. cpp:function:: void AlignColsWith( const DistData& data )
   .. cpp:function:: void AlignRowsWith( const DistData& data )

      Aligns the row or column distribution (or both) as necessary to conform 
      with the specified distribution data.

   .. cpp:function:: void AlignAndResize( int colAlign, int rowAlign, int height, int width, bool force=false )
   .. cpp:function:: void AlignColsAndResize( int colAlign, int height, int width, bool force=false )
   .. cpp:function:: void AlignRowsAndResize( int rowAlign, int height, int width, bool force=false )

      Attempt to realign the row or column distribution (or both), with 
      the realignment being optionally *forced*, and then resize the distributed
      matrix to the specified size.

   .. rubric:: Buffer attachment

   .. cpp:function:: void Attach( int height, int width, const Grid& grid, int colAlign, int rowAlign, T* buffer, int ldim, int root=0 )
   .. cpp:function:: void LockedAttach( int height, int width, const Grid& grid, int colAlign, int rowAlign, const T* buffer, int ldim, int root=0 )

      Reconfigure around the (immutable) buffer of an implicit distributed
      matrix with the specified dimensions, alignments, process grid, and 
      local leading dimension.

   .. cpp:function:: void Attach( int height, int width, const Grid& grid, int colAlign, int rowAlign, Matrix<T>& A, int root=0 )
   .. cpp:function:: void LockedAttach( int height, int width, const Grid& grid, int colAlign, int rowAlign, const Matrix<T>& A, int root=0 )

      Reconfigure around the (immutable) local matrix of an implicit distributed
      matrix with the specified alignments, process grid, and local leading
      dimension.

   .. rubric:: Basic queries

   .. cpp:function:: int Height() const
   .. cpp:function:: int Width() const

      Return the height (width) of the distributed matrix.

   .. cpp:function:: int DiagonalLength( int offset=0 ) const

      Return the length of the specified diagonal of the distributed matrix.

   .. cpp:function:: bool Viewing() const

      Return true if this matrix is viewing another.

   .. cpp:function:: bool Locked() const

      Return true if this matrix is viewing another in a manner that does not
      allow for modifying the viewed data.

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

      Return true if the column (row) alignment is constrained.

   .. cpp:function:: bool RootConstrained() const

      Return if the root (the alignment with respect to the 
      :cpp:func:`CrossComm`) is constrained.

   .. cpp:function:: int ColAlign() const
   .. cpp:function:: int RowAlign() const

      Return the rank of the member of our :cpp:func:`ColComm` or 
      :cpp:func:`RowComm` assigned to the top-left entry of the matrix.

   .. cpp:function:: int ColShift() const
   .. cpp:function:: int RowShift() const

      Return the first row or column to be locally assigned to this process,
      respectively.

   .. cpp:function:: mpi::Comm ColComm() const

      The communicator used to distribute each column of the matrix.

   .. cpp:function:: mpi::Comm RowComm() const

      The communicator used to distribute each row of the matrix.

   .. cpp:function:: mpi::Comm PartialColComm() const
   .. cpp:function:: mpi::Comm PartialUnionColComm() const

      The :cpp:func:`PartialColComm` is a (not necessarily strict) subset of 
      the :cpp:func:`ColComm`; an
      element-wise distribution of each column over this communicator 
      can be reached by unioning the local data from a distribution over the
      :cpp:func:`ColComm` (via an ``AllGather``) over the 
      :cpp:func:`PartialUnionColComm`. One nontrivial example is for 
      :cpp:type:`DistMatrix\<T,VC,STAR>`, where the column communicator is 
      :cpp:func:`Grid::VCComm`, the partial column communicator is 
      :cpp:func:`Grid::MCComm`, and the partial union column communicator is
      :cpp:func:`Grid::MRComm`.

   .. cpp:function:: mpi::Comm PartialRowComm() const
   .. cpp:function:: mpi::Comm PartialUnionRowComm() const

      These are the same as :cpp:func:`PartialColComm` and 
      :cpp:func:`PartialUnionColComm`, except that they correspond to 
      distributions of the rows of the matrix.

   .. cpp:function:: mpi::Comm DistComm() const

      The communicator used to distribute the entire set of entries of the 
      matrix (in a particular precise sense, the product of :cpp:func:`ColComm`
      and :cpp:func:`RowComm`).

   .. cpp:function:: mpi::Comm CrossComm() const

      The orthogonal complement of the product of :cpp:func:`DistComm` and 
      :cpp:func:`RedundantComm` with respect to the process grid. For instance,
      for :cpp:type:`DistMatrix\<T,CIRC,CIRC>`, this is 
      :cpp:func:`Grid::VCComm`.

   .. cpp:function:: mpi::Comm RedundantComm() const

      The communicator over which data is redundantly stored. For instance,
      for :cpp:type:`DistMatrix\<T,MC,STAR>`, this is :cpp:func:`Grid::RowComm`.

   .. cpp:function:: int ColRank() const
   .. cpp:function:: int RowRank() const
   .. cpp:function:: int PartialColRank() const
   .. cpp:function:: int PartialRowRank() const
   .. cpp:function:: int PartialUnionColRank() const
   .. cpp:function:: int PartialUnionRowRank() const
   .. cpp:function:: int DistRank() const
   .. cpp:function:: int CrossRank() const
   .. cpp:function:: int RedundantRank() const

      Return our rank in our :cpp:func:`ColComm`, :cpp:func:`RowComm`,
      :cpp:func:`PartialColComm`, :cpp:func:`PartialRowComm`, 
      :cpp:func:`PartialUnionColComm`, :cpp:func:`PartialUnionRowComm`,
      :cpp:func:`DistComm`, :cpp:func:`CrossComm`, or :cpp:func:`RedundantComm`,
      respectively.

   .. cpp:function:: int ColStride() const
   .. cpp:function:: int RowStride() const
   .. cpp:function:: int PartialColStride() const
   .. cpp:function:: int PartialRowStride() const
   .. cpp:function:: int PartialUnionColStride() const
   .. cpp:function:: int PartialUnionRowStride() const
   .. cpp:function:: int DistSize() const
   .. cpp:function:: int CrossSize() const
   .. cpp:function:: int RedundantSize() const

      Return the number of processes within a particular communicator associated
      with the distributed matrix. For communicators associated with 
      distributions of either the rows or columns of a matrix, the communicator
      size is equal to the distance (or *stride*) between successive row or 
      column indices assigned to a particular process.

   .. cpp:function:: int Root() const

      Return the rank of the member of our cross communicator 
      (:cpp:func:`CrossComm`) which can store data.

   .. cpp:function:: bool Participating() const

      Return true if this process can be assigned matrix data (that is, if
      this process is both in the process grid and the root of 
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

   .. cpp:function:: int GlobalRow( int iLoc ) const
   .. cpp:function:: int GlobalCol( int jLoc ) const

      Return the global row (column) index corresponding to the given local row
      (column) index.

   .. cpp:function:: int LocalRow( int i ) const
   .. cpp:function:: int LocalCol( int j ) const

      Return the local row (column) index for row `i` (`j`); if this process
      is not assigned row `i` (column `j`), then throw an exception.

   .. cpp:function:: int LocalRowOffset( int i ) const
   .. cpp:function:: int LocalColOffset( int j ) const
 
      Return the number of local rows (columns) occurring before the given
      global row (column) index.

   .. cpp:function:: bool IsLocalRow( int i ) const
   .. cpp:function:: bool IsLocalCol( int j ) const
   .. cpp:function:: bool IsLocal( int i, int j ) const

      Return true if the row, column, or entry, respectively, is assigned to
      this process.

   .. cpp:function:: DistData DistData() const

      Returns a description of the distribution and alignment information


   .. rubric:: Single-entry manipulation (global)

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

   .. rubric:: Single-entry manipulation (local)

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

   .. cpp:function:: void MakeLocalReal( int iLoc, int jLoc )

      Force the `(iLoc,jLoc)` entry of our local matrix to be real.

   .. cpp:function:: void ConjugateLocal( int iLoc, int jLoc )

      Conjugate the `(iLoc,jLoc)` entry of our local matrix.

   .. rubric:: Diagonal manipulation

   .. cpp:function:: void MakeDiagonalReal( int offset=0 )

      Force the specified diagonal to be real.

   .. cpp:function:: void ConjugateDiagonal( int offset=0 )

      Conjugate the specified diagonal.

   .. rubric:: Arbitrary-submatrix manipulation (global)

   .. cpp:function:: void GetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<T,STAR,STAR>& ASub ) const
   .. cpp:function:: void GetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<Base<T>,STAR,STAR>& ASub ) const
   .. cpp:function:: void GetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, DistMatrix<Base<T>,STAR,STAR>& ASub ) const

      Return the submatrix (or its real or imaginary part) with the specified
      row and column indices via `ASub`.

   .. cpp:function:: DistMatrix<T,STAR,STAR> GetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const
   .. cpp:function:: DistMatrix<Base<T>,STAR,STAR> GetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd ) const

      Return the submatrix (or its real or imaginary part) with the specified
      row and column indices via C++11 move semantics.

   .. cpp:function:: void SetSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<T,STAR,STAR>& ASub )
   .. cpp:function:: void SetRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<Base<T>,STAR,STAR>& ASub )
   .. cpp:function:: void SetImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, const DistMatrix<Base<T>,STAR,STAR>& ASub )

      Set the submatrix (or its real or imaginary part) with the specified
      row and column indices equal to the matrix `ASub`.

   .. cpp:function:: void UpdateSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, T alpha, const DistMatrix<T,STAR,STAR>& ASub )
   .. cpp:function:: void UpdateRealPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const DistMatrix<Base<T>,STAR,STAR>& ASub )
   .. cpp:function:: void UpdateImagPartOfSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd, Base<T> alpha, const DistMatrix<Base<T>,STAR,STAR>& ASub )

      Update the submatrix (or its real or imaginary part) with the specified
      row and column indices with `alpha` times `ASub`.

   .. cpp:function:: void MakeSubmatrixReal( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Force the submatrix with the specified row and column indices to be real.

   .. cpp:function:: void ConjugateSubmatrix( const std::vector<int>& rowInd, const std::vector<int>& colInd )

      Conjugate the entries in the submatrix with the specified row and column
      indices.

   .. rubric:: Arbitrary-submatrix manipulation (local)

   .. cpp:function:: void GetLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<T>& ASub ) const
   .. cpp:function:: void GetRealPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<Base<T>>& ASub ) const
   .. cpp:function:: void GetImagPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Matrix<Base<T>>& ASub ) const

      Return the local submatrix (or its real or imaginary part) with the specified
      row and column indices via `ASub`.

   .. cpp:function:: Matrix<T> GetLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const
   .. cpp:function:: Matrix<Base<T>> GetRealPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const
   .. cpp:function:: Matrix<Base<T>> GetImagPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc ) const

      Return the local submatrix (or its real or imaginary part) with the 
      specified row and column indices via C++11 move semantics.

   .. cpp:function:: void SetLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<T>& ASub )
   .. cpp:function:: void SetRealPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void SetImagPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, const Matrix<Base<T>>& ASub )

      Set the local submatrix (or its real or imaginary part) with the specified
      row and column indices equal to the matrix `ASub`.

   .. cpp:function:: void UpdateLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, T alpha, const Matrix<T>& ASub )
   .. cpp:function:: void UpdateRealPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Base<T> alpha, const Matrix<Base<T>>& ASub )
   .. cpp:function:: void UpdateImagPartOfLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc, Base<T> alpha, const Matrix<Base<T>>& ASub )

      Update the local submatrix (or its real or imaginary part) with the 
      specified row and column indices with `alpha` times `ASub`.

   .. cpp:function:: void MakeLocalSubmatrixReal( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc )

      Force the local submatrix with the specified row and column indices to be
      real.

   .. cpp:function:: void ConjugateLocalSubmatrix( const std::vector<int>& rowIndLoc, const std::vector<int>& colIndLoc )

      Conjugate the entries in the local submatrix with the specified row and 
      column indices.

   .. rubric:: Sum over a specified communicator

   .. cpp:function:: void SumOver( mpi::Comm comm )

   .. rubric:: Assertions

   .. cpp:function:: void ComplainIfReal() const
   .. cpp:function:: void AssertNotLocked() const
   .. cpp:function:: void AssertNotStoringData() const
   .. cpp:function:: void AssertValidEntry( int i, int j ) const
   .. cpp:function:: void AssertValidSubmatrix( int i, int j, int height, int width ) const
   .. cpp:function:: void AssertSameGrid( const Grid& grid ) const
   .. cpp:function:: void AssertSameSize( int height, int width ) const

.. cpp:type:: struct DistData

   .. cpp:member:: Distribution colDist

      The :cpp:type:`Distribution` scheme used within each column of the matrix.
   
   .. cpp:member:: Distribution rowDist

      The :cpp:type:`Distribution` scheme used within each row of the matrix.

   .. cpp:member:: int colAlign

      The rank in the :cpp:func:`AbstractDistMatrix\<T>::ColComm` which is
      assigned the top-left entry of the matrix.

   .. cpp:member:: int rowAlign

      The rank in the :cpp:func:`AbstractDistMatrix\<T>::RowComm` which
      is assigned the top-left entry of the matrix. 

   .. cpp:member:: int root

      The member of the :cpp:func:`AbstractDistMatrix\<T>::CrossComm` which
      is assigned ownership of the matrix.

   .. cpp:member:: const Grid* grid

      An immutable pointer to the underlying process grid of the distributed
      matrix.

   .. cpp:function:: DistData( const GeneralDistMatrix<T,U,V>& A )

      Construct the distribution data of any instance of 
      :cpp:type:`GeneralDistMatrix\<T,U,V>`.

