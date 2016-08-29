#pragma once

#include "Alloy.h"
#include <QWidget>

namespace Ui {
class AlloyParameters;
}

class AlloyParameters : public QWidget
{
    Q_OBJECT

public:
    explicit AlloyParameters(QWidget *parent = nullptr);
    ~AlloyParameters();

    Alloy alloy() const;

private:
    void setupConnections();

private slots:
    void computeThermalDiffusivity();

private:
    Ui::AlloyParameters *ui;
};
