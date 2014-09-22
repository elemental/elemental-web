Jordan
======
An :math:`n \times n` Jordan block with eigenvalue :math:`\lambda` is a
bidiagonal matrix with main diagonal equal to :math:`\lambda` and superdiagonal
equal to :math:`1`.

C++ API
-------

.. cpp:function:: void Jordan( Matrix<T>& J, Int n, T lambda )
.. cpp:function:: void Jordan( AbstractDistMatrix<T>& J, Int n, T lambda )

C API
-----

.. c:function:: ElError ElJordan_i( ElMatrix_i J, ElInt n, ElInt lambda )
.. c:function:: ElError ElJordan_s( ElMatrix_s J, ElInt n, float lambda )
.. c:function:: ElError ElJordan_d( ElMatrix_d J, ElInt n, double lambda )
.. c:function:: ElError ElJordan_c( ElMatrix_c J, ElInt n, complex_float lambda )
.. c:function:: ElError ElJordan_z( ElMatrix_z J, ElInt n, complex_double lambda )
.. c:function:: ElError ElJordanDist_i( ElDistMatrix_i J, ElInt n, ElInt lambda )
.. c:function:: ElError ElJordanDist_s( ElDistMatrix_s J, ElInt n, float lambda )
.. c:function:: ElError ElJordanDist_d( ElDistMatrix_d J, ElInt n, double lambda )
.. c:function:: ElError ElJordanDist_c( ElDistMatrix_c J, ElInt n, complex_float lambda )
.. c:function:: ElError ElJordanDist_z( ElDistMatrix_z J, ElInt n, complex_double lambda )
