Moving partition boundaries
===========================

Upward
------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{c} A_0 \\ A_1 \\ \hline A_2 \end{array}\right),

into

.. math::

   \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right) = 
   \left(\begin{array}{c} A_0 \\ \hline A_1 \\ A_2 \end{array}\right).

.. cpp:function:: void SlidePartitionUp( Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& AB, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionUp( Matrix<T>& AT, const Matrix<T>& A0, const Matrix<T>& A1, Matrix<T>& AB, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionUp( AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionUp( DistMatrix<T,U,V>& AT, const DistMatrix<T,U,V>& A0, const DistMatrix<T,U,V>& A1, DistMatrix<T,U,V>& AB, const DistMatrix<T,U,V>& A2 )

Note that each of the above routines is meant to be used in a manner similar 
to the following:

.. code-block:: cpp

   SlidePartitionUp( AT,  A0,
                    /**/ /**/
                          A1,
                     AB,  A2 );

Downward
--------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{c} A_0 \\ \hline A_1 \\ A_2 \end{array}\right),

into

.. math::

   \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right) = 
   \left(\begin{array}{c} A_0 \\ A_1 \\ \hline A_2 \end{array}\right).

.. cpp:function:: void SlidePartitionDown( Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& AB, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionDown( Matrix<T>& AT, const Matrix<T>& A0, const Matrix<T>& A1, Matrix<T>& AB, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionDown( AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionDown( AbstractDistMatrix<T>& AT, const AbstractDistMatrix<T>& A0, const AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, const AbstractDistMatrix<T>& A2 )

Note that each of the above routines is meant to be used in a manner similar 
to the following:

.. code-block:: cpp

   SlidePartitionDown( AT,  A0,
                            A1,
                      /**/ /**/
                       AB,  A2 );

SlidePartitionLeft
------------------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{cc|c} A_0 & A_1 & A_2 \end{array}\right)

into

.. math::

   \left(\begin{array}{c|c} A_L & A_R \end{array}\right) = 
   \left(\begin{array}{c|cc} A_0 & A_1 & A_2 \end{array}\right).

.. cpp:function:: void SlidePartitionLeft( Matrix<T>& AL, Matrix<T>& AR, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionLeft( Matrix<T>& AL, Matrix<T>& AR, const Matrix<T>& A0, const Matrix<T>& A1, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionLeft( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionLeft( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, const AbstractDistMatrix<T>& A0, const AbstractDistMatrix<T>& A1, const AbstractDistMatrix<T>& A2 )

Note that each of the above routines is meant to be used in a manner similar 
to the following:

.. code-block:: cpp

   SlidePartitionLeft( AL, /**/ AR,
                       A0, /**/ A1, A2 );

Rightward
---------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{c|cc} A_0 & A_1 & A_2 \end{array}\right)

into

.. math::

   \left(\begin{array}{c|c} A_L & A_R \end{array}\right) = 
   \left(\begin{array}{cc|c} A_0 & A_1 & A_2 \end{array}\right).

.. cpp:function:: void SlidePartitionRight( Matrix<T>& AL, Matrix<T>& AR, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionRight( Matrix<T>& AL, Matrix<T>& AR, const Matrix<T>& A0, const Matrix<T>& A1, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionRight( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionRight( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, const AbstractDistMatrix<T>& A0, const AbstractDistMatrix<T>& A1, const AbstractDistMatrix<T>& A2 )

Note that each of the above routines is meant to be used in a manner similar 
to the following:

.. code-block:: cpp

   SlidePartitionRight( AL,     /**/ AR,
                        A0, A1, /**/ A2 );

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
