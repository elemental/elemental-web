Spectral portrait
=================
The following routines return the norms of the shifted inverses over an 
*automatically-determined* 2D window in the complex plane 
(in the matrix ``invNormMap``) with the specified x and y resolutions.
The returned integer matrix corresponds to the number of iterations required
for convergence at each shift in the 2D grid.

Python API
----------
.. py:function:: SpectralPortrait(A[,realSize=100,imagSize=100,ctrl=None])

C++ API
-------
.. cpp:function:: Matrix<int> SpectralPortrait( const Matrix<F>& A, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> SpectralPortrait( const AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralPortrait( const Matrix<F>& U, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> TriangularSpectralPortrait( const AbstractDistMatrix<F>& U, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> QuasiTriangularSpectralPortrait( const Matrix<Real>& U, Matrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: DistMatrix<int> QuasiTriangularSpectralPortrait( const AbstractDistMatrix<Real>& U, AbstractDistMatrix<Real>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralPortrait( const Matrix<F>& H, Matrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int> HessenbergSpectralPortrait( const AbstractDistMatrix<F>& H, AbstractDistMatrix<Base<F>>& invNormMap, Int realSize, Int imagSize, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralPortrait_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_s( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_s( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralPortrait_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_d( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_d( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralPortrait_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_c( ElConstMatrix_c A, ElMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_c( ElConstDistMatrix_c A, ElDistMatrix_c invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralPortrait_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize )
.. c:function:: ElError ElSpectralPortraitDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize )

.. c:function:: ElError ElSpectralPortraitX_z( ElConstMatrix_z A, ElMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralPortraitXDist_z( ElConstDistMatrix_z A, ElDistMatrix_z invNormMap, ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl )
