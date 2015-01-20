Dot
===
Returns :math:`(x,y) = x^H y`. :math:`x` and :math:`y` are both allowed to be 
stored as column or row vectors, but will be interpreted as column vectors.

C++ API
-------

.. cpp:function:: T Dot( const Matrix<T>& x, const Matrix<T>& y )
.. cpp:function:: T Dot( const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y )

C API
-----

.. c:function:: ElError ElDot_i( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDot_s( ElConstMatrix_s A, ElConstMatrix_s B, float* prod )
.. c:function:: ElError ElDot_d( ElConstMatrix_d A, ElConstMatrix_d B, double* prod )
.. c:function:: ElError ElDot_c( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDot_z( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod )
.. c:function:: ElError ElDotDist_i( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod )
.. c:function:: ElError ElDotDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod )
.. c:function:: ElError ElDotDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod )
.. c:function:: ElError ElDotDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod )
.. c:function:: ElError ElDotDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod )

Python API
----------

.. py:function:: Dot(A,B)
