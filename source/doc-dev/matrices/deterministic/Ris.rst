Ris
===
Return the :math:`n \times n` matrix with the :math:`(i,j)` entry
(counting from zero) set to

.. math::

   A(i,j) = \frac{1}{2(n-i-j)-1}.

C++ API
-------

.. cpp:function:: void Ris( Matrix<F>& R, Int n )
.. cpp:function:: void Ris( AbstractDistMatrix<F>& R, Int n )

C API
-----

.. c:function:: ElError ElRis_s( ElMatrix_s R, ElInt n )
.. c:function:: ElError ElRis_d( ElMatrix_d R, ElInt n )
.. c:function:: ElError ElRis_c( ElMatrix_c R, ElInt n )
.. c:function:: ElError ElRis_z( ElMatrix_z R, ElInt n )
.. c:function:: ElError ElRisDist_s( ElDistMatrix_s R, ElInt n )
.. c:function:: ElError ElRisDist_d( ElDistMatrix_d R, ElInt n )
.. c:function:: ElError ElRisDist_c( ElDistMatrix_c R, ElInt n )
.. c:function:: ElError ElRisDist_z( ElDistMatrix_z R, ElInt n )
