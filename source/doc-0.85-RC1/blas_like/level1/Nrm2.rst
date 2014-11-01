Nrm2
====
Returns :math:`||x||_2 = \sqrt{(x,x)} = \sqrt{x^H x}`. As with most other 
routines, even if :math:`x` is stored as a row vector, it will be interpreted
as a column vector.

C++ API
-------

.. cpp:function:: Base<F> Nrm2( const Matrix<F>& x )
.. cpp:function:: Base<F> Nrm2( const AbstractDistMatrix<F>& x )

C API
-----

.. c:function:: ElError ElNrm2_s( ElConstMatrix_s A, float* gamma )
.. c:function:: ElError ElNrm2_d( ElConstMatrix_d A, double* gamma )
.. c:function:: ElError ElNrm2_c( ElConstMatrix_c A, float* gamma )
.. c:function:: ElError ElNrm2_z( ElConstMatrix_z A, double* gamma )
.. c:function:: ElError ElNrm2Dist_s( ElConstDistMatrix_s A, float* gamma )
.. c:function:: ElError ElNrm2Dist_d( ElConstDistMatrix_d A, double* gamma )
.. c:function:: ElError ElNrm2Dist_c( ElConstDistMatrix_c A, float* gamma )
.. c:function:: ElError ElNrm2Dist_z( ElConstDistMatrix_z A, double* gamma )
