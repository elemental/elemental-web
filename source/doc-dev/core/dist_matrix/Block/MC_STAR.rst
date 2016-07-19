``[MC,STAR]``
=============

This distribution is often used as part of matrix-matrix multiplication. For a
:math:`7 \times 7` block matrix distributed over a
:math:`2 \times 3` process grid,
individual subblocks would be owned by the following processes (assuming the 
column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} \\
     \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & \{1,3,5\} & 
     \{1,3,5\} & \{1,3,5\} \\ 
     \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & \{0,2,4\} & 
     \{0,2,4\} & \{0,2,4\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<scalarType,MC,STAR,BLOCK>
