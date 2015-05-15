Graph
=====
The ``Graph`` class allows for the efficient construction and manipulation
of sequentially-stored, sparse graphs within Elemental and is the primary
building block for the :cpp:class:`SparsMatrix\<T>` class. The usual usage
pattern is to construct a trivial graph, e.g., via

  .. code-block:: cpp

     #include "El.hpp"
     ...
     El::Graph graph(numSources,numTargets);
     // Set aside space for the edges to be inserted
     graph.Reserve(numEdgesUpperBound);
     // Iterate over the set of edges to insert
     ...
       // Queue the insertion of a particular edge
       graph.QueueConnection(source,target);
     ...
     // Handle insertation of all of the queued edges
     graph.ProcessQueues();

For example, to create the graph of a 1D lattice, one could run

  .. code-block:: cpp

     #include "El.hpp"
     ...
     El::Graph graph(n);
     graph.Reserve( 2*n );
     for( El::Int i=0; i<n; ++i )
     {
         if( i != 0 )
             graph.QueueConnection( i, i-1 );
         if( i != n-1 )
             graph.QueueConnection( i, i+1 );
     }
     graph.ProcessQueues();

which would be a significantly faster alternative to

  .. code-block:: cpp

     #include "El.hpp"
     ...
     El::Graph graph(n);
     for( El::Int i=0; i<n; ++i )
     {
         if( i != 0 )
             graph.Connect( i, i-1 );
         if( i != n-1 )
             graph.Connect( i, i+1 );
     }

.. cpp:class:: Graph

   .. rubric:: Constructors and destructors

   .. cpp:function:: Graph()

      Construct a trivial graph with zero source and target vertices.

   .. cpp:function:: Graph( Int numVertices )

      Initialize a trivial graph with ``numVertices`` source and target
      vertices (with no edges). Edges can subsequently be added with 
      either the ``Connect`` routine, or a (more efficient) combination of 
      ``Reserve``, ``QueueConnection``, and ``ProcessQueues`` routines.

   .. cpp:function:: Graph( Int numSources, Int numTargets )

      Initialize a trivial graph with ``numSources`` source vertices, 
      ``numTargets`` target vertices, and no edges. Edges can subsequently be 
      added with either the ``Connect`` routine, or a (more efficient) 
      combination of ``Reserve``, ``QueueConnection``, and ``ProcessQueues`` 
      routines.

   .. cpp:function:: Graph( const Graph& graph )

      Construct a new graph as a copy of a given graph.

   .. cpp:function:: Graph( const DistGraph& graph ) 

      Construct a new graph as a copy of a given ``DistGraph`` which was only
      distributed over a single process.

   .. cpp:function:: ~Graph()

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const Graph& operator=( const Graph& A )

      Set this graph equal to a copy of the given graph.

   .. cpp:function:: const Graph& operator=( const DistGraph& A )

      Set this graph equal to a copy of the given trivially-distributed 
      (i.e., over a single process) graph.

   .. cpp:function:: Graph operator()( Range<Int> I, Range<Int> J ) const

      Make a copy of a contiguous subgraph

   .. cpp:function:: void Empty( bool clearMemory=true )

      Set this graph equal to a trivial (:math:`0 \times 0`) graph 
      (and optionally free all previously-used resources)

   .. cpp:function:: void Resize( Int numVertices )
   .. cpp:function:: void Resize( Int numSources, Int numTargets )

      Change the number of source and target vertices.

   .. cpp:function:: void Reserve( Int numEdges )

      Set aside space for the efficient queueing of up to ``numEdges``
      edges.

   .. cpp:function:: void Connect( Int source, Int target )

      Insert a new edge and perform the necessary sorting so that the 
      graph is in a consistent state.

      .. note::

         When multiple edges are to be inserted, this routine should be 
         avoided in favor of a combination of ``Reserve``, multiple 
         ``QueueConnection`` calls, and then ``ProcessQueues``.

   .. cpp:function:: void Disconnect( Int source, Int target )

      Remove an existing edge and perform the necessary sorting so that the 
      graph is in a consistent state.

      .. note::

         When multiple edges are to be removed, this routine should be 
         avoided in favor of a combination of multiple 
         ``QueueDisconnection`` calls followed by a single 
         ``ProcessQueues`` call.

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
