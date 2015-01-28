Conjugate
=========
.. note:: 

   This is not a standard BLAS routine, but it is BLAS-like.

:math:`A := \bar A`. For real datatypes, this is a no-op.

C++ API
-------
.. cpp:function:: void Conjugate( Matrix<T>& A )
.. cpp:function:: void Conjugate( AbstractDistMatrix<T>& A )

:math:`B := \bar A`.

.. cpp:function:: void Conjugate( const Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Conjugate( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

C API
-----
.. c:function:: ElError ElConjugate_c( ElMatrix_c A )
.. c:function:: ElError ElConjugate_z( ElMatrix_z A )
.. c:function:: ElError ElConjugateDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElConjugateDist_z( ElDistMatrix_z A )

Python API
----------
.. py:function:: Conjugate(A)
