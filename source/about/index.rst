.. General introduction to Elemental.

.. _About:

###############
About Elemental
###############

Elemental is an open-source library for distributed-memory dense 
linear algebra which attempts to strike a careful balance between 
ease-of-use and high-performance.

The development of Elemental has led to a number of 
:doc:`research articles<../citing/index>` and 
a number of related projects, such as the sparse-direct solver, 
`Clique <http://github.com/poulson/Clique.git/>`__, and the parallel sweeping 
preconditioner, `PSP <http://github.com/poulson/PSP.git/>`__.
Additionally, a number of routines in Elemental, such as pivoted QR, 
interpolative, and skeleton decompositions, were implemented as a result of 
work on `a parallel butterfly algorithm <http://github.com/poulson/dist-butterfly.git/>`__.

********
Features
********

TODO

**********
Components
**********

TODO

************
Contributors
************

Please see `the list of contributors <./team.html>`__ for now.

.. _about_license:

*******
License
*******

All of Elemental is licensed under the 
`New BSD License <http://opensource.org/licenses/BSD-3-Clause>`__ as
published by the `Open Source Initiative <http://opensource.org>`__.

*****************
About these pages
*****************

`This website <http://github.com/elemental/elemental-web.git>`__  was 
created by `Jack Poulson <http://www.stanford.edu/~poulson>`__ by 
checking out a copy of 
`fenics-web <https://bitbucket.org/fenics-project/fenics-web>`__ and slowly 
replacing FEniCS-specific content with the appropriate Elemental content.
The modified source code 
`can be found here <http://github.com/elemental/elemental-web.git>`__.

.. toctree::
   :hidden:

   components
   features
   team
