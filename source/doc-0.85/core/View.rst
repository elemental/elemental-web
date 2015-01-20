Viewing submatrices
===================
The following routines form light-weight 
(:math:`O(1)` storage space and construction time) objects which represent 
contiguous submatrices of a given matrix. In many ways, they are an 
object-oriented equivalent of the BLAS convention of representing a matrix
via a pointer, a leading dimension, and its dimensions. Routines with a 
'Locked' prefix return immutable views, whereas routines without the 'Locked'
prefix insist that the data pointed to by the constructed view can be 
modified.

.. toctree::
   :maxdepth: 1

   View/HalfOpen
   View/IndexRanges
   View/OffsetAndSize
   View/Full
