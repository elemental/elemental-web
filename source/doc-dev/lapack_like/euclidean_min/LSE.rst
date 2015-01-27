Equality-constrained Least Squares
==================================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/euclidean_min/LSE.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/LSE.cpp>`__

.. math::

   \min_X \| A X - C \|_F \;\;\; \text{subject to } B X = D.

C++ API
-------
.. cpp:function:: void LSE( Matrix<F>& A, Matrix<F>& B, Matrix<F>& C, Matrix<F>& D, Matrix<F>& X, bool computeResidual=false )
.. cpp:function:: void LSE( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& X, bool computeResidual=false )

C API
-----
.. c:function:: ElError ElLSE_s( ElMatrix_s A, ElMatrix_s B, ElMatrix_s C, ElMatrix_s D, ElMatrix_s X )
.. c:function:: ElError ElLSE_d( ElMatrix_d A, ElMatrix_d B, ElMatrix_d C, ElMatrix_d D, ElMatrix_d X )
.. c:function:: ElError ElLSE_c( ElMatrix_c A, ElMatrix_c B, ElMatrix_c C, ElMatrix_c D, ElMatrix_c X )
.. c:function:: ElError ElLSE_z( ElMatrix_z A, ElMatrix_z B, ElMatrix_z C, ElMatrix_z D, ElMatrix_z X )
.. c:function:: ElError ElLSEDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s C, ElDistMatrix_s D, ElDistMatrix_s X )
.. c:function:: ElError ElLSEDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d C, ElDistMatrix_d D, ElDistMatrix_d X )
.. c:function:: ElError ElLSEDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_c C, ElDistMatrix_c D, ElDistMatrix_c X )
.. c:function:: ElError ElLSEDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_z C, ElDistMatrix_z D, ElDistMatrix_z X )

Python API
----------
.. py:function:: LSE(A,B,C,D)
