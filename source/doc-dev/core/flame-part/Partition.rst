Partitioning
============
The following routines are slight tweaks of the FLAME project's 
(as well as PLAPACK's) approach to submatrix tracking; the difference is that 
they have "locked" versions, which are meant for creating partitionings where 
the submatrices cannot be modified.

.. toctree::
   :maxdepth: 1

   Partition/Down
   Partition/Up
   Partition/Right
   Partition/Left
   Partition/DownDiag
   Partition/DownOffsetDiag
   Partition/UpDiag
   Partition/UpOffsetDiag
