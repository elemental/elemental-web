Lehmer
======
An :math:`n \times n` *Lehmer matrix* is a symmetric positive-definite matrix
whose upper-triangle is defined via the equation

.. math::

   A(i,j) = \frac{i+1}{j+1},\;\;\; i \le j.

The inverse of the Lehmer matrix is known to be symmetric tridiagonal (with
positive eigenvalues), and the condition number is known to be bounded by the
relationship

.. math::

   n \le \text{cond}(A) \le 4 n^2.

C++ API
-------

.. cpp:function:: void Lehmer( Matrix<F>& L, Int n )
.. cpp:function:: void Lehmer( AbstractDistMatrix<F>& L, Int n )

C API
-----

.. c:function:: ElError ElLehmer_s( ElMatrix_s L, ElInt n )
.. c:function:: ElError ElLehmer_d( ElMatrix_d L, ElInt n )
.. c:function:: ElError ElLehmer_c( ElMatrix_c L, ElInt n )
.. c:function:: ElError ElLehmer_z( ElMatrix_z L, ElInt n )
.. c:function:: ElError ElLehmerDist_s( ElDistMatrix_s L, ElInt n )
.. c:function:: ElError ElLehmerDist_d( ElDistMatrix_d L, ElInt n )
.. c:function:: ElError ElLehmerDist_c( ElDistMatrix_c L, ElInt n )
.. c:function:: ElError ElLehmerDist_z( ElDistMatrix_z L, ElInt n )
