Pseudospectra
=============
The :math:`p`-norm :math:`\epsilon`-*pseudospectrum* of a square matrix 
:math:`A` is the set of all shifts :math:`\xi \in \mathbb{C}` such that 
the inverse of :math:`A - \xi I` is sufficiently large (greater than :math:`1/\epsilon`) in the :math:`p`-norm:

.. math::

   \mathcal{L}_\epsilon^p(A) = \{ \xi \in \mathbb{C} : \| (A-\xi I)^{-1} \|_p > \frac{1}{\epsilon} \},

with the convention that :math:`\| (A-\xi I)^{-1} \|_p = +\infty` if the
**resolvent**, :math:`(A-\xi I)^{-1}`, does not exist. In the most common case,
where :math:`p=2`, the definition of the :math:`\epsilon`-pseudospectrum 
reduces to 

.. math::

   \mathcal{L}_\epsilon^2(A) = \{ \xi \in \mathbb{C} : \sigma_{\text{min}}(A-\xi I) < \epsilon \}. 

Elemental currently supports two methods for computing two-norm pseudospectra: 
the first is a high-performance improvement of the triangularization followed
by inverse iteration approach of [VanLoan1984]_ and [Lui1997]_.
In particular, Elemental begins by computing the Schur decomposition of the
given matrix, which preserves the (two-norm) :math:`\epsilon`-pseudospectrum, 
up to round-off error, and then simultaneously performs many Implicitly 
Restarted Arnoldi (IRA) iterations with the inverse normal matrix for each 
shift in a manner which communicates no more data than a standard triangular 
solve with many right-hand sides (with vectors deflated immediately after 
convergence).

The second approach is quite similar and, instead of reducing to triangular
form, reduces to Hessenberg form and performs multi-shift triangular solves
in a manner similar to [Henry1994]_ and [BDP1996]_. This algorithm is not yet 
performance-tuned in Elemental, but could perhaps be preferred in situations 
where a Schur decomposition is infeasible.

Elemental also supports proof-of-concept implementations of high-performance
one-norm pseudospectra which are based upon the Hager-Higham algorithm 
([Hager1984]_, [Higham1988]_, and [Higham1990]_) for 
black-box one-norm estimation, but the blocked variant of [HighamTisseur2006]_
provides qualitatively superior results.

Please see [TrefethenEmbree2009]_ or [Trefethen1999]_ for comprehensive 
histories of the computation of pseudospectra.

.. toctree::
   :maxdepth: 1

   Pseudospectra/SpectralPortrait
   Pseudospectra/SpectralWindow
   Pseudospectra/SpectralCloud
   Pseudospectra/ControlStructures

References
----------

.. [BDP1996] Christian H. Bischof, Biswa Nath Datta, and Avijit Purkayastha, *A parallel algorithm for the Sylvester Observer Equation*, SIAM Journal on Scientific Computing, Vol. 17, No. 3, pp. 686--698, 1996. DOI: `http://dx.doi.org/10.1137/S1064827591223276 <http://dx.doi.org/10.1137/S1064827591223276>`__

.. [Hager1984] William W. Hager, *Condition estimates*, SIAM Journal on Scientific and Statistical Computing, Vol. 5, No. 2, pp. 311--316, 1984. DOI: `http://dx.doi.org/10.1137/0905023 <http://dx.doi.org/10.1137/0905023>`__

.. [Henry1994] Greg Henry, *The shifted Hessenberg system solve computation*, Technical Report, Cornell University, Ithica, NY, 1994. Last accessed from: `http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.33.7403 <http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.33.7403>`__

.. [Higham1988] Nicholas J. Higham, *FORTRAN codes for estimating the one-norm of a real or complex matrix, with applications to condition estimation (Algorithm 674)*, ACM Transactions on Mathematical Software, Vol. 14, Issue 4, pp. 381--396, 1988. DOI: `http://dx.doi.org/10.1145/50063.214386 <http://dx.doi.org/10.1145/50063.214386>`__

.. [Higham1990] Nicholas J. Higham, *Experience with a matrix norm estimator*, SIAM Journal on Scientific and Statistical Computing, Vol. 11, No. 4, pp. 804--809, 1990. DOI: `http://dx.doi.org/10.1137/0911047 <http://dx.doi.org/10.1137/0911047>`__

.. [HighamTisseur2006] Nicholas J. Higham and Francoise Tisseur, *A block algorithm for matrix 1-norm estimation, with an application to 1-norm pseudospectra*, SIAM Journal on Matrix Analysis and Applications, Vol. 21, No. 4, pp. 1185--1201, 2006. DOI: `http://dx.doi.org/10.1137/S0895479899356080 <http://dx.doi.org/10.1137/S0895479899356080>`__

.. [Lui1997] S.H. Lui, *Computation of pseudospectra by continuation*, SIAM Journal on Scientific Computing, Vol. 18, No. 2, pp. 565--573, 1997. DOI: `http://dx.doi.org/10.1137/S1064827594276035 <http://dx.doi.org/10.1137/S1064827594276035>`__

.. [Trefethen1999] Lloyd N. Trefethen, *Computation of pseudospectra*, Acta Numerica, pp. 247--295, 1999. Last accessed from: `http://eprints.maths.ox.ac.uk/1294/1/NA-99-03.pdf <http://eprints.maths.ox.ac.uk/1294/1/NA-99-03.pdf>`__

.. [TrefethenEmbree2009] Lloyd N. Trefethen and Mark Embree, *Spectra and pseudospectra: The behavior of nonnormal matrices*, Princeton University Press, Princeton, 2009. Official website: `http://press.princeton.edu/titles/8113.html <http://press.princeton.edu/titles/8113.html>`__

.. [VanLoan1984] Charles Van Loan, *How near is a stable matrix to an unstable matrix?*, Technical Report, Cornell University, Ithica, NY. Last accessed from: `http://hdl.handle.net/1813/6488 <http://hdl.handle.net/1813/6488>`__

`C++ implementation <https://github.com/elemental/Elemental/tree/master/src/lapack_like/spectral/Pseudospectra.cpp>`__

`C++ pseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/Pseudospectra.cpp>`__

`C++ ChunkedPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/ChunkedPseudospectra.cpp>`__

`C++ TriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/TriangularPseudospectra.cpp>`__

`C++ ChunkedTriangularPseudospectra example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/ChunkedTriangularPseudospectra.cpp>`__
