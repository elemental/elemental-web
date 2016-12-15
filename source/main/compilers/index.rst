.. _compilers:

Supported compilers
###################

C++11 support is required as of Elemental 0.82, and so reasonably up-to-date
compilers are now necessary. More detailed information will hopefully follow
soon, but the following compilers have been verified to compile the recent
releases of Elemental:

* GCC >= 4.8
* Clang >= 3.6
* Intel >= 17 update 1 (due to known bugs in the Intel compilers)

Known toolchain issues
######################

GCC on recent versions of OS X
==============================
As reported by
`Issue #181 <https://github.com/elemental/Elemental/issues/181>`__, GCC 5.x and 6.x appear to be improperly assuming 16-byte alignments on OS X when the `-O3`
optimizations are enabled. While simply using `-O2` optimizations avoids the
issue, Clang should perhaps be preferred on recent versions of OS X.
OS X users are therefore recommended to install GCC 4.9.

MPICH 3.2 + Clang + OS X
========================
As reported by
`Issue #200 <https://github.com/elemental/Elemental/issues/200>`__, there are
known issues with compiling MPICH 3.2 with Clang that can cause failures in
very simple MPI programs. The recommended solution is to take
`the following advice <http://lists.mpich.org/pipermail/discuss/2016-August/004861.html>`__ 
and to build MPICH from source using the most recent version from `git.mpich.org/mpich.git <http://git.mpich.org/mpich.git>`__.

Intel compilers
===============
As discussed by
`Issue #177 <https://github.com/elemental/Elemental/issues/177>`__, relatively
recent versions of the Intel C++ compilers do not properly parse Elemental's
source. The issue is supposedly addressed by version 17 update 1.

OpenMPI < 1.8.1
===============
Due to a known bug in OpenMPI 1.6.5's handling of complex data, Elemental
requires that OpenMPI version 1.8.1 or later be used.
