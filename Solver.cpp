#include "IResultsWriter.h"
#include <QtDebug>
#include "Solver.h"

using arma::uword;

Solver::Solver(std::shared_ptr<IResultsWriter> writer)
    : writer_{writer}
    , inputParameters_{}
{

}

std::shared_ptr<IResultsWriter> Solver::writer() const
{
    return writer_;
}

void Solver::setWriter(const std::shared_ptr<IResultsWriter> &writer)
{
    writer_ = writer;
}

InputParameters Solver::inputParameters() const
{
    return inputParameters_;
}

void Solver::setInputParameters(const InputParameters &inputParameters)
{
    inputParameters_ = inputParameters;
    writer_->writeInputParameters(inputParameters_);
}

void Solver::solve()
{
    arma::mat currentLayer = std::move(initialLayer());
    writer_->writeResults(0, currentLayer);

    double time = 0;

    while (time <= inputParameters_.endTime){
        time += inputParameters_.timeStepSize;

        arma::mat vLayer(currentLayer.n_rows, currentLayer.n_cols);
        assignBoundaryConditions(vLayer);

        writer_->writeResults(time, currentLayer);
    }
}

arma::mat Solver::initialLayer() const
{
    arma::mat result(inputParameters_.widthFragmentsCount + 1, inputParameters_.heightFragmentsCount + 1);

    result.zeros();
    assignBoundaryConditions(result);

    return result;
}

void Solver::assignBoundaryConditions(arma::mat &results) const
{
    for (uword i = 0; i < results.n_rows; ++i){
        results.at(i, 0) = 0;
    }

    for (uword j = 0; j < results.n_cols; ++j){
        results.at(results.n_rows - 1, j) = 0;
    }

    results.at(0, 0) = 1500;
}
