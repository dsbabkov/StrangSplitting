#pragma once

#include "InputParameters.h"
#include <QMainWindow>
#include <memory>

class ResultsMemoryWriter;

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

private slots:
    void saveSettings() const;
    void computeTimeStepCount();
    void solve();


private:
    Ui::MainWindow *ui;
    std::shared_ptr<ResultsMemoryWriter> resultsWriter_;
};
