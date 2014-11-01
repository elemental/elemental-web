2x1 matrix of blocks
--------------------
The following routines vertically merge two matrices which have consistent 
leading dimensions and sizes. When the matrices are distributed, their 
alignments must also be consistent. That is to say, if the inputs are 
consistent, a view of :math:`\begin{pmatrix} B_T \\ B_B \end{pmatrix}` is
returned.

.. note:: 

   :math:`B_T` and :math:`B_B` *must* be contiguous in the sense that, if
   the local portion of :math:`B_T` is :math:`m \times n` with leading 
   dimension `ldim`, then the top-left entry of :math:`B_B` must occur 
   precisely :math:`m` entries after the top-left entry of :math:`B_T`, and 
   both the leading dimensions and widths of the two matricees must be 
   identical.

C++ API
^^^^^^^

.. cpp:function:: void Merge2x1( Matrix<T>& A, Matrix<T>& BT, Matrix<T>& BB )
.. cpp:function:: void LockedMerge2x1( Matrix<T>& A, const Matrix<T>& BT, const Matrix<T>& BB )
.. cpp:function:: void Merge2x1( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& BT, DistMatrix<T,U,V>& BB )
.. cpp:function:: void LockedMerge2x1( AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& BT, const AbstractDistMatrix<T>& BB )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> Merge2x1( Matrix<T>& BT, Matrix<T>& BB )
.. cpp:function:: Matrix<T> LockedMerge2x1( const Matrix<T>& BT, const Matrix<T>& BB )
.. cpp:function:: DistMatrix<T,U,V> Merge2x1( DistMatrix<T,U,V>& BT, DistMatrix<T,U,V>& BB )
.. cpp:function:: DistMatrix<T,U,V> LockedMerge2x1( const DistMatrix<T,U,V>& BT, const DistMatrix<T,U,V>& BB )

   The view is the return value of the function.

C API
^^^^^

.. c:function:: ElError ElMerge2x1_i( ElMatrix_i A, ElMatrix_i BT, ElMatrix_i BB )
.. c:function:: ElError ElMerge2x1_s( ElMatrix_s A, ElMatrix_s BT, ElMatrix_s BB )
.. c:function:: ElError ElMerge2x1_d( ElMatrix_d A, ElMatrix_d BT, ElMatrix_d BB )
.. c:function:: ElError ElMerge2x1_c( ElMatrix_c A, ElMatrix_c BT, ElMatrix_c BB )
.. c:function:: ElError ElMerge2x1_z( ElMatrix_z A, ElMatrix_z BT, ElMatrix_z BB )
.. c:function:: ElError ElMerge2x1Dist_i( ElDistMatrix_i A, ElDistMatrix_i BT, ElDistMatrix_i BB )
.. c:function:: ElError ElMerge2x1Dist_s( ElDistMatrix_s A, ElDistMatrix_s BT, ElDistMatrix_s BB )
.. c:function:: ElError ElMerge2x1Dist_d( ElDistMatrix_d A, ElDistMatrix_d BT, ElDistMatrix_d BB )
.. c:function:: ElError ElMerge2x1Dist_c( ElDistMatrix_c A, ElDistMatrix_c BT, ElDistMatrix_c BB )
.. c:function:: ElError ElMerge2x1Dist_z( ElDistMatrix_z A, ElDistMatrix_z BT, ElDistMatrix_z BB )

.. c:function:: ElError ElLockedMerge2x1_i( ElMatrix_i A, ElConstMatrix_i BT, ElConstMatrix_i BB )
.. c:function:: ElError ElLockedMerge2x1_s( ElMatrix_s A, ElConstMatrix_s BT, ElConstMatrix_s BB )
.. c:function:: ElError ElLockedMerge2x1_d( ElMatrix_d A, ElConstMatrix_d BT, ElConstMatrix_d BB )
.. c:function:: ElError ElLockedMerge2x1_c( ElMatrix_c A, ElConstMatrix_c BT, ElConstMatrix_c BB )
.. c:function:: ElError ElLockedMerge2x1_z( ElMatrix_z A, ElConstMatrix_z BT, ElConstMatrix_z BB )
.. c:function:: ElError ElLockedMerge2x1Dist_i( ElDistMatrix_i A, ElConstDistMatrix_i BT, ElConstDistMatrix_i BB )
.. c:function:: ElError ElLockedMerge2x1Dist_s( ElDistMatrix_s A, ElConstDistMatrix_s BT, ElConstDistMatrix_s BB )
.. c:function:: ElError ElLockedMerge2x1Dist_d( ElDistMatrix_d A, ElConstDistMatrix_d BT, ElConstDistMatrix_d BB )
.. c:function:: ElError ElLockedMerge2x1Dist_c( ElDistMatrix_c A, ElConstDistMatrix_c BT, ElConstDistMatrix_c BB )
.. c:function:: ElError ElLockedMerge2x1Dist_z( ElDistMatrix_z A, ElConstDistMatrix_z BT, ElConstDistMatrix_z BB )
