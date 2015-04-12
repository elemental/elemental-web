SparseMatrix
============

.. cpp:class:: SparseMatrix<T>

   .. rubric:: Constructors and destructors

   .. cpp:function:: SparseMatrix()

   .. cpp:function:: SparseMatrix( Int height, Int width )

   .. cpp:function:: SparseMatrix( const SparseMatrix<T>& A )

   .. cpp:function:: SparseMatrix( const DistSparseMatrix<T>& A ) 

   .. cpp:function:: ~SparseMatrix()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const SparseMatrix<T>& operator=( const SparseMatrix<T>& A )

   .. cpp:function:: const SparseMatrix<T>& operator=( const DistSparseMatrix<T>& A )

   .. cpp:function:: SparseMatrix<T> operator()( Range<Int> I, Range<Int> J ) const

      Make a copy of a contiguous submatrix

   .. cpp:function:: void Empty( bool clearMemory=true )

   .. cpp:function:: void Resize( Int height, Int width )

   .. cpp:function:: void Reserve( Int numEntries )

   .. cpp:function:: void Update( const Entry<T>& entry )
   .. cpp:function:: void Update( Int row, Int col, T value )

   .. cpp:function:: void Zero( Int row, Int col )

   .. cpp:function:: void QueueUpdate( const Entry<T>& entry )
   .. cpp:function:: void QueueUpdate( const Int row, Int col, T value )
   .. cpp:function:: void QueueZero( Int row, Int col )
   .. cpp:function:: void ProcessQueues()

   .. rubric:: Basic queries

   .. cpp:function:: Int Height() const
   .. cpp:function:: Int Width() const
   .. cpp:function:: Int NumEntries() const
   .. cpp:function:: Int Capacity() const
   .. cpp:function:: bool Consistent() const
   .. cpp:function:: El::Graph& Graph()
   .. cpp:function:: const El::Graph& LockedGraph() const

   .. cpp:function:: Int Row( Int index ) const
   .. cpp:function:: Int Col( Int index ) const
   .. cpp:function:: T Value( Int index ) const
   .. cpp:function:: Int EntryOffset( Int row ) const
   .. cpp:function:: Int NumConnections( Int row ) const
   .. cpp:function:: Int* SourceBuffer() 
   .. cpp:function:: Int* TargetBuffer()
   .. cpp:function:: T* ValueBuffer()
   .. cpp:function:: const Int* LockedSourceBuffer() const
   .. cpp:function:: const Int* LockedTargetBuffer() const
   .. cpp:function:: const T* LockedValueBuffer() const

Special cases used in Elemental
-------------------------------
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:type:`SparseMatrix\<T>`.

.. cpp:type:: class SparseMatrix<Real>

   Used to denote that the underlying datatype `Real` is real.

.. cpp:type:: class SparseMatrix<Complex<Real> >

   Used to denote that the underlying datatype :cpp:type:`Complex\<Real>` is
   complex with base type `Real`.

.. cpp:type:: class SparseMatrix<F>

   Used to denote that the underlying datatype `F` is a field.

.. cpp:type:: class SparseMatrix<Int>

   When the underlying datatype is a signed integer.

