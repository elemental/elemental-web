Hadamard
========
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

The Hadamard product of two :math:`m \times n` matrices :math:`A` and
:math:`B` is given entrywise by :math:`\alpha_{i,j} \beta_{i,j}` and denoted
by :math:`C = A \circ B`.

C++ API
-------

.. cpp:function:: void Hadamard( const Matrix<F>& A, const Matrix<F>& B, Matrix<F>& C )
.. cpp:function:: void Hadamard( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C )

C API
-----

.. c:function:: ElError ElHadamard_i( ElConstMatrix_i A, ElConstMatrix_i B, ElMatrix_i C )
.. c:function:: ElError ElHadamard_s( ElConstMatrix_s A, ElConstMatrix_s B, ElMatrix_s C )
.. c:function:: ElError ElHadamard_d( ElConstMatrix_d A, ElConstMatrix_d B, ElMatrix_d C )
.. c:function:: ElError ElHadamard_c( ElConstMatrix_c A, ElConstMatrix_c B, ElMatrix_c C )
.. c:function:: ElError ElHadamard_z( ElConstMatrix_z A, ElConstMatrix_z B, ElMatrix_z C )
.. c:function:: ElError ElHadamardDist_i( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElDistMatrix_i C )
.. c:function:: ElError ElHadamardDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s C )
.. c:function:: ElError ElHadamardDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d C )
.. c:function:: ElError ElHadamardDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElDistMatrix_c C )
.. c:function:: ElError ElHadamardDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElDistMatrix_z C )
