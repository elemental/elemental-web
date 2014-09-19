Adjoint
=======
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`B := A^H`. 

C++ API
-------

.. cpp:function:: void Adjoint( const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Adjoint( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

C API
-----

.. c:function:: ElError ElAdjoint_c( ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElAdjoint_z( ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElAdjointDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElAdjointDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B )
