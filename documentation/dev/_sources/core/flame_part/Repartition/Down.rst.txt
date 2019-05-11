Downward
--------
Given the partition

.. math::

   A = \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right),

and a blocksize, :math:`n_b`, turn the two-way partition into the three-way
partition 

.. math::

   \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right) = 
   \left(\begin{array}{c} A_0 \\ \hline A_1 \\ A_2 \end{array}\right),

where :math:`A_1` is of height :math:`n_b` and :math:`A_0 = A_T`.

C++ API
^^^^^^^

.. cpp:function:: void RepartitionDown( Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& AB, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionDown( const Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, const Matrix<T>& AB, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void RepartitionDown( AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionDown( const AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, const AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   RepartitionDown( AT,  A0,
                   /**/ /**/
                         A1,
                    AB,  A2, blocksize );

C API
^^^^^

.. c:function:: ElError ElRepartitionDown_i( ElMatrix_i AT, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i AB, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDown_s( ElMatrix_s AT, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s AB, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDown_d( ElMatrix_d AT, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d AB, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDown_c( ElMatrix_c AT, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c AB, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDown_z( ElMatrix_z AT, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z AB, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDownDist_i( ElDistMatrix_i AT, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i AB, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDownDist_s( ElDistMatrix_s AT, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s AB, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDownDist_d( ElDistMatrix_d AT, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d AB, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDownDist_c( ElDistMatrix_c AT, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c AB, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionDownDist_z( ElDistMatrix_z AT, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z AB, ElDistMatrix_z A2, ElInt bsize )

.. c:function:: ElError ElLockedRepartitionDown_i( ElConstMatrix_i AT, ElMatrix_i A0, ElMatrix_i A1, ElConstMatrix_i AB, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDown_s( ElConstMatrix_s AT, ElMatrix_s A0, ElMatrix_s A1, ElConstMatrix_s AB, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDown_d( ElConstMatrix_d AT, ElMatrix_d A0, ElMatrix_d A1, ElConstMatrix_d AB, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDown_c( ElConstMatrix_c AT, ElMatrix_c A0, ElMatrix_c A1, ElConstMatrix_c AB, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDown_z( ElConstMatrix_z AT, ElMatrix_z A0, ElMatrix_z A1, ElConstMatrix_z AB, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDownDist_i( ElConstDistMatrix_i AT, ElDistMatrix_i A0, ElDistMatrix_i A1, ElConstDistMatrix_i AB, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDownDist_s( ElConstDistMatrix_s AT, ElDistMatrix_s A0, ElDistMatrix_s A1, ElConstDistMatrix_s AB, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDownDist_d( ElConstDistMatrix_d AT, ElDistMatrix_d A0, ElDistMatrix_d A1, ElConstDistMatrix_d AB, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDownDist_c( ElConstDistMatrix_c AT, ElDistMatrix_c A0, ElDistMatrix_c A1, ElConstDistMatrix_c AB, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionDownDist_z( ElConstDistMatrix_z AT, ElDistMatrix_z A0, ElDistMatrix_z A1, ElConstDistMatrix_z AB, ElDistMatrix_z A2, ElInt bsize )
