DistMultiVec
============

.. cpp:class:: DistMultiVec<T>

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMultiVec( mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: DistMultiVec( Int height, Int width, mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: ~DistMultiVec()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: DistMultiVec<T> operator()( Range<Int> I, Range<Int> J ) const

      Make a copy of a submatrix

   .. cpp:function:: const DistMultiVec<T>& operator=( const DistMultiVec<T>& X )

   .. cpp:function:: const DistMultiVec<T>& operator=( const AbstractDistMatrix<T>& X )

   .. cpp:function:: void Empty()

      Sets the matrix to :math:`0 \times 0` and frees any owned resources.

   .. cpp:function:: void Resize( Int height, Int width )

      Reconfigures the matrix to be `height` :math:`\times` `width`.

   .. cpp:function:: void SetComm( mpi::Comm comm )

   .. rubric:: Basic queries

   .. cpp:function:: Int Height() const
   .. cpp:function:: Int Width() const

      Return the height/width of the matrix.

   .. cpp:function:: Int FirstLocalRow() const

   .. cpp:function:: Int LocalHeight() const

   .. cpp:function:: El::Matrix<T>& Matrix()

   .. cpp:function:: const El::Matrix<T>& LockedMatrix() const

   .. cpp:function:: mpi::Comm Comm() const

   .. cpp:function:: Int Blocksize() const

   .. cpp:function:: int RowOwner( Int i ) const

   .. cpp:function:: Int GlobalRow( Int iLoc ) const

   .. rubric:: Single-entry manipulation

   .. cpp:function:: T Get( Int i, Int j ) const
   .. cpp:function:: T GetLocal( Int iLoc, Int j ) const

      Return a global/local entry

   .. cpp:function:: void Set( Int i, Int j, T alpha )
   .. cpp:function:: void SetLocal( Int iLoc, Int j, T alpha )

      Set entry a global/local entry

   .. cpp:function:: void Update( Int i, Int j, T alpha )
   .. cpp:function:: void UpdateLocal( Int iLoc, Int j, T alpha )

      Add a specifc value to a global/local entry

Special cases used in Elemental
-------------------------------
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`DistMultiVec\<T>`.

.. cpp:type:: class DistMultiVec<Real>

   Used to denote that the underlying datatype `Real` is real.

.. cpp:type:: class DistMultiVec<Complex<Real> >

   Used to denote that the underlying datatype :cpp:type:`Complex\<Real>` is
   complex with base type `Real`.

.. cpp:type:: class DistMultiVec<F>

   Used to denote that the underlying datatype `F` is a field.

.. cpp:type:: DistMultiVecInt>

   When the underlying datatype is a signed integer.

