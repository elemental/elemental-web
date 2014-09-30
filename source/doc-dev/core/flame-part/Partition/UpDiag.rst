Up the main diagonal
--------------------
Given an :math:`m \times n` matrix `A`, configure `ATL`, `ATR`, `ABL`, and `ABR` to view the local data of `A` corresponding to the partitioning

.. math::

   A = \left(\begin{array}{cc} A_{TL} & A_{TR} \\ A_{BL} & A_{BR} \end{array}\right),

where the diagonal of :math:`A_{BR}` lies on the main diagonal 
(aka, the *left* diagonal) of :math:`A` and is of the specified height/width.

C++ API
^^^^^^^

.. cpp:function:: void PartitionUpDiagonal( Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpDiagonal( const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionUpDiagonal( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpDiagonal( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionUpDiagonal_i( ElMatrix_i A, ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i ABL, ElMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonal_s( ElMatrix_s A, ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s ABL, ElMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonal_d( ElMatrix_d A, ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d ABL, ElMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonal_c( ElMatrix_c A, ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c ABL, ElMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonal_z( ElMatrix_z A, ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z ABL, ElMatrix_z ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonalDist_i( ElDistMatrix_i A, ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonalDist_s( ElDistMatrix_s A, ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonalDist_d( ElDistMatrix_d A, ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonalDist_c( ElDistMatrix_c A, ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElPartitionUpDiagonalDist_z( ElDistMatrix_z A, ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElInt diagDist )

.. c:function:: ElError ElLockedPartitionUpDiagonal_i( ElConstMatrix_i A, ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i ABL, ElMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonal_s( ElConstMatrix_s A, ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s ABL, ElMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonal_d( ElConstMatrix_d A, ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d ABL, ElMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonal_c( ElConstMatrix_c A, ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c ABL, ElMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonal_z( ElConstMatrix_z A, ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z ABL, ElMatrix_z ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonalDist_i( ElConstDistMatrix_i A, ElDistConstMatrix_i ATL, ElDistConstMatrix_i ATR, ElDistConstMatrix_i ABL, ElDistConstMatrix_i ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonalDist_s( ElConstDistMatrix_s A, ElDistConstMatrix_s ATL, ElDistConstMatrix_s ATR, ElDistConstMatrix_s ABL, ElDistConstMatrix_s ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonalDist_d( ElConstDistMatrix_d A, ElDistConstMatrix_d ATL, ElDistConstMatrix_d ATR, ElDistConstMatrix_d ABL, ElDistConstMatrix_d ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonalDist_c( ElConstDistMatrix_c A, ElDistConstMatrix_c ATL, ElDistConstMatrix_c ATR, ElDistConstMatrix_c ABL, ElDistConstMatrix_c ABR, ElInt diagDist )
.. c:function:: ElError ElLockedPartitionUpDiagonalDist_z( ElConstDistMatrix_z A, ElDistConstMatrix_z ATL, ElDistConstMatrix_z ATR, ElDistConstMatrix_z ABL, ElDistConstMatrix_z ABR, ElInt diagDist )
