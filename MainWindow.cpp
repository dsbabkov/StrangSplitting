#include "MainWindow.h"
#include <QSettings>
#include <QtDebug>
#include <ResultsMemoryWriter.h>
#include "Solver.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , resultsWriter_{new ResultsMemoryWriter()}
{
    ui->setupUi(this);
    initConnections();
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

InputParameters MainWindow::inputParameters() const
{
    InputParameters result;

    result.width = ui->widthSpn->value();
    result.height = ui->heightSpn->value();
    result.widthFragmentsCount = static_cast<unsigned>(ui->widthFragmentCountSpn->value());
    result.heightFragmentsCount = static_cast<unsigned>(ui->heightFragmentCountSpn->value());
    result.timeStepSize = ui->timeStepSizeSpn->value();
    result.endTime = ui->endTimeSpn->value();

    return result;
}

void MainWindow::initConnections()
{
    connect(ui->timeStepSizeSpn, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::computeTimeStepCount);
    connect(ui->endTimeSpn, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::computeTimeStepCount);
    connect(ui->solveBtn, &QAbstractButton::clicked, this, &MainWindow::saveSettings);
    connect(ui->solveBtn, &QAbstractButton::clicked, this, &MainWindow::solve);
}

void MainWindow::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("WindowGeometry").toByteArray());
    restoreState(settings.value("WindowState").toByteArray());

    settings.beginGroup("InputParameters");
    ui->widthSpn->setValue(settings.value("Width").toDouble());
    ui->heightSpn->setValue(settings.value("Height").toDouble());
    ui->heightFragmentCountSpn->setValue(settings.value("HeightFragmentCount").toInt());
    ui->widthFragmentCountSpn->setValue(settings.value("WidthFragmentCount").toInt());
    ui->timeStepSizeSpn->setValue(settings.value("TimeStepSize").toDouble());
    ui->endTimeSpn->setValue(settings.value("EndTime").toDouble());
}

void MainWindow::saveSettings() const
{
    QSettings settings;
    settings.setValue("WindowGeometry", saveGeometry());
    settings.setValue("WindowState", saveState());

    settings.beginGroup("InputParameters");
    settings.setValue("Width", ui->widthSpn->value());
    settings.setValue("Height", ui->heightSpn->value());
    settings.setValue("HeightFragmentCount", ui->heightFragmentCountSpn->value());
    settings.setValue("WidthFragmentCount", ui->widthFragmentCountSpn->value());
    settings.setValue("TimeStepSize", ui->timeStepSizeSpn->value());
    settings.setValue("EndTime", ui->endTimeSpn->value());
}

void MainWindow::computeTimeStepCount()
{
    ui->timeStepCountLbl->setText(QString::number(inputParameters().timeStepCount()));
}

void MainWindow::solve()
{
    Solver solver(resultsWriter_);
    solver.setInputParameters(inputParameters());

    qDebug() << "Calculation started";
    solver.solve();
    qDebug() << "Calculation finished";
}
