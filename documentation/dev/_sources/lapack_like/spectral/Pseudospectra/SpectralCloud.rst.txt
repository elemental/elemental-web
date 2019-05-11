Spectral cloud
==============
The following routines return the norms of the shifted inverses in the vector 
``invNorms`` for a given set of shifts. The returned integer vector is a list 
of the number of iterations required for convergence of each shift.

Python API
----------
.. py:function:: SpectralCloud(A,shifts[,ctrl=None])

C++ API
-------
.. cpp:function:: Matrix<int> SpectralCloud( const Matrix<F>& A, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> SpectralCloud( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: Matrix<int> TriangularSpectralCloud( const Matrix<F>& U, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> TriangularSpectralCloud( const AbstractDistMatrix<F>& U, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> QuasiTriangularSpectralCloud( const AbstractDistMatrix<Real>& U, const AbstractDistMatrix<Complex<Real>>& shifts, AbstractDistMatrix<Real>& invNorms, PseudospecCtrl<Real> psCtrl=PseudospecCtrl<Real>() )
.. cpp:function:: Matrix<int> HessenbergSpectralCloud( const Matrix<F>& H, const Matrix<Complex<Base<F>>>& shifts, Matrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )
.. cpp:function:: DistMatrix<int,VR,STAR> HessenbergSpectralCloud( const AbstractDistMatrix<F>& H, const AbstractDistMatrix<Complex<Base<F>>>& shifts, AbstractDistMatrix<Base<F>>& invNorms, PseudospecCtrl<Base<F>> psCtrl=PseudospecCtrl<Base<F>>() )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralCloud_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElSpectralCloudDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )

.. c:function:: ElError ElSpectralCloudX_s( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralCloudXDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralCloud_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElSpectralCloudDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElSpectralCloudX_d( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralCloudXDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralCloud_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap )
.. c:function:: ElError ElSpectralCloudDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap )

.. c:function:: ElError ElSpectralCloudX_c( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )
.. c:function:: ElError ElSpectralCloudXDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts, ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSpectralCloud_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap )
.. c:function:: ElError ElSpectralCloudDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap )

.. c:function:: ElError ElSpectralCloudX_z( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )
.. c:function:: ElError ElSpectralCloudXDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts, ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl )

