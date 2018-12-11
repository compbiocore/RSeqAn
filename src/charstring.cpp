#include <RSeqAn.h>
#include <iostream>

//' containment test
//' @param s1 Should be a character string
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