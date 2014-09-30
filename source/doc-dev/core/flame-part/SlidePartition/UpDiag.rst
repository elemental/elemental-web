Up a diagonal
-------------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{cc|c} A_{00} & A_{01} & A_{02} \\
                                 A_{10} & A_{11} & A_{12} \\
                                 \hline
                                 A_{20} & A_{21} & A_{22} \end{array}\right)

into

.. math::

   \left(\begin{array}{c|c} A_{TL} & A_{TR} \\
                            \hline
                            A_{BL} & A_{BR} \end{array}\right) = 
   \left(\begin{array}{c|cc} A_{00} & A_{01} & A_{02} \\
                             \hline
                             A_{10} & A_{11} & A_{12} \\
                             A_{20} & A_{21} & A_{22} \end{array}\right).

.. cpp:function:: void SlidePartitionUpDiagonal( Matrix<T>& ATL, Matrix<T>& ATR, const Matrix<T>& A00, const Matrix<T>& A01, const Matrix<T>& A02, const Matrix<T>& A10, const Matrix<T>& A11, const Matrix<T>& A12, Matrix<T>& ABL, Matrix<T>& ABR, const Matrix<T>& A20, const Matrix<T>& A21, const Matrix<T>& A22 )
.. cpp:function:: void SlideLockedPartitionUpDiagonal( Matrix<T>& ATL, Matrix<T>& ATR, const Matrix<T>& A00, const Matrix<T>& A01, const Matrix<T>& A02, const Matrix<T>& A10, const Matrix<T>& A11, const Matrix<T>& A12, Matrix<T>& ABL, Matrix<T>& ABR, const Matrix<T>& A20, const Matrix<T>& A21, const Matrix<T>& A22 )
.. cpp:function:: void SlidePartitionUpDiagonal( AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, const AbstractDistMatrix<T>& A00, const AbstractDistMatrix<T>& A01, const AbstractDistMatrix<T>& A02, const AbstractDistMatrix<T>& A10, const AbstractDistMatrix<T>& A11, const AbstractDistMatrix<T>& A12, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, const AbstractDistMatrix<T>& A20, const AbstractDistMatrix<T>& A21, const AbstractDistMatrix<T>& A22 )
.. cpp:function:: void SlideLockedPartitionUpDiagonal( AbstractDistMatrix<T>& ATL, AbstractDistMatrix<T>& ATR, const AbstractDistMatrix<T>& A00, const AbstractDistMatrix<T>& A01, const AbstractDistMatrix<T>& A02, const AbstractDistMatrix<T>& A10, const AbstractDistMatrix<T>& A11, const AbstractDistMatrix<T>& A12, AbstractDistMatrix<T>& ABL, AbstractDistMatrix<T>& ABR, const AbstractDistMatrix<T>& A20, const AbstractDistMatrix<T>& A21, const AbstractDistMatrix<T>& A22 )

Note that the above routines are meant to be used as:

.. code-block:: cpp

   SlidePartitionUpDiagonal( ATL, /**/ ATR,  A00, /**/ A01, A02,
                            /*************/ /******************/
                                  /**/       A10, /**/ A11, A12,
                             ABL, /**/ ABR,  A20, /**/ A21, A22 );
