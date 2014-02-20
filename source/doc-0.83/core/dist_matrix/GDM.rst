GeneralDistMatrix
-----------------
The :cpp:type:`GeneralDistMatrix\<T,U,V>` class, which inherits from 
:cpp:type:`AbstractDistMatrix\<T>`, provides a mechanism for 
defining member functions of the :cpp:type:`DistMatrix\<T,U,V>` class which
can be implemented in a templated way over the matrix distribution. Since
a small number of member functions of :cpp:type:`DistMatrix\<T,U,V>` must be
specialized for each particular distribution (choice of the pair `U` and `V`),
a parent class is required in order to support both general and specialized
implementations of member functions whose prototype depends upon the matrix 
distribution.

.. cpp:type:: class GeneralDistMatrix<T,U,V>

   .. rubric:: Related row and column distributions

   .. cpp:member:: Distribution UDiag
   .. cpp:member:: Distribution VDiag

      The column and row :cpp:type:`Distribution`'s of the diagonal of the 
      matrix if it is stored as a column vector.

   .. cpp:member:: Distribution UGath

      The resulting :cpp:type:`Distribution` from unioning distribution `U` over
      :cpp:func:`AbstractDistMatrix\<T>::ColComm`. For most matrix distributions
      this will be ``STAR``, but for :cpp:type:`GeneralDistMatrix\<T,CIRC,CIRC>`
      it will be ``CIRC``.

   .. cpp:member:: Distribution VGath

      The resulting :cpp:type:`Distribution` from unioning distribution `V` over
      :cpp:func:`AbstractDistMatrix\<T>::RowComm`. 

   .. cpp:member:: Distribution UPart
   .. cpp:member:: Distribution VPart

      The resulting :cpp:type:`Distribution` from unioning distribution `U` over
      :cpp:func:`AbstractDistMatrix\<T>::PartialUnionColComm`, or 
      `V` over :cpp:func:`AbstractDistMatrix\<T>::PartialUnionRowComm`,
      respectively.

   .. cpp:member:: Distribution UScat
   .. cpp:member:: Distribution VScat

      The result of scattering :cpp:type:`Distribution` `U` over 
      :cpp:func:`AbstractDistMatrix\<T>::PartialUnionRowComm`, or 
      `V` over :cpp:func:`AbstractDistMatrix\<T>::PartialUnionColComm`,
      respectively.

   .. rubric:: Constructors and destructors

   .. cpp:function:: GeneralDistMatrix( GeneralDistMatrix<T,U,V>&& A )

      A C++11 move constructor which cheaply transfers resources from `A` to
      the new matrix by swapping metadata.

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: GeneralDistMatrix<T,U,V>& operator=( GeneralDistMatrix<T,U,V>&& A )

      A C++11 move assignment which cheaply transfers resources from `A` to
      this matrix by swapping metadata.

   .. cpp:function:: void AllGather( DistMatrix<T,UGath,VGath>& A ) const
   .. cpp:function:: void ColAllGather( DistMatrix<T,UGath,V>& A ) const
   .. cpp:function:: void RowAllGather( DistMatrix<T,U,VGath>& A ) const
   .. cpp:function:: void PartialColAllGather( DistMatrix<T,UPart,V>& A ) const
   .. cpp:function:: void PartialRowAllGather( DistMatrix<T,U,VPart>& A ) const

      Form the distributed matrix which results from unioning the local data
      over :cpp:func:`AbstractDistMatrix\<T>::DistComm`, 
      :cpp:func:`AbstractDistMatrix\<T>::ColComm`, 
      :cpp:func:`AbstractDistMatrix\<T>::RowComm`,
      :cpp:func:`AbstractDistMatrix\<T>::PartialUnionColComm`, or
      :cpp:func:`AbstractDistMatrix\<T>::PartialUnionRowComm`, respectively. 
      Each of these is accomplished via a call to :cpp:func:`mpi::AllGather` 
      over the appropriate communicator.

      .. note:: 

         :cpp:func:`ColAllGather` and (to a lesser degree) 
         :cpp:func:`PartialColAllGather` both 
         require accessing large amounts of data with a non-uniform stride. 
         They therefore do not make efficient usage of cache lines and should 
         be avoided in favor of :cpp:func:`TransposeColAllGather` and 
         :cpp:func:`TransposePartialColAllGather`, respectively.

   .. cpp:function:: void FilterFrom( const DistMatrix<T,UGath,VGath>& A )
   .. cpp:function:: void ColFilterFrom( const DistMatrix<T,UGath,V>& A )
   .. cpp:function:: void RowFilterFrom( const DistMatrix<T,U,VGath>& A )
   .. cpp:function:: void PartialColFilterFrom( const DistMatrix<T,UPart,V>& A )
   .. cpp:function:: void PartialRowFilterFrom( const DistMatrix<T,U,VPart>& A )

      Set the current matrix equal to the appropriate subset of a distributed
      matrix which would have resulted from unioning our local data over a 
      particular communicator.

   .. cpp:function:: void PartialColAllToAllFrom( const DistMatrix<T,UPart,VScat>& A )
   .. cpp:function:: void PartialRowAllToAllFrom( const DistMatrix<T,UScat,VPart>& A )
 
      Set this matrix to the result of scattering columns (rows) and unioning
      rows (columns) of `A` over 
      :cpp:type:`AbstractDistMatrix\<T>::PartialUnionColComm` 
      (:cpp:type:`AbstractDistMatrix\<T>::PartialUnionRowComm`).

   .. cpp:function:: void PartialColAllToAll( DistMatrix<T,UPart,VScat>& A ) const
   .. cpp:function:: void PartialRowAllToAll( DistMatrix<T,UScat,VPart>& A ) const

      Set `A` to the result of unioning columns (rows) and scattering
      rows (columns) of this matrix over 
      :cpp:type:`AbstractDistMatrix\<T>::PartialUnionColComm`
      (:cpp:type:`AbstractDistMatrix\<T>::PartialUnionRowComm`).

   .. cpp:function:: void SumScatterFrom( const DistMatrix<T,UGath,VGath>& A )
   .. cpp:function:: void RowSumScatterFrom( const DistMatrix<T,U,VGath>& A )
   .. cpp:function:: void ColSumScatterFrom( const DistMatrix<T,UGath,V>& A )
   .. cpp:function:: void PartialRowSumScatterFrom( const DistMatrix<T,U,VPart>& A )
   .. cpp:function:: void PartialColSumScatterFrom( const DistMatrix<T,UPart,V>& A )

      Simultaneously sum and scatter each process's local matrix from `A` over
      the :cpp:func:`AbstractDistMatrix\<T>::DistComm`, 
      :cpp:func:`AbstractDistMatrix\<T>::RowComm`,
      :cpp:func:`AbstractDistMatrix\<T>::ColComm`,
      :cpp:func:`AbstractDistMatrix\<T>::PartialRowComm`, or
      :cpp:func:`AbstractDistMatrix\<T>::PartialColComm` communicator, 
      respectively, and set the current matrix equal to the result.

      .. note:: 

         :cpp:func:`ColSumScatterFrom` and (to a lesser degree)
         :cpp:func:`PartialColSumScatterFrom` both require accessing large
         amounts of data with a non-uniform stride. They therefore do not make
         efficient usage of cache lines and should be avoided in favor of 
         :cpp:func:`TransposeColSumScatterFrom` and 
         :cpp:func:`TransposePartialColSumScatterFrom`, respectively.

   .. cpp:function:: void SumScatterUpdate( T alpha, const DistMatrix<T,UGath,VGath>& A )
   .. cpp:function:: void RowSumScatterUpdate( T alpha, const DistMatrix<T,U,VGath>& A )
   .. cpp:function:: void ColSumScatterUpdate( T alpha, const DistMatrix<T,UGath,V>& A )
   .. cpp:function:: void PartialRowSumScatterUpdate( T alpha, const DistMatrix<T,U,VPart>& A )
   .. cpp:function:: void PartialColSumScatterUpdate( T alpha, const DistMatrix<T,UPart,V>& A )

      Simultaneously sum and scatter each process's local matrix from `A` over
      the :cpp:func:`AbstractDistMatrix\<T>::DistComm`, 
      :cpp:func:`AbstractDistMatrix\<T>::RowComm`,
      :cpp:func:`AbstractDistMatrix\<T>::ColComm`,
      :cpp:func:`AbstractDistMatrix\<T>::PartialRowComm`, or
      :cpp:func:`AbstractDistMatrix\<T>::PartialColComm` communicator, 
      respectively, and add `alpha` times the result to the current matrix.

      .. note:: 

         :cpp:func:`ColSumScatterUpdate` and (to a lesser degree)
         :cpp:func:`PartialColSumScatterUpdate` both require accessing large
         amounts of data with a non-uniform stride. They therefore do not make
         efficient usage of cache lines and should be avoided in favor of 
         :cpp:func:`TransposeColSumScatterUpdate` and 
         :cpp:func:`TransposePartialColSumScatterUpdate`, respectively.

   .. rubric:: Transpose redistributions

   .. cpp:function:: void TransposeColAllGather( DistMatrix<T,V,UGath>& A, bool conjugate=false ) const
   .. cpp:function:: void TransposePartialColAllGather( DistMatrix<T,V,UPart>& A, bool conjugate=false ) const

      Since :cpp:func:`ColAllGather` and :cpp:func:`PartialColAllGather` make 
      poor usage of cache lines due to filling up columns of the result in an
      interleaved manner, forming the transposed result, by transposing the 
      data before calling :cpp:func:`mpi::AllGather`, allows for the expensive
      unpacking step to copy entire contiguous rows of the input at a time.
      The optional `conjugate` parameter determines whether or not the result
      should be conjugated in addition to transposed.

   .. cpp:function:: void AdjointColAllGather( DistMatrix<T,V,UGath>& A ) const
   .. cpp:function:: void AdjointPartialColAllGather( DistMatrix<T,V,UPart>& A ) const 

      These routines correspond to :cpp:func:`TransposeColAllGather` and 
      :cpp:func:`TransposePartialColAllGather` with conjugation. 

   .. cpp:function:: void TransposeColFilterFrom( const DistMatrix<T,V,UGath>& A, bool conjugate=false )
   .. cpp:function:: void TransposeRowFilterFrom( const DistMatrix<T,VGath,U>& A, bool conjugate=false )
   .. cpp:function:: void TransposePartialColFilterFrom( const DistMatrix<T,V,UPart>& A, bool conjugate=false )
   .. cpp:function:: void TransposePartialRowFilterFrom( const DistMatrix<T,VPart,U>& A, bool conjugate=false )

      After performing computations with the results of 
      :cpp:func:`TransposeColAllGather` or 
      :cpp:func:`TransposePartialColAllGather`, it is frequently necessary to
      form a subset of the transposed result.
      The result can be optionally conjugated.

   .. cpp:function:: void AdjointColFilterFrom( const DistMatrix<T,V,UGath>& A )
   .. cpp:function:: void AdjointRowFilterFrom( const DistMatrix<T,VGath,U>& A )
   .. cpp:function:: void AdjointPartialColFilterFrom( const DistMatrix<T,V,UPart>& A )
   .. cpp:function:: void AdjointPartialRowFilterFrom( const DistMatrix<T,VPart,U>& A )

      These routines correspond to the conjugated versions of 
      :cpp:func:`TransposeColFilterFrom`, :cpp:func:`TransposeRowFilterFrom`, 
      :cpp:func:`TransposePartialColFilterFrom`, and
      :cpp:func:`TransposePartialRowFilterFrom`.

   .. cpp:function:: void TransposeColSumScatterFrom( const DistMatrix<T,V,UGath>& A, bool conjugate=false )
   .. cpp:function:: void TransposePartialColSumScatterFrom( const DistMatrix<T,V,UPart>& A, bool conjugate=false )

      Since :cpp:func:`ColSumScatterFrom` and 
      (to a lesser degree) :cpp:func:`PartialColSumScatterFrom` involve 
      accessing large amounts of data with a non-uniform stride, these routines
      work with the (conjugate-)transposed input in order to form the result in
      a more efficient manner which primarily moved contiguous chunks of data.

   .. cpp:function:: void AdjointColSumScatterFrom( const DistMatrix<T,V,UGath>& A )
   .. cpp:function:: void AdjointPartialColSumScatterFrom( const DistMatrix<T,V,UPart>& A )

      These routines are the conjugated versions of 
      :cpp:func:`TransposeColSumScatterFrom` and 
      :cpp:func:`TransposePartialColSumScatterFrom`.

   .. cpp:function:: void TransposeColSumScatterUpdate( T alpha, const DistMatrix<T,V,UGath>& A, bool conjugate=false )
   .. cpp:function:: void TransposePartialColSumScatterUpdate( T alpha, const DistMatrix<T,V,UPart>& A, bool conjugate=false )

      Since :cpp:func:`ColSumScatterUpdate` and 
      (to a lesser degree) :cpp:func:`PartialColSumScatterUpdate` involve 
      accessing large amounts of data with a non-uniform stride, these routines
      work with the (conjugate-)transposed input in order to form the result in
      a more efficient manner which primarily moved contiguous chunks of data.
  
   .. cpp:function:: void AdjointColSumScatterUpdate( T alpha, const DistMatrix<T,V,UGath>& A )
   .. cpp:function:: void AdjointPartialColSumScatterUpdate( T alpha, const DistMatrix<T,V,UPart>& A )

      These routines are the conjugated versions of 
      :cpp:func:`TransposeColSumScatterUpdate` and 
      :cpp:func:`TransposePartialColSumScatterUpdate`.
