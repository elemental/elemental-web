Leftward
--------
Given the partition

.. math::

   A = \left(\begin{array}{c|c} A_L & A_R \end{array}\right),

and a blocksize, :math:`n_b`, turn the two-way partition into the three-way 
partition

.. math::

   \left(\begin{array}{c|c} A_L & A_R \end{array}\right) = 
   \left(\begin{array}{cc|c} A_0 & A_1 & A_2 \end{array}\right),

where :math:`A_1` is of width :math:`n_b` and :math:`A_2=A_R`.

C++ API
^^^^^^^

.. cpp:function:: void RepartitionLeft( Matrix<T>& AL, Matrix<T>& AR, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionLeft( const Matrix<T>& AL, const Matrix<T>& AR, Matrix<T>& A0, Matrix<T>& A1, Matrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void RepartitionLeft( AbstractDistMatrix<T>& AL, AbstractDistMatrix<T>& AR, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )
.. cpp:function:: void LockedRepartitionLeft( const AbstractDistMatrix<T>& AL, const AbstractDistMatrix<T>& AR, AbstractDistMatrix<T>& A0, AbstractDistMatrix<T>& A1, AbstractDistMatrix<T>& A2, Int bsize=Blocksize() )

Each of the above routines is meant to be used in a manner similar to:

.. code-block:: cpp

   RepartitionLeft( AL,     /**/ AR,
                    A0, A1, /**/ A2, blocksize );

C API
^^^^^

.. c:function:: ElError ElRepartitionLeft_i( ElMatrix_i AL, ElMatrix_i AR, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeft_s( ElMatrix_s AL, ElMatrix_s AR, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeft_d( ElMatrix_d AL, ElMatrix_d AR, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeft_c( ElMatrix_c AL, ElMatrix_c AR, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeft_z( ElMatrix_z AL, ElMatrix_z AR, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeftDist_i( ElDistMatrix_i AL, ElDistMatrix_i AR, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeftDist_s( ElDistMatrix_s AL, ElDistMatrix_s AR, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeftDist_d( ElDistMatrix_d AL, ElDistMatrix_d AR, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeftDist_c( ElDistMatrix_c AL, ElDistMatrix_c AR, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElRepartitionLeftDist_z( ElDistMatrix_z AL, ElDistMatrix_z AR, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z A2, ElInt bsize )

.. c:function:: ElError ElLockedRepartitionLeft_i( ElConstMatrix_i AL, ElConstMatrix_i AR, ElMatrix_i A0, ElMatrix_i A1, ElMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeft_s( ElConstMatrix_s AL, ElConstMatrix_s AR, ElMatrix_s A0, ElMatrix_s A1, ElMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeft_d( ElConstMatrix_d AL, ElConstMatrix_d AR, ElMatrix_d A0, ElMatrix_d A1, ElMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeft_c( ElConstMatrix_c AL, ElConstMatrix_c AR, ElMatrix_c A0, ElMatrix_c A1, ElMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeft_z( ElConstMatrix_z AL, ElConstMatrix_z AR, ElMatrix_z A0, ElMatrix_z A1, ElMatrix_z A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeftDist_i( ElConstDistMatrix_i AL, ElConstDistMatrix_i AR, ElDistMatrix_i A0, ElDistMatrix_i A1, ElDistMatrix_i A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeftDist_s( ElConstDistMatrix_s AL, ElConstDistMatrix_s AR, ElDistMatrix_s A0, ElDistMatrix_s A1, ElDistMatrix_s A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeftDist_d( ElConstDistMatrix_d AL, ElConstDistMatrix_d AR, ElDistMatrix_d A0, ElDistMatrix_d A1, ElDistMatrix_d A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeftDist_c( ElConstDistMatrix_c AL, ElConstDistMatrix_c AR, ElDistMatrix_c A0, ElDistMatrix_c A1, ElDistMatrix_c A2, ElInt bsize )
.. c:function:: ElError ElLockedRepartitionLeftDist_z( ElConstDistMatrix_z AL, ElConstDistMatrix_z AR, ElDistMatrix_z A0, ElDistMatrix_z A1, ElDistMatrix_z A2, ElInt bsize )

