Blocksize manipulation
======================

.. cpp:function:: Int Blocksize()

   Return the currently chosen algorithmic blocksize. The optimal value 
   depends on the problem size, algorithm, and architecture; the default value
   is 128.

.. cpp:function:: void SetBlocksize( Int blocksize )

   Change the algorithmic blocksize to the specified value.

.. cpp:function:: void PushBlocksizeStack( Int blocksize )

   It is frequently useful to temporarily change the algorithmic blocksize, so 
   rather than having to manually store and reset the current state, one can 
   simply push a new value onto a stack 
   (and later pop the stack to reset the value).

.. cpp:function:: void PopBlocksizeStack() 

   Pops the stack of blocksizes. See above.

.. cpp:function:: Int DefaultBlockHeight()
.. cpp:function:: Int DefaultBlockWidth()

   Returns the default block height (width) for 
   :cpp:type:`BlockMatrix\<scalarType,colDist,rowDist>`.

.. cpp:function:: void SetDefaultBlockHeight( Int mb )
.. cpp:function:: void SetDefaultBlockWidth( Int nb )

   Change the default block height (width) for 
   :cpp:type:`BlockMatrix\<scalarType,colDist,rowDist>`.
