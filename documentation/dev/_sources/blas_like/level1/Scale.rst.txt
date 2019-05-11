Scale
=====
:math:`X := \alpha X`.

C++ API
-------

.. cpp:function:: void Scale( T alpha, Matrix<T>& X )
.. cpp:function:: void Scale( T alpha, AbstractDistMatrix<T>& X )
.. cpp:function:: void Scale( T alpha, SparseMatrix<T>& X )
.. cpp:function:: void Scale( T alpha, DistSparseMatrix<T>& X )

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
.. c:function:: ElError ElScaleSparse_i( ElInt alpha, ElSparseMatrix_i A )
.. c:function:: ElError ElScaleSparse_s( float alpha, ElSparseMatrix_s A )
.. c:function:: ElError ElScaleSparse_d( double alpha, ElSparseMatrix_d A )
.. c:function:: ElError ElScaleSparse_c( complex_float alpha, ElSparseMatrix_c A )
.. c:function:: ElError ElScaleSparse_z( complex_double alpha, ElSparseMatrix_z A )
.. c:function:: ElError ElScaleDistSparse_i( ElInt alpha, ElDistSparseMatrix_i A )
.. c:function:: ElError ElScaleDistSparse_s( float alpha, ElDistSparseMatrix_s A )
.. c:function:: ElError ElScaleDistSparse_d( double alpha, ElDistSparseMatrix_d A )
.. c:function:: ElError ElScaleDistSparse_c( complex_float alpha, ElDistSparseMatrix_c A )
.. c:function:: ElError ElScaleDistSparse_z( complex_double alpha, ElDistSparseMatrix_z A )

Python API
----------

.. py:function:: Scale(allpha,A)
