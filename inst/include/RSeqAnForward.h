// Based off of https://github.com/RcppCore/RcppArmadillo/blob/master/inst/include/RcppArmadilloForward.h

#ifndef RSeqAn__RSeqAnForward__h
#define RSeqAn__RSeqAnForward__h

#include <RcppCommon.h>

#include <seqan/sequence.h>

namespace Rcpp {
  template <> SEXP wrap(const seqan::CharString&) ;
  template <> seqan::CharString as(SEXP); 
}

#endif