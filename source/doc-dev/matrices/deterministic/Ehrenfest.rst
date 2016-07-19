Ehrenfest
=========
An :math:`n \times n` *Ehrenfest matrix* is the transition matrix for the 
famous Ehrenfest urns: a set of two urns collectively contains :math:`n-1` 
balls, and, at each step, a ball is selected at random and moved to the other 
urn.

The transition matrix for the Markov chain is described by a tridiagonal matrix where the main diagonal is zero, the superdiagonal is of the form :math:`\frac{1}{N-1},\frac{2}{N-1},...,1`, and the subdiagonal is of the form :math:`1,\frac{N-2}{N-1},...,\frac{1}{N-1}`.

There is a well-known connection between this model and a random walk over the
corners of a hypercube. Please see Lloyd N. Trefethen and S. J. Chapman's
*Wave packet pseudomodes of twisted Toepitz matrices* for more details.

C++ API
-------

.. cpp:function:: void Ehrenfest( Matrix<F>& P, Int n )
.. cpp:function:: void Ehrenfest( AbstractDistMatrix<F>& P, Int n )

.. cpp:function:: void Ehrenfest( Matrix<F>& P, Matrix<F>& PInf, Int n )
.. cpp:function:: void Ehrenfest( ElementalMatrix<F>& P, ElementalMatrix<F>& PInf, Int n )

.. cpp:function:: void EhrenfestStationary( Matrix<F>& PInf, Int n )
.. cpp:function:: void EhrenfestStationary( AbstractDistMatrix<F>& PInf, Int n )

.. cpp:function:: void EhrenfestDecay( Matrix<F>& A, Int n )
.. cpp:function:: void EhrenfestDecay( ElementalMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElEhrenfest_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElEhrenfest_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElEhrenfest_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElEhrenfest_z( ElMatrix_z P, ElInt n )
.. c:function:: ElError ElEhrenfestDist_s( ElMatrix_s P, ElInt n )
.. c:function:: ElError ElEhrenfestDist_d( ElMatrix_d P, ElInt n )
.. c:function:: ElError ElEhrenfestDist_c( ElMatrix_c P, ElInt n )
.. c:function:: ElError ElEhrenfestDist_z( ElMatrix_z P, ElInt n )

.. c:function:: ElError ElEhrenfestStationary_s( ElMatrix_s PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationary_d( ElMatrix_d PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationary_c( ElMatrix_c PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationary_z( ElMatrix_z PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationaryDist_s( ElDistMatrix_s PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationaryDist_d( ElDistMatrix_d PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationaryDist_c( ElDistMatrix_c PInf, ElInt n )
.. c:function:: ElError ElEhrenfestStationaryDist_z( ElDistMatrix_z PInf, ElInt n )

.. c:function:: ElError ElEhrenfestDecay_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElEhrenfestDecay_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElEhrenfestDecay_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElEhrenfestDecay_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElEhrenfestDecayDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElEhrenfestDecayDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElEhrenfestDecayDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElEhrenfestDecayDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Ehrenfest(P,n)
.. py:function:: EhrenfestStationary(PInf,n)
.. py:function:: EhrenfestDecay(A,n)
