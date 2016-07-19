Multiply after factorization
============================

Python API
----------
.. py:function:: MultiplyAfterLDL(A,B[,conjugate=True])

   :param A: Factored dense matrix
   :param B: Matrix of right-hand sides to multiplied (in-place)
   :param conjugate: (optional) If an LDLH factorization was performed

C++ API
-------
.. cpp:function:: void ldl::MultiplyAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::MultiplyAfter( const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
-----

.. c:function:: ElError ElMultiplyAfterLDL_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDL_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDL_c( ElConstMatrix_c A, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDL_z( ElConstMatrix_z A, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElMultiplyAfterLDLDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElMultiplyAfterLDLDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElMultiplyAfterLDLDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElMultiplyAfterLDLDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B, bool conjugate )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/MultiplyAfter.hpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapac
k_like/factor.py>`__
