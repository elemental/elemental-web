Half-open range
---------------
It is useful to represent intervals in the half-open form :math:`[a,b)`, as
this representation easily allows for expressing empty index intervals without
the usage of negative numbers, e.g., :math:`[0,0)`.

C++ API
^^^^^^^

.. cpp:type:: Range<T>

   .. cpp:member:: T beg
   .. cpp:member:: T end

   .. cpp:function:: Range()
      
      Initializes `beg` and `end` to zero

   .. cpp:function:: Range( T begArg, T endArg )

      Initializes `beg` to `begArg` and `end` to `endArg`

   .. cpp:function:: Range<T> operator+( T shift ) const

      Returns a copy of this object but with the beginning and end values
      increased by `shift`

   .. cpp:function:: Range<T> operator-( T shift ) const

      Returns a copy of this object but with the beginning and end values
      decreased by `shift`

.. cpp:type:: Range<Int>
.. cpp:type:: Range<float>
.. cpp:type:: Range<double>

.. cpp:type:: IR

   A typedef to :cpp:type:`Range\<Int>` which is convenient when extracting
   contiguous submatrices

C API
^^^^^

.. c:type:: Range_i

   .. c:member:: ElInt beg
   .. c:member:: ElInt end

.. c:type:: Range_s

   .. c:member:: float beg
   .. c:member:: float end

.. c:type:: Range_d

   .. c:member:: double beg
   .. c:member:: double end
