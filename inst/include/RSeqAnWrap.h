#ifndef RSeqAn__RSeqAnWrap__h
#define RSeqAn__RSeqAnWrap__h

namespace Rcpp {
  // Defined wrap case
    template <> SEXP wrap(const seqan::CharString &obj) {
      std::string s(toCString(obj));
      return Rcpp::wrap(s);
    }
}

#endif