Level 2
=======

The prototypes for the following routines can be found at          
`include/El/blas-like/level2.hpp <https://github.com/elemental/Elemental/tree/master/include/El/blas-like/level2.hpp>`_, while the
implementations are in `src/blas-like/level2/ <https://github.com/elemental/Elemental/tree/master/src/blas-like/level2>`_.

Gemv
----
General matrix-vector multiply:
:math:`y := \alpha \mbox{op}(A) x + \beta y`,
where :math:`\mbox{op}(A)` can be :math:`A`, :math:`A^T`, or :math:`A^H`.
Whether or not :math:`x` and :math:`y` are stored as row vectors, they will
be interpreted as column vectors.

C++ API
^^^^^^^

.. cpp:function:: void Gemv( Orientation orientation, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y )
.. cpp:function:: void Gemv( Orientation orientation, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y )

C API
^^^^^

.. c:function:: ElError ElGemv_i( ElOrientation orientation, ElInt alpha, ElConstMatrix_i A, ElConstMatrix_i x, ElInt beta, ElMatrix_i y )
.. c:function:: ElError ElGemv_s( ElOrientation orientation, float alpha, ElConstMatrix_s A, ElConstMatrix_s x, float beta, ElMatrix_s y )
.. c:function:: ElError ElGemv_d( ElOrientation orientation, double alpha, ElConstMatrix_d A, ElConstMatrix_d x, double beta, ElMatrix_d y )
.. c:function:: ElError ElGemv_c( ElOrientation orientation, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElGemv_z( ElOrientation orientation, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_z y )
.. c:function:: ElError ElGemvDist_i( ElOrientation orientation, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i x, ElInt beta, ElDistMatrix_i y )
.. c:function:: ElError ElGemvDist_s( ElOrientation orientation, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s x, float beta, ElDistMatrix_s y )
.. c:function:: ElError ElGemvDist_d( ElOrientation orientation, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d x, double beta, ElDistMatrix_d y )
.. c:function:: ElError ElGemvDist_c( ElOrientation orientation, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElGemvDist_z( ElOrientation orientation, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_z y )

Ger
---
General rank-one update: :math:`A := \alpha x y^H + A`. :math:`x` and :math:`y`
are free to be stored as either row or column vectors, but they will be 
interpreted as column vectors.

C++ API
^^^^^^^

.. cpp:function:: void Ger( T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Ger( T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
^^^^^

.. c:function:: ElError ElGer_i( ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElGer_s( float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElGer_d( double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElGer_c( complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElGer_z( complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElGerDist_i( ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElGerDist_s( float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElGerDist_d( double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElGerDist_c( complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElGerDist_z( complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

Geru
----
General rank-one update (unconjugated): :math:`A := \alpha x y^T + A`. :math:`x`
and :math:`y` are free to be stored as either row or column vectors, but they 
will be interpreted as column vectors.

C++ API
^^^^^^^

.. cpp:function:: void Geru( T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Geru( T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
^^^^^

.. c:function:: ElError ElGeru_c( complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElGeru_z( complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElGeruDist_c( complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElGeruDist_z( complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

Hemv
----
Hermitian matrix-vector multiply: :math:`y := \alpha A x + \beta y`, where 
:math:`A` is Hermitian.

Please see :cpp:func:`SetLocalSymvBlocksize\<T>` and 
:cpp:func:`LocalSymvBlocksize\<T>` in the :ref:`blas-tuning` section for 
information on tuning the distributed :cpp:func:`Hemv`.

C++ API
^^^^^^^

.. cpp:function:: void Hemv( UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y )
.. cpp:function:: void Hemv( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y )

C API
^^^^^

.. c:function:: ElError ElHemv_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElHemv_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_c y )
.. c:function:: ElError ElHemvDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElHemvDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_c y )

Her
---
Hermitian rank-one update: implicitly performs :math:`A := \alpha x x^H + A`, 
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
^^^^^^^

.. cpp:function:: void Her( UpperOrLower uplo, T alpha, const Matrix<T>& x, Matrix<T>& A )
.. cpp:function:: void Her( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, AbstractDistMatrix<T>& A )

C API
^^^^^

.. c:function:: ElError ElHer_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElMatrix_c A )
.. c:function:: ElError ElHer_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElMatrix_z A )
.. c:function:: ElError ElHerDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElDistMatrix_c A )
.. c:function:: ElError ElHerDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElDistMatrix_z A )

Her2
----
Hermitian rank-two update: implicitly performs 
:math:`A := \alpha ( x y^H + y x^H ) + A`,
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
^^^^^^^

.. cpp:function:: void Her2( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
.. cpp:function:: void Her2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A )

C API
^^^^^

.. c:function:: ElError ElHer2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElHer2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElHer2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElHer2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

QuasiTrsv
---------
*Quasi-triangular* solve with a vector: computes
:math:`x := \mbox{op}(A)^{-1} x`, where :math:`\mbox{op}(A)` is either 
:math:`A`, :math:`A^T`, or :math:`A^H`, and :math:`A` is treated an either a 
lower or upper quasi-triangular matrix, depending upon `uplo`.

Note that the term *quasi-triangular* is in the context of real Schur 
decompositions, which produce triangular matrices with mixes of 
:math:`1 \times 1` and :math:`2 \times 2` diagonal blocks.

.. note::

   There is no corresponding BLAS routine, but it is a natural extension of 
   Trsv.

.. note::

   For the best performance, both `A` and `x` should be in [MC,MR] 
   distributions.

C++ API
^^^^^^^

.. cpp:function:: void QuasiTrsv( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& x, bool checkIfSingular=false )
.. cpp:function:: void QuasiTrsv( UpperOrLower uplo, Orientation orientation, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& x, bool checkIfSingular=false )

C API
^^^^^

.. c:function:: ElError ElQuasiTrsv_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElQuasiTrsv_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElQuasiTrsv_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElQuasiTrsv_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstMatrix_z A, ElMatrix_z x )
.. c:function:: ElError ElQuasiTrsvDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_s A, ElDistMatrix_s x )
.. c:function:: ElError ElQuasiTrsvDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_d A, ElDistMatrix_d x )
.. c:function:: ElError ElQuasiTrsvDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_c A, ElDistMatrix_c x )
.. c:function:: ElError ElQuasiTrsvDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElConstDistMatrix_z A, ElDistMatrix_z x )


Symv
----
Symmetric matrix-vector multiply: :math:`y := \alpha A x + \beta y`, where 
:math:`A` is symmetric.

Please see :cpp:func:`SetLocalSymvBlocksize\<T>` and 
:cpp:func:`LocalSymvBlocksize\<T>` in the :ref:`blas-tuning` section for 
information on tuning the distributed :cpp:func:`Symv`.

C++ API
^^^^^^^

.. cpp:function:: void Symv( UpperOrLower uplo, T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y, bool conjugate=false )
.. cpp:function:: void Symv( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& A, const AbstractDistMatrix<T>& x, T beta, AbstractDistMatrix<T>& y, bool conjugate=false )

C API
^^^^^

.. c:function:: ElError ElSymv_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i A, ElConstMatrix_i x, ElInt beta, ElMatrix_i y )
.. c:function:: ElError ElSymv_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s A, ElConstMatrix_s x, float beta, ElMatrix_s y )
.. c:function:: ElError ElSymv_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d A, ElConstMatrix_d x, double beta, ElMatrix_d y )
.. c:function:: ElError ElSymv_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c A, ElConstMatrix_c x, complex_float beta, ElMatrix_c y )
.. c:function:: ElError ElSymv_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z A, ElConstMatrix_z x, complex_double beta, ElMatrix_z y )
.. c:function:: ElError ElSymvDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i A, ElConstDistMatrix_i x, ElInt beta, ElDistMatrix_i y )
.. c:function:: ElError ElSymvDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s A, ElConstDistMatrix_s x, float beta, ElDistMatrix_s y )
.. c:function:: ElError ElSymvDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d A, ElConstDistMatrix_d x, double beta, ElDistMatrix_d y )
.. c:function:: ElError ElSymvDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c A, ElConstDistMatrix_c x, complex_float beta, ElDistMatrix_c y )
.. c:function:: ElError ElSymvDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z A, ElConstDistMatrix_z x, complex_double beta, ElDistMatrix_z y )


Syr
---
Symmetric rank-one update: implicitly performs :math:`A := \alpha x x^T + A`, 
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
^^^^^^^

.. cpp:function:: void Syr( UpperOrLower uplo, T alpha, const Matrix<T>& x, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Syr( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
^^^^^

.. c:function:: ElError ElSyr_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElMatrix_i A )
.. c:function:: ElError ElSyr_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElMatrix_s A )
.. c:function:: ElError ElSyr_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElMatrix_d A )
.. c:function:: ElError ElSyr_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElMatrix_c A )
.. c:function:: ElError ElSyr_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElMatrix_z A )
.. c:function:: ElError ElSyrDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElDistMatrix_i A )
.. c:function:: ElError ElSyrDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElDistMatrix_s A )
.. c:function:: ElError ElSyrDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElDistMatrix_d A )
.. c:function:: ElError ElSyrDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElDistMatrix_c A )
.. c:function:: ElError ElSyrDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElDistMatrix_z A )

Syr2
----
Symmetric rank-two update: implicitly performs 
:math:`A := \alpha ( x y^T + y x^T ) + A`,
where only the triangle of :math:`A` specified by `uplo` is updated.

C++ API
^^^^^^^

.. cpp:function:: void Syr2( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Syr2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
^^^^^

.. c:function:: ElError ElSyr2_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElSyr2_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElSyr2_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElSyr2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElSyr2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElSyr2Dist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElSyr2Dist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElSyr2Dist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElSyr2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElSyr2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

Trmv
----

.. math::

   x := \text{tri}(A)^\sharp x

.. note::

   Distributed ``Trmv`` not yet written. Please call :cpp:func:`Trmm` for now.

C++ API
^^^^^^^

.. cpp:function:: void Trmv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const Matrix<T>& A, Matrix<T>& x )

C API
^^^^^

.. c:function:: ElError ElTrmv_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElTrmv_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElTrmv_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElTrmv_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_z A, ElMatrix_z x )

Trr
---

.. math::

   \text{tri}(A) := \text{tri}(A + \alpha x y')

C++ API
^^^^^^^

.. cpp:function:: void Trr( UpperOrLower uplo, T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Trr( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& x, const AbstractDistMatrix<T>& y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
^^^^^

.. c:function:: ElError ElTrr_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i x, ElConstMatrix_i y, ElMatrix_i A )
.. c:function:: ElError ElTrr_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s x, ElConstMatrix_s y, ElMatrix_s A )
.. c:function:: ElError ElTrr_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d x, ElConstMatrix_d y, ElMatrix_d A )
.. c:function:: ElError ElTrr_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c x, ElConstMatrix_c y, ElMatrix_c A )
.. c:function:: ElError ElTrr_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z x, ElConstMatrix_z y, ElMatrix_z A )
.. c:function:: ElError ElTrrDist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i x, ElConstDistMatrix_i y, ElDistMatrix_i A )
.. c:function:: ElError ElTrrDist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s x, ElConstDistMatrix_s y, ElDistMatrix_s A )
.. c:function:: ElError ElTrrDist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d x, ElConstDistMatrix_d y, ElDistMatrix_d A )
.. c:function:: ElError ElTrrDist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c x, ElConstDistMatrix_c y, ElDistMatrix_c A )
.. c:function:: ElError ElTrrDist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z x, ElConstDistMatrix_z y, ElDistMatrix_z A )

Trr2
----

.. math::

   \text{tri}(A) := \text{tri}(A + \alpha X Y'),

where :math:`X` and :math:`Y` each consist of two columns

C++ API
^^^^^^^

.. cpp:function:: void Trr2( UpperOrLower uplo, T alpha, const Matrix<T>& X, const Matrix<T>& Y, Matrix<T>& A, bool conjugate=false )
.. cpp:function:: void Trr2( UpperOrLower uplo, T alpha, const AbstractDistMatrix<T>& X, const AbstractDistMatrix<T>& Y, AbstractDistMatrix<T>& A, bool conjugate=false )

C API
^^^^^

.. c:function:: ElError ElTrr2_i( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElConstMatrix_i Y, ElMatrix_i A )
.. c:function:: ElError ElTrr2_s( ElUpperOrLower uplo, float alpha, ElConstMatrix_s X, ElConstMatrix_s Y, ElMatrix_s A )
.. c:function:: ElError ElTrr2_d( ElUpperOrLower uplo, double alpha, ElConstMatrix_d X, ElConstMatrix_d Y, ElMatrix_d A )
.. c:function:: ElError ElTrr2_c( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElConstMatrix_c Y, ElMatrix_c A )
.. c:function:: ElError ElTrr2_z( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElConstMatrix_z Y, ElMatrix_z A )
.. c:function:: ElError ElTrr2Dist_i( ElUpperOrLower uplo, ElInt alpha, ElConstDistMatrix_i X, ElConstDistMatrix_i Y, ElDistMatrix_i A )
.. c:function:: ElError ElTrr2Dist_s( ElUpperOrLower uplo, float alpha, ElConstDistMatrix_s X, ElConstDistMatrix_s Y, ElDistMatrix_s A )
.. c:function:: ElError ElTrr2Dist_d( ElUpperOrLower uplo, double alpha, ElConstDistMatrix_d X, ElConstDistMatrix_d Y, ElDistMatrix_d A )
.. c:function:: ElError ElTrr2Dist_c( ElUpperOrLower uplo, complex_float alpha, ElConstDistMatrix_c X, ElConstDistMatrix_c Y, ElDistMatrix_c A )
.. c:function:: ElError ElTrr2Dist_z( ElUpperOrLower uplo, complex_double alpha, ElConstDistMatrix_z X, ElConstDistMatrix_z Y, ElDistMatrix_z A )

Trsv
----
Triangular solve with a vector: computes
:math:`x := \mbox{op}(A)^{-1} x`, where :math:`\mbox{op}(A)` is either 
:math:`A`, :math:`A^T`, or :math:`A^H`, and :math:`A` is treated an either a 
lower or upper triangular matrix, depending upon `uplo`. :math:`A` can also be 
treated as implicitly having a unit-diagonal if `diag` is set to ``UNIT``.

.. note::

   For the best performance, `A` and `x` should both be in [MC,MR] 
   distributions.

C++ API
^^^^^^^

.. cpp:function:: void Trsv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const Matrix<F>& A, Matrix<F>& x )
.. cpp:function:: void Trsv( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& x )

C API
^^^^^

.. c:function:: ElError ElTrsv_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_s A, ElMatrix_s x )
.. c:function:: ElError ElTrsv_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_d A, ElMatrix_d x )
.. c:function:: ElError ElTrsv_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_c A, ElMatrix_c x )
.. c:function:: ElError ElTrsv_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstMatrix_z A, ElMatrix_z x )
.. c:function:: ElError ElTrsvDist_s( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_s A, ElDistMatrix_s x )
.. c:function:: ElError ElTrsvDist_d( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_d A, ElDistMatrix_d x )
.. c:function:: ElError ElTrsvDist_c( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_c A, ElDistMatrix_c x )
.. c:function:: ElError ElTrsvDist_z( ElUpperOrLower uplo, ElOrientation orientation, ElUnitOrNonUnit diag, ElConstDistMatrix_z A, ElDistMatrix_z x )
