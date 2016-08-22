#pragma once

#include "InputParameters.h"
#include <armadillo>

class IResultsWriter
{
public:
    virtual ~IResultsWriter();

    virtual void writeInputParameters(const InputParameters &parameters) = 0;
    virtual void writeResults(const arma::mat &matrix) = 0;
};
