Complex data
============

C++ API
-------

.. cpp:type:: Complex<Real>

   Currently a typedef of ``std::complex<Real>``

.. cpp:type:: Base<F>

   The underlying real datatype of the (potentially complex) datatype `F`.
   For example, ``Base<Complex<double>>`` and 
   ``Base<double>`` are both equivalent to ``double``.
   This is often extremely useful in implementing routines which are 
   templated over real and complex datatypes but still make use of real 
   datatypes.

.. cpp:function:: std::ostream& operator<<( std::ostream& os, Complex<Real> alpha )

   Pretty prints `alpha` in the form ``a+bi``.

.. cpp:type:: scomplex

   ``typedef Complex<float> scomplex;``

.. cpp:type:: dcomplex

   ``typedef Complex<double> dcomplex;``

C API
-----

.. c:type:: complex_float

   A struct equivalent to ``struct complex_float { float real, imag; }`` which
   is meant to be binary compatible with ``std::complex<float>``.

.. c:type:: complex_double

   A struct equivalent to ``struct complex_double { double real, imag; }``
   which is meant to be binary compatible with ``std::complex<double>``.
