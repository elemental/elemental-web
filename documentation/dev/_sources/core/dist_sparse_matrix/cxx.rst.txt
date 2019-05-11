DistSparseMatrix (C++ interface)
================================

.. code-block:: cpp

   #include "El.hpp"
   using namespace El;
   ...
   const Int n0 = 50;
   const Int n1 = 100;
   DistSparseMatrix<float> A;
   Zeros( A, n0*n1, n0*n1 );

   const Int localHeight = A.LocalHeight();
   A.Reserve( 5*localHeight );
   for( Int iLoc=0; iLoc<localHeight; ++iLoc )
   {
       const Int i = A.GlobalRow(iLoc);
       const Int x0 = i % n0;
       const Int x1 = i / n0;
       A.QueueLocalUpdate( iLoc, i, 11 );
       if( x0 > 0 )
           A.QueueLocalUpdate( iLoc, s-1, -1 );
       if( x0+1 < n0 )
           A.QueueLocalUpdate( iLoc, s+1, 2 );
       if( x1 > 0 )
           A.QueueLocalUpdate( iLoc, s-n0, -30 );
       if( x1+1 < n1 )
           A.QueueLocalUpdate( iLoc, s+n0, 4 );
   }
   A.ProcessLocalQueues();

.. cpp:class:: DistSparseMatrix<T>

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistSparseMatrix( mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: DistSparseMatrix( Int height, Int width, mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: ~DistSparseMatrix()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: DistSparseMatrix<T> operator()( Range<Int> I, Range<Int> J ) const
   .. cpp:function:: DistSparseMatrix<T> operator()( Range<Int> I, const vector<Int>& J ) const
   .. cpp:function:: DistSparseMatrix<T> operator()( const vector<Int>& I, Range<Int> J ) const
   .. cpp:function:: DistSparseMatrix<T> operator()( const vector<Int>& I, const vector<Int>& J ) const

      Make a copy of a submatrix

   .. cpp:function:: void Empty( bool clearMemory=true )

   .. cpp:function:: void Resize( Int height, Int width )

   .. cpp:function:: void Reserve( Int numLocalEntries, Int numRemoteEntries=0 )

   .. cpp:function:: void Update( const Entry<T>& entry )
   .. cpp:function:: void Update( Int row, Int col, T value )
   .. cpp:function:: void Zero( Int row, Int col )

   .. cpp:function:: void UpdateLocal( const Entry<T>& localEntry )
   .. cpp:function:: void UpdateLocal( Int localRow, Int col, T value )
   .. cpp:function:: void ZeroLocal( Int localRow, Int col )

   .. cpp:function:: void QueueUpdate( const Entry<T>& entry, bool passive=true )
   .. cpp:function:: void QueueUpdate( const Int row, Int col, T value, bool passive=true )
   .. cpp:function:: void QueueZero( Int row, Int col, bool passive=true )

   .. cpp:function:: void QueueLocalUpdate( const Entry<T>& localEntry )
   .. cpp:function:: void QueueLocalUpdate( Int localRow, Int col, T value )
   .. cpp:function:: void QueueLocalZero( Int localRow, Int col )

   .. cpp:function:: void ProcessQueues()
   .. cpp:function:: void ProcessLocalQueues()

   .. rubric:: Basic queries

   .. cpp:function:: Int Height() const
   .. cpp:function:: Int Width() const
   .. cpp:function:: Int FirstLocalRow() const
   .. cpp:function:: Int LocalHeight() const
   .. cpp:function:: Int NumLocalEntries() const
   .. cpp:function:: Int Capacity() const
   .. cpp:function:: bool LocallyConsistent() const
   .. cpp:function:: El::DistGraph& DistGraph()
   .. cpp:function:: const El::DistGraph& LockedDistGraph() const

   .. cpp:function:: Int Row( Int localInd ) const
   .. cpp:function:: Int Col( Int localInd ) const
   .. cpp:function:: T Value( Int localInd ) const
   .. cpp:function:: Int EntryOffset( Int localRow ) const
   .. cpp:function:: Int NumConnections( Int localRow ) const
   .. cpp:function:: Int* SourceBuffer() 
   .. cpp:function:: Int* TargetBuffer()
   .. cpp:function:: T* ValueBuffer()
   .. cpp:function:: const Int* LockedSourceBuffer() const
   .. cpp:function:: const Int* LockedTargetBuffer() const
   .. cpp:function:: const T* LockedValueBuffer() const

   .. cpp:member:: mutable SparseMultMeta<T> multMeta

Special cases used in Elemental
-------------------------------
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special
cases of :cpp:class:`DistSparseMatrix\<T>`.

.. cpp:class:: DistSparseMatrix<Real>

   Used to denote that the underlying datatype `Real` is real.

.. cpp:class:: DistSparseMatrix<Complex<Real> >

   Used to denote that the underlying datatype :cpp:type:`Complex\<Real>` is
   complex with base type `Real`.

.. cpp:class:: DistSparseMatrix<F>

   Used to denote that the underlying datatype `F` is a field.

.. cpp:class:: DistSparseMatrix<Int>

   When the underlying datatype is a signed integer.

