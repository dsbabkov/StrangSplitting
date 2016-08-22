#pragma once

#include "IResultsWriter.h"

class ResultsMemoryWriter: public IResultsWriter
{
public:
    ResultsMemoryWriter();

    virtual void writeInputParameters(const InputParameters &parameters) override;
    virtual void writeResults(const arma::mat &matrix) override;

private:
    InputParameters inputParameters_;
    arma::cube results_;
};
