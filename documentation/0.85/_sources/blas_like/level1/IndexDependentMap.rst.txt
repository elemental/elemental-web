IndexDependentMap
=================
Replace each entry of the passed in matrix with a specified function of
the existing entry and its global indices.

C++ API
-------

.. cpp:function:: void IndexDependentMap( Matrix<T>& A, std::function<T(Int,Int,T)> func )
.. cpp:function:: void IndexDependentMap( AbstractDistMatrix<T>& A, std::function<T(Int,Int,T)> func )
.. cpp:function:: void IndexDependentMap( BlockDistMatrix<T,U,V>& A, std::function<T(Int,Int,T)> func )

C API
-----

.. c:function:: ElError ElIndexDependentMap_i( ElMatrix_i A, ElInt (*func)(ElInt,ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentMap_s( ElMatrix_s A, float (*func)(ElInt,ElInt,float) )
.. c:function:: ElError ElIndexDependentMap_d( ElMatrix_d A, double (*func)(ElInt,ElInt,double) )
.. c:function:: ElError ElIndexDependentMap_c( ElMatrix_c A, complex_float (*func)(ElInt,ElInt,complex_float) )
.. c:function:: ElError ElIndexDependentMap_z( ElMatrix_z A, complex_double (*func)(ElInt,ElInt,complex_double) )
.. c:function:: ElError ElIndexDependentMapDist_i( ElDistMatrix_i A, ElInt (*func)(ElInt,ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentMapDist_s( ElDistMatrix_s A, float (*func)(ElInt,ElInt,float) )
.. c:function:: ElError ElIndexDependentMapDist_d( ElDistMatrix_d A, double (*func)(ElInt,ElInt,double) )
.. c:function:: ElError ElIndexDependentMapDist_c( ElDistMatrix_c A, complex_float (*func)(ElInt,ElInt,complex_float) )
.. c:function:: ElError ElIndexDependentMapDist_z( ElDistMatrix_z A, complex_double (*func)(ElInt,ElInt,complex_double) )
