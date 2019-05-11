General
=======
This routine computes the in-place inverse of a general fully-populated
(invertible) matrix :math:`A` as

.. math::

   A^{-1} = U^{-1} L^{-1} P,

where :math:`PA=LU` is the result of LU factorization with partial pivoting.
The algorithm essentially factors :math:`A`, inverts :math:`U` in place,
solves against :math:`L` one block column at a time, and then applies the
row pivots in reverse order to the columns of the result.

Python API
----------
.. py:function:: Inverse(A)

C++ API
-------
.. cpp:function:: void Inverse( Matrix<F>& A )
.. cpp:function:: void Inverse( AbstractDistMatrix<F>& A )

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElInverse_s( ElMatrix_s A )
.. c:function:: ElError ElInverseDist_s( ElDistMatrix_s A )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElInverse_d( ElMatrix_d A )
.. c:function:: ElError ElInverseDist_d( ElDistMatrix_d A )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElInverse_c( ElMatrix_c A )
.. c:function:: ElError ElInverseDist_c( ElDistMatrix_c A )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElInverse_z( ElMatrix_z A )
.. c:function:: ElError ElInverseDist_z( ElDistMatrix_z A )
