Walsh
=====
The Walsh matrix of order :math:`k` is a :math:`2^k \times 2^k` matrix, where

.. math::

   W_1 = \left(\begin{array}{cc} 1 & 1 \\ 1 & -1 \end{array}\right),

and

.. math::

   W_k = \left(\begin{array}{cc} W_{k-1} & W_{k-1} \\ W_{k-1} & -W_{k-1} 
               \end{array}\right).

A *binary* Walsh matrix changes the bottom-right entry of :math:`W_1` from
:math:`-1` to :math:`0`.

C++ API
-------

.. cpp:function:: void Walsh( Matrix<T>& W, Int k, bool binary=false )
.. cpp:function:: void Walsh( AbstractDistMatrix<T>& W, Int k, bool binary=false )

C API
-----

.. c:function:: ElError ElWalsh_i( ElMatrix_i W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_s( ElMatrix_s W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_d( ElMatrix_d W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_c( ElMatrix_c W, ElInt k, bool binary )
.. c:function:: ElError ElWalsh_z( ElMatrix_z W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_i( ElDistMatrix_i W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_s( ElDistMatrix_s W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_d( ElDistMatrix_d W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_c( ElDistMatrix_c W, ElInt k, bool binary )
.. c:function:: ElError ElWalshDist_z( ElDistMatrix_z W, ElInt k, bool binary )
