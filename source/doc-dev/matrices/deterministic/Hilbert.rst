Hilbert
=======
The Hilbert matrix of order :math:`n` is the :math:`n \times n` matrix where

.. math::

   A(i,j) = \frac{1}{i+j+1}.

C++ API
-------

.. cpp:function:: void Hilbert( Matrix<F>& A, Int n )
.. cpp:function:: void Hilbert( AbstractDistMatrix<F>& A, Int n )

C API
-----

.. c:function:: ElError ElHilbert_s( ElMatrix_s A, ElInt n )
.. c:function:: ElError ElHilbert_d( ElMatrix_d A, ElInt n )
.. c:function:: ElError ElHilbert_c( ElMatrix_c A, ElInt n )
.. c:function:: ElError ElHilbert_z( ElMatrix_z A, ElInt n )
.. c:function:: ElError ElHilbertDist_s( ElDistMatrix_s A, ElInt n )
.. c:function:: ElError ElHilbertDist_d( ElDistMatrix_d A, ElInt n )
.. c:function:: ElError ElHilbertDist_c( ElDistMatrix_c A, ElInt n )
.. c:function:: ElError ElHilbertDist_z( ElDistMatrix_z A, ElInt n )

Python API
----------

.. py:function:: Hilbert(A,n)
