Magnitude and sign
==================

C++ API
-------

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
-----

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
