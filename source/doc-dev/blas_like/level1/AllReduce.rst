AllReduce
=========
Perform an (MPI) AllReduce on the contents of a matrix.

C++ API
-------
.. cpp:function:: void AllReduce( AbstractDistMatrix<T>& A, mpi::Comm comm, mpi::Op op=mpi::SUM )
.. cpp:function:: void AllReduce( AbstractBlockDistMatrix<T>& A, mpi::Comm comm, mpi::Op op=mpi::SUM )

C API
-----
**TODO**

Python API
----------
**TODO**
