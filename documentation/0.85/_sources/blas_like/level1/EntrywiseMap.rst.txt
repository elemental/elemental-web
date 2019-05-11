EntrywiseMap
============
Replace each entry of the passed in matrix with a specified function of
the existing entry.

C++ API
-------

.. cpp:function:: void EntrywiseMap( Matrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( AbstractDistMatrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( BlockDistMatrix<T,U,V>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( SparseMatrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( DistSparseMatrix<T>& A, std::function<T(T)> func )

C API
-----

.. c:function:: ElError ElEntrywiseMap_i( ElMatrix_i A, ElInt (*func)(ElInt) )
.. c:function:: ElError ElEntrywiseMap_s( ElMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElEntrywiseMap_d( ElMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElEntrywiseMap_c( ElMatrix_c A, complex_float (*func)(complex_float) )
.. c:function:: ElError ElEntrywiseMap_z( ElMatrix_z A, complex_double (*func)(complex_double) )
.. c:function:: ElError ElEntrywiseMapDist_i( ElDistMatrix_i A, ElInt (*func)(ElInt) )
.. c:function:: ElError ElEntrywiseMapDist_s( ElDistMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElEntrywiseMapDist_d( ElDistMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElEntrywiseMapDist_c( ElDistMatrix_c A, complex_float (*func)(complex_float) )
.. c:function:: ElError ElEntrywiseMapDist_z( ElDistMatrix_z A, complex_double (*func)(complex_double) )
.. c:function:: ElError ElEntrywiseMapSparse_i( ElSparseMatrix_i A, ElInt (*func)(ElInt) )
.. c:function:: ElError ElEntrywiseMapSparse_s( ElSparseMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElEntrywiseMapSparse_d( ElSparseMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElEntrywiseMapSparse_c( ElSparseMatrix_c A, complex_float (*func)(complex_float) )
.. c:function:: ElError ElEntrywiseMapSparse_z( ElSparseMatrix_z A, complex_double (*func)(complex_double) )
.. c:function:: ElError ElEntrywiseMapDistSparse_i( ElDistSparseMatrix_i A, ElInt (*func)(ElInt) )
.. c:function:: ElError ElEntrywiseMapDistSparse_s( ElDistSparseMatrix_s A, float (*func)(float) )
.. c:function:: ElError ElEntrywiseMapDistSparse_d( ElDistSparseMatrix_d A, double (*func)(double) )
.. c:function:: ElError ElEntrywiseMapDistSparse_c( ElDistSparseMatrix_c A, complex_float (*func)(complex_float) )
.. c:function:: ElError ElEntrywiseMapDistSparse_z( ElDistSparseMatrix_z A, complex_double (*func)(complex_double) )

Python API
----------

.. py:function:: EntrywiseMap(A,func)
