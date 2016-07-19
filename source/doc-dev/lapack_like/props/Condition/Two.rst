Two-norm condition number
=========================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Condition/Two.cpp>`__

C++ API
-------

.. cpp:function:: Base<F> TwoCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoCondition( const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElTwoCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElTwoCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElTwoCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElTwoCondition_z( ElConstMatrix_z A, double* cond )

.. c:function:: ElError ElTwoConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElTwoConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElTwoConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElTwoConditionDist_z( ElConstDistMatrix_z A, double* cond )

Python API
----------
.. py:function:: TwoCondition(A)
