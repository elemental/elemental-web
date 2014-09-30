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
