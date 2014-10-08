GCDMatrix
=========
A *GCD matrix* fills each entry :math:`(i,j)` (counting from zero) of an 
:math:`m \times n` matrix with the greatest common denominator of :math:`i+1` 
and :math:`j+1`, i.e.,

.. math::

   A(i,j) = \text{gcd}(i+1,j+1).

C++ API
-------

.. cpp:function:: void GCDMatrix( Matrix<T>& G, Int m, Int n )
.. cpp:function:: void GCDMatrix( AbstractDistMatrix<T>& G, Int m, Int n )

C API
-----

.. c:function:: ElError ElGCDMatrix_i( ElMatrix_i G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_s( ElMatrix_s G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_d( ElMatrix_d G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_c( ElMatrix_c G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrix_z( ElMatrix_z G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_i( ElDistMatrix_i G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_s( ElDistMatrix_s G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_d( ElDistMatrix_d G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_c( ElDistMatrix_c G, ElInt m, ElInt n )
.. c:function:: ElError ElGCDMatrixDist_z( ElDistMatrix_z G, ElInt m, ElInt n )

Python API
----------

.. py:function:: GCDMatrix(G,m,n)
