#!/bin/bash

## Travis can let us run R 3.4.0 (from CRAN and the PPAs) but this R version
## does not know about C++14.  Even though we can select CXX_STD = C++14, R
## will fail as the version we use there was built in too old an environment,
## namely Ubuntu "trusty" 14.04.
##
## So we install g++-6 from another repo and rely on the fact that is
## defaults to C++14.  Sadly, we need R to not fail and hence, just on
## Travis, remove the C++14 instruction

if [[ "${CI}" == "true" ]]; then
    if [[ "${TRAVIS}" == "true" ]]; then 
        echo "** Overriding DESCRIPTION and removing C++14 on Travis only"
        sed -i 's|C++14, ||' DESCRIPTION
    fi
fi