Broadcast
=========
Give every process in the specified communicator a copy of the matrix 
stored on the process with the given rank.

C++ API
-------
.. cpp:function:: void Broadcast( AbstractDistMatrix<T>& A, mpi::Comm comm, Int rank=0 )
.. cpp:function:: void Broadcast( AbstractBlockDistMatrix<T>& A, mpi::Comm comm, Int rank=0 )

C API
-----
**TODO**

Python API
----------
**TODO**
