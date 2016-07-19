Inertia after factorization
===========================

Python API
----------
.. py:function:: InertiaAfterLDL(d,dSub)

   :param d: A vector containing the main diagonal of :math:`D`
   :param dSub: A vector containing the subdiagonal of :math:`D`
   :rtype: The resulting :py:class:`InertiaType` instance

C++ API
-------
.. cpp:function:: InertiaType ldl::Inertia( const Matrix<Base<F>>& d, const Matrix<F>& dSub )
.. cpp:function:: InertiaType ldl::Inertia( const AbstractDistMatrix<Base<F>>& d, const AbstractDistMatrix<F>& dSub )

C API
-----
.. c:function:: ElError ElInertiaAfterLDL_s( ElConstMatrix_s d, ElConstMatrix_s dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_d( ElConstMatrix_d d, ElConstMatrix_d dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_c( ElConstMatrix_s d, ElConstMatrix_c dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDL_z( ElConstMatrix_d d, ElConstMatrix_z dSub, ElInertiaType* inertia )

.. c:function:: ElError ElInertiaAfterLDLDist_s( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_d( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_c( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaAfterLDLDist_z( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, ElInertiaType* inertia )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/InertiaAfter.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like
/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__
