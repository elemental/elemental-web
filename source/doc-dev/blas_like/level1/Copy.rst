Copy
====
Sets :math:`Y := X`.

C++ API
-------
.. cpp:function:: void Copy( const Matrix<S>& X, Matrix<T>& Y )
.. cpp:function:: void Copy( const AbstractDistMatrix<S>& A, AbstractDistMatrix<T>& B )
.. cpp:function:: void Copy( const AbstractBlockDistMatrix<S>& A, AbstractBlockDistMatrix<T>& B )
.. cpp:function:: void Copy( const SparseMatrix<S>& A, SparseMatrix<T>& B )
.. cpp:function:: void Copy( const SparseMatrix<S>& A, Matrix<T>& B )
.. cpp:function:: void Copy( const DistSparseMatrix<S>& A, DistSparseMatrix<T>& B )
.. cpp:function:: void Copy( const DistSparseMatrix<S>& A, AbstractDistMatrix<T>& B )
.. cpp:function:: void Copy( const DistMultiVec<T>& A, DistMultiVec<T>& B )
.. cpp:function:: void Copy( const DistMultiVec<T>& A, AbstractDistMatrix<T>& B )
.. cpp:function:: void Copy( const AbstractDistMatrix<T>& A, DistMultiVec<T>& B )

.. cpp:function:: void CopyFromRoot( const DistSparseMatrix<T>& ADist, SparseMatrix<T>& A )
.. cpp:function:: void CopyFromNonRoot( const DistSparseMatrix<T>& ADist, int root=0 )
.. cpp:function:: void CopyFromRoot( const DistMultiVec<T>& XDist, Matrix<T>& X )
.. cpp:function:: void CopyFromNonRoot( const DistMultiVec<T>& XDist, int root=0 )

.. cpp:function:: void Copy( const Graph& A, Graph& B )
.. cpp:function:: void Copy( const Graph& A, DistGraph& B )
.. cpp:function:: void Copy( const DistGraph& A, Graph& B )
.. cpp:function:: void Copy( const DistGraph& A, DistGraph& B )

.. cpp:function:: void CopyFromRoot( const DistGraph& distGraph, Graph& graph )
.. cpp:function:: void CopyFromNonRoot( const DistGraph& distGraph, int root=0 )

copy namespace
^^^^^^^^^^^^^^
**TODO**

C API
-----
.. c:function:: ElError ElCopy_i( ElConstMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElCopy_s( ElConstMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElCopy_d( ElConstMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElCopy_c( ElConstMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElCopy_z( ElConstMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElCopyDist_i( ElConstDistMatrix_i X, ElDistMatrix_i Y )
.. c:function:: ElError ElCopyDist_s( ElConstDistMatrix_s X, ElDistMatrix_s Y )
.. c:function:: ElError ElCopyDist_d( ElConstDistMatrix_d X, ElDistMatrix_d Y )
.. c:function:: ElError ElCopyDist_c( ElConstDistMatrix_c X, ElDistMatrix_c Y )
.. c:function:: ElError ElCopyDist_z( ElConstDistMatrix_z X, ElDistMatrix_z Y )
.. c:function:: ElError ElCopySparse_i( ElConstSparseMatrix_i X, ElSparseMatrix_i Y )
.. c:function:: ElError ElCopySparse_s( ElConstSparseMatrix_s X, ElSparseMatrix_s Y )
.. c:function:: ElError ElCopySparse_d( ElConstSparseMatrix_d X, ElSparseMatrix_d Y )
.. c:function:: ElError ElCopySparse_c( ElConstSparseMatrix_c X, ElSparseMatrix_c Y )
.. c:function:: ElError ElCopySparse_z( ElConstSparseMatrix_z X, ElSparseMatrix_z Y )
.. c:function:: ElError ElCopyDistSparse_i( ElConstDistSparseMatrix_i X, ElDistSparseMatrix_i Y )
.. c:function:: ElError ElCopyDistSparse_s( ElConstDistSparseMatrix_s X, ElDistSparseMatrix_s Y )
.. c:function:: ElError ElCopyDistSparse_d( ElConstDistSparseMatrix_d X, ElDistSparseMatrix_d Y )
.. c:function:: ElError ElCopyDistSparse_c( ElConstDistSparseMatrix_c X, ElDistSparseMatrix_c Y )
.. c:function:: ElError ElCopyDistSparse_z( ElConstDistSparseMatrix_z X, ElDistSparseMatrix_z Y )
.. c:function:: ElError ElCopyDistMultiVec_i( ElConstDistMultiVec_i A, ElDistMultiVec_i B )
.. c:function:: ElError ElCopyDistMultiVec_s( ElConstDistMultiVec_s A, ElDistMultiVec_s B )
.. c:function:: ElError ElCopyDistMultiVec_d( ElConstDistMultiVec_d A, ElDistMultiVec_d B )
.. c:function:: ElError ElCopyDistMultiVec_c( ElConstDistMultiVec_c A, ElDistMultiVec_c B )
.. c:function:: ElError ElCopyDistMultiVec_z( ElConstDistMultiVec_z A, ElDistMultiVec_z B )

.. c:function:: ElError ElCopySparseToDense_i( ElConstSparseMatrix_i A, ElMatrix_i B )
.. c:function:: ElError ElCopySparseToDense_s( ElConstSparseMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElCopySparseToDense_d( ElConstSparseMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElCopySparseToDense_c( ElConstSparseMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElCopySparseToDense_z( ElConstSparseMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElCopyDistSparseToDense_i( ElConstDistSparseMatrix_i A, ElSparseMatrix_i B )
.. c:function:: ElError ElCopyDistSparseToDense_s( ElConstDistSparseMatrix_s A, ElSparseMatrix_s B )
.. c:function:: ElError ElCopyDistSparseToDense_d( ElConstDistSparseMatrix_d A, ElSparseMatrix_d B )
.. c:function:: ElError ElCopyDistSparseToDense_c( ElConstDistSparseMatrix_c A, ElSparseMatrix_c B )
.. c:function:: ElError ElCopyDistSparseToDense_z( ElConstDistSparseMatrix_z A, ElSparseMatrix_z B )

.. c:function:: ElError ElCopySparseMatrixFromRoot_i( ElConstDistSparseMatrix_i ADist, ElSparseMatrix_i A )
.. c:function:: ElError ElCopySparseMatrixFromRoot_s( ElConstDistSparseMatrix_s ADist, ElSparseMatrix_s A )
.. c:function:: ElError ElCopySparseMatrixFromRoot_d( ElConstDistSparseMatrix_d ADist, ElSparseMatrix_d A )
.. c:function:: ElError ElCopySparseMatrixFromRoot_c( ElConstDistSparseMatrix_c ADist, ElSparseMatrix_c A )
.. c:function:: ElError ElCopySparseMatrixFromRoot_z( ElConstDistSparseMatrix_z ADist, ElSparseMatrix_z A )
.. c:function:: ElError ElCopySparseMatrixFromNonRoot_i( ElConstDistSparseMatrix_i ADist, int root )
.. c:function:: ElError ElCopySparseMatrixFromNonRoot_s( ElConstDistSparseMatrix_s ADist, int root )
.. c:function:: ElError ElCopySparseMatrixFromNonRoot_d( ElConstDistSparseMatrix_d ADist, int root )
.. c:function:: ElError ElCopySparseMatrixFromNonRoot_c( ElConstDistSparseMatrix_c ADist, int root )
.. c:function:: ElError ElCopySparseMatrixFromNonRoot_z( ElConstDistSparseMatrix_z ADist, int root )

.. c:function:: ElError ElCopyMultiVecFromRoot_i( ElConstDistMultiVec_i XDist, ElMatrix_i X )
.. c:function:: ElError ElCopyMultiVecFromRoot_s( ElConstDistMultiVec_s XDist, ElMatrix_s X )
.. c:function:: ElError ElCopyMultiVecFromRoot_d( ElConstDistMultiVec_d XDist, ElMatrix_d X )
.. c:function:: ElError ElCopyMultiVecFromRoot_c( ElConstDistMultiVec_c XDist, ElMatrix_c X )
.. c:function:: ElError ElCopyMultiVecFromRoot_z( ElConstDistMultiVec_z XDist, ElMatrix_z X )
.. c:function:: ElError ElCopyMultiVecFromNonRoot_i( ElConstDistMultiVec_i XDist, int root )
.. c:function:: ElError ElCopyMultiVecFromNonRoot_s( ElConstDistMultiVec_s XDist, int root )
.. c:function:: ElError ElCopyMultiVecFromNonRoot_d( ElConstDistMultiVec_d XDist, int root )
.. c:function:: ElError ElCopyMultiVecFromNonRoot_c( ElConstDistMultiVec_c XDist, int root )
.. c:function:: ElError ElCopyMultiVecFromNonRoot_z( ElConstDistMultiVec_z XDist, int root )

.. c:function:: ElError ElCopyGraph( ElConstGraph A, ElGraph B )
.. c:function:: ElError ElCopyDistGraph( ElConstDistGraph A, ElDistGraph B )
.. c:function:: ElError ElCopyGraphFromRoot( ElConstDistGraph distGraph, ElGraph graph )
.. c:function:: ElError ElCopyGraphFromNonRoot( ElConstDistGraph distGraph, int root )

Python API
----------
.. py:function:: Copy(X,Y)
.. py:function:: CopyFromRoot(ADist,ASeq)
.. py:function:: CopyFromNonRoot(ADist,root=0)
