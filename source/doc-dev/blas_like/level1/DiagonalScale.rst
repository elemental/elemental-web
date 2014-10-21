DiagonalScale
=============
.. note::

   This is not a standard BLAS routine, but it is BLAS-like.

Performs either :math:`X := \mbox{op}(D) X` or :math:`X := X \mbox{op}(D)`, 
where :math:`op(D)` equals :math:`D=D^T`, or :math:`D^H=\bar D`, where
:math:`D = \mbox{diag}(d)` and :math:`d` is a column vector.

C++ API
-------

.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const Matrix<T>& d, Matrix<T>& X )
.. cpp:function:: void DiagonalScale( LeftOrRight side, Orientation orientation, const AbstractDistMatrix<T>& d, AbstractDistMatrix<T>& X )

C API
-----

.. c:function:: ElError ElDiagonalScale_i( ElLeftOrRight side, ElConstMatrix_i d, ElMatrix_i X )
.. c:function:: ElError ElDiagonalScale_s( ElLeftOrRight side, ElConstMatrix_s d, ElMatrix_s X )
.. c:function:: ElError ElDiagonalScale_d( ElLeftOrRight side, ElConstMatrix_d d, ElMatrix_d X )
.. c:function:: ElError ElDiagonalScale_c( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_c d, ElMatrix_c X )
.. c:function:: ElError ElDiagonalScale_z( ElLeftOrRight side, ElOrientation orientation, ElConstMatrix_z d, ElMatrix_z X )

Python API
----------

.. py:function:: DiagonalScale(side,d,X)
