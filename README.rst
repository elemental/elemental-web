===================================
Elemental documentation and webpage
===================================

The repository contains the source for the pages at
http://libelemental.org.

* How to: generate web pages
  ::

    make web

  This will read .rst files from the 'source' directory and generate
  .html files in the 'build/html' directory.

* How to: import documentation
  ::

    make import_docs

  This will import documentation input files (.rst) from all projects,
  build .html files and add those to 'build/html'. Running this
  script requires that all projects (currently Elemental) have
  been built and that the environment variable ELEM_DIR has been set.

* How to: publish web pages
  ::

    make publish

  This will upload the generated pages from 'build/html' to
  libelemental.org/new, including both the web pages and the
  documentation pages. Running this script requires access to the
  account u73318331@libelemental.org.

* How to: do it all
  ::

    make all

  This is equivalent to running all of the above targets.

* NOTE: This documentation was forked from fenics-web, which may be found at
  https://bitbucket.org/fenics-project/fenics-web.
