Wilkinson
=========
A *Wilkinson matrix* of order :math:`k` is a tridiagonal matrix with diagonal

.. math::

   [k,k-1,k-2,...,1,0,1,...,k-2,k-1,k],

and sub- and super-diagonals of all ones.

C++ API
-------

.. cpp:function:: void Wilkinson( Matrix<T>& W, Int k )
.. cpp:function:: void Wilkinson( AbstractDistMatrix<T>& W, Int k )


C API
-----

.. c:function:: ElError ElWilkinson_i( ElMatrix_i W, ElInt k )
.. c:function:: ElError ElWilkinson_s( ElMatrix_s W, ElInt k )
.. c:function:: ElError ElWilkinson_d( ElMatrix_d W, ElInt k )
.. c:function:: ElError ElWilkinson_c( ElMatrix_c W, ElInt k )
.. c:function:: ElError ElWilkinson_z( ElMatrix_z W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_i( ElDistMatrix_i W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_s( ElDistMatrix_s W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_d( ElDistMatrix_d W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_c( ElDistMatrix_c W, ElInt k )
.. c:function:: ElError ElWilkinsonDist_z( ElDistMatrix_z W, ElInt k )

Python API
----------

.. py:function:: Wilkinson(W,k)
