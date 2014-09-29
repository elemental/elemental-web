Viewing submatrices
===================
The following routines form light-weight 
(:math:`O(1)` storage space and construction time) objects which represent 
contiguous submatrices of a given matrix. In many ways, they are an 
object-oriented equivalent of the BLAS convention of representing a matrix
via a pointer, a leading dimension, and its dimensions. Routines with a 
'Locked' prefix return immutable views, whereas routines without the 'Locked'
prefix insist that the data pointed to by the constructed view can be 
modified.

Half-open range
---------------
It is useful to represent intervals in the half-open form :math:`[a,b)`, as
this representation easily allows for expressing empty index intervals without
the usage of negative numbers, e.g., :math:`[0,0)`.

C++ API
^^^^^^^

.. cpp:type:: Range<T>

   .. cpp:member:: T beg
   .. cpp:member:: T end

   .. cpp:function:: Range()
      
      Initializes `beg` and `end` to zero

   .. cpp:function:: Range( T begArg, T endArg )

      Initializes `beg` to `begArg` and `end` to `endArg`

   .. cpp:function:: Range<T> operator+( T shift ) const

      Returns a copy of this object but with the beginning and end values
      increased by `shift`

   .. cpp:function:: Range<T> operator-( T shift ) const

      Returns a copy of this object but with the beginning and end values
      decreased by `shift`

.. cpp:type:: Range<Int>
.. cpp:type:: Range<float>
.. cpp:type:: Range<double>

.. cpp:type:: IR

   A typedef to :cpp:type:`Range\<Int>` which is convenient when extracting
   contiguous submatrices

C API
^^^^^

.. c:type:: Range_i

   .. c:member:: ElInt beg
   .. c:member:: ElInt end

.. c:type:: Range_s

   .. c:member:: float beg
   .. c:member:: float end

.. c:type:: Range_d

   .. c:member:: double beg
   .. c:member:: double end

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
