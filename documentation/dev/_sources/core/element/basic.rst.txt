Basic element manipulation and I/O
==================================

Return the real/imaginary part of an element
--------------------------------------------

C++ API
^^^^^^^

.. cpp:function:: T RealPart( const T& alpha )
.. cpp:function:: T ImagPart( const T& alpha )

C API
^^^^^

.. note::

   Since C does not support generic programming, it is best to directly
   manipulate the structure for complex data.

Set the real/imaginary part of an element
-----------------------------------------

.. note::

   If an element is non-complex, an error is thrown if an attempt is
   made to set its imaginary component.

C++ API
^^^^^^^

.. cpp:function:: void SetRealPart( T& alpha, Base<T>& beta )
.. cpp:function:: void SetImagPart( T& alpha, Base<T>& beta )

C API
^^^^^

.. note::

   Since C does not support generic programming, it is best to directly
   manipulate the structure for complex data.

Update the real/imaginary part of an element
--------------------------------------------

.. note::

   If an element is non-complex, an error is thrown if an attempt is
   made to update its imaginary component.

C++ API
^^^^^^^

.. cpp:function:: void UpdateRealPart( T& alpha, Base<T>& beta )
.. cpp:function:: void UpdateImagPart( T& alpha, Base<T>& beta )

C API
^^^^^

.. note::

   Since C does not support generic programming, it is best to directly
   manipulate the structure for complex data.

Conjugate an element
--------------------

C++ API
^^^^^^^

.. cpp:function:: F Conj( const F& alpha )

C API
^^^^^

.. note::

   Since C does not support generic programming, it is best to directly
   manipulate the structure for complex data.

Return the complex argument
---------------------------

C++ API
^^^^^^^

.. cpp:function:: Base<F> Arg( const F& alpha )

C API
^^^^^

.. c:function:: ElError ElArg_s( float alpha, float* result )
.. c:function:: ElError ElArg_d( double alpha, double* result )
.. c:function:: ElError ElArg_c( complex_float alpha, float* result )
.. c:function:: ElError ElArg_z( complex_double alpha, double* result )

Construct a complex number from its polar coordinates
-----------------------------------------------------

C++ API
^^^^^^^

.. cpp:function:: Complex<Real> Polar( const R& r, const R& theta=0 )

C API
^^^^^

.. c:function:: ElError ElComplexFromPolar_c( float r, float theta, complex_float* result )
.. c:function:: ElError ElComplexFromPolar_z( double r, double theta, complex_double* result )
