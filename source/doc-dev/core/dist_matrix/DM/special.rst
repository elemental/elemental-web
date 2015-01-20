Some special cases used in Elemental
====================================
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<T,U,V>`.

.. cpp:type:: DistMatrix<double,U,V>
.. cpp:type:: DistMatrix<double>
.. cpp:type:: DistMatrix<double,CIRC,CIRC>
.. cpp:type:: DistMatrix<double,MC,MR>
.. cpp:type:: DistMatrix<double,MC,STAR>
.. cpp:type:: DistMatrix<double,MD,STAR>
.. cpp:type:: DistMatrix<double,MR,MC>
.. cpp:type:: DistMatrix<double,MR,STAR>
.. cpp:type:: DistMatrix<double,STAR,MC>
.. cpp:type:: DistMatrix<double,STAR,MD>
.. cpp:type:: DistMatrix<double,STAR,MR>
.. cpp:type:: DistMatrix<double,STAR,STAR>
.. cpp:type:: DistMatrix<double,STAR,VC>
.. cpp:type:: DistMatrix<double,STAR,VR>
.. cpp:type:: DistMatrix<double,VC,STAR>
.. cpp:type:: DistMatrix<double,VR,STAR>

   The underlying datatype is the set of double-precision real numbers.

.. cpp:type:: DistMatrix<Complex<double>,U,V>
.. cpp:type:: DistMatrix<Complex<double>>
.. cpp:type:: DistMatrix<Complex<double>,CIRC,CIRC>
.. cpp:type:: DistMatrix<Complex<double>,MC,MR>
.. cpp:type:: DistMatrix<Complex<double>,MC,STAR>
.. cpp:type:: DistMatrix<Complex<double>,MD,STAR>
.. cpp:type:: DistMatrix<Complex<double>,MR,MC>
.. cpp:type:: DistMatrix<Complex<double>,MR,STAR>
.. cpp:type:: DistMatrix<Complex<double>,STAR,MC>
.. cpp:type:: DistMatrix<Complex<double>,STAR,MD>
.. cpp:type:: DistMatrix<Complex<double>,STAR,MR>
.. cpp:type:: DistMatrix<Complex<double>,STAR,STAR>
.. cpp:type:: DistMatrix<Complex<double>,STAR,VC>
.. cpp:type:: DistMatrix<Complex<double>,STAR,VR>
.. cpp:type:: DistMatrix<Complex<double>,VC,STAR>
.. cpp:type:: DistMatrix<Complex<double>,VR,STAR>

   The underlying datatype is the set of double-precision complex numbers.

.. cpp:type:: DistMatrix<Real,U,V>
.. cpp:type:: DistMatrix<Real>
.. cpp:type:: DistMatrix<Real,CIRC,CIRC>
.. cpp:type:: DistMatrix<Real,MC,MR>
.. cpp:type:: DistMatrix<Real,MC,STAR>
.. cpp:type:: DistMatrix<Real,MD,STAR>
.. cpp:type:: DistMatrix<Real,MR,MC>
.. cpp:type:: DistMatrix<Real,MR,STAR>
.. cpp:type:: DistMatrix<Real,STAR,MC>
.. cpp:type:: DistMatrix<Real,STAR,MD>
.. cpp:type:: DistMatrix<Real,STAR,MR>
.. cpp:type:: DistMatrix<Real,STAR,STAR>
.. cpp:type:: DistMatrix<Real,STAR,VC>
.. cpp:type:: DistMatrix<Real,STAR,VR>
.. cpp:type:: DistMatrix<Real,VC,STAR>
.. cpp:type:: DistMatrix<Real,VR,STAR>

   The underlying datatype, `Real`, is real (as opposed to complex).

.. cpp:type:: DistMatrix<Complex<Real>,U,V>
.. cpp:type:: DistMatrix<Complex<Real>>
.. cpp:type:: DistMatrix<Complex<Real>,CIRC,CIRC>
.. cpp:type:: DistMatrix<Complex<Real>,MC,MR>
.. cpp:type:: DistMatrix<Complex<Real>,MC,STAR>
.. cpp:type:: DistMatrix<Complex<Real>,MD,STAR>
.. cpp:type:: DistMatrix<Complex<Real>,MR,MC>
.. cpp:type:: DistMatrix<Complex<Real>,MR,STAR>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,MC>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,MD>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,MR>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,STAR>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,VC>
.. cpp:type:: DistMatrix<Complex<Real>,STAR,VR>
.. cpp:type:: DistMatrix<Complex<Real>,VC,STAR>
.. cpp:type:: DistMatrix<Complex<Real>,VR,STAR>

   The underlying datatype, :cpp:type:`Complex\<Real>`, is complex with base type 
   `Real`. 

.. cpp:type:: DistMatrix<F,U,V>
.. cpp:type:: DistMatrix<F>
.. cpp:type:: DistMatrix<F,CIRC,CIRC>
.. cpp:type:: DistMatrix<F,MC,MR>
.. cpp:type:: DistMatrix<F,MC,STAR>
.. cpp:type:: DistMatrix<F,MD,STAR>
.. cpp:type:: DistMatrix<F,MR,MC>
.. cpp:type:: DistMatrix<F,MR,STAR>
.. cpp:type:: DistMatrix<F,STAR,MC>
.. cpp:type:: DistMatrix<F,STAR,MD>
.. cpp:type:: DistMatrix<F,STAR,MR>
.. cpp:type:: DistMatrix<F,STAR,STAR>
.. cpp:type:: DistMatrix<F,STAR,VC>
.. cpp:type:: DistMatrix<F,STAR,VR>
.. cpp:type:: DistMatrix<F,VC,STAR>
.. cpp:type:: DistMatrix<F,VR,STAR>

   The underlying datatype, `F`, is a field.

.. cpp:type:: DistMatrix<Int,U,V>
.. cpp:type:: DistMatrix<Int>
.. cpp:type:: DistMatrix<Int,CIRC,CIRC>
.. cpp:type:: DistMatrix<Int,MC,MR>
.. cpp:type:: DistMatrix<Int,MC,STAR>
.. cpp:type:: DistMatrix<Int,MD,STAR>
.. cpp:type:: DistMatrix<Int,MR,MC>
.. cpp:type:: DistMatrix<Int,MR,STAR>
.. cpp:type:: DistMatrix<Int,STAR,MC>
.. cpp:type:: DistMatrix<Int,STAR,MD>
.. cpp:type:: DistMatrix<Int,STAR,MR>
.. cpp:type:: DistMatrix<Int,STAR,STAR>
.. cpp:type:: DistMatrix<Int,STAR,VC>
.. cpp:type:: DistMatrix<Int,STAR,VR>
.. cpp:type:: DistMatrix<Int,VC,STAR>
.. cpp:type:: DistMatrix<Int,VR,STAR>

   The underlying datatype is a signed integer (of standard size).

