DistGraph (C++ interface)
=========================

.. cpp:class:: DistGraph

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistGraph( mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: DistGraph( Int numVertices, mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: DistGraph( Int numSources, Int numTargets, mpi::Comm comm=mpi::COMM_WORLD )

   .. cpp:function:: DistGraph( const Graph& graph )

   .. cpp:function:: DistGraph( const DistGraph& graph ) 

   .. cpp:function:: ~DistGraph()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const DistGraph& operator=( const Graph& A )

   .. cpp:function:: const DistGraph& operator=( const DistGraph& A )

   .. cpp:function:: DistGraph operator()( Range<Int> I, Range<Int> J ) const
   .. cpp:function:: DistGraph operator()( Range<Int> I, const vector<Int>& J ) const
   .. cpp:function:: DistGraph operator()( const vector<Int>& I, Range<Int> J ) const
   .. cpp:function:: DistGraph operator()( const vector<Int>& I, const vector<Int>& J ) const

      Make a copy of a subgraph

   .. cpp:function:: void Empty( bool clearMemory=true )

   .. cpp:function:: void Resize( Int numVertices )
   .. cpp:function:: void Resize( Int numSources, Int numTargets )

   .. cpp:function:: void SetComm( mpi::Comm comm )

   .. cpp:function:: void Reserve( Int numLocalEdges, Int numRemoteEdges=0 )

   .. cpp:function:: void Connect( Int source, Int target )
   .. cpp:function:: void Disconnect( Int source, Int target )

   .. cpp:function:: void ConnectLocal( Int localSource, Int target )
   .. cpp:function:: void DisconnectLocal( Int localSource, Int target )

   .. cpp:function:: void QueueConnection( Int source, Int target, bool passive=true )
   .. cpp:function:: void QueueDisconnection( Int source, Int target, bool passive=true )

   .. cpp:function:: void QueueLocalConnection( Int localSource, Int target )
   .. cpp:function:: void QueueLocalDisconnection( Int localSource, Int target )

   .. cpp:function:: void ProcessQueues()
   .. cpp:function:: void ProcessLocalQueues()

   .. rubric:: Basic queries

   .. cpp:function:: Int NumSources() const
   .. cpp:function:: Int NumTargets() const
   .. cpp:function:: Int FirstLocalSource() const
   .. cpp:function:: Int NumLocalSources() const
   .. cpp:function:: Int NumLocalEdges() const
   .. cpp:function:: Int Capacity() const
   .. cpp:function:: bool LocallyConsistent() const

   .. cpp:function:: mpi::Comm Comm() const
   .. cpp:function:: Int Blocksize() const
   .. cpp:function:: int SourceOwner( Int source ) const
   .. cpp:function:: Int GlobalSource( Int localSource ) const

   .. cpp:function:: Int Source( Int localEdge ) const
   .. cpp:function:: Int Target( Int localEdge ) const
   .. cpp:function:: Int EdgeOffset( Int localSource ) const
   .. cpp:function:: Int NumConnections( Int localSource ) const

   .. cpp:function:: Int* SourceBuffer() 
   .. cpp:function:: Int* TargetBuffer()
   .. cpp:function:: const Int* LockedSourceBuffer() const
   .. cpp:function:: const Int* LockedTargetBuffer() const
