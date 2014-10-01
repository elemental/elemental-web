Downward
--------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{c} A_0 \\ \hline A_1 \\ A_2 \end{array}\right),

into

.. math::

   \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right) = 
   \left(\begin{array}{c} A_0 \\ A_1 \\ \hline A_2 \end{array}\right).

C++ API
^^^^^^^

.. cpp:function:: void SlidePartitionDown( Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& AB, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionDown( Matrix<T>& AT, const Matrix<T>& A0, const Matrix<T>& A1, Matrix<T>& AB, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionDown( AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionDown( AbstractDistMatrix<T>& AT, const AbstractDistMatrix<T>& A0, const AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, const AbstractDistMatrix<T>& A2 )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   SlidePartitionDown( AT,  A0,
                            A1,
                      /**/ /**/
                       AB,  A2 );

C API
^^^^^

.. c:function:: ElError ElSlidePartitionDown_i( ElMatrix_i AT, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i AB, ElMatrix_i A2 )
.. c:function:: ElError ElSlidePartitionDown_s( ElMatrix_s AT, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s AB, ElMatrix_s A2 )
.. c:function:: ElError ElSlidePartitionDown_d( ElMatrix_d AT, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d AB, ElMatrix_d A2 )
.. c:function:: ElError ElSlidePartitionDown_c( ElMatrix_c AT, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c AB, ElMatrix_c A2 )
.. c:function:: ElError ElSlidePartitionDown_z( ElMatrix_z AT, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z AB, ElMatrix_z A2 )
.. c:function:: ElError ElSlidePartitionDownDist_i( ElDistMatrix_i AT, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i AB, ElDistMatrix_i A2 )
.. c:function:: ElError ElSlidePartitionDownDist_s( ElDistMatrix_s AT, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s AB, ElDistMatrix_s A2 )
.. c:function:: ElError ElSlidePartitionDownDist_d( ElDistMatrix_d AT, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d AB, ElDistMatrix_d A2 )
.. c:function:: ElError ElSlidePartitionDownDist_c( ElDistMatrix_c AT, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c AB, ElDistMatrix_c A2 )
.. c:function:: ElError ElSlidePartitionDownDist_z( ElDistMatrix_z AT, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z AB, ElDistMatrix_z A2 )

.. c:function:: ElError ElSlideLockedPartitionDown_i( ElMatrix_i AT, ElConstMatrix_i A0, ElConstMatrix_i A1, ElMatrix_i AB, ElConstMatrix_i A2 )
.. c:function:: ElError ElSlideLockedPartitionDown_s( ElMatrix_s AT, ElConstMatrix_s A0, ElConstMatrix_s A1, ElMatrix_s AB, ElConstMatrix_s A2 )
.. c:function:: ElError ElSlidePartitionDown_d( ElMatrix_d AT, ElConstMatrix_d A0, ElConstMatrix_d A1, ElMatrix_d AB, ElConstMatrix_d A2 )
.. c:function:: ElError ElSlideLockedPartitionDown_c( ElMatrix_c AT, ElConstMatrix_c A0, ElConstMatrix_c A1, ElMatrix_c AB, ElConstMatrix_c A2 )
.. c:function:: ElError ElSlideLockedPartitionDown_z( ElMatrix_z AT, ElConstMatrix_z A0, ElConstMatrix_z A1, ElMatrix_z AB, ElConstMatrix_z A2 )
.. c:function:: ElError ElSlideLockedPartitionDownDist_i( ElDistMatrix_i AT, ElConstDistMatrix_i A0, ElConstDistMatrix_i A1, ElDistMatrix_i AB, ElConstDistMatrix_i A2 )
.. c:function:: ElError ElSlideLockedPartitionDownDist_s( ElDistMatrix_s AT, ElConstDistMatrix_s A0, ElConstDistMatrix_s A1, ElDistMatrix_s AB, ElConstDistMatrix_s A2 )
.. c:function:: ElError ElSlideLockedPartitionDownDist_d( ElDistMatrix_d AT, ElConstDistMatrix_d A0, ElConstDistMatrix_d A1, ElDistMatrix_d AB, ElConstDistMatrix_d A2 )
.. c:function:: ElError ElSlideLockedPartitionDownDist_c( ElDistMatrix_c AT, ElConstDistMatrix_c A0, ElConstDistMatrix_c A1, ElDistMatrix_c AB, ElConstDistMatrix_c A2 )
.. c:function:: ElError ElSlideLockedPartitionDownDist_z( ElDistMatrix_z AT, ElConstDistMatrix_z A0, ElConstDistMatrix_z A1, ElDistMatrix_z AB, ElConstDistMatrix_z A2 )
