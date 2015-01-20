``[STAR,VR]``
=============
This is the transpose of the above ``[VR,* ]`` distribution. On the standard
:math:`2 \times 3` process grid with a row alignment of zero, a 
:math:`7 \times 7` matrix would be distributed as:

.. math::

   \left(\begin{array}{ccccccc}
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 \\
   0 & 2 & 4 & 1 & 3 & 5 & 0 
   \end{array}\right)

.. cpp:type:: DistMatrix<T,STAR,VR>

   All public member functions have been described as part of
   :cpp:type:`AbstractDistMatrix\<T>` and :cpp:type:`DistMatrix\<T,U,V>`.
