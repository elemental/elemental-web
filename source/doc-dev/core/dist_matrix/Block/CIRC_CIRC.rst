``[CIRC,CIRC]``
===============
This ``distribution`` stores the entire matrix on a single process.
For instance,
if the root process is process 0 with respect to a column-major ordering of the 
process grid, then the corresponding overlay for the owners of each 
subblock of our 7 x 7 block matrix example would be:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0 
   \end{array}\right)

.. cpp:class:: DistMatrix<scalarType,CIRC,CIRC,BLOCK>
