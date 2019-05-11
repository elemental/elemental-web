Bernoulli
=========
A *Bernoulli matrix* is a matrix whose entries are independent and uniformly
sampled from :math:`\{-1,1\}`. This is a special case of a *three-valued matrix*
with :math:`p=1.`.

C++ API
-------

.. cpp:function:: void Bernoulli( Matrix<T>& A, Int m, Int n )
.. cpp:function:: void Bernoulli( AbstractDistMatrix<T>& A, Int m, Int n )
.. cpp:function:: void Bernoulli( AbstractBlockDistMatrix<T>& A, Int m, Int n )

C API
-----

.. c:function:: ElError ElBernoulli_i( ElMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulli_s( ElMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulli_d( ElMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulli_c( ElMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulli_z( ElMatrix_z A, ElInt m, ElInt n )

.. c:function:: ElError ElBernoulliDist_i( ElDistMatrix_i A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulliDist_s( ElDistMatrix_s A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulliDist_d( ElDistMatrix_d A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulliDist_c( ElDistMatrix_c A, ElInt m, ElInt n )
.. c:function:: ElError ElBernoulliDist_z( ElDistMatrix_z A, ElInt m, ElInt n )

Python API
----------

.. py:function:: Bernoulli(A,m,n)
