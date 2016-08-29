#pragma once

struct Alloy
{
    Alloy();
    Alloy(double thermalConductivity, double specificHeat, double density);
    double thermalDiffusivity() const;

    double thermalConductivity; //         W/(m*K)
    double specificHeat; //         J/(kg*K)
    double density;      //         kg/m^3
};
