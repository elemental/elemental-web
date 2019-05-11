Upward
------
Given an :math:`m \times n` matrix `A`, configure `AT` and `AB` to view the local data of `A` corresponding to the partition

.. math::

   A = \left(\begin{array}{c}A_T \\ A_B \end{array}\right), 

where :math:`A_B` is of a specified height. 

C++ API
^^^^^^^

.. cpp:function:: void PartitionUp( Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void LockedPartitionUp( const Matrix<T>& A, Matrix<T>& AT, Matrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void PartitionUp( AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAB=Blocksize() )
.. cpp:function:: void LockedPartitionUp( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& AB, Int heightAB=Blocksize() )

C API
^^^^^

.. c:function:: ElError ElPartitionUp_i( ElMatrix_i A, ElMatrix_i AT, ElMatrix_i AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUp_s( ElMatrix_s A, ElMatrix_s AT, ElMatrix_s AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUp_d( ElMatrix_d A, ElMatrix_d AT, ElMatrix_d AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUp_c( ElMatrix_c A, ElMatrix_c AT, ElMatrix_c AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUp_z( ElMatrix_z A, ElMatrix_z AT, ElMatrix_z AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUpDist_i( ElDistMatrix_i A, ElDistMatrix_i AT, ElDistMatrix_i AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUpDist_s( ElDistMatrix_s A, ElDistMatrix_s AT, ElDistMatrix_s AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUpDist_d( ElDistMatrix_d A, ElDistMatrix_d AT, ElDistMatrix_d AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUpDist_c( ElDistMatrix_c A, ElDistMatrix_c AT, ElDistMatrix_c AB, ElInt heightAB )
.. c:function:: ElError ElPartitionUpDist_z( ElDistMatrix_z A, ElDistMatrix_z AT, ElDistMatrix_z AB, ElInt heightAB )

.. c:function:: ElError ElLockedPartitionUp_i( ElConstMatrix_i A, ElMatrix_i AT, ElMatrix_i AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUp_s( ElConstMatrix_s A, ElMatrix_s AT, ElMatrix_s AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUp_d( ElConstMatrix_d A, ElMatrix_d AT, ElMatrix_d AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUp_c( ElConstMatrix_c A, ElMatrix_c AT, ElMatrix_c AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUp_z( ElConstMatrix_z A, ElMatrix_z AT, ElMatrix_z AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUpDist_i( ElConstDistMatrix_i A, ElDistMatrix_i AT, ElDistMatrix_i AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUpDist_s( ElConstDistMatrix_s A, ElDistMatrix_s AT, ElDistMatrix_s AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUpDist_d( ElConstDistMatrix_d A, ElDistMatrix_d AT, ElDistMatrix_d AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUpDist_c( ElConstDistMatrix_c A, ElDistMatrix_c AT, ElDistMatrix_c AB, ElInt heightAB )
.. c:function:: ElError ElLockedPartitionUpDist_z( ElConstDistMatrix_z A, ElDistMatrix_z AT, ElDistMatrix_z AB, ElInt heightAB )
