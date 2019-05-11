GetSubmatrix
============
Gets a (possibly non-contiguous) submatrix of a given matrix.

Python API
----------
.. py:function:: GetSubmatrix(A,I,J)

C++ API
-------

Contiguous
^^^^^^^^^^
.. cpp:function:: void GetSubmatrix( const Matrix<T>& A, const Range<Int>& I, const Range<Int>& J, Matrix<T>& ASub )
.. cpp:function:: Matrix<T> GetSubmatrix( const Matrix<T>& A, const Range<Int>& I, const Range<Int>& J )

.. cpp:function:: void GetSubmatrix( const AbstractDistMatrix<T>& A, const Range<Int>& I, const Range<Int>& J, AbstractDistMatrix<T>& ASub )
.. cpp:function:: AbstractDistMatrix<T> GetSubmatrix( const AbstractDistMatrix<T>& A, const Range<Int>& I, const Range<Int>& J )

.. cpp:function:: void GetSubmatrix( const SparseMatrix<T>& A, const Range<Int>& I, const Range<Int>& J, SparseMatrix<T>& ASub )
.. cpp:function:: SparseMatrix<T> GetSubmatrix( const SparseMatrix<T>& A, const Range<Int>& I, const Range<Int>& J )

.. cpp:function:: void GetSubmatrix( const DistSparseMatrix<T>& A, const Range<Int>& I, const Range<Int>& J, DistSparseMatrix<T>& ASub )
.. cpp:function:: DistSparseMatrix<T> GetSubmatrix( const DistSparseMatrix<T>& A, const Range<Int>& I, const Range<Int>& J )

.. cpp:function:: void GetSubmatrix( const DistMultiVec<T>& A, const Range<Int>& I, const Range<Int>& J, DistMultiVec<T>& ASub )
.. cpp:function:: DistMultiVec<T> GetSubmatrix( const DistMultiVec<T>& A, const Range<Int>& I, const Range<Int>& J )

Noncontiguous
^^^^^^^^^^^^^
.. cpp:function:: void GetSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, Matrix<T>& ASub )
.. cpp:function:: Matrix<T> GetSubmatrix( const Matrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )

.. cpp:function:: void GetSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J, AbstractDistMatrix<T>& ASub )
.. cpp:function:: DistMatrix<T> GetSubmatrix( const AbstractDistMatrix<T>& A, const std::vector<Int>& I, const std::vector<Int>& J )

C API
-----

Contiguous
^^^^^^^^^^

Integer
"""""""
.. c:function:: ElError ElGetContigSubmatrix_i( ElConstMatrix_i A, ElIndexRange I, ElIndexRange J, ElMatrix_i ASub )
.. c:function:: ElError ElGetContigSubmatrixDist_i( ElConstDistMatrix_i A, ElIndexRange I, ElIndexRange J, ElDistMatrix_i ASub )
.. c:function:: ElError ElGetContigSubmatrixSparse_i( ElConstSparseMatrix_i A, ElIndexRange I, ElIndexRange J, ElSparseMatrix_i ASub )
.. c:function:: ElError ElGetContigSubmatrixDistSparse_i( ElConstDistSparseMatrix_i A, ElIndexRange I, ElIndexRange J, ElDistSparseMatrix_i ASub )
.. c:function:: ElError ElGetContigSubmatrixDistMultiVec_i( ElConstDistMultiVec_i A, ElIndexRange I, ElIndexRange J, ElDistMultiVec_i ASub )

Single-precision
""""""""""""""""
.. c:function:: ElError ElGetContigSubmatrix_s( ElConstMatrix_s A, ElIndexRange I, ElIndexRange J, ElMatrix_s ASub )
.. c:function:: ElError ElGetContigSubmatrixDist_s( ElConstDistMatrix_s A, ElIndexRange I, ElIndexRange J, ElDistMatrix_s ASub )
.. c:function:: ElError ElGetContigSubmatrixSparse_s( ElConstSparseMatrix_s A, ElIndexRange I, ElIndexRange J, ElSparseMatrix_s ASub )
.. c:function:: ElError ElGetContigSubmatrixDistSparse_s( ElConstDistSparseMatrix_s A, ElIndexRange I, ElIndexRange J, ElDistSparseMatrix_s ASub )
.. c:function:: ElError ElGetContigSubmatrixDistMultiVec_s( ElConstDistMultiVec_s A, ElIndexRange I, ElIndexRange J, ElDistMultiVec_s ASub )

Double-precision
""""""""""""""""
.. c:function:: ElError ElGetContigSubmatrix_d( ElConstMatrix_d A, ElIndexRange I, ElIndexRange J, ElMatrix_d ASub )
.. c:function:: ElError ElGetContigSubmatrixDist_d( ElConstDistMatrix_d A, ElIndexRange I, ElIndexRange J, ElDistMatrix_d ASub )
.. c:function:: ElError ElGetContigSubmatrixSparse_d( ElConstSparseMatrix_d A, ElIndexRange I, ElIndexRange J, ElSparseMatrix_d ASub )
.. c:function:: ElError ElGetContigSubmatrixDistSparse_d( ElConstDistSparseMatrix_d A, ElIndexRange I, ElIndexRange J, ElDistSparseMatrix_d ASub )
.. c:function:: ElError ElGetContigSubmatrixDistMultiVec_d( ElConstDistMultiVec_d A, ElIndexRange I, ElIndexRange J, ElDistMultiVec_d ASub )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGetContigSubmatrix_c( ElConstMatrix_c A, ElIndexRange I, ElIndexRange J, ElMatrix_c ASub )
.. c:function:: ElError ElGetContigSubmatrixDist_c( ElConstDistMatrix_c A, ElIndexRange I, ElIndexRange J, ElDistMatrix_c ASub )
.. c:function:: ElError ElGetContigSubmatrixSparse_c( ElConstSparseMatrix_c A, ElIndexRange I, ElIndexRange J, ElSparseMatrix_c ASub )
.. c:function:: ElError ElGetContigSubmatrixDistSparse_c( ElConstDistSparseMatrix_c A, ElIndexRange I, ElIndexRange J, ElDistSparseMatrix_c ASub )
.. c:function:: ElError ElGetContigSubmatrixDistMultiVec_c( ElConstDistMultiVec_c A, ElIndexRange I, ElIndexRange J, ElDistMultiVec_c ASub )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElGetContigSubmatrix_z( ElConstMatrix_z A, ElIndexRange I, ElIndexRange J, ElMatrix_z ASub )
.. c:function:: ElError ElGetContigSubmatrixDist_z( ElConstDistMatrix_z A, ElIndexRange I, ElIndexRange J, ElDistMatrix_z ASub )
.. c:function:: ElError ElGetContigSubmatrixSparse_z( ElConstSparseMatrix_z A, ElIndexRange I, ElIndexRange J, ElSparseMatrix_z ASub )
.. c:function:: ElError ElGetContigSubmatrixDistSparse_z( ElConstDistSparseMatrix_z A, ElIndexRange I, ElIndexRange J, ElDistSparseMatrix_z ASub )
.. c:function:: ElError ElGetContigSubmatrixDistMultiVec_z( ElConstDistMultiVec_z A, ElIndexRange I, ElIndexRange J, ElDistMultiVec_z ASub )

Noncontiguous
^^^^^^^^^^^^^
**TODO**
