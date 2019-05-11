Factorization
=============

Python API
----------
.. py:function:: LDL(A[,conjugate=True[,pivType=BUNCH_KAUFMAN_A]])

   :param A: The (sequential or distributed) dense input/output matrix
   :param conjugate: (optional) boolean for whether to perform LDLT or LDLH
   :param pivType: (optional) the preferred pivoting strategy
   :rtype: Nothing is returned if ``pivType`` is :py:data:`LDL_WITHOUT_PIVOTING`, but, otherwise, the subdiagonal of :math:`D`, ``dSub``, and the permutation vector, ``p``, are returned

The following Python pseudo-enum contains the list of allowable pivoting 
approaches for dense LDL factorization:

.. py:data:: BUNCH_KAUFMAN_A

   Hardcoded to the value 0

.. py:data:: BUNCH_KAUFMAN_C

   Not yet supported (and hardcoded to the value 1)

.. py:data:: BUNCH_KAUFMAN_D

   Hardcoded to the value 2

.. py:data:: BUNCH_KAUFMAN_BOUNDED

   Not yet supported (and hardcoded to the value 3)

.. py:data:: BUNCH_PARLETT

   Hardcoded to the value 4

.. py:data:: LDL_WITHOUT_PIVOTING

   Hardcoded to the value 5

C++ API
-------

.. cpp:enum:: LDLPivotType

   For specifying the symmetric pivoting strategy. The current
   (not yet all supported) options include:

   .. cpp:enumerator:: BUNCH_KAUFMAN_A

   .. cpp:enumerator:: BUNCH_KAUFMAN_C

      Not yet supported

   .. cpp:enumerator:: BUNCH_KAUFMAN_D

   .. cpp:enumerator:: BUNCH_KAUFMAN_BOUNDED

      Not yet supported

   .. cpp:enumerator:: BUNCH_PARLETT

   .. cpp:enumerator:: LDL_WITHOUT_PIVOTING

.. cpp:function:: Real LDLPivotConstant<Real>(LDLPivotType pivotType)

   Maps various LDL pivotings schemes to their optimal threshold constant.

.. cpp:class:: LDLPivotCtrl<Real>

   .. cpp:member:: LDLPivotType pivotType

      The type of pivoting to perform (by default, ``BUNCH_KAUFMAN_A``)

   .. cpp:member:: Real gamma

      Pivot tolerance (by default, set to ``LDLPivotConstant<Real>(pivotType)``)

   .. cpp:function:: LDLPivotCtrl(LDLPivotType piv=BUNCH_KAUFMAN_A)

.. cpp:class:: LDLPivot

   .. cpp:member:: Int nb

      Whether the pivot is 1x1 or 2x2.

   .. cpp:member:: Int from[2]

      The source indices of the row or rows to swap with for the 1x1 or 2x2
      pivot.

.. cpp:function:: void LDL( Matrix<F>& A, Matrix<F>& dSub, Matrix<int>& p, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )
.. cpp:function:: void LDL( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& dSub, AbstractDistMatrix<int>& p, bool conjugate=false, const LDLPivotCtrl<Base<F>>& ctrl=LDLPivotCtrl<Base<F>>() )

C API
-----

.. c:type:: ElLDLPivotType

   An enum for specifying the symmetric pivoting strategy. The current
   (not yet all supported) options include:

   * ``EL_BUNCH_KAUFMAN_A`` 
   * ``EL_BUNCH_KAUFMAN_C`` (not yet supported)
   * ``EL_BUNCH_KAUFMAN_D``
   * ``EL_BUNCH_KAUFMAN_BOUNDED`` (not yet supported)
   * ``EL_BUNCH_PARLETT``

.. c:type:: ElLDLPivotCtrl_s

   .. c:member:: ElLDLPivotType pivotType

   .. c:member:: float gamma

.. c:type:: ElLDLPivotCtrl_d

   .. c:member:: ElLDLPivotType pivotType

   .. c:member:: double gamma

.. c:type:: ElLDLPivot

   .. c:member:: Int nb

      Whether the pivot is 1x1 or 2x2.

   .. c:member:: Int from[2]

      The source indices of the row or rows to swap with for the 1x1 or 2x2
      pivot.

.. c:function:: ElError ElLDLPiv_s( ElMatrix_s A, ElMatrix_s dSub, ElMatrix_i p )
.. c:function:: ElError ElLDLPiv_d( ElMatrix_d A, ElMatrix_d dSub, ElMatrix_i p )
.. c:function:: ElError ElLDLPiv_c( ElMatrix_c A, ElMatrix_c dSub, ElMatrix_i p, bool conjugate )
.. c:function:: ElError ElLDLPiv_z( ElMatrix_z A, ElMatrix_z dSub, ElMatrix_i p, bool conjugate )

.. c:function:: ElError ElLDLPivDist_s( ElDistMatrix_s A, ElDistMatrix_s dSub, ElDistMatrix_i p )
.. c:function:: ElError ElLDLPivDist_d( ElDistMatrix_d A, ElDistMatrix_d dSub, ElDistMatrix_i p )
.. c:function:: ElError ElLDLPivDist_c( ElDistMatrix_c A, ElDistMatrix_c dSub, ElDistMatrix_i p, bool conjugate )
.. c:function:: ElError ElLDLPivDist_z( ElDistMatrix_z A, ElDistMatrix_z dSub, ElDistMatrix_i p, bool conjugate )

References
----------
`C++11 implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/Pivoted.hpp>`__

`C++11 subroutines <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor/LDL/dense/Pivoted/>`__

`C++11 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.hpp>`__

`C99 wrapper <https://github.com/elemental/Elemental/blob/master/src/lapack_like/factor-C.cpp>`__

`C99 header <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/factor.h>`__

`Python wrapper <https://github.com/elemental/Elemental/blob/master/python/lapack_like/factor.py>`__

`C++11 test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/LDL.cpp>`__

`C++11 example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LDL.cpp>`__
