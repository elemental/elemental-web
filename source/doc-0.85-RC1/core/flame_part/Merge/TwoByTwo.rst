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
