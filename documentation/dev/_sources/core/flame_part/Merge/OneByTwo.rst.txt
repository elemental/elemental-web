1x2 matrix of blocks
--------------------
The following routines horizontally merge two matrices which have consistent 
leading dimensions and sizes. When the matrices are distributed, their
alignments must also be distributed. That is to say, if the inputs are 
consistent, a view is constructed of 
:math:`\begin{pmatrix} B_L & B_R \end{pmatrix}`.

.. note:: 

   :math:`B_L` and :math:`B_R` *must* be contiguous in the sense that, if
   the local portion of :math:`B_L` is :math:`m \times n` with leading 
   dimension `ldim`, then the top-left entry of :math:`B_R` must occur 
   precisely `ldim` times :math:`n` entries after the top-left entry of 
   :math:`B_L`, and :math:`B_R` must have an equivalent leading dimension.

C++ API
^^^^^^^

.. cpp:function:: void Merge1x2( Matrix<T>& A, Matrix<T>& BL, Matrix<T>& BR )
.. cpp:function:: void LockedMerge1x2( Matrix<T>& A, const Matrix<T>& BL, const Matrix<T>& BR )
.. cpp:function:: void Merge1x2( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& BL, AbstractDistMatrix<T>& BR )
.. cpp:function:: void LockedMerge1x2( AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& BL, const AbstractDistMatrix<T>& BR )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> Merge1x2( Matrix<T>& BL, Matrix<T>& BR )
.. cpp:function:: Matrix<T> LockedMerge1x2( const Matrix<T>& BL, const Matrix<T>& BR )
.. cpp:function:: DistMatrix<T,U,V> Merge1x2( DistMatrix<T,U,V>& BL, DistMatrix<T,U,V>& BR )
.. cpp:function:: DistMatrix<T,U,V> LockedMerge1x2( const DistMatrix<T,U,V>& BL, const DistMatrix<T,U,V>& BR )

   The view is the return value of the function.

C API
^^^^^

.. c:function:: ElError ElMerge1x2_i( ElMatrix_i A, ElMatrix_i BL, ElMatrix_i BR )
.. c:function:: ElError ElMerge1x2_s( ElMatrix_s A, ElMatrix_s BL, ElMatrix_s BR )
.. c:function:: ElError ElMerge1x2_d( ElMatrix_d A, ElMatrix_d BL, ElMatrix_d BR )
.. c:function:: ElError ElMerge1x2_c( ElMatrix_c A, ElMatrix_c BL, ElMatrix_c BR )
.. c:function:: ElError ElMerge1x2_z( ElMatrix_z A, ElMatrix_z BL, ElMatrix_z BR )
.. c:function:: ElError ElMerge1x2Dist_i( ElDistMatrix_i A, ElDistMatrix_i BL, ElDistMatrix_i BR )
.. c:function:: ElError ElMerge1x2Dist_s( ElDistMatrix_s A, ElDistMatrix_s BL, ElDistMatrix_s BR )
.. c:function:: ElError ElMerge1x2Dist_d( ElDistMatrix_d A, ElDistMatrix_d BL, ElDistMatrix_d BR )
.. c:function:: ElError ElMerge1x2Dist_c( ElDistMatrix_c A, ElDistMatrix_c BL, ElDistMatrix_c BR )
.. c:function:: ElError ElMerge1x2Dist_z( ElDistMatrix_z A, ElDistMatrix_z BL, ElDistMatrix_z BR )

.. c:function:: ElError ElLockedMerge1x2_i( ElMatrix_i A, ElMatrix_i BL, ElMatrix_i BR )
.. c:function:: ElError ElLockedMerge1x2_s( ElMatrix_s A, ElMatrix_s BL, ElMatrix_s BR )
.. c:function:: ElError ElLockedMerge1x2_d( ElMatrix_d A, ElMatrix_d BL, ElMatrix_d BR )
.. c:function:: ElError ElLockedMerge1x2_c( ElMatrix_c A, ElMatrix_c BL, ElMatrix_c BR )
.. c:function:: ElError ElLockedMerge1x2_z( ElMatrix_z A, ElMatrix_z BL, ElMatrix_z BR )
.. c:function:: ElError ElLockedMerge1x2Dist_i( ElDistMatrix_i A, ElConstDistMatrix_i BL, ElConstDistMatrix_i BR )
.. c:function:: ElError ElLockedMerge1x2Dist_s( ElDistMatrix_s A, ElConstDistMatrix_s BL, ElConstDistMatrix_s BR )
.. c:function:: ElError ElLockedMerge1x2Dist_d( ElDistMatrix_d A, ElConstDistMatrix_d BL, ElConstDistMatrix_d BR )
.. c:function:: ElError ElLockedMerge1x2Dist_c( ElDistMatrix_c A, ElConstDistMatrix_c BL, ElConstDistMatrix_c BR )
.. c:function:: ElError ElLockedMerge1x2Dist_z( ElDistMatrix_z A, ElConstDistMatrix_z BL, ElConstDistMatrix_z BR )
