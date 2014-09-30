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
