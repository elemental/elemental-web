Fill
====
Fill each entry of a matrix with the same value.

C++ API
-------
.. cpp:function:: void Fill( Matrix<T>& A, T alpha )
.. cpp:function:: void Fill( AbstractDistMatrix<T>& A, T alpha )
.. cpp:function:: void Fill( DistMultiVec<T>& A, T alpha )

C API
-----
.. c:function:: ElError ElFill_i( ElMatrix_i A, ElInt alpha )
.. c:function:: ElError ElFill_s( ElMatrix_s A, float alpha )
.. c:function:: ElError ElFill_d( ElMatrix_d A, double alpha )
.. c:function:: ElError ElFill_c( ElMatrix_c A, complex_float alpha )
.. c:function:: ElError ElFill_z( ElMatrix_z A, complex_double alpha )
.. c:function:: ElError ElFillDist_i( ElDistMatrix_i A, ElInt alpha )
.. c:function:: ElError ElFillDist_s( ElDistMatrix_s A, float alpha )
.. c:function:: ElError ElFillDist_d( ElDistMatrix_d A, double alpha )
.. c:function:: ElError ElFillDist_c( ElDistMatrix_c A, complex_float alpha )
.. c:function:: ElError ElFillDist_z( ElDistMatrix_z A, complex_double alpha )

Python API
----------
.. py:function:: Fill(A,alpha)
