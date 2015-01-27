Control theory
**************

The following rudimentary algorithms draw heavily from the second chapter of 
Nicholas J. Higham's "Functions of Matrices: Theory and Computation" and depend
heavily on the matrix sign function. They have only undergone cursory testing
and primarily exist due to the simplicity of their implementation. Ideally,
there will eventually be high-performance implementations based upon Schur 
decompositions.

Sylvester
---------
As long as both :math:`A` and :math:`B` only have eigenvalues in the open 
right-half plane, the following routines solve for :math:`X` in the *Sylvester
equation*

.. math::

   A X + X B = C

via computing :math:`\text{sgn}(W)`, where

.. math::

   W = \begin{pmatrix} A & -C \\ 0 & -B \end{pmatrix}.

C++ API
^^^^^^^

.. cpp:function:: void Sylvester( const Matrix<F>& A, const Matrix<F>& B, const Matrix<F>& C, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sylvester( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& B, const AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions where the individual matrices are passed in

.. cpp:function:: void Sylvester( int m, Matrix<F>& W, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Sylvester( int m, AbstractDistMatrix<F>& W, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which saves space by accepting the preformed :math:`W` matrix

C API
^^^^^

.. c:function:: ElError ElSylvester_s( ElConstMatrix_s A, ElConstMatrix_s B, ElConstMatrix_s C, ElMatrix_s X )
.. c:function:: ElError ElSylvester_d( ElConstMatrix_d A, ElConstMatrix_d B, ElConstMatrix_d C, ElMatrix_d X )
.. c:function:: ElError ElSylvester_c( ElConstMatrix_c A, ElConstMatrix_c B, ElConstMatrix_c C, ElMatrix_c X )
.. c:function:: ElError ElSylvester_z( ElConstMatrix_z A, ElConstMatrix_z B, ElConstMatrix_z C, ElMatrix_z X )
.. c:function:: ElError ElSylvesterDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElConstDistMatrix_s C, ElDistMatrix_s X )
.. c:function:: ElError ElSylvesterDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElConstDistMatrix_d C, ElDistMatrix_d X )
.. c:function:: ElError ElSylvesterDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElConstDistMatrix_c C, ElDistMatrix_c X )
.. c:function:: ElError ElSylvesterDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElConstDistMatrix_z C, ElDistMatrix_z X )

   Versions where the individual matrices are passed in

.. c:function:: ElError ElSylvesterPreformed_s( ElInt m, ElMatrix_s W, ElMatrix_s X )
.. c:function:: ElError ElSylvesterPreformed_d( ElInt m, ElMatrix_d W, ElMatrix_d X )
.. c:function:: ElError ElSylvesterPreformed_c( ElInt m, ElMatrix_c W, ElMatrix_c X )
.. c:function:: ElError ElSylvesterPreformed_z( ElInt m, ElMatrix_z W, ElMatrix_z X )
.. c:function:: ElError ElSylvesterPreformedDist_s( ElInt m, ElMatrix_s W, ElMatrix_s X )
.. c:function:: ElError ElSylvesterPreformedDist_d( ElInt m, ElMatrix_d W, ElMatrix_d X )
.. c:function:: ElError ElSylvesterPreformedDist_c( ElInt m, ElMatrix_c W, ElMatrix_c X )
.. c:function:: ElError ElSylvesterPreformedDist_z( ElInt m, ElMatrix_z W, ElMatrix_z X )

   Versions which save memory by accepting the preformed :math:`W` matrix

Lyapunov
--------
A special case of the Sylvester solver, where :math:`B = A^H`.

.. note::

   If minimizing memory usage is of importance, then the "preformed" Sylvester
   interface should be used instead.

C++ API
^^^^^^^

.. cpp:function:: void Lyapunov( const Matrix<F>& A, const Matrix<F>& C, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Lyapunov( const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& C, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElLyapunov_s( ElConstMatrix_s A, ElConstMatrix_s C, ElMatrix_s X )
.. c:function:: ElError ElLyapunov_d( ElConstMatrix_d A, ElConstMatrix_d C, ElMatrix_d X )
.. c:function:: ElError ElLyapunov_c( ElConstMatrix_c A, ElConstMatrix_c C, ElMatrix_c X )
.. c:function:: ElError ElLyapunov_z( ElConstMatrix_z A, ElConstMatrix_z C, ElMatrix_z X )
.. c:function:: ElError ElLyapunovDist_s( ElConstDistMatrix_s A, ElConstDistMatrix_s C, ElDistMatrix_s X )
.. c:function:: ElError ElLyapunovDist_d( ElConstDistMatrix_d A, ElConstDistMatrix_d C, ElDistMatrix_d X )
.. c:function:: ElError ElLyapunovDist_c( ElConstDistMatrix_c A, ElConstDistMatrix_c C, ElDistMatrix_c X )
.. c:function:: ElError ElLyapunovDist_z( ElConstDistMatrix_z A, ElConstDistMatrix_z C, ElDistMatrix_z X )

.. note::

   An "expert" C interface needs to be added and documented.

Algebraic Ricatti
-----------------
Under suitable conditions, the following routines solve for :math:`X` in the 
*algebraic Ricatti equation*

.. math::

   X K X - A^H X - X A = L,

where both :math:`K` and :math:`L` are Hermitian. 

C++ API
^^^^^^^

.. cpp:function:: void Ricatti( UpperOrLower uplo, const Matrix<F>& A, const Matrix<F>& K, const Matrix<F>& L, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Ricatti( UpperOrLower uplo, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& K, const AbstractDistMatrix<F>& L, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which accept the individual matrices

.. cpp:function:: void Ricatti( Matrix<F>& W, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Ricatti( AbstractDistMatrix<F>& W, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which save memory by directly accepting the preformed :math:`W`
   matrix

C API
^^^^^

.. c:function:: ElError ElRicatti_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElConstMatrix_s K, ElConstMatrix_s L, ElMatrix_s X )
.. c:function:: ElError ElRicatti_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElConstMatrix_d K, ElConstMatrix_d L, ElMatrix_d X )
.. c:function:: ElError ElRicatti_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElConstMatrix_c K, ElConstMatrix_c L, ElMatrix_c X )
.. c:function:: ElError ElRicatti_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElConstMatrix_z K, ElConstMatrix_z L, ElMatrix_z X )
.. c:function:: ElError ElRicattiDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElConstDistMatrix_s K, ElConstDistMatrix_s L, ElDistMatrix_s X )
.. c:function:: ElError ElRicattiDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElConstDistMatrix_d K, ElConstDistMatrix_d L, ElDistMatrix_d X )
.. c:function:: ElError ElRicattiDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElConstDistMatrix_c K, ElConstDistMatrix_c L, ElDistMatrix_c X )
.. c:function:: ElError ElRicattiDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElConstDistMatrix_z K, ElConstDistMatrix_z L, ElDistMatrix_z X )

   Versions which accept the individual matrices

.. c:function:: ElError ElRicattiPreformed_s( ElMatrix_s W, ElMatrix_s X )
.. c:function:: ElError ElRicattiPreformed_d( ElMatrix_d W, ElMatrix_d X )
.. c:function:: ElError ElRicattiPreformed_c( ElMatrix_c W, ElMatrix_c X )
.. c:function:: ElError ElRicattiPreformed_z( ElMatrix_z W, ElMatrix_z X )
.. c:function:: ElError ElRicattiPreformedDist_s( ElDistMatrix_s W, ElDistMatrix_s X )
.. c:function:: ElError ElRicattiPreformedDist_d( ElDistMatrix_d W, ElDistMatrix_d X )
.. c:function:: ElError ElRicattiPreformedDist_c( ElDistMatrix_c W, ElDistMatrix_c X )
.. c:function:: ElError ElRicattiPreformedDist_z( ElDistMatrix_z W, ElDistMatrix_z X )

   Versions which accept the preformed :math:`W` matrix
