Max-norm condition number
=========================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Condition/Max.cpp>`__

Returns the condition number with respect to the entrywise maximum norm.

C++ API
-------

.. cpp:function:: Base<F> MaxCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> MaxCondition( const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElMaxCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElMaxCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElMaxCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElMaxCondition_z( ElConstMatrix_z A, double* cond )

.. c:function:: ElError ElMaxConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElMaxConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElMaxConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElMaxConditionDist_z( ElConstDistMatrix_z A, double* cond )

Python API
----------
.. py:function:: MaxCondition(A)
