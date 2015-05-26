Error handling
==============

C++ API
-------

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
-----

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
