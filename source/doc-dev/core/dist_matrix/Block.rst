BlockMatrix
===========
The :cpp:class:`BlockMatrix\<scalarType>` is the parent class of each
partial specialization
:cpp:class:`DistMatrix\<scalarTypee,colDist,rowDist,BLOCK>` of `DistMatrix`
to block-wise distributions; it is a child class of
:cpp:class:`AbstractDistMatrix\<scalarType>`.
Each of the derivatives of `ElementalMatrix\<scalarType>` chooses a
sensical pairing of distributions for the rows and columns of the matrix.

.. cpp:class:: BlockMatrix<scalarType>
.. cpp:class:: DistMatrix<scalarType,colDist,rowDist,BLOCK>

   The following routines are available for each legal pairing of row and column
   distributions.

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMatrix( const Grid& grid=DefaultGrid(), Int blockHeight=DefaultBlockHeight(), Int blockWidth=DefaultBlockWidth(), Int root=0 )

      Construct an empty (:math:`0 \times 0`) distributed matrix.

   .. cpp:function:: DistMatrix( Int height, Int width, const Grid& grid=DefaultGrid(), Int blockHeight=DefaultBlockHeight(), Int blockWidth=DefaultBlockWidth(), Int root=0 )

      Create a `height` :math:`\times` `width` distributed matrix.

   .. cpp:function:: DistMatrix( const AbstractDistMatrix<scalarType>& A )

      Construct the current matrix to be a redistributed copy of the input 
      matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<scalarType,colDist,rowDist,BLOCK>&& A ) noexcept

      Use C++11 move semantics to construct the current matrix in a way which
      transfers the resources from the input matrix.

   .. cpp:function:: ~DistMatrix()

      All resources owned by the `DistMatrix` are freed upon destruction.

   .. cpp:function:: El::DistData DistData() const

      Returns a description of the distribution and alignment information

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist>& operator=( const AbstractDistMatrix<scalarType>& A )

      Set the current distributed matrix equal to the matrix `A` redistributed
      into the appropriate form.

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,BLOCK>& operator=( DistMatrix<scalarType,colDist,rowDist,BLOCK>&& A )

      A C++11 move assignment which cheaply transfers the resources from `A`
      to the current matrix by swapping metadata.

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,BLOCK>& operator*=( T alpha )

      Multiply every entry in the matrix by `alpha`.

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,BLOCK>& operator+=( const AbstractDistMatrix<T>& A )
   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,BLOCK>& operator-=( const AbstractDistMatrix<T>& A )

      Updates this matrix (via either addition or subtraction) with another
      another matrix.

   .. rubric:: Submatrices

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,BLOCK> operator()( Range<Int> I, Range<Int> J )

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,BLOCK> operator()( Range<Int> I, Range<Int> J ) const

      Return a view of a contiguous submatrix with the given row and column
      index ranges.

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,BLOCK> operator()( Range<Int> I, const vector<Int>& J ) const
   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,BLOCK> operator()( const vector<Int>& I, Range<Int> J ) const
   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,BLOCK> operator()( const vector<Int>& I, const vector<Int>& J ) const

      Return a copy of the (generally non-contiguous) submatrix given by the
      specified row and column index lists.

   .. cpp:function:: DistWrap Wrap() const

      Returns


.. toctree::
   :maxdepth: 1

   Block/MC_MR
   Block/MC_STAR
   Block/MD_STAR
   Block/MR_MC
   Block/MR_STAR
   Block/STAR_MC
   Block/STAR_MD
   Block/STAR_MR
   Block/STAR_STAR
   Block/STAR_VC
   Block/STAR_VR
   Block/VC_STAR
   Block/VR_STAR
   Block/CIRC_CIRC
   Block/special
