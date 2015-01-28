DiagonalScale
=============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`X := \mbox{op}(D) X` or :math:`X := X \mbox{op}(D)`, 
where :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, where
:math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

C++ API
-------
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const Matrix<TDiag>& d, Matrix<T>& X )
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<TDiag>& d, AbstractDistMatrix<T>& X )
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const Matrix<TDiag>& d, SparseMatrix<T>& X )
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const DistMultiVec<TDiag>& d, DistSparseMatrix<T>& X )
.. cpp:function:: void DiagonalScale( Orientation orientation, const DistMultiVec<TDiag>& d, DistMultiVec<T>& X )

C API
-----
.. c:function:: ElError ElDiagonalScale_i( ElLeftOrRight side, ElConstMatrix_i d, ElMatrix_i X )
.. c:function:: ElError ElDiagonalScale_s( ElLeftOrRight side, ElConstMatrix_s d, ElMatrix_s X )
.. c:function:: ElError ElDiagonalScale_d( ElLeftOrRight side, ElConstMatrix_d d, ElMatrix_d X )
.. c:function:: ElError ElDiagonalScale_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X )
.. c:function:: ElError ElDiagonalScale_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X )

.. c:function:: ElError ElDiagonalScaleDist_i( ElLeftOrRight side, ElConstDistMatrix_i d, ElDistMatrix_i X )
.. c:function:: ElError ElDiagonalScaleDist_s( ElLeftOrRight side, ElConstDistMatrix_s d, ElDistMatrix_s X )
.. c:function:: ElError ElDiagonalScaleDist_d( ElLeftOrRight side, ElConstDistMatrix_d d, ElDistMatrix_d X )
.. c:function:: ElError ElDiagonalScaleDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c d, ElDistMatrix_c X )
.. c:function:: ElError ElDiagonalScaleDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z d, ElDistMatrix_z X )

.. c:function:: ElError ElDiagonalScaleSparse_i( ElLeftOrRight side, ElConstMatrix_i d, ElSparseMatrix_i X )
.. c:function:: ElError ElDiagonalScaleSparse_s( ElLeftOrRight side, ElConstMatrix_s d, ElSparseMatrix_s X )
.. c:function:: ElError ElDiagonalScaleSparse_d( ElLeftOrRight side, ElConstMatrix_d d, ElSparseMatrix_d X )
.. c:function:: ElError ElDiagonalScaleSparse_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElSparseMatrix_c X )
.. c:function:: ElError ElDiagonalScaleSparse_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElSparseMatrix_z X )

.. c:function:: ElError ElDiagonalScaleDistSparse_i( ElLeftOrRight side, ElConstDistMultiVec_i d, ElDistSparseMatrix_i X )
.. c:function:: ElError ElDiagonalScaleDistSparse_s( ElLeftOrRight side, ElConstDistMultiVec_s d, ElDistSparseMatrix_s X )
.. c:function:: ElError ElDiagonalScaleDistSparse_d( ElLeftOrRight side, ElConstDistMultiVec_d d, ElDistSparseMatrix_d X )
.. c:function:: ElError ElDiagonalScaleDistSparse_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMultiVec_c d, ElDistSparseMatrix_c X )
.. c:function:: ElError ElDiagonalScaleDistSparse_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMultiVec_z d, ElDistSparseMatrix_z X )

Python API
----------
.. py:function:: DiagonalScale(side,orient,d,X)
