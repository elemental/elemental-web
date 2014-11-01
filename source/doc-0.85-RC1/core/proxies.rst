Read/write proxies
==================
Elemental provides a number of routines which provide cheap 
(:math:`O(1)` if possible) conversion mechanisms for allowing a matrix to be
operated on via a particular datatype and distribution.

Read proxy
----------
A smart pointer to a matrix with the requested datatype and distribution,
but filled with the (distributed) contents of the input matrix, is returned.

.. cpp:function:: std::shared_ptr<const Matrix<T>> ReadProxy( const Matrix<S>* A )
.. cpp:function:: std::shared_ptr<const DistMatrix<T,U,V>> ReadProxy( const AbstractDistMatrix<S>* A, const ProxyCtrl& ctrl=ProxyCtrl() )

   For immutable inputs, the output is also immutable

.. cpp:function:: std::shared_ptr<Matrix<T>> ReadProxy( Matrix<S>* A )
.. cpp:function:: std::shared_ptr<DistMatrix<T,U,V>> ReadProxy( AbstractDistMatrix<S>* A, const ProxyCtrl& ctrl=ProxyCtrl() )

   For mutable inputs, the output is also mutable

Read-write proxy
----------------
A smart pointer to a matrix with the requested datatype and distribution,
but filled with the (distributed) contents of the input matrix, is returned.
When the shared pointer goes out of scope, the (modified) matrix is copied
back into :math:`A`.

.. cpp:function:: std::shared_ptr<Matrix<T>> ReadWriteProxy( Matrix<S>* A )
.. cpp:function:: std::shared_ptr<DistMatrix<T,U,V>> ReadWriteProxy( AbstractDistMatrix<S>* A, const ProxyCtrl& ctrl=ProxyCtrl() )

Write proxy
-----------
A smart pointer to a matrix with the requested datatype and distribution
is returned and, when the object goes out of scope, the matrix is copied into
:math:`A`.

.. cpp:function:: std::shared_ptr<Matrix<T>> WriteProxy( Matrix<S>* A )
.. cpp:function:: std::shared_ptr<DistMatrix<T,U,V>> WriteProxy( AbstractDistMatrix<S>* A, const ProxyCtrl& ctrl=ProxyCtrl() )

Configuring the proxy
---------------------

.. cpp:type:: ProxyCtrl

   .. cpp:member:: bool colConstrain
   .. cpp:member:: bool rowConstrain
   .. cpp:member:: bool rootConstrain
   .. cpp:member:: Int colAlign
   .. cpp:member:: Int rowAlign
   .. cpp:member:: Int root

   .. cpp:function:: ProxyCtrl()

      Initializes all booleans to false and all integers to zero.

