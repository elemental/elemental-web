Spectral window
===============
The following routines return the norms of the shifted inverses over a
*user-specified* 2D window in the complex plane (in the matrix ``invNormMap``) 
with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

Python API
----------
.. py:function:: SpectralWindow(A[,center=0,realWidth=1,imagWidth=1,realSize=100,imagSize=100,ctrl=None])

C++ API
-------
.. cpp:function:: Matrix<int> SpectralWindow( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> SpectralWindow( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralWindow( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularSpectralWindow( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularSpectralWindow( const Matrix<Real>& U, Matrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularSpectralWindow( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Complex<Real> center, Real realWidth, Real imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralWindow( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergSpectralWindow( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Complex<Base<F>> center, Base<F> realWidth, Base<F> imagWidth, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralWindow_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralWindowXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralWindow_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralWindowXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralWindow_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralWindowXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, complex_float center, float realWidth, float imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralWindow_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralWindowDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralWindowX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralWindowXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, complex_double center, double realWidth, double imagWidth, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
