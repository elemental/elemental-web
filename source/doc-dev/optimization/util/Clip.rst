Clip
====
Force every entry of a matrix to lie within a given (half-)interval.

`Implementations <https://github.com/elemental/Elemental/blob/master/src/optimization/Clip.cpp>`__

Lower clip
----------
Force every entry to be at least `lowerBound`.

C++ API
^^^^^^^

.. cpp:function:: void LowerClip( Matrix<Real>& X, Real lowerBound=0 )
.. cpp:function:: void LowerClip( AbstractDistMatrix<Real>& X, Real lowerBound=0 )

C API
^^^^^

.. c:function:: ElError ElLowerClip_s( ElMatrix_s X, float lowerBound )
.. c:function:: ElError ElLowerClip_d( ElMatrix_d X, double lowerBound )
.. c:function:: ElError ElLowerClipDist_s( ElDistMatrix_s X, float lowerBound )
.. c:function:: ElError ElLowerClipDist_d( ElDistMatrix_d X, double lowerBound )

Upper clip
----------
Force every entry to be at most `upperBound`.

C++ API
^^^^^^^

.. cpp:function:: void UpperClip( Matrix<Real>& X, Real upperBound=0 )
.. cpp:function:: void UpperClip( AbstractDistMatrix<Real>& X, Real upperBound=0 )

C API
^^^^^

.. c:function:: ElError ElUpperClip_s( ElMatrix_s X, float upperBound )
.. c:function:: ElError ElUpperClip_d( ElMatrix_d X, double upperBound )
.. c:function:: ElError ElUpperClipDist_s( ElDistMatrix_s X, float upperBound )
.. c:function:: ElError ElUpperClipDist_d( ElDistMatrix_d X, double upperBound )

Interval clip
-------------
Force every entry to lie within the interval defined by `lowerBound` and 
`upperBound`.

C++ API
^^^^^^^

.. cpp:function:: void Clip( Matrix<Real>& X, Real lowerBound=0, Real upperBound=1 )
.. cpp:function:: void Clip( AbstractDistMatrix<Real>& X, Real lowerBound=0, Real upperBound=1 )

C API
^^^^^

.. c:function:: ElError ElClip_s( ElMatrix_s X, float lowerBound, float upperBound )
.. c:function:: ElError ElClip_d( ElMatrix_d X, double lowerBound, double upperBound )
.. c:function:: ElError ElClipDist_s( ElDistMatrix_s X, float lowerBound, float upperBound )
.. c:function:: ElError ElClipDist_d( ElDistMatrix_d X, double lowerBound, double upperBound )
