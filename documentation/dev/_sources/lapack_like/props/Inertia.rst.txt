Inertia
=======
The following routines return a triplet containing the number of positive, 
negative, and zero eigenvalues of a Hermitian matrix by analyzing the 
quasi-diagonal matrix resulting from a pivoted LDLH factorization.

Python API
----------
.. py:class: InertiaType

   .. py:member:: numPositive

   .. py:member:: numNegative

   .. py:member:: numZero

.. py:function:: Inertia(A[,uplo=LOWER[,pivType=BUNCH_KAUFMAN_A]])

   :param A: The (sequential or distributed) dense Hermitian matrix
   :param uplo: (optional) Which triangle of :math:`A` to access
   :param pivType: (optional) The preferred pivoting strategy
   :rtype: The resulting :py:class:`InertiaType` instance

C++ API
-------

.. cpp:class:: InertiaType

   .. cpp:member:: Int numPositive
   .. cpp:member:: Int numNegative
   .. cpp:member:: Int numZero

      The basic eigenvalue structure of a Hermitian matrix (which can be quickly
      computed from the quasi-diagonal matrix produced by Bunch-Kaufman).

.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, Matrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )
.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, AbstractDistMatrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )

C API
-----

.. c:type:: ElInertiaType

   .. c:member:: ElInt numPositive
   .. c:member:: ElInt numNegative
   .. c:member:: ElInt numZero

.. c:function:: ElError ElInertia_s( ElUpperOrLower uplo, ElMatrix_s A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_d( ElUpperOrLower uplo, ElMatrix_d A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_c( ElUpperOrLower uplo, ElMatrix_c A, ElInertiaType* inertia )
.. c:function:: ElError ElInertia_z( ElUpperOrLower uplo, ElMatrix_z A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElInertiaType* inertia )
.. c:function:: ElError ElInertiaDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElInertiaType* inertia )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/props/Inertia.cpp>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/props-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/props.py>`__
