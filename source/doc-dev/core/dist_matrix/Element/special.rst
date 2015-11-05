Some special cases used in Elemental
====================================
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<T,colDist,rowDist,ELEMENT>`.

.. cpp:class:: DistMatrix<Real,colDist,rowDist>
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

.. cpp:class:: DistMatrix<Real,colDist,rowDist,ELEMENT>
.. cpp:class:: DistMatrix<Real,ELEMENT>
.. cpp:class:: DistMatrix<Real,CIRC,CIRC,ELEMENT>
.. cpp:class:: DistMatrix<Real,MC,MR,ELEMENT>
.. cpp:class:: DistMatrix<Real,MC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Real,MD,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Real,MR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Real,MR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,MD,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,MR,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,VC,ELEMENT>
.. cpp:class:: DistMatrix<Real,STAR,VR,ELEMENT>
.. cpp:class:: DistMatrix<Real,VC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Real,VR,STAR,ELEMENT>

   The underlying datatype, `Real`, is real (as opposed to complex).

.. cpp:class:: DistMatrix<Complex<Real>,colDist,rowDist>
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

.. cpp:class:: DistMatrix<Complex<Real>,colDist,rowDist,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,CIRC,CIRC,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,MC,MR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,MC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,MD,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,MR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,MR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MD,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VC,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,VC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Complex<Real>,VR,STAR,ELEMENT>

   The underlying datatype, :cpp:type:`Complex\<Real>`, is complex with base type 
   `Real`. 

.. cpp:class:: DistMatrix<F,colDist,rowDist>
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

.. cpp:class:: DistMatrix<F,colDist,rowDist,ELEMENT>
.. cpp:class:: DistMatrix<F,ELEMENT>
.. cpp:class:: DistMatrix<F,CIRC,CIRC,ELEMENT>
.. cpp:class:: DistMatrix<F,MC,MR,ELEMENT>
.. cpp:class:: DistMatrix<F,MC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<F,MD,STAR,ELEMENT>
.. cpp:class:: DistMatrix<F,MR,MC,ELEMENT>
.. cpp:class:: DistMatrix<F,MR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,MC,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,MD,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,MR,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,VC,ELEMENT>
.. cpp:class:: DistMatrix<F,STAR,VR,ELEMENT>
.. cpp:class:: DistMatrix<F,VC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<F,VR,STAR,ELEMENT>

   The underlying datatype, `F`, is a field.

.. cpp:class:: DistMatrix<Int,colDist,rowDist>
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

.. cpp:class:: DistMatrix<Int,colDist,rowDist,ELEMENT>
.. cpp:class:: DistMatrix<Int,ELEMENT>
.. cpp:class:: DistMatrix<Int,CIRC,CIRC,ELEMENT>
.. cpp:class:: DistMatrix<Int,MC,MR,ELEMENT>
.. cpp:class:: DistMatrix<Int,MC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Int,MD,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Int,MR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Int,MR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,MC,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,MD,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,MR,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,VC,ELEMENT>
.. cpp:class:: DistMatrix<Int,STAR,VR,ELEMENT>
.. cpp:class:: DistMatrix<Int,VC,STAR,ELEMENT>
.. cpp:class:: DistMatrix<Int,VR,STAR,ELEMENT>

   The underlying datatype is a signed integer (of standard size).
