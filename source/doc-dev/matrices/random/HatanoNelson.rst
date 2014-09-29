Hatano-Nelson
=============
*Hatano-Nelson matrices* extend the (Nobel prize winning) work of Anderson on 
the localization of eigenvalues of random tridiagonal matrices. The matrices
have a main diagonal with each entry sampled from the uniform distribution
over a ball from the real line or complex plane; each entry of the superdiagonal
is set to :math:`e^g` (if periodic, also the bottom-left corner), 
each entry of the subdiagonal is set to :math:`e^{-g}` 
(if periodic, also the top-right corner).

C++ API
-------

.. cpp:function:: void HatanoNelson( Matrix<F>& A, Int n, F center, Base<F> radius, F g, bool periodic=true )
.. cpp:function:: void HatanoNelson( AbstractDistMatrix<F>& A, Int n, F center, Base<F> radius, F g, bool periodic=true )

C API
-----

.. c:function:: ElError ElHatanoNelson_s( ElMatrix_s A, ElInt n, float center, float radius, float g, bool periodic )
.. c:function:: ElError ElHatanoNelson_d( ElMatrix_d A, ElInt n, double center, double radius, double g, bool periodic )
.. c:function:: ElError ElHatanoNelson_c( ElMatrix_c A, ElInt n, complex_float center, float radius, complex_float g, bool periodic )
.. c:function:: ElError ElHatanoNelson_z( ElMatrix_z A, ElInt n, complex_double center, double radius, complex_double g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_s( ElDistMatrix_s A, ElInt n, float center, float radius, float g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_d( ElDistMatrix_d A, ElInt n, double center, double radius, double g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_c( ElDistMatrix_c A, ElInt n, complex_float center, float radius, complex_float g, bool periodic )
.. c:function:: ElError ElHatanoNelsonDist_z( ElDistMatrix_z A, ElInt n, complex_double center, double radius, complex_double g, bool periodic )

