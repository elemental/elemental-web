Trstrm
======
Performs a triangular solve against a triangular matrix. Only the Left Lower 
Normal option is currently supported.

.. note::

   For the best performance, `A` and `B` should both be in [MC,MR] 
   distributions.

C++ API
-------

.. cpp:function:: void Trstrm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const Matrix<F>& A, Matrix<F>& X, bool checkIfSingular=true )
.. cpp:function:: void Trstrm( LeftOrRight side, UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, F alpha, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& X, bool checkIfSingular=true )

C API
-----

.. c:function:: ElError ElTrstrm_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstMatrix_s A, ElMatrix_s B )
.. c:function:: ElError ElTrstrm_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstMatrix_d A, ElMatrix_d B )
.. c:function:: ElError ElTrstrm_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstMatrix_c A, ElMatrix_c B )
.. c:function:: ElError ElTrstrm_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstMatrix_z A, ElMatrix_z B )
.. c:function:: ElError ElTrstrmDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, float alpha, ElConstDistMatrix_s A, ElDistMatrix_s B )
.. c:function:: ElError ElTrstrmDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, double alpha, ElConstDistMatrix_d A, ElDistMatrix_d B )
.. c:function:: ElError ElTrstrmDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_float alpha, ElConstDistMatrix_c A, ElDistMatrix_c B )
.. c:function:: ElError ElTrstrmDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, complex_double alpha, ElConstDistMatrix_z A, ElDistMatrix_z B )

Python API
----------

.. py:function:: Trstrm(side,uplo,orient,diag,alpha,A,X)
