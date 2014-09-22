TriW
====
An :math:`n \times n` *TriW matrix* of order :math:`k` is a banded
upper-triangular matrix with its main diagonal set to one and its :math:`k`
super-diagonals each set to some value :math:`\alpha`.
This family of matrices was regularly employed by Wilkinson.

C++ API
-------

.. cpp:function:: void TriW( Matrix<T>& A, Int n, T alpha, Int k )
.. cpp:function:: void TriW( AbstractDistMatrix<T>& A, Int n, T alpha, Int k )

C API
-----

.. c:function:: ElError ElTriW_i( ElMatrix_i A, ElInt n, ElInt alpha, ElInt k )
.. c:function:: ElError ElTriW_s( ElMatrix_s A, ElInt n, float alpha, ElInt k )
.. c:function:: ElError ElTriW_d( ElMatrix_d A, ElInt n, double alpha, ElInt k )
.. c:function:: ElError ElTriW_c( ElMatrix_c A, ElInt n, complex_float alpha, ElInt k )
.. c:function:: ElError ElTriW_z( ElMatrix_z A, ElInt n, complex_double alpha, ElInt k )
.. c:function:: ElError ElTriWDist_i( ElDistMatrix_i A, ElInt n, ElInt alpha, ElInt k )
.. c:function:: ElError ElTriWDist_s( ElDistMatrix_s A, ElInt n, float alpha, ElInt k )
.. c:function:: ElError ElTriWDist_d( ElDistMatrix_d A, ElInt n, double alpha, ElInt k )
.. c:function:: ElError ElTriWDist_c( ElDistMatrix_c A, ElInt n, complex_float alpha, ElInt k )
.. c:function:: ElError ElTriWDist_z( ElDistMatrix_z A, ElInt n, complex_double alpha, ElInt k )
