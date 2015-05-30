AbstractDistMatrix
------------------

This abstract class defines the list of member functions that are guaranteed 
to be available for all matrix distributions and whose prototype does not 
depend upon the particular matrix distribution.

One of the many conveniences provided by :cpp:class::`AbstractDistMatrix\<T>` 
is the ability for individual processes to easily modify arbitrary 
(possibly non-local) entries of the distribute matrix using a combination of
``Reserve``, ``QueueUpdate``, and ``ProcessQueues``. For example:

.. code-block:: cpp

   #include "El.hpp"
   using namespace El;
   ...
   DistMatrix<double> A;
   Zeros( A, 100, 100 );
   if( A.DistRank() == 0 )
   {
       A.Reserve( 3 );
       A.QueueUpdate( 50, 50, 1. );
       A.QueueUpdate( 51, 51, 2. );
       A.QueueUpdate( 52, 52, 3. );
   }
   else if( A.DistRank() == 1 )
   {
       A.Reserve( 2 );
       A.QueueUpdate( 0, 0, 17. );
       A.QueueUpdate( 1, 0, 18. );
   }
   A.ProcessQueues();

.. cpp:class:: AbstractDistMatrix<T>

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

   .. cpp:function:: void Resize( Int height, Int width )
   .. cpp:function:: void Resize( Int height, Int width, Int ldim )

      Reconfigure the matrix so that it is `height` :math:`\times` `width`.
      Optionally, the local leading dimension may also be specified.

   .. cpp:function:: void MakeConsistent()

      Gives every non-participating process a copy of the metadata stored
      by the root process in the distribution communicator.

   .. rubric:: Realignment

   .. cpp:function:: void Align( Int colAlign, Int rowAlign )
   .. cpp:function:: void AlignCols( Int colAlign )
   .. cpp:function:: void AlignRows( Int rowAlign )
 
      Aligns the row or column distribution (or both).

   .. cpp:function:: void FreeAlignments()

      Free all alignment constaints.

   .. cpp:function:: void SetRoot( Int root )
      
      For querying and changing the process rank in the cross communicator which
      owns the data.

   .. cpp:function:: void AlignWith( const DistData& data )
   .. cpp:function:: void AlignColsWith( const DistData& data )
   .. cpp:function:: void AlignRowsWith( const DistData& data )

      Aligns the row or column distribution (or both) as necessary to conform 
      with the specified distribution data.

   .. cpp:function:: void AlignAndResize( Int colAlign, Int rowAlign, Int height, Int width, bool force=false )
   .. cpp:function:: void AlignColsAndResize( Int colAlign, Int height, Int width, bool force=false )
   .. cpp:function:: void AlignRowsAndResize( Int rowAlign, Int height, Int width, bool force=false )

      Attempt to realign the row or column distribution (or both), with 
      the realignment being optionally *forced*, and then resize the distributed
      matrix to the specified size.

   .. rubric:: Buffer attachment

   .. cpp:function:: void Attach( Int height, Int width, const Grid& grid, Int colAlign, Int rowAlign, T* buffer, Int ldim, Int root=0 )
   .. cpp:function:: void LockedAttach( Int height, Int width, const Grid& grid, Int colAlign, Int rowAlign, const T* buffer, Int ldim, Int root=0 )

      Reconfigure around the (immutable) buffer of an implicit distributed
      matrix with the specified dimensions, alignments, process grid, and 
      local leading dimension.

   .. cpp:function:: void Attach( Int height, Int width, const Grid& grid, Int colAlign, Int rowAlign, Matrix<T>& A, Int root=0 )
   .. cpp:function:: void LockedAttach( Int height, Int width, const Grid& grid, Int colAlign, Int rowAlign, const Matrix<T>& A, Int root=0 )

      Reconfigure around the (immutable) local matrix of an implicit distributed
      matrix with the specified alignments, process grid, and local leading
      dimension.

   .. rubric:: Basic queries

   .. cpp:function:: Int Height() const
   .. cpp:function:: Int Width() const

      Return the height (width) of the distributed matrix.

   .. cpp:function:: Int DiagonalLength( Int offset=0 ) const

      Return the length of the specified diagonal of the distributed matrix.

   .. cpp:function:: bool Viewing() const

      Return true if this matrix is viewing another.

   .. cpp:function:: bool Locked() const

      Return true if this matrix is viewing another in a manner that does not
      allow for modifying the viewed data.

   .. cpp:function:: Int LocalHeight() const
   .. cpp:function:: Int LocalWidth() const

      Return the height (width) of the local matrix stored by a particular 
      process.

   .. cpp:function:: Int LDim() const

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

   .. cpp:function:: T* Buffer( Int iLoc, Int jLoc )
   .. cpp:function:: const T* LockedBuffer( Int iLoc, Int jLoc ) const

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

   .. cpp:function:: Int ColAlign() const
   .. cpp:function:: Int RowAlign() const

      Return the rank of the member of our :cpp:func:`ColComm` or 
      :cpp:func:`RowComm` assigned to the top-left entry of the matrix.

   .. cpp:function:: Int ColShift() const
   .. cpp:function:: Int RowShift() const

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
      :cpp:class:`DistMatrix\<T,VC,STAR>`, where the column communicator is 
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
      for :cpp:class:`DistMatrix\<T,CIRC,CIRC>`, this is 
      :cpp:func:`Grid::VCComm`.

   .. cpp:function:: mpi::Comm RedundantComm() const

      The communicator over which data is redundantly stored. For instance,
      for :cpp:class:`DistMatrix\<T,MC,STAR>`, this is 
      :cpp:func:`Grid::RowComm`.

   .. cpp:function:: Int ColRank() const
   .. cpp:function:: Int RowRank() const
   .. cpp:function:: Int PartialColRank() const
   .. cpp:function:: Int PartialRowRank() const
   .. cpp:function:: Int PartialUnionColRank() const
   .. cpp:function:: Int PartialUnionRowRank() const
   .. cpp:function:: Int DistRank() const
   .. cpp:function:: Int CrossRank() const
   .. cpp:function:: Int RedundantRank() const

      Return our rank in our :cpp:func:`ColComm`, :cpp:func:`RowComm`,
      :cpp:func:`PartialColComm`, :cpp:func:`PartialRowComm`, 
      :cpp:func:`PartialUnionColComm`, :cpp:func:`PartialUnionRowComm`,
      :cpp:func:`DistComm`, :cpp:func:`CrossComm`, or :cpp:func:`RedundantComm`,
      respectively.

   .. cpp:function:: Int ColStride() const
   .. cpp:function:: Int RowStride() const
   .. cpp:function:: Int PartialColStride() const
   .. cpp:function:: Int PartialRowStride() const
   .. cpp:function:: Int PartialUnionColStride() const
   .. cpp:function:: Int PartialUnionRowStride() const
   .. cpp:function:: Int DistSize() const
   .. cpp:function:: Int CrossSize() const
   .. cpp:function:: Int RedundantSize() const

      Return the number of processes within a particular communicator associated
      with the distributed matrix. For communicators associated with 
      distributions of either the rows or columns of a matrix, the communicator
      size is equal to the distance (or *stride*) between successive row or 
      column indices assigned to a particular process.

   .. cpp:function:: Int Root() const

      Return the rank of the member of our cross communicator 
      (:cpp:func:`CrossComm`) which can store data.

   .. cpp:function:: bool Participating() const

      Return true if this process can be assigned matrix data (that is, if
      this process is both in the process grid and the root of 
      :cpp:func:`CrossComm`).

   .. cpp:function:: Int RowOwner( Int i ) const

      Return the rank (in :cpp:func:`ColComm`) of the process which owns 
      row `i`.

   .. cpp:function:: Int ColOwner( Int j ) const

      Return the rank (in :cpp:func:`RowComm`) of the process which owns 
      column `j`.

   .. cpp:function:: Int Owner( Int i, Int j ) const

      Return the rank (in :cpp:func:`DistComm`) of the process which owns entry
      `(i,j)`.

   .. cpp:function:: Int GlobalRow( Int iLoc ) const
   .. cpp:function:: Int GlobalCol( Int jLoc ) const

      Return the global row (column) index corresponding to the given local row
      (column) index.

   .. cpp:function:: Int LocalRow( Int i ) const
   .. cpp:function:: Int LocalCol( Int j ) const

      Return the local row (column) index for row `i` (`j`); if this process
      is not assigned row `i` (column `j`), then throw an exception.

   .. cpp:function:: Int LocalRowOffset( Int i ) const
   .. cpp:function:: Int LocalColOffset( Int j ) const
 
      Return the number of local rows (columns) occurring before the given
      global row (column) index.

   .. cpp:function:: bool IsLocalRow( Int i ) const
   .. cpp:function:: bool IsLocalCol( Int j ) const
   .. cpp:function:: bool IsLocal( Int i, Int j ) const

      Return true if the row, column, or entry, respectively, is assigned to
      this process.

   .. cpp:function:: DistData DistData() const

      Returns a description of the distribution and alignment information


   .. rubric:: Single-entry manipulation (global)

   .. cpp:function:: T Get( Int i, Int j ) const
   .. cpp:function:: Base<T> GetRealPart( Int i, Int j ) const
   .. cpp:function:: Base<T> GetImagPart( Int i, Int j ) const

      Return the `(i,j)` entry (or its real or imaginary part) of the global 
      matrix.

   .. cpp:function:: void Set( Int i, Int j, T alpha )
   .. cpp:function:: void SetRealPart( Int i, Int j, Base<T> alpha )
   .. cpp:function:: void SetImagPart( Int i, Int j, Base<T> alpha )

      Set the `(i,j)` entry (or its real or imaginary part) of the global 
      matrix to :math:`\alpha`. 

   .. cpp:function:: void Update( Int i, Int j, T alpha )
   .. cpp:function:: void UpdateRealPart( Int i, Int j, Base<T> alpha )
   .. cpp:function:: void UpdateImagPart( Int i, Int j, Base<T> alpha )

      Add :math:`\alpha` to the `(i,j)` entry (or its real or imaginary part) 
      of the global matrix. 

   .. cpp:function:: void MakeReal( Int i, Int j )

      Force the :math:`(i,j)` entry of the global matrix to be real.

   .. cpp:function:: void Conjugate( Int i, Int j )

      Conjugate the :math:`(i,j)` entry of the global matrix.

   .. rubric:: Batch remote entry updates

   The following set of routines provide a convenient mechanism for allowing
   all processes to contribute updates to arbitrary entries of the 
   distributed matrix. Each process should begin by calling ``Reserve`` with
   an upper bound on the number of remote entries to contribute, followed
   by calling ``QueueUpdate`` for each (potentially remote) update, and then
   all processes must collectively call ``ProcessQueues``.
   
   .. cpp:function:: void Reserve( Int numRemoteEntries )

   .. cpp:function:: void QueueUpdate( const Entry<T>& entry )
   .. cpp:function:: void QueueUpdate( Int i, Int j, T value )

   .. cpp:function:: void ProcessQueues()

   .. rubric:: Single-entry manipulation (local)

   .. cpp:function:: T GetLocal( Int iLoc, Int jLoc ) const
   .. cpp:function:: Base<T> GetRealPartLocal( Int iLoc, Int jLoc ) const
   .. cpp:function:: Base<T> GetLocalImagPart( Int iLoc, Int jLoc ) const

      Return the :math:`(iLoc,jLoc)` entry (or its real or imaginary part) of 
      our local matrix.

   .. cpp:function:: void SetLocal( Int iLoc, Int jLoc, T alpha )
   .. cpp:function:: void SetLocalRealPart( Int iLoc, Int jLoc, Base<T> alpha )
   .. cpp:function:: void SetLocalImagPart( Int iLoc, Int jLoc, Base<T> alpha )

      Set the `(iLoc,jLoc)` entry (or its real or imaginary part) of our 
      local matrix to :math:`\alpha`.

   .. cpp:function:: void UpdateLocal( Int iLoc, Int jLoc, T alpha )
   .. cpp:function:: void UpdateRealPartLocal( Int iLoc, Int jLoc, Base<T> alpha )
   .. cpp:function:: void UpdateLocalImagPart( Int iLoc, Int jLoc, Base<T> alpha )

      Add :math:`\alpha` to the `(iLoc,jLoc)` entry (or its real or 
      imaginary part) of our local matrix.

   .. cpp:function:: void MakeLocalReal( Int iLoc, Int jLoc )

      Force the `(iLoc,jLoc)` entry of our local matrix to be real.

   .. cpp:function:: void ConjugateLocal( Int iLoc, Int jLoc )

      Conjugate the `(iLoc,jLoc)` entry of our local matrix.

   .. rubric:: Assertions

   .. cpp:function:: void ComplainIfReal() const
   .. cpp:function:: void AssertNotLocked() const
   .. cpp:function:: void AssertNotStoringData() const
   .. cpp:function:: void AssertValidEntry( Int i, Int j ) const
   .. cpp:function:: void AssertValidSubmatrix( Int i, Int j, Int height, Int width ) const
   .. cpp:function:: void AssertSameGrid( const Grid& grid ) const
   .. cpp:function:: void AssertSameSize( Int height, Int width ) const

.. cpp:class:: AbstractDistMatrix<F>

   An instance of `AbstractDistMatrix` where the underlying datatype is 
   assumed to be a field.

.. cpp:class:: AbstractDistMatrix<Real>

   An instance of `AbstractDistMatrix` where the underlying datatype is real
   (e.g., ``float`` or ``double``).

.. cpp:class:: AbstractDistMatrix<Base<F>>

   An instance of `AbstractDistMatrix` where the underlying datatype is the
   underlying real datatype from a field (e.g., ``double`` is the base type
   of ``Complex<double>``).

.. cpp:class:: AbstractDistMatrix<Complex<Base<F>>>

   An instance of `AbstractDistMatrix` where the underlying datatype is the
   complex extension of the base type of the field `F` (
   (e.g., ``Complex<double>`` is the complex extension of both ``double``
   and ``Complex<double>``).

.. cpp:class:: AbstractDistMatrix<Int>

   An instance of `AbstractDistMatrix` where the underlying datatype is 
   an ``int``.

.. cpp:class:: DistData

   .. cpp:member:: Distribution colDist

      The :cpp:enum:`Distribution` scheme used within each column of the matrix.
   
   .. cpp:member:: Distribution rowDist

      The :cpp:enum:`Distribution` scheme used within each row of the matrix.

   .. cpp:member:: Int colAlign

      The rank in the :cpp:func:`AbstractDistMatrix\<T>::ColComm` which is
      assigned the top-left entry of the matrix.

   .. cpp:member:: Int rowAlign

      The rank in the :cpp:func:`AbstractDistMatrix\<T>::RowComm` which
      is assigned the top-left entry of the matrix. 

   .. cpp:member:: Int root

      The member of the :cpp:func:`AbstractDistMatrix\<T>::CrossComm` which
      is assigned ownership of the matrix.

   .. cpp:member:: const Grid* grid

      An immutable pointer to the underlying process grid of the distributed
      matrix.

   .. cpp:function:: DistData( const AbstractDistMatrix<T>& A )

      Construct the distribution data of any instance of 
      :cpp:class:`AbstractDistMatrix\<T>`.

