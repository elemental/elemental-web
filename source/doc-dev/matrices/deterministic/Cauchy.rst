Cauchy
======
An :math:`m \times n` matrix :math:`A` is called *Cauchy* if there exist 
vectors :math:`x` and :math:`y` such that 

.. math::

   A(i,j) = \frac{1}{x(i) - y(j)}.

The following functions generate a Cauchy matrix using the defining vectors, 
:math:`x` and :math:`y`. 

C++ API
-------

.. cpp:function:: void Cauchy( Matrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void Cauchy( AbstractDistMatrix<F>& A, const std::vector<F>& x, const std::vector<F>& y )

C API
-----

.. c:function:: ElError ElCauchy_s( ElMatrix_s A, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchy_d( ElMatrix_d A, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchy_c( ElMatrix_c A, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchy_z( ElMatrix_z A, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )
.. c:function:: ElError ElCauchyDist_s( ElDistMatrix_s A, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyDist_d( ElDistMatrix_d A, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyDist_c( ElDistMatrix_c A, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyDist_z( ElDistMatrix_z A, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )
