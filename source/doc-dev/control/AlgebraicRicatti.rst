Algebraic Ricatti
=================
Under suitable conditions, the following routines solve for :math:`X` in the 
*algebraic Ricatti equation*

.. math::

   X K X - A^H X - X A = L,

where both :math:`K` and :math:`L` are Hermitian. 

Python API
----------
**TODO**

C++ API
-------

.. cpp:function:: void Ricatti( UpperOrLower uplo, const Matrix<F>& A, const Matrix<F>& K, const Matrix<F>& L, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Ricatti( UpperOrLower uplo, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& K, const AbstractDistMatrix<F>& L, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which accept the individual matrices

.. cpp:function:: void Ricatti( Matrix<F>& W, Matrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )
.. cpp:function:: void Ricatti( AbstractDistMatrix<F>& W, AbstractDistMatrix<F>& X, SignCtrl<Base<F>> signCtrl=SignCtrl<Base<F>>() )

   Versions which save memory by directly accepting the preformed :math:`W`
   matrix

C API
-----

Single-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRicatti_s( ElUpperOrLower uplo, ElConstMatrix_s A, ElConstMatrix_s K, ElConstMatrix_s L, ElMatrix_s X )
.. c:function:: ElError ElRicattiDist_s( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElConstDistMatrix_s K, ElConstDistMatrix_s L, ElDistMatrix_s X )

   Versions which accept the individual matrices

.. c:function:: ElError ElRicattiPreformed_s( ElMatrix_s W, ElMatrix_s X )
.. c:function:: ElError ElRicattiPreformedDist_s( ElDistMatrix_s W, ElDistMatrix_s X )

   Versions which accept the preformed :math:`W` matrix

Double-precision
^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRicatti_d( ElUpperOrLower uplo, ElConstMatrix_d A, ElConstMatrix_d K, ElConstMatrix_d L, ElMatrix_d X )
.. c:function:: ElError ElRicattiDist_d( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElConstDistMatrix_d K, ElConstDistMatrix_d L, ElDistMatrix_d X )

   Versions which accept the individual matrices

.. c:function:: ElError ElRicattiPreformed_d( ElMatrix_d W, ElMatrix_d X )
.. c:function:: ElError ElRicattiPreformedDist_d( ElDistMatrix_d W, ElDistMatrix_d X )

   Versions which accept the preformed :math:`W` matrix

Single-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRicatti_c( ElUpperOrLower uplo, ElConstMatrix_c A, ElConstMatrix_c K, ElConstMatrix_c L, ElMatrix_c X )
.. c:function:: ElError ElRicattiDist_c( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElConstDistMatrix_c K, ElConstDistMatrix_c L, ElDistMatrix_c X )

   Versions which accept the individual matrices

.. c:function:: ElError ElRicattiPreformed_c( ElMatrix_c W, ElMatrix_c X )
.. c:function:: ElError ElRicattiPreformedDist_c( ElDistMatrix_c W, ElDistMatrix_c X )

   Versions which accept the preformed :math:`W` matrix

Double-precision complex
^^^^^^^^^^^^^^^^^^^^^^^^
.. c:function:: ElError ElRicatti_z( ElUpperOrLower uplo, ElConstMatrix_z A, ElConstMatrix_z K, ElConstMatrix_z L, ElMatrix_z X )
.. c:function:: ElError ElRicattiDist_z( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElConstDistMatrix_z K, ElConstDistMatrix_z L, ElDistMatrix_z X )

   Versions which accept the individual matrices

.. c:function:: ElError ElRicattiPreformed_z( ElMatrix_z W, ElMatrix_z X )
.. c:function:: ElError ElRicattiPreformedDist_z( ElDistMatrix_z W, ElDistMatrix_z X )

   Versions which accept the preformed :math:`W` matrix
