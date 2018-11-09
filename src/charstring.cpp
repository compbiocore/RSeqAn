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


using namespace seqan;

//' containment test
//' @export
// [[Rcpp::export]]
Rcpp::String containment_test(SEXP s1) {
    Rcpp::Rcout << "Converting from SEXP to CharString" << std::endl;
    seqan::CharString s = Rcpp::as<seqan::CharString>(s1);
  
    Rcpp::Rcout << "Running output test with toCString(CharString)" << std::endl;
    Rcpp::Rcout << toCString(s) << std::endl;
  
    Rcpp::Rcout << "Converting from CharString to Rcpp::String" << std::endl;
    return(Rcpp::wrap(s));
  }