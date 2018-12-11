// Based off of https://github.com/RcppCore/RcppArmadillo/blob/master/inst/include/RcppArmadilloAs.h

#ifndef RSeqAn__RSeqAnAs__h
#define RSeqAn__RSeqAnAs__h

namespace Rcpp {

  template <> seqan::CharString as(SEXP dt) {
    std::string dts = Rcpp::as<std::string>(dt);
    seqan::CharString s = dts;
    return s;
  };
}

#endif