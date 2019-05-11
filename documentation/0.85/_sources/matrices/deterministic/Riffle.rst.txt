Riffle
======
This is an implementation of the riffle-shuffle transition matrix made famous by
Diaconis et al. The computation of binomial and Eulerian coefficients closely
follows the scripts provided in Trefethen and Embree's 
*Spectra and Pseudospectra: The Behaviour of Nonnormal Matrices and Operators*.

C++ API
-------

.. cpp:function:: void Riffle( Matrix<F>& P, Int n )
.. cpp:function:: void Riffle( AbstractDistMatrix<F>& P, Int n )
.. cpp:function:: void Riffle( AbstractBlockDistMatrix<F>& P, Int n )

   Return the :math:`n \times n` transition matrix.

.. cpp:function:: void Riffle( Matrix<F>& P, Matrix<F>& PInf, Int n )
.. cpp:function:: void Riffle( AbstractDistMatrix<F>& P, AbstractDistMatrix<F>& PInf, Int n )
.. cpp:function:: void Riffle( AbstractBlockDistMatrix<F>& P, AbstractBlockDistMatrix<F>& PInf, Int n )

   Return both the :math:`n \times n` transition matrix and its stationary 
   distribution (as a square matrix with identical rows).

.. cpp:function:: void RiffleStationary( Matrix<F>& PInf, Int n )
.. cpp:function:: void RiffleStationary( AbstractDistMatrix<F>& PInf, Int n )
.. cpp:function:: void RiffleStationary( AbstractBlockDistMatrix<F>& PInf, Int n )

   Return the stationary distribution of the :math:`n \times n` system as
   a square matrix with identical rows.

.. cpp:function:: void RiffleDecay( Matrix<F>& A, Int n )
.. cpp:function:: void RiffleDecay( AbstractDistMatrix<F>& A, Int n )

   Return the transition matrix with its stationary distribution subtracted
   from each row.

C API
-----

.. c:function:: ElError ElRiffle_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElRiffle_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElRiffle_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElRiffle_z( ElMatrix_z P, ElInt n )
.. c:function:: ElError ElRiffleDist_s( ElDistMatrix_s P, ElInt n )
.. c:function:: ElError ElRiffleDist_d( ElDistMatrix_d P, ElInt n )
.. c:function:: ElError ElRiffleDist_c( ElDistMatrix_c P, ElInt n )
.. c:function:: ElError ElRiffleDist_z( ElDistMatrix_z P, ElInt n )

   Return the :math:`n \times n` transition matrix.

.. c:function:: ElError ElRiffleStationary_s( ElMatrix_s PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_d( ElMatrix_d PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_c( ElMatrix_c PInf, ElInt n )
.. c:function:: ElError ElRiffleStationary_z( ElMatrix_z PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_s( ElDistMatrix_s PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_d( ElDistMatrix_d PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_c( ElDistMatrix_c PInf, ElInt n )
.. c:function:: ElError ElRiffleStationaryDist_z( ElDistMatrix_z PInf, ElInt n )

   Return the stationary distribution of the :math:`n \times n` system as a
   square matrix with identical rows.

.. c:function:: ElError ElRiffleDecay_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElRiffleDecay_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElRiffleDecay_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElRiffleDecay_z( ElMatrix_z A, ElInt n )

   Return the transition matrix with its stationary distribution subtracted
   from each row.

Python API
----------

.. py:function:: Riffle(P,n)
.. py:function:: RiffleStationary(PInf,n)
.. py:function:: RiffleDecay(A,n)
