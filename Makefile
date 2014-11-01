# Makefile for Elemental documentation

# You can set these variables from the command line
MAKE = make
SPHINXOPTS  =
SPHINXBUILD = sphinx-build
PAPER       =

# Internal variables
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
OPTSPRE   = $(PAPEROPT_$(PAPER)) $(SPHINXOPTS)
OPTSMAIN  = $(OPTSPRE) -d build/main-tree
OPTSDEV   = $(OPTSPRE) -d build/dev-tree
OPTS85RC1 = $(OPTSPRE) -d build/85-RC1-tree
OPTS84 = $(OPTSPRE) -d build/84-tree
OPTS83    = $(OPTSPRE) -d build/83-tree

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
	$(SPHINXBUILD) -b html $(OPTSMAIN) source/main build/html/
	$(SPHINXBUILD) -b html $(OPTSDEV)  source/doc-dev build/html/documentation/dev
	$(SPHINXBUILD) -b html $(OPTS85RC1)  source/doc-0.85-RC1 build/html/documentation/0.85-RC1
	$(SPHINXBUILD) -b html $(OPTS84)  source/doc-0.84 build/html/documentation/0.84
	$(SPHINXBUILD) -b html $(OPTS83)  source/doc-0.83 build/html/documentation/0.83
	cp source/.htaccess             build/html/
	chmod +x build/html/index.html
	chmod +x build/html/documentation/dev/index.html
	chmod +x build/html/documentation/0.85-RC1/index.html
	chmod +x build/html/documentation/0.84/index.html
	chmod +x build/html/documentation/0.83/index.html
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
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.85-RC1 build/latex/0.85-RC1
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.84 build/latex/0.84
	$(SPHINXBUILD) -b latex $(OPTSPRE) source/doc-0.83 build/latex/0.83
	$(MAKE) -C build/latex/dev
	$(MAKE) -C build/latex/0.85-RC1
	$(MAKE) -C build/latex/0.84
	$(MAKE) -C build/latex/0.83
	cp build/latex/dev/Elemental.pdf build/html/documentation/elem-dev.pdf
	cp build/latex/0.84/Elemental.pdf build/html/documentation/elem-0.85-RC1.pdf
	cp build/latex/0.84/Elemental.pdf build/html/documentation/elem-0.84.pdf
	cp build/latex/0.83/Elemental.pdf build/html/documentation/elem-0.83.pdf
	@echo
	@echo "Build finished. LaTeX generated in build/latex."

pdf:
	make -C build/latex all-pdf
