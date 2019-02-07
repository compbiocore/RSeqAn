---
title: 'RSeqAn: Headers and wrappers for the SeqAn library in R'
author:
  - August Guang
authors:
- affiliation: "1,2"
  name: August Guang
  orcid: 0000-0003-0872-7098
tags:
- SeqAn
- bioinformatics
- R
- Rcpp
affiliations:
- index: 1
  name: Center for Computation and Visualization, Brown University, Providence, Rhode Island, United States of America
- index: 2
  name: Center for Computational Biology of Human Disease, Brown University, Providence, Rhode Island, United States of America
date: 5 February 2019
bibliography: paper.bib
---

Summary
=======

R is used heavily in the bioinformatics community for processing, analyzing, and visualizing biological sequence data due to the strong support for data exploration and analysis. One common complaint about R is its lack of speed relative to other languages, which have to do with properties of the R kernel [@Sridharan2015]. A solution to this is to rewrite key functions in C++ instead, then use Rcpp [@Eddelbuettel2018] to interface with R. Many packages in R are sped up with C++ code: as of [November
2018](http://dirk.eddelbuettel.com/blog/2018/11/07/), out of 13525 packages on CRAN, 1493 of those use Rcpp. On Bioconductor [@Huber2015], a repository specifically for bioinformatics packages, there is a similar proportion of packages using Rcpp: 150 out of 1649.

Writing certain functions in C++ also allows the researcher to take advantage of high-performance C++ libraries. One such library that has proven powerful and popular for bioinformatics applications is SeqAn [@Doring2008; @Reinert2017]. SeqAn is an open source C++ library of efficient algorithms and data structures for the analysis of sequences with a focus on biological data. It has been used for many popular bioinformatics tools, including Bowtie2 [@Langmead2012] and Tophat [@Trapnell2009]. Its capabilities include efficient storage and I/O of sequence data, fast algorithms for pattern matching, and much more.

To date, no R package has taken advantage of SeqAn. This is due to two issues. First, R for Windows is built with the mingw compiler, which the SeqAn development team does not offer support for. Second, SeqAn implements several custom data types in order to make the library more efficient. This means that any data type in SeqAn needs to have have R to C++ conversion and C++ to R conversion functions written for it before it can be used in R.

`RSeqAn` solves both of these problems, thus allowing any R researcher to use the capabilities of SeqAn in their own work without need for the user to install SeqAn themselves or deal with interfacing between R and C++. `RSeqAn` can be installed from Bioconductor, and documentation for it can be found in the package as well as [online](https://compbiocore.github.io/RSeqAn/).

Benchmarked Example
-------------------

As a proof of concept for its utility, we have benchmarked a function
(searching for adapter contamination) from `qckitfastq`, a package that
uses RSeqAn for quality control on bioinformatics data compared to
`ShortRead` [@Morgan2009], another package on Bioconductor
serving the same function that is purely written in R (Table 1). As can
be seen, computing adapter content through `qckitfastq` is much faster
than `ShortRead`.

   
   ------------------------------------------------------------------------------
        File          Package     replications   elapsed    user.self  sys.self
   ----------------- ------------ -------------- --------- ---------- -----------
    **E-MTAB-1147**   ShortRead        100         13.3       11.58        1.37    
   
                      qckitfastq       100         5.159      4.902      0.091     

    **test.fq.gz**    ShortRead        100         6.612      5.739      0.567     
     
                      qckitfastq       100         0.195      0.105      0.019      
   ------------------------------------------------------------------------------
     
   Table: Benchmark results of qckitfastq, which uses RSeqAn, and ShortRead, which does not against a test file from each package.


Acknowledgments
---------------

Thanks to Ashok Ragavendran for the concept of using SeqAn in R packages
to speed up functions. Thanks to Fernando Gelin for help with the
documentation and style. This publication was supported by an
Institutional Development Award (IDeA) from the National Institute of
General Medical Sciences of the National Institutes of Health under
grant number P20GM109035.

References
==========
