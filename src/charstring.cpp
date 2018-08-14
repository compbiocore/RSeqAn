#include <RcppCommon.h>
#include <seqan/sequence.h>
#include <iostream>

namespace Rcpp {
  template <> SEXP wrap(const seqan::CharString &obj);
  template <> seqan::CharString as(SEXP dt); 
}

#include <Rcpp.h>

namespace Rcpp {
  // Defined wrap case
    template <> SEXP wrap(const seqan::CharString &obj) {
      std::string s(toCString(obj));
      return Rcpp::wrap(s);
    };
    
    template <> seqan::CharString as(SEXP dt) {
      std::string dts = Rcpp::as<std::string>(dt);
      seqan::CharString s = dts;
      return s;
    };
}