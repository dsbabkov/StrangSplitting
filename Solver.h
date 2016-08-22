#pragma once

#include "InputParameters.h"
#include <armadillo>
#include <memory>

class IResultsWriter;

class Solver
{
public:
    explicit Solver(std::shared_ptr<IResultsWriter> writer);

    std::shared_ptr<IResultsWriter> writer() const;
    void setWriter(const std::shared_ptr<IResultsWriter> &writer);

    InputParameters inputParameters() const;
    void setInputParameters(const InputParameters &inputParameters);

    void solve();

private:
    arma::mat initialLayer() const;
    void assignBoundaryConditions(arma::mat &results) const;

private:
    std::shared_ptr<IResultsWriter> writer_;
    InputParameters inputParameters_;
};
