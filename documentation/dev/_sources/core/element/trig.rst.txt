Trigonometric functions
=======================

C++ API
-------

.. cpp:function:: F Cos( const F& alpha )
.. cpp:function:: F Sin( const F& alpha )
.. cpp:function:: F Tan( const F& alpha )

   Trigonometric functions

.. cpp:function:: Acos( const F& alpha )
.. cpp:function:: Asin( const F& alpha )
.. cpp:function:: Atan( const F& alpha )

   Inverse trigonometric functions

.. cpp:function:: Real Atan2( const Real& y, const Real& x )

   Return the inverse tangent of :math:`x+iy`

C API
-----

.. c:function:: ElError ElCos_s( float alpha, float* result )
.. c:function:: ElError ElCos_d( double alpha, double* result )
.. c:function:: ElError ElCos_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElCos_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElSin_s( float alpha, float* result )
.. c:function:: ElError ElSin_d( double alpha, double* result )
.. c:function:: ElError ElSin_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElSin_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElTan_s( float alpha, float* result )
.. c:function:: ElError ElTan_d( double alpha, double* result )
.. c:function:: ElError ElTan_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElTan_z( complex_double alpha, complex_double* result )

   Trigonometric functions

.. c:function:: ElError ElAcos_s( float alpha, float* result )
.. c:function:: ElError ElAcos_d( double alpha, double* result )
.. c:function:: ElError ElAcos_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAcos_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElAsin_s( float alpha, float* result )
.. c:function:: ElError ElAsin_d( double alpha, double* result )
.. c:function:: ElError ElAsin_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAsin_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElAtan_s( float alpha, float* result )
.. c:function:: ElError ElAtan_d( double alpha, double* result )
.. c:function:: ElError ElAtan_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAtan_z( complex_double alpha, complex_double* result )

   Inverse trigonometric functions

.. c:function:: ElError ElAtan2_s( float y, float x, float* result )
.. c:function:: ElError ElAtan2_d( double y, double x, double* result )

   Return the inverse tangent of the point :math:`x + i y`
