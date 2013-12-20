# Makefile for Elemental documentation

# You can set these variables from the command line
SPHINXOPTS  =
SPHINXBUILD = sphinx-build
PAPER       =

# Internal variables
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
OPTSPRE = $(PAPEROPT_$(PAPER)) $(SPHINXOPTS)
OPTSMAIN = $(OPTSPRE) -d build/main-tree
OPTSDEV  = $(OPTSPRE) -d build/dev-tree
OPTS82P1 = $(OPTSPRE) -d build/82p1-tree
OPTS82   = $(OPTSPRE) -d build/82-tree
OPTS81   = $(OPTSPRE) -d build/81-tree

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo ""
	@echo "  all          to build all targets: html, doc, publish"
	@echo "  web          to build web pages"
	@echo "  import_docs  to import documentation for projects"
	@echo "  publish      to publish everything on libelemental.org"
	@echo "  clean        to clean out everything (build directory)"
	@echo "  fetch_news   to fetch the news"
	@echo ""
	@echo "In addition, the targets 'latex' and 'pdf' exist but are not used."

all:	web import_docs publish

web:
	$(SPHINXBUILD) -b html $(OPTSMAIN) source/main        build/html/
	$(SPHINXBUILD) -b html $(OPTSDEV)  source/doc-dev     build/html/documentation/dev
	$(SPHINXBUILD) -b html $(OPTS82P1) source/doc-0.82-p1 build/html/documentation/0.82-p1
	$(SPHINXBUILD) -b html $(OPTS82) source/doc-0.82 build/html/documentation/0.82
	$(SPHINXBUILD) -b html $(OPTS81) source/doc-0.81 build/html/documentation/0.81
	cp source/.htaccess             build/html/
	chmod +x build/html/index.html
	chmod +x build/html/documentation/dev/index.html
	chmod +x build/html/documentation/0.82-p1/index.html
	chmod +x build/html/documentation/0.82/index.html
	chmod +x build/html/documentation/0.81/index.html
	@echo
	@echo "Build finished. HTML generated in build/html."

import_docs:
	scripts/import_docs

publish:
	scripts/publish
	@echo ""
	@echo "If you didn't run 'make fetch_news', please do so and 'make publish' again"

clean:
	-rm -rf build

fetch_news:
	cd scripts && ./fetch_news

latex:
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-dev build/latex/dev
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.82-p1 build/latex/0.82-p1
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.82 build/latex/0.82
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.81 build/latex/0.81
	@echo
	@echo "Build finished. LaTeX generated in build/latex."

pdf:
	make -C build/latex all-pdf
