Egorov
======
Sets :math:`A` to an :math:`n \times n` matrix with the :math:`(i,j)` entry
equal to

.. math::

   A(i,j) = \exp(i \phi(i,j)).

C++ API
-------

.. cpp:function:: void Egorov( Matrix<Complex<Real> >& A, std::function<Real(Int,Int)> phi, Int n )
.. cpp:function:: void Egorov( AbstractDistMatrix<Complex<Real>>& A, std::function<Real(Int,Int)> phi, Int n )

C API
-----

.. c:function:: ElError ElEgorov_c( ElMatrix_c A, float (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorov_z( ElMatrix_z A, double (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorovDist_c( ElDistMatrix_c A, float (*phase)(ElInt,ElInt), ElInt n )
.. c:function:: ElError ElEgorovDist_z( ElDistMatrix_z A, double (*phase)(ElInt,ElInt), ElInt n )

Python API
----------

.. py:function:: Egorov(A,phase,n)
