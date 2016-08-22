#include "InputParameters.h"
#include <QtMath>

InputParameters::InputParameters()
    : width{}
    , height{}
    , widthFragmentsCount{}
    , heightFragmentsCount{}
    , timeStepSize{}
    , endTime{}
{

}

unsigned InputParameters::timeStepCount() const
{
    return static_cast<unsigned>(std::round(endTime / timeStepSize));
}
