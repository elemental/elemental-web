Laplacian
=========

C++ API
-------

.. cpp:function:: void Laplacian( Matrix<F>& L, Int n )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int n )

   Discrete Laplacian over :math:`[0,1]` with n grid points

.. cpp:function:: void Laplacian( Matrix<F>& L, Int nx, Int ny )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int nx, Int ny )

   Discrete Laplacian over :math:`[0,1]^2` with :math:`n_x \times n_y`
   grid points

.. cpp:function:: void Laplacian( Matrix<F>& L, Int nx, Int ny, Int nz )
.. cpp:function:: void Laplacian( AbstractDistMatrix<F>& L, Int nx, Int ny, Int nz )

   Discrete Laplacian over :math:`[0,1]^3` with 
   :math:`n_x \times n_y \times n_z` grid points

C API
-----

.. c:function:: ElError ElLaplacian1D_s( ElMatrix_s L, ElInt n )
.. c:function:: ElError ElLaplacian1D_d( ElMatrix_d L, ElInt n )
.. c:function:: ElError ElLaplacian1D_c( ElMatrix_c L, ElInt n )
.. c:function:: ElError ElLaplacian1D_z( ElMatrix_z L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_s( ElDistMatrix_s L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_d( ElDistMatrix_d L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_c( ElDistMatrix_c L, ElInt n )
.. c:function:: ElError ElLaplacian1DDist_z( ElDistMatrix_z L, ElInt n )

   Discrete Laplacian over :math:`[0,1]` with `n` grid points

.. c:function:: ElError ElLaplacian2D_s( ElMatrix_s L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_d( ElMatrix_d L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_c( ElMatrix_c L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2D_z( ElMatrix_z L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_s( ElDistMatrix_s L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_d( ElDistMatrix_d L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_c( ElDistMatrix_c L, ElInt nx, ElInt ny )
.. c:function:: ElError ElLaplacian2DDist_z( ElDistMatrix_z L, ElInt nx, ElInt ny )

   Discrete Laplacian over :math:`[0,1]^2` with :math:`n_x \times n_y`
   grid points
