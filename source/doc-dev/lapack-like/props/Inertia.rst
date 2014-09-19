Inertia
-------

`Implementation <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Inertia.hpp>`__

The following routines return a triplet containing the number of positive, 
negative, and zero eigenvalues of a Hermitian matrix by analyzing the 
quasi-diagonal matrix resulting from a pivoted LDLH factorization.

C++ API
^^^^^^^

.. cpp:type:: InertiaType

   .. cpp:member:: Int numPositive
   .. cpp:member:: Int numNegative
   .. cpp:member:: Int numZero

      The basic eigenvalue structure of a Hermitian matrix (which can be quickly
      computed from the quasi-diagonal matrix produced by Bunch-Kaufman).

.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, Matrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )
.. cpp:function:: InertiaType Inertia( UpperOrLower uplo, AbstractDistMatrix<F>& A, LDLPivotType pivotType=BUNCH_PARLETT )

C API
^^^^^

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

