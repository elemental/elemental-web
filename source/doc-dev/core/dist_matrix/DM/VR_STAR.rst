``[VR,STAR]``
=============
This distribution makes use of a 1d distribution which uses a row-major 
ordering of the entire process grid. Since 1d distributions are useful for 
distributing *vectors*, and a *row-major* ordering is used, the distribution 
symbol is ``VR``. Again using the simple :math:`2 \times 3` process grid, 
with a zero column alignment, each entry of a :math:`7 \times 7` matrix 
would be owned by the following sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\
     0 & 0 & 0 & 0 & 0 & 0 & 0
   \end{array}\right)

.. cpp:class:: DistMatrix<scalarType,VR,STAR>
.. cpp:class:: DistMatrix<scalarType,VR,STAR,ELEMENT>
