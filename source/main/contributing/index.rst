.. Developer information.

.. _developers:

Contributing
############

Elemental is an open source project and contributions are always welcome.
This page contains information for prospective Elemental
developers, including an overview of the organization of the current
code base, how to write code and documentation, and how to use the
tools like Git.

Contributions are actively encouraged. Your first few contributions should
ideally take the form of git-formatted changesets. After submitting several
high-quality changesets, you may receive direct commit access to the
`GitHub <http://github.com/elemental/Elemental>`__ repositories.

Organization
************

At this point in time, Elemental is led in a manner which closely resembles 
that of Python or the Linux kernel: community and developer feedback and 
changesets are actively encouraged, but decisions are ultimately decided by 
the main developer of the project (in this case, 
`Jack Poulson <http://www.cc.gatech.edu/~jpoulson>`__). 
This role is traditionally referred to as the Benevolent Dictator.
As more developers begin to more frequently contribute high-quality changesets
to the library, Elemental will move towards a more distributed decision-making 
structure. The most recent contributions pushing towards this model were 
`Michael Grant's <http://cvxr.com/bio/>`__ addition of a Python interface 
and his reworking of Elemental's ownership attributes for the ``Matrix`` and 
``DistMatrix`` classes.

Brief development history
*************************

After spending a summer internship at Microsoft Research and being exposed to 
high-quality C++ development, Jack Poulson was inspired to scrap his previous
closed-source C-based alternative implementation of the High-Performance LINPACK
benchmark and develop an open-source object-oriented C++ replacement for 
PLAPACK. This was a close collaboration with 
`Robert van de Geijn <http://cs.utexas.edu/users/rvdg>`__ which, after several
years of development, led to the publication of 
*Elemental: A new framework for distributed memory dense matrix computations* 
in ACM TOMS. This stage of development took place while Jack was in the 
beginning stages of his PhD at UT Austin. Towards the end of his PhD, he began
working on a *sweeping preconditioner* for 3D Helmholtz equations, and this 
led to the development of the sparse-direct solver, 
`Clique <http://github.com/poulson/Clique>`__, which is built on top of 
Elemental. Jack finished his PhD under 
`Lexing Ying <http://math.stanford.edu/~lexing>`__ at the end of 2012 and 
moved to Stanford's math department as a postdoc for ten months.
After serving as an Assistant Professor of Computational Science and 
Engineering at the Georgia Institute for Technology, he accepted a Simon's 
Math+X position in Stanford's `Math department <http://math.stanford.edu>`__ 
and `Institute for Computational and Mathematical Engineering (ICME).<https://icme.stanford.edu>`__.

The source code which became Elemental was originally hosted on 
`GitHub <http://github.com>`__ in 2009 (briefly under the poorly-chosen name 
`Glass`, which was meant to emphasize the simplicity of each operation's 
implementation), development soon switched to Mercurial with hosting on 
`Google Code <http://code.google.com/p/elemental>`__ for roughly four years, 
and in mid-2013 Elemental's home moved to the custom website 
`libelemental.org <http://libelemental.org>`__ with development switching back
to Git and GitHub. The revision history of the current GitHub repository dates
back to the original Google Code commit; hopefully the original GitHub 
changesets can be edited back in at some point.

Workflow
********

While the project's main page is `libelemental.org <http://libelemental.org>`__,
development takes place at 
`github.com/elemental/Elemental <http://github.com/elemental/Elemental>`__ and
discussions about development take place via the mailing list
``dev@libelemental.org`` (please see `the support page </support>`__ for 
sign-up instructions).

The most straight-forward way to contribute is to 
`fork Elemental on GitHub <http://github.com/elemental/Elemental/>`__, commit 
your proposed changes, and then to submit a pull request. If the changeset 
involves a significant change to the library that warrants discussion, then 
it would be best to also send a message to ``dev@libelemental.org``.
