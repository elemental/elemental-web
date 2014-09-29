Partitioning
============
The following routines are slight tweaks of the FLAME project's 
(as well as PLAPACK's) approach to submatrix tracking; the difference is that 
they have "locked" versions, which are meant for creating partitionings where 
the submatrices cannot be modified.

Upward
------
Given an :math:`m \times n` matrix `A`, configure `AT` and `AB` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{c}A_T \\ A_B \end{array}\right), 

where :math:`A_B` is of a specified height. 

.. cpp:function:: void PartitionUp( Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void LockedPartitionUp( const Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void PartitionUp( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void LockedPartitionUp( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAB=Blocksize() )

Downward
--------
Given an :math:`m \times n` matrix `A`, configure `AT` and `AB` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{c}A_T \\ A_B \end{array}\right),

where :math:`A_T` is of a specified height.

.. cpp:function:: void PartitionDown( Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void LockedPartitionDown( const Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void PartitionDown( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void LockedPartitionDown( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAT=Blocksize() )

Leftward
--------
Given an :math:`m \times n` matrix `A`, configure `AL` and `AR` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{cc} A_L & A_R \end{array}\right),

where :math:`A_R` is of a specified width.

.. cpp:function:: void PartitionLeft( Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void LockedPartitionLeft( const Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void PartitionLeft( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void LockedPartitionLeft( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAR=Blocksize() )

Rightward
---------
Given an :math:`m \times n` matrix `A`, configure `AL` and `AR` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{cc} A_L & A_R \end{array}\right),

where :math:`A_L` is of a specified width.

.. cpp:function:: void PartitionRight( Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void LockedPartitionRight( const Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void PartitionRight( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void LockedPartitionRight( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAL=Blocksize() )

Up the main diagonal
--------------------
Given an :math:`m \times n` matrix `A`, configure `ATL`, `ATR`, `ABL`, and `ABR` to view the local data of `A` corresponding to the partitioning

.. math::

   A = \left(\begin{array}{cc} A_{TL} & A_{TR} \\ A_{BL} & A_{BR} \end{array}\right),

where the diagonal of :math:`A_{BR}` lies on the main diagonal 
(aka, the *left* diagonal) of :math:`A` and is of the specified height/width.

.. cpp:function:: void PartitionUpDiagonal( Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpDiagonal( const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionUpDiagonal( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpDiagonal( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )

Up an offset diagonal
---------------------
Given an :math:`m \times n` matrix `A`, configure `ATL`, `ATR`, `ABL`, and `ABR` to view the local data of `A` corresponding to the partitioning

.. math::

   A = \left(\begin{array}{cc} A_{TL} & A_{TR} \\ A_{BL} & A_{BR} \end{array}\right),

where the diagonal of :math:`A_{BR}` lies on the ``offset`` diagonal of 
:math:`A`, where the main diagonal corresponds to an offset of 0, the 
subdiagonal is an offset of :math:`-1`, the superdiagonal is an offset of 
:math:`1`, etc. The length of the diagonal of :math:`A_{BR}` is specified as
``diagDist``.

.. cpp:function:: void PartitionUpOffsetDiagonal( Int offset, Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpOffsetDiagonal( Int offset, const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionUpOffsetDiagonal( Int offset, AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionUpOffsetDiagonal( Int offset, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )

Down the main diagonal
----------------------
Given an :math:`m \times n` matrix `A`, configure `ATL`, `ATR`, `ABL`, and `ABR` to view the local data of :math:`A` corresponding to the partitioning

.. math::

   A = \left(\begin{array}{cc} A_{TL} & A_{TR} \\ A_{BL} & A_{BR} \end{array}\right),

where the diagonal of :math:`A_{TL}` is of the specified length and lies on 
the main diagonal (aka, the *left* diagonal) of :math:`A`. 

.. cpp:function:: void PartitionDownDiagonal( Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownDiagonal( const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionDownDiagonal( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ATL, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownDiagonal( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )
 
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

.. cpp:function:: void PartitionDownOffsetDiagonal( Int offset, Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownOffsetDiagonal( Int offset, const Matrix<T>& A, Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& ABL, Matrix<T>& ABR, Int diagDist=Blocksize() )
.. cpp:function:: void PartitionDownOffsetDiagonal( Int offset, AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ATL, Int diagDist=Blocksize() )
.. cpp:function:: void LockedPartitionDownOffsetDiagonal( Int offset, const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, Int diagDist=Blocksize() )
