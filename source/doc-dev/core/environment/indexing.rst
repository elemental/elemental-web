Indexing utilities
==================

.. cpp:function:: Int Shift( Int rank, Int firstRank, Int numProcs )

   Given a element-wise cyclic distribution over `numProcs` processes, 
   where the first entry is owned by the process with rank `firstRank`, 
   this routine returns the first entry owned by the process with rank
   `rank`.

.. cpp:function:: Int Length( Int n, Int shift, Int numProcs )

   Given a vector with :math:`n` entries distributed over `numProcs` 
   processes with shift as defined above, this routine returns the number of 
   entries of the vector which are owned by this process.

.. cpp:function:: Int Length( Int n, Int rank, Int firstRank, Int numProcs )

   Given a vector with :math:`n` entries distributed over `numProcs` 
   processes, with the first entry owned by process `firstRank`, this routine
   returns the number of entries locally owned by the process with rank 
   `rank`.

.. cpp:function:: Int MaxLength( Int n, Int numProcs )

   The maximum result of :cpp:func:`Length` with the given parameters.
   This is useful for padding collective communication routines which are
   almost regular.

.. cpp:function:: Int Mod( Int a, Int b )

   An extension of C++'s ``%`` operator which handles cases where `a` is 
   negative and still returns a result in :math:`[0,b)`.

.. cpp:function:: Int GCD( Int a, Int b )

   Return the greatest common denominator of the integers `a` and `b`.

.. cpp:function:: Unsigned Log2( Unsigned n )

   Return the base-two logarithm of a positive integer.

.. cpp:function:: bool PowerOfTwo( Unsigned n )

   Return whether or not a positive integer is an integer power of two.
