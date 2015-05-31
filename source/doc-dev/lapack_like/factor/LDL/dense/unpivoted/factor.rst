Factorization
=============

Python API
----------
Elemental's Python interface to *unpivoted* dense LDL factorizations can be 
called as a special case of the *pivoted* interface, :py:func:`LDL` by 
specifying ``pivType`` to :py:data:`LDL_WITHOUT_PIVOTING`.

C++ API
-------
.. cpp:function:: void LDLT( Matrix<F>& A )
.. cpp:function:: void LDLT( AbstractDistMatrix<F>& A )

.. cpp:function:: void LDLH( Matrix<F>& A )
.. cpp:function:: void LDLH( AbstractDistMatrix<F>& A )

C API
-----
.. c:function:: ElError ElLDLT_s( ElMatrix_s A )
.. c:function:: ElError ElLDLT_d( ElMatrix_d A )
.. c:function:: ElError ElLDLT_c( ElMatrix_c A )
.. c:function:: ElError ElLDLT_z( ElMatrix_z A )

.. c:function:: ElError ElLDLTDist_s( ElDistMatrix_s A )
.. c:function:: ElError ElLDLTDist_d( ElDistMatrix_d A )
.. c:function:: ElError ElLDLTDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLDLTDist_z( ElDistMatrix_z A )

.. c:function:: ElError ElLDLH_c( ElMatrix_c A )
.. c:function:: ElError ElLDLH_z( ElMatrix_z A )

.. c:function:: ElError ElLDLHDist_c( ElDistMatrix_c A )
.. c:function:: ElError ElLDLHDist_z( ElDistMatrix_z A )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/Var3.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C++11 test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`C++11 example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__
