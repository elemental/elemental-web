Gemm
====
General matrix-matrix multiplication: updates
:math:`C := \alpha A^\# B^\sharp + \beta C`,
where :math:`M^\#` and :math:`M^\sharp` are individually defined to be one of
:math:`\{M,M^T,M^H\}`.

.. note::

   For the best performance, `A`, `B`, and `C` should all be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:enum:: GemmAlgorithm

   .. cpp:enumerator:: GEMM_DEFAULT

   .. cpp:enumerator:: GEMM_SUMMA_A

   .. cpp:enumerator:: GEMM_SUMMA_B

   .. cpp:enumerator:: GEMM_SUMMA_C

   .. cpp:enumerator:: GEMM_SUMMA_DOT

   .. cpp:enumerator:: GEMM_CANNON

.. cpp:function:: void Gemm( Orientation orientationOfA, Orientation orientationOfB, T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C )
.. cpp:function:: void Gemm( Orientation orientationOfA, Orientation orientationOfB, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, T beta, AbstractDistMatrix<T>& C, GemmAlgorithm alg=GEMM_DEFAULT )

C API
-----

.. c:function:: ElError ElGemm_i( ElOrientation orientationOfA, ElOrientation orientationOfB, ElInt alpha, ElConstMatrix_i A, ElConstMatrix_i B, ElInt beta, ElMatrix_i C )
.. c:function:: ElError ElGemm_s( ElOrientation orientationOfA, ElOrientation orientationOfB, float alpha, ElConstMatrix_s A, ElConstMatrix_s B, float beta, ElMatrix_s C )
.. c:function:: ElError ElGemm_d( ElOrientation orientationOfA, ElOrientation orientationOfB, double alpha, ElConstMatrix_d A, ElConstMatrix_d B, double beta, ElMatrix_d C )
.. c:function:: ElError ElGemm_c( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c B, complex_float beta, ElMatrix_c C )
.. c:function:: ElError ElGemm_z( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z B, complex_double beta, ElMatrix_z C )
.. c:function:: ElError ElGemmDist_i( ElOrientation orientationOfA, ElOrientation orientationOfB, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt beta, ElDistMatrix_i C )
.. c:function:: ElError ElGemmDist_s( ElOrientation orientationOfA, ElOrientation orientationOfB, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C )
.. c:function:: ElError ElGemmDist_d( ElOrientation orientationOfA, ElOrientation orientationOfB, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C )
.. c:function:: ElError ElGemmDist_c( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C )
.. c:function:: ElError ElGemmDist_z( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C )

.. c:type:: ElGemmAlgorithm

   An enum which can take on the values:

   * ``EL_GEMM_DEFAULT``
   * ``EL_GEMM_SUMMA_A``
   * ``EL_GEMM_SUMMA_B``
   * ``EL_GEMM_SUMMA_C``
   * ``EL_GEMM_SUMMA_DOT``
   * ``EL_GEMM_CANNON``

.. c:function:: ElError ElGemmXDist_i( ElOrientation orientationOfA, ElOrientation orientationOfB, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt beta, ElDistMatrix_i C, ElGemmAlgorithm alg )
.. c:function:: ElError ElGemmXDist_s( ElOrientation orientationOfA, ElOrientation orientationOfB, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s B, float beta, ElDistMatrix_s C, ElGemmAlgorithm alg )
.. c:function:: ElError ElGemmXDist_d( ElOrientation orientationOfA, ElOrientation orientationOfB, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d B, double beta, ElDistMatrix_d C, ElGemmAlgorithm alg )
.. c:function:: ElError ElGemmXDist_c( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float beta, ElDistMatrix_c C, ElGemmAlgorithm alg )
.. c:function:: ElError ElGemmXDist_z( ElOrientation orientationOfA, ElOrientation orientationOfB, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double beta, ElDistMatrix_z C, ElGemmAlgorithm alg )

Python API
----------

.. py:data:: GemmAlgorithm

   An enum which can take the values...**TODO**

.. py:function:: Gemm(orientA,orientB,alpha,A,B,beta,C[,alg=GEMM_DEFAULT])
