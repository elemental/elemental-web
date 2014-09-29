Merging submatrices
===================
Many matrix algorithms can be formulated as a sequence of operations on 
submatrices which are repeatedly split into smaller (contiguous) submatrices 
and then reformed in a different manner. Such a reformation process requires
only a small (constant) number of operations when the matrices to be "merged" 
are stored contiguously in memory, and so the following routines make this
assumption.

.. note::

   These routines are currently exclusively used within Elemental's 
   :cpp:func:`SlidePartitionUp`, :cpp:func:`SlidePartitionDown`, etc., routines
   and are likely only of use to advanced users in very special circumstances.

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

2x2 matrix of blocks
--------------------
The following routines merge a two-by-two set of contiguous submatrices which
have conformal leading dimensions, sizes, and, if applicable, alignments.
That is to say, if the inputs are consistent, a view of 
:math:`\begin{pmatrix} B_{TL} & B_{TR} \\ B_{BL} & B_{BR} \end{pmatrix}` is 
returned.

.. note:: 

   The constraints described above for horizontally and vertically merging
   submatrices both apply here.

C++ API
^^^^^^^

.. cpp:function:: void Merge2x2( Matrix<T>& A, Matrix<T>& BTL, Matrix<T>& BTR, Matrix<T>& BBL, Matrix<T>& BBR )
.. cpp:function:: void LockedMerge2x2( Matrix<T>& A, const Matrix<T>& BTL, const Matrix<T>& BTR, const Matrix<T>& BBL, const Matrix<T>& BBR )
.. cpp:function:: void Merge2x2( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& BTL, AbstractDistMatrix<T>& BTR, AbstractDistMatrix<T>& BBL, AbstractDistMatrix<T>& BBR )
.. cpp:function:: void LockedMerge2x2( AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& BTL, const AbstractDistMatrix<T>& BTR, const AbstractDistMatrix<T>& BBL, const AbstractDistMatrix<T>& BBR )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> Merge2x2( Matrix<T>& BTL, Matrix<T>& BTR, Matrix<T>& BBL, Matrix<T>& BBR )
.. cpp:function:: Matrix<T> LockedMerge2x2( const Matrix<T>& BTL, const Matrix<T>& BTR, const Matrix<T>& BBL, const Matrix<T>& BBR )
.. cpp:function:: DistMatrix<T,U,V> Merge2x2( DistMatrix<T,U,V>& BTL, DistMatrix<T,U,V>& BTR, DistMatrix<T,U,V>& BBL, DistMatrix<T,U,V>& BBR )
.. cpp:function:: DistMatrix<T,U,V> LockedMerge2x2( const DistMatrix<T,U,V>& BTL, const DistMatrix<T,U,V>& BTR, const DistMatrix<T,U,V>& BBL, const DistMatrix<T,U,V>& BBR )

   The view is the return value of the function

C API
^^^^^

.. c:function:: ElError ElMerge2x2_i( ElMatrix_i A, ElMatrix_i BTL, ElMatrix_i BTR, ElMatrix_i BBL, ElMatrix_i BBR )
.. c:function:: ElError ElMerge2x2_s( ElMatrix_s A, ElMatrix_s BTL, ElMatrix_s BTR, ElMatrix_s BBL, ElMatrix_s BBR )
.. c:function:: ElError ElMerge2x2_d( ElMatrix_d A, ElMatrix_d BTL, ElMatrix_d BTR, ElMatrix_d BBL, ElMatrix_d BBR )
.. c:function:: ElError ElMerge2x2_c( ElMatrix_c A, ElMatrix_c BTL, ElMatrix_c BTR, ElMatrix_c BBL, ElMatrix_c BBR )
.. c:function:: ElError ElMerge2x2_z( ElMatrix_z A, ElMatrix_z BTL, ElMatrix_z BTR, ElMatrix_z BBL, ElMatrix_z BBR )
.. c:function:: ElError ElMerge2x2Dist_i( ElDistMatrix_i A, ElDistMatrix_i BTL, ElDistMatrix_i BTR, ElDistMatrix_i BBL, ElDistMatrix_i BBR )
.. c:function:: ElError ElMerge2x2Dist_s( ElDistMatrix_s A, ElDistMatrix_s BTL, ElDistMatrix_s BTR, ElDistMatrix_s BBL, ElDistMatrix_s BBR )
.. c:function:: ElError ElMerge2x2Dist_d( ElDistMatrix_d A, ElDistMatrix_d BTL, ElDistMatrix_d BTR, ElDistMatrix_d BBL, ElDistMatrix_d BBR )
.. c:function:: ElError ElMerge2x2Dist_c( ElDistMatrix_c A, ElDistMatrix_c BTL, ElDistMatrix_c BTR, ElDistMatrix_c BBL, ElDistMatrix_c BBR )
.. c:function:: ElError ElMerge2x2Dist_z( ElDistMatrix_z A, ElDistMatrix_z BTL, ElDistMatrix_z BTR, ElDistMatrix_z BBL, ElDistMatrix_z BBR )

.. c:function:: ElError ElLockedMerge2x2_i( ElMatrix_i A, ElConstMatrix_i BTL, ElConstMatrix_i BTR, ElConstMatrix_i BBL, ElConstMatrix_i BBR )
.. c:function:: ElError ElLockedMerge2x2_s( ElMatrix_s A, ElConstMatrix_s BTL, ElConstMatrix_s BTR, ElConstMatrix_s BBL, ElConstMatrix_s BBR )
.. c:function:: ElError ElLockedMerge2x2_d( ElMatrix_d A, ElConstMatrix_d BTL, ElConstMatrix_d BTR, ElConstMatrix_d BBL, ElConstMatrix_d BBR )
.. c:function:: ElError ElLockedMerge2x2_c( ElMatrix_c A, ElConstMatrix_c BTL, ElConstMatrix_c BTR, ElConstMatrix_c BBL, ElConstMatrix_c BBR )
.. c:function:: ElError ElLockedMerge2x2_z( ElMatrix_z A, ElConstMatrix_z BTL, ElConstMatrix_z BTR, ElConstMatrix_z BBL, ElConstMatrix_z BBR )
.. c:function:: ElError ElLockedMerge2x2Dist_i( ElDistMatrix_i A, ElConstDistMatrix_i BTL, ElConstDistMatrix_i BTR, ElConstDistMatrix_i BBL, ElConstDistMatrix_i BBR )
.. c:function:: ElError ElLockedMerge2x2Dist_s( ElDistMatrix_s A, ElConstDistMatrix_s BTL, ElConstDistMatrix_s BTR, ElConstDistMatrix_s BBL, ElConstDistMatrix_s BBR )
.. c:function:: ElError ElLockedMerge2x2Dist_d( ElDistMatrix_d A, ElConstDistMatrix_d BTL, ElConstDistMatrix_d BTR, ElConstDistMatrix_d BBL, ElConstDistMatrix_d BBR )
.. c:function:: ElError ElLockedMerge2x2Dist_c( ElDistMatrix_c A, ElConstDistMatrix_c BTL, ElConstDistMatrix_c BTR, ElConstDistMatrix_c BBL, ElConstDistMatrix_c BBR )
.. c:function:: ElError ElLockedMerge2x2Dist_z( ElDistMatrix_z A, ElConstDistMatrix_z BTL, ElConstDistMatrix_z BTR, ElConstDistMatrix_z BBL, ElConstDistMatrix_z BBR )
