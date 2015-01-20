View a submatrix via offset and size
------------------------------------
The following routines return a view of a `height` by `width` contiguous 
submatrix of the matrix :math:`B` whose upper-left entry has coordinates
:math:`(i,j)`.

C++ API
^^^^^^^

.. cpp:function:: void View( Matrix<T>& A, Matrix<T>& B, int i, int j, int height, int width )
.. cpp:function:: void LockedView( Matrix<T>& A, const Matrix<T>& B, int i, int j, int height, int width )
.. cpp:function:: void View( DistMatrix<T,U,V>& A, DistMatrix<T,U,V>& B, int i, int j, int height, int width )
.. cpp:function:: void LockedView( DistMatrix<T,U,V>& A, const DistMatrix<T,U,V>& B, int i, int j, int height, int width )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> View( Matrix<T>& B, int i, int j, int height, int width )
.. cpp:function:: Matrix<T> LockedView( const Matrix<T>& B, int i, int j, int height, int width )
.. cpp:function:: DistMatrix<T,U,V> View( DistMatrix<T,U,V>& B, int i, int j, int height, int width )
.. cpp:function:: DistMatrix<T,U,V> LockedView( const DistMatrix<T,U,V>& B, int i, int j, int height, int width )

   The view is the return value of the function.

C API
^^^^^

.. c:function:: ElError ElViewOffset_i( ElMatrix_i A, ElMatrix_i B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffset_s( ElMatrix_s A, ElMatrix_s B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffset_d( ElMatrix_d A, ElMatrix_d B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffset_c( ElMatrix_c A, ElMatrix_c B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffset_z( ElMatrix_z A, ElMatrix_z B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffsetDist_i( ElDistMatrix_i A, ElDistMatrix_i B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffsetDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffsetDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffsetDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElViewOffsetDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElInt i, ElInt j, ElInt height, ElInt width )

   The input matrix is mutable

.. c:function:: ElError ElLockedViewOffset_i( ElMatrix_i A, ElConstMatrix_i B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffset_s( ElMatrix_s A, ElConstMatrix_s B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffset_d( ElMatrix_d A, ElConstMatrix_d B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffset_c( ElMatrix_c A, ElConstMatrix_c B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffset_z( ElMatrix_z A, ElConstMatrix_z B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffsetDist_i( ElDistMatrix_i A, ElConstDistMatrix_i B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffsetDist_s( ElDistMatrix_s A, ElConstDistMatrix_s B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffsetDist_d( ElDistMatrix_d A, ElConstDistMatrix_d B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffsetDist_c( ElDistMatrix_c A, ElConstDistMatrix_c B, ElInt i, ElInt j, ElInt height, ElInt width )
.. c:function:: ElError ElLockedViewOffsetDist_z( ElDistMatrix_z A, ElConstDistMatrix_z B, ElInt i, ElInt j, ElInt height, ElInt width )

   The input matrix need not be mutable
