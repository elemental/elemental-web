EntrywiseMap
============
Replace each entry of the passed in matrix with a specified function of
the existing entry.

C++ API
-------

.. cpp:function:: void EntrywiseMap( Matrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( AbstractDistMatrix<T>& A, std::function<T(T)> func )
.. cpp:function:: void EntrywiseMap( BlockDistMatrix<T,U,V>& A, std::function<T(T)> func )

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

