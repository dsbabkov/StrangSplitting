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
