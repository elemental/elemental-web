Wigner
======
A Hermitian matrix whose entries in one triangle are all independent samples
from a normal distribution. The spectra of these matrices are well-studied.

C++ API
-------

.. cpp:function:: void Wigner( Matrix<T>& A, Int n, T mean=0, Base<T> stddev=1 )
.. cpp:function:: void Wigner( AbstractDistMatrix<T>& A, Int n, T mean=0, Base<T> stddev=1 )

C API
-----

.. c:function:: ElError ElWigner_i( ElMatrix_i A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_s( ElMatrix_s A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_d( ElMatrix_d A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_c( ElMatrix_c A, ElInt k, bool binary )
.. c:function:: ElError ElWigner_z( ElMatrix_z A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_i( ElDistMatrix_i A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_s( ElDistMatrix_s A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_d( ElDistMatrix_d A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_c( ElDistMatrix_c A, ElInt k, bool binary )
.. c:function:: ElError ElWignerDist_z( ElDistMatrix_z A, ElInt k, bool binary )
