// [[Rcpp::depends(RSeqAn)]]

#include <iostream>
#include <seqan/file.h>
#include <seqan/sequence.h>
#include <Rcpp.h>

using namespace Rcpp;
using namespace seqan;

// [[Rcpp::export]]
IntegerVector pattern_search(std::string t, std::string p) {

    seqan::String<char> text = t;
    seqan::String<char> pattern = p;

    seqan::String<int> score;
    resize(score, length(text) - length(pattern) + 1);

    // Computation of the similarities
    // Iteration over the text (outer loop)
    for (unsigned i = 0; i < length(text) - length(pattern) + 1; ++i)
    {
        int localScore = 0;
        // Iteration over the pattern for character comparison
        for (unsigned j = 0; j < length(pattern); ++j)
        {
            if (text[i + j] == pattern[j])
                ++localScore;
        }
        score[i] = localScore;
    }

    // Returning the result
    IntegerVector s(length(score));
    for (unsigned i = 0; i < length(score); ++i)
        s[i] = score[i];

    return s;
}