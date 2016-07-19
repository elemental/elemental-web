Infinity-norm condition number
==============================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Condition/Infinity.cpp>`__

C++ API
"""""""
.. cpp:function:: Base<F> InfinityCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> InfinityCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElInfinityCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElInfinityCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElInfinityCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElInfinityCondition_z( ElConstMatrix_z A, double* cond )

.. c:function:: ElError ElInfinityConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElInfinityConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElInfinityConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElInfinityConditionDist_z( ElConstDistMatrix_z A, double* cond )

Python API
----------
.. py:function:: InfinityCondition(A)
