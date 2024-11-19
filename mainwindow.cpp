#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "queue.h"
#include <cstdlib>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , simulationRunning(false)
    , progress(0)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::on_btnStart_clicked);
    connect(ui->btnReset, &QPushButton::clicked, this, &MainWindow::on_btnReset_clicked);

    // Initialize the timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUI);

    // Generate initial random patients
    generateRandomPatients();
    updateUI();
}

MainWindow::~MainWindow() {
    delete ui;
    delete timer;
}

void MainWindow::on_btnStart_clicked() {
    if (!simulationRunning) {
        simulationRunning = true;
        timer->start(1000); // Serve patients every second
        ui->textLogs->append("Simulation started.");
    }
}

void MainWindow::on_btnReset_clicked() {
    // Stop the simulation
    simulationRunning = false;
    timer->stop();

    // Clear UI components
    ui->listUrgentQueue->clear();
    ui->listNormalQueue->clear();
    ui->listStatistics->clear();
    ui->textLogs->clear();

    // Reset queue and generate new patients
    queue = Queue();
    generateRandomPatients();
    updateUI();
}

void MainWindow::generateRandomPatients() {
    for (int i = 0; i < 100; ++i) {
        // Generate random patient details
        std::string id = std::to_string(28501012345678 + i);
        char gender = (i % 2 == 0) ? 'M' : 'F';
        std::string arrivalTime = std::to_string(8 + rand() % 15) + ":" + (rand() % 60 < 10 ? "0" : "") + std::to_string(rand() % 60);
        std::string type = (i % 2 == 0) ? "Urgent" : "Normal";

        try {
            Patient patient(id, gender, arrivalTime, type);
            queue.dispatchPatient(patient);
        } catch (const std::exception &e) {
            qDebug() << "Error creating patient:" << e.what();
        }
    }
}

void MainWindow::updateUI() {
    if (simulationRunning) {
        // Serve a random number of patients (5–10)
        queue.servePatients(5 + rand() % 6, ui->textLogs);
        queue.updateWaitingTimes(10); // Increment waiting times by 10 minutes
    }

    // Refresh UI elements
    queue.displayQueues(ui->listUrgentQueue, "Urgent");
    queue.displayQueues(ui->listNormalQueue, "Normal");
    queue.displayStatistics(ui->listStatistics);
}
