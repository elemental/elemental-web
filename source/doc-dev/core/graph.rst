Graph
=====

.. cpp:class:: Graph

   .. rubric:: Constructors and destructors

   .. cpp:function:: Graph()

   .. cpp:function:: Graph( Int numVertices )

   .. cpp:function:: Graph( Int numSources, Int numTargets )

   .. cpp:function:: Graph( const Graph& graph )

   .. cpp:function:: Graph( const DistGraph& graph ) 

   .. cpp:function:: ~Graph()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const Graph& operator=( const Graph& A )

   .. cpp:function:: const Graph& operator=( const DistGraph& A )

   .. cpp:function:: Graph operator()( Range<Int> I, Range<Int> J ) const

      Make a copy of a contiguous subgraph

   .. cpp:function:: void Empty( bool clearMemory=true )

   .. cpp:function:: void Resize( Int numVertices )
   .. cpp:function:: void Resize( Int numSources, Int numTargets )

   .. cpp:function:: void Reserve( Int numEdges )

   .. cpp:function:: void Connect( Int source, Int target )
   .. cpp:function:: void Disconnect( Int source, Int target )

   .. cpp:function:: void QueueConnection( Int source, Int target )
   .. cpp:function:: void QueueDisconnection( Int source, Int target )
   .. cpp:function:: void ProcessQueues()

   .. rubric:: Basic queries

   .. cpp:function:: Int NumSources() const
   .. cpp:function:: Int NumTargets() const
   .. cpp:function:: Int NumEdges() const
   .. cpp:function:: Int Capacity() const
   .. cpp:function:: bool Consistent() const

   .. cpp:function:: Int Source( Int edge ) const
   .. cpp:function:: Int Target( Int edge ) const
   .. cpp:function:: Int EdgeOffset( Int source ) const
   .. cpp:function:: Int NumConnections( Int source ) const

   .. cpp:function:: Int* SourceBuffer() 
   .. cpp:function:: Int* TargetBuffer()
   .. cpp:function:: const Int* LockedSourceBuffer() const
   .. cpp:function:: const Int* LockedTargetBuffer() const
