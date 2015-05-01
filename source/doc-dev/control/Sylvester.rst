Sylvester
=========
As long as both :math:`A` and :math:`B` only have eigenvalues in the open 
right-half plane, the following routines solve for :math:`X` in the *Sylvester
equation*

.. math::

   A X + X B = C

via computing :math:`\text{sgn}(W)`, where

.. math::

   W = \begin{pmatrix} A & -C \\ 0 & -B \end{pmatrix}.

Python API
----------
**TODO**

C++ API
-------

.. cpp:function:: void Sylvester( const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& C, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sylvester( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions where the individual matrices are passed in

.. cpp:function:: void Sylvester( int m, Matrix<F>& W, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sylvester( int m, AbstractDistMatrix<F>& W, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which saves space by accepting the preformed :math:`W` matrix

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSylvester_s( ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s C, ElMatrix_s X )
.. c:function:: ElError ElSylvesterDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s C, ElDistMatrix_s X )

   Versions where the individual matrices are passed in

.. c:function:: ElError ElSylvesterPreformed_s( ElInt m, ElMatrix_s W, ElMatrix_s X )
.. c:function:: ElError ElSylvesterPreformedDist_s( ElInt m, ElMatrix_s W, ElMatrix_s X )

   Versions which save memory by accepting the preformed :math:`W` matrix

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSylvester_d( ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d C, ElMatrix_d X )
.. c:function:: ElError ElSylvesterDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d C, ElDistMatrix_d X )

   Versions where the individual matrices are passed in

.. c:function:: ElError ElSylvesterPreformed_d( ElInt m, ElMatrix_d W, ElMatrix_d X )
.. c:function:: ElError ElSylvesterPreformedDist_d( ElInt m, ElMatrix_d W, ElMatrix_d X )

   Versions which save memory by accepting the preformed :math:`W` matrix

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSylvester_c( ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c C, ElMatrix_c X )
.. c:function:: ElError ElSylvesterDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c C, ElDistMatrix_c X )

   Versions where the individual matrices are passed in

.. c:function:: ElError ElSylvesterPreformed_c( ElInt m, ElMatrix_c W, ElMatrix_c X )
.. c:function:: ElError ElSylvesterPreformedDist_c( ElInt m, ElMatrix_c W, ElMatrix_c X )

   Versions which save memory by accepting the preformed :math:`W` matrix

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElSylvester_z( ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z C, ElMatrix_z X )
.. c:function:: ElError ElSylvesterDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z C, ElDistMatrix_z X )

   Versions where the individual matrices are passed in

.. c:function:: ElError ElSylvesterPreformed_z( ElInt m, ElMatrix_z W, ElMatrix_z X )
.. c:function:: ElError ElSylvesterPreformedDist_z( ElInt m, ElMatrix_z W, ElMatrix_z X )

   Versions which save memory by accepting the preformed :math:`W` matrix

