Upward
------
Given the partition

.. math::

   A = \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right),

and a blocksize, :math:`n_b`, turn the two-way partition into the three-way
partition 

.. math::

   \left(\begin{array}{c} A_T \\ \hline A_B \end{array}\right) = 
   \left(\begin{array}{c} A_0 \\ A_1 \\ \hline A_2 \end{array}\right),

where :math:`A_1` is of height :math:`n_b` and :math:`A_2 = A_B`.

C++ API
^^^^^^^

.. cpp:function:: void RepartitionUp( Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& AB, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionUp( const Matrix<T>& AT, Matrix<T>& A0, Matrix<T>& A1, const Matrix<T>& AB, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void RepartitionUp( AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionUp( const AbstractDistMatrix<T>& AT, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, const AbstractDistMatrix<T>& AB, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   RepartitionUp( AT,  A0,
                       A1,
                 /**/ /**/
                  AB,  A2, blocksize );

C API
^^^^^

.. c:function:: ElError ElRepartitionUp_i( ElMatrix_i AT, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i AB, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUp_s( ElMatrix_s AT, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s AB, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUp_d( ElMatrix_d AT, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d AB, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUp_c( ElMatrix_c AT, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c AB, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUp_z( ElMatrix_z AT, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z AB, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDist_i( ElDistMatrix_i AT, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i AB, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDist_s( ElDistMatrix_s AT, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s AB, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDist_d( ElDistMatrix_d AT, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d AB, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDist_c( ElDistMatrix_c AT, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c AB, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionUpDist_z( ElDistMatrix_z AT, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z AB, ElDistMatrix_z A2, ElInt bsize )

.. c:function:: ElError ElLockedRepartitionUp_i( ElConstMatrix_i AT, ElMatrix_i A0, ElMatrix_i A1, ElConstMatrix_i AB, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUp_s( ElConstMatrix_s AT, ElMatrix_s A0, ElMatrix_s A1, ElConstMatrix_s AB, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUp_d( ElConstMatrix_d AT, ElMatrix_d A0, ElMatrix_d A1, ElConstMatrix_d AB, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUp_c( ElConstMatrix_c AT, ElMatrix_c A0, ElMatrix_c A1, ElConstMatrix_c AB, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUp_z( ElConstMatrix_z AT, ElMatrix_z A0, ElMatrix_z A1, ElConstMatrix_z AB, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDist_i( ElConstDistMatrix_i AT, ElDistMatrix_i A0, ElDistMatrix_i A1, ElConstDistMatrix_i AB, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDist_s( ElConstDistMatrix_s AT, ElDistMatrix_s A0, ElDistMatrix_s A1, ElConstDistMatrix_s AB, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDist_d( ElConstDistMatrix_d AT, ElDistMatrix_d A0, ElDistMatrix_d A1, ElConstDistMatrix_d AB, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDist_c( ElConstDistMatrix_c AT, ElDistMatrix_c A0, ElDistMatrix_c A1, ElConstDistMatrix_c AB, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionUpDist_z( ElConstDistMatrix_z AT, ElDistMatrix_z A0, ElDistMatrix_z A1, ElConstDistMatrix_z AB, ElDistMatrix_z A2, ElInt bsize )
