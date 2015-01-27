Least Squares
=============

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/euclidean_min/LeastSquares.cpp>`__

Given :math:`A \in \mathbb{F}^{m \times n}` and a right-hand side 
:math:`b \in \mathbb{F}^m`, a *least-squares* method solves
:math:`A x \approx b` differently depending upon whether :math:`m \ge n`.

When :math:`m \ge n`, there are at least as many constraints as degrees of freedom, and 
so a solution is sought for

.. math::

   \min_x \| A x - b \|_2

This problem is solved through the use of :cpp:func:`QR`.

When :math:`m < n`, the problem is under-constrained and a solution is sought for the
problem

.. math::

   \min_x \| x \|_2 \;\;\; \text{such that } A x = b.

This problem is solved through the use of :cpp:func:`LQ`.

The above optimization problems can be readily generalized to multiple 
right-hand sides by switching to Frobenius norms. 

.. note::

   If `orientation` is set to ``NORMAL``, then solve :math:`AX=B`, otherwise 
   `orientation` must be equal to ``ADJOINT`` and :math:`A^H X=B` will 
   be solved. Upon completion, :math:`A` is overwritten with its QR or LQ 
   factorization, and each column of :math:`X` is overwritten with a solution 
   vector.

C++ API
-------
.. cpp:function:: void LeastSquares( Orientation orientation, Matrix<F>& A, const Matrix<F>& B, Matrix<F>& X )
.. cpp:function:: void LeastSquares( Orientation orientation, AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& X )

C API
-----
.. c:function:: ElError ElLeastSquares_s( ElOrientation orientation, ElMatrix_s A, ElConstMatrix_s B, ElMatrix_s X )
.. c:function:: ElError ElLeastSquares_d( ElOrientation orientation, ElMatrix_d A, ElConstMatrix_d B, ElMatrix_d X )
.. c:function:: ElError ElLeastSquares_c( ElOrientation orientation, ElMatrix_c A, ElConstMatrix_c B, ElMatrix_c X )
.. c:function:: ElError ElLeastSquares_z( ElOrientation orientation, ElMatrix_z A, ElConstMatrix_z B, ElMatrix_z X )
.. c:function:: ElError ElLeastSquaresDist_s( ElOrientation orientation, ElDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s X )
.. c:function:: ElError ElLeastSquaresDist_d( ElOrientation orientation, ElDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d X )
.. c:function:: ElError ElLeastSquaresDist_c( ElOrientation orientation, ElDistMatrix_c A, ElConstDistMatrix_c B, ElDistMatrix_c X )
.. c:function:: ElError ElLeastSquaresDist_z( ElOrientation orientation, ElDistMatrix_z A, ElConstDistMatrix_z B, ElDistMatrix_z X )

Python API
----------
.. py:function:: LeastSquares(A,B,orient=NORMAL)
