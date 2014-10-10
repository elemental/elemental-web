Up a diagonal
-------------
Given the partition

.. math::

   A = \left(\begin{array}{c|c} A_{TL} & A_{TR} \\ \hline A_{BL} & A_{BR}
             \end{array}\right),

turn the two-by-two partition into the three-by-three partition

.. math::

   \left(\begin{array}{c|c} A_{TL} & A_{TR} \\ 
                            \hline
                            A_{BL} & A_{BR} \end{array}\right) = 
   \left(\begin{array}{cc|c} A_{00} & A_{01} & A_{02} \\ 
                             A_{10} & A_{11} & A_{12} \\
                             \hline
                             A_{20} & A_{21} & A_{22} \end{array}\right),

where :math:`A_{11}` is :math:`n_b \times n_b` and the corresponding quadrants are equivalent.

C++ API
^^^^^^^

.. cpp:function:: void RepartitionUpDiagonal( Matrix<T>& ATL, Matrix<T>& ATR, Matrix<T>& A00, Matrix<T>& A01, Matrix<T>& A02, Matrix<T>& A10, Matrix<T>& A11, Matrix<T>& A12, Matrix<T>& ABL, Matrix<T>& ABR, Matrix<T>& A20, Matrix<T>& A21, Matrix<T>& A22, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionUpDiagonal( const Matrix<T>& ATL, const Matrix<T>& ATR, Matrix<T>& A00, Matrix<T>& A01, Matrix<T>& A02, Matrix<T>& A10, Matrix<T>& A11, Matrix<T>& A12, const Matrix<T>& ABL, const Matrix<T>& ABR, Matrix<T>& A20, Matrix<T>& A21, Matrix<T>& A22, Int bsize=Blocksize() )
.. cpp:function:: void RepartitionUpDiagonal( AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& A00, AbstractDistMatrix<T>& A01, AbstractDistMatrix<T>& A02, AbstractDistMatrix<T>& A10, AbstractDistMatrix<T>& A11, AbstractDistMatrix<T>& A12, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, AbstractDistMatrix<T>& A20, AbstractDistMatrix<T>& A21, AbstractDistMatrix<T>& A22, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionUpDiagonal( const AbstractDistMatrix<T>& ATL, const AbstractDistMatrix<T>& ATR, AbstractDistMatrix<T>& A00, AbstractDistMatrix<T>& A01, AbstractDistMatrix<T>& A02, AbstractDistMatrix<T>& A10, AbstractDistMatrix<T>& A11, AbstractDistMatrix<T>& A12, const AbstractDistMatrix<T>& ABL, const AbstractDistMatrix<T>& ABR, AbstractDistMatrix<T>& A20, AbstractDistMatrix<T>& A21, AbstractDistMatrix<T>& A22, Int bsize=Blocksize() )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   RepartitionUpDiagonal( ATL, /**/ ATR,  A00, A01, /**/ A02,
                               /**/       A10, A11, /**/ A12,
                         /*************/ /******************/
                          ABL, /**/ ABR,  A20, A21, /**/ A22, blocksize );

C API
^^^^^

.. c:function:: ElError ElRepartitionUpDiagonal_i( ElMatrix_i ATL, ElMatrix_i ATR, ElMatrix_i A00, ElMatrix_i A01, ElMatrix_i A02, ElMatrix_i A10, ElMatrix_i A11, ElMatrix_i A12, ElMatrix_i ABL, ElMatrix_i ABR, ElMatrix_i A20, ElMatrix_i A21, ElMatrix_i A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonal_s( ElMatrix_s ATL, ElMatrix_s ATR, ElMatrix_s A00, ElMatrix_s A01, ElMatrix_s A02, ElMatrix_s A10, ElMatrix_s A11, ElMatrix_s A12, ElMatrix_s ABL, ElMatrix_s ABR, ElMatrix_s A20, ElMatrix_s A21, ElMatrix_s A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonal_d( ElMatrix_d ATL, ElMatrix_d ATR, ElMatrix_d A00, ElMatrix_d A01, ElMatrix_d A02, ElMatrix_d A10, ElMatrix_d A11, ElMatrix_d A12, ElMatrix_d ABL, ElMatrix_d ABR, ElMatrix_d A20, ElMatrix_d A21, ElMatrix_d A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonal_c( ElMatrix_c ATL, ElMatrix_c ATR, ElMatrix_c A00, ElMatrix_c A01, ElMatrix_c A02, ElMatrix_c A10, ElMatrix_c A11, ElMatrix_c A12, ElMatrix_c ABL, ElMatrix_c ABR, ElMatrix_c A20, ElMatrix_c A21, ElMatrix_c A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonal_z( ElMatrix_z ATL, ElMatrix_z ATR, ElMatrix_z A00, ElMatrix_z A01, ElMatrix_z A02, ElMatrix_z A10, ElMatrix_z A11, ElMatrix_z A12, ElMatrix_z ABL, ElMatrix_z ABR, ElMatrix_z A20, ElMatrix_z A21, ElMatrix_z A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonalDist_i( ElDistMatrix_i ATL, ElDistMatrix_i ATR, ElDistMatrix_i A00, ElDistMatrix_i A01, ElDistMatrix_i A02, ElDistMatrix_i A10, ElDistMatrix_i A11, ElDistMatrix_i A12, ElDistMatrix_i ABL, ElDistMatrix_i ABR, ElDistMatrix_i A20, ElDistMatrix_i A21, ElDistMatrix_i A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonalDist_s( ElDistMatrix_s ATL, ElDistMatrix_s ATR, ElDistMatrix_s A00, ElDistMatrix_s A01, ElDistMatrix_s A02, ElDistMatrix_s A10, ElDistMatrix_s A11, ElDistMatrix_s A12, ElDistMatrix_s ABL, ElDistMatrix_s ABR, ElDistMatrix_s A20, ElDistMatrix_s A21, ElDistMatrix_s A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonalDist_d( ElDistMatrix_d ATL, ElDistMatrix_d ATR, ElDistMatrix_d A00, ElDistMatrix_d A01, ElDistMatrix_d A02, ElDistMatrix_d A10, ElDistMatrix_d A11, ElDistMatrix_d A12, ElDistMatrix_d ABL, ElDistMatrix_d ABR, ElDistMatrix_d A20, ElDistMatrix_d A21, ElDistMatrix_d A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonalDist_c( ElDistMatrix_c ATL, ElDistMatrix_c ATR, ElDistMatrix_c A00, ElDistMatrix_c A01, ElDistMatrix_c A02, ElDistMatrix_c A10, ElDistMatrix_c A11, ElDistMatrix_c A12, ElDistMatrix_c ABL, ElDistMatrix_c ABR, ElDistMatrix_c A20, ElDistMatrix_c A21, ElDistMatrix_c A22, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDiagonalDist_z( ElDistMatrix_z ATL, ElDistMatrix_z ATR, ElDistMatrix_z A00, ElDistMatrix_z A01, ElDistMatrix_z A02, ElDistMatrix_z A10, ElDistMatrix_z A11, ElDistMatrix_z A12, ElDistMatrix_z ABL, ElDistMatrix_z ABR, ElDistMatrix_z A20, ElDistMatrix_z A21, ElDistMatrix_z A22, ElInt bsize )

.. c:function:: ElError ElLockedRepartitionUpDiagonal_i( ElConstMatrix_i ATL, ElConstMatrix_i ATR, ElMatrix_i A00, ElMatrix_i A01, ElMatrix_i A02, ElMatrix_i A10, ElMatrix_i A11, ElMatrix_i A12, ElConstMatrix_i ABL, ElConstMatrix_i ABR, ElMatrix_i A20, ElMatrix_i A21, ElMatrix_i A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonal_s( ElConstMatrix_s ATL, ElConstMatrix_s ATR, ElMatrix_s A00, ElMatrix_s A01, ElMatrix_s A02, ElMatrix_s A10, ElMatrix_s A11, ElMatrix_s A12, ElConstMatrix_s ABL, ElConstMatrix_s ABR, ElMatrix_s A20, ElMatrix_s A21, ElMatrix_s A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonal_d( ElConstMatrix_d ATL, ElConstMatrix_d ATR, ElMatrix_d A00, ElMatrix_d A01, ElMatrix_d A02, ElMatrix_d A10, ElMatrix_d A11, ElMatrix_d A12, ElConstMatrix_d ABL, ElConstMatrix_d ABR, ElMatrix_d A20, ElMatrix_d A21, ElMatrix_d A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonal_c( ElConstMatrix_c ATL, ElConstMatrix_c ATR, ElMatrix_c A00, ElMatrix_c A01, ElMatrix_c A02, ElMatrix_c A10, ElMatrix_c A11, ElMatrix_c A12, ElConstMatrix_c ABL, ElConstMatrix_c ABR, ElMatrix_c A20, ElMatrix_c A21, ElMatrix_c A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonal_z( ElConstMatrix_z ATL, ElConstMatrix_z ATR, ElMatrix_z A00, ElMatrix_z A01, ElMatrix_z A02, ElMatrix_z A10, ElMatrix_z A11, ElMatrix_z A12, ElConstMatrix_z ABL, ElConstMatrix_z ABR, ElMatrix_z A20, ElMatrix_z A21, ElMatrix_z A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonalDist_i( ElConstDistMatrix_i ATL, ElConstDistMatrix_i ATR, ElDistMatrix_i A00, ElDistMatrix_i A01, ElDistMatrix_i A02, ElDistMatrix_i A10, ElDistMatrix_i A11, ElDistMatrix_i A12, ElConstDistMatrix_i ABL, ElConstDistMatrix_i ABR, ElDistMatrix_i A20, ElDistMatrix_i A21, ElDistMatrix_i A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonalDist_s( ElConstDistMatrix_s ATL, ElConstDistMatrix_s ATR, ElDistMatrix_s A00, ElDistMatrix_s A01, ElDistMatrix_s A02, ElDistMatrix_s A10, ElDistMatrix_s A11, ElDistMatrix_s A12, ElConstDistMatrix_s ABL, ElConstDistMatrix_s ABR, ElDistMatrix_s A20, ElDistMatrix_s A21, ElDistMatrix_s A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonalDist_d( ElConstDistMatrix_d ATL, ElConstDistMatrix_d ATR, ElDistMatrix_d A00, ElDistMatrix_d A01, ElDistMatrix_d A02, ElDistMatrix_d A10, ElDistMatrix_d A11, ElDistMatrix_d A12, ElConstDistMatrix_d ABL, ElConstDistMatrix_d ABR, ElDistMatrix_d A20, ElDistMatrix_d A21, ElDistMatrix_d A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonalDist_c( ElConstDistMatrix_c ATL, ElConstDistMatrix_c ATR, ElDistMatrix_c A00, ElDistMatrix_c A01, ElDistMatrix_c A02, ElDistMatrix_c A10, ElDistMatrix_c A11, ElDistMatrix_c A12, ElConstDistMatrix_c ABL, ElConstDistMatrix_c ABR, ElDistMatrix_c A20, ElDistMatrix_c A21, ElDistMatrix_c A22, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDiagonalDist_z( ElConstDistMatrix_z ATL, ElConstDistMatrix_z ATR, ElDistMatrix_z A00, ElDistMatrix_z A01, ElDistMatrix_z A02, ElDistMatrix_z A10, ElDistMatrix_z A11, ElDistMatrix_z A12, ElConstDistMatrix_z ABL, ElConstDistMatrix_z ABR, ElDistMatrix_z A20, ElDistMatrix_z A21, ElDistMatrix_z A22, ElInt bsize )

