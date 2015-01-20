``[STAR,STAR]``
===============
This "distribution" actually redundantly stores every entry of the associated
matrix on every process. Again using a :math:`2 \times 3` process grid, 
the entries of a :math:`7 \times 7` matrix would be owned by the following
sets of processes:

.. math::

   \left(\begin{array}{ccccccc}
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} \\
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} & 
   \{0,1,...,5\} & \{0,1,...,5\} & \{0,1,...,5\} 
   \end{array}\right)

.. cpp:type:: DistMatrix<T,STAR,STAR>

   All public member functions have been described as part of
   :cpp:type:`AbstractDistMatrix\<T>` and :cpp:type:`DistMatrix\<T,U,V>`.
