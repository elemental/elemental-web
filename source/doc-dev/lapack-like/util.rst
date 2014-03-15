Utilities
=========

Householder reflectors
----------------------
**TODO:** Describe major difference from LAPACK's conventions (i.e., we do not 
treat the identity matrix as a Householder transform since it requires the 
:math:`u` in :math:`H=I-2uu'` to have norm zero rather than one). 

.. cpp:function:: F LeftReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F LeftReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F LeftReflector( F& chi, DistMatrix<F>& x )
.. cpp:function:: F LeftReflector( DistMatrix<F>& chi, DistMatrix<F>& x )
.. cpp:function:: F reflector::Col( F& chi, DistMatrix<F>& x )
.. cpp:function:: F reflector::Col( DistMatrix<F>& chi, DistMatrix<F>& x )

.. cpp:function:: F RightReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F RightReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F RightReflector( F& chi, DistMatrix<F>& x )
.. cpp:function:: F RightReflector( DistMatrix<F>& chi, DistMatrix<F>& x )
.. cpp:function:: F reflector::Row( F& chi, DistMatrix<F>& x )
.. cpp:function:: F reflector::Row( DistMatrix<F>& chi, DistMatrix<F>& x )

.. cpp:function:: F LeftHyperbolicReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( F& chi, DistMatrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( DistMatrix<F>& chi, DistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Col( F& chi, DistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Col( DistMatrix<F>& chi, DistMatrix<F>& x )

.. cpp:function:: F RightHyperbolicReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( F& chi, DistMatrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( DistMatrix<F>& chi, DistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Row( F& chi, DistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Row( DistMatrix<F>& chi, DistMatrix<F>& x )

.. cpp:function:: void ApplyPackedReflectors( LeftOrRight side, UpperOrLower uplo, VerticalOrHorizontal dir, ForwardOrBackward order, Conjugation conjugation, int offset, const Matrix<F>& H, const Matrix<F>& t, Matrix<F>& A )
.. cpp:function:: void ApplyPackedReflectors( LeftOrRight side, UpperOrLower uplo, VerticalOrHorizontal dir, ForwardOrBackward order, Conjugation conjugation, int offset, const DistMatrix<F>& H, const DistMatrix<F,MD,STAR>& t, DistMatrix<F>& A )
.. cpp:function:: void ApplyPackedReflectors( LeftOrRight side, UpperOrLower uplo, VerticalOrHorizontal dir, ForwardOrBackward order, Conjugation conjugation, int offset, const DistMatrix<F>& H, const DistMatrix<F,STAR,STAR>& t, DistMatrix<F>& A )

.. cpp:function:: void ExpandPackedReflectors( UpperOrLower uplo, VerticalOrHorizontal dir, Conjugation conjugation, int offset, Matrix<F>& H, const Matrix<F>& t )
.. cpp:function:: void ExpandPackedReflectors( UpperOrLower uplo, VerticalOrHorizontal dir, Conjugation conjugation, int offset, DistMatrix<F>& H, const DistMatrix<F,MD,STAR>& t )
.. cpp:function:: void ExpandPackedReflectors( UpperOrLower uplo, VerticalOrHorizontal dir, Conjugation conjugation, int offset, DistMatrix<F>& H, const DistMatrix<F,STAR,STAR>& t )

Sorting
-------

.. cpp:function:: void Sort( Matrix<Real>& X, SortType sort=ASCENDING )
.. cpp:function:: void Sort( DistMatrix<Real,U,V>& X, SortType sort=ASCENDING )

.. cpp:function:: std::vector<ValueInt<Real> > TaggedSort( const Matrix<Real>& X, SortType sort=ASCENDING )
.. cpp:function:: std::vector<ValueInt<Real> > TaggedSort( const DistMatrix<Real,U,V>& X, SortType sort=ASCENDING )

.. cpp:function:: ValueInt<Real> Median( const Matrix<Real>& x )
.. cpp:function:: ValueInt<Real> Median( const DistMatrix<Real,U,V>& x )

