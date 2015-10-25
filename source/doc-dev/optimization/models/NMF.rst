Non-negative matrix factorizations
==================================
A rank-k *non-negative matrix factorization* of an :math:`m \times n` matrix 
:math:`A` with all non-negative entries is a solution to the problem

.. math::

   \min_{X,Y} \| A - X Y \|_F, \text{ such that } X,Y \ge 0

where :math:`X` is :math:`m \times k` and :math:`Y` is :math:`k \times n`.

The following routines employ alternating non-negative least squares algorithms.

.. note:: 

   The following routines are still just prototypes and do not employ proper 
   stopping criteria

Python API
----------

.. py:function:: NMF(A[,ctrl=None])
   
   :param A: dense, sequential or distributed matrix to approximate with NMF
   :param ctrl: (optional) :py:class:`NNLSCtrl_s` or :py:class:`NNLSCtrl_d` control structure, depending upon whether the data is single-precision or double-precision
   :rtype: the two non-negative factors (which will have types compatible with that of ``A``)

C++ API
-------

.. cpp:function:: void NMF( const Matrix<Real>& A, Matrix<Real>& X, Matrix<Real>& Y, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )
.. cpp:function:: void NMF( const ElementalMatrix<Real>& A, ElementalMatrix<Real>& X, ElementalMatrix<Real>& Y, const NNLSCtrl<Real>& ctrl=NNLSCtrl<Real>() )

C API
-----

Standard interface
^^^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElNMF_s( ElConstMatrix_s A, ElMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElNMFDist_s( ElConstDistMatrix_s A, ElDistMatrix_s X, ElDistMatrix_s Y )

Double-precision
""""""""""""""""

.. c:function:: ElError ElNMF_d( ElConstMatrix_d A, ElMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElNMFDist_d( ElConstDistMatrix_d A, ElDistMatrix_d X, ElDistMatrix_d Y )

Expert interface
^^^^^^^^^^^^^^^^

Single-precision
""""""""""""""""

.. c:function:: ElError ElNMFX_s( ElConstMatrix_s A, ElMatrix_s X, ElMatrix_s Y, ElNNLSCtrl_s ctrl )
.. c:function:: ElError ElNMFXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s X, ElDistMatrix_s Y, ElNNLSCtrl_s ctrl )

Double-precision
""""""""""""""""

.. c:function:: ElError ElNMFX_d( ElConstMatrix_d A, ElMatrix_d X, ElMatrix_d Y, ElNNLSCtrl_d ctrl )
.. c:function:: ElError ElNMFXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d X, ElDistMatrix_d Y, ElNNLSCtrl_d ctrl )

