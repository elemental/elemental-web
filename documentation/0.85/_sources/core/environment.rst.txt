Environment
===========

This section describes the routines and data structures which help set up 
Elemental's programming environment: it discusses initialization of Elemental,
call stack manipulation, a custom data structure for complex data, many routines
for manipulating real and complex data, a litany of custom enums, and a few 
useful routines for simplifying index calculations.

Version and configuration information
-------------------------------------

Every Elemental driver with proper command-line argument processing will run
`PrintVersion` if the ``--version`` argument is used. If ``--build`` is used,
then all of the below information is reported.

Versioning
^^^^^^^^^^
The following routines print the Git revision, (pre-)release version, and 
build type. For example::

    Elemental version information:
      Git revision: 3c6fbdaad901a554fc27a83378d63dab55af0dd3
      Version:      0.85-dev
      Build type:   PureDebug

C++ API
"""""""

.. cpp:function:: void PrintVersion( std::ostream& os=std::cout )

C API
"""""

.. c:function:: ElError ElPrintVersion( FILE* stream )

Python API
""""""""""

.. py:function:: PrintVersion(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

Configuration
^^^^^^^^^^^^^
The following routines print several relevant configuration details. 
For example::

 Elemental configuration:
   Math libraries:               /usr/lib/liblapack.so;/usr/lib/libblas.so
   Have FLAME bidiagonal SVD:    YES
   Have OpenMP:                  YES
   Have Qt5:                     YES
   Avoiding complex MPI:         YES
   Have MPI_Reducescatter_block: YES
   Have MPI_IN_PLACE:            YES
   AllReduce ReduceScatterBlock: YES
   Use byte AllGathers:          YES

C++ API
"""""""
   
.. cpp:function:: void PrintConfig( std::ostream& os=std::cout )

C API
"""""

.. c:function:: ElError ElPrintConfig( FILE* stream )

Python API
""""""""""

.. py:function:: PrintConfig(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

C compiler info
^^^^^^^^^^^^^^^
The following routines print various details about the C compilation process. 
For example::

 Elemental's C compiler info:
   EL_CMAKE_C_COMPILER:    /usr/local/bin/gcc
   EL_MPI_C_COMPILER:      /home/poulson/Install/bin/mpicc
   EL_MPI_C_INCLUDE_PATH:  /home/poulson/Install/include
   EL_MPI_C_COMPILE_FLAGS: 
   EL_MPI_C_LINK_FLAGS:     -Wl,-rpath  -Wl,/home/poulson/Install/lib
   EL_MPI_C_LIBRARIES:     /home/poulson/Install/lib/libmpich.so;/home/poulson/Install/lib/libopa.so;/home/poulson/Install/lib/libmpl.so;/usr/lib/i386-linux-gnu/librt.so;/usr/lib/i386-linux-gnu/libpthread.so

C++ API
"""""""

.. cpp:function:: void PrintCCompilerInfo( std::ostream& os=std::cout )

C API
"""""

.. c:function:: ElError ElPrintCCompilerInfo( FILE* stream )

Python API
""""""""""

.. py:function:: PrintCCompilerInfo(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

C++ compiler info
^^^^^^^^^^^^^^^^^
The following routines print various details about the C++ compilation process.
For example::

 Elemental's C++ compiler info:
   EL_CMAKE_CXX_COMPILER:    /usr/local/bin/g++
   EL_CXX_FLAGS:             -Wall
   EL_MPI_CXX_COMPILER:      /home/poulson/Install/bin/mpicxx
   EL_MPI_CXX_INCLUDE_PATH:  /home/poulson/Install/include
   EL_MPI_CXX_COMPILE_FLAGS: 
   EL_MPI_CXX_LINK_FLAGS:     -Wl,-rpath  -Wl,/home/poulson/Install/lib
   EL_MPI_CXX_LIBRARIES:     /home/poulson/Install/lib/libmpichcxx.so;/home/poulson/Install/lib/libmpich.so;/home/poulson/Install/lib/libopa.so;/home/poulson/Install/lib/libmpl.so;/usr/lib/i386-linux-gnu/librt.so;/usr/lib/i386-linux-gnu/libpthread.so

C++ API
"""""""

.. cpp:function:: void PrintCxxCompilerInfo( std::ostream& os=std::cout )

C API
"""""

.. c:function:: ElError ElPrintCxxCompilerInfo( FILE* stream )

Python API
""""""""""

.. py:function:: PrintCxxCompilerInfo(f=ctypes.pythonapi.PyFile_AsFile(sys.stdout))

Set up and clean up
-------------------

Initialization
^^^^^^^^^^^^^^
Initializes Elemental and (if necessary) MPI. The usage is very similar to 
``MPI_Init``, but the `argc` and `argv` can be directly passed in.

C++ API
"""""""

.. cpp:function:: void Initialize( int& argc, char**& argv )

.. code-block:: cpp

   #include "El.hpp"
   int main( int argc, char* argv[] )
   {
       El::Initialize( argc, argv );
       // ...
       El::Finalize();
       return 0;
   }

C API
"""""

.. c:function:: ElError ElInitialize( int* argc, char*** argv )

Finalization
^^^^^^^^^^^^
The following routines free all resources allocated by Elemental and 
(if necessary) MPI.

C++ API
"""""""

.. cpp:function:: void Finalize()

C API
"""""

.. c:function:: ElError ElFinalize()

Testing for initialization
^^^^^^^^^^^^^^^^^^^^^^^^^^
Several routines are provided for querying whether or not Elemental is 
currently initialized.

C++ API
"""""""

.. cpp:function:: bool Initialized()

C API
"""""

.. c:function:: ElError ElInitialized( bool* initialized )

Exception handling
^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void ReportException( std::exception& e )

   Used for handling Elemental's various exceptions, e.g.,

   .. code-block:: cpp

      #include "El.hpp"
      int main( int argc, char* argv[] )
      {
          El::Initialize( argc, argv );
          try {
              // ...
          } catch( std::exception& e ) { ReportException(e); }
          El::Finalize();
          return 0;
      }

C API
"""""

Please see the :c:type::`ElError` enum.

Blocksize manipulation
----------------------

.. cpp:function:: Int Blocksize()

   Return the currently chosen algorithmic blocksize. The optimal value 
   depends on the problem size, algorithm, and architecture; the default value
   is 128.

.. cpp:function:: void SetBlocksize( Int blocksize )

   Change the algorithmic blocksize to the specified value.

.. cpp:function:: void PushBlocksizeStack( Int blocksize )

   It is frequently useful to temporarily change the algorithmic blocksize, so 
   rather than having to manually store and reset the current state, one can 
   simply push a new value onto a stack 
   (and later pop the stack to reset the value).

.. cpp:function:: void PopBlocksizeStack() 

   Pops the stack of blocksizes. See above.

.. cpp:function:: Int DefaultBlockHeight()
.. cpp:function:: Int DefaultBlockWidth()

   Returns the default block height (width) for 
   :cpp:type:`BlockDistMatrix\<T,U,V>`.

.. cpp:function:: void SetDefaultBlockHeight( Int mb )
.. cpp:function:: void SetDefaultBlockWidth( Int nb )

   Change the default block height (width) for 
   :cpp:type:`BlockDistMatrix\<T,U,V>`.

Default process grid
--------------------

.. cpp:function:: Grid& DefaultGrid()

   Return a process grid built over :cpp:type:`mpi::COMM_WORLD`. This is 
   typically used as a means of allowing instances of the 
   :cpp:type:`DistMatrix\<T,MC,MR>` class to be constructed without having to 
   manually specify a process grid, e.g., 

   .. code-block:: cpp

      // Build a 10 x 10 distributed matrix over mpi::COMM_WORLD
      El::DistMatrix<T,MC,MR> A( 10, 10 );

Call stack manipulation
-----------------------

.. note::

   The following call stack manipulation routines are only available in 
   non-release builds (i.e., PureDebug and HybridDebug) and are meant to allow 
   for the call stack to be printed (via :cpp:func:`DumpCallStack`) when an 
   exception is caught.

.. cpp:function:: void PushCallStack( std::string s )

   Push the given routine name onto the call stack.

.. cpp:function:: void PopCallStack()

   Remove the routine name at the top of the call stack.

.. cpp:function:: void DumpCallStack()

   Print (and empty) the contents of the call stack.

Error handling
--------------

C++ API
^^^^^^^

.. cpp:type:: SingularMatrixException

   An extension of ``std::runtime_error`` which is meant to be thrown when 
   a singular matrix is unexpectedly encountered.

   .. cpp:function:: SingularMatrixException( const char* msg="Matrix was singular" )

      Builds an instance of the exception which allows one to optionally 
      specify the error message.

   .. code-block:: cpp

      throw El::SingularMatrixException();

.. cpp:type:: NonHPDMatrixException 

   An extension of ``std::runtime_error`` which is meant to be thrown when
   a non positive-definite Hermitian matrix is unexpectedly encountered
   (e.g., during Cholesky factorization).

   .. cpp:function:: NonHPDMatrixException( const char* msg="Matrix was not HPD" )

      Builds an instance of the exception which allows one to optionally 
      specify the error message.

   .. code-block:: cpp

      throw El::NonHPDMatrixException();

.. cpp:type:: NonHPSDMatrixException 

   An extension of ``std::runtime_error`` which is meant to be thrown when
   a non positive semi-definite Hermitian matrix is unexpectedly encountered
   (e.g., during computation of the square root of a Hermitian matrix).

   .. cpp:function:: NonHPSDMatrixException( const char* msg="Matrix was not HPSD" )

      Builds an instance of the exception which allows one to optionally 
      specify the error message.

   .. code-block:: cpp

      throw El::NonHPSDMatrixException();

C API
^^^^^

.. c:type:: ElError

   An enum which can be set to one of the following values:

   * ``EL_SUCCESS``
   * ``EL_ALLOC_ERROR``
   * ``EL_OUT_OF_BOUNDS_ERROR``
   * ``EL_ARG_ERROR``
   * ``EL_LOGIC_ERROR``
   * ``EL_RUNTIME_ERROR``
   * ``EL_ERROR``

.. c:function:: const char* ElErrorString( ElError error )

   Convert the error code into a (hopefully) descriptive message

Complex data
------------

C++ API
^^^^^^^

.. cpp:type:: Complex<Real>

   Currently a typedef of ``std::complex<Real>``

.. cpp:type:: Base<F>

   The underlying real datatype of the (potentially complex) datatype `F`.
   For example, ``Base<Complex<double>>`` and 
   ``Base<double>`` are both equivalent to ``double``.
   This is often extremely useful in implementing routines which are 
   templated over real and complex datatypes but still make use of real 
   datatypes.

.. cpp:function:: std::ostream& operator<<( std::ostream& os, Complex<Real> alpha )

   Pretty prints `alpha` in the form ``a+bi``.

.. cpp:type:: scomplex

   ``typedef Complex<float> scomplex;``

.. cpp:type:: dcomplex

   ``typedef Complex<double> dcomplex;``

C API
^^^^^

.. c:type:: complex_float

   A struct equivalent to ``struct complex_float { float real, imag; }`` which
   is meant to be binary compatible with ``std::complex<float>``.

.. c:type:: complex_double

   A struct equivalent to ``struct complex_double { double real, imag; }``
   which is meant to be binary compatible with ``std::complex<double>``.

Other typedefs and enums
------------------------

C++ API
^^^^^^^

.. cpp:type:: byte

   ``typedef unsigned char byte;``

.. cpp:type:: Int

   Typically a typedef to ``int``, but if the experimental ``EL_USE_64BIT_INTS``
   compilation mode is enabled, it becomes a typedef to ``long long int``,
   which is guaranteed to be at least 64-bit by C++11

.. cpp:type:: Unsigned

   Typically a typedef to ``unsigned``, but if the experimental 
   ``EL_USE_64BIT_INTS`` compilation mode is enabled, it becomes a typedef to 
   ``long long unsigned``, which is guaranteed to be at least 64-bit by C++11

.. cpp:type:: Conjugation

   An enum which can be set to either ``CONJUGATED`` or ``UNCONJUGATED``.

.. cpp:type:: Dist

   An enum for specifying the distribution of a row or column of a distributed
   matrix:

   * ``MC``: Column of a standard matrix distribution
   * ``MD``: Diagonal of a standard matrix distribution
   * ``MR``: Row of a standard matrix distribution
   * ``VC``: Column-major vector distribution
   * ``VR``: Row-major vector distribution
   * ``STAR``: Redundantly stored on every process
   * ``CIRC``: Stored on a single process

.. cpp:type:: ForwardOrBackward

   An enum for specifying ``FORWARD`` or ``BACKWARD``.

.. cpp:type:: GridOrder

   An enum for specifying either a ``ROW_MAJOR`` or ``COLUMN_MAJOR`` ordering;
   it is used to decide how to construct process grids and is also useful for 
   tuning one of the algorithms in :cpp:func:`HermitianTridiag`
   which requires building a smaller square process grid from a rectangular 
   process grid, as the ordering of the processes can greatly impact 
   performance. See :cpp:func:`SetHermitianTridiagGridOrder`.

.. cpp:type:: LeftOrRight

   An enum for specifying ``LEFT`` or ``RIGHT``.

.. cpp:type:: SortType

   An enum for specifying a sorting strategy:

   * ``UNSORTED``: do not sort
   * ``DESCENDING``: smallest values first
   * ``ASCENDING``: largest values first

.. cpp:type:: NormType

   An enum that can be set to either

   * ``ONE_NORM``:

     .. math:: 

        \|A\|_1 = \max_{\|x\|_1=1} \|Ax\|_1 
                = \max_j \sum_{i=0}^{m-1} |\alpha_{i,j}|

   * ``INFINITY_NORM``:

     .. math:: 

        \|A\|_{\infty} = \max_{\|x\|_{\infty}=1} \|Ax\|_{\infty} 
                       = \max_i \sum_{j=0}^{n-1} |\alpha_{i,j}|

   * ``ENTRYWISE_ONE_NORM``:

     .. math::

       \|\text{vec}(A)\|_1 = \sum_{i,j} |\alpha_{i,j}|

   * ``MAX_NORM``:

     .. math::
     
        \|A\|_{\mbox{max}} = \max_{i,j} |\alpha_{i,j}|

   * ``NUCLEAR_NORM``:

     .. math::

        \|A\|_* = \sum_{i=0}^{\min(m,n)} \sigma_i(A)

   * ``FROBENIUS_NORM``:

     .. math::

        \|A\|_F = \sqrt{\sum_{i=0}^{m-1} \sum_{j=0}^{n-1} |\alpha_{i,j}|^2}
                = \sum_{i=0}^{\min(m,n)} \sigma_i(A)^2

   * ``TWO_NORM``:

     .. math::

        \|A\|_2 = \max_i \sigma_i(A)
  
.. cpp:type:: Orientation

   An enum for specifying whether a matrix, say :math:`A`, should be implicitly 
   treated as :math:`A` (``NORMAL``), :math:`A^H` (``ADJOINT``), or :math:`A^T`
   (``TRANSPOSE``).

.. cpp:type:: UnitOrNonUnit

   An enum for specifying either ``UNIT`` or ``NON_UNIT``; typically used for 
   stating whether or not a triangular matrix's diagonal is explicitly stored
   (``NON_UNIT``) or is implicitly unit-diagonal (``UNIT``).

.. cpp:type:: UpperOrLower

   An enum for specifying ``LOWER`` or ``UPPER`` (triangular).

.. cpp:type:: VerticalOrHorizontal

   An enum for specifying ``VERTICAL`` or ``HORIZONTAL``.

C API
^^^^^
The following are analogues to the above C++ definitions.

.. c:type:: ElByte

   A typedef to ``unsigned char``

.. c:type:: ElInt

   Typically a typedef to ``int``, but if the experimental ``EL_USE_64BIT_INTS``
   compilation mode is enabled, it becomes a typedef to ``long long int``

.. c:type:: ElUnsigned

   Typically a typedef to ``unsigned``, but if the experimental 
   ``EL_USE_64BIT_INTS`` compilation mode is enabled, it becomes a typedef to 
   ``long long unsigned``

.. c:type:: ElConjugation

   An enum equal to either ``EL_CONJUGATED`` or ``EL_UNCONJUGATED``

.. c:type:: ElDist

   An enum equal to one of:

   * ``EL_MC``
   * ``EL_MD``
   * ``EL_MR``
   * ``EL_STAR``
   * ``EL_VC``
   * ``EL_VR``
   * ``EL_CIRC``

.. c:type:: ElForwardOrBackward

   An enum equal to either ``EL_FORWARD`` or ``EL_BACKWARD``

.. c:type:: ElGridOrder

   An enum equal to either ``EL_ROW_MAJOR`` or ``EL_COLUMN_MAJOR``

.. c:type:: ElLeftOrRight

   An enum equal to either ``EL_LEFT`` or ``EL_RIGHT``

.. c:type:: ElSortType

   An enum equal to ``EL_UNSORTED``, ``EL_ASCENDING``, or ``EL_DESCENDING``

.. c:type:: ElNormType

   An enum equal to one of:

   * ``EL_ONE_NORM``
   * ``EL_INFINITY_NORM``
   * ``EL_ENTRYWISE_ONE_NORM``
   * ``EL_MAX_NORM``
   * ``EL_NUCLEAR_NORM``
   * ``EL_FROBENIUS_NORM``
   * ``EL_TWO_NORM``

.. c:type:: ElOrientation

   An enum equal to ``EL_NORMAL``, ``EL_TRANSPOSE``, or ``EL_ADJOINT``

.. c:type:: ElUnitOrNonUnit

   An enum equal to either ``EL_UNIT`` or ``EL_NON_UNIT``

.. c:type:: ElUpperOrLower

   An enum equal to either ``EL_UPPER`` or ``EL_LOWER``

.. c:type:: ElVerticalOrHorizontal

   An enum equal to either ``EL_VERTICAL`` or ``EL_HORIZONTAL``

Indexing utilities
------------------

.. cpp:function:: Int Shift( Int rank, Int firstRank, Int numProcs )

   Given a element-wise cyclic distribution over `numProcs` processes, 
   where the first entry is owned by the process with rank `firstRank`, 
   this routine returns the first entry owned by the process with rank
   `rank`.

.. cpp:function:: Int Length( Int n, Int shift, Int numProcs )

   Given a vector with :math:`n` entries distributed over `numProcs` 
   processes with shift as defined above, this routine returns the number of 
   entries of the vector which are owned by this process.

.. cpp:function:: Int Length( Int n, Int rank, Int firstRank, Int numProcs )

   Given a vector with :math:`n` entries distributed over `numProcs` 
   processes, with the first entry owned by process `firstRank`, this routine
   returns the number of entries locally owned by the process with rank 
   `rank`.

.. cpp:function:: Int MaxLength( Int n, Int numProcs )

   The maximum result of :cpp:func:`Length` with the given parameters.
   This is useful for padding collective communication routines which are
   almost regular.

.. cpp:function:: Int Mod( Int a, Int b )

   An extension of C++'s ``%`` operator which handles cases where `a` is 
   negative and still returns a result in :math:`[0,b)`.

.. cpp:function:: Int GCD( Int a, Int b )

   Return the greatest common denominator of the integers `a` and `b`.

.. cpp:function:: Unsigned Log2( Unsigned n )

   Return the base-two logarithm of a positive integer.

.. cpp:function:: bool PowerOfTwo( Unsigned n )

   Return whether or not a positive integer is an integer power of two.
