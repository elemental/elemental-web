``[MR,STAR]``
=============
This is the transpose of the ``[* ,MR]`` distribution and is, like many of 
the previous distributions, useful for matrix-matrix multiplication.
For a :math:`7 \times 7` block matrix distributed over a :math:`2 \times 3`
process grid, individual entries would be owned by the following processes
(assuming the column alignment is 0):

.. math::

   \left(\begin{array}{ccccccc}
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} \\
     \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} & \{2,3\} \\
     \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} & \{4,5\} \\
     \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} & \{0,1\} 
   \end{array}\right)

.. cpp:class:: DistMatrix<scalarType,MR,STAR,BLOCK>
