Down an offset diagonal
-----------------------
Given an :math:`m \times n` matrix `A`, configure `ATL`, `ATR`, `ABL`, and `ABR` to view the local data of `A` corresponding to the partitioning

.. math::

   A = \left(\begin{array}{cc} A_{TL} & A_{TR} \\ A_{BL} & A_{BR} \end{array}\right),

where the diagonal of :math:`A_{BR}` lies on the ``offset`` diagonal of 
:math:`A`, where the main diagonal corresponds to an offset of 0, the 
subdiagonal is an offset of :math:`-1`, the superdiagonal is an offset of 
:math:`1`, etc. The length of the diagonal of :math:`A_{TL}` is specified as
``diagDist``.

C++ API
^^^^^^^

.. cpp:function:: void PartitionDownOffsetDiagonal( Int offset, Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownOffsetDiagonal( Int offset, const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionDownOffsetDiagonal( Int offset, AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ATL, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownOffsetDiagonal( Int offset, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionDownOffsetDiagonal_i( ElInt offset, ElMatrix_i A, ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i ABL, ElMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonal_s( ElInt offset, ElMatrix_s A, ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s ABL, ElMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonal_d( ElInt offset, ElMatrix_d A, ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d ABL, ElMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonal_c( ElInt offset, ElMatrix_c A, ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c ABL, ElMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonal_z( ElInt offset, ElMatrix_z A, ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z ABL, ElMatrix_z ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonalDist_i( ElInt offset, ElDistMatrix_i A, ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonalDist_s( ElInt offset, ElDistMatrix_s A, ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonalDist_d( ElInt offset, ElDistMatrix_d A, ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonalDist_c( ElInt offset, ElDistMatrix_c A, ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionDownOffsetDiagonalDist_z( ElInt offset, ElDistMatrix_z A, ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElInt diagDist )

.. c:function:: ElError ElLockedPartitionDownOffsetDiagonal_i( ElInt offset, ElConstMatrix_i A, ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i ABL, ElMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonal_s( ElInt offset, ElConstMatrix_s A, ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s ABL, ElMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonal_d( ElInt offset, ElConstMatrix_d A, ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d ABL, ElMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonal_c( ElInt offset, ElConstMatrix_c A, ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c ABL, ElMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonal_z( ElInt offset, ElConstMatrix_z A, ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z ABL, ElMatrix_z ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonalDist_i( ElInt offset, ElConstDistMatrix_i A, ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonalDist_s( ElInt offset, ElConstDistMatrix_s A, ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonalDist_d( ElInt offset, ElConstDistMatrix_d A, ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonalDist_c( ElInt offset, ElConstDistMatrix_c A, ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionDownOffsetDiagonalDist_z( ElInt offset, ElConstDistMatrix_z A, ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElInt diagDist )

