IndexDependentFill
==================
Fill each entry of the passed in matrix by querying the specified function
which depends upon the global index of the entry.

C++ API
-------

.. cpp:function:: void IndexDependentFill( Matrix<T>& A, std::function<T(Int,Int)> func )
.. cpp:function:: void IndexDependentFill( AbstractDistMatrix<T>& A, std::function<T(Int,Int)> func )

C API
-----

.. c:function:: ElError ElIndexDependentFill_i( ElMatrix_i A, ElInt (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFill_s( ElMatrix_s A, float (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFill_d( ElMatrix_d A, double (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFill_c( ElMatrix_c A, complex_float (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFill_z( ElMatrix_z A, complex_double (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFillDist_i( ElDistMatrix_i A, ElInt (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFillDist_s( ElDistMatrix_s A, float (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFillDist_d( ElDistMatrix_d A, double (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFillDist_c( ElDistMatrix_c A, complex_float (*fill)(ElInt,ElInt) )
.. c:function:: ElError ElIndexDependentFillDist_z( ElDistMatrix_z A, complex_double (*fill)(ElInt,ElInt) )
