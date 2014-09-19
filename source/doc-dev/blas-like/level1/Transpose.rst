Transpose
=========
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^T` or :math:`B := A^H`. 

C++ API
-------

.. cpp:function:: void Transpose( const Matrix<T>& A, Matrix<T>& B, bool conjugate=false )
.. cpp:function:: void Transpose( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

C API
-----

.. c:function:: ElError ElTranspose_i( ElConstMatrix_i A, ElMatrix_i B )
.. c:function:: ElError ElTranspose_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElTranspose_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElTranspose_c( ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElTranspose_z( ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElTransposeDist_i( ElConstDistMatrix_i A, ElDistMatrix_i B )
.. c:function:: ElError ElTransposeDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElTransposeDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElTransposeDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElTransposeDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B )
