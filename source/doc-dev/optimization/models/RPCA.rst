Robust principal component analysis
===================================
*Robust principal component analysis* (RPCA) seeks a decomposition of a matrix
as a sum of a low-rank and sparse matrix, i.e.,

.. math::

   M = L + S,

where a balance is sought between the rank of :math:`L` and the number of 
nonzeros in :math:`S`. Such a balance is (weakly) imposed via convex 
relaxations of penalties on the number of nonzero singular values of :math:`L`
and entries of :math:`S` to their :math:`\ell_1` counterparts. In particular,
a solution is sought for the problem

.. math::

   \min_{L,S} \| L \|_* + \| \text{vec}(S) \|_1 \text{ such that } M = L + S,

where :math:`\| \cdot \|_*` denotes the nuclear norm and 
:math:`\| \text{vec}(\cdot) \|_1` denotes the entrywise one-norm.

Python API
----------

.. py:function:: RPCA(M[,ctrl=None])

C++ API
-------

.. cpp:type:: RPCACtrl

   .. cpp:member:: bool useALM
   .. cpp:member:: bool usePivQR
   .. cpp:member:: bool progress
   .. cpp:member:: Int numPivSteps
   .. cpp:member:: Int maxIts
   .. cpp:member:: Real tau
   .. cpp:member:: Real beta
   .. cpp:member:: Real rho
   .. cpp:member:: Real tol
   .. cpp:member:: RPCACtrl()

.. cpp:function:: void RPCA( const AbstractDistMatrix<F>& M, AbstractDistMatrix<F>& L, AbstractDistMatrix<F>& S, const RPCACtrl<Base<F>>& ctrl=RPCACtrl<Base<F>>() )

C API
-----

.. c:function:: ElError ElRPCADist_s( ElConstDistMatrix_s M, ElDistMatrix_s L, ElDistMatrix_s S )
.. c:function:: ElError ElRPCADist_d( ElConstDistMatrix_d M, ElDistMatrix_d L, ElDistMatrix_d S )
.. c:function:: ElError ElRPCADist_c( ElConstDistMatrix_c M, ElDistMatrix_c L, ElDistMatrix_c S )
.. c:function:: ElError ElRPCADist_z( ElConstDistMatrix_z M, ElDistMatrix_z L, ElDistMatrix_z S )

