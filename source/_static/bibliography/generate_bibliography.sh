#!/bin/sh
#
# This script generates the bibliography in various formats
# from the common input file 'elemental.pub'.

# Check that we have publish
PUBLISH=`which publish`
if [ "x$PUBLISH" = "x" ]; then
    echo "The Publish program is required to run this script."
    echo "This may be installed by running the following commands:"
    echo ""
    echo "  hg clone ssh://hg@bitbucket.org/logg/publish"
    echo "  cd publish"
    echo "  sudo python setup.py install"
    echo ""
    exit 1
fi

# Export the two files
publish export elemental.bib database_filename=elemental.pub debug=1
publish export elemental.rst database_filename=elemental.pub debug=1

# Rename .rst file to get rid of Sphinx warning
# Also add comment on how to edit files
rm -f elemental.rst_
echo ".. Note! This file should not be edited manually. It should" >> elemental.rst_
echo ".. instead be generated from within source/_static/bibliography." >> elemental.rst_
echo "" >> elemental.rst_
cat elemental.rst >> elemental.rst_

# Copy file to citing directory
cp elemental.rst_ ../../citing
