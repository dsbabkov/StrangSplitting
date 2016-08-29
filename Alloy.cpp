#include "Alloy.h"

Alloy::Alloy()
    : conductivity{}
    , specificHeat{}
    , density{}
{
}

Alloy::Alloy(double conductivity, double specificHeat, double density)
    : conductivity(conductivity)
    , specificHeat(specificHeat)
    , density(density)
{
}

double Alloy::thermalDiffusivity() const
{
    return conductivity / (specificHeat * density);
}
