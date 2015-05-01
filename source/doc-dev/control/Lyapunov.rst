Lyapunov
========
A special case of the Sylvester solver, where :math:`B = A^H`.

.. note::

   If minimizing memory usage is of importance, then the "preformed" Sylvester
   interface should be used instead.

Python API
----------
**TODO**

C++ API
-------

.. cpp:function:: void Lyapunov( const Matrix<F>& A, const Matrix<F>& C, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Lyapunov( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

C API
-----
.. note::

   An "expert" C interface needs to be added and documented.

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElLyapunov_s( ElConstMatrix_s A, ElConstMatrix_s C, ElMatrix_s X )
.. c:function:: ElError ElLyapunovDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s C, ElDistMatrix_s X )

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElLyapunov_d( ElConstMatrix_d A, ElConstMatrix_d C, ElMatrix_d X )
.. c:function:: ElError ElLyapunovDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d C, ElDistMatrix_d X )

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElLyapunov_c( ElConstMatrix_c A, ElConstMatrix_c C, ElMatrix_c X )
.. c:function:: ElError ElLyapunovDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c C, ElDistMatrix_c X )

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElLyapunov_z( ElConstMatrix_z A, ElConstMatrix_z C, ElMatrix_z X )
.. c:function:: ElError ElLyapunovDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z C, ElDistMatrix_z X )

