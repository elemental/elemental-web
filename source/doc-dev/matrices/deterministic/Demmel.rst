Demmel
======
An :math:`n \times n` *Demmel* matrix is of the form

.. math::

   D(n,\beta) = (\beta J(-\beta^{-1},n))^{-1},

where :math:`J(-\beta^{-1},n)` is the :math:`n \times n` Jordan block with
eigenvalue :math:`-\beta^{-1}`, and the standard value for :math:`\beta` is 
:math:`10^{4/(n-1)}`. More explicitly, :math:`D(n,\beta)` is an 
upper-triangular matrix where the :math:`j`'th super-diagonal is equal to 
:math:`-\beta^j`.

C++ API
-------

.. cpp:function:: void Demmel( Matrix<F>& A, Int n )
.. cpp:function:: void Demmel( AbstractDistMatrix<F>& A, Int n )
.. cpp:function:: void Demmel( AbstractBlockDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElDemmel_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElDemmel_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElDemmel_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElDemmel_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElDemmelDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElDemmelDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElDemmelDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElDemmelDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Demmel(A,n)
