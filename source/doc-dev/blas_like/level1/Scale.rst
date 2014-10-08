Scale
=====
:math:`X := \alpha X`.

C++ API
-------

.. cpp:function:: void Scale( T alpha, Matrix<T>& X )
.. cpp:function:: void Scale( T alpha, AbstractDistMatrix<T>& X )

C API
-----

.. c:function:: ElError ElScale_i( ElInt alpha, ElMatrix_i A )
.. c:function:: ElError ElScale_s( float alpha, ElMatrix_s A )
.. c:function:: ElError ElScale_d( double alpha, ElMatrix_d A )
.. c:function:: ElError ElScale_c( complex_float alpha, ElMatrix_c A )
.. c:function:: ElError ElScale_z( complex_double alpha, ElMatrix_z A )
.. c:function:: ElError ElScaleDist_i( ElInt alpha, ElDistMatrix_i A )
.. c:function:: ElError ElScaleDist_s( float alpha, ElDistMatrix_s A )
.. c:function:: ElError ElScaleDist_d( double alpha, ElDistMatrix_d A )
.. c:function:: ElError ElScaleDist_c( complex_float alpha, ElDistMatrix_c A )
.. c:function:: ElError ElScaleDist_z( complex_double alpha, ElDistMatrix_z A )
