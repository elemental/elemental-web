Copy
====
Sets :math:`Y := X`.

C++ API
-------

.. cpp:function:: void Copy( const Matrix<S>& X, Matrix<T>& Y )
.. cpp:function:: void Copy( const AbstractDistMatrix<S>& A, AbstractDistMatrix<T>& B )

C API
-----

.. c:function:: ElError ElCopy_i( ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElCopy_s( ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElCopy_d( ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElCopy_c( ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElCopy_z( ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElCopyDist_i( ElConstDistMatrix_i X, ElDistMatrix_i Y )
.. c:function:: ElError ElCopyDist_s( ElConstDistMatrix_s X, ElDistMatrix_s Y )
.. c:function:: ElError ElCopyDist_d( ElConstDistMatrix_d X, ElDistMatrix_d Y )
.. c:function:: ElError ElCopyDist_c( ElConstDistMatrix_c X, ElDistMatrix_c Y )
.. c:function:: ElError ElCopyDist_z( ElConstDistMatrix_z X, ElDistMatrix_z Y )

