Cauchy-like
===========
An :math:`m \times n` matrix :math:`A` is called *Cauchy-like* if there exist 
vectors :math:`r`, :math:`s`, :math:`x`, and :math:`y` such that 

.. math::

   A(i,j) = \frac{r(i) s(j)}{x(i) - y(j)}.

The following routines generate a Cauchy-like matrix using the defining 
vectors: :math:`r`, :math:`s`, :math:`x`, and :math:`y`.

C++ API
-------

.. cpp:function:: void CauchyLike( Matrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )
.. cpp:function:: void CauchyLike( AbstractDistMatrix<F>& A, const std::vector<F>& r, const std::vector<F>& s, const std::vector<F>& x, const std::vector<F>& y )

C API
-----

.. c:function:: ElError ElCauchyLike_s( ElMatrix_s A, ElInt rSize, float* rBuf, ElInt sSize, float* sBuf, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyLike_d( ElMatrix_d A, ElInt rSize, double* rBuf, ElInt sSize, double* sBuf, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyLike_c( ElMatrix_c A, ElInt rSize, complex_float* rBuf, ElInt sSize, complex_float* sBuf, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyLike_z( ElMatrix_z A, ElInt rSize, complex_double* rBuf, ElInt sSize, complex_double* sBuf, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )
.. c:function:: ElError ElCauchyLikeDist_s( ElDistMatrix_s A, ElInt rSize, float* rBuf, ElInt sSize, float* sBuf, ElInt xSize, float* xBuf, ElInt ySize, float* yBuf )
.. c:function:: ElError ElCauchyLikeDist_d( ElDistMatrix_d A, ElInt rSize, double* rBuf, ElInt sSize, double* sBuf, ElInt xSize, double* xBuf, ElInt ySize, double* yBuf )
.. c:function:: ElError ElCauchyLikeDist_c( ElDistMatrix_c A, ElInt rSize, complex_float* rBuf, ElInt sSize, complex_float* sBuf, ElInt xSize, complex_float* xBuf, ElInt ySize, complex_float* yBuf )
.. c:function:: ElError ElCauchyLikeDist_z( ElDistMatrix_z A, ElInt rSize, complex_double* rBuf, ElInt sSize, complex_double* sBuf, ElInt xSize, complex_double* xBuf, ElInt ySize, complex_double* yBuf )

Python API
----------

.. py:function:: CauchyLike(A,r,s,x,y)

