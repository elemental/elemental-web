GEPP Growth
===========
:math:`n \times n` extensions of matrices of the form

.. math::

   A = \begin{pmatrix} 1 & 0 & 0 & 1 \\
                      -1 & 1 & 0 & 1 \\
                      -1 &-1 & 1 & 1 \\
                      -1 &-1 &-1 & 1 \end{pmatrix}

were known by Wilkinson to lead to an element-growth factor of 
:math:`2^{n-1}` for Gaussian Elimination with Partial Pivoting (GEPP).

C++ API
-------

.. cpp:function:: void GEPPGrowth( Matrix<F>& A, Int n )
.. cpp:function:: void GEPPGrowth( AbstractDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElGEPPGrowth_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElGEPPGrowth_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElGEPPGrowth_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElGEPPGrowth_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElGEPPGrowthDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElGEPPGrowthDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElGEPPGrowthDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElGEPPGrowthDist_z( ElDistMatrix_z A, ElInt n )
