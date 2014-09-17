Skeleton decomposition
======================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack-like/factor/Skeleton.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack-like/Skeleton.cpp>`__

Skeleton decompositions are essentially two-sided interpolative decompositions,
but the terminology is unfortunately extremely contested. We follow the 
convention that a skeleton decomposition is an approximation

.. math::

   A \approx A_C Z A_R,

where :math:`A_C` is a (small) selection of columns of :math:`A`, 
:math:`A_R` is a (small) selection of rows of :math:`A`, and :math:`Z` is a 
(small) square matrix. When :math:`Z` is allowed to be rectangular, it is more
common to call this a CUR decomposition.

Note that the following routines do not directly return :math:`A_R` and 
:math:`A_C`; the permutation matrices which implicitly define them are 
returned instead. 

C++ API
-------

.. cpp:function:: void Skeleton( const Matrix<F>& A, Matrix<int>& pR, Matrix<int>& pC, Matrix<F>& Z, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )
.. cpp:function:: void Skeleton( const AbstractDistMatrix<F>& A, AbstractDistMatrix<int>& pR, AbstractDistMatrix<int>& pC, const QRCtrl<Base<F>> ctrl=QRCtrl<Base<F>>() )

C API
-----

.. c:function:: ElError ElSkeleton_s( ElConstMatrix_s A, ElMatrix_i pR, ElMatrix_i pC, ElMatrix_s Z, ElQRCtrl_s ctrl )
.. c:function:: ElError ElSkeleton_d( ElConstMatrix_d A, ElMatrix_i pR, ElMatrix_i pC, ElMatrix_d Z, ElQRCtrl_d ctrl )
.. c:function:: ElError ElSkeleton_c( ElConstMatrix_c A, ElMatrix_i pR, ElMatrix_i pC, ElMatrix_c Z, ElQRCtrl_s ctrl )
.. c:function:: ElError ElSkeleton_z( ElConstMatrix_z A, ElMatrix_i pR, ElMatrix_i pC, ElMatrix_z Z, ElQRCtrl_d ctrl )
.. c:function:: ElError ElSkeletonDist_s( ElConstDistMatrix_s A, ElDistMatrix_i pR, ElDistMatrix_i pC, ElDistMatrix_s Z, ElQRCtrl_s ctrl )
.. c:function:: ElError ElSkeletonDist_d( ElConstDistMatrix_d A, ElDistMatrix_i pR, ElDistMatrix_i pC, ElDistMatrix_d Z, ElQRCtrl_d ctrl )
.. c:function:: ElError ElSkeletonDist_c( ElConstDistMatrix_c A, ElDistMatrix_i pR, ElDistMatrix_i pC, ElDistMatrix_c Z, ElQRCtrl_s ctrl )
.. c:function:: ElError ElSkeletonDist_z( ElConstDistMatrix_z A, ElDistMatrix_i pR, ElDistMatrix_i pC, ElDistMatrix_z Z, ElQRCtrl_d ctrl )

