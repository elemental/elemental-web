Square to Hessenberg
====================

Reduction
---------
Elemental's algorithms for reducing square matrices to Hessenberg form via
products of Householder similarity transformations are straight-forward 
parallelizations (and extensions to the complex field) of an algorithm 
described within [QvdG2006]_, which can be viewed as a modification of the 
corresponding algorithm from [DSH1989]_ which shifts some of the work from 
level 2 to level 3 BLAS.

Python API
^^^^^^^^^^
.. py:function:: Hessenberg(uplo,A[,hessOnly=False])

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

Single-precision
""""""""""""""""
.. c:function:: ElError ElHessenberg_s( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s t )
.. c:function:: ElError ElHessenbergDist_s( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. c:function:: ElError ElHessenbergExplicitCondensed_s( ElUpperOrLower uplo, ElMatrix_s A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_s( ElUpperOrLower uplo, ElDistMatrix_s A )

    Return just the Hessenberg matrix.

Double-precision
""""""""""""""""
.. c:function:: ElError ElHessenberg_d( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d t )
.. c:function:: ElError ElHessenbergDist_d( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. c:function:: ElError ElHessenbergExplicitCondensed_d( ElUpperOrLower uplo, ElMatrix_d A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_d( ElUpperOrLower uplo, ElDistMatrix_d A )

    Return just the Hessenberg matrix.

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElHessenberg_c( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c t )
.. c:function:: ElError ElHessenbergDist_c( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. c:function:: ElError ElHessenbergExplicitCondensed_c( ElUpperOrLower uplo, ElMatrix_c A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_c( ElUpperOrLower uplo, ElDistMatrix_c A )

    Return just the Hessenberg matrix.

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElHessenberg_z( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z t )
.. c:function:: ElError ElHessenbergDist_z( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z t )

   Return the in-place reduction of the matrix A to lower-/upper-Hessenberg
   form. The vector `t` contains the scalings for the Householder
   reflectors, which are stored in the locations of the zeros that they
   introduced.

.. c:function:: ElError ElHessenbergExplicitCondensed_z( ElUpperOrLower uplo, ElMatrix_z A )
.. c:function:: ElError ElHessenbergExplicitCondensedDist_z( ElUpperOrLower uplo, ElDistMatrix_z A )

    Return just the Hessenberg matrix.

Applying the change of basis
----------------------------

Python API
^^^^^^^^^^
.. py:function:: ApplyQAfterHessenberg(side,uplo,orient,A,t,B)

C++ API
^^^^^^^
.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, const Matrix<F>& t, Matrix<F>& H )
.. cpp:function:: void hessenberg::ApplyQ( LeftOrRight side, UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& H )

C API
^^^^^

Single-precision
""""""""""""""""
.. c:function:: ElError ElApplyQAfterHessenberg_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElConstMatrix_s t, ElMatrix_s H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_s( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElConstDistMatrix_s t, ElDistMatrix_s H )

Double-precision
""""""""""""""""
.. c:function:: ElError ElApplyQAfterHessenberg_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElConstMatrix_d t, ElMatrix_d H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_d( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElConstDistMatrix_d t, ElDistMatrix_d H )

Single-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElApplyQAfterHessenberg_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElConstMatrix_c t, ElMatrix_c H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_c( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElConstDistMatrix_c t, ElDistMatrix_c H )

Double-precision complex
""""""""""""""""""""""""
.. c:function:: ElError ElApplyQAfterHessenberg_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElConstMatrix_z t, ElMatrix_z H )
.. c:function:: ElError ElApplyQAfterHessenbergDist_z( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElConstDistMatrix_z t, ElDistMatrix_z H )

References
----------
`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/condense/Hessenberg.cpp>`__

`Subroutine header files <https://github.com/elemental/Elemental/tree/master/src/lapack_like/condense/Hessenberg>`__

`Test driver <https://github.com/elemental/Elemental/blob/master/tests/lapack_like/Hessenberg.cpp>`__

.. [DSH1989] Jack J. Dongarra, Danny C. Sorensen, and Sven J. Hammarling, *Block reduction of matrices to condensed forms for eigenvalue computations*, Journal of Computational and Applied Mathematics, Vol. 27, Issues 1--2, pp. 215--227, 1989. DOI: http://dx.doi.org/10.1016/0377-0427(89)90367-1 <http://dx.doi.org/10.1016/0377-0427(89)90367-1>`__

.. [QvdG2006] Gregorio Quintana-Orti and Robert van de Geijn, *Improving the performance of reduction to Hessenberg form*, ACM Transactions on Mathematical Software, Vol. 32, Issue 2, pp. 180--194, 2006. DOI: `http://dx.doi.org/10.1145/1141885.1141887 <http://dx.doi.org/10.1145/1141885.1141887>`__
