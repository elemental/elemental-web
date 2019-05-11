EntrywiseFill
=============
Fill each entry of the passed in matrix by querying the specified function.

C++ API
-------

.. cpp:function:: void EntrywiseFill( Matrix<T>& A, std::function<T(void)> func )
.. cpp:function:: void EntrywiseFill( AbstractDistMatrix<T>& A, std::function<T(void)> func )
.. cpp:function:: void EntrywiseFill( BlockDistMatrix<T,U,V>& A, std::function<T(void)> func )

C API
-----

.. c:function:: ElError ElEntrywiseFill_i( ElMatrix_i A, ElInt (*fill)() )
.. c:function:: ElError ElEntrywiseFill_s( ElMatrix_s A, float (*fill)() )
.. c:function:: ElError ElEntrywiseFill_d( ElMatrix_d A, double (*fill)() )
.. c:function:: ElError ElEntrywiseFill_c( ElMatrix_c A, complex_float (*fill)() )
.. c:function:: ElError ElEntrywiseFill_z( ElMatrix_z A, complex_double (*fill)() )
.. c:function:: ElError ElEntrywiseFillDist_i( ElDistMatrix_i A, ElInt (*fill)() )
.. c:function:: ElError ElEntrywiseFillDist_s( ElDistMatrix_s A, float (*fill)() )
.. c:function:: ElError ElEntrywiseFillDist_d( ElDistMatrix_d A, double (*fill)() )
.. c:function:: ElError ElEntrywiseFillDist_c( ElDistMatrix_c A, complex_float (*fill)() )
.. c:function:: ElError ElEntrywiseFillDist_z( ElDistMatrix_z A, complex_double (*fill)() )

