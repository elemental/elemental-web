HilbertSchmidt
==============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

The Hilbert-Schmidt inner-product of two :math:`m \times n` matrices :math:`A`
and :math:`B` is :math:`\mbox{tr}(A^H B)`.

C++ API
-------

.. cpp:function:: F HilbertSchmidt( const Matrix<F>& A, const Matrix<F>& B )
.. cpp:function:: F HilbertSchmidt( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B )

C API
-----

.. c:function:: ElError ElHilbertSchmidt_i( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod )
.. c:function:: ElError ElHilbertSchmidt_s( ElConstMatrix_s A, ElConstMatrix_s B, float* prod )
.. c:function:: ElError ElHilbertSchmidt_d( ElConstMatrix_d A, ElConstMatrix_d B, double* prod )
.. c:function:: ElError ElHilbertSchmidt_c( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod )
.. c:function:: ElError ElHilbertSchmidt_z( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod )
.. c:function:: ElError ElHilbertSchmidtDist_i( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod )
.. c:function:: ElError ElHilbertSchmidtDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod )
.. c:function:: ElError ElHilbertSchmidtDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod )
.. c:function:: ElError ElHilbertSchmidtDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod )
.. c:function:: ElError ElHilbertSchmidtDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod )
