One-norm condition number
=========================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Condition/One.cpp>`__

C++ API
-------

.. cpp:function:: Base<F> OneCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> OneCondition( const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElOneCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElOneCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElOneCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElOneCondition_z( ElConstMatrix_z A, double* cond )

.. c:function:: ElError ElOneConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElOneConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElOneConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElOneConditionDist_z( ElConstDistMatrix_z A, double* cond )

Python API
----------
.. py:function:: OneCondition(A)
