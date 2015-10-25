Druinsky-Toledo
===============
A *Druinsky-Toledo* matrix of order :math:`k` is of the form

.. math::

   A_k = \begin{pmatrix} G_k & I_k \\ I_k & I_k \end{pmatrix},

where

.. math::

   G_k = \begin{pmatrix} \text{diag}(d_0,d_1,\cdots,d_{n-3}) & \text{ones}(k-2,2) \\ \text{ones}(2,k-2) & \text{ones}(2,2) \end{pmatrix}

Such a matrix is well-conditioned and achieves near the worst-case bound for
element-growth with the "A" pivoting rule for Bunch-Kaufman factorizations

**TODO: Longer description with a reference**

C++ API
-------

.. cpp:function:: void DruinskyToledo( Matrix<F>& A, Int k )
.. cpp:function:: void DruinskyToledo( ElementalMatrix<F>& A, Int k )

C API
-----

.. c:function:: ElError ElDruinskyToledo_s( ElMatrix_s A, ElInt k )
.. c:function:: ElError ElDruinskyToledo_d( ElMatrix_d A, ElInt k )
.. c:function:: ElError ElDruinskyToledo_c( ElMatrix_c A, ElInt k )
.. c:function:: ElError ElDruinskyToledo_z( ElMatrix_z A, ElInt k )

.. c:function:: ElError ElDruinskyToledoDist_s( ElDistMatrix_s A, ElInt k )
.. c:function:: ElError ElDruinskyToledoDist_d( ElDistMatrix_d A, ElInt k )
.. c:function:: ElError ElDruinskyToledoDist_c( ElDistMatrix_c A, ElInt k )
.. c:function:: ElError ElDruinskyToledoDist_z( ElDistMatrix_z A, ElInt k )

Python API
----------

.. py:function:: DruinskyToledo(A,k)
