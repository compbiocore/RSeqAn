[![Build Status](https://travis-ci.org/compbiocore/RSeqAn.svg?branch=master)](https://travis-ci.org/compbiocore/RSeqAn) [![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

# RSeqAn
SeqAn Headers for R

## About

This package provides R with access to [SeqAn v2.4](http://www.seqan.de/) header files. SeqAn is an open source C++ library of efficient algorithms and data structures for the analysis of sequences with the focus on biological data.

RSeqAn can be used via the `LinkingTo:` field in the `DESCRIPTION` field of an R package. Note that the compiler will need to compile as C++14. This can be done in R as `Sys.setenv("PKG_CXXFLAGS"="-std=c++14")`.

## Author

August Guang

## License

The license provided is the same as for SeqAn and is unaltered.