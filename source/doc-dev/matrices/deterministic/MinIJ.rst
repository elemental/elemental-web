MinIJ
=====
Return an :math:`n \times n` matrix with the :math:`(i,j)` entry equal to
:math:`\text{min}(i+1,j+1)` (counting from zero).

C++ API
-------

.. cpp:function:: void MinIJ( Matrix<T>& M, Int n )
.. cpp:function:: void MinIJ( AbstractDistMatrix<T>& M, Int n )

C API
-----

.. c:function:: ElError ELMinIJ_i( ElMatrix_i M, ElInt n )
.. c:function:: ElError ELMinIJ_s( ElMatrix_s M, ElInt n )
.. c:function:: ElError ELMinIJ_d( ElMatrix_d M, ElInt n )
.. c:function:: ElError ELMinIJ_c( ElMatrix_c M, ElInt n )
.. c:function:: ElError ELMinIJ_z( ElMatrix_z M, ElInt n )
.. c:function:: ElError ELMinIJDist_i( ElDistMatrix_i M, ElInt n )
.. c:function:: ElError ELMinIJDist_s( ElDistMatrix_s M, ElInt n )
.. c:function:: ElError ELMinIJDist_d( ElDistMatrix_d M, ElInt n )
.. c:function:: ElError ELMinIJDist_c( ElDistMatrix_c M, ElInt n )
.. c:function:: ElError ELMinIJDist_z( ElDistMatrix_z M, ElInt n )
