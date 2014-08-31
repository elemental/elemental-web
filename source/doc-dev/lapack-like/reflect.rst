Reflectors
==========

Householder reflectors
----------------------

Generate a reflector
^^^^^^^^^^^^^^^^^^^^
**TODO:** Describe major difference from LAPACK's conventions (i.e., we do not 
treat the identity matrix as a Householder transform since it requires the 
:math:`u` in :math:`H=I-2uu'` to have norm zero rather than one). 

.. cpp:function:: F LeftReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F LeftReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F LeftReflector( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F LeftReflector( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F reflector::Col( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F reflector::Col( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )

.. cpp:function:: F RightReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F RightReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F RightReflector( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F RightReflector( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F reflector::Row( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F reflector::Row( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )

Apply packed reflectors
^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ApplyPackedReflectors( LeftOrRight side, UpperOrLower uplo, VerticalOrHorizontal dir, ForwardOrBackward order, Conjugation conjugation, int offset, const Matrix<F>& H, const Matrix<F>& t, Matrix<F>& A )
.. cpp:function:: void ApplyPackedReflectors( LeftOrRight side, UpperOrLower uplo, VerticalOrHorizontal dir, ForwardOrBackward order, Conjugation conjugation, int offset, const AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& t, AbstractDistMatrix<F>& A )

Expand packed reflectors
^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void ExpandPackedReflectors( UpperOrLower uplo, VerticalOrHorizontal dir, Conjugation conjugation, int offset, Matrix<F>& H, const Matrix<F>& t )
.. cpp:function:: void ExpandPackedReflectors( UpperOrLower uplo, VerticalOrHorizontal dir, Conjugation conjugation, int offset, AbstractDistMatrix<F>& H, const AbstractDistMatrix<F>& t )

Hyperbolic reflectors
---------------------

Generate a reflector
^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: F LeftHyperbolicReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F LeftHyperbolicReflector( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Col( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Col( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )

.. cpp:function:: F RightHyperbolicReflector( F& chi, Matrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( Matrix<F>& chi, Matrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F RightHyperbolicReflector( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Row( F& chi, AbstractDistMatrix<F>& x )
.. cpp:function:: F hyp_reflector::Row( AbstractDistMatrix<F>& chi, AbstractDistMatrix<F>& x )
