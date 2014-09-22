Lauchli
=======
An :math:`n+1 \times n` *Lauchli matrix* has is a concatenation of a 
:math:`1 \times n` row-vector of all ones with the :math:`n \times n` matrix
:math:`mu I`. The case where :math:`mu = \sqrt{\epsilon}` is a prominent 
example of where the explicit formation of :math:`A^H A` can be catastrophic.

C++ API
-------

.. cpp:function:: void Lauchli( Matrix<T>& A, Int n, T mu )
.. cpp:function:: void Lauchli( AbstractDistMatrix<T>& A, Int n, T mu )

C API
-----

.. c:function:: ElError ElLauchli_i( ElMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElLauchli_s( ElMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElLauchli_d( ElMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElLauchli_c( ElMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElLauchli_z( ElMatrix_z A, ElInt n, complex_double mu )
.. c:function:: ElError ElLauchliDist_i( ElDistMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElLauchliDist_s( ElDistMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElLauchliDist_d( ElDistMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElLauchliDist_c( ElDistMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElLauchliDist_z( ElDistMatrix_z A, ElInt n, complex_double mu )
