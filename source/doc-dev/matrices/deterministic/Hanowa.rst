Hanowa
======
A :math:`2n \times 2n` matrix is said to be a *Hanowa matrix* if it is
of the form

.. math::

   A = \begin{pmatrix} \mu I_{n \times n} & -D \\ 
                       D                  & \mu I_{n \times n} \end{pmatrix},

where :math:`D = \text{diag}( [1,2,...,n] )` and :math:`I_{n \times n}` is the
:math:`n \times n` identity matrix.

C++ API
-------

.. cpp:function:: void Hanowa( Matrix<T>& A, Int n, T mu )
.. cpp:function:: void Hanowa( AbstractDistMatrix<T>& A, Int n, T mu )

C API
-----

.. c:function:: ElError ElHanowa_i( ElMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElHanowa_s( ElMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElHanowa_d( ElMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElHanowa_c( ElMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElHanowa_z( ElMatrix_z A, ElInt n, complex_double mu )
.. c:function:: ElError ElHanowaDist_i( ElDistMatrix_i A, ElInt n, ElInt mu )
.. c:function:: ElError ElHanowaDist_s( ElDistMatrix_s A, ElInt n, float mu )
.. c:function:: ElError ElHanowaDist_d( ElDistMatrix_d A, ElInt n, double mu )
.. c:function:: ElError ElHanowaDist_c( ElDistMatrix_c A, ElInt n, complex_float mu )
.. c:function:: ElError ElHanowaDist_z( ElDistMatrix_z A, ElInt n, complex_double mu )
