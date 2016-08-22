#include "ResultsMemoryWriter.h"

ResultsMemoryWriter::ResultsMemoryWriter()
{

}

void ResultsMemoryWriter::writeInputParameters(const InputParameters &parameters)
{
    inputParameters_ = parameters;
}

void ResultsMemoryWriter::writeResults(const arma::mat &matrix)
{
    results_ = std::move(arma::join_slices(results_, matrix));
}
