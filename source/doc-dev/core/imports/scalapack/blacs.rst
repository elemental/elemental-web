BLACS
=====
A handful of Basic Linear Algebra Communication Subprograms (BLACS) routines 
are currently exposed to Elemental if ``MATH_LIBS`` was detected to contain a 
recent version of ScaLAPACK.

.. cpp:function:: int blacs::Handle( MPI_Comm comm )
.. cpp:function:: int blacs::GridInit( int bhandle, bool colMajor, int gridHeight, int gridWidth )

.. cpp:function:: int blacs::GridHeight( int context )
.. cpp:function:: int blacs::GridWidth( int context )

.. cpp:function:: int blacs::GridRow( int context )
.. cpp:function:: int blacs::GridCol( int context )

.. cpp:function:: void blacs::FreeHandle( int bhandle )
.. cpp:function:: void blacs::FreeGrid( int context )

.. cpp:function:: void blacs::Exit( bool finished=true )

.. cpp:type:: blacs::Desc

   Currently a typedef to ``std::array<int,9>``.

While the following routine is not a wrapper around a BLACS routine, it is 
the most common means of filling a ``blacs::Desc`` from a ``BlockDistMatrix``:

.. cpp:function:: blacs::Desc FillDesc( const BlockDistMatrix<F>& A, int context )

   Form the descriptor for the distributed matrix `A` using the specified
   context.
