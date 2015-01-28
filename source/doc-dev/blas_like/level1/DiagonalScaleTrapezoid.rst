DiagonalScaleTrapezoid
======================
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`A := \mbox{op}(D) A` or :math:`A := A \mbox{op}(D)`, 
where :math:`A` is trapezoidal (upper or lower with the boundary diagonal 
of given offset), :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, 
where :math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

C++ API
-------
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<TDiag>& d, Matrix<T>& A, Int offset=0 )
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<TDiag>& d, AbstractDistMatrix<T>& A, Int offset=0 )
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<TDiag>& d, SparseMatrix<T>& A, Int offset=0 )
.. cpp:function:: void DiagonalScaleTrapezoid( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const DistMultiVec<TDiag>& d, DistSparseMatrix<T>& A, Int offset=0 )

C API
-----
.. c:function:: ElError ElDiagonalScaleTrapezoid_i( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_i d, ElMatrix_i X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_s( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_s d, ElMatrix_s X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_d( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_d d, ElMatrix_d X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoid_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X, ElInt offset )

.. c:function:: ElError ElDiagonalScaleTrapezoidDist_i( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMatrix_i d, ElDistMatrix_i X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMatrix_s d, ElDistMatrix_s X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMatrix_d d, ElDistMatrix_d X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c d, ElDistMatrix_c X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z d, ElDistMatrix_z X, ElInt offset )

.. c:function:: ElError ElDiagonalScaleTrapezoidSparse_i( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_i d, ElSparseMatrix_i X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidSparse_s( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_s d, ElSparseMatrix_s X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidSparse_d( ElLeftOrRight side, ElUpperOrLower uplo, ElConstMatrix_d d, ElSparseMatrix_d X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidSparse_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c d, ElSparseMatrix_c X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidSparse_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z d, ElSparseMatrix_z X, ElInt offset )

.. c:function:: ElError ElDiagonalScaleTrapezoidDistSparse_i( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMultiVec_i d, ElDistSparseMatrix_i X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDistSparse_s( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMultiVec_s d, ElDistSparseMatrix_s X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDistSparse_d( ElLeftOrRight side, ElUpperOrLower uplo, ElConstDistMultiVec_d d, ElDistSparseMatrix_d X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDistSparse_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMultiVec_c d, ElDistSparseMatrix_c X, ElInt offset )
.. c:function:: ElError ElDiagonalScaleTrapezoidDistSparse_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMultiVec_z d, ElDistSparseMatrix_z X, ElInt offset )

Python API
----------
.. py:function:: DiagonalScaleTrapezoid(side,uplo,d,X,offset=0)
