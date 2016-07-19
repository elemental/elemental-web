Exponentiation
==============

C++ API
-------

.. cpp:function:: F Exp( const F& alpha )

   Returns the exponential of a scalar

.. cpp:function:: F Pow( const F& alpha, const T& beta )

   Returns :math:`\alpha^\beta` for scalar :math:`\alpha` and scalar or integer :math:`\beta`

.. cpp:function:: F Log( const F& alpha )

   Returns the natural logarithm of a scalar

.. cpp:function:: F Sqrt( const F& alpha )

   Returns the square-root of a scalar

C API
-----

.. c:function:: ElError ElExp_s( float alpha, float* result )
.. c:function:: ElError ElExp_d( double alpha, double* result )
.. c:function:: ElError ElExp_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElExp_z( complex_double alpha, complex_double* result )

.. c:function:: ElError ElPow_s( float alpha, float beta, float* result )
.. c:function:: ElError ElPow_d( double alpha, double beta, double* result )
.. c:function:: ElError ElPow_c( complex_float alpha, complex_float beta, complex_float* result )
.. c:function:: ElError ElPow_z( complex_double alpha, complex_double beta, complex_double* result )

.. c:function:: ElError ElLog_s( float alpha, float* result )
.. c:function:: ElError ElLog_d( double alpha, double* result )
.. c:function:: ElError ElLog_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElLog_z( complex_double alpha, complex_double* result )

.. c:function:: ElError ElSqrt_s( float alpha, float* result )
.. c:function:: ElError ElSqrt_d( double alpha, double* result )
.. c:function:: ElError ElSqrt_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElSqrt_z( complex_double alpha, complex_double* result )
