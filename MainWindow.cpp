#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Solver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vSolver(new Solver)
    , wSolver(new Solver)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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
