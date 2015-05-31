Multiply after factorization
============================

Python API
----------
.. py:function:: MultiplyAfterLDLPiv(A,dSub,p,B[,conjugate=True])

   :param A: The factored dense matrix
   :param dSub: The vector containing the subdiagonal of :math:`D`
   :param p: The integer permutation vector
   :param B: The right-hand sides to be multiplied (in-place)
   :param conjugate: (optional) If an :math:`LDL^H` factorization was performed

C++ API
-------
.. cpp:function:: void ldl::MultiplyAfter( const Matrix<F>& A, const Matrix<F>& dSub, const Matrix<int>& p, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::MultiplyAfter( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& dSub, const AbstractDistMatrix<int>& p, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
-----
.. c:function:: ElError ElMultiplyAfterLDLPiv_s( ElConstMatrix_s A, ElConstMatrix_s dSub, ElConstMatrix_i p, ElMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLPiv_d( ElConstMatrix_d A, ElConstMatrix_d dSub, ElConstMatrix_i p, ElMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLPiv_c( ElConstMatrix_c A, ElConstMatrix_c dSub, ElConstMatrix_i p, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLPiv_z( ElConstMatrix_z A, ElConstMatrix_z dSub, ElConstMatrix_i p, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElMultiplyAfterLDLPivDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s dSub, ElConstDistMatrix_i p, ElDistMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d dSub, ElConstDistMatrix_i p, ElDistMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c dSub, ElConstDistMatrix_i p, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLPivDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z dSub, ElConstDistMatrix_i p, ElDistMatrix_z B, bool conjugate )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/MultiplyAfter.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like
/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__

`C++11 test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`C++11 example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__
