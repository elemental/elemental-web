Square to Hessenberg
====================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/condense/Hessenberg.cpp>`__

`Subroutine header files <https://github.com/elemental/Elemental/tree/master/src/lapack_like/condense/Hessenberg>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/Hessenberg.cpp>`__

Reduction
---------

C++ API
^^^^^^^

.. cpp:function:: void Hessenberg( UpperOrLower uplo, Matrix<F>& A, Matrix<F>& t )
.. cpp:function:: void Hessenberg( UpperOrLower uplo, AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. cpp:function:: void hessenberg::ExplicitCondensed( UpperOrLower uplo, Matrix<F>& A )
.. cpp:function:: void hessenberg::ExplicitCondensed( UpperOrLower uplo, AbstractDistMatrix<F>& A )

    Return just the Hessenberg matrix.

C API
^^^^^

.. c:function:: ElError ElHessenberg_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s t )
.. c:function:: ElError ElHessenberg_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d t )
.. c:function:: ElError ElHessenberg_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c t )
.. c:function:: ElError ElHessenberg_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z t )
.. c:function:: ElError ElHessenbergDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t )
.. c:function:: ElError ElHessenbergDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t )
.. c:function:: ElError ElHessenbergDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t )
.. c:function:: ElError ElHessenbergDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. c:function:: ElError ElHessenbergExplicitCondensed_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHessenbergExplicitCondensed_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHessenbergExplicitCondensed_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHessenbergExplicitCondensed_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

    Return just the Hessenberg matrix.

Applying the change of basis
----------------------------

C++ API
^^^^^^^

.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& H )
.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& H )

C API
^^^^^

.. c:function:: ElError ElApplyQAfterHessenberg_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElMatrix_s H )
.. c:function:: ElError ElApplyQAfterHessenberg_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d H )
.. c:function:: ElError ElApplyQAfterHessenberg_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c H )
.. c:function:: ElError ElApplyQAfterHessenberg_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElDistMatrix_s H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z H )
