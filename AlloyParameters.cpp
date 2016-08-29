#include "AlloyParameters.h"
#include <QSettings>
#include "ui_AlloyParameters.h"

AlloyParameters::AlloyParameters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlloyParameters)
{
    ui->setupUi(this);
    setupConnections();
    computeThermalDiffusivity();
    loadSettings();
}

AlloyParameters::~AlloyParameters()
{
    saveSettings();
    delete ui;
}

Alloy AlloyParameters::alloy() const
{
    Alloy result;

    result.thermalConductivity = ui->thermalConductivitySpn->value();
    result.specificHeat = ui->specificHeatSpn->value();
    result.density = ui->densitySpn->value();

    return result;
}

void AlloyParameters::setAlloy(const Alloy &alloy)
{
    ui->thermalConductivitySpn->setValue(alloy.thermalConductivity);
    ui->specificHeatSpn->setValue(alloy.specificHeat);
    ui->densitySpn->setValue(alloy.density);
}

void AlloyParameters::setupConnections()
{
    const std::vector<QDoubleSpinBox *> spinBoxes {{ui->thermalConductivitySpn, ui->specificHeatSpn, ui->densitySpn}};
    for (QDoubleSpinBox *spinBox: spinBoxes){
        connect(spinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &AlloyParameters::computeThermalDiffusivity);
    }
}

void AlloyParameters::loadSettings()
{
    QSettings settings("Alloy");
    Alloy alloy;
    alloy.thermalConductivity = settings.value("ThermalConductivity", alloy.thermalConductivity).toDouble();
    alloy.specificHeat = settings.value("SpecificHeat", alloy.specificHeat).toDouble();
    alloy.density = settings.value("Density", alloy.density).toDouble();
    setAlloy(alloy);
}

void AlloyParameters::saveSettings()
{
    QSettings settings("Alloy");
    const Alloy &alloy = this->alloy();
    settings.setValue("ThermalConductivity", alloy.thermalConductivity);
    settings.setValue("SpecificHeat", alloy.specificHeat);
    settings.setValue("Density", alloy.density);
}

void AlloyParameters::computeThermalDiffusivity()
{
    const Alloy &alloy = this->alloy();
    if (qFuzzyIsNull(alloy.specificHeat) ||
            qFuzzyIsNull(alloy.density)){
        ui->thermalDiffusivityLbl->setText("---");
        return;
    }

    ui->thermalDiffusivityLbl->setText(QString::number(alloy.thermalDiffusivity(), 'e'));
}
