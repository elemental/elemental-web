Soft-thresholding
=================
Overwrites each entry of :math:`A` with its soft-thresholded value.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/optimization/SoftThreshold.cpp>`__

C++ API
-------

.. cpp:function:: void SoftThreshold( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: void SoftThreshold( AbstractDistMatrix<F>& A, Base<F> tau, bool relative=false )

C API
-----

.. c:function:: ElError ElSoftThreshold_s( ElMatrix_s A, float rho, bool relative )
.. c:function:: ElError ElSoftThreshold_d( ElMatrix_d A, double rho, bool relative )
.. c:function:: ElError ElSoftThreshold_c( ElMatrix_c A, float rho, bool relative )
.. c:function:: ElError ElSoftThreshold_z( ElMatrix_z A, double rho, bool relative )
.. c:function:: ElError ElSoftThresholdDist_s( ElDistMatrix_s A, float rho, bool relative )
.. c:function:: ElError ElSoftThresholdDist_d( ElDistMatrix_d A, double rho, bool relative )
.. c:function:: ElError ElSoftThresholdDist_c( ElDistMatrix_c A, float rho, bool relative )
.. c:function:: ElError ElSoftThresholdDist_z( ElDistMatrix_z A, double rho, bool relative )
