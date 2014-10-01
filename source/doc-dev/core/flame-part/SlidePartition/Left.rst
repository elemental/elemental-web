Leftward
--------
Simultaneously slide and merge the partition

.. math::

   A = \left(\begin{array}{cc|c} A_0 & A_1 & A_2 \end{array}\right)

into

.. math::

   \left(\begin{array}{c|c} A_L & A_R \end{array}\right) = 
   \left(\begin{array}{c|cc} A_0 & A_1 & A_2 \end{array}\right).

C++ API
^^^^^^^

.. cpp:function:: void SlidePartitionLeft( Matrix<T>& AL, Matrix<T>& AR, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionLeft( Matrix<T>& AL, Matrix<T>& AR, const Matrix<T>& A0, const Matrix<T>& A1, const Matrix<T>& A2 )
.. cpp:function:: void SlidePartitionLeft( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& A2 )
.. cpp:function:: void SlideLockedPartitionLeft( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, const AbstractDistMatrix<T>& A0, const AbstractDistMatrix<T>& A1, const AbstractDistMatrix<T>& A2 )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   SlidePartitionLeft( AL, /**/ AR,
                       A0, /**/ A1, A2 );

C API
^^^^^

.. c:function:: ElError ElSlidePartitionLeft_i( ElMatrix_i AL, ElMatrix_i AR, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i A2 )
.. c:function:: ElError ElSlidePartitionLeft_s( ElMatrix_s AL, ElMatrix_s AR, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s A2 )
.. c:function:: ElError ElSlidePartitionLeft_d( ElMatrix_d AL, ElMatrix_d AR, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d A2 )
.. c:function:: ElError ElSlidePartitionLeft_c( ElMatrix_c AL, ElMatrix_c AR, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c A2 )
.. c:function:: ElError ElSlidePartitionLeft_z( ElMatrix_z AL, ElMatrix_z AR, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z A2 )
.. c:function:: ElError ElSlidePartitionLeftDist_i( ElDistMatrix_i AL, ElDistMatrix_i AR, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i A2 )
.. c:function:: ElError ElSlidePartitionLeftDist_s( ElDistMatrix_s AL, ElDistMatrix_s AR, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s A2 )
.. c:function:: ElError ElSlidePartitionLeftDist_d( ElDistMatrix_d AL, ElDistMatrix_d AR, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d A2 )
.. c:function:: ElError ElSlidePartitionLeftDist_c( ElDistMatrix_c AL, ElDistMatrix_c AR, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c A2 )
.. c:function:: ElError ElSlidePartitionLeftDist_z( ElDistMatrix_z AL, ElDistMatrix_z AR, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z A2 )

.. c:function:: ElError ElSlideLockedPartitionLeft_i( ElMatrix_i AL, ElMatrix_i AR, ElConstMatrix_i A0, ElConstMatrix_i A1, ElConstMatrix_i A2 )
.. c:function:: ElError ElSlideLockedPartitionLeft_s( ElMatrix_s AL, ElMatrix_s AR, ElConstMatrix_s A0, ElConstMatrix_s A1, ElConstMatrix_s A2 )
.. c:function:: ElError ElSlideLockedPartitionLeft_d( ElMatrix_d AL, ElMatrix_d AR, ElConstMatrix_d A0, ElConstMatrix_d A1, ElConstMatrix_d A2 )
.. c:function:: ElError ElSlideLockedPartitionLeft_c( ElMatrix_c AL, ElMatrix_c AR, ElConstMatrix_c A0, ElConstMatrix_c A1, ElConstMatrix_c A2 )
.. c:function:: ElError ElSlideLockedPartitionLeft_z( ElMatrix_z AL, ElMatrix_z AR, ElConstMatrix_z A0, ElConstMatrix_z A1, ElConstMatrix_z A2 )
.. c:function:: ElError ElSlideLockedPartitionLeftDist_i( ElDistMatrix_i AL, ElDistMatrix_i AR, ElConstDistMatrix_i A0, ElConstDistMatrix_i A1, ElConstDistMatrix_i A2 )
.. c:function:: ElError ElSlideLockedPartitionLeftDist_s( ElDistMatrix_s AL, ElDistMatrix_s AR, ElConstDistMatrix_s A0, ElConstDistMatrix_s A1, ElConstDistMatrix_s A2 )
.. c:function:: ElError ElSlideLockedPartitionLeftDist_d( ElDistMatrix_d AL, ElDistMatrix_d AR, ElConstDistMatrix_d A0, ElConstDistMatrix_d A1, ElConstDistMatrix_d A2 )
.. c:function:: ElError ElSlideLockedPartitionLeftDist_c( ElDistMatrix_c AL, ElDistMatrix_c AR, ElConstDistMatrix_c A0, ElConstDistMatrix_c A1, ElConstDistMatrix_c A2 )
.. c:function:: ElError ElSlideLockedPartitionLeftDist_z( ElDistMatrix_z AL, ElDistMatrix_z AR, ElConstDistMatrix_z A0, ElConstDistMatrix_z A1, ElConstDistMatrix_z A2 )
