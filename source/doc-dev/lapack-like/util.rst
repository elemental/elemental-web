Utilities
=========

Median
------

.. cpp:function:: ValueInt<Real> Median( const Matrix<Real>& x )
.. cpp:function:: ValueInt<Real> Median( const AbstractDistMatrix<Real>& x )

Sorting
-------

.. cpp:function:: void Sort( Matrix<Real>& X, SortType sort=ASCENDING )
.. cpp:function:: void Sort( AbstractDistMatrix<Real>& X, SortType sort=ASCENDING )

.. cpp:function:: std::vector<ValueInt<Real> > TaggedSort( const Matrix<Real>& X, SortType sort=ASCENDING )
.. cpp:function:: std::vector<ValueInt<Real> > TaggedSort( const AbstractDistMatrix<Real>& X, SortType sort=ASCENDING )

