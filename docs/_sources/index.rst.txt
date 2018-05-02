
.. RSeqAn index file, created by `ablog start` on Mon Apr 30 11:28:23 2018.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. post:: May 1, 2018
   :tags: overview
   :author: August Guang

RSeqAn
==================================

SeqAn Headers for R

About
------

This package provides R with access to `SeqAn
v2.4 <http://www.seqan.de/>`__ header files. SeqAn is an open source C++
library of efficient algorithms and data structures for the analysis of
sequences with the focus on biological data.

RSeqAn can be used via the ``LinkingTo:`` field in the ``DESCRIPTION``
field of an R package. Note that the compiler will need to compile as
C++14. This can be done in R as
``Sys.setenv("PKG_CXXFLAGS"="-std=c++14")``.

Vignettes
---------

.. toctree::
   :maxdepth: 2
   :caption: Contents

   Introduction to RSeqAn <first_example>

Developers
-----------

- `August Guang <http://www.augustguang.com>`__
	Author, maintainer

Citation
--------

Please do not forget to cite SeqAn if you use this package in your
acedemic work, even if only in auxiliary tools or pipelines:
https://doi.org/10.1016/j.jbiotec.2017.07.017

Links
------

-  Download from BIOC at
   `https://​www.bioconductor.org/​packages/​RSeqAn <https://www.bioconductor.org/packages/RSeqAn>`__
-  Report a bug at
   `https://​github.com/​compbiocore/​RSeqAn/​issues <https://github.com/compbiocore/RSeqAn/issues>`__


.. rubric:: Dev status
   :name: dev-status

-  |Build Status|
-  |License|

.. |Build Status| image:: https://travis-ci.org/compbiocore/RSeqAn.svg?branch=master
   :target: https://travis-ci.org/compbiocore/RSeqAn
.. |License| image:: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
   :target: https://opensource.org/licenses/BSD-3-Clause

