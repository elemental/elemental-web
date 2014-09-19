Condition number
----------------

`Main header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack-like/props/Condition.hpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/include/El/lapack-like/props/Condition>`__

The condition number of a matrix with respect to a particular norm is

.. math::

   \kappa(A) = \|A\| \|A^{-1}\|,

with the most common choice being the matrix two-norm.

General
^^^^^^^
Returns the condition number with respect to the specified norm 
(one, two, or Frobenius).

C++ API
"""""""

.. cpp:function:: Base<F> Condition( const Matrix<F>& A, NormType type=TWO_NORM )
.. cpp:function:: Base<F> Condition( const AbstractDistMatrix<F>& A, NormType type=TWO_NORM )

C API
"""""

.. c:function:: ElError ElCondition_s( ElConstMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_d( ElConstMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElCondition_c( ElConstMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_z( ElConstMatrix_z A, ElNormType normType, double* cond )
.. c:function:: ElError ElConditionDist_s( ElConstDistMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_d( ElConstDistMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElConditionDist_c( ElConstDistMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_z( ElConstDistMatrix_z A, ElNormType normType, double* cond )

Frobenius norm
^^^^^^^^^^^^^^
Returns the condition number with respect to the Frobenius norm.

C++ API
"""""""

.. cpp:function:: Base<F> FrobeniusCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> FrobeniusCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElFrobeniusCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElFrobeniusConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElFrobeniusConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElFrobeniusConditionDist_z( ElConstDistMatrix_z A, double* cond )

Infinity norm
^^^^^^^^^^^^^
Returns the condition number with respect to the infinity norm.

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

Max norm
^^^^^^^^
Returns the condition number with respect to the entrywise maximum norm.

C++ API
"""""""

.. cpp:function:: Base<F> MaxCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> MaxCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElMaxCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElMaxCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElMaxCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElMaxCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElMaxConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElMaxConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElMaxConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElMaxConditionDist_z( ElConstDistMatrix_z A, double* cond )

One norm
^^^^^^^^
Returns the condition number with respect to the one norm.

C++ API
"""""""

.. cpp:function:: Base<F> OneCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> OneCondition( const AbstractDistMatrix<F>& A )

C API
"""""

.. c:function:: ElError ElOneCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElOneCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElOneCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElOneCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElOneConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElOneConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElOneConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElOneConditionDist_z( ElConstDistMatrix_z A, double* cond )

Two norm
^^^^^^^^
Returns the condition number with respect to the two norm.

C++ API
"""""""

.. cpp:function:: Base<F> TwoCondition( const Matrix<F>& A )
.. cpp:function:: Base<F> TwoCondition( const AbstractDistMatrix<F>& A )

C API
^^^^^

.. c:function:: ElError ElTwoCondition_s( ElConstMatrix_s A, float* cond )
.. c:function:: ElError ElTwoCondition_d( ElConstMatrix_d A, double* cond )
.. c:function:: ElError ElTwoCondition_c( ElConstMatrix_c A, float* cond )
.. c:function:: ElError ElTwoCondition_z( ElConstMatrix_z A, double* cond )
.. c:function:: ElError ElTwoConditionDist_s( ElConstDistMatrix_s A, float* cond )
.. c:function:: ElError ElTwoConditionDist_d( ElConstDistMatrix_d A, double* cond )
.. c:function:: ElError ElTwoConditionDist_c( ElConstDistMatrix_c A, float* cond )
.. c:function:: ElError ElTwoConditionDist_z( ElConstDistMatrix_z A, double* cond )

