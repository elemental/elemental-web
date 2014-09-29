Uniform
=======
We call an :math:`m \times n` matrix is uniformly random if each entry is drawn 
from a uniform distribution over a ball with the specified center and radius.

C++ API
-------

.. cpp:function:: void Uniform( Matrix<T>& A, Int m, Int n, T center=0, Base<T> radius=1 )
.. cpp:function:: void Uniform( AbstractDistMatrix<T>& A, Int m, Int n, T center=0, Base<T> radius=1 )

.. cpp:function:: void MakeUniform( Matrix<T>& A, T center=0, Base<T> radius=1 )
.. cpp:function:: void MakeUniform( AbstractDistMatrix<T>& A, T center=0, Base<T> radius=1 )

C API
-----

.. c:function:: ElError ElUniform_i( ElMatrix_i A, ElInt m, ElInt n, ElInt center, ElInt radius )
.. c:function:: ElError ElUniform_s( ElMatrix_s A, ElInt m, ElInt n, float center, float radius )
.. c:function:: ElError ElUniform_d( ElMatrix_d A, ElInt m, ElInt n, double center, double radius )
.. c:function:: ElError ElUniform_c( ElMatrix_c A, ElInt m, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElUniform_z( ElMatrix_z A, ElInt m, ElInt n, complex_double center, double radius )
.. c:function:: ElError ElUniformDist_i( ElDistMatrix_i A, ElInt m, ElInt n, ElInt center, ElInt radius )
.. c:function:: ElError ElUniformDist_s( ElDistMatrix_s A, ElInt m, ElInt n, float center, float radius )
.. c:function:: ElError ElUniformDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double center, double radius )
.. c:function:: ElError ElUniformDist_c( ElDistMatrix_c A, ElInt m, ElInt n, complex_float center, float radius )
.. c:function:: ElError ElUniformDist_z( ElDistMatrix_z A, ElInt m, ElInt n, complex_double center, double radius )
