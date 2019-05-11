Three-valued
============
A *three-valued matrix* is a matrix whose entries are independently
sampled from :math:`\{-1,0,1\}`.with probabilities :math:`\{p/2,1-p,p/2\}`.

C++ API
-------

.. cpp:function:: void ThreeValued( Matrix<T>& A, Int m, Int n, double p=2./3. )
.. cpp:function:: void ThreeValued( AbstractDistMatrix<T>& A, Int m, Int n, double p=2./3. )

C API
-----

.. c:function:: ElError ElThreeValued_i( ElMatrix_i A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValued_s( ElMatrix_s A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValued_d( ElMatrix_d A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValued_c( ElMatrix_c A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValued_z( ElMatrix_z A, ElInt m, ElInt n, double p )

.. c:function:: ElError ElThreeValuedDist_i( ElDistMatrix_i A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValuedDist_s( ElDistMatrix_s A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValuedDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValuedDist_c( ElDistMatrix_c A, ElInt m, ElInt n, double p )
.. c:function:: ElError ElThreeValuedDist_z( ElDistMatrix_z A, ElInt m, ElInt n, double p )

Python API
----------

.. py:function:: ThreeValued(A,m,n,p)
