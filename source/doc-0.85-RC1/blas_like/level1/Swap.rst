Swap
====

Entire matrices
---------------
The following routines replace :math:`A` and :math:`B` with each other, 
their transpose, or their adjoint.

C++ API
^^^^^^^

.. cpp:function:: void Swap( Orientation orientation, Matrix<T>& A, Matrix<T>& B )
.. cpp:function:: void Swap( Orientation orientation, AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B )

C API
^^^^^

.. c:function:: ElError ElSwap_i( ElOrientation orientation, ElMatrix_i X, ElMatrix_i Y )
.. c:function:: ElError ElSwap_s( ElOrientation orientation, ElMatrix_s X, ElMatrix_s Y )
.. c:function:: ElError ElSwap_d( ElOrientation orientation, ElMatrix_d X, ElMatrix_d Y )
.. c:function:: ElError ElSwap_c( ElOrientation orientation, ElMatrix_c X, ElMatrix_c Y )
.. c:function:: ElError ElSwap_z( ElOrientation orientation, ElMatrix_z X, ElMatrix_z Y )
.. c:function:: ElError ElSwapDist_i( ElOrientation orientation, ElDistMatrix_i X, ElDistMatrix_i Y )
.. c:function:: ElError ElSwapDist_s( ElOrientation orientation, ElDistMatrix_s X, ElDistMatrix_s Y )
.. c:function:: ElError ElSwapDist_d( ElOrientation orientation, ElDistMatrix_d X, ElDistMatrix_d Y )
.. c:function:: ElError ElSwapDist_c( ElOrientation orientation, ElDistMatrix_c X, ElDistMatrix_c Y )
.. c:function:: ElError ElSwapDist_z( ElOrientation orientation, ElDistMatrix_z X, ElDistMatrix_z Y )

Pairs of rows
-------------
Swap rows `to` and `from` in the matrix.

C++ API
^^^^^^^

.. cpp:function:: void RowSwap( Matrix<T>& A, Int to, Int from )
.. cpp:function:: void RowSwap( AbstractDistMatrix<T>& A, Int to, Int from )

C API
^^^^^

.. c:function:: ElError ElRowSwap_i( ElMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwap_s( ElMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwap_d( ElMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwap_c( ElMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwap_z( ElMatrix_z A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwapDist_i( ElDistMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwapDist_s( ElDistMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwapDist_d( ElDistMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwapDist_c( ElDistMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElRowSwapDist_z( ElDistMatrix_z A, ElInt to, ElInt from )

Pairs of columns
----------------
Swap columns `to` and `from` in the matrix.

C++ API
^^^^^^^

.. cpp:function:: void ColSwap( Matrix<T>& A, Int to, Int from )
.. cpp:function:: void ColSwap( AbstractDistMatrix<T>& A, Int to, Int from )

C API
^^^^^

.. c:function:: ElError ElColSwap_i( ElMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwap_s( ElMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwap_d( ElMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwap_c( ElMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwap_z( ElMatrix_z A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwapDist_i( ElDistMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwapDist_s( ElDistMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwapDist_d( ElDistMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwapDist_c( ElDistMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElColSwapDist_z( ElDistMatrix_z A, ElInt to, ElInt from )

Symmetric/Hermitian swap
------------------------
Symmetrically permute the `to` and `from` degrees of freedom within the 
implicitly symmetric (Hermitian) matrix :math:`A` which stores its data
in the specified triangle.

C++ API
^^^^^^^

.. cpp:function:: void SymmetricSwap( UpperOrLower uplo, Matrix<T>& A, Int to, Int from, bool conjugate=false )
.. cpp:function:: void SymmetricSwap( UpperOrLower uplo, AbstractDistMatrix<T>& A, Int to, Int from, bool conjugate=false )

.. cpp:function:: void HermitianSwap( UpperOrLower uplo, Matrix<T>& A, Int to, Int from )
.. cpp:function:: void HermitianSwap( UpperOrLower uplo, AbstractDistMatrix<T>& A, Int to, Int from )

C API
^^^^^

.. c:function:: ElError ElSymmetricSwap_i( ElUpperOrLower uplo, ElMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwap_s( ElUpperOrLower uplo, ElMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwap_d( ElUpperOrLower uplo, ElMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwap_c( ElUpperOrLower uplo, ElMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwap_z( ElUpperOrLower uplo, ElMatrix_z A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwapDist_i( ElUpperOrLower uplo, ElDistMatrix_i A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwapDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwapDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwapDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElSymmetricSwapDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt to, ElInt from )

.. c:function:: ElError ElHermitianSwap_c( ElUpperOrLower uplo, ElMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElHermitianSwap_z( ElUpperOrLower uplo, ElMatrix_z A, ElInt to, ElInt from )
.. c:function:: ElError ElHermitianSwapDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt to, ElInt from )
.. c:function:: ElError ElHermitianSwapDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt to, ElInt from )
