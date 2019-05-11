SetDiagonal
===========
.. note::
   
   This is not a standard BLAS routine.

Sets all of the diagonal entries of a matrix to a given value.

C++ API
-------

.. cpp:function:: void SetDiagonal( Matrix<T>& A, T alpha )
.. cpp:function:: void SetDiagonal( AbstractDistMatrix<T>& A, T alpha )

.. cpp:function:: void SetDiagonal( Matrix<T>& A, T alpha, Int offset=0, LeftOrRight side=LEFT )
.. cpp:function:: void SetDiagonal( AbstractDistMatrix<T>& A, T alpha, Int offset=0, LeftOrRight side=LEFT )

C API
-----

.. c:function:: ElError ElSetDiagonal_i( ElMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonal_s( ElMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonal_d( ElMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonal_c( ElMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonal_z( ElMatrix_z A, complex_double alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonalDist_i( ElDistMatrix_i A, ElInt alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonalDist_s( ElDistMatrix_s A, float alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonalDist_d( ElDistMatrix_d A, double alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonalDist_c( ElDistMatrix_c A, complex_float alpha, ElInt offset )
.. c:function:: ElError ElSetDiagonalDist_z( ElDistMatrix_z A, complex_double alpha, ElInt offset )
