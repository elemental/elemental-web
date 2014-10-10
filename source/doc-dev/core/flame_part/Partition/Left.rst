Leftward
--------
Given an :math:`m \times n` matrix `A`, configure `AL` and `AR` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{cc} A_L & A_R \end{array}\right),

where :math:`A_R` is of a specified width.

C++ API
^^^^^^^

.. cpp:function:: void PartitionLeft( Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void LockedPartitionLeft( const Matrix<T>& A, Matrix<T>& AL, Matrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void PartitionLeft( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAR=Blocksize() )
.. cpp:function:: void LockedPartitionLeft( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, Int widthAR=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionLeft_i( ElMatrix_i A, ElMatrix_i AL, ElMatrix_i AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeft_s( ElMatrix_s A, ElMatrix_s AL, ElMatrix_s AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeft_d( ElMatrix_d A, ElMatrix_d AL, ElMatrix_d AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeft_c( ElMatrix_c A, ElMatrix_c AL, ElMatrix_c AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeft_z( ElMatrix_z A, ElMatrix_z AL, ElMatrix_z AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeftDist_i( ElDistMatrix_i A, ElDistMatrix_i AL, ElDistMatrix_i AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeftDist_s( ElDistMatrix_s A, ElDistMatrix_s AL, ElDistMatrix_s AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeftDist_d( ElDistMatrix_d A, ElDistMatrix_d AL, ElDistMatrix_d AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeftDist_c( ElDistMatrix_c A, ElDistMatrix_c AL, ElDistMatrix_c AR, ElInt widthAR )
.. c:function:: ElError ElPartitionLeftDist_z( ElDistMatrix_z A, ElDistMatrix_z AL, ElDistMatrix_z AR, ElInt widthAR )

.. c:function:: ElError ElLockedPartitionLeft_i( ElConstMatrix_i A, ElMatrix_i AL, ElMatrix_i AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeft_s( ElConstMatrix_s A, ElMatrix_s AL, ElMatrix_s AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeft_d( ElConstMatrix_d A, ElMatrix_d AL, ElMatrix_d AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeft_c( ElConstMatrix_c A, ElMatrix_c AL, ElMatrix_c AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeft_z( ElConstMatrix_z A, ElMatrix_z AL, ElMatrix_z AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeftDist_i( ElConstDistMatrix_i A, ElDistMatrix_i AL, ElDistMatrix_i AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeftDist_s( ElConstDistMatrix_s A, ElDistMatrix_s AL, ElDistMatrix_s AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeftDist_d( ElConstDistMatrix_d A, ElDistMatrix_d AL, ElDistMatrix_d AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeftDist_c( ElConstDistMatrix_c A, ElDistMatrix_c AL, ElDistMatrix_c AR, ElInt widthAR )
.. c:function:: ElError ElLockedPartitionLeftDist_z( ElConstDistMatrix_z A, ElDistMatrix_z AL, ElDistMatrix_z AR, ElInt widthAR )
