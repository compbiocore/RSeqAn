#include <RSeqAn.h>

namespace Rcpp {
  // Defined wrap case
  template <> SEXP wrap(const seqan::CharString &obj) {
    std::string s(toCString(obj));
    return Rcpp::wrap(s);
  }

  template <> seqan::CharString as(SEXP dt) {
    std::string dts = Rcpp::as<std::string>(dt);
    seqan::CharString s = dts;
    return s;
  };
  
}