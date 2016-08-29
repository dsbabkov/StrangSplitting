#pragma once

struct Alloy
{
    Alloy();
    Alloy(double conductivity, double specificHeat, double density);
    double thermalDiffusivity() const;

    double conductivity; //         W/(m*K)
    double specificHeat; //         J/(kg*K)
    double density;      //         kg/m^3
};
