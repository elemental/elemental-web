Bernoulli
=========
A *Bernoulli matrix* with parameter :math:`0 < p < 1` is a matrix which is 
equal to :math:`0` with probability :math:`1-p` and :math:`1` with probability
:math:`p`.

C++ API
-------

.. cpp:function:: void Bernoulli( Matrix<T>& A, Int m, Int n, double p=0.5 )
.. cpp:function:: void Bernoulli( AbstractDistMatrix<T>& A, Int m, Int n, double p=0.5 )
.. cpp:function:: void Bernoulli( AbstractBlockDistMatrix<T>& A, Int m, Int n, double p=0.5 )

C API
-----

.. c:function:: ElError ElBernoulli_i( ElMatrix_i A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulli_s( ElMatrix_s A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulli_d( ElMatrix_d A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulli_c( ElMatrix_c A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulli_z( ElMatrix_z A, ElInt m, ElInt n, double p=0.5 )

.. c:function:: ElError ElBernoulliDist_i( ElDistMatrix_i A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulliDist_s( ElDistMatrix_s A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulliDist_d( ElDistMatrix_d A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulliDist_c( ElDistMatrix_c A, ElInt m, ElInt n, double p=0.5 )
.. c:function:: ElError ElBernoulliDist_z( ElDistMatrix_z A, ElInt m, ElInt n, double p=0.5 )

Python API
----------

.. py:function:: Bernoulli(A,m,n[,p=0.5])
