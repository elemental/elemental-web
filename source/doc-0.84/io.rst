Input/output
************

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
