Coherence
=========
The *coherence* of an :math:`m \times n` matrix :math:`A` can be defined as

.. math::
   \| \hat A^H \hat A - I \|_{\text{max}},

where :math:`\hat A` is formed by normalizing each column of :math:`A` to 
have a unit Euclidean norm.

C++ API
-------

.. cpp:function:: Base<F> Coherence( const Matrix<F>& A )
.. cpp:function:: Base<F> Coherence( const AbstractDistMatrix<F>& A )

C API
-----

.. c:function:: ElError ElCoherence_s( ElConstMatrix_s A, float* coherence )
.. c:function:: ElError ElCoherence_d( ElConstMatrix_d A, double* coherence )
.. c:function:: ElError ElCoherence_c( ElConstMatrix_c A, float* coherence )
.. c:function:: ElError ElCoherence_z( ElConstMatrix_z A, double* coherence )

.. c:function:: ElError ElCoherence_s( ElConstDistMatrix_s A, float* coherence )
.. c:function:: ElError ElCoherence_d( ElConstDistMatrix_d A, double* coherence )
.. c:function:: ElError ElCoherence_c( ElConstDistMatrix_c A, float* coherence )
.. c:function:: ElError ElCoherence_z( ElConstDistMatrix_z A, double* coherence )

Python API
----------

.. py:function:: Coherence(A)
