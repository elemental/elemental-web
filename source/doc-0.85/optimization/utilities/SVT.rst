Singular-value soft-thresholding
================================
Overwrites :math:`A` with :math:`U S_{\tau}(\Sigma) V^H`, where :math:`U \Sigma V^H` is the singular-value decomposition of :math:`A` upon input and :math:`S_{\tau}` performs soft-thresholding with parameter :math:`\tau`.
The return value is the rank of the soft-thresholded matrix.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/optimization/SVT.cpp>`__

Standard algorithm
------------------
Runs the default SVT algorithm. In the sequential case, this is currently
`svt::Normal`, and, in the parallel case, it is `svt::Cross`.

C++ API
^^^^^^^

.. cpp:function:: Int SVT( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: Int SVT( AbstractDistMatrix<F>& A, Base<F> tau, bool relative=false )

C API
^^^^^

.. c:function:: ElError ElSVT_s( ElMatrix_s A, float rho, bool relative )
.. c:function:: ElError ElSVT_d( ElMatrix_d A, double rho, bool relative )
.. c:function:: ElError ElSVT_c( ElMatrix_c A, float rho, bool relative )
.. c:function:: ElError ElSVT_z( ElMatrix_z A, double rho, bool relative )
.. c:function:: ElError ElSVTDist_s( ElDistMatrix_s A, float rho, bool relative )
.. c:function:: ElError ElSVTDist_d( ElDistMatrix_d A, double rho, bool relative )
.. c:function:: ElError ElSVTDist_c( ElDistMatrix_c A, float rho, bool relative )
.. c:function:: ElError ElSVTDist_z( ElDistMatrix_z A, double rho, bool relative )

Approximate algorithm
---------------------
Runs a faster (for small ranks), but less accurate, algorithm given an
upper bound on the rank of the soft-thresholded matrix.
The current implementation preprocesses via `relaxedRank` steps of 
(Businger-Golub) column-pivoted QR via the routine `svt::PivotedQR`.

C++ API
^^^^^^^

.. cpp:function:: Int SVT( Matrix<F>& A, Base<F> tau, Int relaxedRank, bool relative=false )
.. cpp:function:: Int SVT( AbstractDistMatrix<F>& A, Base<F> tau, Int relaxedRank, bool relative=false )

C API
^^^^^

**TODO**

Tall-skinny algorithm
---------------------
Runs an SVT algorithm designed for tall-skinny matrices. 
The current implementation is based on TSQR factorization and is
`svt::TSQR`.

C++ API
^^^^^^^

.. cpp:function:: Int SVT( DistMatrix<F,U,STAR>& A, Base<F> tau, bool relative=false )

C API
^^^^^

**TODO**

namespace svt
-------------

.. cpp:function:: Int svt::Normal( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: Int svt::Normal( AbstractDistMatrix<F>& A, Base<F> tau, bool relative=false )

   Runs a standard SVD, soft-thresholds the singular values, and then reforms
   the matrix.

.. cpp:function:: Int svt::Cross( Matrix<F>& A, Base<F> tau, bool relative=false )
.. cpp:function:: Int svt::Cross( AbstractDistMatrix<F>& A, Base<F> tau, bool relative=false )

   Forms the normal matrix, computes its Hermitian EVD, soft-thresholds the
   eigenvalues, and then reforms the matrix. Note that Elemental's parallel 
   Hermitian EVD is much faster than its parallel SVD; this is typically worth
   the loss of accuracy in the computed small (truncated) singular values and
   is therefore the default choice for parallel SVT.

.. cpp:function:: Int svt::PivotedQR( Matrix<F>& A, Base<F> tau, Int numStepsQR, bool relative=false )
.. cpp:function:: Int svt::PivotedQR( AbstractDistMatrix<F>& A, Base<F> tau, Int numStepsQR, bool relative=false )

   Computes an approximate SVT by first approximating A as the rank-`numSteps`
   approximation produced by `numSteps` iterations of column-pivoted QR.

.. cpp:function:: Int svt::TSQR( AbstractDistMatrix<F>& A, Base<F> tau, bool relative=false ) 

   Since the majority of the work in a tall-skinny SVT will be in the initial
   QR factorization, this algorithm runs a TSQR factorization and then 
   computes the SVT of the small R factor using a single process.
