Non-negative matrix factorizations
==================================
A rank-k *non-negative matrix factorization* of an :math:`m \times n` matrix 
:math:`A` with all non-negative entries is a solution to the problem

.. math::

   \min_{X,Y} \| A - X Y \|_F, \text{ such that } X,Y \ge 0

where :math:`X` is :math:`m \times k` and :math:`Y` is :math:`k \times n`.

The following routines employ alternating non-negative least squares algorithms.

C++ API
-------

.. cpp:function:: void NMF( const Matrix<Real>& A, Matrix<Real>& X, Matrix<Real>& Y )
.. cpp:function:: void NMF( const AbstractDistMatrix<Real>& A, AbstractDistMatrix<Real>& X, AbstractDistMatrix<Real>& Y )

C API
-----

.. c:function:: ElError ElNMF_s( ElConstMatrix_s A, ElMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElNMF_d( ElConstMatrix_d A, ElMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElNMFDist_s( ElConstDistMatrix_s A, ElDistMatrix_s X, ElDistMatrix_s Y )
.. c:function:: ElError ElNMFDist_d( ElConstDistMatrix_d A, ElDistMatrix_d X, ElDistMatrix_d Y )

