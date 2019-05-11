Dotu
====
Returns :math:`x^T y`, which is **not** an inner product.

C++ API
-------

.. cpp:function:: T Dotu( const Matrix<T>& x, const Matrix<T>& y )
.. cpp:function:: T Dotu( const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y )

C API
-----

.. c:function:: ElError ElDotu_c( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotu_z( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotuDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotuDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod )

Python API
----------

.. py:function:: Dotu(A,B)
