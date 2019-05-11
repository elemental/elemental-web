Solve after factorization
=========================

Python API
----------
.. py:function:: SolveAfterLDL(A,B[,conjugate=True])

   :param A: Factored dense matrix
   :param B: Matrix of right-hand sides to solved against (in-place)
   :param conjugate: (optional) If an LDLH factorization was performed

C++ API
-------
.. cpp:function:: void ldl::SolveAfter( const Matrix<F>& A, Matrix<F>& B, bool conjugated=false )
.. cpp:function:: void ldl::SolveAfter( const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, bool conjugated=false )

C API
-----
.. c:function:: ElError ElSolveAfterLDL_s( ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElSolveAfterLDL_d( ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElSolveAfterLDL_c( ElConstMatrix_c A, ElMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDL_z( ElConstMatrix_z A, ElMatrix_z B, bool conjugate )

.. c:function:: ElError ElSolveAfterLDLDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElSolveAfterLDLDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElSolveAfterLDLDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B, bool conjugate )
.. c:function:: ElError ElSolveAfterLDLDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B, bool conjugate )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/SolveAfter.hpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapac
k_like/factor.py>`__
