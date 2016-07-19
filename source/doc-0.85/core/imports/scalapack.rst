BLACS
-----
A handful of Basic Linear Algebra Communication Subprograms (BLACS) routines 
are currently exposed to Elemental if ``MATH_LIBS`` was detected to contain a 
recent version of ScaLAPACK.

.. cpp:function:: int blacs::Handle( MPI_Comm comm )
.. cpp:function:: int blacs::GridInit( int bhandle, bool colMajor, int gridHeight, int gridWidth )

.. cpp:function:: int blacs::GridHeight( int context )
.. cpp:function:: int blacs::GridWidth( int context )

.. cpp:function:: int blacs::GridRow( int context )
.. cpp:function:: int blacs::GridCol( int context )

.. cpp:function:: void blacs::FreeHandle( int bhandle )
.. cpp:function:: void blacs::FreeGrid( int context )

.. cpp:function:: void blacs::Exit( bool finished=true )

.. cpp:type:: blacs::Desc

   Currently a typedef to ``std::array<int,9>``.

.. cpp:function:: blacs::Desc FillDesc( const BlockDistMatrix<F>& A, int context )

   Form the descriptor for the distributed matrix `A` using the specified
   corresponding context.

ScaLAPACK
---------
A handful of ScaLAPACK routines are currently exposed to Elemental if 
``MATH_LIBS`` was detected to contain a recent version of ScaLAPACK.

Hessenberg Schur decomposition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void scalapack::HessenbergSchur( int n, F* H, int* desch, Complex<Base<F>>* w, bool fullTriangle=false, bool aed=false )

   Computes the eigenvalues (and possibly the full Schur factor) of an upper 
   Hessenberg matrix using the QR algorithm. Aggressive Early Deflation may
   be optionally used for real matrices, but there are known bugs in the 
   ScaLAPACK implementation.

.. cpp:function:: void scalapack::HessenbergSchur( int n, F* H, int* desch, Complex<Base<F>>* w, F* Q, int* descq, bool fullTriangle=true, bool multiplyQ=false, bool aed=false )

   Computes the eigenvalues (and possibly the full Schur factor) as well as 
   the Schur vectors of of an upper Hessenberg matrix using the QR algorithm.
   If `multiplyQ` is true, then the Schur vectors are multiplied against the
   input matrix from the right. Aggressive Early Deflation may
   be optionally used for real matrices, but there are known bugs in the 
   ScaLAPACK implementation.

Hessenberg eigenvalues/pairs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. cpp:function:: void scalapack::HessenbergEig( int n, F* H, int* desch, Complex<Base<F>>* w )

   Computes the eigenvalues of an upper Hessenberg matrix using the QR 
   algorithm.

.. note::

   There are not yet wrappers for computing Hessenberg eigenvectors.
