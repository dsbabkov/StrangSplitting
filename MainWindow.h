#pragma once

#include "InputParameters.h"
#include <QMainWindow>
#include <memory>

class Solver;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    InputParameters inputParameters() const;

private:
    void initConnections();
    void loadSettings();
    void saveSettings() const;


private:
    Ui::MainWindow *ui;

    std::unique_ptr<Solver> vSolver;
    std::unique_ptr<Solver> wSolver;
};
