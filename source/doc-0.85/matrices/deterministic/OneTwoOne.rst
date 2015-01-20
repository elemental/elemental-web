OneTwoOne
=========
A "1-2-1" matrix is tridiagonal with a diagonal of all twos and sub- and
super-diagonals of all ones.

C++ API
-------

.. cpp:function:: void OneTwoOne( Matrix<T>& A, Int n )
.. cpp:function:: void OneTwoOne( AbstractDistMatrix<T>& A, Int n )

C API
-----

.. c:function:: ElError ElOneTwoOne_i( ElMatrix_i A, ElInt n )
.. c:function:: ElError ElOneTwoOne_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElOneTwoOne_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElOneTwoOne_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElOneTwoOne_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_i( ElDistMatrix_i A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElOneTwoOneDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: OneTwoOne(A,n)
