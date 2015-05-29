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

.. cpp:enum:: Conjugation

   .. cpp:enumerator:: CONJUGATED

   .. cpp:enumerator:: UNCONJUGATED

.. cpp:enum:: Dist

   For specifying the distribution of a row or column of a distributed matrix:

   .. cpp:enumerator:: MC

      Column of a standard matrix distribution

   .. cpp:enumerator:: MD

      Diagonal of a standard matrix distribution

   .. cpp:enumerator:: MR

      Row of a standard matrix distribution

   .. cpp:enumerator:: VC

      Column-major vector distribution

   .. cpp:enumerator:: VR

      Row-major vector distribution

   .. cpp:enumerator:: STAR

      Redundantly stored on every process

   .. cpp:enumerator:: CIRC

      Stored on a single process

.. cpp:enum:: ForwardOrBackward

   .. cpp:enumerator:: FORWARD

   .. cpp:enumerator:: BACKWARD

.. cpp:enum:: GridOrder

   For specifying either a ``ROW_MAJOR`` or ``COLUMN_MAJOR`` ordering;
   it is used to decide how to construct process grids and is also useful for 
   tuning one of the algorithms in :cpp:func:`HermitianTridiag`
   which requires building a smaller square process grid from a rectangular 
   process grid, as the ordering of the processes can greatly impact 
   performance. See :cpp:func:`SetHermitianTridiagGridOrder`.

   .. cpp:enumerator:: ROW_MAJOR

   .. cpp:enumerator:: COLUMN_MAJOR

.. cpp:enum:: LeftOrRight

   .. cpp:enumerator:: LEFT

   .. cpp:enumerator:: RIGHT

.. cpp:enum:: SortType

   .. cpp:enumerator:: UNSORTED

      Do not sort.

   .. cpp:enumerator:: DESCENDING

      Smallest values first.

   .. cpp:enumerator:: ASCENDING

      Largest values first.

.. cpp:enum:: NormType

   .. cpp:enumerator:: ONE_NORM

      .. math:: 

         \|A\|_1 = \max_{\|x\|_1=1} \|Ax\|_1 
                 = \max_j \sum_{i=0}^{m-1} |\alpha_{i,j}|

   .. cpp:enumerator:: INFINITY_NORM

      .. math:: 

         \|A\|_{\infty} = \max_{\|x\|_{\infty}=1} \|Ax\|_{\infty} 
                        = \max_i \sum_{j=0}^{n-1} |\alpha_{i,j}|

   .. cpp:enumerator:: ENTRYWISE_ONE_NORM

      .. math::

        \|\text{vec}(A)\|_1 = \sum_{i,j} |\alpha_{i,j}|

   .. cpp:enumerator:: MAX_NORM

      .. math::
     
         \|A\|_{\mbox{max}} = \max_{i,j} |\alpha_{i,j}|

   .. cpp:enumerator:: NUCLEAR_NORM

      .. math::

         \|A\|_* = \sum_{i=0}^{\min(m,n)} \sigma_i(A)

   .. cpp:enumerator:: FROBENIUS_NORM

      .. math::

         \|A\|_F = \sqrt{\sum_{i=0}^{m-1} \sum_{j=0}^{n-1} |\alpha_{i,j}|^2}
                 = \sum_{i=0}^{\min(m,n)} \sigma_i(A)^2

   .. cpp:enumerator:: TWO_NORM

      .. math::

         \|A\|_2 = \max_i \sigma_i(A)
  
.. cpp:enum:: Orientation

   .. cpp:enumerator:: NORMAL

      Do not transpose or conjugate

   .. cpp:enumerator:: TRANSPOSE
 
      Transpose without conjugation

   .. cpp:enumerator:: ADJOINT

      Transpose and conjugate

.. cpp:enum:: UnitOrNonUnit

   .. cpp:enumerator:: UNIT

   .. cpp:enumerator:: NON_UNIT

.. cpp:enum:: UpperOrLower

   .. cpp:enumerator:: LOWER

   .. cpp:enumerator:: UPPER

.. cpp:enum:: VerticalOrHorizontal

   .. cpp:enumerator:: VERTICAL

   .. cpp:enumerator:: HORIZONTAL

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
