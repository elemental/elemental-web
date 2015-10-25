Input/output
************

Display
-------
If Qt5 was detected during Elemental's configuration process, the following
routines draw data structures on screen; otherwise, they print entries to
the standard output stream (i.e., ``std::cout``).

Dense matrices
^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Display( const Matrix<T>& A, std::string title="Matrix" )
.. cpp:function:: void Display( const AbstractDistMatrix<T>& A, std::string title="DistMatrix" )

C API
"""""

.. c:function:: ElError ElDisplay_i( ElConstMatrix_i A, const char* title )
.. c:function:: ElError ElDisplay_s( ElConstMatrix_s A, const char* title )
.. c:function:: ElError ElDisplay_d( ElConstMatrix_d A, const char* title )
.. c:function:: ElError ElDisplay_c( ElConstMatrix_c A, const char* title )
.. c:function:: ElError ElDisplay_z( ElConstMatrix_z A, const char* title )
.. c:function:: ElError ElDisplayDist_i( ElConstDistMatrix_i A, const char* title )
.. c:function:: ElError ElDisplayDist_s( ElConstDistMatrix_s A, const char* title )
.. c:function:: ElError ElDisplayDist_d( ElConstDistMatrix_d A, const char* title )
.. c:function:: ElError ElDisplayDist_c( ElConstDistMatrix_c A, const char* title )
.. c:function:: ElError ElDisplayDist_z( ElConstDistMatrix_z A, const char* title )

Graphs and sparse matrices
^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Display( const Graph& graph, std::string title="Graph" )
.. cpp:function:: void Display( const DistGraph& graph, std::string title="DistGraph" )
.. cpp:function:: void Display( const SparseMatrix<T>& A, std::string title="SparseMatrix" )
.. cpp:function:: void Display( const DistSparseMatrix<T>& A, std::string title="DistSparseMatrix" )

C API
"""""

**TODO**

Sparse-direct data structures
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void DisplayLocal( const DistSymmInfo& info, bool beforeFact, std::string title="" )

C API
"""""

**TODO**

Print
-----
The following routines print a given matrix or graph to a given output stream
(which defaults to ``std::cout``).

Dense matrices
^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Print( const Matrix<T>& A, std::string title="Matrix", std::ostream& os=std::cout )
.. cpp:function:: void Print( const AbstractDistMatrix<T>& A, std::string title="DistMatrix", std::ostream& os=std::cout )

C API
"""""

.. c:function:: ElError ElPrint_i( ElConstMatrix_i A, const char* title )
.. c:function:: ElError ElPrint_s( ElConstMatrix_s A, const char* title )
.. c:function:: ElError ElPrint_d( ElConstMatrix_d A, const char* title )
.. c:function:: ElError ElPrint_c( ElConstMatrix_c A, const char* title )
.. c:function:: ElError ElPrint_z( ElConstMatrix_z A, const char* title )
.. c:function:: ElError ElPrintDist_i( ElConstDistMatrix_i A, const char* title )
.. c:function:: ElError ElPrintDist_s( ElConstDistMatrix_s A, const char* title )
.. c:function:: ElError ElPrintDist_d( ElConstDistMatrix_d A, const char* title )
.. c:function:: ElError ElPrintDist_c( ElConstDistMatrix_c A, const char* title )
.. c:function:: ElError ElPrintDist_z( ElConstDistMatrix_z A, const char* title )

Graphs and sparse matrices
^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Print( const Graph& graph, std::string title="Graph", std::ostream& os=std::cout )
.. cpp:function:: void Print( const DistGraph& graph, std::string title="DistGraph", std::ostream& os=std::cout )
.. cpp:function:: void Print( const SparseMatrix<T>& A, std::string title="SparseMatrix", std::ostream& os=std::cout )
.. cpp:function:: void Print( const DistSparseMatrix<T>& A, std::string title="DistSparseMatrix", std::ostream& os=std::cout )

C API
"""""

**TODO**

Sparse-direct data structures
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void PrintLocal( const DistSymmInfo& info, std::string title="Local DistSymmInfo", std::ostream& os=std::cout )

C API
"""""

**TODO**

Utilities
^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Print( const std::vector<T>& x, std::string title="std::vector", std::ostream& os=std::cout )

Spy
---
If Qt5 was detected during configuration, then the following routines display
a sply plot of the elements of a matrix with absolute values greater than or 
equal to a given tolerance, ``tol``.

Dense matrices
^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Spy( const Matrix<T>& A, std::string title="Matrix", Base<T> tol=0 )
.. cpp:function:: void Spy( const AbstractDistMatrix<T>& A, std::string title="DistMatrix", Base<T> tol=0 )

C API
"""""

.. c:function:: ElError ElSpy_i( ElConstMatrix_i A, const char* title, ElInt tol )
.. c:function:: ElError ElSpy_s( ElConstMatrix_s A, const char* title, float tol )
.. c:function:: ElError ElSpy_d( ElConstMatrix_d A, const char* title, double tol )
.. c:function:: ElError ElSpy_c( ElConstMatrix_c A, const char* title, float tol )
.. c:function:: ElError ElSpy_z( ElConstMatrix_z A, const char* title, double tol )
.. c:function:: ElError ElSpyDist_i( ElConstDistMatrix_i A, const char* title, ElInt tol )
.. c:function:: ElError ElSpyDist_s( ElConstDistMatrix_s A, const char* title, float tol )
.. c:function:: ElError ElSpyDist_d( ElConstDistMatrix_d A, const char* title, double tol )
.. c:function:: ElError ElSpyDist_c( ElConstDistMatrix_c A, const char* title, float tol )
.. c:function:: ElError ElSpyDist_z( ElConstDistMatrix_z A, const char* title, double tol )

Read
----

File formats
^^^^^^^^^^^^
.. note::

   In the case that a ``BINARY_FLAT`` file is read, the formed matrix should
   have already been of the correct size before reading.

C++ API
"""""""

.. cpp:enum:: FileFormat

   .. cpp:enumerator:: AUTO

      Attempt to detect format from filename extension

   .. cpp:enumerator:: ASCII

      Simple ASCII text file

   .. cpp:enumerator:: ASCII_MATLAB

      MATLAB-ready ASCII text file

   .. cpp:enumerator:: BINARY

      Column-major binary file with integer height and width header

   .. cpp:enumerator:: BINARY_FLAT

      Column-major binary file with no header data

   .. cpp:enumerator:: BMP

      Bitmap image format (requires Qt5)

   .. cpp:enumerator:: MATRIX_MARKET

      Matrix Market format

   .. cpp:enumerator:: JPG

      JPG image format (requires Qt5)

   .. cpp:enumerator:: JPEG

      JPEG image format (requires Qt5)

   .. cpp:enumerator:: PNG

      PNG image format (requires Qt5)

   .. cpp:enumerator:: PPM

      PPM image format (requires Qt5)

   .. cpp:enumerator:: XBM

      XBM image format (requires Qt5)
 
   .. cpp:enumerator:: XPM

      XPM image format (requires Qt5)

C API
"""""

.. c:type:: ElFileFormat

   An enum that can take on the following values:

   * ``EL_AUTO``: attempt to detect format from filename extension
   * ``EL_ASCII``: simple ASCII text file
   * ``EL_ASCII_ASCII``: MATLAB-ready ASCII text file
   * ``EL_BINARY``: column-major binary file with integer height and width header
   * ``EL_BINARY_FLAT``: column-major binary file with no header data
   * ``EL_BMP``: bitmap image format (requires Qt5)
   * ``EL_MATRIX_MARKET``: Matrix Market format
   * ``EL_JPG``: JPG image format (requires Qt5)
   * ``EL_JPEG``: JPEG image format (requires Qt5)
   * ``EL_PNG``: PNG image format (requires Qt5)
   * ``EL_PPM``: PPM image format (requires Qt5)
   * ``EL_XBM``: XBM image format (requires Qt5)
   * ``EL_XPM``: XPM image format (requires Qt5)

Dense matrices
^^^^^^^^^^^^^^
Elemental supports reading matrices from several different file formats (at the moment, ``ASCII``, ``BINARY``, ``BINARY_FLAT`` and ``MATRIX_MARKET``).
In the distributed case, the ``sequential`` flag determines whether or not 
the data should be read from file by a single process and then afterward 
scattered to the entire set of processes.

C++ API
"""""""

.. cpp:function:: void Read( Matrix<T>& A, std::string filename, FileFormat format=AUTO )
.. cpp:function:: void Read( AbstractDistMatrix<T>& A, std::string filename, FileFormat format=AUTO, bool sequential=false )

C API
"""""

.. c:function:: ElError ElRead_i( ElMatrix_i A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElRead_s( ElMatrix_s A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElRead_d( ElMatrix_d A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElRead_c( ElMatrix_c A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElRead_z( ElMatrix_z A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElReadDist_i( ElMatrix_i A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElReadDist_s( ElMatrix_s A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElReadDist_d( ElMatrix_d A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElReadDist_c( ElMatrix_c A, const char* filename, ElFileFormat format )
.. c:function:: ElError ElReadDist_z( ElMatrix_z A, const char* filename, ElFileFormat format )

Write
-----
Elemental also supports writing matrices to disk in various file formats.
However, please note that Qt5 is currently required for writing to image 
formats.

Dense matrices
^^^^^^^^^^^^^^

C++ API
"""""""

.. cpp:function:: void Write( const Matrix<T>& A, std::string basename="Matrix", FileFormat format=BINARY, std::string title="" )
.. cpp:function:: void Write( const AbstractDistMatrix<T>& A, std::string basename="DistMatrix", FileFormat format=BINARY, std::string title="" )

C API
"""""

.. c:function:: ElError ElWrite_i( ElConstMatrix_i A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWrite_s( ElConstMatrix_s A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWrite_d( ElConstMatrix_d A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWrite_c( ElConstMatrix_c A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWrite_z( ElConstMatrix_z A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWriteDist_i( ElConstDistMatrix_i A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWriteDist_s( ElConstDistMatrix_s A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWriteDist_d( ElConstDistMatrix_d A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWriteDist_c( ElConstDistMatrix_c A, const char* basename, ElFileFormat format, const char* title )
.. c:function:: ElError ElWriteDist_z( ElConstDistMatrix_z A, const char* basename, ElFileFormat format, const char* title )
