Condition number
================

Specialized interfaces
----------------------

.. toctree::
   :maxdepth: 1

   Condition/Frobenius
   Condition/Infinity
   Condition/Max
   Condition/One
   Condition/Two

Vanilla interface
-----------------

`Header file <https://github.com/elemental/Elemental/blob/master/include/El/lapack_like/props.hpp>`__

`Implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/props/Condition.cpp>`__

The condition number of a matrix with respect to a particular norm is

.. math::

   \kappa(A) = \|A\| \|A^{-1}\|,

with the most common choice being the matrix two-norm.

C++ API
-------

.. cpp:function:: Base<F> Condition( const Matrix<F>& A, NormType type=TWO_NORM )
.. cpp:function:: Base<F> Condition( const AbstractDistMatrix<F>& A, NormType type=TWO_NORM )

C API
-----

.. c:function:: ElError ElCondition_s( ElConstMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_d( ElConstMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElCondition_c( ElConstMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElCondition_z( ElConstMatrix_z A, ElNormType normType, double* cond )

.. c:function:: ElError ElConditionDist_s( ElConstDistMatrix_s A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_d( ElConstDistMatrix_d A, ElNormType normType, double* cond )
.. c:function:: ElError ElConditionDist_c( ElConstDistMatrix_c A, ElNormType normType, float* cond )
.. c:function:: ElError ElConditionDist_z( ElConstDistMatrix_z A, ElNormType normType, double* cond )

Python API
----------
.. py:function:: Condition(A,normType=FROBENIUS_NORM)
