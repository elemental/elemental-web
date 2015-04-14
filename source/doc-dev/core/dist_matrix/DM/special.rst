Some special cases used in Elemental
====================================
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<T,U,V>`.

.. cpp:class:: DistMatrix<double,U,V>
.. cpp:class:: DistMatrix<double>
.. cpp:class:: DistMatrix<double,CIRC,CIRC>
.. cpp:class:: DistMatrix<double,MC,MR>
.. cpp:class:: DistMatrix<double,MC,STAR>
.. cpp:class:: DistMatrix<double,MD,STAR>
.. cpp:class:: DistMatrix<double,MR,MC>
.. cpp:class:: DistMatrix<double,MR,STAR>
.. cpp:class:: DistMatrix<double,STAR,MC>
.. cpp:class:: DistMatrix<double,STAR,MD>
.. cpp:class:: DistMatrix<double,STAR,MR>
.. cpp:class:: DistMatrix<double,STAR,STAR>
.. cpp:class:: DistMatrix<double,STAR,VC>
.. cpp:class:: DistMatrix<double,STAR,VR>
.. cpp:class:: DistMatrix<double,VC,STAR>
.. cpp:class:: DistMatrix<double,VR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:class:: DistMatrix<Complex<double>,U,V>
.. cpp:class:: DistMatrix<Complex<double>>
.. cpp:class:: DistMatrix<Complex<double>,CIRC,CIRC>
.. cpp:class:: DistMatrix<Complex<double>,MC,MR>
.. cpp:class:: DistMatrix<Complex<double>,MC,STAR>
.. cpp:class:: DistMatrix<Complex<double>,MD,STAR>
.. cpp:class:: DistMatrix<Complex<double>,MR,MC>
.. cpp:class:: DistMatrix<Complex<double>,MR,STAR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MC>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MD>
.. cpp:class:: DistMatrix<Complex<double>,STAR,MR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,STAR>
.. cpp:class:: DistMatrix<Complex<double>,STAR,VC>
.. cpp:class:: DistMatrix<Complex<double>,STAR,VR>
.. cpp:class:: DistMatrix<Complex<double>,VC,STAR>
.. cpp:class:: DistMatrix<Complex<double>,VR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:class:: DistMatrix<Real,U,V>
.. cpp:class:: DistMatrix<Real>
.. cpp:class:: DistMatrix<Real,CIRC,CIRC>
.. cpp:class:: DistMatrix<Real,MC,MR>
.. cpp:class:: DistMatrix<Real,MC,STAR>
.. cpp:class:: DistMatrix<Real,MD,STAR>
.. cpp:class:: DistMatrix<Real,MR,MC>
.. cpp:class:: DistMatrix<Real,MR,STAR>
.. cpp:class:: DistMatrix<Real,STAR,MC>
.. cpp:class:: DistMatrix<Real,STAR,MD>
.. cpp:class:: DistMatrix<Real,STAR,MR>
.. cpp:class:: DistMatrix<Real,STAR,STAR>
.. cpp:class:: DistMatrix<Real,STAR,VC>
.. cpp:class:: DistMatrix<Real,STAR,VR>
.. cpp:class:: DistMatrix<Real,VC,STAR>
.. cpp:class:: DistMatrix<Real,VR,STAR>

   The underlying datatype, `Real`, is real (as opposed to complex).

.. cpp:class:: DistMatrix<Complex<Real>,U,V>
.. cpp:class:: DistMatrix<Complex<Real>>
.. cpp:class:: DistMatrix<Complex<Real>,CIRC,CIRC>
.. cpp:class:: DistMatrix<Complex<Real>,MC,MR>
.. cpp:class:: DistMatrix<Complex<Real>,MC,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,MD,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,MR,MC>
.. cpp:class:: DistMatrix<Complex<Real>,MR,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MC>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MD>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VC>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VR>
.. cpp:class:: DistMatrix<Complex<Real>,VC,STAR>
.. cpp:class:: DistMatrix<Complex<Real>,VR,STAR>

   The underlying datatype, :cpp:type:`Complex\<Real>`, is complex with base type 
   `Real`. 

.. cpp:class:: DistMatrix<F,U,V>
.. cpp:class:: DistMatrix<F>
.. cpp:class:: DistMatrix<F,CIRC,CIRC>
.. cpp:class:: DistMatrix<F,MC,MR>
.. cpp:class:: DistMatrix<F,MC,STAR>
.. cpp:class:: DistMatrix<F,MD,STAR>
.. cpp:class:: DistMatrix<F,MR,MC>
.. cpp:class:: DistMatrix<F,MR,STAR>
.. cpp:class:: DistMatrix<F,STAR,MC>
.. cpp:class:: DistMatrix<F,STAR,MD>
.. cpp:class:: DistMatrix<F,STAR,MR>
.. cpp:class:: DistMatrix<F,STAR,STAR>
.. cpp:class:: DistMatrix<F,STAR,VC>
.. cpp:class:: DistMatrix<F,STAR,VR>
.. cpp:class:: DistMatrix<F,VC,STAR>
.. cpp:class:: DistMatrix<F,VR,STAR>

   The underlying datatype, `F`, is a field.

.. cpp:class:: DistMatrix<Int,U,V>
.. cpp:class:: DistMatrix<Int>
.. cpp:class:: DistMatrix<Int,CIRC,CIRC>
.. cpp:class:: DistMatrix<Int,MC,MR>
.. cpp:class:: DistMatrix<Int,MC,STAR>
.. cpp:class:: DistMatrix<Int,MD,STAR>
.. cpp:class:: DistMatrix<Int,MR,MC>
.. cpp:class:: DistMatrix<Int,MR,STAR>
.. cpp:class:: DistMatrix<Int,STAR,MC>
.. cpp:class:: DistMatrix<Int,STAR,MD>
.. cpp:class:: DistMatrix<Int,STAR,MR>
.. cpp:class:: DistMatrix<Int,STAR,STAR>
.. cpp:class:: DistMatrix<Int,STAR,VC>
.. cpp:class:: DistMatrix<Int,STAR,VR>
.. cpp:class:: DistMatrix<Int,VC,STAR>
.. cpp:class:: DistMatrix<Int,VR,STAR>

   The underlying datatype is a signed integer (of standard size).

