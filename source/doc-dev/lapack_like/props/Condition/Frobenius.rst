Frobenius-norm condition number
===============================

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/include/El/lapack_like/props/Condition/Frobenius.cpp>`__

C++ API
-------

.. cpp:function:: Base<F> FrobeniusCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusCondition( const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElFrobeniusCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_z( ElConstMatrix_z A, double* cond )

.. c:function:: ElError ElFrobeniusConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_z( ElConstDistMatrix_z A, double* cond )

Python API
----------
.. py:function:: FrobeniusCondition(A)
