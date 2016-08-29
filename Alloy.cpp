#include "Alloy.h"

Alloy::Alloy()
    : thermalConductivity{50}
    , specificHeat{462}
    , density{7800}
{
}

Alloy::Alloy(double conductivity, double specificHeat, double density)
    : thermalConductivity(conductivity)
    , specificHeat(specificHeat)
    , density(density)
{
}

double Alloy::thermalDiffusivity() const
{
    return thermalConductivity / (specificHeat * density);
}
