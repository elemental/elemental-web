``[STAR,MD]``
=============
In the case of our :math:`2 \times 3` process grid, each diagonal of the tesselation
of the process grid will contain the entire set of processes, for instance, in the
order :math:`0,3,4,1,2,5`. This would result in the following overlay for the
owning processes of the entries of our :math:`7 \times 7` matrix example:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 \\
     0 & 3 & 4 & 1 & 2 & 5 & 0 
   \end{array}\right)

Notice that each *row* of this matrix is distributed like a diagonal of a 
``[MC,MR]`` distribution.

.. cpp:type:: DistMatrix<T,STAR,MD>

   All public member functions have been described as part of
   :cpp:type:`AbstractDistMatrix\<T>` and :cpp:type:`DistMatrix\<T,U,V>`.
