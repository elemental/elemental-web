DiagonalSolve
=============
Performs either :math:`X := \mbox{op}(D)^{-1} X` or 
:math:`X := X \mbox{op}(D)^{-1}`, where :math:`D = \mbox{diag}(d)` and :math:`d`
is a column vector.

C++ API
-------
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const Matrix<FDiag>& d, Matrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<FDiag>& d, AbstractDistMatrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const Matrix<FDiag>& d, SparseMatrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const DistMultiVec<FDiag>& d, DistSparseMatrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void DiagonalSolve( Orientation orientation, const DistMultiVec<FDiag>& d, DistMultiVec<F>& X, bool checkIfSingular=true )

C API
-----
.. c:function:: ElError ElDiagonalSolve_s( ElLeftOrRight side, ElConstMatrix_s d, ElMatrix_s X )
.. c:function:: ElError ElDiagonalSolve_d( ElLeftOrRight side, ElConstMatrix_d d, ElMatrix_d X )
.. c:function:: ElError ElDiagonalSolve_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X )
.. c:function:: ElError ElDiagonalSolve_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X )

.. c:function:: ElError ElDiagonalSolveDist_s( ElLeftOrRight side, ElConstDistMatrix_s d, ElDistMatrix_s X )
.. c:function:: ElError ElDiagonalSolveDist_d( ElLeftOrRight side, ElConstDistMatrix_d d, ElDistMatrix_d X )
.. c:function:: ElError ElDiagonalSolveDist_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_c d, ElDistMatrix_c X )
.. c:function:: ElError ElDiagonalSolveDist_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMatrix_z d, ElDistMatrix_z X )

.. c:function:: ElError ElDiagonalSolveSparse_s( ElLeftOrRight side, ElConstMatrix_s d, ElSparseMatrix_s X )
.. c:function:: ElError ElDiagonalSolveSparse_d( ElLeftOrRight side, ElConstMatrix_d d, ElSparseMatrix_d X )
.. c:function:: ElError ElDiagonalSolveSparse_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElSparseMatrix_c X )
.. c:function:: ElError ElDiagonalSolveSparse_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElSparseMatrix_z X )

.. c:function:: ElError ElDiagonalSolveDistSparse_s( ElLeftOrRight side, ElConstDistMultiVec_s d, ElDistSparseMatrix_s X )
.. c:function:: ElError ElDiagonalSolveDistSparse_d( ElLeftOrRight side, ElConstDistMultiVec_d d, ElDistSparseMatrix_d X )
.. c:function:: ElError ElDiagonalSolveDistSparse_c( ElLeftOrRight side, ElOrientation orientation, ElConstDistMultiVec_c d, ElDistSparseMatrix_c X )
.. c:function:: ElError ElDiagonalSolveDistSparse_z( ElLeftOrRight side, ElOrientation orientation, ElConstDistMultiVec_z d, ElDistSparseMatrix_z X )

Python API
----------
.. py:function:: DiagonalSolve(side,orient,d,X)
