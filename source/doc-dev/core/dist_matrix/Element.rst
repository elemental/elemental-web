ElementalMatrix
===============
The :cpp:class:`ElementalMatrix\<scalarType>` is the parent class of each 
partial specialization
:cpp:class:`DistMatrix\<scalarTypee,colDist,rowDist,ELEMENT>` of `DistMatrix` 
to element-wise distributions; it is a child class of
:cpp:class:`AbstractDistMatrix\<scalarType>`.
Each of the derivatives of `ElementalMatrix\<scalarType>` chooses a 
sensical pairing of distributions for the rows and columns of the matrix.

.. cpp:class:: ElementalMatrix<scalarType>
.. cpp:class:: DistMatrix<scalarType,colDist,rowDist,ELEMENT>

   The following routines are available for each legal pairing of row and column
   distributions.

   .. rubric:: Constructors and destructors

   .. cpp:function:: DistMatrix( const Grid& grid=DefaultGrid(), Int root=0 )

      Construct an empty (:math:`0 \times 0`) distributed matrix.

   .. cpp:function:: DistMatrix( Int height, Int width, const Grid& grid=DefaultGrid(), Int root=0 )

      Create a `height` :math:`\times` `width` distributed matrix.

   .. cpp:function:: DistMatrix( const AbstractDistMatrix<scalarType>& A )

      Construct the current matrix to be a redistributed copy of the input 
      matrix.

   .. cpp:function:: DistMatrix( const DistMatrix<scalarType,colDist,rowDist,ELEMENT>&& A ) noexcept

      Use C++11 move semantics to construct the current matrix in a way which
      transfers the resources from the input matrix.

   .. cpp:function:: ~DistMatrix()

      All resources owned by the `DistMatrix` are freed upon destruction.

   .. cpp:function:: ElementalData DistData() const

      Returns a description of the distribution and alignment information

   .. rubric:: Assignment and reconfiguration

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,ELEMENT>& operator=( const AbstractDistMatrix<scalarType>& A )

      Set the current distributed matrix equal to the matrix `A` redistributed
      into the appropriate form.

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,ELEMENT>& operator=( DistMatrix<scalarType,colDist,rowDist,ELEMENT>&& A )

      A C++11 move assignment which cheaply transfers the resources from `A`
      to the current matrix by swapping metadata.

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,ELEMENT>& operator*=( T alpha )

      Multiply every entry in the matrix by `alpha`.

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,ELEMENT>& operator+=( const AbstractDistMatrix<T>& A )
   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,ELEMENT>& operator-=( const AbstractDistMatrix<T>& A )

      Updates this matrix (via either addition or subtraction) with another
      another matrix.

   .. rubric:: Submatrices

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,ELEMENT> operator()( Range<Int> I, Range<Int> J )

   .. cpp:function:: const DistMatrix<scalarType,colDist,rowDist,ELEMENT> operator()( Range<Int> I, Range<Int> J ) const

      Return a view of a contiguous submatrix with the given row and column
      index ranges.

   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,ELEMENT> operator()( Range<Int> I, const vector<Int>& J ) const
   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,ELEMENT> operator()( const vector<Int>& I, Range<Int> J ) const
   .. cpp:function:: DistMatrix<scalarType,colDist,rowDist,ELEMENT> operator()( const vector<Int>& I, const vector<Int>& J ) const

      Return a copy of the (generally non-contiguous) submatrix given by the
      specified row and column index lists.

.. toctree::
   :maxdepth: 1

   Element/MC_MR
   Element/MC_STAR
   Element/MD_STAR
   Element/MR_MC
   Element/MR_STAR
   Element/STAR_MC
   Element/STAR_MD
   Element/STAR_MR
   Element/STAR_STAR
   Element/STAR_VC
   Element/STAR_VR
   Element/VC_STAR
   Element/VR_STAR
   Element/CIRC_CIRC
   Element/special
