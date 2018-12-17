---
title: "RSeqAn: Headers and wrappers for the SeqAn library in R"
authors:
  - affiliation: 1
    name: August Guang
    orcid: 0000-0003-0872-7098
date: "7 December 2018"
bibliography: paper.bib
tags:
  - SeqAn
  - bioinformatics
  - R
  - Rcpp
affiliations:
  - index: 1
    name: Brown University
---



# Summary

`RSeqAn` provides R with access to SeqAn [@Doring2008,@Reinert2017] header files. SeqAn is an open source C++ library of efficient algorithms and data structures for the analysis of sequences with a focus on biological data. It has been used for many popular bioinformatics tools, including Bowtie2 [@Langmead2013] and Tophat [@Trapnell2009]. Many packages in R are sped up with C++ code: as of [November 2018](http://dirk.eddelbuettel.com/blog/2018/11/07/), out of 13525 packages on CRAN, 1493 of those use Rcpp [@Eddelbuettel2018]. On Bioconductor [@Huber2015], a repository specifically for bioinformatics packages, there is a similar proportion of packages using Rcpp: 150 out of 1649. However, to date these packages have not utilized SeqAn.

An R package that does aim to use SeqAn runs into two issues. First, R for Windows is built with the mingw compiler, which the SeqAn development team does not offer support for. Second, SeqAn implements several data types in order to make the library more efficient. Any data types in SeqAn must thus be extended with Rcpp through the templated functions `Rcpp::as` and `Rcpp::wrap`.

In `RSeqAn` v1.0 we provide access to SeqAn header files and add support for mingw so that it can be used in R for Windows as well. The development version also includes some wrappers to convert between R objects and SeqAn data types with a goal of eventually providing all necessary wrappers for easy interface with SeqAn. `RSeqAn` thus provides an easy way to write R bioinformatics packages that are much more efficient without need for the user to install SeqAn themselves. `RSeqAn` can be installed from Bioconductor, and documentation for it can be found in the package as well as [online](https://compbiocore.github.io/RSeqAn/).

## Benchmarked Example

As a proof of concept for its utility, we have benchmarked a function (searching for adapter contamination) from `qckitfastq`, a package that uses RSeqAn for quality control on bioinformatics data compared to `ShortRead` [@Morgan2009], another package on Bioconductor serving the same function that is purely written in R (Table 1). As can be seen, computing adapter content through `qckitfastq` is much faster than `ShortRead`.



<table>
<caption>Benchmark results of qckitfastq, which uses RSeqAn, and ShortRead, which does not against a test file from each package.</caption>
 <thead>
  <tr>
   <th style="text-align:left;"> Package </th>
   <th style="text-align:right;"> replications </th>
   <th style="text-align:right;"> elapsed </th>
   <th style="text-align:right;"> relative </th>
   <th style="text-align:right;"> user.self </th>
   <th style="text-align:right;"> sys.self </th>
   <th style="text-align:right;"> user.child </th>
   <th style="text-align:right;"> sys.child </th>
  </tr>
 </thead>
<tbody>
  <tr grouplength="2"><td colspan="8" style="border-bottom: 1px solid;"><strong>system.file(package="ShortRead", "extdata", "E-MTAB-1147")</strong></td></tr>
<tr>
   <td style="text-align:left; padding-left: 2em;" indentlevel="1"> ShortRead </td>
   <td style="text-align:right;"> 100 </td>
   <td style="text-align:right;"> 13.733 </td>
   <td style="text-align:right;"> 1 </td>
   <td style="text-align:right;"> 11.529 </td>
   <td style="text-align:right;"> 1.592 </td>
   <td style="text-align:right;"> 0.130 </td>
   <td style="text-align:right;"> 0.114 </td>
  </tr>
  <tr>
   <td style="text-align:left; padding-left: 2em;" indentlevel="1"> qckitfastq </td>
   <td style="text-align:right;"> 100 </td>
   <td style="text-align:right;"> 5.230 </td>
   <td style="text-align:right;"> 1 </td>
   <td style="text-align:right;"> 4.864 </td>
   <td style="text-align:right;"> 0.120 </td>
   <td style="text-align:right;"> 0.056 </td>
   <td style="text-align:right;"> 0.045 </td>
  </tr>
  <tr grouplength="2"><td colspan="8" style="border-bottom: 1px solid;"><strong>system.file(package="qckitfastq", "extdata", "test.fq.gz")</strong></td></tr>
<tr>
   <td style="text-align:left; padding-left: 2em;" indentlevel="1"> ShortRead </td>
   <td style="text-align:right;"> 100 </td>
   <td style="text-align:right;"> 8.070 </td>
   <td style="text-align:right;"> 1 </td>
   <td style="text-align:right;"> 6.900 </td>
   <td style="text-align:right;"> 0.687 </td>
   <td style="text-align:right;"> 0.079 </td>
   <td style="text-align:right;"> 0.071 </td>
  </tr>
  <tr>
   <td style="text-align:left; padding-left: 2em;" indentlevel="1"> qckitfastq </td>
   <td style="text-align:right;"> 100 </td>
   <td style="text-align:right;"> 0.295 </td>
   <td style="text-align:right;"> 1 </td>
   <td style="text-align:right;"> 0.125 </td>
   <td style="text-align:right;"> 0.046 </td>
   <td style="text-align:right;"> 0.019 </td>
   <td style="text-align:right;"> 0.018 </td>
  </tr>
</tbody>
</table>

## Acknowledgments

Thanks to Ashok Ragavendran for the concept of using SeqAn in R packages to speed up functions. Thanks to Fernando Gelin for help with the documentation and style. This publication was supported by an Institutional Development Award (IDeA) from the National Institute of General Medical Sciences of the National Institutes of Health under grant number P20GM109035.

# References
