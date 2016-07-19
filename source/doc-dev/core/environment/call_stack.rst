Call stack manipulation
=======================

.. note::

   The following call stack manipulation routines are only available in 
   non-release builds (i.e., Debug) and are meant to allow 
   for the call stack to be printed (via :cpp:func:`DumpCallStack`) when an 
   exception is caught.

.. cpp:function:: void PushCallStack( std::string s )

   Push the given routine name onto the call stack.

.. cpp:function:: void PopCallStack()

   Remove the routine name at the top of the call stack.

.. cpp:function:: void DumpCallStack()

   Print (and empty) the contents of the call stack.

