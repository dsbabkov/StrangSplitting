#pragma once

struct InputParameters
{
    InputParameters();
    unsigned timeStepCount() const;

    double width;
    double height;
    unsigned widthFragmentsCount;
    unsigned heightFragmentsCount;
    double timeStepSize;
    double endTime;
};
