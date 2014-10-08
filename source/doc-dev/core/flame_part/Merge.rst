Merging submatrices
===================
Many matrix algorithms can be formulated as a sequence of operations on 
submatrices which are repeatedly split into smaller (contiguous) submatrices 
and then reformed in a different manner. Such a reformation process requires
only a small (constant) number of operations when the matrices to be "merged" 
are stored contiguously in memory, and so the following routines make this
assumption.

.. note::

   These routines are currently exclusively used within Elemental's 
   :cpp:func:`SlidePartitionUp`, :cpp:func:`SlidePartitionDown`, etc., routines
   and are likely only of use to advanced users in very special circumstances.

.. toctree::
   :maxdepth: 1

   Merge/OneByTwo
   Merge/TwoByOne
   Merge/TwoByTwo
