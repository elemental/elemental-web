Lotkin
======
The :math:`n \times n` *Lotkin matrix* is equal to the Hilbert matrix with its
first row replaced with ones. Its inverse is analytically known and contains
integer entries.

C++ API
-------

.. cpp:function:: void Lotkin( Matrix<F>& A, Int n )
.. cpp:function:: void Lotkin( AbstractDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElLotkin_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElLotkin_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElLotkin_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElLotkin_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElLotkinDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElLotkinDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElLotkinDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElLotkinDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Lotkin(A,n)
