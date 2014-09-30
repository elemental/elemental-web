Downward
--------
Given an :math:`m \times n` matrix `A`, configure `AT` and `AB` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{c}A_T \\ A_B \end{array}\right),

where :math:`A_T` is of a specified height.

C++ API
^^^^^^^

.. cpp:function:: void PartitionDown( Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void LockedPartitionDown( const Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void PartitionDown( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAT=Blocksize() )
.. cpp:function:: void LockedPartitionDown( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAT=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionDown_i( ElMatrix_i A, ElMatrix_i AT, ElMatrix_i AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDown_s( ElMatrix_s A, ElMatrix_s AT, ElMatrix_s AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDown_d( ElMatrix_d A, ElMatrix_d AT, ElMatrix_d AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDown_c( ElMatrix_c A, ElMatrix_c AT, ElMatrix_c AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDown_z( ElMatrix_z A, ElMatrix_z AT, ElMatrix_z AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDownDist_i( ElDistMatrix_i A, ElDistMatrix_i AT, ElDistMatrix_i AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDownDist_s( ElDistMatrix_s A, ElDistMatrix_s AT, ElDistMatrix_s AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDownDist_d( ElDistMatrix_d A, ElDistMatrix_d AT, ElDistMatrix_d AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDownDist_c( ElDistMatrix_c A, ElDistMatrix_c AT, ElDistMatrix_c AB, ElInt heightAT )
.. c:function:: ElError ElPartitionDownDist_z( ElDistMatrix_z A, ElDistMatrix_z AT, ElDistMatrix_z AB, ElInt heightAT )

.. c:function:: ElError ElLockedPartitionDown_i( ElConstMatrix_i A, ElMatrix_i AT, ElMatrix_i AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDown_s( ElConstMatrix_s A, ElMatrix_s AT, ElMatrix_s AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDown_d( ElConstMatrix_d A, ElMatrix_d AT, ElMatrix_d AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDown_c( ElConstMatrix_c A, ElMatrix_c AT, ElMatrix_c AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDown_z( ElConstMatrix_z A, ElMatrix_z AT, ElMatrix_z AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDownDist_i( ElConstDistMatrix_i A, ElDistMatrix_i AT, ElDistMatrix_i AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDownDist_s( ElConstDistMatrix_s A, ElDistMatrix_s AT, ElDistMatrix_s AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDownDist_d( ElConstDistMatrix_d A, ElDistMatrix_d AT, ElDistMatrix_d AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDownDist_c( ElConstDistMatrix_c A, ElDistMatrix_c AT, ElDistMatrix_c AB, ElInt heightAT )
.. c:function:: ElError ElLockedPartitionDownDist_z( ElConstDistMatrix_z A, ElDistMatrix_z AT, ElDistMatrix_z AB, ElInt heightAT )
