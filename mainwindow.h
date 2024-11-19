#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();
    void on_btnReset_clicked();
    void updateUI();

private:
    Ui::MainWindow *ui;
    Queue queue;
    bool simulationRunning;
    int progress;
    QTimer *timer;

    void generateRandomPatients();
};

#endif // MAINWINDOW_H
