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
