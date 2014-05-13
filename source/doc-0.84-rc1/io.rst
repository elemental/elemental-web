Input/output
************

.. cpp:type:: enum FileFormat

   * ``AUTO``: attempt to detect format from filename extension
   * ``ASCII``: simple ASCII text file
   * ``ASCII_ASCII``: MATLAB-ready ASCII text file
   * ``BINARY``: column-major binary file with integer height and width header
   * ``BINARY_FLAT``: column-major binary file with no header data
   * ``BMP``: bitmap image format (requires Qt5)
   * ``MATRIX_MARKET``: Matrix Market format
   * ``JPG``: JPG image format (requires Qt5)
   * ``JPEG``: JPEG image format (requires Qt5)
   * ``PNG``: PNG image format (requires Qt5)
   * ``PPM``: PPM image format (requires Qt5)
   * ``XBM``: XBM image format (requires Qt5)
   * ``XPM``: XPM image format (requires Qt5)

Display
-------

.. cpp:function:: void Display( const Matrix<T>& A, std::string title="Default" )
.. cpp:function:: void Display( const DistMatrix<T,U,V>& A, std::string title="Default" )

   If Qt5 was detected during configuration, display the matrix on screen.
   Otherwise, print it to the console.

Print
-----

.. cpp:function:: void Print( const Matrix<T>& A, std::string title="", std::ostream& os=std::cout )
.. cpp:function:: void Print( const DistMatrix<T,U,V>& A, std::string title="", std::ostream& os=std::cout )

   Prints the matrix to the console.

Spy
---

.. cpp:function:: void Spy( const Matrix<T>& A, std::string title="Default", Base<T> tol=0 )
.. cpp:function:: void Spy( const DistMatrix<T,U,V>& A, std::string title="Default", Base<T> tol=0 )

   Only available if Qt5 was detected during configuration. A spy plot of 
   the elements with absolute values greater than or equal to ``tol`` is 
   displayed on screen.

Read
----

.. cpp:function:: void Read( Matrix<T>& A, std::string filename, FileFormat format=AUTO )
.. cpp:function:: void Read( DistMatrix<T,U,V>& A, std::string filename, FileFormat format=AUTO, bool sequential=false )

   Read the specified matrix from a file with a supported format. As of now,
   only the ``ASCII``, ``BINARY``, ``BINARY_FLAT`` and ``MATRIX_MARKET`` formats 
   are supported. 
   In the distributed case, the ``sequential`` flag determines whether or not 
   the data should be read from a single process and then scattered to the 
   other processes as necessary.

   .. note::

      In the case that a ``BINARY_FLAT`` file is read, `A` should already have
      the correct dimensions.

Write
-----

.. cpp:function:: void Write( const Matrix<T>& A, std::string basename="matrix", FileFormat format=BINARY, std::string title="" )
.. cpp:function:: void Write( const DistMatrix<T,U,V>& A, std::string basename="matrix", FileFormat format=BINARY, std::string title="" )

   The matrix is written to a file (the given basename plus the appropriate extension) in the specified format. Note that Qt5 is required for the image formats.
