METIS and ParMETIS
==================
If ParMETIS was not disabled (e.g., by commercial users), then Elemental makes
use of ParMETIS's internal API's in order to `expose an interface for computing
a vertex separator in parallel <https://github.com/elemental/Elemental/blob/f4eb8fa39a958306aabac64eb95bfbe0c1efb615/src/lapack_like/factor/sparse/symbolic/ParallelBisect.c>`__. If ParMETIS was disabled, then Elemental instead makes use of
the (sequential) METIS routine ``METIS_ComputeVertexSeparator``.

In either case, a primitive for performing a nodal bisection of a graph is 
used within Elemental in order to find Nested Dissection orderings of sparse
matrices.
