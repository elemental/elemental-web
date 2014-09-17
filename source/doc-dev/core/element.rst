Element manipulation
====================

Basic element manipulation and I/O
----------------------------------

Return the real/imaginary part of an element
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: T RealPart( const T& alpha )
.. cpp:function:: T ImagPart( const T& alpha )

C API
"""""

.. c:function:: ElError ElRealPart_c( complex_float alpha, float* result )
.. c:function:: ElError ElRealPart_z( complex_double alpha, double* result )

Set the real/imaginary part of an element
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   If an element is non-complex, an error is thrown if an attempt is
   made to set its imaginary component.

C++ API
"""""""

.. cpp:function:: void SetRealPart( T& alpha, Base<T>& beta )
.. cpp:function:: void SetImagPart( T& alpha, Base<T>& beta )

C API
"""""

.. c:function:: ElError ElSetRealPart_c( complex_float* alpha, float* result )
.. c:function:: ElError ElSetRealPart_z( complex_double* alpha, double* result )

Update the real/imaginary part of an element
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   If an element is non-complex, an error is thrown if an attempt is
   made to update its imaginary component.

C++ API
"""""""

.. cpp:function:: void UpdateRealPart( T& alpha, Base<T>& beta )
.. cpp:function:: void UpdateImagPart( T& alpha, Base<T>& beta )

C API
"""""

.. c:function:: ElError ElUpdateRealPart_c( complex_float* alpha, float* result )
.. c:function:: ElError ElUpdateRealPart_z( complex_double* alpha, double* result )

Conjugate an element
^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: F Conj( const F& alpha )

C API
"""""

.. c:function:: ElError ElConj_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElConj_z( complex_double alpha, complex_double* result )

Return the complex argument
^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: Base<F> Arg( const F& alpha )

C API
"""""

.. c:function:: ElError ElArg_s( float alpha, float* result )
.. c:function:: ElError ElArg_d( double alpha, double* result )
.. c:function:: ElError ElArg_c( complex_float alpha, float* result )
.. c:function:: ElError ElArg_z( complex_double alpha, double* result )

Construct a complex number from its polar coordinates
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: Complex<Real> Polar( const R& r, const R& theta=0 )

C API
"""""

.. c:function:: ElError ElComplexFromPolar_c( float r, float theta, complex_float* result )
.. c:function:: ElError ElComplexFromPolar_z( double r, double theta, complex_double* result )

Magnitude and sign
------------------

C++ API
^^^^^^^

.. cpp:function:: Base<F> Abs( const F& alpha )

   Use the naive algorithm for computing the absolute value 
   (note that unnecessary overflow may occur for complex values, please see :cpp:func:`SafeAbs`)

.. cpp:function:: Real SafeAbs( const Complex<Real>& alpha )

   Carefully avoid overflow via ``slapy2`` or ``dlapy2``

.. cpp:function:: Real FastAbs( const Complex<Real>& alpha )

   Return the sum of the absolute values of the real and imaginary components

.. cpp:function:: Real Sgn( const Real& alpha, bool symmetric=true )

   If :math:`\alpha \neq 0`, :math:`\alpha/|\alpha|` is returned. 
   If `symmetric` is true, :math:`\text{sgn}(0)=0`, otherwise, 
   :math:`\text{sgn}(0)=1`.

C API
^^^^^

.. c:function:: ElError ElAbs_i( ElInt alpha, ElInt* result )
.. c:function:: ElError ElAbs_s( float alpha, float* result )
.. c:function:: ElError ElAbs_d( double alpha, double* result )
.. c:function:: ElError ElAbs_c( complex_float alpha, float* result )
.. c:function:: ElError ElAbs_z( complex_double alpha, double* result )

.. c:function:: ElError ElSafeAbs_c( complex_float alpha, float* result )
.. c:function:: ElError ElSafeAbs_z( complex_double alpha, double* result )

.. c:function:: ElError ElFastAbs_c( complex_float alpha, float* result )
.. c:function:: ElError ElFastAbs_z( complex_double alpha, double* result )

.. c:function:: ElError ElSgn_i( ElInt alpha, bool symmetric, ElInt* result )
.. c:function:: ElError ElSgn_s( float alpha, bool symmetric, float* result )
.. c:function:: ElError ElSgn_d( double alpha, bool symmetric, double* result )

Exponentiation
--------------

C++ API
^^^^^^^

.. cpp:function:: F Exp( const F& alpha )

   Returns the exponential of a scalar

.. cpp:function:: F Pow( const F& alpha, const T& beta )

   Returns :math:`\alpha^\beta` for scalar :math:`\alpha` and scalar or integer :math:`\beta`

.. cpp:function:: F Log( const F& alpha )

   Returns the natural logarithm of a scalar

.. cpp:function:: F Sqrt( const F& alpha )

   Returns the square-root of a scalar

C API
^^^^^

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

Trigonometric functions
-----------------------

C++ API
^^^^^^^

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
^^^^^

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

Hyperbolic functions
--------------------

C++ API
^^^^^^^

.. cpp:function:: F Cosh( const F& alpha )
.. cpp:function:: F Sinh( const F& alpha )
.. cpp:function:: F Tanh( const F& alpha )

   Hyperbolic functions

.. cpp:function:: Acosh( const F& alpha )
.. cpp:function:: Asinh( const F& alpha )
.. cpp:function:: Atanh( const F& alpha )

   Inverse hyperbolic functions

C API
^^^^^

.. c:function:: ElError ElCosh_s( float alpha, float* result )
.. c:function:: ElError ElCosh_d( double alpha, double* result )
.. c:function:: ElError ElCosh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElCosh_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElSinh_s( float alpha, float* result )
.. c:function:: ElError ElSinh_d( double alpha, double* result )
.. c:function:: ElError ElSinh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElSinh_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElTanh_s( float alpha, float* result )
.. c:function:: ElError ElTanh_d( double alpha, double* result )
.. c:function:: ElError ElTanh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElTanh_z( complex_double alpha, complex_double* result )

   Hyperbolic functions

.. c:function:: ElError ElAcosh_s( float alpha, float* result )
.. c:function:: ElError ElAcosh_d( double alpha, double* result )
.. c:function:: ElError ElAcosh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAcosh_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElAsinh_s( float alpha, float* result )
.. c:function:: ElError ElAsinh_d( double alpha, double* result )
.. c:function:: ElError ElAsinh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAsinh_z( complex_double alpha, complex_double* result )
.. c:function:: ElError ElAtanh_s( float alpha, float* result )
.. c:function:: ElError ElAtanh_d( double alpha, double* result )
.. c:function:: ElError ElAtanh_c( complex_float alpha, complex_float* result )
.. c:function:: ElError ElAtanh_z( complex_double alpha, complex_double* result )

   Inverse hyperbolic functions
