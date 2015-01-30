AllReduce
=========
Perform an (MPI) AllReduce over the contents of a matrix stored on different
process (which overwrites every process's input with the summation over all process's copies).

C++ API
-------
.. cpp:function:: void AllReduce( AbstractDistMatrix<T>& A, mpi::Comm comm )
.. cpp:function:: void AllReduce( AbstractBlockDistMatrix<T>& A, mpi::Comm comm )

C API
-----
**TODO**

Python API
----------
**TODO**
