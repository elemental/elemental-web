``[MD,STAR]``
=============
In the case of our :math:`2 \times 3` process grid, each diagonal of the tesselation
of the process grid will contain the entire set of processes, for instance, in the
order :math:`0,3,4,1,2,5`. This would result in the following overlay for the
owning processes of the entries of our :math:`7 \times 7` matrix example:

.. math::

   \left(\begin{array}{ccccccc}
     0 & 0 & 0 & 0 & 0 & 0 & 0 \\
     3 & 3 & 3 & 3 & 3 & 3 & 3 \\ 
     4 & 4 & 4 & 4 & 4 & 4 & 4 \\
     1 & 1 & 1 & 1 & 1 & 1 & 1 \\ 
     2 & 2 & 2 & 2 & 2 & 2 & 2 \\
     5 & 5 & 5 & 5 & 5 & 5 & 5 \\ 
     0 & 0 & 0 & 0 & 0 & 0 & 0  
   \end{array}\right)

Notice that each column of this matrix is distributed like a diagonal of a 
``[MC,MR]`` distribution.

.. cpp:class:: DistMatrix<T,MD,STAR>

   .. cpp:function:: DistMatrix<T,MD,STAR> operator()( Range<Int> I, Range<Int> J )

   .. cpp:function:: const DistMatrix<T,MD,STAR> operator()( Range<Int> I, Range<Int> J ) const

