#pragma once

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

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Solver> vSolver;
    std::unique_ptr<Solver> wSolver;
};
