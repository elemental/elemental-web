.. _release_0_69:

##########################
09/08/2011: Elemental 0.69
##########################

`elemental-0.69.tgz <http://libelemental.org/pub/releases/elemental-0.69.tgz>`__

Changes
=======
- LQ factorization was added
- LDL^T and LDL^H factorizations (without pivoting) were added
- The AxpyInterface was rewritten to avoid a subtle bug that appeared when performing many Axpy's
- Norms for symmetric matrices are now explicitly supported
- Several modified Trsm algorithms were added
- The documentation is starting to take form
- Everything in the elemental::utilities namespace was moved into the elemental namespace
- The entire inheritance tree for the Matrix and DistMatrix classes was halved in depth
- The majority of the library was moved into header files in preparation for fully supporting much more general datatypes (and to fix a subtlety with respect to instantiating template member functions of a template class).
