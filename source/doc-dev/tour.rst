A brief tour of the library
***************************
This is just starting to be sketched and the details should be filled in soon.

Boiler-plate programs
=====================

.. code-block:: c++

   #include <El.hpp>
   int main( int argc, char* argv[] )
   {
     El::Environment env( argc, argv );
     try {
       // Nontrivial computation goes here
     } catch( std::exception& except ) { El::ReportException(except); }
     return 0;
   }

Floating-point types
====================
Elemental supports a variety of different floating-point types; the typical
order of increasing cost is ``float``, ``double``, ``El::DoubleDouble``,
``El::QuadDouble``, ``El::Quad``, ``El::BigFloat``. ``El::DoubleDouble`` and
``El::QuadDouble`` are essentially concatenations of the mantissas of two and
four doubles (respectively), while ``El::Quad`` is an IEEE 128-bit format that
is typically implemented in software, and ``El::BigFloat`` is a wrapper for
GNU MPFR's arbitrary-precision floating-point arithmetic.

.. code-block:: c++

   #include <El.hpp>
   template<typename Real>
   void QueryLimits()
   {
     El::Output("base:      ",El::limits::Base<Real>());
     El::Output("epsilon:   ",El::limits::Epsilon<Real>());
     El::Output("precision: ",El::limits::Precision<Real>());
     El::Output("min:       ",El::limits::Min<Real>());
     El::Output("max:       ",El::limits::Max<Real>());
     El::Output("lowest:    ",El::limits::Lowest<Real>());
   }

float
-----

The 32-bit IEEE floating-point type yields an output from
``QueryLimits<float>()`` of::

  base:      2
  epsilon:   5.96046e-08
  precision: 1.19209e-07
  min:       1.17549e-38
  max:       3.40282e+38
  lowest:    -3.40282e+38

double
------

The 64-bit IEEE floating-point type yields an output from
``QueryLimits<double>()`` of::

  base:      2
  epsilon:   1.11022e-16
  precision: 2.22045e-16
  min:       2.22507e-308
  max:       1.79769e+308
  lowest:    -1.79769e+308

DoubleDouble
------------

The concatenation of the mantissas from two 64-bit IEEE floating-point types,
``El::DoubleDouble``, results in::

  base:      2.000000e+00
  epsilon:   2.465190e-32
  precision: 4.930381e-32
  min:       2.004168e-292
  max:       1.797693e+308
  lowest:    -1.797693e+308

This datatype is only available if Elemental was configured with support for the
package `QD <http://crd-legacy.lbl.gov/~dhbailey/mpdist/>`__ (the preprocessor definition `EL_HAVE_QD` will exist if this is the case).

QuadDouble
----------

The concatenation of the mantissas from four 64-bit IEEE floating-point types,
``El::QuadDouble``, results in::

  base:      2.000000e+00
  epsilon:   6.077163e-64
  precision: 1.215433e-63
  min:       1.625975e-260
  max:       1.797693e+308
  lowest:    -1.797693e+308

Like `El::DoubleDouble`, this datatype is only available if Elemental was
configured with support for the package
`QD <http://crd-legacy.lbl.gov/~dhbailey/mpdist/>`__ (the preprocessor
definition `EL_HAVE_QD` will exist if this is the case).

Quad
----

The 128-bit IEEE floating-point type (which is made available by the GNU and Intel compilers), ``El::Quad``, yields::

  base:      2.000000e+00
  epsilon:   9.629650e-35
  precision: 1.925930e-34
  min:       3.362103e-4932
  max:       1.189731e+4932
  lowest:    -1.189731e+4932

This datatype is only available if Elemental was configured with support for
``__float128`` via
`libquadmath <https://gcc.gnu.org/onlinedocs/libquadmath/>`__
(the preprocessor definition `EL_HAVE_QUAD` will exist if this is the case).

BigFloat
--------

The arbitrary-precision floating-point type in Elemental, ``El::BigFloat``,
which currently builds on top of GNU MPFR, defaults to 256-bit but is
configurable at runtime with the routine
``void El::mpfr::SetPrecision( mpfr_prec_t precision )``. With the default
choice of 256 bits, the output of our ``QueryLimits`` function is::

  base:      2
  epsilon:   8.63616855509444462538635186280039957111600036443628138502370347016859180316243e-78
  precision: 1.72723371101888892507727037256007991422320007288725627700474069403371836063249e-77
  min:       2.38256490488795107321616978173267452041519612555923978795502375260094538610432e-323228497
  max:       2.09857871646738769240435811688383907063809796547335262778664622571024044777575e+323228496
  lowest:    -2.09857871646738769240435811688383907063809796547335262778664622571024044777575e+323228496

After a call to ``El::mpfr::SetPrecision( 1024 )``, the output should become::

  base:      2
  epsilon:   5.56268464626800345772558179333101016054803995115582957638331854221801108703479548963570789753127755141016834932758952751288108540388365027214003096344429705282694498383000582619902536860645909017980391261735625933552093812701662654164539737180122794992147909912125158977192529576218699945221938437487362895113e-309
  precision: 1.11253692925360069154511635866620203210960799023116591527666370844360221740695909792714157950625551028203366986551790550257621708077673005442800619268885941056538899676600116523980507372129181803596078252347125186710418762540332530832907947436024558998429581982425031795438505915243739989044387687497472579023e-308
  min:       2.38256490488795107321616978173267452041519612555923978795502375260094538610432437489305775137932142344261757534893513700376849772992139878050298035792983488792657869701244309719036212063256710725856070515025356232010332123318365401263732225092389771322296946086646765801855827879773904684428316399822674037349e-323228497
  max:       2.09857871646738769240435811688383907063809796547335262778664622571024044777576820818355304081267655987295599577960564840596747121502665142009783113610500048360066244023816505568400011005103679303701081473191703433515051267336632313268218262621740510855082829034802224115869883581782547386877774641524094504273e+323228496
  lowest:    -2.09857871646738769240435811688383907063809796547335262778664622571024044777576820818355304081267655987295599577960564840596747121502665142009783113610500048360066244023816505568400011005103679303701081473191703433515051267336632313268218262621740510855082829034802224115869883581782547386877774641524094504273e+323228496

This datatype is only available if Elemental was configured with support for
`MPFR <http://www.mpfr.org/>`__ and
`MPC <http://www.multiprecision.org/index.php?prog=mpc>`__ 
(the preprocessor definition `EL_HAVE_MPC` will exist if this is the case).

Dense linear algebra
====================

Solving linear systems
----------------------
As a pathological example, the following routine can be used to test a
Cholesky-based linear system solver on a Hilbert matrix for various precisions:

.. code-block:: c++

  template<typename Real>
  void SolveHilbert( Int n )
  {
      El::Output("Attempting to solve Hilbert system with ",El::TypeName<Real>());
  
      // Form an n x n Hilbert matrix
      El::Matrix<Real> A;
      El::Hilbert( A, n );
  
      // Form a uniform random vector
      El::Matrix<Real> x;
      El::Uniform( x, n, 1 );
      const Real xFrob = El::FrobeniusNorm( x );
  
      // Form b := A x
      El::Matrix<Real> b;
      El::Gemv( El::NORMAL, Real(1), A, x, b );
      const Real bFrob = El::FrobeniusNorm( b );
  
      // Form xComp := inv(A) b
      El::Matrix<Real> xComp(b);
      El::HPDSolve( El::LOWER, El::NORMAL, A, xComp );
  
      // Form r := b - A x
      El::Matrix<Real> r(b);
      El::Gemv( El::NORMAL, Real(-1), A, xComp, Real(1), r );
      const Real rFrob = El::FrobeniusNorm( r );
      El::Output("|| r ||_2 / || b ||_2 = ",rFrob/bFrob);

      // Form e := x - xComp
      El::Matrix<Real> e(x);
      e -= xComp;
      const Real eFrob = El::FrobeniusNorm( e );
      El::Output("|| e ||_2 / || x ||_2 = ",eFrob/xFrob);

      El::Output("");
  }

A ``main`` function for calling this should ideally separately handle exceptions
for each datatype, as it turns out that neither single-precision nor
double-precision can successfully factor 20 x 20 Hilbert matrices:

.. code-block:: c++
  
  int main( int argc, char* argv[] )
  {
      El::Environment env( argc, argv );
  
      El::Int n;
  #ifdef EL_HAVE_MPC
      mpfr_prec_t prec;
  #endif
      try
      {
          n = El::Input("--n","matrix width",20);
  #ifdef EL_HAVE_MPC
          prec = El::Input("--prec","MPFR precision",256);
  #endif
          El::ProcessInput();
      }
      catch( std::exception& e ) { El::ReportException(e); }
  #ifdef EL_HAVE_MPC
      El::mpfr::SetPrecision( prec );
  #endif
  
      try { SolveHilbert<float>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
      try { SolveHilbert<double>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
  #ifdef EL_HAVE_QD
      try { SolveHilbert<El::DoubleDouble>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
      try { SolveHilbert<El::QuadDouble>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
  #endif
  #ifdef EL_HAVE_QUAD
      try { SolveHilbert<El::Quad>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
  #endif
  #ifdef EL_HAVE_MPC
      try { SolveHilbert<El::BigFloat>( n ); }
      catch( std::exception& e ) { El::ReportException(e); }
  #endif
  
      return 0;
  }

For a 20 x 20 Hilbert matrix, one should see output of the form::

  Attempting to solve Hilbert system with float
  Process 0 caught error message:
  A was not numerically HPD

  Attempting to solve Hilbert system with double
  Process 0 caught error message:
  A was not numerically HPD

  Attempting to solve Hilbert system with DoubleDouble
  || r ||_2 / || b ||_2 = 3.543271e-32
  || e ||_2 / || x ||_2 = 3.538193e-06
  
  Attempting to solve Hilbert system with QuadDouble
  || r ||_2 / || b ||_2 = 2.506190e-65
  || e ||_2 / || x ||_2 = 2.439582e-38
  
  Attempting to solve Hilbert system with Quad
  || r ||_2 / || b ||_2 = 2.745784e-34
  || e ||_2 / || x ||_2 = 7.907429e-08
  
  Attempting to solve Hilbert system with BigFloat
  || r ||_2 / || b ||_2 = 1.9482282137301946384577456453427454630087917713177475059958544871005206470301e-77
  || e ||_2 / || x ||_2 = 2.28840034493301788424999659531588179908629747565564912546598839357700494446305e-51

A cursory comparison of the residual and solution errors relative to machine epsilon reveals that the relative residuals are near optimal but the relative
solution error loses about 26 digits of accuracy. Because the relative residuals
are on the order of machine epsilon, iterative refinement cannot be expected to
yield any improvement.

Cholesky
^^^^^^^^

Bunch-Kaufman
^^^^^^^^^^^^^

LU
^^

QR
^^

Hermitian eigensolvers (and their extensions)
---------------------------------------------

Hermitian eigensolvers
^^^^^^^^^^^^^^^^^^^^^^

Skew-Hermitian eigensolvers
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Hermitian generalized-definite eigensolvers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Singular Value Decompositions
-----------------------------

Schur decompositions
--------------------

Pseudospectra
-------------

Sparse-direct linear and (generalized) least squares solvers
============================================================

Unpivoted LDL
-------------

Symmetric Quasi-SemiDefinite (SQSD) systems
-------------------------------------------

General linear systems
----------------------

Least Squares
-------------

Tikhonov
--------

Equality-constrained Least Squares (LSE)
----------------------------------------

General Linear Model (GLM)
--------------------------

Solving Linear, Quadratic Programs, and Second-Order Cone Programs
==================================================================

Linear Programs
---------------

Quadratic Programs
------------------

Second-Order Cone Programs
--------------------------

Lattice reduction
=================

Lenstra/Lenstra/Lovasz (LLL) basis reduction
--------------------------------------------

Block Korkine-Zolotarev basis reduction (and its extensions)
------------------------------------------------------------

Vanilla BKZ
^^^^^^^^^^^

"BKZ 2.0"
^^^^^^^^^

"y-sparse" enumeration
^^^^^^^^^^^^^^^^^^^^^^

Solving Shortest Vector Problems
--------------------------------

Integer dependence searches
---------------------------

Some simple number theory support
=================================

Simple integer factorization
----------------------------

Direct sieving
^^^^^^^^^^^^^^

Pollard's rho method
^^^^^^^^^^^^^^^^^^^^

Pollard's p-1 method
^^^^^^^^^^^^^^^^^^^^

Discrete logarithms
-------------------

References
==========

.. [PEtAl2013] Jack Poulson, Bryan Marker, Robert A. van de Geijn, Jeff R. Hammond, and Nichols A. Romero, *Elemental: A new framework for distributed memory dense matrix computations*, ACM Transactions on Mathematical Software, Vol. 39, Issue 2, Article No. 13, 2013. DOI: `http://dx.doi.org/10.1145/2427023.2427030 <http://dx.doi.org/10.1145/2427023.2427030>`__