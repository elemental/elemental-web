Down a diagonal
---------------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{c|cc} A_{00} & A_{01} & A_{02} \\
                                 \hline
                                 A_{10} & A_{11} & A_{12} \\
                                 A_{20} & A_{21} & A_{22} \end{array}\right)

into

.. math::

   \left(\begin{array}{c|c} A_{TL} & A_{TR} \\
                            \hline
                            A_{BL} & A_{BR} \end{array}\right) = 
   \left(\begin{array}{cc|c} A_{00} & A_{01} & A_{02} \\
                             A_{10} & A_{11} & A_{12} \\
                             \hline
                             A_{20} & A_{21} & A_{22} \end{array}\right).

C++ API
^^^^^^^

.. cpp:function:: void SlidePartitionDownDiagonal( Matrix<T>& ATL, Matrix<T>& ATR, const Matrix<T>& A00, const Matrix<T>& A01, const Matrix<T>& A02, const Matrix<T>& A10, const Matrix<T>& A11, const Matrix<T>& A12, Matrix<T>& ABL, Matrix<T>& ABR, const Matrix<T>& A20, const Matrix<T>& A21, const Matrix<T>& A22 )
.. cpp:function:: void SlideLockedPartitionDownDiagonal( Matrix<T>& ATL, Matrix<T>& ATR, const Matrix<T>& A00, const Matrix<T>& A01, const Matrix<T>& A02, const Matrix<T>& A10, const Matrix<T>& A11, const Matrix<T>& A12, Matrix<T>& ABL, Matrix<T>& ABR, const Matrix<T>& A20, const Matrix<T>& A21, const Matrix<T>& A22 )
.. cpp:function:: void SlidePartitionDownDiagonal( AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, const AbstractDistMatrix<T>& A00, const AbstractDistMatrix<T>& A01, const AbstractDistMatrix<T>& A02, const AbstractDistMatrix<T>& A10, const AbstractDistMatrix<T>& A11, const AbstractDistMatrix<T>& A12, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, const AbstractDistMatrix<T>& A20, const AbstractDistMatrix<T>& A21, const AbstractDistMatrix<T>& A22 )
.. cpp:function:: void SlideLockedPartitionDownDiagonal( AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, const AbstractDistMatrix<T>& A00, const AbstractDistMatrix<T>& A01, const AbstractDistMatrix<T>& A02, const AbstractDistMatrix<T>& A10, const AbstractDistMatrix<T>& A11, const AbstractDistMatrix<T>& A12, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, const AbstractDistMatrix<T>& A20, const AbstractDistMatrix<T>& A21, const AbstractDistMatrix<T>& A22 )

Note that the above routines are meant to be used as:

.. code-block:: cpp

   SlidePartitionDownDiagonal( ATL, /**/ ATR,  A00, A01, /**/ A02,
                                    /**/       A10, A11, /**/ A12,
                              /*************/ /******************/
                               ABL, /**/ ABR,  A20, A21, /**/ A22 );

C API
^^^^^

.. c:function:: ElError ElSlidePartitionDownDiagonal_i( ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i A00, ElMatrix_i A01, ElMatrix_i A02, ElMatrix_i A10, ElMatrix_i A11, ElMatrix_i A12, ElMatrix_i ABL, ElMatrix_i ABR, ElMatrix_i A20, ElMatrix_i A21, ElMatrix_i A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonal_s( ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s A00, ElMatrix_s A01, ElMatrix_s A02, ElMatrix_s A10, ElMatrix_s A11, ElMatrix_s A12, ElMatrix_s ABL, ElMatrix_s ABR, ElMatrix_s A20, ElMatrix_s A21, ElMatrix_s A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonal_d( ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d A00, ElMatrix_d A01, ElMatrix_d A02, ElMatrix_d A10, ElMatrix_d A11, ElMatrix_d A12, ElMatrix_d ABL, ElMatrix_d ABR, ElMatrix_d A20, ElMatrix_d A21, ElMatrix_d A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonal_c( ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c A00, ElMatrix_c A01, ElMatrix_c A02, ElMatrix_c A10, ElMatrix_c A11, ElMatrix_c A12, ElMatrix_c ABL, ElMatrix_c ABR, ElMatrix_c A20, ElMatrix_c A21, ElMatrix_c A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonal_z( ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z A00, ElMatrix_z A01, ElMatrix_z A02, ElMatrix_z A10, ElMatrix_z A11, ElMatrix_z A12, ElMatrix_z ABL, ElMatrix_z ABR, ElMatrix_z A20, ElMatrix_z A21, ElMatrix_z A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonalDist_i( ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElDistMatrix_i A00, ElDistMatrix_i A01, ElDistMatrix_i A02, ElDistMatrix_i A10, ElDistMatrix_i A11, ElDistMatrix_i A12, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElDistMatrix_i A20, ElDistMatrix_i A21, ElDistMatrix_i A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonalDist_s( ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElDistMatrix_s A00, ElDistMatrix_s A01, ElDistMatrix_s A02, ElDistMatrix_s A10, ElDistMatrix_s A11, ElDistMatrix_s A12, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElDistMatrix_s A20, ElDistMatrix_s A21, ElDistMatrix_s A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonalDist_d( ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElDistMatrix_d A00, ElDistMatrix_d A01, ElDistMatrix_d A02, ElDistMatrix_d A10, ElDistMatrix_d A11, ElDistMatrix_d A12, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElDistMatrix_d A20, ElDistMatrix_d A21, ElDistMatrix_d A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonalDist_c( ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElDistMatrix_c A00, ElDistMatrix_c A01, ElDistMatrix_c A02, ElDistMatrix_c A10, ElDistMatrix_c A11, ElDistMatrix_c A12, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElDistMatrix_c A20, ElDistMatrix_c A21, ElDistMatrix_c A22 )
.. c:function:: ElError ElSlidePartitionDownDiagonalDist_z( ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElDistMatrix_z A00, ElDistMatrix_z A01, ElDistMatrix_z A02, ElDistMatrix_z A10, ElDistMatrix_z A11, ElDistMatrix_z A12, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElDistMatrix_z A20, ElDistMatrix_z A21, ElDistMatrix_z A22 )

.. c:function:: ElError ElSlideLockedPartitionDownDiagonal_i( ElMatrix_i ATL, ElMatrix_i ATR, ElConstMatrix_i A00, ElConstMatrix_i A01, ElConstMatrix_i A02, ElConstMatrix_i A10, ElConstMatrix_i A11, ElConstMatrix_i A12, ElMatrix_i ABL, ElMatrix_i ABR, ElConstMatrix_i A20, ElConstMatrix_i A21, ElConstMatrix_i A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonal_s( ElMatrix_s ATL, ElMatrix_s ATR, ElConstMatrix_s A00, ElConstMatrix_s A01, ElConstMatrix_s A02, ElConstMatrix_s A10, ElConstMatrix_s A11, ElConstMatrix_s A12, ElMatrix_s ABL, ElMatrix_s ABR, ElConstMatrix_s A20, ElConstMatrix_s A21, ElConstMatrix_s A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonal_d( ElMatrix_d ATL, ElMatrix_d ATR, ElConstMatrix_d A00, ElConstMatrix_d A01, ElConstMatrix_d A02, ElConstMatrix_d A10, ElConstMatrix_d A11, ElConstMatrix_d A12, ElMatrix_d ABL, ElMatrix_d ABR, ElConstMatrix_d A20, ElConstMatrix_d A21, ElConstMatrix_d A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonal_c( ElMatrix_c ATL, ElMatrix_c ATR, ElConstMatrix_c A00, ElConstMatrix_c A01, ElConstMatrix_c A02, ElConstMatrix_c A10, ElConstMatrix_c A11, ElConstMatrix_c A12, ElMatrix_c ABL, ElMatrix_c ABR, ElConstMatrix_c A20, ElConstMatrix_c A21, ElConstMatrix_c A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonal_z( ElMatrix_z ATL, ElMatrix_z ATR, ElConstMatrix_z A00, ElConstMatrix_z A01, ElConstMatrix_z A02, ElConstMatrix_z A10, ElConstMatrix_z A11, ElConstMatrix_z A12, ElMatrix_z ABL, ElMatrix_z ABR, ElConstMatrix_z A20, ElConstMatrix_z A21, ElConstMatrix_z A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonalDist_i( ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElConstDistMatrix_i A00, ElConstDistMatrix_i A01, ElConstDistMatrix_i A02, ElConstDistMatrix_i A10, ElConstDistMatrix_i A11, ElConstDistMatrix_i A12, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElConstDistMatrix_i A20, ElConstDistMatrix_i A21, ElConstDistMatrix_i A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonalDist_s( ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElConstDistMatrix_s A00, ElConstDistMatrix_s A01, ElConstDistMatrix_s A02, ElConstDistMatrix_s A10, ElConstDistMatrix_s A11, ElConstDistMatrix_s A12, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElConstDistMatrix_s A20, ElConstDistMatrix_s A21, ElConstDistMatrix_s A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonalDist_d( ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElConstDistMatrix_d A00, ElConstDistMatrix_d A01, ElConstDistMatrix_d A02, ElConstDistMatrix_d A10, ElConstDistMatrix_d A11, ElConstDistMatrix_d A12, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElConstDistMatrix_d A20, ElConstDistMatrix_d A21, ElConstDistMatrix_d A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonalDist_c( ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElConstDistMatrix_c A00, ElConstDistMatrix_c A01, ElConstDistMatrix_c A02, ElConstDistMatrix_c A10, ElConstDistMatrix_c A11, ElConstDistMatrix_c A12, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElConstDistMatrix_c A20, ElConstDistMatrix_c A21, ElConstDistMatrix_c A22 )
.. c:function:: ElError ElSlideLockedPartitionDownDiagonalDist_z( ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElConstDistMatrix_z A00, ElConstDistMatrix_z A01, ElConstDistMatrix_z A02, ElConstDistMatrix_z A10, ElConstDistMatrix_z A11, ElConstDistMatrix_z A12, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElConstDistMatrix_z A20, ElConstDistMatrix_z A21, ElConstDistMatrix_z A22 )
