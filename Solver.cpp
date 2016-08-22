#include "IResultsWriter.h"
#include "Solver.h"

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

}
