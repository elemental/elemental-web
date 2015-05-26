Other typedefs and enums
========================

C++ API
-------

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
-----
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
