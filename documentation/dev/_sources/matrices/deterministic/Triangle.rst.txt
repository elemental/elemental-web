Triangle
========

C++ API
-------

.. cpp:function:: void Triangle( Matrix<F>& A, Int n )
.. cpp:function:: void Triangle( AbstractDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElTriangle_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElTriangle_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElTriangle_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElTriangle_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElTriangleDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElTriangleDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElTriangleDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElTriangleDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Triangle(A,n)
