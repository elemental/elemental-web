Boiler plate
============

Initialization
--------------
Initializes Elemental and (if necessary) MPI. The usage is very similar to 
``MPI_Init``, but the `argc` and `argv` can be directly passed in.

C++ API
^^^^^^^

.. cpp:function:: void Initialize()
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
^^^^^

.. c:function:: ElError ElInitialize( int* argc, char*** argv )

Finalization
------------
The following routines free all resources allocated by Elemental and 
(if necessary) MPI.

C++ API
^^^^^^^

.. cpp:function:: void Finalize()

C API
^^^^^

.. c:function:: ElError ElFinalize()

Testing for initialization
--------------------------
Several routines are provided for querying whether or not Elemental is 
currently initialized.

C++ API
^^^^^^^

.. cpp:function:: bool Initialized()

C API
^^^^^

.. c:function:: ElError ElInitialized( bool* initialized )

Exception handling
------------------

C++ API
^^^^^^^

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
^^^^^

Please see the :c:type::`ElError` enum.

