Rightward
---------
Given an :math:`m \times n` matrix `A`, configure `AL` and `AR` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{cc} A_L & A_R \end{array}\right),

where :math:`A_L` is of a specified width.

C++ API
^^^^^^^

.. cpp:function:: void PartitionRight( Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void LockedPartitionRight( const Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void PartitionRight( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAL=Blocksize() )
.. cpp:function:: void LockedPartitionRight( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAL=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionRight_i( ElgMatrix_i A, ElConstMatrix_i AL, ElConstMatrix_i AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRight_s( ElgMatrix_s A, ElConstMatrix_s AL, ElConstMatrix_s AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRight_d( ElgMatrix_d A, ElConstMatrix_d AL, ElConstMatrix_d AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRight_c( ElgMatrix_c A, ElConstMatrix_c AL, ElConstMatrix_c AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRight_z( ElgMatrix_z A, ElConstMatrix_z AL, ElConstMatrix_z AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRightDist_i( ElgDistMatrix_i A, ElConstDistMatrix_i AL, ElConstDistMatrix_i AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRightDist_s( ElgDistMatrix_s A, ElConstDistMatrix_s AL, ElConstDistMatrix_s AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRightDist_d( ElgDistMatrix_d A, ElConstDistMatrix_d AL, ElConstDistMatrix_d AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRightDist_c( ElgDistMatrix_c A, ElConstDistMatrix_c AL, ElConstDistMatrix_c AR, ElInt widthAL )
.. c:function:: ElError ElPartitionRightDist_z( ElgDistMatrix_z A, ElConstDistMatrix_z AL, ElConstDistMatrix_z AR, ElInt widthAL )

.. c:function:: ElError ElLockedPartitionRight_i( ElConstMatrix_i A, ElMatrix_i AL, ElMatrix_i AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRight_s( ElConstMatrix_s A, ElMatrix_s AL, ElMatrix_s AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRight_d( ElConstMatrix_d A, ElMatrix_d AL, ElMatrix_d AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRight_c( ElConstMatrix_c A, ElMatrix_c AL, ElMatrix_c AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRight_z( ElConstMatrix_z A, ElMatrix_z AL, ElMatrix_z AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRightDist_i( ElConstDistMatrix_i A, ElDistMatrix_i AL, ElDistMatrix_i AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRightDist_s( ElConstDistMatrix_s A, ElDistMatrix_s AL, ElDistMatrix_s AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRightDist_d( ElConstDistMatrix_d A, ElDistMatrix_d AL, ElDistMatrix_d AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRightDist_c( ElConstDistMatrix_c A, ElDistMatrix_c AL, ElDistMatrix_c AR, ElInt widthAL )
.. c:function:: ElError ElLockedPartitionRightDist_z( ElConstDistMatrix_z A, ElDistMatrix_z AL, ElDistMatrix_z AR, ElInt widthAL )
