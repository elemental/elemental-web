View a full matrix
------------------
The following routines return a view of an entire matrix. 

C++ API
^^^^^^^

.. cpp:function:: void View( Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void LockedView( Matrix<T>& A, const Matrix<T>& B )
.. cpp:function:: void View( DistMatrix<T,U,V>& A, DistMatrix<T,U,V>& B )
.. cpp:function:: void LockedView( DistMatrix<T,U,V>& A, const DistMatrix<T,U,V>& B )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> View( Matrix<T>& B )
.. cpp:function:: Matrix<T> LockedView( const Matrix<T>& B )
.. cpp:function:: DistMatrix<T,U,V> View( DistMatrix<T,U,V>& B )
.. cpp:function:: DistMatrix<T,U,V> LockedView( const DistMatrix<T,U,V>& B )

   Return a view of the matrix `B`.

C API
^^^^^

.. c:function:: ElError ElViewFull_i( ElMatrix_i A, ElMatrix_i B )
.. c:function:: ElError ElViewFull_s( ElMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElViewFull_d( ElMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElViewFull_c( ElMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElViewFull_z( ElMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElViewFullDist_i( ElDistMatrix_i A, ElDistMatrix_i B )
.. c:function:: ElError ElViewFullDist_s( ElDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElViewFullDist_d( ElDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElViewFullDist_c( ElDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElViewFullDist_z( ElDistMatrix_z A, ElDistMatrix_z B )

   The input matrix is mutable

.. c:function:: ElError ElLockedViewFull_i( ElMatrix_i A, ElConstMatrix_i B )
.. c:function:: ElError ElLockedViewFull_s( ElMatrix_s A, ElConstMatrix_s B )
.. c:function:: ElError ElLockedViewFull_d( ElMatrix_d A, ElConstMatrix_d B )
.. c:function:: ElError ElLockedViewFull_c( ElMatrix_c A, ElConstMatrix_c B )
.. c:function:: ElError ElLockedViewFull_z( ElMatrix_z A, ElConstMatrix_z B )
.. c:function:: ElError ElLockedViewFullDist_i( ElDistMatrix_i A, ElConstDistMatrix_i B )
.. c:function:: ElError ElLockedViewFullDist_s( ElDistMatrix_s A, ElConstDistMatrix_s B )
.. c:function:: ElError ElLockedViewFullDist_d( ElDistMatrix_d A, ElConstDistMatrix_d B )
.. c:function:: ElError ElLockedViewFullDist_c( ElDistMatrix_c A, ElConstDistMatrix_c B )
.. c:function:: ElError ElLockedViewFullDist_z( ElDistMatrix_z A, ElConstDistMatrix_z B )

   The input matrix need not be mutable
