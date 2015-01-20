Distributed matrices
====================
The :cpp:type:`DistMatrix\<T,U,V>` class is meant to provide a 
distributed-memory analogue of the :cpp:type:`Matrix\<T>` class. 
In a manner similar to PLAPACK, roughly ten different matrix 
distributions are provided and it is trivial (in the sense that it requires a 
single command) to redistribute from one to another: in PLAPACK, one would 
simply call ``PLA_Copy``, whereas, in Elemental, it is handled through 
overloading the :math:`=` operator (or instead calling the :cpp:func:`Copy` 
function).

Since it is crucial to know not only how many 
processes to distribute the data over, but *which* processes, and in what 
manner they should be decomposed into a logical two-dimensional grid, an 
instance of the :cpp:type:`Grid` class must be passed into the constructor of 
the :cpp:type:`DistMatrix\<T,U,V>` class.

.. note:: 
   
   Since the :cpp:type:`DistMatrix\<T,U,V>` class makes use of MPI for 
   message passing, custom interfaces must be written for nonstandard datatypes.
   As of now, the following datatypes are fully supported for 
   :cpp:type:`DistMatrix\<T,U,V>`:
   ``int``, ``float``, ``double``, ``Complex<float>``, and ``Complex<double>``.

The :cpp:type:`DistMatrix\<T,U,V>` class is implemented in a manner which 
attempts to expose as many symmetries within the various member functions and 
redistributions as possible. In particular, there are there is a hierarchy of
three increasingly-specific distributed matrix classes:
:cpp:type:`AbstractDistMatrix\<T>`, which contains every member function which
whose prototype does not depend upon the exact matrix distribution, and 
:cpp:type:`DistMatrix\<T,U,V>`, which contains implementations of member 
functions which are specific to a particular matrix distribution.

.. toctree::
   :maxdepth: 1

   dist_matrix/ADM
   dist_matrix/DM
