Rademacher
==========
A *Rademacher matrix* is a matrix whose entries are independent and uniformly
sampled from :math:`\{-1,1\}`. 

C++ API
-------

.. cpp:function:: void Rademacher( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Rademacher( AbstractDistMatrix<T>& A, Int m, Int n )
.. cpp:function:: void Rademacher( AbstractBlockDistMatrix<T>& A, Int m, Int n )

C API
-----

.. c:function:: ElError ElRademacher_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacher_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacher_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacher_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacher_z( ElMatrix_z A, ElInt m, ElInt n )

.. c:function:: ElError ElRademacherDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacherDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacherDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacherDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElRademacherDist_z( ElDistMatrix_z A, ElInt m, ElInt n )

Python API
----------

.. py:function:: Rademacher(A,m,n)
