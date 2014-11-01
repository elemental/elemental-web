UpdateDiagonal
==============
.. note::
   
   This is not a standard BLAS routine.

Adds a given value to the diagonal of a matrix.

C++ API
-------

.. cpp:function:: void UpdateDiagonal( Matrix<T>& A, T alpha )
.. cpp:function:: void UpdateDiagonal( AbstractDistMatrix<T>& A, T alpha )

.. cpp:function:: void UpdateDiagonal( Matrix<T>& A, T alpha, Int offset=0, LeftOrRight side=LEFT )
.. cpp:function:: void UpdateDiagonal( AbstractDistMatrix<T>& A, T alpha, Int offset=0, LeftOrRight side=LEFT )

C API
-----

.. c:function:: ElError ElUpdateDiagonal_i( ElMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonal_s( ElMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonal_d( ElMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonal_c( ElMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonal_z( ElMatrix_z A, complex_double alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonalDist_i( ElDistMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonalDist_s( ElDistMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonalDist_d( ElDistMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonalDist_c( ElDistMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElUpdateDiagonalDist_z( ElDistMatrix_z A, complex_double alpha, ElInt offset )
