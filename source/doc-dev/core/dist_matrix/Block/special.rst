Some special cases used in Elemental
====================================
This list of special cases is here to help clarify the notation used throughout
Elemental's source (as well as this documentation). These are all special 
cases of :cpp:type:`DistMatrix\<scalarType,colDist,rowDist,BLOCK>`.

.. cpp:class:: DistMatrix<Real,colDist,rowDist,BLOCK>
.. cpp:class:: DistMatrix<Real,CIRC,CIRC,BLOCK>
.. cpp:class:: DistMatrix<Real,MC,MR,BLOCK>
.. cpp:class:: DistMatrix<Real,MC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Real,MD,STAR,BLOCK>
.. cpp:class:: DistMatrix<Real,MR,MC,BLOCK>
.. cpp:class:: DistMatrix<Real,MR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,MC,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,MD,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,MR,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,VC,BLOCK>
.. cpp:class:: DistMatrix<Real,STAR,VR,BLOCK>
.. cpp:class:: DistMatrix<Real,VC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Real,VR,STAR,BLOCK>

   The underlying datatype, `Real`, is real (as opposed to complex).

.. cpp:class:: DistMatrix<Complex<Real>,colDist,rowDist,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,CIRC,CIRC,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,MC,MR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,MC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,MD,STAR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,MR,MC,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,MR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MC,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MD,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,MR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VC,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,STAR,VR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,VC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Complex<Real>,VR,STAR,BLOCK>

   The underlying datatype, :cpp:type:`Complex\<Real>`, is complex with base type 
   `Real`. 

.. cpp:class:: DistMatrix<F,colDist,rowDist,BLOCK>
.. cpp:class:: DistMatrix<F,CIRC,CIRC,BLOCK>
.. cpp:class:: DistMatrix<F,MC,MR,BLOCK>
.. cpp:class:: DistMatrix<F,MC,STAR,BLOCK>
.. cpp:class:: DistMatrix<F,MD,STAR,BLOCK>
.. cpp:class:: DistMatrix<F,MR,MC,BLOCK>
.. cpp:class:: DistMatrix<F,MR,STAR,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,MC,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,MD,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,MR,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,STAR,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,VC,BLOCK>
.. cpp:class:: DistMatrix<F,STAR,VR,BLOCK>
.. cpp:class:: DistMatrix<F,VC,STAR,BLOCK>
.. cpp:class:: DistMatrix<F,VR,STAR,BLOCK>

   The underlying datatype, `F`, is a field.

.. cpp:class:: DistMatrix<Int,colDist,rowDist,BLOCK>
.. cpp:class:: DistMatrix<Int,CIRC,CIRC,BLOCK>
.. cpp:class:: DistMatrix<Int,MC,MR,BLOCK>
.. cpp:class:: DistMatrix<Int,MC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Int,MD,STAR,BLOCK>
.. cpp:class:: DistMatrix<Int,MR,MC,BLOCK>
.. cpp:class:: DistMatrix<Int,MR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,MC,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,MD,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,MR,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,STAR,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,VC,BLOCK>
.. cpp:class:: DistMatrix<Int,STAR,VR,BLOCK>
.. cpp:class:: DistMatrix<Int,VC,STAR,BLOCK>
.. cpp:class:: DistMatrix<Int,VR,STAR,BLOCK>

   The underlying datatype is a signed integer (of standard size).

