Reshape
=======
Reshape an :math:`m' \times n'` matrix into an :math:`m \times n` matrix,
where :math:`m'n' = mn`, with the entries maintaining their column-major 
ordering.

Python API
----------
.. py:function:: Reshape(m,n,A)

C++ API
-------
.. cpp:function:: void Reshape( Int m, Int n, const Matrix<T>& A, Matrix<T>& ASub )
.. cpp:function:: Matrix<T> Reshape( Int m, Int n, const Matrix<T>& A )

.. cpp:function:: void Reshape( Int m, Int n, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ASub )
.. cpp:function:: AbstractDistMatrix<T> Reshape( Int m, Int n, const AbstractDistMatrix<T>& A )

.. cpp:function:: void Reshape( Int m, Int n, const SparseMatrix<T>& A, SparseMatrix<T>& ASub )
.. cpp:function:: SparseMatrix<T> Reshape( Int m, Int n, const SparseMatrix<T>& A )

.. cpp:function:: void Reshape( Int m, Int n, const DistSparseMatrix<T>& A, DistSparseMatrix<T>& ASub )
.. cpp:function:: DistSparseMatrix<T> Reshape( Int m, Int n, const DistSparseMatrix<T>& A )

C API
-----

Integer
^^^^^^^
.. c:function:: ElError ElReshape_i( ElInt m, ElInt n, ElConstMatrix_i A, ElMatrix_i B )
.. c:function:: ElError ElReshapeDist_i( ElInt m, ElInt n, ElConstDistMatrix_i A, ElDistMatrix_i B )
.. c:function:: ElError ElReshapeSparse_i( ElInt m, ElInt n, ElConstSparseMatrix_i A, ElSparseMatrix_i B )
.. c:function:: ElError ElReshapeDistSparse_i( ElInt m, ElInt n, ElConstDistSparseMatrix_i A, ElDistSparseMatrix_i B )

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElReshape_s( ElInt m, ElInt n, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElReshapeDist_s( ElInt m, ElInt n, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElReshapeSparse_s( ElInt m, ElInt n, ElConstSparseMatrix_s A, ElSparseMatrix_s B )
.. c:function:: ElError ElReshapeDistSparse_s( ElInt m, ElInt n, ElConstDistSparseMatrix_s A, ElDistSparseMatrix_s B )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElReshape_d( ElInt m, ElInt n, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElReshapeDist_d( ElInt m, ElInt n, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElReshapeSparse_d( ElInt m, ElInt n, ElConstSparseMatrix_d A, ElSparseMatrix_d B )
.. c:function:: ElError ElReshapeDistSparse_d( ElInt m, ElInt n, ElConstDistSparseMatrix_d A, ElDistSparseMatrix_d B )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElReshape_c( ElInt m, ElInt n, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElReshapeDist_c( ElInt m, ElInt n, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElReshapeSparse_c( ElInt m, ElInt n, ElConstSparseMatrix_c A, ElSparseMatrix_c B )
.. c:function:: ElError ElReshapeDistSparse_c( ElInt m, ElInt n, ElConstDistSparseMatrix_c A, ElDistSparseMatrix_c B )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElReshape_z( ElInt m, ElInt n, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElReshapeDist_z( ElInt m, ElInt n, ElConstDistMatrix_z A, ElDistMatrix_z B )
.. c:function:: ElError ElReshapeSparse_z( ElInt m, ElInt n, ElConstSparseMatrix_z A, ElSparseMatrix_z B )
.. c:function:: ElError ElReshapeDistSparse_z( ElInt m, ElInt n, ElConstDistSparseMatrix_z A, ElDistSparseMatrix_z B )
