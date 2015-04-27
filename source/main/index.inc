<div id="leader">
  <div id="feature-info">
    <h1>Elemental</h1>
    <p>
    <a href="https://github.com/elemental/Elemental">Elemental</a> is 
    <a href="http://opensource.org/licenses/BSD-2-Clause">open-source</a>, 
    <a href="https://github.com/elemental/Elemental/commits/master">openly-developed</a>, 
    software for distributed-memory dense and sparse-direct linear algebra and 
    optimization which <a href="/about/">supports a wide range of functionality
    not available elsewhere</a>.
    </p>

  </div>
  <div class="clear-block"></div>
</div>

<div id="leader">
    <h2><a href="/download/">Elemental releases</a></h2>

    <p>
    Please note that the <a href="https://github.com/elemental/Elemental/releases/tag/0.86-rc1">release candidate for Elemental 0.86</a> is now available and
    contains support for dense and sparse Interior Point Methods for linear and 
    quadratic programs. The official release will follow when 
    <a href="http://libelemental.org/documentation/dev/index.html">the documentation</a>
    is reasonably updated to reflect the recent rapid increase in functionality.
    </p>

    <p>The previous release, from November 2014, is also available:</p>

    <a href="/releases/0.85/">
      <img style="margin-left:auto; margin-right:auto; margin-top:10px;"
         src="/_static/download-button-0.85.png" alt="Download button" />
    </a>
  <div class="clear-block"></div>
</div>

<div id="leader">
  <h2><a href="/about/contributors.html">Elemental's contributors</a></h2>

  <p>
  While the project's development community is 
  <a href="https://github.com/elemental/Elemental/graphs/contributors">clearly still in its early stages</a>, 
  we hope to overcome the current high barrier to entry for
  development by gradually adding support for on-demand access to a
  a development version of the library on modest-sized clusters 
  (Cf. <a href="http://juliabox.org">JuliaBox</a>).</p>
</div>

<div id="feature">
  <h2>Dependencies</h2>

  <h3>Intranodal linear algebra</h3>
  <ul>
    <li><a href="http://netlib.org/blas">BLAS</a></li>
    <li><a href="http://netlib.org/lapack">LAPACK</a></li>
    <li><a href="http://www.cs.utexas.edu/~flame/web/libFLAME.html">libFLAME</a> (optional for faster bidiagonal SVDs)</li>
  </ul>
  <a href="http://www.openblas.net">OpenBLAS</a> is automatically downloaded and
  installed if no vendor/tuned BLAS/LAPACK is detected.

  <h3>Intranodal graph partitioning</h3>
  <ul>
    <li><a href="http://glaros.dtc.umn.edu/gkhome/metis/metis/overview">METIS</a></li>
    <li><a href="http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview">ParMETIS</a></li>
  </ul>
  If ParMETIS is not disabled (e.g., by a commercial user), then it is 
  automatically downloaded and installed (access to internal headers which are 
  not usually installed is required). Otherwise, METIS is either automatically 
  detected or downloaded and installed.

  <h3>Internodal linear algebra</h3>
  <ul>
    <li><a href="https://code.google.com/p/pmrrr/">PMRRR</a> (packaged with Elemental)</li>
    <li><a href="http://netlib.org/scalapack">ScaLAPACK</a> (optional for Hessenberg QR algorithm)</li>
  </ul>

  <h3>Internodal communication</h3>
  <ul>
    <li>MPI2: typically <a href="http://www.mpich.org">MPICH</a>, <a href="http://mvapich.cse.ohio-state.edu/">MVAPICH</a>, or <a href="http://www.open-mpi.org">OpenMPI</a></li>
  </ul>

  <h3>Auxiliary libraries</h3>
  <ul>
    <li><a href="https://gcc.gnu.org/onlinedocs/libquadmath/">libquadmath</a> provides support for quad-precision (users who prefer to use Elemental under the terms of the New BSD License must disable libquadmath when compiling with GCC)
  </ul>

  <h3>Python interface</h3>
  <ul>
    <li><a href="http://matplotlib.org/">matplotlib</a> (optional for python matrix visualization)</li>
    <li><a href="https://networkx.github.io/">NetworkX</a> (optional for python graph visualization)</li>
    <li><a href="http://www.numpy.org/">NumPy</a></li>
  </ul>

  <h3>C++ visualization</h3>
  <ul>
    <li><a href="http://qt-project.org/qt5">Qt 5</a> (optional for visualization from C++</li>
  </ul>

  <h3>Build system</h3>
  <ul>
    <li><a href="http://www.cmake.org/">CMake >= 2.8.8</a></li>
  </ul>
</div>

<div id="feature">
  <h2>Third-party interfaces</h2>
  <p>
  In addition to the C++11, C, and Python interfaces included within the 
  project, two external interfaces are currently being externally developed:
  </p>
  <ul>
  <li><a href="https://github.com/roconale/R-Elemental">R-El</a> <a href="http://www.r-project.org">R</a> interface to Elemental developed by <a href="https://github.com/roconale">Rodrigo Canales</a> <a href="http://hpac.rwth-aachen.de/~pauldj/">Paolo Bientinesi</a></li>
  <li><a href="https://github.com/JuliaParallel/Elemental.jl">Elemental.jl</a> 
    is an (in-progress) <a href="http://julialang.org">Julia</a> interface to 
    Elemental being developed by <a href="https://github.com/jakebolewski">Jake Bolewski</a>, <a href="https://jiahao.github.io">Jiahao Chen</a>, and <a href="http://andreasnoack.github.io/academiccv.html">Andreas Noack</a></li.
  </ul>
</div>

<div id="leader">
  <h2>Related projects</h2>

  <h3>Distributed dense linear algebra</h3>
  <ul>
    <li><a href="http://elpa.rzg.mpg.de/">ELPA</a></li>
    <li><a href="http://icl.eecs.utk.edu/dplasma/">DPLASMA</a></li>
    <li><a href="https://github.com/solomonik/NuLAB">NuLAB</a></li>
    <li><a href="http://www.cs.utexas.edu/~plapack/">PLAPACK</a></li>
    <li><a href="http://www.netlib.org/scalapack/">ScaLAPACK</a></li>
  </ul>

  <h3>Distributed sparse-direct linear algebra</h3>
  <ul>
    <li> <a href="http://www.cse.psu.edu/~raghavan/Dscpack/">DSCPACK</a></li>
    <li> <a href="http://mumps.enseeiht.fr/">MUMPS</a></li>
    <li> <a href="http://crd-legacy.lbl.gov/~xiaoye/SuperLU/">SuperLU</a></li>
  </ul>

  <h3>Distributed linear algebra Frameworks</h3>
  <ul>
    <li><a href="https://www.mcs.anl.gov/petsc/">PETSc</a></li>
    <li><a href="http://trilinos.sandia.gov/">Trilinos</a></li>
  </ul>

  <h3>Convex optimization</h3>
  <ul>
    <li><a href="http://cvxopt.org">CVXOPT</a></li>
    <li><a href="https://github.com/embotech/ecos">ECOS</a></li>
    <li><a href="http://users.ece.gatech.edu/~justin/l1magic/">L1-MAGIC</a></li>
    <li><a href="http://sdpa.sourceforge.net/index.html">SDPA</a></li>
  </ul>
</div>
