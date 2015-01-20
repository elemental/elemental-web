DiagonalSolve
=============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`X := \mbox{op}(D)^{-1} X` or 
:math:`X := X \mbox{op}(D)^{-1}`, where :math:`D = \mbox{diag}(d)` and :math:`d`
is a column vector.

C++ API
-------

.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const Matrix<F>& d, Matrix<F>& X, bool checkIfSingular=false )
.. cpp:function:: void DiagonalSolve( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<F>& d, AbstractDistMatrix<F>& X, bool checkIfSingular=false )

C API
-----

.. c:function:: ElError ElDiagonalSolve_s( ElLeftOrRight side, ElConstMatrix_s d, ElMatrix_s X )
.. c:function:: ElError ElDiagonalSolve_d( ElLeftOrRight side, ElConstMatrix_d d, ElMatrix_d X )
.. c:function:: ElError ElDiagonalSolve_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X )
.. c:function:: ElError ElDiagonalSolve_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X )

Python API
----------

.. py:function:: DiagonalSolve(side,d,X)
