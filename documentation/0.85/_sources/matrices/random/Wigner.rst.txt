Wigner
======
A Hermitian matrix whose entries in one triangle are all independent samples
from a normal distribution. The spectra of these matrices are well-studied.

C++ API
-------

.. cpp:function:: void Wigner( Matrix<F>& A, Int n, F mean=0, Base<F> stddev=1 )
.. cpp:function:: void Wigner( AbstractDistMatrix<F>& A, Int n, F mean=0, Base<F> stddev=1 )

C API
-----

.. c:function:: ElError ElWigner_s( ElMatrix_s A, ElInt n, float mean, float stddev )
.. c:function:: ElError ElWigner_d( ElMatrix_d A, ElInt n, double mean, double stddev )
.. c:function:: ElError ElWigner_c( ElMatrix_c A, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElWigner_z( ElMatrix_z A, ElInt n, complex_double mean, double stddev )
.. c:function:: ElError ElWignerDist_s( ElDistMatrix_s A, ElInt n, float mean, float stddev )
.. c:function:: ElError ElWignerDist_d( ElDistMatrix_d A, ElInt n, double mean, double stddev )
.. c:function:: ElError ElWignerDist_c( ElDistMatrix_c A, ElInt n, complex_float mean, float stddev )
.. c:function:: ElError ElWignerDist_z( ElDistMatrix_z A, ElInt n, complex_double mean, double stddev )

Python API
----------

.. py:function:: Wigner(A,n,mean=0,stddev=1)
