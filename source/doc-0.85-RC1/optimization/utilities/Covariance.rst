Covariance
==========
The following routines compute the covariance matrix

.. math::

   S := \frac{1}{n-1} \sum_{j=0}^{n-1} (d_j-\bar d) (d_j-\bar d)^H,

where :math:`\bar d` is the average of the :math:`n` observations 
(the columns of :math:`D`).

C++ API
-------

.. cpp:function:: void Covariance( const Matrix<F>& D, Matrix<F>& S )
.. cpp:function:: void Covariance( const AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& S )

C API
-----

.. c:function:: ElError ElCovariance_s( ElConstMatrix_s D, ElMatrix_s S )
.. c:function:: ElError ElCovariance_d( ElConstMatrix_d D, ElMatrix_d S )
.. c:function:: ElError ElCovariance_c( ElConstMatrix_c D, ElMatrix_c S )
.. c:function:: ElError ElCovariance_z( ElConstMatrix_z D, ElMatrix_z S )
.. c:function:: ElError ElCovarianceDist_s( ElConstDistMatrix_s D, ElDistMatrix_s S )
.. c:function:: ElError ElCovarianceDist_d( ElConstDistMatrix_d D, ElDistMatrix_d S )
.. c:function:: ElError ElCovarianceDist_c( ElConstDistMatrix_c D, ElDistMatrix_c S )
.. c:function:: ElError ElCovarianceDist_z( ElConstDistMatrix_z D, ElDistMatrix_z S )
