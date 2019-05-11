View a submatrix via index ranges
---------------------------------
The following routines return a view of :math:`B(I,J)`, where :math:`I` and
:math:`J` are each half-open contiguous index ranges, i.e., [I.beg,I.end) and 
[J.beg,J.end).

C++ API
^^^^^^^

.. cpp:function:: void View( Matrix<T>& A, Matrix<T>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: void LockedView( Matrix<T>& A, const Matrix<T>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: void View( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: void LockedView( AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& B, Range<Int> I, Range<Int> J )

   The view is returned in :math:`A`.

.. cpp:function:: Matrix<T> View( Matrix<T>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: Matrix<T> LockedView( const Matrix<T>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: DistMatrix<T,U,V> View( DistMatrix<T,U,V>& B, Range<Int> I, Range<Int> J )
.. cpp:function:: DistMatrix<T,U,V> LockedView( const DistMatrix<T,U,V>& B, Range<Int> I, Range<Int> J )

   The view is the return value of the function.

C API
^^^^^

.. c:function:: ElError ElView_i( ElMatrix_i A, ElMatrix_i B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElView_s( ElMatrix_s A, ElMatrix_s B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElView_d( ElMatrix_d A, ElMatrix_d B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElView_c( ElMatrix_c A, ElMatrix_c B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElView_z( ElMatrix_z A, ElMatrix_z B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElViewDist_i( ElDistMatrix_i A, ElDistMatrix_i B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElViewDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElViewDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElViewDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElViewDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElRange_i I, ElRange_i J )

   The input matrix is mutable

.. c:function:: ElError ElLockedView_i( ElMatrix_i A, ElConstMatrix_i B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedView_s( ElMatrix_s A, ElConstMatrix_s B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedView_d( ElMatrix_d A, ElConstMatrix_d B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedView_c( ElMatrix_c A, ElConstMatrix_c B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedView_z( ElMatrix_z A, ElConstMatrix_z B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedViewDist_i( ElDistMatrix_i A, ElConstDistMatrix_i B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedViewDist_s( ElDistMatrix_s A, ElConstDistMatrix_s B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedViewDist_d( ElDistMatrix_d A, ElConstDistMatrix_d B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedViewDist_c( ElDistMatrix_c A, ElConstDistMatrix_c B, ElRange_i I, ElRange_i J )
.. c:function:: ElError ElLockedViewDist_z( ElDistMatrix_z A, ElConstDistMatrix_z B, ElRange_i I, ElRange_i J )

   The input matrix need not be mutable
